class ParkingSystem {
public:
    vector<int> limit, count;
    ParkingSystem(int big, int medium, int small) {
        this->limit= {big, medium, small};
        this->count= {0, 0, 0};
    } 
    
    bool addCar(int carType) {
        if(this->count[carType-1] < this->limit[carType-1])
        {
            this-> count[carType-1]++;
            return true;
        }
        return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */