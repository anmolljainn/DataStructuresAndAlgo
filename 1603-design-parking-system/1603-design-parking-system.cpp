class ParkingSystem {
public:
    int bg,md,sm;
    ParkingSystem(int big, int medium, int small) {
        bg = big;
        md = medium;
        sm = small;
    }
    
    bool addCar(int carType) {
        if(carType == 1){
            if(bg>0){
                bg--;
                return true;
            }else{
                return false;
            }
        }
        else if(carType == 2){
            if(md>0){
                md--;
                return true;
            }else{
                return false;
            }
        }
        if(carType == 3){
            if(sm>0){
                sm--;
                return true;
            }else{
                return false;
            }
        }
        return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */