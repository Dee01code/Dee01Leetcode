class SeatManager {
public:
    
    set<int> res;
    
    SeatManager(int n) {
        for(int i = 1; i<=n; i++) res.insert(i);
    }
    
    int reserve() {
        int st = *res.begin();
        res.erase(res.begin());
        return st;
    }
    
    void unreserve(int sn) {
        res.insert(sn);
    }
    
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */