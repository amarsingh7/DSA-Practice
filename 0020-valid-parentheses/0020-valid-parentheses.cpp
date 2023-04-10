class Solution {
public:
    bool isValid(string s) {
        int a= s.size();
        stack<char> c;
    	for (int i = 0; i<a; i++)
    	{	
    		if (c.empty() || (((c.top() + 0) != (s[i] - 1)) && ((c.top() + 0) != (s[i] - 2))))
    			c.push(s[i]);
    		else c.pop();
    	}
    	return c.empty();
    }
};