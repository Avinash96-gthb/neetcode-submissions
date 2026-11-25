
// [1, 1, 2, 8]
// [1, 1, 1, 2]
// [16 ,16 ,8 ,1]
// [16, 16, 8, 2]

// [1, -1, 0, 0, 0]
// [1, 1, -1, 0, 0]
// [0 ,0 ,0 ,0 ,1]

// division method
// iterate over the list: if one zero ignore, if two zeroes, return all 0's, else get total product
// iterate through list and divide product with current number that is answer
// time complexity o(n)


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefixSum(nums.size());
        vector<int> suffixSum(nums.size());
        prefixSum[0] = 1;
        for (int i = 1; i < nums.size(); i++){
            prefixSum[i] = prefixSum[i-1] * nums[i-1];
        }
        suffixSum[nums.size()-1] = 1;
        for (int i = nums.size() - 2; i >= 0; i--){
            suffixSum[i] = suffixSum[i+1]*nums[i+1];
        }
        vector<int> res(nums.size());
        for (int i = 0; i < nums.size(); i++){
            res[i] = prefixSum[i] * suffixSum[i];
        }
        return res;
    }
};
