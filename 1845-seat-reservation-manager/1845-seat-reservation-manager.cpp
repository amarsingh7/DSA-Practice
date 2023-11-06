class SeatManager {
public:
    priority_queue<int, vector<int>, greater<int> > availseats;
    
    SeatManager(int n) {
        for(int i=1; i<=n; i++)
        {
            availseats.push(i);
        }
    }
    
    int reserve() {
        int seatnum= availseats.top();
        availseats.pop();
        
        return seatnum;
    }
    
    void unreserve(int seatNumber) {
        availseats.push(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */