class Solution {
public:
    int identifyCorrectIndex(vector<vector<int>>& matrix, int target){
        int left = 0;
        int right = matrix.size() - 1;
        while (left <= right){
            int mid = left + (right - left)/2;
            cout << "the mid is" << mid;
            if (target >= matrix[mid][0] && target <= matrix[mid][matrix[mid].size()-1]){
                cout << "are we returning?";
                return mid;
            } else if (target > matrix[mid][matrix[mid].size()-1]){
                left = mid + 1;
            } else if (target < matrix[mid][0]){
                right = mid - 1;
            }
        }
        return -1;
    }
    bool binarySearch(vector<int>& search, int target){
        int left = 0;
        int right = search.size() - 1;
        while (left <= right){
            int mid = left + (right - left)/2;
            if (search[mid] == target){
                return true;
            } else if (search[mid] > target){
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int value = identifyCorrectIndex(matrix, target);
        if (value == -1){
            return false;
        }
        return binarySearch(matrix[value], target);
        // for (int i = 0; i < matrix.size(); i++){
        //     if (binarySearch(matrix[i], target)){
        //         return true;
        //     }
        // }
        // return false;
    }
};
