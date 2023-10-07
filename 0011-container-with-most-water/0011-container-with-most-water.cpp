class Solution {
public:
    int maxArea(vector<int>& height) {
        int n= height.size();
        int ans=0, res=INT_MIN;
        
        int start=0, end= n-1;
        
        while(start<=end)
        {
            ans= min(height[start], height[end])*(end-start);
            if(ans>res)
                res= ans;
            if(height[start]<height[end])
                start++;
            else
                end--;
        }
        return res;
    }
};