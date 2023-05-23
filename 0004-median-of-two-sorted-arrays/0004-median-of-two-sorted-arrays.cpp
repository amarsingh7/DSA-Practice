class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i=0;
        int j=0, k=0;
        int n= nums1.size(), m= nums2.size();
        vector<int> mergd(n+m);
        while(i<n and j<m)
        {
            if(nums1[i]<nums2[j])
                mergd[k++]= nums1[i++];
            
            else
                mergd[k++]= nums2[j++];
            
        }
        while(i<n)
             mergd[k++]= nums1[i++];
        
        while(j<m)
             mergd[k++]= nums2[j++];
    
        int sz= mergd.size();
        if(sz%2==0)
            return (mergd[sz/2 -1]+mergd[(sz+2)/2 -1])/2.0;
        return mergd[(sz+1)/2 -1];
            
    }
};