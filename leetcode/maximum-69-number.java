class Solution {
    public int maximum69Number (int num) {
        char[] best = String.valueOf(num).toCharArray();
        for (int i = 0; i < best.length; i++) {
            if (best[i] == '6') {
                best[i] = '9';
                break;
            }
        }

        return Integer.valueOf(new String(best));
    }
}