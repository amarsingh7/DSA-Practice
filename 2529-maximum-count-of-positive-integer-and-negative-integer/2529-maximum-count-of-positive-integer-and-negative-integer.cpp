class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n= nums.size();
        int start=0;
        int end= n-1;
        
        int ntemp=-1;
        int ptemp= -1;
        while(start<=end)
        {

            int mid= start +(end-start)/2;
            
            if(nums[mid]<0)
            {
                start= mid+1;
                ntemp=mid;
            }
            else if(nums[mid]>=0)
            {
                end= mid-1;
            }
            
        }
        cout<<ntemp<<" ";
        start=ntemp+1; end=n-1;
        while(start<=end)
        {

            int mid= start +(end-start)/2;
            
            if(nums[mid]>0)
            {
                 ptemp=mid;
                end= mid-1;

            }
            else if(nums[mid]>=0)
            {
                start=mid+1;
            }
            
        }
        if(ntemp==-1){
            if(ptemp==-1){
                return 0;
            }
            else{
                return n-ptemp;
            }
        }//all pos or 0
        else{
          if(ptemp==-1){
                return ntemp+1;
            }
            else{
                return max(ntemp+1,n-ptemp);
            }
        }
        //  ptemp=n-ptemp;
        // return max(ptemp,ntemp);
    }
};
