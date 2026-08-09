class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0){
            return 0;
        }
        if (s.size() == 1){
            return 1;
        }
        int maxLenght = 0;
        int left = 0;
        int right = 1;
        unordered_map<char, int> count;
        count[s[0]]++;
        while (right < s.size()){
            count[s[right]]++;
            while (count[s[right]] > 1 && left < right){
                count[s[left]]--;
                left++;
            }
            maxLenght = max(maxLenght, right - left + 1);
            right++;
        }
        return maxLenght;
    }
};
