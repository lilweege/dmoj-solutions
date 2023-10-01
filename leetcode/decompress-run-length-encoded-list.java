class Solution {
    public int[] decompressRLElist(int[] nums) {
        int sum = 0;
        for (int i = 0; i < nums.length; i += 2) {
            sum += nums[i];
        }
        int[] res = new int[sum];
        
        int index = 0;
        for (int i = 0; i < nums.length; i += 2) {
            for (int j = 0; j < nums[i]; j++) {
                res[index] = nums[i+1];
                index++;
            }
        }
        
        return res;
    }
}