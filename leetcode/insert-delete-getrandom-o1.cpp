class RandomizedSet {
    // val, idx
    unordered_map<int, int> m;
    vector<int> v;
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if (m.find(val) != m.end())
            return false;
        m[val] = v.size();
        v.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        auto it = m.find(val);
        if (it == m.end())
            return false;
        
        int idx = it->second;
        
        int old = v[v.size()-1];
        swap(v[idx], v[v.size()-1]);
        v.pop_back();
        
        m.erase(it);
        if (val != old)
            m[old] = idx;
        return true;
    }
    
    int getRandom() {
        return v[rand() % v.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */