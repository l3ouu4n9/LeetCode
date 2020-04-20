"""
A 3 x 3 magic square is a 3 x 3 grid filled with distinct numbers from 1 to 9 such that each row, column, and both diagonals all have the same sum.

Given an grid of integers, how many 3 x 3 "magic square" subgrids are there?  (Each subgrid is contiguous).

Example 1:

Input: [[4,3,8,4],
        [9,5,1,9],
        [2,7,6,2]]
Output: 1
Explanation: 
The following subgrid is a 3 x 3 magic square:
438
951
276

while this one is not:
384
519
762

In total, there is only one magic square inside the given grid.
Note:

1 <= grid.length <= 10
1 <= grid[0].length <= 10
0 <= grid[i][j] <= 15
"""

class Solution(object):
    def numMagicSquaresInside(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        ret = 0
        for i in range(0, len(grid) - 2):
            l = []
            for j in range(0, len(grid[0]) - 2):
                if j == 0:
                    for ptr1 in range(i, i + 3):
                        for ptr2 in range(j, j + 3):
                            l.append(grid[ptr1][ptr2])
                else:
                    for ptr1 in range(i, i + 3):
                        l.remove(grid[ptr1][j - 1])
                        l.append(grid[ptr1][j + 2])
                
                # Check from 1 to 9
                if 1 in l and 2 in l and 3 in l and 4 in l and 5 in l and 6 in l and 7 in l and 8 in l and 9 in l:
                    sum1 = 0 
                    sum2 = 0
                    sum3 = 0
                    # row
                    for ptr2 in range(j, j + 3):
                        sum1 += grid[i][ptr2]
                        sum2 += grid[i + 1][ptr2]
                        sum3 += grid[i + 2][ptr2]
                        
                    if sum1 == sum2 == sum3:
                        s = sum1
                        sum1 = 0 
                        sum2 = 0
                        sum3 = 0
                        # column
                        for ptr1 in range(i, i + 3):
                            sum1 += grid[ptr1][j]
                            sum2 += grid[ptr1][j + 1]
                            sum3 += grid[ptr1][j + 2]
                        if s == sum1 == sum2 == sum3:
                            sum1 = 0 
                            sum2 = 0
                            # diagonals
                            sum1 += grid[i][j] + grid[i + 1][j + 1] + grid[i + 2][j + 2]
                            sum2 += grid[i][j + 2] + grid[i + 1][j + 1] + grid[i + 2][j]
                            if s == sum1 == sum2:
                                print(s)
                                ret += 1
        return ret
