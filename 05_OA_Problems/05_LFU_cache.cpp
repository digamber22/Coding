// TC -> O(logn) , SC -> O(capacity)
class LFUCache {
public:
    int capacity;
    int lastD = 0;
    unordered_map<int, tuple<int, int, int>> mpp; // key -> {value, freq, time}
    set<tuple<int, int, int>> st;                 // {freq, time, key}  --> {get<0>(it), get<1>(it), get<2>(it) } 

    LFUCache(int cap) { capacity = cap; }

    int get(int key) {
        if (mpp.find(key) == mpp.end())
            return -1;

        auto [val, freq, time] = mpp[key];
        st.erase({freq, time, key});

        // Update frequency + time
        lastD++;
        freq++;
        time = lastD;

        mpp[key] = {val, freq, time};
        st.insert({freq, time, key});

        return val;
    }
    // L F U
    void put(int key, int value) {
        if (capacity == 0)
            return;

        if (mpp.find(key) != mpp.end()) {
            auto [val, freq, time] = mpp[key];
            st.erase({freq, time, key});

            freq++;
            lastD++;
            time = lastD;

            mpp[key] = {value, freq, time};
            st.insert({freq, time, key});

        } else {
            if ((int)mpp.size() == capacity) {
                // Evict least freq + LRU
                auto it = *st.begin();

                //{freq, time, key}  --> {get<0>(it), get<1>(it), get<2>(it)} accessing respectively . 
                int delKey = get<2>(it);    // delkey means accessing key from set .

                st.erase(it);
                mpp.erase(delKey);
            }

            lastD++;
            int freq = 1, time = lastD;
            mpp[key] = {value, freq, time};
            st.insert({freq, time, key});
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */