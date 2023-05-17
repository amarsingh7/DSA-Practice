class Solution {
public:
    int findPeakElement(vector<int>& arr) {
        int n= arr.size();
        
        return max_element(arr.begin(), arr.end())- arr.begin();
    }
};