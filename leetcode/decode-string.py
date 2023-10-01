class Solution:
    def decodeString(self, s: str) -> str:
        stack = []
        for c in s:
            if c == ']':
                ans = ""
                while stack[-1] != '[':
                    ans = stack.pop() + ans
                stack.pop()
                n = ""
                while len(stack) > 0 and stack[-1].isnumeric():
                    n = stack.pop() + n
                n = int(n)
                
                stack.append(ans * n)
            else:
                stack.append(c)
        return ''.join(stack)
