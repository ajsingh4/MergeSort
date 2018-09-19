//
//  main.cpp
//  MergeSort
//
//  Created by Aj Gill on 9/14/18.
//  Copyright © 2018 Aj Gill. All rights reserved.
//
//MergeSort(arr[], l,  r)
//If r > l
//1. Find the middle point to divide the array into two halves:
//middle m = (l+r)/2
//2. Call mergeSort for first half:
//Call mergeSort(arr, l, m)
//3. Call mergeSort for second half:
//Call mergeSort(arr, m+1, r)
//4. Merge the two halves sorted in step 2 and 3:
//Call merge(arr, l, m, r)

#include <iostream>
#include <math.h>

using namespace std;

void mergeSort(int arr[],int beginIndex, int endIndex);
void mergeArr(int arr[], int beginIndex, int middleIndex, int endIndex);


int main() {
    int arr[10] = {10,100,1,10,100,1,1,100,1,1000};
    int size = 10;
    mergeSort(arr, 0, size-1);
    
    for (int i=0; i<size; i++) {
        cout << arr[i] << endl;
    }
}

void mergeSort(int arr[],int beginIndex, int endIndex){
    if (endIndex > beginIndex) {
        int middleIndex = floor((endIndex+beginIndex)/2);
        mergeSort(arr, beginIndex, middleIndex);
        mergeSort(arr, middleIndex+1, endIndex);
        mergeArr(arr, beginIndex, middleIndex, endIndex);

    }
}

void mergeArr(int arr[], int beginIndex, int middleIndex, int endIndex){
    //get sizes of the two arrays
    int lengthFirstArray = middleIndex - beginIndex +1;
    int lengthSecondArray = endIndex - middleIndex;
    
    //create temp arrays of those sizes
    int leftArr[lengthFirstArray];
    int rightArr[lengthSecondArray];
    
    
    for(int i=0; i<lengthFirstArray;i++){
        leftArr[i] = arr[i+beginIndex];
    }
    for(int j=0; j<lengthSecondArray;j++){
        rightArr[j] = arr[middleIndex+1+j];
    }
    
    int i = 0; // Initial index of first subarray
    int j = 0; // Initial index of second subarray
    int k = beginIndex; // Initial index of merged subarray
    while (i < lengthFirstArray && j < lengthSecondArray)
    {
        if (leftArr[i] <= rightArr[j])
        {
            arr[k] = leftArr[i];
            i++;
        }
        else
        {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }
    //Copy any leftover numbers
    while (i < lengthFirstArray)
    {
        arr[k] = leftArr[i];
        i++;
        k++;
    }
    while (j < lengthSecondArray)
    {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}



