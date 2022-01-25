class RandomizedSet(object):

	def __init__(self):
		self.myList = []

	def insert(self, val):
		if val in self.myList:
			return False
		self.myList.append(val)
		return True

	def remove(self, val):
		if val in self.myList:
			self.myList.remove(val)
			return True
		else:
			return False		

	def getRandom(self):
		return random.choice(self.myList)