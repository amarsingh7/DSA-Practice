class Solution {
public:
    int mod= 1e9+ 7;
    
    int count(int i, int seats, string &corridor, int cache[][3])
    {
        if(i==corridor.length())
            return seats==2? 1:0;
        if(cache[i][seats] != -1)
            return cache[i][seats];
        
        int res=0;
        if(seats==2)
        {
            if(corridor[i]=='S')
                res= count(i+1, 1, corridor, cache);
            else
            {
                res= (count(i+1, 0, corridor, cache) + count(i+1, 2, corridor, cache))% mod;
            }
        }
        else
        {
            if(corridor[i]=='S')
                res= count(i+1, seats+1, corridor, cache);
            else
                res= count(i+1, seats, corridor, cache);
        }
        
        cache[i][seats]= res;
        return cache[i][seats];
    }
    int numberOfWays(string corridor) {
        int cache[corridor.length()][3];
        
        memset(cache, -1, sizeof(cache));
        
        return count(0, 0, corridor, cache);
        
    }
};