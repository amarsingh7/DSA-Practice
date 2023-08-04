//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	    void subsequence(vector<string> &vec, string s, string &cur, int index)
	    {
	        if(index== s.length())
	        {
	            if(cur.size() >=1)
	                vec.push_back(cur);
	            return;
	        }
	        subsequence(vec, s, cur, index+1);
	        cur.push_back(s[index]);
	        subsequence(vec, s, cur, index+1);
	        cur.pop_back();
	    }
		vector<string> AllPossibleStrings(string s){
		    // Code here
		    vector<string> vec;
		    int n= s.size();
		    string cur="";
		    subsequence(vec, s, cur, 0);
		    sort(vec.begin(), vec.end());
		    return vec;
		}
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends