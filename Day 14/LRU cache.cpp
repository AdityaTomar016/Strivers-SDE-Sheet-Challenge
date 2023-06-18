class LRUCache {
public:
    unordered_map<int,int>mp;
    list<int>l;
    unordered_map<int,list<int>::iterator> add;
    int sz=0;
    int cap;
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if(mp.find(key) != mp.end()){
            l.erase(add[key]);
            l.push_front(key);
            add.erase(key);
            add[key] = l.begin();
            return mp[key];
        }
        
        return -1;
    }
    
    void put(int key, int value) {
        
        if(mp.find(key)!=mp.end()){
            l.erase(add[key]);
            add.erase(key);
            mp.erase(key);
            sz--;
        }
        else if(sz == cap){
            mp.erase(l.back());
            add.erase(l.back());
            l.pop_back();
            sz--;
        }
            l.push_front(key);
            mp[key] = value;
            add[key] = l.begin();
            sz++;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
