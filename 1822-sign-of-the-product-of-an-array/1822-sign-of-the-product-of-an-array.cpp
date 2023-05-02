class Solution {
public:
    int arraySign(vector<int>& nums) {
        int n= nums.size();
        int cn=0;
        int cp=0;
        int co=0;
        for(auto i:nums)
        {
            if(i<0)
                cn++;
            else if(i>0)
                cp++;
            else
                co++;
        }
        if(co>=1)
            return 0;
        if(cn%2 !=0 and co<=0)
            return -1;
        return 1;
    }
};