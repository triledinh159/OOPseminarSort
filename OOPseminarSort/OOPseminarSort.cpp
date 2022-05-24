#include <iostream>
#include <random>
#include <time.h>
#include <algorithm>
#include <Windows.h>
using namespace std;

int random(int min, int max) {
    static bool first = true;
    if (first) {
        srand(time(NULL));
        first = false;
    }
    return min + rand() % ((max + 1) - min);
}

void interChangeSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) swap(a[j], a[i]);

        }
}

void bubbleSort(int a[], int n) {
    for (int i = 0; i < n - 2; i++)
        for (int j = n - 1; j >= i + 1; j--) {
            if (a[j] < a[j - 1]) {
                int temp = a[j];
                a[j] = a[j - 1];
                a[j - 1] = temp;
            }
        }
}

void selectionSort(int a[], int n) {
    for (int i = 0; i <= n - 2; i++) {
        int lc = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[lc])
                lc = j;
        }
        swap(a[lc], a[i]);
    }
}

void heapify(int a[], int n, int vt) {
    while (vt <= (n / 2) - 1) {
        int child1 = 2 * vt + 1;
        int child2 = 2 * vt + 2;
        int lc = child1;
        if (child2 < n && a[lc] < a[child2])
            lc = child2;
        if (a[vt] < a[lc])
            swap(a[vt], a[lc]);
        vt = lc;
    }
}

void buildheap(int a[], int n) {
    for (int i = n / 2; i >= 0; i--)
        heapify(a, n, i);
}

void heapSort(int a[], int n) {
    buildheap(a, n);
    int length = n;
    while (length > 1) {
        swap(a[0], a[length - 1]);
        length--;
        heapify(a, length, 0);
    }
}

void Merge(int a[], int Left, int Mid, int Right) {
    int* temp = new int[Right - Left + 1];
    int n;
    int i = Left;
    int j = Mid + 1;
    n = 0;
    while (!(i > Mid && j > Right)) {
        if ((i <= Mid && j <= Right && a[i] < a[j]) || (j > Right))
            temp[n++] = a[i++];
        else
            temp[n++] = a[j++];
    }
    for (i = 0; i < n; i++)
        a[Left + i] = temp[i];
    delete[] temp;
}

void mergeSort(int a[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(a, left, mid);
        mergeSort(a, mid + 1, right);
        Merge(a, left, mid, right);
    }
}

void quickSort(int a[], int d, int c) {
    if (d > c)
        return;
    int low = d;
    int high = c;
    int sw = a[(d + c) / 2];
    do {
        while (a[low] < sw)
            low++;
        while (a[high] > sw)
            high--;
        if (low <= high) {
            swap(a[low], a[high]);
            low++;
            high--;
        }
    } while (low < high);
    if (d < high)
        quickSort(a, d, high);
    if (c > low)
        quickSort(a, low, c);
}

void insertionSort(int a[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
    }
}
void ShakerSort(int a[], int n)
{
    int Left = 0;
    int Right = n - 1;
    int k = 0;
    int i;
    while (Left < Right)
    {
        for (i = Left; i < Right; i++)
        {
            if (a[i] > a[i + 1])
            {
                swap(a[i], a[i + 1]);
                k = i;
            }
        }
        Right = k;
        for (i = Right; i > Left; i--)
        {
            if (a[i] < a[i - 1])
            {
                swap(a[i], a[i - 1]);
                k = i;
            }
        }
        Left = k;
    }
}
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
void binaryInsertionSort(int a[], int n)
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
void shellSort(int arr[], int n)
{
    // Start with a big gap, then reduce the gap
    for (int gap = n / 2; gap > 0; gap /= 2)
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
}

//void countSort(int array[], int size) {
//    // The size of count must be at least the (max+1) but
//    // we cannot assign declare it as int count(max+1) in C++ as
//    // it does not support dynamic memory allocation.
//    // So, its size is provided statically.
//    int output[100];
//    int count[100];
//    int max = array[0];
//
//    // Find the largest element of the array
//    for (int i = 1; i < size; i++) {
//        if (array[i] > max)
//            max = array[i];
//    }
//
//    // Initialize count array with all zeros.
//    for (int i = 0; i <= max; ++i) {
//        count[i] = 0;
//    }
//
//    // Store the count of each element
//    for (int i = 0; i < size; i++) {
//        count[array[i]]++;
//    }
//
//    // Store the cummulative count of each array
//    for (int i = 1; i <= max; i++) {
//        count[i] += count[i - 1];
//    }
//
//    // Find the index of each element of the original array in count array, and
//    // place the elements in output array
//    for (int i = size - 1; i >= 0; i--) {
//        output[count[array[i]] - 1] = array[i];
//        count[array[i]]--;
//    }
//
//    // Copy the sorted elements into original array
//    for (int i = 0; i < size; i++) {
//        array[i] = output[i];
//    }
//}

