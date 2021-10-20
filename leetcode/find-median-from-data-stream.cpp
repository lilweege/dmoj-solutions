// https://leetcode.com/problems/find-median-from-data-stream

class MedianFinder {
public:
    /** initialize your data structure here. */
    vector<int> nums;
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        nums.insert(upper_bound(nums.begin(), nums.end(), num), num);
    }
    
    double findMedian() {
        double mid = (nums.size()-1) * 0.5;
        if (nums.size() % 2 == 1)
            return nums[mid];
        return (nums[mid] + nums[mid + 1]) * 0.5;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */