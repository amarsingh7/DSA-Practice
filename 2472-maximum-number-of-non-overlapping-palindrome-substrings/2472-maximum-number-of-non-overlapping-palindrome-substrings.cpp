class Solution {
public:
    bool ispal(string s, int i, int j)
    {
        while(i <j)
        {
            if(s[i++] != s[j--])
                return false;
        }
        return true;
    }
    int maxPalindromes(string s, int k) {
        int ans=0;
        int n= s.size();
         
        for(int i=0; i<n; i++)
        {
            for(int j=i; j<n; j++)
            {
                int len= (j-i)+1;
                if(len>k+1)
                    break;
                if(len>=k and ispal(s, i, j))
                {
                    ans++; i= j;
                    break;
                }
                
            }
        }
        return ans;
    }
};