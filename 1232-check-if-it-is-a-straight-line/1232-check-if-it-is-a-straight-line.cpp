class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coor) {
        int r = coor.size();
        int c = 2;
        int num = coor[1][1] - coor[0][1];
        int deno = coor[1][0] - coor[0][0];     
	    for( int i=2; i < r; i++) 
        {
		    auto p = coor[i];
		    if( deno*(p[1] - coor[0][1]) != num*(p[0] - coor[0][0]) )
			    return false;
	    }
	    return true;
    }
};