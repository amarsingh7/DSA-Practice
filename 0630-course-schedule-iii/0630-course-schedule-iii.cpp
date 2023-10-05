class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        int n= courses.size();
        int ans=0;
        long long sumd=0;
        sort(courses.begin(), courses.end(), [](vector<int>&a, vector<int> &b){
           return a[1]<b[1];
        });
        priority_queue<int> pq;
        
        for(auto x:courses)
        {
            sumd+= x[0]; 
            pq.push(x[0]);
            
            if(sumd > x[1])
                sumd-= pq.top(), pq.pop(); 
        } 
         
        return pq.size();
        
    }
};