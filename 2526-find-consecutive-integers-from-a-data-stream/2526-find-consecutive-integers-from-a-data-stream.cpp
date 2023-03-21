class DataStream {
public:
    
    map<int, int> m;
    int val, size;
    DataStream(int value, int k) {
        val= value;
        size= k;
        m[value]= size;
    }
    
    bool consec(int num) {
        if(val==num)
            m[val]--;
        else
            m[val]=size;
        
        return m[val]<=0;
    }
    
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */