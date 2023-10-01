class Solution:
    def minimumEffort(self, tasks: List[List[int]]) -> int:
        tasks.sort(key=lambda x: x[0]-x[1])
        effort = 0
        committed = 0
        for actual, minimum in tasks:
            if committed < minimum:
                effort += minimum - committed
                committed = minimum
            committed -= actual
        return effort
