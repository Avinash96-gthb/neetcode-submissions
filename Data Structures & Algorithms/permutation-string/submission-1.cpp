class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> freq;
        for (char word: s1){
            freq[word]++;
        }
        for (int i = 0; i < s2.size(); i++){
            if (freq.find(s2[i]) != freq.end()){
                int localCount = s1.size();
                int j = i;
                unordered_map<char, int> local = freq;
                while (j < s2.size() && j < i + s1.size()){
                    if (local.find(s2[j]) != local.end()){
                        if (local[s2[j]] > 0){
                            local[s2[j]]--;
                            localCount--;
                        }
                        j++;
                    } else {
                        break;
                    }
                }
                if (localCount == 0){
                    return true;
                }
            }
        }
        return false;
    }
};
