class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n= bank.size();
        int ans=0;
        int count=0;
        vector<int> vec;
        for(auto x:bank)
        {
            count=0;
            for(int i=0; i<x.size(); i++)
            {
                if(x[i]=='1')
                    count++;
            }
            if(count>0)
                vec.push_back(count);
        }
        if(vec.size()==0)
            return 0;
        for(int i=0; i<vec.size()-1; i++)
        {
            ans+= vec[i]*vec[i+1];
        }
        return ans;
    }
};