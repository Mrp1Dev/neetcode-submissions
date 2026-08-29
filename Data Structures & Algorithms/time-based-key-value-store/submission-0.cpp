class TimeMap {
    unordered_map<string, vector<pair<int, string>>> keyTimeValue;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        auto& v = keyTimeValue[key];
        v.push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        vector<pair<int, string>>& v = keyTimeValue[key];
        if(v.empty()) return "";
        int r = lowerBound(v, timestamp);
        if(r == -1) return "";
        return v[r].second;
    }

    int lowerBound(vector<pair<int, string>>& v, int timestamp){
        int l = 0;
        int r = v.size() - 1;
        while (l <= r){
            int m = l + (r-l)/2;
            if(timestamp == v[m].first) return m;
            else if (timestamp > v[m].first) l = m+1;
            else r = m - 1;
        }
        return r;
    }
};
