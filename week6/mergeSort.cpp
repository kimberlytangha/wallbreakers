#include <iostream>
#include <pthread.h>
#include <time.h>

using namespace std;

#define SIZE 1024
#define NUMTHREADS 4

// global vars
int nums[SIZE];
int section = 0; 

// merging your part of the array 
void merge(int low, int mid, int high) {
	// compute sizes of arrays 
	int sizeL = mid - low + 1; 
	int sizeR = high - mid;
	
	// split array into left and right halves
	int *left = new int[mid - low + 1];
	int *right = new int[high-mid];

	// pointers for left and right halves of array 
	int i; 
	int j;

	// copy left over to tmp array 
	for (i = 0; i < sizeL; i++) {
		int idx = low + i; 
		left[i] = nums[idx];
	}

	// copy right array over to tmp array 
	for (i = 0; i < sizeR; i++) {
		int idx = mid + i + 1; 
		right[i] = nums[idx];
	}

	int k = low;
	i = j = 0; 		// reset pointers to 0

	while (i < sizeL && j < sizeR) {
		// merge left and right arrays into nums

		if (left[i] <= right[j])	// store left if it's smaller
			nums[k++] = left[i++];
		else
			nums[k++] = right[j++]; // store right if it's smaller
	}

	// copy rest of values over 
	while (i < sizeL)
		nums[k++] = left[i++]; 		
	while (j < sizeR)
		nums[k++] = right[j++];	
}

void mergeSort(int low, int high) {
	// use this for mid instead of (high-low)/ 2 
	// to deal with large ints 
	int mid = low + (high - low) / 2; 

	if (low < high) {
		mergeSort(low, mid);		// ms first half
		mergeSort(mid+1, high);		// ms second half
		merge(low, mid, high);		// merge two halves
	}
}

// multi-threading merge sort 
void *mtMergeSort(void *argv) {
	int threadPart = section++; 

	// calculate how to splice array up 
	// and mergesort/ merge on different threads
	int low = threadPart * (SIZE / NUMTHREADS);
	int high = (threadPart + 1) * (SIZE / NUMTHREADS) - 1; 
	int mid = low + (high - low) / 2; 

	if (low < high) {
		// sort left and right halves
		mergeSort(low, mid);
		mergeSort(mid + 1, high);

		// merge both halfs of array
		merge(low, mid, high);
	}
}

void multithreadMS() {
	// initalize array with random values from 0..SIZE
	for (int i = 0; i < SIZE; i++) 
		nums[i] = rand() % SIZE; 

    cout << "Array inital state:" << endl; 
	// displaying sorted array 
    for (int i = 0; i < SIZE; i++) 
        cout << nums[i] << endl;
    cout << endl;

	clock_t beginTime, endTime;
	beginTime = clock(); 
	
	pthread_t threads[NUMTHREADS];
	for (int k = 0; k < NUMTHREADS; k++) 
		// create threads
		pthread_create(&threads[k], NULL, mtMergeSort, (void*) NULL);
	for (int k = 0; k < NUMTHREADS; k++)
		// rejoin threads after ms 
		pthread_join(threads[k], NULL);

	int midIdx = SIZE/2;
	
	merge(0, (midIdx-1)/2, midIdx-1); 					// 0 to mid
    merge(midIdx, midIdx+(SIZE-1-midIdx)/2, SIZE-1);	// mid to end
    merge(0, (SIZE-1)/2, SIZE-1); 						// 0 to end 

    endTime = clock(); 
  
    cout << "\nAfter multi-threaded merge sort:" << endl; 
    for (int i = 0; i < SIZE; i++) 
        cout << nums[i] << endl; 
  	cout << endl;

   	// time for ms in secs
    double runTime = (endTime - beginTime) / (double)CLOCKS_PER_SEC; 
    cout << "Took : " << runTime << "s" << endl; 
}


int main() {
	
	multithreadMS();

    return 0; 
}






