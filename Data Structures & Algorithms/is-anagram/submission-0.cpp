class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> count;
        for (char c: s){
            count[c]--;
        }
        for (char b: t){
            count[b]++;
        }

        for (auto it = count.begin(); it != count.end(); it++){
            if (it->second != 0){
                return false;
            }
        }
        return true;
    }
};
