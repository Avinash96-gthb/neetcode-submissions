class Solution {
public:
    vector<string> sol;
    void createString(string current, int n, int left, int right){
        if (2 * n == left + right){
            sol.push_back(current);
            return;
        }
        if (n == left){
            current.push_back(')');
            createString(current, n, left, right+1);
            return;
        }
        // here we can either add a open or close param
        //adding a open param
        if (left < n){
            current.push_back('(');
            createString(current, n, left+1, right);
        }
        current.pop_back();
        if (right < left && right < n && left > 0){
            current.push_back(')');
            createString(current, n, left, right+1);
        }
    }
    vector<string> generateParenthesis(int n) {
        if (n == 0){
            return sol;
        }
        string current;
        current.push_back('(');
        createString(current, n, 1, 0);
        return sol;
    }
};
