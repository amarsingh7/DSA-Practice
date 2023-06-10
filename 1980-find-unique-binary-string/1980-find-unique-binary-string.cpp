class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
       
       int n= nums.size();
       string ans="";
       for(int i=0; i<n; i++)
       {
           ans+= nums[i][i]=='1'? '0':'1';
           /* nums.length and the nums[i].length are same so thats why it worked. */
       }
        return ans;
    }
};