class Solution {
public:
    int minPartitions(string n) {
        int mm = 0;
        for (char c : n)
            if (c > mm)
                mm = c;
        return mm - '0';
    }
};