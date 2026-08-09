class Solution {
public:
    int trap(vector<int>& height) {
        int total = 0;
        vector<int> maxLeft(height.size());
        vector<int> maxRight(height.size());

        maxLeft[0] = 0;
        int currentMaxLeft = height[0];
        for (int i = 1; i < maxLeft.size(); i++){
            maxLeft[i] = currentMaxLeft;
            if (height[i] > currentMaxLeft){
                currentMaxLeft = height[i];
            }
        }
        maxRight[height.size()-1] = 0;
        int currentMaxRight = height[height.size()-1];
        for (int i = height.size()-2; i>=0; i--){
            maxRight[i] = currentMaxRight;
            if (height[i] > currentMaxRight){
                currentMaxRight = height[i];
            }
        }

        for (int i = 0; i < height.size(); i++){
            int minVal = min(maxLeft[i], maxRight[i]);
            int value = minVal - height[i];
            if (value > 0){
                total+=value;
            }
        }        
        return total;
    }
};
