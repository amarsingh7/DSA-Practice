#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
    int tc;
        cin >> tc;
    while(tc--)
    {
        int n;
            cin >> n;
        vector<int> vc(n);
        for(int i=0; i<n; i++)
        {
            cin >> vc[i];
        }
        unordered_map<int, int> ump;
        for(auto x:vc)
            ump[x]++;
        sort(vc.begin(), vc.end(), [&](int a, int b){
            return ump[a]== ump[b]? a>b: ump[a]< ump[b];
        });
        reverse(vc.begin(), vc.end());
        for(auto x:vc)
        cout <<x <<" ";
        cout << endl;
    }
	return 0;
}