class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0;
        int right = 0;
        unordered_map<char, int> count;
        int maxSubString = 0;
        int currentMaxFrequency = 0;
        while (right < s.size()){
            count[s[right]]++;
            currentMaxFrequency = max(currentMaxFrequency, count[s[right]]);
            while ((right - left + 1) - currentMaxFrequency > k){
                count[s[left]]--;
                left++;
            }
            maxSubString = max(maxSubString, right - left + 1);
            right++;
        }
        return maxSubString;
    }
};
