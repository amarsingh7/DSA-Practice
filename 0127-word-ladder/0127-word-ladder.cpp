class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        int n= wordList.size();
        unordered_set<string> st(wordList.begin(), wordList.end());
        queue<string> q;
        int ladder=1;
        q.push(beginWord);
        
        while(!q.empty())
        {
            int n= q.size();
            for(int i=0; i<n; i++)
            {
                string s= q.front();
                q.pop();
                if(s==endWord)
                    return ladder;
                
                st.erase(s);
                for(int i=0; i<s.size(); i++)
                {
                    char c= s[i];
                    for(int j=0; j<26; j++)
                    {
                        s[i]= 'a'+ j;
                        if(st.count(s))
                            q.push(s);
                    }
                    s[i]= c;
                }
                
            }
             ladder++;
        }
        return 0;
    }
};