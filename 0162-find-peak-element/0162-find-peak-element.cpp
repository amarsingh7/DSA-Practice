class Solution {
public:
    int findPeakElement(vector<int>& arr) {
        int n= arr.size();
        
        int start=0;
        int end= n-1;
        while(start<end-1)
        {
            int mid= (start+end) /2;
            if(arr[mid]>arr[mid+1] and arr[mid] >arr[mid-1])
                return mid;
            else if(arr[mid]>arr[mid+1])
                end= mid-1;
            else
                start= mid+1;
        }
        return arr[start]>arr[end] ? start:end;
    }
};