class Solution {
public:
    bool isPalindrome(string s) {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
     string t="";
     for(int i=0; i<s.size(); i++)
     {
         if(isalnum(s[i]))
             t+= s[i];
     }
     int left=0; 
     int right=t.size()-1;
        while(left<right)
            if(t[left++] !=t[right--])
                return false;
        return true;
        
     
        
    }
};