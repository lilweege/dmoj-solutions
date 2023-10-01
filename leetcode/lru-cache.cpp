class LRUCache {
public:
    unordered_map<int, list<pair<int, int>>::iterator> m;
    list<pair<int, int>> l;
    int sz = 0;
    int cap;
    
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if (m.count(key)) {
            l.splice(l.begin(), l, m[key]);
            return m[key]->second;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (m.count(key)) {
            m[key]->second = value;
            l.splice(l.begin(), l, m[key]);
        }
        else {
            if (sz == cap) {
                m.erase(l.back().first);
                l.pop_back();
            }
            else sz++;
            l.push_front({ key, value });
            m[key] = l.begin();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */