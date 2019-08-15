#include<stdio.h>
#include <cstdlib> 

#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))

void merge(int array[],int start, int partition, int end){
    int i = start;
    int j = partition + 1;
    int index_sorted = start;
    int tmp_arr[end - start];
    while (i <= partition && j <= end )
    {

        if( j > end){
            tmp_arr[index_sorted] = array[i];
            i++;
            index_sorted++;
        }
        else if( i > partition ){
            tmp_arr[index_sorted] = array[j];
            j++;
            index_sorted++;
        }else if(array[i] <= array[j]){
            tmp_arr[index_sorted] = array[i];
            i++;
            index_sorted++;

        }else{
            tmp_arr[index_sorted] = array[j];
            j++;
            index_sorted++;
        };
    }
    for ( i = start; i <= end; i++)
    {
        array[i] = tmp_arr[i];
    }
    
}

void mergesort(int array[],int start, int end){

    int partition = (start + end) / 2;
    if (start < end)
    {
        mergesort(array,start,partition);
        mergesort(array,partition + 1,end);
        merge(array,start,partition,end);
    };
}


int main(void) {

    int array[] = {3,2,6,5,4,9,8,3};
    int array_length = ARRAY_LENGTH(array);
    mergesort(array,0,array_length);

    for(int i=0;i<array_length;++i){
        printf("%d\n", array[i]);
    }

    return 0;

}