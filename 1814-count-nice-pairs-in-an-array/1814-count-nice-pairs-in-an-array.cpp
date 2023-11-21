class Solution {
public:
    int countNicePairs(vector<int>& A) {
        int res = 0, mod = 1e9 + 7;
        unordered_map<int, int> count;
        for (int& a : A){
            res = (res + count[a - rev(a)]) % mod;
            count[a-rev(a)]++;
        }
            
        return res;
    }
    int rev(int x) {
        string s= to_string(x);
        reverse(s.begin(), s.end());
        
        return stoi(s);
    }
};