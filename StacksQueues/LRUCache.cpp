// 146

class LRUCache {
public:
    deque<int> q;
    unordered_map<int,int>mp;
    unordered_map<int, int> pairs;
    int cap=0;

    LRUCache(int capacity) {
        cap=capacity;
    }
    
    int get(int key) {
        if (mp.contains(key)==false) return -1; 
        stack <int> s;
        while (q.empty()!=true && q.front()!=key){
            s.push(q.front());
            q.pop_front();
        }
        q.pop_front();
        q.push_back(key);
        while(s.empty()!=true){
            q.push_front(s.top());
            s.pop();
        }
        return pairs[key];        
    }
    
    void put(int key, int value) {
        if (pairs.contains(key)) {
            pairs[key]=value;
            stack <int> s;
            while (q.empty()!=true && q.front()!=key){
                s.push(q.front());
                q.pop_front();
            }
            q.pop_front();
            q.push_back(key);
            while(s.empty()!=true){
                q.push_front(s.top());
                s.pop();
            }
        }
        else{
            if (q.size()>=cap){
                mp[q.front()]--;
                cout<<q.front()<<" "<<mp[q.front()]<<endl;
                if (mp[q.front()]==0){
                    mp.erase(q.front());
                    pairs.erase(q.front());
                } 
                q.pop_front();
            } 
            pairs[key]=value;
            mp[key]++;
            q.push_back(key);
        }

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */