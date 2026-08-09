class Solution {
public:
    vector<vector<int>> solution;

    void checkAllNumbers(vector<int>& current, vector<int>& candidates, int target, int currentIndex, int currentSum){
        if (currentSum == target){
            solution.push_back(current);
            return;
        }
        if (currentIndex >= candidates.size()){
            return;
        }
        if (currentSum > target){
            return;
        }
        if (candidates[currentIndex] > target){
            return;
        }
        // find the number of values equal to currentValue
        int nextIndex = currentIndex;
        while (nextIndex < candidates.size() && candidates[nextIndex] == candidates[currentIndex]){
            nextIndex++;
        }
        for (int i = currentIndex; i < nextIndex; i++){
            current.push_back(candidates[i]);
            currentSum += candidates[i];
            checkAllNumbers(current, candidates, target, nextIndex, currentSum);
        }

        // remove all the elements pushed now for not using this number 
        for (int i = nextIndex - 1; i >= currentIndex; i--){
            current.pop_back();
            currentSum -= candidates[i];
        }
        checkAllNumbers(current, candidates, target, nextIndex, currentSum);
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> current;
        checkAllNumbers(current, candidates, target, 0, 0);
        return solution;
    }
};
