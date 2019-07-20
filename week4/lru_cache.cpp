// use a hm to store your <key, reference to node in dll>
// use list (functions same as dll in cpp) to hold 
// recently used keys at the head and least used keys at the tail 
class LRUCache {
public:
    int capacity; 

    // map : <key, reference to ListNode in dll> 
    unordered_map<int, list<pair<int,int>>::iterator> hm; 
    
    // holds most recently used key, value pairs
    list<pair<int,int>> recent; 
    
    LRUCache(int c) {
        capacity = c; 
    }
    
    int get(int key) {
        auto iter = hm.find(key); 
    
        if (iter == hm.end()) 
            // key not found
            return -1;
        
        list<pair<int,int>>::iterator listNode = iter->second;
        // inserts into front of dll 
        recent.splice(recent.begin(), recent, listNode);
        
        return listNode->second; 
    }
    
    void put(int key, int value) {
        auto iter = hm.find(key); 
        
        if (iter != hm.end()) { // key exists
            list<pair<int,int>>::iterator listNode = iter->second;
            
            // move node to front of recent 
            recent.splice(recent.begin(), recent, listNode);
            
            // update value 
            listNode->second = value; 
            return; 
        }
        
        // at capacity, delete least recently used 
        if (hm.size() == capacity) {
            int deleteKey = recent.back().first; 
            recent.pop_back();
            hm.erase(deleteKey);
        }
        
        // add to front of dll 
        recent.emplace_front(key, value);
        hm[key] = recent.begin();  
    }
};