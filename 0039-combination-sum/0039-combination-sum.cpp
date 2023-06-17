class Solution {
public:
    
    void search(vector<int>& num, int next, vector<int>& temp, int n, vector<vector<int> >& result)
    {
        if(n == 0)
        {
            result.push_back(temp);
            return;
        }
        
        if(n<0 || next==num.size())
            return;
            
        search(num, next+1, temp, n, result);
        temp.push_back(num[next]);
        
        search(num, next, temp, n- num[next], result);
        temp.pop_back();
    }
    
    vector<vector<int> > combinationSum(vector<int> &nums, int target) 
    {
        vector<vector<int> > result;
        sort(nums.begin(), nums.end());
        vector<int> temp;
        search(nums, 0, temp, target, result);
        return result;    
    }
};