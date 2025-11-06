class LRUCache {
public:
    int cap;
    int lastD = 0;

    map<int, pair<int, int>> mpp; // key , {val , time};
    set<pair<int, int>> st;       // time , key;

    LRUCache(int capacity) {
         cap = capacity; 
         }
         
    int get(int key) {

        if (mpp.find(key) == mpp.end())
            return -1;

        st.erase({mpp[key].second, key});

        lastD++;
        mpp[key].second = lastD;
        st.insert({lastD, key});

        return mpp[key].first;
    }

    void put(int key, int value) {

        if (mpp.find(key) != mpp.end()) {
            st.erase({mpp[key].second, key});
        }

        else if (mpp.size() == cap) {
            auto it = *st.begin();
            st.erase(it);
            mpp.erase(it.second);
        }

        lastD++;
        st.insert({lastD, key});
        mpp[key] = {value, lastD};
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */