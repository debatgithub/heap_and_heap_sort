#include <iostream>
#include "heap.h"
#include "sort_data.h"

int main(void );
void print_array(int the_data[], int n );



int main(void ) 
{
int i, j, k;
int *xptr;

    i = sizeof(unsorted_data)/sizeof(int);
    heap<int> * sorted_heap = new heap<int>(unsorted_data, i, MAX_HEAP );
    for (j = i-1; j >=0; j--) {
        sorted_heap->swap(unsorted_data, 0, j );
        sorted_heap->max_heapify(unsorted_data, j, 0 );
    }
    print_array(unsorted_data, i );
    return 0;
}


void print_array(int the_data[], int n )
{
    std::cout << "Array now = " << std::endl;
    for (int j = 0; j < n; j++) {
        if ((j+1)%16 == 0)
            std::cout << the_data[j] << " " << std::endl;
        else
            std::cout << the_data[j] << " ";
    }
    std::cout << std::endl;
}


           
    
  

 
