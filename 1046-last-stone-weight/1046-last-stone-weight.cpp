class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n= stones.size();
        if(n==1)
            return stones[0];
        priority_queue<int> pq(begin(stones), end(stones));
        
        while(pq.size()>1)
        {
            int x= pq.top(); pq.pop();
            int y= pq.top(); pq.pop();
            if(x>y)
                pq.push(x-y);
        }
        return pq.size()==0? 0:pq.top();
    }
};