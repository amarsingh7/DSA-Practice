class Solution {
public:
    int firstoc(vector<int> arr, int n, int x)
{
    int start=0;
    int end=n-1;
    int first=-1;
    while(start<=end)
    {
        int mid= start +(end-start)/2;
        if(arr[mid]==x)
        {
            first= mid;
            end=mid-1;
        }
        else if(arr[mid]<x)
            start= mid+1;
        else
            end= mid-1;
    }
    return first;
}
int lastoc(vector<int> arr, int n, int x)
{
    int start=0;
    int end=n-1;
    int second=-1;
    while(start<=end)
    {
        int mid= start +(end-start)/2;
        if(arr[mid]==x)
        {
            second= mid;
            start= mid+1;
        }
        else if(arr[mid]<x)
            start= mid+1;
        else
            end= mid-1;
    }
    return second;
}
    vector<int> searchRange(vector<int>& nums, int x) {
        vector<int> v(2);
        int n= nums.size();
        v[0]= firstoc(nums, n, x);
        v[1]= lastoc(nums, n, x);
        return v;
    }
};