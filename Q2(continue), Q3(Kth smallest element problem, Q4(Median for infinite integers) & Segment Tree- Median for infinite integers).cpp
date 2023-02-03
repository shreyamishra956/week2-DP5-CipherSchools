#include<bits/stdc++.h>
using namespace std;

class MedianFinder {
public:
    priority_queue <int> max;
    priority_queue <int, vector<int>, greater<int>> min;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if((max.size() == 0) && (min.size() == 0))
        {
            max.push(num);
            return;
        }
        
        else if(max.size() > min.size())
        {
            min.push(num);
            if(max.top() > min.top())
            {
                int temp = max.top();
                max.pop();
                max.push(min.top());
                min.pop();
                min.push(temp);
            }
        }
        
        else
        {
            max.push(num);
            if(max.top() > min.top())
            {
                int temp = max.top();
                max.pop();
                max.push(min.top());
                min.pop();
                min.push(temp);
            }
        }
        
        
    }
    
    double findMedian() {
        if(max.size() > min.size())
        {
            return max.top();
        }
        else
        {
            return (max.top() + min.top())/2.0;
        }
    }
};


int main()
{
    
}