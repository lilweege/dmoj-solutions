class Solution:
    
    def digitSum(self, s: str, k: int) -> str:
        def transform(w):
            # print("\t", w)
            return str(sum(int(x) for x in w))
        
        while len(s) > k:
            news = ""
            for i in range(len(s)//k):
                # print(i)
                chunk = s[i*k:(i+1)*k]
                news += transform(chunk)
            if len(s)%k != 0:
                news += transform(s[(i+1)*k:])
            s = news
            # print("s =", s)
        return s