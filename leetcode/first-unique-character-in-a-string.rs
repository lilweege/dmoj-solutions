// https://leetcode.com/problems/first-unique-character-in-a-string

impl Solution {
    pub fn first_uniq_char(s: String) -> i32 {
        let mut cnt = [0;26];
        for c in s.chars() {
            cnt[(c as i32 - 'a' as i32) as usize] += 1;
        }
        for (i, c) in s.chars().enumerate() {
            if cnt[(c as i32 - 'a' as i32) as usize] == 1 {
                return i as i32;
            }
        }
        return -1;
    }
}