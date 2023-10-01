class Solution:
    def hashArr(self, arr):
        return hash(tuple(arr))

    def equalPairs(self, grid: List[List[int]]) -> int:
        return sum(self.hashArr(row) == self.hashArr(col)
            for row in grid
            for col in list(zip(*grid)))