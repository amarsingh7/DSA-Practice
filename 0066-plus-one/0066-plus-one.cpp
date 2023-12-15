class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n= digits.size();
        if(digits[n-1] != 9)
        {
            digits[n-1]++;
            return digits;
        }
        int count=0;
        for(auto x:digits)
            if(x==9)
                count++;
        vector<int> ans(n+1, 0);
        ans[0]= 1;
        if(count==n)
            return ans;
        int i=n-1;
        while(i>=0)
        {
            while(digits[i]==9)
            {
                digits[i]=0;
                i--;
            }
            digits[i]+= 1;
            break;
        }
        return digits;
    }
};