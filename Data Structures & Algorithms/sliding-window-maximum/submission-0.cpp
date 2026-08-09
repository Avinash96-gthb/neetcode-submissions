class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        for (int i = 0; i <= nums.size() - k; i++){
            int maxNum = nums[i];
            for (int j = i + 1; j < i + k; j++){
                maxNum = max(maxNum, nums[j]);
            }
            ans.push_back(maxNum);
        }
        return ans;
    }
};
