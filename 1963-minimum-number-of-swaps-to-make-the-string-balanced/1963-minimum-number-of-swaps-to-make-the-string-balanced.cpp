class Solution {
public:
    int minSwaps(string s) {
        stack<char> st;
        int n= s.size();
        int size=0;
        for(auto x:s)
        {
            if(x == '[')      size++;
            else if(size != 0) size--;
        }
        
        return (size+1)/2;
    }
};