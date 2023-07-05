class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int i;
        int j=0;
        int n= answerKey.size();
        int res=0, ans=0;
        int pk=k;
        int p=0;
        for(i=0; i<n; i++)
        {
            if(answerKey[i]=='T')   k--;
            if(k<0 and answerKey[j++]=='T')
                k++;
            if(answerKey[i]=='F')   pk--;
            if(pk<0 and answerKey[p++]=='F')
                pk++;
        }
        // res= i-j;
        return max(i-j, i-p);
        // ans= i-p;
        // return max(res, ans);
    }
};