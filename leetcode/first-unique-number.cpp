class FirstUnique {
    unordered_map<int, int> f;
    queue<int> q;
public:
    FirstUnique(vector<int>& nums) {
        for (int num : nums)
            add(num);
    }
    
    int showFirstUnique() {
        while (!q.empty() && f[q.front()] > 1)
            q.pop();
        return q.empty() ? -1 : q.front();
    }
    
    void add(int x) {
        q.push(x);
        f[x]++;
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */