class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        // int n= arr.size();
        // vector<int> v;
        // int i=1;
        // while(k>0)
        // {
        //     vector<int> ::iterator it;
        //     it= find(arr.begin(), arr.end(), i);
        //     if(it != arr.end())
        //         i++;
        //     else
        //     {
        //         k--; i++;
        //     }
        // }
        // return i-1;
        int l=0, r= arr.size(), m;
        while(l<r)
        {
            m= (l+r)/2;
            if(arr[m]-m-1 <k)
                l=m+1;
            else
                r=m;
        }
        return l+k;
        
    }
};