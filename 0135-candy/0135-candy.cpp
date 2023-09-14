class Solution {
public:
    int candy(vector<int>& ratings) {
        int n= ratings.size();
        int res=0;
        if(n==1)
            return 1;
        vector<int> vec(n, 1);
        
        for(int i=1; i<n-1; i++)
        {
            if(ratings[i]>ratings[i-1])
                vec[i]= vec[i-1]+1;
            
        }
        for(int i= n-1; i>0; i--)
        {
            if(ratings[i-1]>ratings[i])
                vec[i-1]= max(vec[i-1], vec[i]+1);
        }
        // if(ratings[0]>ratings[1])
        //     vec[0]= vec[1]+1;
        if(ratings[n-1]>ratings[n-2])
            vec[n-1]= vec[n-2]+1;
        for(auto x:vec)
            res+= x;
        return res;
    }
};