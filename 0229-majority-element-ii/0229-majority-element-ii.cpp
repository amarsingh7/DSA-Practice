class Solution {
public:
    
    vector<int> majorityElement(vector<int>& nums) {
        vector <int> v;
        // unordered_map<int, int> mp;  // O(n) space
        // for(int i=0; i<nums.size(); i++)
        // {
        //     mp[nums[i]]++;
        // }
        // for(auto x:mp)
        // {
        //     if(x.second >floor(nums.size()/3))
        //     {
        //         v.push_back(x.first);
        //     }
        // }
        // return v;
        int num1= -1, num2= -1, c1=0, c2=0;   // O(1) space
        int s = nums.size();
        for(int i=0; i<s; i++)
        {
            if(nums[i]==num1)
                c1++; 
            else if(nums[i]==num2)
                c2++;
            else if(c1==0)
            {
                num1 = nums[i]; c1=1;
            }
            else if(c2 ==0)
            {
                num2 = nums[i]; c2=1;
            }
            else 
            {
                c1--; c2--;
            }
        }
        
        c1 = c2 =0;
        for(int i=0; i<s; i++)
        {
            if(nums[i]== num1)
                c1++;
            else if(nums[i]== num2)
                c2++;
        }
        if(c1 > s/3)
            v.push_back(num1);
        if(c2 > s/3)
            v.push_back(num2);
        
        return v;
            
    }
};