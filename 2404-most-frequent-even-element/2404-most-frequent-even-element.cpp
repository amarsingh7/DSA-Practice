class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        int ans= -1;
        
        int n= nums.size();
        int ansbc= -1;
        map<int, int> m;
        for(int i=0; i<n; i++)
        {
            m[nums[i]]++;
        }
        for(auto x:m)
        {
            int lolbc= int(x.first);
            if(lolbc %2==0 && x.second> ansbc)
            {
                ansbc= x.second;
                ans= x.first;
            }
        }
        return ans;
    }
};