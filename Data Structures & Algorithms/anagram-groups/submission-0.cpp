class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagrams;
        for (string word: strs){
            string sorted = word;
            sort(sorted.begin(), sorted.end());
            anagrams[sorted].push_back(word);
        }

        vector<vector<string>> ans;
        for (auto it = anagrams.begin(); it != anagrams.end(); it++){
            vector<string> subList;
            for (string anagram: it->second){
                subList.push_back(anagram);
            }
            ans.push_back(subList);
        }
        return ans;
    }
};
