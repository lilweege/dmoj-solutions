// https://leetcode.com/problems/number-complement

impl Solution {
    pub fn find_complement(num: i32) -> i32 {
        let mut num = num;
        let mut ans = 0;
        for i in 0..32 {
            if num == 0 {
                break;
            }
            if num % 2 == 0 {
                ans += 1 << i;
            }
            num /= 2;
        }
        return ans;
    }
}
/*
int findComplement(int num) {
    int ans = 0;
    for (int i = 0; num; i++) {
        if (num % 2 == 0)
            ans += 1 << i;
        num /= 2;
    }
    return ans;
}
*/