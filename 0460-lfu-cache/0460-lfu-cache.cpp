
class LFUCache {
    struct Node { int k, v, f; };
    int cap, min_f;
    unordered_map<int, list<Node>::iterator> m;
    unordered_map<int, list<Node>> fm;
    
    void update(int k) {
        auto it = m[k];
        int v = it->v, f = it->f;
        fm[f].erase(it);
        if (fm[f].empty() && min_f == f) min_f++;
        fm[f + 1].push_front({k, v, f + 1});
        m[k] = fm[f + 1].begin();
    }

public:
    LFUCache(int capacity) {
        cap = capacity;
        min_f = 0;
    }
    
    int get(int k) {
        if (m.find(k) == m.end()) return -1;
        update(k);
        return m[k]->v;
    }
    
    void put(int k, int v) {
        if (cap == 0) return;
        if (m.find(k) != m.end()) {
            m[k]->v = v;
            update(k);
        } else {
            if (m.size() == cap) {
                m.erase(fm[min_f].back().k);
                fm[min_f].pop_back();
            }
            min_f = 1;
            fm[1].push_front({k, v, 1});
            m[k] = fm[1].begin();
        }
    }
};