class MyCircularQueue {
public:
    list<int> l;
    int max_size,current_size;
    MyCircularQueue(int k) {
        max_size=k;
        current_size=0;
    }
    
    bool enQueue(int value) {
        if(current_size==max_size) return false;
        l.push_back(value);
        current_size++;
        return true;
    }
    
    bool deQueue() {
        if(current_size==0) return false;
        l.pop_front();
        current_size--;
        return true;
    }
    
    int Front() {
        if(current_size==0) return -1;
        return l.front();
    }
    
    int Rear() {
        if(current_size==0) return -1;
        return l.back();
    }
    
    bool isEmpty() {
        return current_size==0;
    }
    
    bool isFull() {
        return current_size==max_size;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */