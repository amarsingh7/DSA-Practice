class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int xs=0, xt=0;
        int ys=0, yt=0;
        xs= max(rec1[0], rec2[0]);
        ys= max(rec1[1], rec2[1]);
        xt= min(rec1[2], rec2[2]);
        yt= min(rec1[3], rec2[3]);
        if(xs<xt and ys<yt)
            return true;
        return false;
    }
};