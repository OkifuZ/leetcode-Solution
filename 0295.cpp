#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>


using namespace std;

class MedianFinder {
public:
    priority_queue<int, vector<int>, greater<int>> bottom_smaller; 
    priority_queue<int, vector<int>, less<int>> upper_bigger;

    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (bottom_smaller.size() > upper_bigger.size()) {
            bottom_smaller.push(num);
            upper_bigger.push(bottom_smaller.top());
            bottom_smaller.pop();
        }
        else {
            upper_bigger.push(num);
            bottom_smaller.push(upper_bigger.top());
            upper_bigger.pop();
        }
    }
    
    double findMedian() {
        if (bottom_smaller.size() > upper_bigger.size()) {
            return bottom_smaller.top();
        }
        if (bottom_smaller.size() < upper_bigger.size()) {
            return upper_bigger.top();
        }
        return 1.0 * (bottom_smaller.top() + upper_bigger.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

int main() {
    
}