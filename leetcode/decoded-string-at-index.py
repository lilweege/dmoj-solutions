class Solution:
    def decodeAtIndex(self, s: str, k: int) -> str:
        k -= 1
        ss = []
        words = []
        sz = 0
        for c in s:
            if c.isdigit():
                word = ''.join(ss)
                ss.clear()
                rep = int(c)
                sz = (sz + len(word)) * rep
                words.append((word, rep, sz))
                if k < sz:
                    break
            else:
                ss.append(c)

        if len(words) == 0:
            return s[k]

        for i in reversed(range(1, len(words))):
            cword, crep, csz = words[i]
            pword, prep, psz = words[i-1]
            # print(k)
            # print(cword, crep, csz)
            # print(pword, prep, psz)
            # print()
            k %= psz + len(cword)
            if k >= psz:
                return cword[k-psz]

        # print(k)
        return s[k%len(words[0][0])]
