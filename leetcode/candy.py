class Solution:
    def candy(self, ratings: List[int]) -> int:
        n = len(ratings)
        left_neigh = [1] * n
        right_neigh = [1] * n
        for i in range(1, n):
            if ratings[i] > ratings[i-1]:
                left_neigh[i] = left_neigh[i-1] + 1

        for i in reversed(range(0, n-1)):
            if ratings[i] > ratings[i+1]:
                right_neigh[i] = right_neigh[i+1] + 1

        return sum(max(left_neigh[i], right_neigh[i]) for i in range(n))