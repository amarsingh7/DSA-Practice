class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int zerocnt=0;
        int start=0;
        int longwind=0;
        
        for(int i=0; i<nums.size(); i++)
        {
            zerocnt+= (nums[i]==0);
            while(zerocnt>1)
            {
                zerocnt -= (nums[start]==0);
                start++;
            }
            longwind= max(longwind, i-start);
        }
        return longwind;
    }
};