// input: vector<int> nums
// bounds: 1 < nums.size() < 1000
// bounds: -1000 <= nums[i] <= 1000
// to find: how much array was rotated by
// example: [3,4,5,6,1,2] rotated by 4 times
// to find: min num in array







class Solution {
public:
    int findMin(vector<int> &nums) {
        int minNum = INT_MAX;
        for (int num: nums){
            minNum = min(num, minNum);
        }
        return minNum;
    }
};
