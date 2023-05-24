//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int solve(int m, int k, vector<int> &bday){
      // Code here
      if((long long)m*k >bday.size())
            return -1;
        int n= bday.size();
        //sort(bday.begin(), bday.end());
        int start=1, end= 1e9;
        while(start<end)
        {
            int mid= (end+start)/2;
            int flow=0;
            int ans=0;
            for(int j=0; j<n; j++)
            {
                if(bday[j]> mid)
                    flow=0;
                else if(++flow>=k)
                {
                    ans++;
                    flow=0;
                }
            }
            if(ans<m)
                start= mid+1;
            else
                end= mid;
        }
        return start;
      
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int m, k;
    cin >> m >> k;
    string s;
    getline(cin, s);
    getline(cin, s);
    int n = s.length();
    int num = 0;
    bool f = 0;
    vector<int> bloomDay;
    for (int i = 0; i < n; i++)
    {
      if (s[i] == ' ')
      {
        if (!f)
          continue;
        bloomDay.push_back(num);
        num = 0;
        f = 0;
      }
      else
      {
        num = (num * 10) + (s[i] - '0');
        f = 1;
      }
    }
    if (f)
    {
      bloomDay.push_back(num);
    }
    Solution obj;
    cout<<obj.solve(m, k, bloomDay)<<endl;
    }
    return 0;
}
// } Driver Code Ends