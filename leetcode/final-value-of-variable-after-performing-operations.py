class Solution:
    def finalValueAfterOperations(self, operations: List[str]) -> int:
        return sum((-1 if x[1] == '-' else +1) for x in operations)