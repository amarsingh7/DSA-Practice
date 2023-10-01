class Solution {
public:
    int trap(vector<int>& ht) {
        int ans=0;
        int n= ht.size();
        
        int left=0, right= n-1;
        int leftmax= ht[left];
        int rightmax= ht[right];
        if(n<=2)
            return 0;
        
        while(left<right)
        {
            if(ht[left] <ht[right])
            {
                leftmax= max(leftmax, ht[++left]);
                ans+= leftmax- ht[left];
            }
            else
            {
                rightmax= max(rightmax, ht[--right]);
                ans+= rightmax- ht[right];
            }
        }
        return ans;
    }
};