// Function to print an array
void printArray(int array[], int size) {
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;
}
//void radixSort(int* a, int n)
//{
//    int b[10000], m = a[0], exp = 1;
//
//    for (int i = 0; i < n; i++)
//        if (a[i] > m)
//            m = a[i];
//
//    while (m / exp > 0)
//    {
//        int bucket[10] = { 0 };
//        for (int i = 0; i < n; i++)
//            bucket[a[i] / exp % 10]++;
//        for (int i = 1; i < 10; i++)
//            bucket[i] += bucket[i - 1];
//        for (int i = n - 1; i >= 0; i--)
//            b[--bucket[a[i] / exp % 10]] = a[i];
//        for (int i = 0; i < n; i++)
//            a[i] = b[i];
//        exp *= 10;
//    }
//}
void generateIntArray(int a[], int& n) {
    for (int i = 0; i < n; i++)
        a[i] = random(-50000, 50000);
}

void output(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
}
void output1(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
}

int main() {

    clock_t start, end;

    int x, n;
    cout << "Choose size: \n1. 100\n2.1000\n3.5000\n4.10000\n5.50000\nPick a number: ";

    while (true) {
        cin >> x;
        if (x == 1)  n = 100;
        if (x == 2)  n = 1000;
        if (x == 3)  n = 1000;
        if (x == 4)  n = 10000;
        if (x == 5)  n = 50000;
        if (x <= 0 || x > 5) cout << "Invalid, please retype: ";
        else break;
    }
    int a[50000], b[50000];
    generateIntArray(a, n);
    for (int i = 0; i < n; i++) {
        b[i] = a[i];


    }
    cout << "Original string number: \n";
    output1(a, n);

    //cout << "\n\nInterchange Sort: \n";
    //start = clock();
    //interChangeSort(a, n);
    //output(a, n);
    //end = clock();
    //cout << "\nRuntime: ";
    //cout << (double)(end - start) / CLOCKS_PER_SEC;

    //cout << "\n\nBubble Sort: \n";
    //start = clock();
    //bubbleSort(b, n);
    //output(b, n);
    //end = clock();
    //cout << "\nRuntime: ";
    //cout << (double)(end - start) / CLOCKS_PER_SEC;

    //cout << "\n\nSelection Sort: \n";
    //start = clock();
    //selectionSort(a, n);
    //output(a, n);
    //end = clock();
    //cout << "\nRuntime: ";
    //cout << (double)(end - start) / CLOCKS_PER_SEC;

    //cout << "\n\nHeap Sort: \n";
    //start = clock();
    //heapSort(b, n);
    //output(b, n);
    //end = clock();
    //cout << "\nRuntime: ";
    //cout << (double)(end - start) / CLOCKS_PER_SEC;
    //cout << "\n\nMerge Sort: \n";
    //start = clock();
    //mergeSort(a, 0, n - 1);
    //output(a, n);
    //end = clock();
    //cout << "\nRuntime: ";
    //cout << (double)(end - start) / CLOCKS_PER_SEC;

    //cout << "\n\nQuick Sort: \n";
    //start = clock();
    //quickSort(a, 0, n - 1);
    //output(a, n);
    //end = clock();
    //cout << "\nRuntime: ";
    //cout << (double)(end - start) / CLOCKS_PER_SEC;

    //cout << "\n\nIntersection Sort: \n";
    //start = clock();
    //insertionSort(a, n);
    //output(a, n);
    //end = clock();
    //cout << "\nRuntime: ";
    //cout << (double)(end - start) / CLOCKS_PER_SEC;


    //cout << "\n\nBinary Intersection Sort: \n";
    //start = clock();
    //binaryInsertionSort(a, n);
    //output(a, n);
    //end = clock();
    //cout << "\nRuntime: ";
    //cout << (double)(end - start) / CLOCKS_PER_SEC;

    //cout << "\n\nShaker Sort: \n";
    //start = clock();
    //ShakerSort(a, n);
    //output(a, n);
    //end = clock();
    //cout << "\nRuntime: ";
    //cout << (double)(end - start) / CLOCKS_PER_SEC;

    //cout << "\n\nShell Sort: \n";
    //start = clock();
    //shellSort(a, n);
    //output(a, n);
    //end = clock();
    //cout << "\nRuntime: ";
    //cout << (double)(end - start) / CLOCKS_PER_SEC;

    //cout << "\n\nCount Sort: \n";
    //start = clock();
    //countSort(a, n);
    //output(a, n);
    //end = clock();
    //cout << "\nRuntime: ";
    //cout << (double)(end - start) / CLOCKS_PER_SEC;
    //system("pause");
    //return 0;

    //cout << "\n\nRadix Sort: \n";
    //start = clock();
    //radixSort(&a[0], n);
    //output(a, n);
    //end = clock();
    //cout << "\nRuntime: ";
    //cout << (double)(end - start) / CLOCKS_PER_SEC;
    //system("pause");
    //return 0;
}

