#include <unordered_map>
#include <list>
using std::list;
using std::unordered_map;

class LRUCache {
private:
    int size;
    unordered_map<int, int> ma;// key ->value

    list<int> que;// 维护一个key的队列
    unordered_map<int, list<int>::iterator> mp;// key -> iterator
    
    void updateLRU(int key)
    {
        if(ma.count(key)) que.erase(mp[key]);
        que.push_front(key);
        mp[key] = que.begin();
    }

    void dump()
    {
        mp.erase(que.back());
        ma.erase(que.back());
        que.pop_back();
    }
public:
    LRUCache(int capacity) : size(capacity) {}

    int get(int key) 
    {
        if(ma.count(key) == 0) return -1;
        updateLRU(key);
        return ma[key];
    }
    
    void put(int key, int value) 
    {
        if(ma.size() == size && ma.count(key) == 0) dump();
        ma[key] = value;
        updateLRU(key);
    }
};