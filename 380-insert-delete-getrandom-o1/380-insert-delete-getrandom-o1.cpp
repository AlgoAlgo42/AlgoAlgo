class RandomizedSet 
{
    set<int> s;
public:
    RandomizedSet() 
    {}
    
    bool insert(int val) 
    {
        if(s.find(val) == s.end())
        {
            s.insert(val);
            return (true);
        }
        return (false); 
    }
    
    bool remove(int val) {
        if(s.find(val) == s.end())
            return (false);
        s.erase(val);
        return (true);
    }
    
    int getRandom() {
        int randint = rand();
        auto it = s.begin();
        advance(it, (randint % s.size()));
        return (*it);
    }
};