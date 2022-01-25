class RandomizedSet:
    s1 = set()
    def __init__(self):
        self.s1 = set()

    def insert(self, val: int) -> bool:
        return_v = val in self.s1
        self.s1.add(val)
        return(not return_v)

    def remove(self, val: int) -> bool:
        return_v = val in self.s1
        self.s1.discard(val)
        return (return_v)
        # try:
        #     self.s1.remove(val)
        #     return (1);
        # except:
        #     return (0)

    def getRandom(self) -> int:
        l1 = list(self.s1);
        set(self.s1)
        return (random.choice(l1))


# Your RandomizedSet object will be instantiated and called as such:
# obj = RandomizedSet()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()
