/*
380. Insert Delete GetRandom O(1)
Implement the RandomizedSet class:

    RandomizedSet() Initializes the RandomizedSet object.
    bool insert(int val) Inserts an item val into the set if not present. Returns true if the item was not present, false otherwise.
    bool remove(int val) Removes an item val from the set if present. Returns true if the item was present, false otherwise.
    int getRandom() Returns a random element from the current set of elements (it's guaranteed that at least one element exists when this method is called). Each element must have the same probability of being returned.

You must implement the functions of the class such that each function works in average O(1) time complexity.

SUBMISSION IN C++
*/
class RandomizedSet
{
public:
    unordered_map<int, int>mp;
    vector<int>v;
    RandomizedSet()
    {

    }

    bool insert(int val)
    {
        if(mp.count(val))
        {
            return false;
        }
        v.push_back(val);
        mp[val]=v.size()-1;
        return true;
    }

    bool remove(int val)
    {
        if(mp.count(val))
        {
            int index=mp[val];
            int last=v.back();
            v[index]=last;
            mp[last]=index;
            v.pop_back();
            mp.erase(val);
            return true;
        }
        return false;
    }

    int getRandom()
    {
        int ind=rand()%v.size();
        return v[ind];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

