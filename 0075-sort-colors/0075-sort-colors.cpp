class Solution {
public:
    void sortColors(vector<int>& A) {
        //sort(nums.begin(), nums.end());
        int n= A.size();
        int j = 0, k = n-1;
    for (int i=0; i <= k; i++) 
    {
        if (A[i] == 0)
            swap(A[i], A[j++]);
        else if (A[i] == 2)
            swap(A[i--], A[k--]);
    }
    }
    
};