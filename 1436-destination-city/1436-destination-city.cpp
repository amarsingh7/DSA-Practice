class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        vector<string> vec, bec;
        for(auto x:paths){
            vec.push_back(x[1]);
            bec.push_back(x[0]);
        }
            
        
        for(auto x:vec){
          if(find(bec.begin(), bec.end(), x) == bec.end())
              return x;
        }
        return "";
    }
};