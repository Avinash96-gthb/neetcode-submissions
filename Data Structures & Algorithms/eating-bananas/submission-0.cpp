class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(), piles.end());
        int left = 1;
        int right = piles[piles.size() - 1];
        int res = right;
        while (left <= right) {
            int mid = (left + right)/2;
            long long totalHoursNeeded = 0;
            for (int pile: piles){
                totalHoursNeeded += ceil(static_cast<double>(pile)/mid);
            }
            if (totalHoursNeeded <= h){
                res = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return res;

    }
};
