class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        int n= arr.size();
        int mod= 1e9+7;
        long long psum=0, pmax=0, ssum=0, smax=0, cbest=0, obest=0;
        
        for(int i=0; i<n; i++)
        {
            // prefix sum
            psum+= arr[i];
            pmax= max(pmax, psum);
            
            // suffix sum
            ssum+= arr[n-1-i];
            smax= max(ssum, smax);
            
            // kadane's algorithm
            cbest= max(cbest, 0LL) +arr[i];
            obest= max(obest, cbest);
        }
        long long res= max(obest, pmax+smax+ max(0LL ,psum*(k-2)%mod)); 
        return (int)((k==1? obest: res)%mod);
    }
};


