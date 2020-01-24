"""
A binary watch has 4 LEDs on the top which represent the hours (0-11), and the 6 LEDs on the bottom represent the minutes (0-59).

Each LED represents a zero or one, with the least significant bit on the right.

Given a non-negative integer n which represents the number of LEDs that are currently on, return all possible times the watch could represent.

Hour: 8 4 2 1
Minute: 32 16 8 4 2 1

Example:

Input: n = 1
Return: ["1:00", "2:00", "4:00", "8:00", "0:01", "0:02", "0:04", "0:08", "0:16", "0:32"]

Note:

The order of output does not matter.
The hour must not contain a leading zero, for example "01:00" is not valid, it should be "1:00".
The minute must be consist of two digits and may contain a leading zero, for example "10:2" is not valid, it should be "10:02".
"""

class Solution(object):
    def readBinaryWatch(self, num):
        """
        :type num: int
        :rtype: List[str]
        """
        watch = [1, 2, 4, 8, 16, 32, 1, 2, 4, 8]
        c = list(itertools.combinations(range(10), num))
        
        l = []
        for t in c:
            hour = 0
            minute = 0
            for item in t:
                if item < 6:
                    minute += watch[item]
                else:
                    hour += watch[item]
            if hour < 12 and minute < 60:
                if minute > 9:
                    s = str(hour) + ':' + str(minute)
                else:
                    s = str(hour) + ':' + '0' + str(minute)
                l.append(s)
        return l
