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
        //这里要考虑两种情况
        // 1️⃣key已经存在
        // 2️⃣key是新插入
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
        //已满且容器里没有待添加的key,则调用dump()
        if(ma.size() == size && ma.count(key) == 0) dump();
        updateLRU(key);
        ma[key] = value;
    }
};