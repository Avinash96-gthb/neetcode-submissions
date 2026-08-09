class Solution {
public:
   vector<vector<string>> sol;


   void dfs(int i, string s, vector<string>& part){
    if (i >= s.size()){
        sol.push_back(part);
        return;
    }

    for (int j = i; j < s.size(); j++){
        if (isPali(s, i, j)){
            part.push_back(s.substr(i, j - i + 1));
            dfs(j + 1, s, part);
            part.pop_back();
        }
    }

   }

   bool isPali(const string& s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }

    
    vector<vector<string>> partition(string s) {
        vector<string> part;
        dfs(0, s, part);
        return sol;
        
    }
};
