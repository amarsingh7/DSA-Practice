class Solution {
public:
    string largestGoodInteger(string num) {
        string ans="";
        int n= num.size();
        vector<string> arr = {"999", "888", "777", "666", "555", "444",
                                    "333", "222", "111", "000"};
        for (std::string s : arr) 
        {
            if(num.find(s) != std::string::npos) 
                return s;
        }

      return "";
    }
};