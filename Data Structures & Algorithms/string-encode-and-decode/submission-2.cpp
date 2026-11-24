class Solution {
public:

    string encode(vector<string>& strs) {
        string res;
        for (string word: strs){
            string sizeOfWord = to_string(word.size());
            res += sizeOfWord + ':' + word;
        }
        return res;
    }

    // 6:happpy index: 7  start index: 2, endIndex = 6 + 2 - 1

    vector<string> decode(string s) {
        vector<string> res;
        int i = 0;
        while (i < s.size()){
            string sizeOfWord;
            while (s[i] != ':'){
                sizeOfWord += s[i];
                i++;
            }
            int countOfWord = stoi(sizeOfWord);
            int startIndex = i+1;
            int endIndex = startIndex + countOfWord - 1;
            string word = s.substr(startIndex, countOfWord);
            res.push_back(word);
            i = endIndex + 1;
            

        }
        return res;
    }
};
