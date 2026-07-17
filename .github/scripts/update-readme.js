const fs = require('fs');
const path = require('path');

const root = path.resolve(__dirname, '..', '..');
const readmePath = path.join(root, 'README.md');
const statsPath = path.join(root, 'stats.json');

function readJson(filePath) {
  if (!fs.existsSync(filePath)) return null;
  return JSON.parse(fs.readFileSync(filePath, 'utf8'));
}

function listDirectories(directoryPath) {
  if (!fs.existsSync(directoryPath)) return [];
  return fs
    .readdirSync(directoryPath, { withFileTypes: true })
    .filter((entry) => entry.isDirectory())
    .map((entry) => entry.name)
    .sort();
}

function countFiles(directoryPath, extension) {
  if (!fs.existsSync(directoryPath)) return 0;
  let count = 0;
  for (const entry of fs.readdirSync(directoryPath, { withFileTypes: true })) {
    const entryPath = path.join(directoryPath, entry.name);
    if (entry.isDirectory()) {
      count += countFiles(entryPath, extension);
    } else if (entry.name.endsWith(extension)) {
      count += 1;
    }
  }
  return count;
}

function getDifficultyStats(stats) {
  const leetcode = stats && stats.leetcode ? stats.leetcode : {};
  return {
    solved: leetcode.solved || 0,
    easy: leetcode.easy || 0,
    medium: leetcode.medium || 0,
    hard: leetcode.hard || 0,
  };
}

function getLatestProblems(problemNames, stats, limit = 5) {
  const leetcode = stats && stats.leetcode ? stats.leetcode : {};
  const shas = leetcode.shas || {};
  const fromStats = Object.keys(shas)
    .filter((name) => problemNames.has(name))
    .reverse()
    .slice(0, limit);

  if (fromStats.length > 0) {
    return fromStats;
  }

  return [...problemNames]
    .sort((a, b) => {
      const left = Number((a.match(/^\d+/) || ['0'])[0]);
      const right = Number((b.match(/^\d+/) || ['0'])[0]);
      return right - left || b.localeCompare(a);
    })
    .slice(0, limit);
}

function replaceSection(content, startMarker, endMarker, replacement) {
  const start = content.indexOf(startMarker);
  const end = content.indexOf(endMarker);
  if (start === -1 || end === -1 || end < start) {
    throw new Error(`Missing README markers: ${startMarker} / ${endMarker}`);
  }
  return `${content.slice(0, start + startMarker.length)}\n${replacement.trim()}\n${content.slice(end)}`;
}

const stats = readJson(statsPath);
const difficulty = getDifficultyStats(stats);

const cppRoot = path.join(root, 'DSA with CPP', 'LeetCode');
const javaRoot = path.join(root, 'DSA with Java', 'LeetCode');
const cppProblems = listDirectories(cppRoot);
const javaProblems = listDirectories(javaRoot);
const allProblems = new Set([...cppProblems, ...javaProblems]);

const cppFiles = countFiles(cppRoot, '.cpp');
const javaFiles = countFiles(javaRoot, '.java');
const sortingFiles = countFiles(path.join(root, 'Sorting'), '.cpp');
const patternFiles = countFiles(path.join(root, 'Pattern'), '.cpp');
const latestProblems = getLatestProblems(allProblems, stats);
const updatedAt = new Date().toISOString().slice(0, 10);

const progressSection = `
| Category | Count |
| --- | ---: |
| Total LeetCode problems | ${allProblems.size} |
| Solved tracked in stats | ${difficulty.solved} |
| Easy | ${difficulty.easy} |
| Medium | ${difficulty.medium} |
| Hard | ${difficulty.hard} |
| C++ LeetCode folders | ${cppProblems.length} |
| Java LeetCode folders | ${javaProblems.length} |
| C++ solution files | ${cppFiles} |
| Java solution files | ${javaFiles} |
| Sorting implementations | ${sortingFiles} |
| Pattern practice files | ${patternFiles} |
| Last updated | ${updatedAt} |
`;

const latestSection = latestProblems.length
  ? latestProblems
      .map((problem) => {
        const cppPath = cppProblems.includes(problem)
          ? `DSA with CPP/LeetCode/${problem}`
          : '';
        const javaPath = javaProblems.includes(problem)
          ? `DSA with Java/LeetCode/${problem}`
          : '';
        const links = [
          cppPath ? `[C++](${encodeURI(cppPath)})` : null,
          javaPath ? `[Java](${encodeURI(javaPath)})` : null,
        ]
          .filter(Boolean)
          .join(' / ');
        return `| ${problem} | ${links} |`;
      })
      .join('\n')
  : '| No problems yet | - |';

const latestTable = `
| Problem | Solution |
| --- | --- |
${latestSection}
`;

let readme = fs.readFileSync(readmePath, 'utf8');
readme = replaceSection(
  readme,
  '<!-- AUTO-STATS:START -->',
  '<!-- AUTO-STATS:END -->',
  progressSection,
);
readme = replaceSection(
  readme,
  '<!-- LATEST-PROBLEMS:START -->',
  '<!-- LATEST-PROBLEMS:END -->',
  latestTable,
);

fs.writeFileSync(readmePath, readme);
