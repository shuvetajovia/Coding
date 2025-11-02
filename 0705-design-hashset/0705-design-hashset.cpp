class MyHashSet {
private:
    vector<bool> data; // acts as hash table
    
public:
    MyHashSet() {
        data.resize(1000001, false); // keys range from 0 to 10^6
    }
    
    void add(int key) {
        data[key] = true;
    }
    
    void remove(int key) {
        data[key] = false;
    }
    
    bool contains(int key) {
        return data[key];
    }
};
