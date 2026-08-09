class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() == 0 || t.size() > s.size()){
            return "";
        }
        unordered_map<char, int> targetWord;
        unordered_map<char, int> slidingWindow;
        for (char c: t){
            targetWord[c]++;
        }
        int totalUniqueChars = t.size();
        int currentCount = 0;
        pair<int, int> resultIndex = {-1, -1};
        int currentSmallestSize = INT_MAX;
        int left = 0;
        for (int right = 0; right < s.size(); right++){
            slidingWindow[s[right]]++;
            if (targetWord.find(s[right]) != targetWord.end() && slidingWindow[s[right]] <= targetWord[s[right]]){
                currentCount++;
            }
            while (currentCount == totalUniqueChars){
                if (right - left + 1 < currentSmallestSize){
                    currentSmallestSize = right - left + 1;
                    resultIndex.first = left;
                    resultIndex.second = right;
                }
                slidingWindow[s[left]]--;
                if (targetWord.find(s[left]) != targetWord.end() && slidingWindow[s[left]] < targetWord[s[left]]){
                    currentCount--;
                }
                left++;
            }
        }
        if (currentSmallestSize == INT_MAX){
            return "";
        }
        return s.substr(resultIndex.first, resultIndex.second - resultIndex.first + 1);
    }
};
