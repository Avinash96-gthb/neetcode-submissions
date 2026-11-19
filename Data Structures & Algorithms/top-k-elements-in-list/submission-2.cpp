class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int num: nums){
            freq[num]++;
        }
        map<int, vector<int>> largerList;
        for (auto it = freq.begin(); it != freq.end(); it++){
            largerList[it->second].push_back(it->first);
        }
        vector<int> ans;
        int rem = k;
        for (auto it = largerList.rbegin(); it != largerList.rend(); it++){
            if (rem == 0){
                break;
            }
            for (int val: it->second){
                if (rem == 0){
                    break;
                }
                ans.push_back(val);
                rem--;
            }
        }
        return ans;
    }
};
