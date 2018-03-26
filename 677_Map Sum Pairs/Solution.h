class MapSum {
private:
    unordered_map<string, int> mm;
public:
    /** Initialize your data structure here. */
    MapSum() {
        
    }
    
    void insert(string key, int val) {
        mm[key] = val;
    }
    
    int sum(string prefix) {
        int sum = 0;
        for(auto iter = mm.begin(); iter != mm.end(); iter++){
            auto res = std::mismatch(prefix.begin(), prefix.end(), iter->first.begin());
            if (res.first == prefix.end()) {
                sum += iter->second;
            }
        }
        return sum;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum obj = new MapSum();
 * obj.insert(key,val);
 * int param_2 = obj.sum(prefix);
 */
