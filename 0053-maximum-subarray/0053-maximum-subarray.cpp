class Solution {
public:
    int maxSubArray(vector<int>& arr) {
       int msf=arr[0], sum=0;
       int n= arr.size();
       for(int i=0;i<n;i++) //maximizing sum
       {
           sum+= arr[i];
           if(sum> msf)
               msf= sum;
           if(sum<= 0)
               sum= 0;
       }
       return msf;
    }
};