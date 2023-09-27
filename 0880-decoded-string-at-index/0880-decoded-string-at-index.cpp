class Solution {
public:
    string decodeAtIndex(string s, int k) {
        string ans="";
        int n= s.size();
        
        long long total=0;
        for(int i=0; i<n; i++)
        {
            if(isdigit(s[i]))
                total= total * (s[i]-'0');
            else
                total+= 1;
        }
        
        for(int i=n-1; i>=0; i--)
        {
            if(isdigit(s[i]))
            {
                total /= s[i]-'0';
                k= k%total;
            }
            else
            {
                if(k==0 || total==k)
                    return string(1, s[i]);
                total--;
            }
        }
        
          return "fck" ;
    }
};