class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // idea:
        // key: list with count per 26 char : [word list...]

        int size_strs = strs.size();
        // init map
        unordered_map<string, vector<string>> ans;

        // base case
        if (size_strs == 1) {
            return {strs};
        }
        else {
            for (int i = 0; i < size_strs; i++) {
                // arr of status
                vector<int> count(26, 0);
                // get current word
                string cur = strs[i];
                // iter through chars
                for(char& c : cur) {
                    // ascii difference
                    count[c - 'a']++;
                }
                string key;
                for (int i : count) {
                    key += "#" + to_string(i);
                }
                ans[key].push_back(cur);

            }

            vector<vector<string>> result;
            for (auto& pair : ans) {
                result.push_back(pair.second);
            }

            return result;

        }
        
    }
};
