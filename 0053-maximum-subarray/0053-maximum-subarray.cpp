class Solution {
public:
    int maxSubArray(vector<int>& arr) {
        // int cbest=INT_MIN, obest=0;
        // if(nums.size() ==1)
        //     return nums[0];
        // for( int it=0; it< nums.size(); it++)
        // {
        //     if(cbest >= 0)
        //         cbest += nums[it];
        //     else
        //         cbest = nums[it];
        //     if(cbest > obest)
        //         obest = cbest;
        // }
        // return obest;
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