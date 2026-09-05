// 295

class MedianFinder {
public:
    priority_queue<int, vector<int>, greater<>> pmin; // for greater elements, such that its top is median
    priority_queue<int> pmax; // for smaller elements, such that its top is median
    int count;
    MedianFinder() {
        count=0;
    }
    
    void addNum(int num) {
        if (pmax.empty()==true || num<=pmax.top()) pmax.push(num);
        else pmin.push(num);

        if (pmax.size()>pmin.size()+1){
            pmin.push(pmax.top());
            pmax.pop();
        }
        else if (pmin.size()>pmax.size()+1){
            pmax.push(pmin.top());
            pmin.pop();
        }
        count++;
    }
    
    double findMedian() {
        double ans=0;
        if (count%2==0){
            ans=(double)(pmin.top()+pmax.top())/2;
        }
        else{
            if (pmin.size()>pmax.size())ans=(double)pmin.top();
            else ans=(double) pmax.top();
        }
        return ans;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */