class TimeMap {
    unordered_map<string, map<int, string>> m;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        m[key][-timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        auto& mm = m[key];
        // cout << "looking up timestamp=" << timestamp << '\n';
        // for (auto& [k, v] : mm) {
        //     cout << k << ' ' << v << '\n';
        // }

        auto it = mm.upper_bound(-timestamp-1);
        if (it == mm.end()) return "";
        cout << "got " << it->second << '\n';
        return it->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */