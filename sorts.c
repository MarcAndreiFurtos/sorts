#include <stdio.h>


//swap function
void swapInts(int *a ,int *b){
    int tmp = *a;
    *a = *b ;
    *b = tmp;
}

// shaker sort :
// 2 steps ,step 1 run through the array from start to end switching elements
// untill bigest element is at the end, step 2 run through elements from  
// end to start swapping as you go untill smallest element is at start 
// repeat steps untill array is sorted 

void shakerSort(int arr[],int n){
    int start = 0;
    int end = n-1;
    for(int j = 0 ; j < n ; j++){
        for(int i = start ; i < end ; i++){
            if (arr[i]>arr[i+1]){
                swapInts(&arr[i],&arr[i+1]);
            }
        }
        for(int i = end ; i <= start ; i--){
             if (arr[i]>arr[i+1]){
                swapInts(&arr[i],&arr[i+1]);
            }
        }
    }
}


//insertion sort you start with 3 variables i,j and key  i and j are 
//counters and key is the element that we compare to 
//to start the sort we set i to 1 the key to the element on position i
//and j to i-1 then we tell the function that while j >=0 and arr[j] > key
//it should keep moving the element down that results in it being in the 
// right position

void insertionSort(int arr[], int n){
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }

}

//check the first element with the next keep checking that element until
//it is in the right position on the top then grab the first element 
//again and repeat

void bubbleSort(int arr[],int n){
    int end = n-1;
    for(int i =0; i < n ; i++){
        for (int j =0; j < end;j++){
            if (arr[j]>arr[j+1]){
                swapInts(&arr[j],&arr[j+1]);
            }
        }
    }
}

// this sort searches for the smallest
// element and it switches it with the element on position i
// it does this repeatedly untill every element is in the right position
// the way it searches for the smallest element is 
// it goes through all the elements untill it finds the one that is smallest

void selectionSort(int arr[], int n)
{
    int i, j, min_idx;
 
    // One by one move boundary of unsorted subarray
    for (i = 0; i < n-1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++)
          if (arr[j] < arr[min_idx])
            min_idx = j;
 
        // Swap the found minimum element with the first element
           if(min_idx != i)
            swapInts(&arr[min_idx], &arr[i]);
    }
}



// binary insertion sort is just a insertion sort that uses a binary search 
// instead of a normal search ,the binary search is 
// given the array the start and end of it and it devides it in half constantly
// to find the place where the item you are searching for is 
// (untill the item is in the miffle of a the array)


int binarySearch(int a[], int item, 
                 int low, int high)
{
    if (high <= low)
        return (item > a[low]) ? 
                (low + 1) : low;
  
    int mid = (low + high) / 2;
  
    if (item == a[mid])
        return mid + 1;
  
    if (item > a[mid])
        return binarySearch(a, item, 
                            mid + 1, high);
    return binarySearch(a, item, low, 
                        mid - 1);
}
  
// Function to sort an array a[] of size 'n'
void insertionSort(int a[], int n)
{
    int i, loc, j, k, selected;
  
    for (i = 1; i < n; ++i) 
    {
        j = i - 1;
        selected = a[i];
  
        // find location where selected should be inseretd
        loc = binarySearch(a, selected, 0, j);
  
        // Move all elements after location to create space
        while (j >= loc) 
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = selected;
    }
}



// shell sort the idea of this sort is that we sort with a gap the first for loop starts
// by setting the gap to half of the lenght of the array and halfing it each itteration
// the second loop starts at gap and it ends at n ,in the second loop the following happens
// a temp value is created and it gets the vallue of arr of i this is the value we will
// switch around ,in the third loop we start at i abd end at gap decreasing the value of j 
// this is going to be used to check the values behind temp in order to see if we need to 
// switch or not  if j>=gap and arr[j-gap]>temp we switch after that we put temp in its
// correct place 

int shellSort(int arr[], int n)
{
    // Start with a big gap, then reduce the gap
    for (int gap = n/2; gap > 0; gap /= 2)
    {
        // Do a gapped insertion sort for this gap size.
        // The first gap elements a[0..gap-1] are already in gapped order
        // keep adding one more element until the entire array is
        // gap sorted 
        for (int i = gap; i < n; i += 1)
        {
            // add a[i] to the elements that have been gap sorted
            // save a[i] in temp and make a hole at position i
            int temp = arr[i];
  
            // shift earlier gap-sorted elements up until the correct 
            // location for a[i] is found
            int j;            
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
              
            //  put temp (the original a[i]) in its correct location
            arr[j] = temp;
        }
    }
    return 0;
}

