class Solution {
public:
    int computeArea(int a, int b, int c, int d, int e, int f, int g, int h) {
        
        int left= max(a, e);
        int bottom= max(b, f);
        
        int right= max(min(c, g), left);
        int top= max(min(d, h), bottom);
        
        return (c-a)*(d-b)+ (g-e)*(h-f) - (right-left)*(top-bottom);
    }
};