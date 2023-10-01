class Solution {
    public int subarraysWithKDistinct(int[] A, int K) {
        int[] cnt1 = new int[20001];
        int nz1 = 0;
        int[] cnt2 = new int[20001];
        int nz2 = 0;
        int ans = 0, left1 = 0, left2 = 0;

        for (int right = 0; right < A.length; ++right) {
            cnt1[A[right]]++;
            if (cnt1[A[right]] == 1)
                nz1++;
            cnt2[A[right]]++;
            if (cnt2[A[right]] == 1)
                nz2++;
            
            while (K < nz1) {
                cnt1[A[left1]]--;
                if (cnt1[A[left1++]] == 0)
                    nz1--;
            }
            while (K <= nz2) {
                cnt2[A[left2]]--;
                if (cnt2[A[left2++]] == 0)
                    nz2--;
            }

            ans += left2 - left1;
        }

        return ans;
    }
}