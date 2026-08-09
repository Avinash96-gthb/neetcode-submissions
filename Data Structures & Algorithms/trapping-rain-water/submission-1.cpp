class Solution {
public:
    int trap(vector<int>& height) {
        int total = 0;
        int maxLeft = height[0];
        int maxRight = height[height.size()-1];
        int left = 0;
        int right = height.size()-1;
        while (left < right){
            if (maxLeft > maxRight){
                right--;
                int minVal = maxRight - height[right];
                if (minVal > 0){
                    total += minVal;
                }
                if (height[right] > maxRight){
                    maxRight = height[right];
                }
            } else {
                left++;
                int minVal = maxLeft - height[left];
                if (minVal > 0){
                    total += minVal;
                }
                if (height[left] > maxLeft){
                    maxLeft = height[left];
                }
            }
        }        
        return total;
    }
};
