class Solution {
public:
    
    bool arithmetic(vector<int> &x)
    {
        sort(x.begin(), x.end());
        if(x.size()==2)
            return true;
        int a= x[0];
        int b= x[1];
        bool check= false;
        for(int i=1; i<x.size()-1; i++){
            if((x[i+1]-x[i])  != (b-a))
                return false;
        }
            
        return true;
    }
        
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int n= nums.size();
        int m= l.size();
        
        vector<bool> res;
        
        for(int i=0; i<m; i++)
        {
            vector<int> arr(nums.begin()+l[i], nums.begin()+r[i]+1);
            sort(arr.begin(), arr.end());
            
            res.push_back(arithmetic(arr));
        }
        
        
        return res;
    }
};