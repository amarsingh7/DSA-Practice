class Solution {
public:
    int countElements(vector<int>& nums) {
        bool ans= false;
        int n= nums.size();
        int firstElement = nums[0];
        for (int i = 1; i < n; i++) 
        {
            if (nums[i] != firstElement) 
            ans=true; 
        }
        if(ans==false)
            return 0;
        int minval= *min_element(nums.begin(), nums.end());
        int maxval= *max_element(nums.begin(), nums.end());
    
        int min_count = std::count(nums.begin(), nums.end(), minval);
        int max_count = std::count(nums.begin(), nums.end(), maxval);
        int res = n - min_count - max_count;
        return res;
    }
};