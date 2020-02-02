解法一：暴力搜索
class Solution(object):
    def TwoSum(self,nums,target):
        lens=len(nums)
        print(lens)
        for i in range(lens):
            num=target-nums[i]
            if num in nums:
                j=nums.index(num)
#               当取得两个下标不一样时，才会停止循环，return
                if i!=j:
                    return [i,j] if i<j else [j,i]
solu=Solution()
print(solu.TwoSum([1,2,3,4],6))

