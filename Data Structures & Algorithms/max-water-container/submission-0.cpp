class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxVal = INT_MIN;
        int left = 0;
        int right = heights.size()-1;
        while (left < right){
            if (heights[left] < heights[right]){
                int area = (right - left) * heights[left];
                maxVal = max(area, maxVal);
                left++;
            } else {
                int area = (right - left) * heights[right];
                maxVal = max(area, maxVal);
                right--;
            }
        }
        if (maxVal == INT_MIN){
            return 0;
        }
        return maxVal;
    }
};
