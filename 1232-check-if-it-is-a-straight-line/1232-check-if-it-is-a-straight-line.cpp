class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coor) {
        int r = coor.size();
        int c = 2;
        int num = coor[1][1] - coor[0][1];
        int deno = coor[1][0] - coor[0][0];

        if (deno == 0) {
            for (int i = 2; i < r; i++) {
                if (coor[i][0] != coor[0][0])
                    return false;
            }
            return true;
        }

        double m = (double)(num) / deno; 
        bool ans = true;

        for (int i = 1; i < r; i++) 
        {
            for (int j = i + 1; j < r; j++) 
            {
                double slope = (double)(coor[j][1] - coor[i][1]) / (coor[j][0] - coor[i][0]);
                if (slope != m)
                    ans = false;
            }
        }

        return ans;
    }
};