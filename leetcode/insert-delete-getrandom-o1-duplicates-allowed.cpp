// https://stackoverflow.com/a/55113454/12637867
class hash_tuple {
    template<class T>
    struct component {
        const T& value;
        component(const T& value) : value(value) {}
        uintmax_t operator,(uintmax_t n) const {
            n ^= std::hash<T>()(value);
            n ^= n << (sizeof(uintmax_t) * 4 - 1);
            return n ^ std::hash<uintmax_t>()(n);
        }
    };
public:
    template<class Tuple>
    size_t operator()(const Tuple& tuple) const {
        return std::hash<uintmax_t>()(
            std::apply([](const auto& ... xs) { return (component(xs), ..., 0); }, tuple));
    }
};

class RandomizedCollection {
    
    // val, num
    using P = pair<int, int>;
    
    // val, cnt
    unordered_map<int, int> cnt;
    // (val, num), idx
    unordered_map<P, int, hash_tuple> m;
    vector<P> v;
    
public:
    RandomizedCollection() {
        
    }
    
    bool insert(int val) {
        int num = cnt[val]++;
        P x = { val, num };
        m[x] = v.size();
        v.push_back(x);
        return num == 0;
    }
    
    bool remove(int val) {
        int& num = cnt[val];
        assert(num >= 0);
        if (num == 0)
            return false;
        
        P x = { val, --num };
        auto it = m.find(x);
        assert(it != m.end());
        
        int idx = it->second;
        
        P old = v[v.size()-1];
        swap(v[idx], v[v.size()-1]);
        v.pop_back();
        
        m.erase(it);
        if (x != old)
            m[old] = idx;
        return true;
    }
    
    int getRandom() {
        return v[rand() % v.size()].first;
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */