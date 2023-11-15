class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n= arr.size();
        if(arr[0]>=n)
            return n;
        arr[0]= 1;
        for(int i=1; i<n; i++)
        {
            if(arr[i]- arr[i-1]>1)
                arr[i]= arr[i-1]+1;
        }
        return *max_element(arr.begin(), arr.end());
    }
};