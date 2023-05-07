class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        
        int n = obstacles.size();
        vector<int> answer(n, 1), lis;
        
        for (int i = 0; i < n; ++i) 
        {
            int id = upper_bound(lis.begin(), lis.end(), obstacles[i])- lis.begin();
            if (id == lis.size())
                lis.push_back(obstacles[i]);
            else
                lis[id] = obstacles[i];
            answer[i] = id + 1;
        }
        return answer;
    }
};