// heap sort, you turn the array into a max heap by heapifying the array then
// you extract the top element place it at the bottom of the array and heapyfi the 
// array again

void heapify(int arr[], int n, int i) {
    int largest = i;  // Initialize largest as root
    int left = 2 * i + 1;  // left = 2*i + 1
    int right = 2 * i + 2;  // right = 2*i + 2

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not root
    if (largest != i) {
        swapInts(&arr[i], &arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

// Main function to do heap sort
void heapSort(int arr[], int n) {
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // One by one extract an element from heap
    for (int i = n - 1; i >= 0; i--) {
        // Move current root to end
        swapInts(&arr[0], &arr[i]);

        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

// radix


// A utility function to get maximum value in arr[]
int getMax(int arr[], int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

// A function to do counting sort of arr[] according to
// the digit represented by exp.
void countSort(int arr[], int n, int exp)
{
    int output[n]; // output array
    int i, count[10] = {0};

    // Store count of occurrences in count[]
    for (i = 0; i < n; i++)
        count[ (arr[i]/exp)%10 ]++;

    // Change count[i] so that count[i] now contains actual
    //  position of this digit in output[]
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build the output array
    for (i = n - 1; i >= 0; i--)
    {
        output[count[ (arr[i]/exp)%10 ] - 1] = arr[i];
        count[ (arr[i]/exp)%10 ]--;
    }

    // Copy the output array to arr[], so that arr[] now
    // contains sorted numbers according to current digit
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}

// The main function to that sorts arr[] of size n using
// Radix Sort
void radixsort(int arr[], int n)
{
    // Find the maximum number to know number of digits
    int m = getMax(arr, n);

    // Do counting sort for every digit. Note that instead
    // of passing digit number, exp is passed. exp is 10^i
    // where i is current digit number
    for (int exp = 1; m/exp > 0; exp *= 10)
        countSort(arr, n, exp);
}



// quick sort uses recursion it is a sorting algorithm which does the following:
// first it picks a pivot as the rightmost element then it takes 2 counters i and j
// j will circle through all the numbers untill it finds one that is <= than the pivot
// at which point it will increment i and swap arr[i] with arr[j] it does this untill j
// gets to the pivot at which point the function swaps arr[i+1] with arr[high] which 
// puts the pivot in the correct position ,after this the function is recursively called
// on the lower and higher halfs of the array

int partition (int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high- 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swapInts(&arr[i], &arr[j]);
        }
    }
    swapInts(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// binsort also known as bucket sort
// Create an array of empty "bins" or "buckets" where each bin represents a range of values.
// Iterate through the original unsorted array, and for each element,
// determine which bin it belongs to based on its value.
// Insert the element into the appropriate bin.
// Sort the elements within each bin, for example, using insertion sort.
// Concatenate the elements from all the bins back into the original array in the 
// order of the bins

#define MAX_BUCKETS 100

struct Node {
    int data;
    struct Node* next;
};

void bucketSort(int arr[], int n) {
    struct Node* buckets[MAX_BUCKETS];
    int i, j, k;

    for (i = 0; i < MAX_BUCKETS; i++) {
        buckets[i] = NULL;
    }

    for (i = 0; i < n; i++) {
        struct Node* current;
        current = (struct Node*)malloc(sizeof(struct Node));
        current->data = arr[i];
        current->next = buckets[arr[i]];
        buckets[arr[i]] = current;
    }

    for (k = 0, i = 0; i < MAX_BUCKETS; i++) {
        struct Node* current;
        current = (struct Node*)malloc(sizeof(struct Node));
        for (current = buckets[i]; current; current = current->next) {
            arr[k++] = current->data;
        }
    }
}

// merge sort splits the array in eaven sides untill you get 1 element arrays then it
// merges them with the merge function putting them back with the smallest elements first
// and the biggest ones last 


void merge(int arr[], int left[], int leftSize, int right[], int rightSize) {
    int i = 0, j = 0, k = 0;
    while (i < leftSize && j < rightSize) {
        if (left[i] <= right[j]) {
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
        }
    }
    while (i < leftSize) {
        arr[k++] = left[i++];
    }
    while (j < rightSize) {
        arr[k++] = right[j++];
    }
}

void mergeSort(int arr[], int n) {
    if (n < 2) {
        return;
    }
    int mid = n / 2;
    int left[mid];
    int right[n - mid];
    for (int i = 0; i < mid; i++) {
        left[i] = arr[i];
    }
    for (int i = mid; i < n; i++) {
        right[i - mid] = arr[i];
    }
    mergeSort(left, mid);
    mergeSort(right, n - mid);
    merge(arr, left, mid, right, n - mid);
}
