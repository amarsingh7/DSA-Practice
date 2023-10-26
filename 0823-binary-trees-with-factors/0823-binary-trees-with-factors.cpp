class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        int n= arr.size();
        int mod= 1e9+7;
        long ans=0;
        sort(arr.begin(), arr.end());
       
        unordered_map<int, long long> ump;
        ump[arr[0]]= 1;
        
        for(int i=1; i<n; i++)
        {
            int root= arr[i] ;
            ump[root]= 1;
            
            for(int j=0; j<i; j++)
            {
                if(root%arr[j]==0 and ump.find(root/arr[j]) != ump.end())
                    ump[root] += ump[arr[j]]*ump[root/arr[j]];
            }
        }
        for(auto x:ump)
        {
            ans= (ans+x.second) %mod;
        }
         return ans; 
    }
};
