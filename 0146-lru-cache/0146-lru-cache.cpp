class LRUCache {
private:
    int capacity;
    // Doubly linked list storing {key, value} pairs
    list<pair<int, int>> cache_list; 
    // Hash map storing key -> iterator to the list node
    unordered_map<int, list<pair<int, int>>::iterator> cache_map; 

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        // If key is not found, return -1
        if (cache_map.find(key) == cache_map.end()) {
            return -1;
        }
        
        // Key exists: move the node to the front (Most Recently Used)
        // splice() moves the node from its current position to the begin() in O(1) time
        cache_list.splice(cache_list.begin(), cache_list, cache_map[key]);
        
        // Return the value
        return cache_map[key]->second;
    }
    
    void put(int key, int value) {
        if (cache_map.find(key) != cache_map.end()) {
            // Key already exists: update its value and move it to the front
            cache_map[key]->second = value;
            cache_list.splice(cache_list.begin(), cache_list, cache_map[key]);
        } else {
            // Key does not exist: check if we need to evict the LRU item
            if (cache_list.size() == capacity) {
                // The LRU item is at the back of the list
                int lru_key = cache_list.back().first;
                
                // Remove from map and list
                cache_map.erase(lru_key);
                cache_list.pop_back();
            }
            
            // Insert the new key-value pair at the front
            cache_list.push_front({key, value});
            // Record its iterator in the hash map
            cache_map[key] = cache_list.begin();
        }
    }
};