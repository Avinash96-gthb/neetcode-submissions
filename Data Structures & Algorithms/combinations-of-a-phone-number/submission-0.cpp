class Solution {
public:
    unordered_map<char, vector<char>> keys = {
        {'2', {'a', 'b', 'c'}},
        {'3', {'d', 'e', 'f'}},
        {'4', {'g', 'h', 'i'}},
        {'5', {'j', 'k', 'l'}},
        {'6', {'m', 'n', 'o'}},
        {'7', {'p', 'q', 'r', 's'}},
        {'8', {'t', 'u', 'v'}},
        {'9', {'w', 'x', 'y', 'z'}}
    };

    vector<string> sol; 

    void dfs(int i, string& current, string& digits){
        if (i >= digits.size()){
            sol.push_back(current);
            return;
        }

        vector<char> chars = keys[digits[i]];
        for (char b: chars){
            current.push_back(b);
            dfs(i+1, current, digits);
            current.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0){
            return sol;
        }
        string current;
        dfs(0, current, digits);
        return sol;
    }
};
