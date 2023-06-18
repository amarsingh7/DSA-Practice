class Solution {
public:
    void search(vector<int>& num, int next, vector<int>& temp, int n, vector<vector<int> >& result) {
    if (n == 0) {
        result.push_back(temp);
        return;
    }

    if (n < 0 || next == num.size())
        return;

    for (int i = next; i < num.size(); i++) {
        if (i > next && num[i] == num[i - 1])
            continue;
        
        temp.push_back(num[i]);
        search(num, i + 1, temp, n - num[i], result);
        temp.pop_back();
    }
}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int> > result;
        sort(candidates.begin(), candidates.end());
        vector<int> temp;
        search(candidates, 0, temp, target, result);
        return result;  
    }
};