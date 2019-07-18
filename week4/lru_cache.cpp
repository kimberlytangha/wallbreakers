// class LRUCache {
// public:
//     unordered_map<int,int> cache;   
//     list<int> mostUsed; 
//     int maxCount; 
    
//     LRUCache(int capacity) {
//         maxCount = capacity; 
//     }
    
//     int get(int key) {
//         if (cache.find(key) != cache.end()) {
//             // update mostUsed
//             if (mostUsed.front() != key) {
//                 mostUsed.remove(key);
//                 mostUsed.push_front(key);     
//             }
            
//             return cache[key];
//         } else {
//             return -1; 
//         }
//     }
    
//     void put(int key, int value) {
//         if (cache.size() < maxCount) {
//             if (cache.find(key) == cache.end()) {
//                 // update most used
//                 mostUsed.push_front(key);     
//             }
            
//             cache[key] = value;
//         } else {
//             if (cache.find(key) != cache.end()) {
//                 // if there is a match in the cache

//                 // update mostUsed
//                 mostUsed.remove(key);
//                 mostUsed.push_front(key);

//                 // update cache
//                 cache[key] = value;
//             } else {
//                 // else there is not a match in the cache
                
//                 // grab least used key and store in var
//                 int toRemove = mostUsed.back(); 

//                 // remove key from both memory stores
//                 mostUsed.remove(toRemove);
//                 cache.erase(toRemove);

//                 // add new entries 
//                 mostUsed.push_front(key);
//                 cache[key] = value;     
//             }
            
//         }
//     }
// };

class LRUCache {
public:
    int capacity; 
    
    // declares iterator to list 
    // list<pair<int,int>>::iterator 
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
        
        // auto tmpIter = recent.find(iter);
        // int val = tmpNode.second; 
        // recent.erase(iter); 
        // recent.emplace_front(key, val); 
        
        // updates recents to reflect usage 
        recent.splice(recent.begin(), recent, iter->second);
        
        return iter->second->second; 
    }
    
    void put(int key, int value) {
        auto iter = hm.find(key); 
        
        if (iter != hm.end()) { // key exists
            // move node to front of recent 
            recent.splice(recent.begin(), recent, iter->second);
            
            // update value 
            iter->second->second = value; 
            return; 
        }
        
        if (hm.size() == capacity) {
            // remove least used node from recents and map 
            int deleteKey = recent.back().first; 
            recent.pop_back();
            hm.erase(deleteKey);
        }
        
        // place new node at front of recents 
        recent.emplace_front(key, value);
        // add new entry into map 
        hm[key] = recent.begin();  
    }
};