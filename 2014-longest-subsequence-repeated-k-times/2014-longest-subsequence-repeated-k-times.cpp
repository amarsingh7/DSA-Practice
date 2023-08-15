class Solution {
public:
    int count_oc(string sub, string s) {
    if (sub.length() == 0) 
        return s.length();  
    // If substring is empty, it can appear as many times as the length of 's'
    
    int ind = 0;  // Current pointer in 'sub'
    int cntr = 0; // Number of times 'sub' appears as a substring
    
    for (int i = 0; i < s.length(); i++) 
    {
        if (sub[ind] == s[i]) 
        {   // If the current characters match
            ind++; 
            if (ind == (int)sub.length())  
            // If the entire 'sub' is found, reset the pointer and increment counter
                ind = 0, cntr++;
        } 
    }
    
    return cntr;  // Return the count of occurrences of 'sub' in 's'
}

string best;  // To store the longest subsequence found

void rec(string sub, string s, int k) {
    if (count_oc(sub, s) < k) 
        return;  // If 'sub' doesn't occur 'k' times, stop generating subsequence
    
    if (sub.length() >= best.length() && sub > best) 
        best = sub;  
    // Update 'best' if current subsequence is longer & lexicographically greater
    
    for (char c = 'a'; c <= 'z'; c++) 
        rec(sub + c, s, k);  
    // Recursively generate new subsequence by appending 'c' and check
    
    // The recursive function explores all possible subsequences
}

string longestSubsequenceRepeatedK(string s, int k) {
    rec("", s, k);  // Start generating subsequences from an empty subsequence
    return best;  // Return the 'best' found subsequence
}

};