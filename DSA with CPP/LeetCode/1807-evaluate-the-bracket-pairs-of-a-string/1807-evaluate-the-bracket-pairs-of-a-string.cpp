class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {

        unordered_map<string, string> mp;

        // Store knowledge in hashmap
        for (auto& k : knowledge) {
            mp[k[0]] = k[1];
        }

        string ans;

        for (int i = 0; i < s.size(); i++) {

            // Normal character
            if (s[i] != '(') {
                ans += s[i];
            }

            // Bracket pair
            else {
                i++; // skip '('

                string key;

                // Extract key
                while (s[i] != ')') {
                    key += s[i];
                    i++;
                }

                // Check key in map
                if (mp.count(key)) {
                    ans += mp[key];
                } else {
                    ans += '?';
                }
            }
        }

        return ans;
    }
};