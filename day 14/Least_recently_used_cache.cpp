
Least Recently Used Cache (LRU cache)
          head <-> most recent <-> ... <-> least recent <-> tail
          we define insertion and remove of nodes based on req requirements
1. Get(k) we find the Node* using hash map and then we  remove that Node* and add it to start of LL (LRU) and return val
2. Put(k,v) we find Node* if already exists we update value and move it to front of LL
            else if cap is full we delete last of LL and create new node and insert it in start of LL


Using list stl

class LRUCache {
    int cap;
    list<pair<int,int>> dll;  
    unordered_map<int, list<pair<int,int>>> mp;

public:
    LRUCache(int capacity) {
        cap = capacity;
    }

    int get(int key) {
        if (mp.find(key) == mp.end())
            return -1;

        // Move accessed node to front (MRU)
        auto it = mp[key];
        int value = it->second;

        dll.erase(it);
        dll.push_front({key, value});
        mp[key] = dll.begin();

        return value;
    }

    void put(int key, int value) {

        // If key already exists
        if (mp.find(key) != mp.end()) {
            dll.erase(mp[key]);
        }
        else if (dll.size() == cap) {
            // Remove LRU element
            auto last = dll.back();
            mp.erase(last.first);
            dll.pop_back();
        }

        // Insert new or updated value at front
        dll.push_front({key, value});
        mp[key] = dll.begin();
    }
};



Using User defined Doubly linked list

class Node {
public:
    int key, value;
    Node* prev;
    Node* next;

    Node(int k, int v) {
        key = k;
        value = v;
        prev = next = NULL;
    }
};

class LRUCache {
private:
    int n;
    unordered_map<int,Node*> mp;
    Node* head;
    Node* tail;
public:
    LRUCache(int capacity) {
        n=capacity;
        head=new Node(0,0);
        tail=new Node(0,0);
        head->next=tail;
        tail->prev=head;
    }
    
    void remove(Node* t){
        t->prev->next=t->next;
        t->next->prev=t->prev;
    }

    void insertFront(Node* t){
        t->next=head->next;
        t->prev=head;
        head->next->prev=t;
        head->next=t;
    }

    int get(int key) {
        if(mp.find(key)==mp.end())  return -1;

        Node* t=mp[key];
        remove(t);
        insertFront(t);

        return t->value;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            Node* t=mp[key];
            t->value=value;
            remove(t);
            insertFront(t);
        }
        else{
            if(mp.size()==n){
                Node* t=tail->prev;
                remove(t);
                mp.erase(t->key);
                delete t;
            }
            Node* t=new Node(key,value);
            mp[key]=t;
            insertFront(t);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
