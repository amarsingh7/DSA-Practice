class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int s= nums.size();
        unsigned int shift = 1;
        unsigned int ans = 0;
        
        for (int i = 0; i < 32; ++i) {
            int count = 0;
            for (int i : nums) 
                if (i & shift)
                    count += 1;
            if ((count % 3) != 0)
                ans = ans + shift;
            shift <<= 1;
        }
        
        return ans;
    }
};