class Solution {
public:
    int candy(vector<int>& ratings) {
        int n= ratings.size();
        int res=0;
        if(n==1)
            return 1;
        vector<int> vec(n, 1);  // set kro min no. of candy sabka
        // aage se kro fir peeche se krlo ya vice-versa
        
        for(int i=1; i<n; i++)
        {
            if(ratings[i]>ratings[i-1])
                vec[i]= vec[i-1]+1;
            
        }
        for(int i= n-1; i>0; i--)
        {
            if(ratings[i-1]>ratings[i])
                vec[i-1]= max(vec[i-1], vec[i]+1);
        }
        
        for(auto x:vec)
            res+= x;
        return res;
    }
};