#ifndef __INCLUDE_HEAP_H__
#define __INCLUDE_HEAP_H__
#include <iostream>
typedef enum e_heap_property { MAX_HEAP = 1, MIN_HEAP = 2 } HEAP_PROPERTY;

template <class T>
class heap {

public:
    
    heap (T _data[], int _sz, HEAP_PROPERTY _heap_type) { 
       if (_heap_type == MAX_HEAP) {
           for (int i = _sz/2 - 1; i >= 0; i--) 
               max_heapify(_data, _sz, i );
       }
       else if (_heap_type == MIN_HEAP) {
           for (int i = 0; i < _sz/2; i++) 
               min_heapify(_data, _sz, i );
       }
    };
    void max_heapify(T src[], int sz, int n ) {
        int largest = n;
        int l = heap_left(n );
        int r = heap_right(n );
        if ((l < sz) && (src[l] > src[largest]))
            largest = l;
        if ((r < sz) && (src[r] > src[largest]))
            largest = r;
        if (largest != n) {
            swap(src, largest, n );
            max_heapify(src, sz, largest );
        }
    };
    void min_heapify(T src[], int sz, int n ) {
        int smallest = n;
        int l = heap_left(n );
        int r = heap_right(n );
        if ((l <= sz) && (src[l] < src[smallest]))
            smallest = l;
        if ((r <= sz) && (src[r] < src[smallest]))
            smallest = r;
        if (smallest != n) {
            swap(src, smallest, n );
            min_heapify(src, sz, smallest );
        }
    };
    void swap(T src[], int i, int j ) {
        T temp = src[j];
        src[j] = src[i];
        src[i] = temp;
    };
    int heap_parent (int i) {
        return (i-1)/2;
    };
    int heap_left (int i) {
        return 2*i + 1;
    };
    int heap_right (int i) {
        return 2*i + 2;
    };    

};

#endif // __INCLUDE_HEAP_H__
