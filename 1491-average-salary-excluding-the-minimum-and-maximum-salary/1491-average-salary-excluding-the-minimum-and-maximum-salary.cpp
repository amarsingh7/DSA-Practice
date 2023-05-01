class Solution {
public:
    double average(vector<int>& salary) {
        double ans=0;
        int n= salary.size();
        long double add=0;
        sort(salary.begin(), salary.end());
        for(int i=1; i<n-1; i++)
        {
            add+= salary[i];
        }
        ans= (double)(add/(n-2));
        return ans;
    }
};