
// [1, 1, 2, 8]
// [48, 24, 6, 1]
// ans [48, 24, 12, 8]

// [1, -1, 0, 0, 0]
// [0, 6, 6, 3, 1]


// division method
// iterate over the list: if one zero ignore, if two zeroes, return all 0's, else get total product
// iterate through list and divide product with current number that is answer
// time complexity o(n)


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int zeroCount = 0;
        int zeroPosition;
        vector<int> res(nums.size(), 0);
        int product = 1;
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] == 0){
                zeroPosition = i;
                zeroCount++;
                if (zeroCount > 1){
                    return res;
                }
            } else {
                product *= nums[i];
            }
        }

        for (int i = 0; i < nums.size(); i++){
            if (zeroCount > 0){
                if (i == zeroPosition){
                    res[i] = product;
                }
            } else {
                res[i] = product / nums[i];
            }
        }
        return res;
    }
};
