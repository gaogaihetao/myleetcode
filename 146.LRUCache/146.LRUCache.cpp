class LRUCache {
public:
    list<pair<int, int>> _list;
    int _cap;
    
    LRUCache(int capacity) {
        _cap = capacity;
    }

    int get(int key) {
        for(auto it = _list.begin(); it != _list.end(); it++) {
            if(it->first == key) {
                pair<int, int> pi = *it;
                _list.erase(it);
                _list.push_back(pi);
                return pi.second;
            }
        }
        return -1;
    }

    void put(int key, int value) {
        for(auto it = _list.begin(); it != _list.end(); it++) {
            if(it->first == key) {
                pair<int, int> pi = *it;
                _list.erase(it);
                pi.second = value;
                _list.push_back(pi);
                return;
            }
        }
        while(_list.size() >= _cap) {
            _list.pop_front();
        }
        _list.push_back(make_pair(key, value));
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */