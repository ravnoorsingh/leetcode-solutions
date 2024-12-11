class MyCircularQueue {
public:
    int f;  // front
    int b;  // back
    int s;  // current size
    int c;  // capacity
    vector<int> arr;
    MyCircularQueue(int k) {
        f = 0;
        b = 0;
        s = 0;
        c = k;
        vector<int> v(k);
        arr = v;
    }
    
    bool enQueue(int value) {
        if(s==c) return false;
        arr[b++] = value;
        if(b==c) b = 0;
        s++;
        return true;
    }
    
    bool deQueue() {
        if(s==0) return false;
        f++;
        if(f==c) f = 0;
        s--;
        return true;
    }
    
    int Front() {
        if(s==0) return -1;
        else return arr[f];
    }
    
    int Rear() {
        if(s==0) return -1;
        else if(b==0) return arr[c-1]; 
        else return arr[b-1];
    }
    
    bool isEmpty() {
        if(s==0) return true;
        else return false;
    }
    
    bool isFull() {
        if(s==c) return true;
        else return false;
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
