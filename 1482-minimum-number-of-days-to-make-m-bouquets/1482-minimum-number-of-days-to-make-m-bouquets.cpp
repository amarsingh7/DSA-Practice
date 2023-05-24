class Solution {
public:
    
    int minDays(vector<int>& bday, int m, int k) {
        if((long long)m*k >bday.size())
            return -1;
        int n= bday.size();
        //sort(bday.begin(), bday.end());
        int start=1, end= 1e9;
        while(start<end)
        {
            int mid= (end+start)/2;
            int flow=0;
            int ans=0;
            for(int j=0; j<n; j++)
            {
                if(bday[j]> mid)
                    flow=0;
                else if(++flow>=k)
                {
                    ans++;
                    flow=0;
                }
                
            }
            if(ans<m)
                start= mid+1;
            else
                end= mid;
        }
        return start;
    }
};