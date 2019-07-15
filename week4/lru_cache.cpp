class LRUCache {
public:
    unordered_map<int,int> cache;   
    list<int> mostUsed; 
    int maxCount; 
    
    LRUCache(int capacity) {
        maxCount = capacity; 
    }
    
    int get(int key) {
        if (cache.find(key) != cache.end()) {
            // update mostUsed
            if (mostUsed.front() != key) {
                mostUsed.remove(key);
                mostUsed.push_front(key);     
            }
            
            return cache[key];
        } else {
            return -1; 
        }
    }
    
    void put(int key, int value) {
        if (cache.size() < maxCount) {
            if (cache.find(key) == cache.end()) {
                // update most used
                mostUsed.push_front(key);     
            }
            
            cache[key] = value;
        } else {
            if (cache.find(key) != cache.end()) {
                // if there is a match in the cache

                // update mostUsed
                mostUsed.remove(key);
                mostUsed.push_front(key);

                // update cache
                cache[key] = value;
            } else {
                // else there is not a match in the cache
                
                // grab least used key and store in var
                int toRemove = mostUsed.back(); 

                // remove key from both memory stores
                mostUsed.remove(toRemove);
                cache.erase(toRemove);

                // add new entries 
                mostUsed.push_front(key);
                cache[key] = value;     
            }
            
        }
    }
};