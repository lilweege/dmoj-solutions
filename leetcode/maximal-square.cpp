class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        
        int largest = 0;
        int r = matrix.size(), c = matrix[0].size();
        
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (matrix[i][j] == '1') {
                    int cnt = 1;
                    bool expand = true;
                    while (expand && i + cnt < r && j + cnt < c) {
                        for (int l = 0; l <= cnt; l++) {
                            if (matrix[i + l][j + cnt] == '0') {
                                expand = false;
                                break;
                            }
                        }
                        if (expand) {
                            for (int m = 0; m <= cnt; m++) {
                                if (matrix[i + cnt][j + m] == '0') {
                                    expand = false;
                                    break;
                                }
                            }
                        }
                        if (expand) {
                            cnt++;
                        }
                    }
                    largest = max(largest, cnt);
                }
            }
        }
        return (int)pow(largest, 2);
    }
};