class Solution {
public:
    int shortestSequence(vector<int>& rolls, int k) {
        int n= rolls.size();
        unordered_map<int, int> ump;
        int count=0, res=0;
        for(auto x:rolls)
        {
            ump[x]++;
            if(ump[x]==1)
                count++;
            if(count==k)
            {
                res++;
                ump.clear();
                count=0;
            }
        }
         return res+1; 
    }
};