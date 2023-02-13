class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> v;
        for(auto &it: nums)
        {
            string s= to_string(it);
            for(auto &itt: s)
                v.push_back(itt-'0');
        }
        return v;
    }
};