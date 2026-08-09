class Solution {
public:
    vector<vector<int>> result;
    int numsEndIndex;
    void decisionTree(int i, vector<int> arr, vector<int>& nums){
        if (i >= nums.size()){
            result.push_back(arr);
            return;
        }
        int newInt = i + 1;
        decisionTree(newInt, arr, nums);
        arr.push_back(nums[i]);
        decisionTree(newInt,arr, nums);
        // arr.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        numsEndIndex = nums.size() - 1;
        vector<int> arr;
        decisionTree(0, arr, nums);
        return result;
    }
};
