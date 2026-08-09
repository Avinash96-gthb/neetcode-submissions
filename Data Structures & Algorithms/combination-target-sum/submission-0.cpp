// given list of nums and target
// to return unique list of subsets of nums making target
// using backtracking
// can use same number n number of times
// so decision tree becomes, do I use current number or do I not
// if I use current number then once again decision tree wether I use it or not
// also I have a choice if I do not use it not to use other nums as well

// dry run
// [2,5,6,9] target = 9
// 




class Solution {
public:
    vector<vector<int>> sol;
    void backtracking(vector<int>& current, vector<int>& nums, int index, int currentSum, int target){
        if (currentSum == target){
            sol.push_back(current);
            return;
        }
        if (currentSum > target){
            return;
        }
        if (index >= nums.size()){
            return;
        }
        // first we choose to add current index
        current.push_back(nums[index]);
        currentSum += nums[index];
        backtracking(current, nums, index, currentSum, target);
        current.pop_back();
        currentSum -= nums[index];
        backtracking(current, nums, index + 1, currentSum, target);

    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> current;
        backtracking(current, nums, 0, 0, target);
        return sol;
    }
};
