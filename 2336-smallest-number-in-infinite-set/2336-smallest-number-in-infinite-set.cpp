class SmallestInfiniteSet {
public:

    map<int,int> m;
    SmallestInfiniteSet() {
        int i = 1;
        while(i<=1000){
           m[i++] = 1;
        }
    }
    
    int popSmallest() {
        int a = m.begin()->first;
        m.erase(a);
        return a;
    }
    
    void addBack(int num) {
        if(m.count(num)) return;
        m[num] = 1;
        // p.push(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */