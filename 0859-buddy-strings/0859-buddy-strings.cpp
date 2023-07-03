class Solution {
public:
   bool buddyStrings(string A, string B) {
    if (A.length() != B.length()) {
        return false;
    }
    
    if (A == B) {
        set<char> uniqueChars(A.begin(), A.end());
        return uniqueChars.size() < A.size();
    }
    
    vector<int> dif;
    for (int i = 0; i < A.length(); ++i) {
        if (A[i] != B[i]) {
            dif.push_back(i);
        }
    }
    
    return dif.size() == 2 && A[dif[0]] == B[dif[1]] && A[dif[1]] == B[dif[0]];
}

};