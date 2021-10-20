// https://leetcode.com/problems/search-a-2d-matrix

class Solution:
    def searchMatrix(self, matrix, target):
        if len(matrix) == 0 or len(matrix[0]) == 0: return
        rows = len(matrix)
        cols = len(matrix[0])
        for m in range(rows):
            if len(matrix[m]) > 0:
                if matrix[m][-1] == target: return(m,-1)
                if matrix[m][-1] > target:
                    for n in range(cols):
                        if matrix[m][n] == target: return(m,n)