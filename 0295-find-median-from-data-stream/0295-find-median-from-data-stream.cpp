class MedianFinder {
public:
    priority_queue<int> big;
    priority_queue<int, vector<int>, greater<int>> smol;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        big.push(num);
        smol.push(big.top());
        big.pop();
        if(smol.size() > big.size()){
            big.push(smol.top());
            smol.pop();
        }
    }
    
    double findMedian() {
        if(big.size()  > smol.size()) return big.top();
        else return (big.top()+smol.top())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */