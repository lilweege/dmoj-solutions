class Solution {
    public int subtractProductAndSum(int n) {
        int sum = 0;
        int product = 1;
        for (int i = 0; i < String.valueOf(n).length(); i++) {
            int num = Integer.valueOf(String.valueOf(String.valueOf(n).charAt(i)));
            sum += num;
            product *= num;
        }
        return product - sum;
    }
}