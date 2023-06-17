class Solution {
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        auto& s = arr1;
		auto& t = arr2;
		
		if (s.empty()) return 0;
		
		sort(t.begin(), t.end());
		t.resize(unique(t.begin(), t.end()) - t.begin());

		int m = arr1.size();
		int n = arr2.size();
		
		vector<vector<int>> f(m, vector<int>(n, INT_MAX));
		vector<int> g(m, INT_MAX);

		for (int i = 0; i < n; i++) 
			f[0][i] = 1;
		
		g[0] = 0; 

		for (int i = 1; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (t[j] > s[i - 1]) { 
					f[i][j] = min(g[i - 1], INT_MAX - 1) + 1;
				}
				if (j > 0) {
					f[i][j] = min(f[i][j], min(f[i - 1][j - 1], INT_MAX - 1) + 1);
				} 
			}
			if (s[i] > s[i - 1]) {
				g[i] = g[i - 1];
			} 
            else {
				g[i] = INT_MAX;
			}
			for (int j = 0; j < n; j++) {
				if (t[j] < s[i]) {
					g[i] = min(g[i], f[i - 1][j]);
				}
			}
		}
		int ans = min(g[m - 1], *min_element(f[m - 1].begin(), f[m - 1].end()));
		return ans == INT_MAX ? -1 : ans;
	
    }
};