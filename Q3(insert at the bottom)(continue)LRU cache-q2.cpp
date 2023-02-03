#include<bits/stdc++.h>
using namespace std;


class LRUCache {
public:
    unordered_map<int, int> mp; // map to store the key and corresponding value
    unordered_map<int, list<int>::iterator> ad; // map to store the address of linked list node storeing the key to 
                                      // maintain the lru 
    list<int> l; // stl method to make a doubly linked list in c++. here we are using the ll to 
                // maintain the lru order
    int cap = 0; // cap to store the maximum size of the linked list
    int size = 0; // size to know the current size of the linked list so that it can't go beyound the 
                  //capacity
    LRUCache(int capacity) 
    {
        cap = capacity;
        size = 0;
    }
    
    int get(int key) 
    {
        if(mp.find(key) == mp.end()) 
            return -1;
        
        list<int> :: iterator it = ad[key];
        l.erase(it);
        l.push_front(key);
        ad.erase(key);
        ad[key] = l.begin();
        return mp[key];
    }
    
    void put(int key, int value) 
    {
        if(mp.find(key) != mp.end())
        {
            l.erase(ad[key]);
            ad.erase(key);
            mp.erase(key);
            size--;
        }
        
        if(size == cap)
        {
            int k = l.back();
            mp.erase(k);
            l.erase(ad[k]);
            ad.erase(k);
            size--;
        }
        
        size++;
        l.push_front(key);
        ad[key] = l.begin();
        mp[key] = value;
    }
};


int main()
{
    
}