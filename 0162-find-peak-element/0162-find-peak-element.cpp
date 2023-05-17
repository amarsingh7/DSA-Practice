class Solution {
public:
    int findPeakElement(vector<int>& arr) {
        int n= arr.size();
        int index=0;
        if(n==1)
            return 0;
        if(n==2)
        {
            return arr[0]>arr[1] ? 0:1;
        }
        for(int i=1; i<n-1; i++)
        {
            if(arr[i]>arr[i+1] and arr[i]>arr[i-1])
                index= i;
            if(arr[0]>arr[1])
                index= 0;
            if(arr[n-1]>arr[n-2])
                index= n-1;
        }
        return index;
    }
};