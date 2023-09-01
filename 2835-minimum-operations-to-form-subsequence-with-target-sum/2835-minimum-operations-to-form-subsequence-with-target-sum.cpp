class Solution {
public:
    int minOperations(vector<int>& nums, int target) {
        long long sum= accumulate(nums.begin(), nums.end(), 0L);
        long long count=0;
        if(sum<target)
            return -1;
        sort(nums.begin(), nums.end());
        while(target>0)
        {
            int last= nums.back();
            nums.pop_back();
            if(sum-last>= target)
                sum-= last;
            else if(last<=target)
                sum-= last, target-= last;
            else
            {
                nums.push_back(last/2);
                nums.push_back(last/2);
                count++;
            }
        }
        return count;
    }
};