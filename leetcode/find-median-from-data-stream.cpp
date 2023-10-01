class MedianFinder {
public:
    priority_queue<int, vector<int>, less<int>> big;
    priority_queue<int, vector<int>, greater<int>> sml;
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        big.push(num);
        sml.push(big.top()); big.pop();
        if (sml.size() > big.size()) {
            big.push(sml.top()); sml.pop();
        }
    }
    
    double findMedian() {
        if (big.size() == sml.size())
            return (big.top() + sml.top()) / 2.0;
        return big.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */