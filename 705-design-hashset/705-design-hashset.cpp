class MyHashSet {
public:
    vector<int> v;
    MyHashSet() {
        v.resize(1000001,0);
    }
    
    void add(int key) {
        if(v[key]==0){
            v[key]++;
        }
    }
    
    void remove(int key) {
        if(v[key]==0){
            return;
        }
        v[key]--;
    }
    
    bool contains(int key) {
        return v[key]!=0;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */