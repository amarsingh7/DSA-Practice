class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n= nums.size();
        int start=0; 
        int end= n-1;
        
        int ntemp= -1;
        int ptemp= -1;
        
        //Negative wala case
        while(start<=end)
        {
            int mid= start +(end- start)/2;
            if(nums[mid]<0)
            {
                start= mid+1;
                ntemp= mid;
            }
            else if(nums[mid]>=0)
                end= mid-1;
                
        }
        start= ntemp+1;
        end= n-1;
        //Positive wala case
        while(start<=end)
        {
            int mid= start +(end-start)/2;
            if(nums[mid]>0)
            {
                end= mid-1;
                ptemp= mid;
            }
            else if(nums[mid]>=0)
                start= mid+1;
        }
        //conclusion
        if(ntemp== -1)
        {
            if(ptemp== -1)
                return 0;
            else
                return n-ptemp;
        }
        else
        {
           if(ptemp== -1)
               return ntemp+1;
            return max(ntemp+1, n-ptemp);
        }
    }
};