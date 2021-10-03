#The main task here is to convert a sorted array into a Balanced Binary Search Tree
'''
Made by: Ansh Gupta(@ansh422)
Date: 03/10/2021
'''
class TreeNode:
  def __init__(self,val=0,left=None,right=None):
    self.val=val
    self.left=left
    self.right=right
    
def sortedArrayToBST(nums):
  if not nums:
    return None
  mid=len(nums)//2
  root=TreeNode(nums[mid])
  root.left=sortedArrayToBST(nums[:mid])
  root.right=sortedArrayToBST(nums[mid+1:])
  return root

if __name__ == "__main__":
  nums=list(map(int,input().split()))
  root=sortedArrayToBST(nums)
  
