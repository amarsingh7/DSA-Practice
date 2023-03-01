class Solution {
public:
    void csort(vector<int> &nums)
    {
        unordered_map<int, int> um;
        int minv= *min_element(nums.begin(), nums.end());
        int maxv= *max_element(nums.begin(), nums.end());
        
        for(auto &i:nums)
        {
            um[i]++;
        }
            
        int index=0;
        for(int i=minv; i<=maxv; i++)
        {
            while(um[i]>0)
            {
                nums[index]=i;
                index +=1;
                um[i] -= 1;
            }
        }
    }
    vector<int> sortArray(vector<int>& amar) {
        csort(amar);
        return amar;
    }
};