class Solution {
public:
    int longestOnes(vector<int>& arr, int m) {
        int i=0;
        int j=0;
        int ans = 0;
        int n= arr.size();
        while(j<n)
        {
            
            if(arr[j]==0){
                m--;
            }
            
            if(m >= 0){
                ans = max(ans, j-i+1);
            }
            
            else if(m<0)
            {
                while(m<0){
                    if(arr[i]==0){
                        m++;
                    }
                    i++;
                }
            }
            
            if(m >= 0){
                ans = max(ans, j-i+1);
            }
            
            j++;
        }
        
        return ans;
    }
};