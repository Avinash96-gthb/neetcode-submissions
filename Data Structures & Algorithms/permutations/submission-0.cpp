class Solution {
public:
    vector<vector<int>> returnAllPermutations(int index, vector<int>& nums){
        if (index == nums.size()){
            return {{}};
        }
        vector<vector<int>> result;
        vector<vector<int>> perms = returnAllPermutations(index+1, nums);
        for (vector<int> p: perms){
            for (int j = 0; j <= p.size(); j++){
                vector<int> pCopy(p);
                pCopy.insert(pCopy.begin() + j, nums[index]);
                result.push_back(pCopy);
            }
        }
        return result;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        return returnAllPermutations(0, nums);
    }
};
