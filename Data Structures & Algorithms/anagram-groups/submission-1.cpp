class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagrams;
        for (string word: strs){
            vector<int> count(26, 0);
            for (char c: word){
                count[c - 'a']++;
            }
            string key = to_string(count[0]);
            for (int i = 1; i < 26; i++){
                key += ',' + to_string(count[i]);
            }
            anagrams[key].push_back(word);
        }

        vector<vector<string>> ans;
        for (auto it = anagrams.begin(); it != anagrams.end(); it++){
            ans.push_back(it->second);
        }
        return ans;
    }
};
