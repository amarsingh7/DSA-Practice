class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n= arr.size();
        if(n==1 || n==2)
            return arr[0];
        int count=0;
        unordered_map<int, int> mp;
        
        for(auto x:arr)
            mp[x]++;
        
        for(auto x:mp)
            if(n/x.second <=4)
                return x.first;
        return 0;
    }
};