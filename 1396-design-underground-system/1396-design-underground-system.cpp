class UndergroundSystem {
private:
    using Note = tuple<string, int>;
    using Notes = unordered_map<int, Note>;
    Notes notes; // { id: { source-station, check-in time }}
    using Edge = tuple<double, int>;
    using Edges = unordered_map<string, unordered_map<string, Edge>>;
    Edges edges; // { source: { destination: { total time, count of time entries }}}
public:
    void checkIn(int id, string s1, int t1) {
        notes[id] = {s1, t1};
    }
    void checkOut(int id, string s2, int t2) {
        auto [s1, t1] = notes[id];
        auto& [total, cnt] = edges[s1][s2]; 
        total += (t2 - t1), ++cnt;
    }
    double getAverageTime(string s1, string s2) {
        auto [total, cnt] = edges[s1][s2];
        return total / cnt;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */