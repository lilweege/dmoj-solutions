class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if (n % groupSize != 0)
            return false;
        sort(hand.begin(), hand.end());

        // cout<< "yes" << endl;
        map<int, int> cnt;
        for (int x : hand) ++cnt[x];
        for (int i = 0; i < n/groupSize; ++i) {
            int mi = min_element(begin(cnt), end(cnt))->first;
            // cout << "bruh\n";
            for (int x = mi; x < mi+groupSize; ++x) {
                // cout << x << ' ';
                if (--cnt[x] < 0) return false;
            }
            // cout << '\n';
            for (int x = mi; x < mi+groupSize; ++x)
                if (cnt[x] == 0) cnt.erase(cnt.find(x));
        }
        return true;
    }
};