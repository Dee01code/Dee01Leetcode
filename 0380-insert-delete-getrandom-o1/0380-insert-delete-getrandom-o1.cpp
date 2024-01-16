class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(ht.find(val)==ht.end()){
            vec.push_back(val);
            ht[val]=vec.size()-1;
            return true;
        }
        else
            return false;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(ht.find(val)!=ht.end()){
            vec[ht[val]]=vec[vec.size()-1];
            ht[vec[vec.size()-1]]=ht[val];
            vec.pop_back();
            ht.erase(val);
            return true;
        }
        else 
            return false;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        if(vec.size()==1)
            return vec[0];
        else{
            int idx=rand()%(vec.size());
            return vec[idx];   
        }
    }
    
    unordered_map<int,int> ht;
    vector<int> vec;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */