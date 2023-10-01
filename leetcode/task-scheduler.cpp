class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if (n == 0) return tasks.size();
        int cnt[26]{};
        for (char c : tasks) ++cnt[c-'A'];
        // The most occurences of one task is limiting
        int slow = 0;
        for (int i = 0; i < 26; ++i)
            slow = max(slow, cnt[i]);
        // If the same count of tasks is seen then it should come
        // immediately after slow (add one to the total)
        // A B ..... A B ..... A B ..... A B
        // ^-------^ ^-------^ ^-------^ ^ ^
        //    n+1       n+1       n+1    1 1
        // ^---------------------------^ ^-^
        //              slow             same
        int same = 0;
        for (int i = 0; i < 26; ++i)
            if (cnt[i] == slow) ++same;
        // n+1 cycles per task (slow-1 times)
        int ans = (slow - 1) * (n + 1) + same;
        // If ans is less than the total number of tasks then the
        // the arrangement of A ... A ... doesn't have enough space
        // for all of the other tasks, the total time will be the
        // number of tasks
        if (ans < tasks.size()) return tasks.size();
        return ans;
    }
};