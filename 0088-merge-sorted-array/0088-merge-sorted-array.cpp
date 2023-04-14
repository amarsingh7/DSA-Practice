class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> v(m+n);
        int sz= nums1.size();
        int j=0;
        for(int i=m; i<(m+n) and j<n; i++)
        {
            nums1[i] += nums2[j];
            j++;
        }
        sort(nums1.begin(), nums1.end());
    }
};