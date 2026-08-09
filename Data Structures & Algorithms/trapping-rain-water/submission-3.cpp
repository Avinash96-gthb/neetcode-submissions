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
                maxRight = max(maxRight, height[right]);
                total += maxRight - height[right];
            } else {
                left++;
                maxLeft = max(maxLeft, height[left]);
                total += maxLeft - height[left];
            }
        }        
        return total;
    }
};
