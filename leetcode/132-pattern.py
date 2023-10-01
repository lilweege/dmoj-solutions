class Solution:
    def find132pattern(self, nums: List[int]) -> bool:
        st = []
        c = -inf
        for a in reversed(nums):
            if a < c:
                return True

            while st and st[-1] < a:
                c = st.pop()

            st.append(a)

        return False
