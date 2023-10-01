class Solution:
    def minimumRounds(self, tasks: List[int]) -> int:
        dct = {}
        for diff in tasks:
            if diff not in dct:
                dct[diff] = 0
            dct[diff] += 1
        num = 0
        for diff,cnt in dct.items():
            if cnt == 1: return -1
            if cnt % 3 == 0:
                num += cnt // 3
                continue
            if (cnt-2) % 3 == 0:
                num += 1 + (cnt-2) // 3
                continue
            if (cnt-4) % 3 == 0:
                num += 2 + (cnt-4) // 3
                continue
            return -1
        return num