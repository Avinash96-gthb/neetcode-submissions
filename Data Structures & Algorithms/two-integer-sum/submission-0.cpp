class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> remainder;
        vector<int> answer;
        for (int i = 0; i < nums.size(); i++){
            int difference = target - nums[i];
            auto it = remainder.find(difference);
            if (it != remainder.end()){
                answer.push_back(it->second);
                answer.push_back(i);
                return answer;
            } else {
                remainder[nums[i]] = i;
            }
        }
        return answer;
    }
};
