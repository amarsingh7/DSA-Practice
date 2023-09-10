class Solution {
    map<vector<vector<int>>, int> visited;
public:
    
    int minFlips(vector<vector<int>>& mat) {
        if(mat.empty())
            return -1;
        queue<vector<vector<int>>> q;
        q.push(mat);
        visited[mat]= 1;
        int steps=0;
        while(!q.empty())
        {
            int l= q.size();
            for(int i=0; i<l; i++)
            {
                vector<vector<int>> v= q.front();
                q.pop();
                if(!check(v))
                    return steps;
                
                for(int i=0; i<v.size(); i++)
                {
                    for(int j=0; j<v[0].size(); j++)
                    {
                        vector<vector<int>> temp= v;
                        changeMat(temp, i, j);
                        if(!visited[temp])
                        {
                            q.push(temp);
                            visited[temp]=1;
                        }
                    }
                }
            }
            steps++;
        }
        return -1;
        
    }
    
    bool check(vector<vector<int>> &mat)
    {
        for(auto x:mat)
        {
            for(auto y:x)
            {
                if(y !=0)
                    return true;
            }
        }
        return false;
    }
    void changeMat(vector<vector<int>> &vec, int i, int j)
    {
        int m, n;
        m= vec.size();
        n= vec[0].size();
        
        vec[i][j]= !vec[i][j];
        
        if(i+1<m)
            vec[i+1][j]= !vec[i+1][j];
        if(i-1>=0)
            vec[i-1][j]= !vec[i-1][j];
        if(j+1<n)
            vec[i][j+1]= !vec[i][j+1];
        if(j-1>=0)
            vec[i][j-1]= !vec[i][j-1];
    }
    
};