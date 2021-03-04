class Solution(object):
    def insert(self, intervals, newInterval):
        """
        :type intervals: List[List[int]]
        :type newInterval: List[int]
        :rtype: List[List[int]]
        """
        i = 0
        upbound = len(intervals)
        res = []
        while(i < upbound and intervals[i][1] < newInterval[0]):
            res.append(intervals[i])
            i += 1
        while(i < upbound and intervals[i][0] <= newInterval[1]):
            newInterval[0] = min(intervals[i][0], newInterval[0])
            newInterval[1] = max(intervals[i][1], newInterval[1])
            i += 1
        res.append(newInterval)
        
        for j in range(i, upbound):
            res.append(intervals[j])
        return res
