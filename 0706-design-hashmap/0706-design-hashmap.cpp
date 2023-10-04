class MyHashMap {
public:
    vector<pair<int, int>> vp;
    MyHashMap() { 
        
    }
    
    void put(int key, int value) {
        bool check= false;
        for(int i=0; i<vp.size(); i++)
        {
            if(vp[i].first == key){
                check= true;
                vp[i].second= value;
            } 
        }
        if(check== false)
            vp.push_back({key, value});
    }
    
    int get(int key) {
        for(auto x:vp)
            if(x.first== key)
                return x.second;
        return -1;
    }
    
    void remove(int key) {
        for(int i=0; i<vp.size(); i++)
        {
            if(vp[i].first == key)
                vp.erase(vp.begin()+i);
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */