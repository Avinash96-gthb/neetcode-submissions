class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> final;
        int arr1 = 0;
        int arr2 = 0;
        while (arr1 < nums1.size() && arr2 < nums2.size()){
            if (nums1[arr1] <= nums2[arr2]){
                final.push_back(nums1[arr1]);
                arr1++;
            } else {
                final.push_back(nums2[arr2]);
                arr2++;
            }
        }
        while (arr1 < nums1.size()){
            final.push_back(nums1[arr1]);
            arr1++;
        }
        while (arr2 < nums2.size()){
            final.push_back(nums2[arr2]);
            arr2++;
        }
        if (final.size() % 2 == 0){
            int center = final.size() / 2;
            cout << "the two values are" << final[center] << final[center-1];
            return double(double(final[center] + final[center - 1])/2.0);
        } else {
            int center = final.size() / 2;
            return double(final[center]);
        }
    }
};
