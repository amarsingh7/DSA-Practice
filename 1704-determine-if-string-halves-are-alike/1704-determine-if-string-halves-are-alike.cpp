class Solution {
public:
    bool halvesAreAlike(string s) {
        int n= s.size();
        int count1=0, count2=0;
        
        string p="";
        for(char c:s)
            p+= tolower(c);
        
        string vov= "aeiou";
        for(int i=0; i<n/2; i++)
        {
            if(find(vov.begin(), vov.end(), p[i]) != vov.end())
                count1++;
            if(find(vov.begin(), vov.end(), p[n-1-i]) != vov.end())
                count2++;
        }
        cout<< count1 << " " << count2;
        return count1==count2;
    }
};