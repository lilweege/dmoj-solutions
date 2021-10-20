// https://leetcode.com/problems/find-numbers-with-even-number-of-digits

class Solution {
    public int findNumbers(int[] nums) {
        int even = 0;
        for (int i = 0; i < nums.length; i++) {
            if (String.valueOf(nums[i]).length()%2==0) {
                even++;
            }
        }
        return even;
    }
}