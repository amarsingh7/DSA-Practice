class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        int n= asteroids.size();
        
        for(auto ast: asteroids)
        {
           int flag= 1;
           while(!st.empty() and (st.top() >0 and ast <0))
           {
               if(abs(st.top()) < abs(ast)){
                   st.pop(); continue;
               }
                   
               if(abs(st.top()) == abs(ast))
                   st.pop();
               flag=0;
               break;
           }
           if(flag)
               st.push(ast);
        }
        vector<int> ans;
        while(!st.empty())
            ans.push_back(st.top()), st.pop();
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};