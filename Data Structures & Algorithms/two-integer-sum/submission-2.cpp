class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> remainder;
        for (int i = 0; i < nums.size(); i++){
            int difference = target - nums[i];
            // auto it = remainder.find(difference);
            if (remainder.find(difference) != remainder.end()){
                return {remainder[difference], i};
            } else {
                remainder[nums[i]] = i;
            }
        }
        return {};
    }
};
