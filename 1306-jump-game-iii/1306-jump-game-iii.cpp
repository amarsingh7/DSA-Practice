class Solution {
public:
    bool visited[500001];
    bool canReach(vector<int>& arr, int start) {
        int n= arr.size();
        
        if(start<0 || start>=n || arr[start]<0 || visited[start])
            return false;
        if(arr[start]==0)
            return true;
        visited[start]= true;
        
        return canReach(arr, start+arr[start]) || canReach(arr, start-arr[start]);
        
    }
};