#It's a little tricky. If you can figure out how many buckets for two pigs can check at most in an hour, then you can fid the solution.
#Imagine that for two pigs, each pig can check 5 times in one hour. They they can check at most 25(5*5) buckets at most.
#Which is 5^2. Check those buckets in n dimention. I used to think that for last check, we must check from two buckets.
class Solution(object):
    def poorPigs(self, buckets, minutesToDie, minutesToTest):
        """
        :type buckets: int
        :type minutesToDie: int
        :type minutesToTest: int
        :rtype: int
        """
        times = minutesToTest/minutesToDie+1
        total = 1
        cnt = 0
        while total < buckets:
            total *= times
            cnt += 1
        return cnt
        
