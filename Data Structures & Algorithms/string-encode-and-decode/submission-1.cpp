class Solution {
public:

    string encode(vector<string>& strs) {
        string ans;
        for (string s: strs){
            ans += to_string(s.size());
            ans += "#";
            ans += s;
        }
        return ans;
    }

    string decodeIndividualString(string s, int size, int currentIndex){
        string ans;
        for (int i = currentIndex + 2; i <= currentIndex + size + 1; i++){
            ans += s[i];
        }
        return ans;
    }

    //5 # H E L L O 4 #

    vector<string> decode(string s) {
        vector<string> ans;
        int i = 0;
        while (i < s.size()){
            int j = i;
            while (s[j] != '#'){
                j++;
            }
            int val = stoi(s.substr(i,j-i));
            i = j+1;
            j = i + val;
            ans.push_back(s.substr(i, val));
            i = j;
        }
        return ans;
    }
};
