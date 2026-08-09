// input is: vector<int> nums (1 <= nums.size() <= 100,000) and -10000 <= nums[i] <= 10000 int k ()
// return vector<int> of size nums.size() - k with each element being max in window of size k starting from 0 to nums.size()
// brute force (iterate over array and each step compute max window size)
// optimized
// 1 2 1 0 4 2 6  k = 3

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        int currentMaxValue = INT_MIN;
        int currentMaxIndex = 0;
        for (int i = 0; i < k; i++){
            if (nums[i] > currentMaxValue){
                currentMaxValue = nums[i];
                currentMaxIndex = i;
            }
        }
        ans.push_back(currentMaxValue);
        for (int i = k; i < nums.size(); i++){
            if (i - k + 1 > currentMaxIndex ){
                int localCurrentMax = INT_MIN;
                for (int j = i; j >= i - k + 1; j--){
                    if (nums[j] > localCurrentMax){
                        localCurrentMax = nums[j];
                        currentMaxIndex = j;
                    }
                }
                currentMaxValue = localCurrentMax;
                ans.push_back(currentMaxValue);
            } else {
                if (nums[i] > currentMaxValue){
                    currentMaxValue = nums[i];
                    currentMaxIndex = i;
                    ans.push_back(nums[i]);
                } else {
                    ans.push_back(currentMaxValue);
                }
            }
        }
        return ans;
    }
};
