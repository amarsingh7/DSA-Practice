class Solution {
public:
    long long mirror(long long ans) {
    string str = to_string(ans);
    int i = 0;
    int j = str.length() - 1;
    while (i < j)
        str[j--] = str[i++];
    return stoll(str);
}

string nearestPalindromic(string n) {
    int order = pow(10, n.length() / 2);
    long long ans = stoll(n);
    long long noChange = mirror(ans);
    long long larger = mirror((ans / order) * order + order + 1);
    long long smaller = mirror((ans / order) * order - 1);

    if (noChange > ans) {
        larger = min(noChange, larger);
    } 
    else if (noChange < ans) {
        smaller = max(noChange, smaller);
    }

    return to_string(ans - smaller <= larger - ans ? smaller : larger);
}
};