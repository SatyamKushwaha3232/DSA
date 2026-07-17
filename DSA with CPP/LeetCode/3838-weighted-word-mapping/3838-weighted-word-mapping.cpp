class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {

        string ans;
        ans.reserve(words.size());

        for (const string& word : words) {

            int sum = 0;

            for (char c : word) {
                sum += weights[c - 'a'];
            }

            ans.push_back(char('z' - (sum % 26)));
        }

        return ans;
    }
};