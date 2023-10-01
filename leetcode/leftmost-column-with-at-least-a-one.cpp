/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int x, int y);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        vector<int> d = binaryMatrix.dimensions();
        int r = d[0], c = d[1];
        int ans = c;
        for (int i = 0; i < r; i++) {
            while (ans && binaryMatrix.get(i, ans - 1)) {
                ans--;
            }
        }
        return ans == c ? -1 : ans;

        /*
        vector<int> d = binaryMatrix.dimensions(); // [m, n]
        int i = d[0] - 1, j = d[1] - 1;
        
        int ans = -1;
        while (i >= 0 && j >= 0) {
            if (binaryMatrix.get(i, j)) {
                ans = j;
                j--;
            }
            else {
                i--;
            }
            
        }
        return ans;
        */
    }
};