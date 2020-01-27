"""
Given n points in the plane that are all pairwise distinct, a "boomerang" is a tuple of points (i, j, k) such that the distance between i and j equals the distance between i and k (the order of the tuple matters).

Find the number of boomerangs. You may assume that n will be at most 500 and coordinates of points are all in the range [-10000, 10000] (inclusive).

Example:

Input:
[[0,0],[1,0],[2,0]]

Output:
2

Explanation:
The two boomerangs are [[1,0],[0,0],[2,0]] and [[1,0],[2,0],[0,0]]
"""

class Solution(object):
    def distance(self, point1, point2):
        return (point1[0] - point2[0]) ** 2 + (point1[1] - point2[1]) ** 2
    def numberOfBoomerangs(self, points):
        """
        :type points: List[List[int]]
        :rtype: int
        """
        dist_map = collections.Counter()
        ans = 0
        for i in range(len(points)):
            dist_map.clear()
            for j in range(len(points)):
                if i == j:
                    continue
                d = self.distance(points[i], points[j])
                dist_map[d] += 1
            for value in dist_map.values():
                if value > 1:
                    ans += value * (value - 1)
        return ans
