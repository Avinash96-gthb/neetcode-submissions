// input: vector<int> nums
// bounds: 1 < nums.size() < 1000
// bounds: -1000 <= nums[i] <= 1000
// to find: how much array was rotated by
// example: [3,4,5,6,1,2] rotated by 4 times
// to find: min num in array
// easy to find in o(n), how to optimize this?
// for [3,4,5,6,1,2]
// l = 0, r = 5, mid = l + (r - l)/2 = 2
// 5 > r which means the rotation is all the things left of it cant be min
// l = 2 + 1 = 3
// 3 + 5 / 2 = 4
// 4 < r meaning it is a candidate
// if nums[mid] >= nums[right] then the value in end was rotated till it reached mid so the smallest ones are in right
// if nums[mid] < nums[right] means mid to right is sorted so min has to be in left part of array







class Solution {
public:
    int findMin(vector<int> &nums) {
        int minNum = nums[0];
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right){
            int mid = left + (right - left)/2;
            minNum = min(minNum, nums[mid]);
            if (nums[mid] >= nums[right]){
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return minNum;
    }
};
