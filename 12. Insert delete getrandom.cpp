class RandomizedSet {
public:
    /** Initialize your data structure here. */
    unordered_map<int,int>ds;
    vector<int>arr;
    RandomizedSet() {
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(ds.find(val)!=ds.end()) return false;
        else{
            arr.push_back(val);
            ds[val]=arr.size()-1;
            return true;
        }
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(ds.find(val)==ds.end()) return false;
        else{
            int last = arr.back();
            ds[last] = ds[val];
            arr[ds[val]] = last;
            arr.pop_back();
            ds.erase(val);
            return true;
        }
        
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return arr[rand()%arr.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */