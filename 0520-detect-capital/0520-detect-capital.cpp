class Solution {
public:
    bool detectCapitalUse(string word) {
        // int n= word.size();
        // int count=0;
        // for(int i=0; i<n; i++)
        //         if(int(word[i])<90)
        //             count++;
        // if(count==n) return true;
        // if(count<n)
        // {
        //     for(int i=0; i<n; i++)
        //         if(word[0]<90 && word[i]<90)
        //             return false;
        //         else
        //             return true;
        // }
        // return false;
        for(int i = 1; i < word.size(); i++)
        {
        if(isupper(word[1]) != isupper(word[i]) || 
           islower(word[0]) && isupper(word[i])) return false;
        }        
    return true;
    }
};