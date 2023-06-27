class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue< pair<int,vector<int> > >pq;
        for(int i=0; i<nums1.size() && i<k;i++)
        {
            pq.push({-(nums1[i]+nums2[0]), {i,0}});
        }
             
        vector< vector<int> >res;
        while(!pq.empty() && k--)
        {
            int i = pq.top().second[0];
            int j = pq.top().second[1];
            res.push_back({nums1[i],nums2[j]});
            pq.pop();
            if(j+1==nums2.size())
                continue;
            pq.push({-(nums1[i]+nums2[j+1]), {i,j+1}});            
        }
        return res;
    }
};