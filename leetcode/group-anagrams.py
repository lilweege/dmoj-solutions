// https://leetcode.com/problems/group-anagrams

class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        def freq(s):
            f = [0] * 26
            for c in s:
                f[ord(c) - ord('a')] += 1
            return f
        m = {}
        for s in strs:
            m.setdefault(''.join(map(str, freq(s))), []).append(s)
        return list(m.values())
