class PeekingIterator : public Iterator {
public:
    int i=0;
    vector<int>n;
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    n=nums;
	}
	
	int peek() {
        if(hasNext())
            return n[i];
        return -1;
	}
	
	int next() {
	    if(hasNext())
            return n[i++];
        return -1;
	}
	
	bool hasNext() const {
	    return (i<n.size());
	}
};