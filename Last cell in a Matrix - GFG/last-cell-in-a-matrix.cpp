//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    bool check (int i, int j, int n, int m)
    { 
        if(i<0 || j<0 || i>=n || j>=m) return false; 
        return true;
    }

pair<int, int> endPoints(vector<vector<int>> v, int n, int m) 
{ 
    int i=0, j=0; 
    char s = 'r'; 
    while(check(i,j,n,m))
    {
        if (v[i][j]==0)
        {
            if(s=='r') j++; 
            else if(s=='d') i++; 
            else if(s=='l') j--; 
            else i--;
        }

        else
        {
            if(s=='r'){s='d';}

        else if(s=='u'){s='r';} 
        else if(s=='l') {s='u';}

        else{s='l';}
        v[i][j]=0;
        }
    }


if(i<=0) i=0;

else if(i>=n) i=n-1;
if(j<=0) j=0;
else if(j>=m) j=m-1;

return {i, j};

}
};

//{ Driver Code Starts.


int main()
{
    int tc;
	scanf("%d", &tc);
	while(tc--){
		int row, col;
		scanf("%d", &row);
		scanf("%d", &col);
		vector<vector<int>> matrix(row , vector<int> (col));
	 
		for(int i = 0; i < row; i++){
			for(int j = 0; j < col; j++){
			    cin>>matrix[i][j];
			}
		}
		Solution obj;
		pair<int,int> p = obj.endPoints(matrix, row, col);
		
		cout << "(" << p.first << ", " << p.second << ")" << endl;
	}
	return 0;
}
// } Driver Code Ends