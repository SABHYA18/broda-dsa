class TimeMap {
public:
    unordered_map<string, vector<pair<string, int>>> store; 
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        if(!store.contains(key)){
            store[key] = {};
        }
        store[key].emplace_back(value, timestamp);
        
    }
    
    string get(string key, int timestamp) {
        string res = "";
        vector<pair<string, int>> &values = store[key];

        if(store.contains(key)){
            int l = 0, r = values.size()-1;

            while(l<=r){
                int mid = l + (r-l)/2;

                if(values[mid].second<=timestamp){
                    res = values[mid].first;
                    l = mid+1;
                }
                else r = mid-1;
            } 
        }
        return res;

    }
};
