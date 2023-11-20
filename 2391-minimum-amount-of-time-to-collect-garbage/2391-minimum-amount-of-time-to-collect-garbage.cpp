class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int n= garbage.size();
        int m= travel.size();
        int sum=0, count=0;
        map<char, int> mp;
        
        for(int i=0; i<n; i++)
        {
            count+= garbage[i].size();
            for(auto x:garbage[i])
                mp[x]= sum;
            if(i<travel.size())
                sum+= travel[i];
        }
        
        return count+ mp['M']+ mp['P']+ mp['G'];
    }
};