class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> arr(n, vector<int>(n, 0));
        int val=1;
        int dir=1;
        int top=0, bottom=n-1, left=0, right=n-1;
        while(top<=bottom && left<=right)
        {
            if(dir==1)
            {
              for(int i=left; i<=right; i++)
                  arr[top][i]= val++;
              top++;
              dir=2;  
            }
            else if(dir==2)
            {
              for(int i=top; i<=bottom; i++)
                  arr[i][right]= val++;
              right--;
              dir=3;  
            }
            else if(dir==3)
            {
                for(int i=right; i>=left; i--)
                    arr[bottom][i]= val++;
              bottom--;
              dir=4;
            }
            else if(dir==4)
            {
                for(int i=bottom; i>=top; i--)
                    arr[i][left]= val++;
              left++;
              dir=1;
            }     
            
        }
        return arr;
    }
};