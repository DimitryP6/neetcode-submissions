class MyHashSet {
public:
    MyHashSet() {
        this->set.resize(10000);
        for (auto& bucket : this->set) {
            bucket = new ListNode(0);
        }
    }
    
    void add(int key) {
       ListNode* curNode = this->set[this->hash(key)];
       while (curNode->next != nullptr) {
        if (curNode->next->key == key) {
            return;
        } else {
            curNode = curNode->next;
        }
       }
       curNode->next = new ListNode(key); 
    }
    
    void remove(int key) {
        if (!this->contains(key)) {
            return;
        } else {
            ListNode* curNode = this->set[this->hash(key)];
            while (curNode->next->key != key) {
                curNode = curNode->next;
            }
            ListNode* temp = curNode->next;
            curNode->next = temp->next;
            delete temp;
            return;
        }
    }
    
    bool contains(int key) {
        ListNode* curNode = this->set[this->hash(key)];
        while (curNode->next != nullptr) {
            if (curNode->next->key == key) {
                return true;
            }
        }
        return false;
    }
private:
    struct ListNode {
        int key;
        ListNode* next;
        ListNode(int k) : key(k), next(nullptr) {}
    };

    vector<ListNode*> set;

    int hash(int key) {
        return key % set.size();
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */