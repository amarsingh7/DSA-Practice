class Solution {
public:
    vector<int> rsort(vector<int> &nums)
    {
        int arr[50001]={0};
        int arr1[50001]={0};
        for(auto it:nums){
            if(it<0)arr1[abs(it)]++;
            else arr[it]++;
        }
        vector<int>ans;
        for(int i=50000;i>=0;i--){
            if(arr1[i]>0){
                for(int j=0;j<arr1[i];j++)ans.push_back(-i);
            }
        }
        for(int i=0;i<50001;i++){
            if(arr[i]>0){
                for(int j=0;j<arr[i];j++)ans.push_back(i);
            }
        }
        return ans;
    }
    vector<int> sortArray(vector<int>& amar) {
        return rsort(amar);
    }
};