/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU缓存机制
 */
class LRUCache
{
public:
    LRUCache(int capacity) : _cap(capacity) {}

    // O(1)
    // hash 查找，如果找到了，就把 list 中的节点接下来移到头部
    int get(int key)
    {
        auto it = _m.find(key);
        if (it == _m.end())
            return -1;
        int val = it->second->second;
        _list.erase(it->second);
        _list.push_front(make_pair(key, val));
        _m[key] = _list.begin();
        return it->second->second;
    }

    // O(1)
    // 先查找旧 key 是否存在，如果存在，将节点移动到首部。
    // 如果不存在，插入新节点。
    // 如果容量超限，删除最脏的节点。
    void put(int key, int value)
    {
        auto it = _m.find(key);
        if (it != _m.end())
        {
            _list.erase(it->second);
        }

        _list.push_front(make_pair(key, value));
        _m[key] = _list.begin();

        if (_list.size() > _cap)
        {
            int key = _list.back().first;
            _m.erase(key);
            _list.pop_back();
        }
    }

private:
    unordered_map<int, list<pair<int, int>>::iterator> _m;
    // 新节点或刚访问的节点插入表头，因为表头指针可以通过 begin 很方便的获取到。
    list<pair<int, int>> _list;
    int _cap;
};
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
