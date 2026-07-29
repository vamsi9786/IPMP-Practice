https://leetcode.com/problems/find-median-from-data-stream/description/

The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value, 
and the median is the mean of the two middle values.

For example, for arr = [2,3,4], the median is 3.
For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.
Implement the MedianFinder class:

MedianFinder() initializes the MedianFinder object.
void addNum(int num) adds the integer num from the data stream to the data structure.
double findMedian() returns the median of all elements so far. Answers within 10-5 of the actual answer will be accepted.

Algo/Idea: Use 2 heaps ==> max heap and min heap
           =====> use max heap to store left half ele and min heap to store right half ele.

class MedianFinder {
private:
    priority_queue<int> left; //max heap
    priority_queue<int,vector<int>,greater<int>> right; //min heap

public:
    MedianFinder() {
    }
    
    void addNum(int num) {
        if(left.empty() || num<=left.top()){
            left.push(num);
        }
        else{
            right.push(num);
        }

        if(left.size() > right.size()+1){
            right.push(left.top());
            left.pop();
        }
        else if(right.size() > left.size()+1){
            left.push(right.top());
            right.pop();
        }
    }
    
    double findMedian() {
        if(left.size()==right.size()){
            return (left.top()+right.top())/2.0;
        }
        if(left.size()>right.size()) return left.top();
        return right.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
