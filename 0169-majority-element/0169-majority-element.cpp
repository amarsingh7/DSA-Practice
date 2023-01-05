class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // Using O(n) space
     unordered_map<int, int> um;
        int ans;
        int n= nums.size();
        int p= floor(n/2);
        for(int i=0; i<nums.size(); i++)
            um[nums[i]]++;
        for(auto x:um)
        {
            if(x.second > p)
            {
                ans= x.first;
            }
        }
        return ans;
        
            
    }
};