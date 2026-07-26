class MyHashMap {
public:
    MyHashMap() {
        this->map.resize(10,000);
        for (auto& bucket : this->map) {
            bucket = new ListNode(0, 0);
        }
    }
    
    void put(int key, int value) {
        ListNode* curNode = this->map[this->hash(key)];
        while (curNode->next != nullptr) {
            if (curNode->next->key == key) {
                curNode->next->value = value;
                return;
            }
            curNode = curNode->next;
        }
        curNode->next = new ListNode(key, value);
    }
    
    int get(int key) {
        if (this->contains(key)) {
            ListNode* curNode = this->map[this->hash(key)];
            while(curNode->next->key != key) {
                curNode = curNode->next;
            }
            return curNode->next->value;
        } else {
            return -1;
        }
        
    }
    
    void remove(int key) {
        if (!this->contains(key)) {
            return;
        } else {
            ListNode* curNode = this->map[this->hash(key)];
            while (curNode->next->key != key) {
                curNode = curNode->next;
            }
            ListNode* temp = curNode->next;
            curNode->next = temp->next;
            delete temp;
            return;
        }
    }

private:
    struct ListNode {
        ListNode* next;
        int key;
        int value;
        ListNode(int k, int v) : next(nullptr), key(k), value(v) {}
    };

    vector<ListNode*> map;

    int hash(int key) {
        return (key % this->map.size());
    }

    bool contains(int key) {
        ListNode* curNode = this->map[this->hash(key)];
        while (curNode->next != nullptr) {
            if (curNode->next->key == key) {
                return true;
            }
            curNode = curNode->next;
        }
        return false;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */