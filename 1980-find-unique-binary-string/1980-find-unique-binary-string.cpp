class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
       
        int n= nums[0].size();
        vector<string> vec;
        for(int i=0; i<pow(2, n); i++)
        {
            std::bitset<16> binary(i);
            string res= binary.to_string();
            vec.push_back(res.substr(16-n, n));
        }
        string ans="";
        for(int i=0; vec.size(); i++)
        {
            if(find(nums.begin(), nums.end(), vec[i])== nums.end())
            {
                ans+= vec[i];
                break;
            }
        }
        
        return ans;
    }
};