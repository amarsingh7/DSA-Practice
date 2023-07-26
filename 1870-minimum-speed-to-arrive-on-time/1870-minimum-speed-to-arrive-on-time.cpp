class Solution {
public:
    double treq(vector<int> &dist, int speed)
    {
        double time= 0.0;
        for(int i=0; i<dist.size(); i++)
        {
            double t= (double)dist[i]/ (double)speed;
            time+= (i== dist.size() -1 ?t:ceil(t));
        }
        return time;
    }
    
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int left=1;
        int right= 1e7;
        int minspeed= -1;
        while(left<=right)
        {
            int mid= left+(right-left)/2;
            if(treq(dist, mid) <=hour)
            {   // left half;
                minspeed= mid;
                right= mid-1;
            }
            else
                left= mid+1; // right half;
        }
        return minspeed;
    }
};