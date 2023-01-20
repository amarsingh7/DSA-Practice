class Solution {
public:
    void func(int idx,vector<int>&nums,vector<int>&a,set<vector<int>>&ans){
        int n=nums.size();
        if(idx>=n)
        {
            if(a.size()>=2){
                ans.insert(a);
            }
            return ;
        }
        
        if(!a.size()||nums[idx]>=a.back())
        {
            //we will push back into a vector and then call the func for idx+1;
            a.push_back(nums[idx]);
            func(idx+1,nums,a,ans);
            //we are removing element because a vector is being passed by reference
            a.pop_back();
        }
        //calling the function without that value
        func(idx+1,nums,a,ans); 
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        //we have made a temp vector for storing the values till an index
        vector<int>temp;
        set<vector<int>>ans;
        //we are calling our recursive function giving starting index to 0
        func(0,nums,temp,ans);
        //typecasting the set into vector and returning it we can do it manually also
        return vector(ans.begin(),ans.end());
        
    }
};