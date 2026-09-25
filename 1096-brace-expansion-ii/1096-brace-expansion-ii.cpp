class Solution {
public:

    string s;
    int pos = 0;

    // Union of two sets
    set<string> unite(set<string> a, set<string> b) {
        for (string x : b) {
            a.insert(x);
        }
        return a;
    }

    // Concatenation of two sets
    set<string> concat(set<string> a, set<string> b) {
        set<string> result;

        for (string x : a) {
            for (string y : b) {
                result.insert(x + y);
            }
        }

        return result;
    }

    // Parse an expression
    set<string> parse() {
        set<string> result;
        set<string> current = {""};

        while (pos < s.size() && s[pos] != '}') {

            // Comma means UNION
            if (s[pos] == ',') {
                result = unite(result, current);
                current = {""};
                pos++;
            }

            // Opening brace
            else if (s[pos] == '{') {
                pos++; // skip '{'

                set<string> inside = parse();

                pos++; // skip '}'

                current = concat(current, inside);
            }

            // Lowercase letter
            else {
                string ch(1, s[pos]);
                current = concat(current, {ch});
                pos++;
            }
        }

        // Add the last part
        result = unite(result, current);

        return result;
    }

    vector<string> braceExpansionII(string expression) {
        s = expression;
        pos = 0;

        set<string> result = parse();

        return vector<string>(result.begin(), result.end());
    }
};