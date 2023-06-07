class Solution {
public:
    int myAtoi(string s) {
        int n= s.size();
        int index=0;
        int sign=1;
        while(index<n and s[index]==' ')
            index++;
        if (index < n && (s[index] == '-' || s[index] == '+')) 
        {
            sign = (s[index] == '-') ? -1 : 1;
            index++;
        }
        int ans=0;
        while(index<n and isdigit(s[index])) {
            int digit = s[index] - '0';
            if (ans > INT_MAX / 10 || (ans== INT_MAX / 10 && digit > INT_MAX % 10))
                return (sign == 1) ? INT_MAX : INT_MIN;

            ans= ans*10 + digit;
            index++;
            
        }
        return ans*sign;
        
    }
};