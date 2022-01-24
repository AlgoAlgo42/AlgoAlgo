# Below is the interface for Iterator, which is already defined for you.
#
# class Iterator(object):
#     def __init__(self, nums):
#         """
#         Initializes an iterator object to the beginning of a list.
#         :type nums: List[int]
#         """
#
#     def hasNext(self):
#         """
#         Returns true if the iteration has more elements.
#         :rtype: bool
#         """
#
#     def next(self):
#         """
#         Returns the next element in the iteration.
#         :rtype: int
#         """

class PeekingIterator:
	def __init__(self, iterator):
		self.iter = iterator
		self.isPeek = False
		self.peekNum = None

	def peek(self):
		if self.isPeek == False:
			self.isPeek = True
			self.peekNum = next(self.iter)
		return self.peekNum

	def next(self):
		if self.isPeek:
			res = self.peekNum
			self.isPeek = False
			self.peekNum = None
			return res
		else:
			return next(self.iter)

	def hasNext(self):
		return self.isPeek or self.iter.hasNext()
        

# Your PeekingIterator object will be instantiated and called as such:
# iter = PeekingIterator(Iterator(nums))
# while iter.hasNext():
#     val = iter.peek()   # Get the next element but not advance the iterator.
#     iter.next()         # Should return the same value as [val].