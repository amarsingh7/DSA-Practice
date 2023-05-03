class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> ans;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        nums1.erase( unique( nums1.begin(), nums1.end() ), nums1.end() );
        nums2.erase( unique( nums2.begin(), nums2.end() ), nums2.end() );
        vector<int> resa;
        set_difference(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), back_inserter(resa));
        
        vector<int> resb;
        set_difference(nums2.begin(), nums2.end(), nums1.begin(), nums1.end(), back_inserter(resb));
        
        ans.push_back(resa);
        ans.push_back(resb);
        
        return ans;
    }
};