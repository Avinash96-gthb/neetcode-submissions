class Solution {
public:
    vector<vector<int>> solution;
    void dfs(vector<int>& nums, vector<int>& current, int index){
        if (index >= nums.size()){
            solution.push_back(current);
            return;
        }
        //find next index (first index different)
        int nextIndex = index;
        while (nextIndex < nums.size() && nums[index] == nums[nextIndex]){
            nextIndex++;
        }
        //now we add the duplicate values
        for (int i = index; i < nextIndex; i++){
            current.push_back(nums[i]);
            dfs(nums, current, nextIndex);
        }

        for (int i = nextIndex - 1; i >= index; i--){
            current.pop_back();
        }
        dfs(nums, current, nextIndex);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> current;
        dfs(nums, current, 0);
        return solution;
        
    }
};
