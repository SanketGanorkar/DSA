#include <iostream>
using namespace std;

class Heap
{
public:
    int arr[100];
    int size = 0;

    // The insert function is typically used for inserting a new element into the heap, usually just once per element that needs to be added to the heap. On the other hand, the heapify function is used for maintaining the heap property, often called after removal or replacement of elements, to ensure that the heap structure remains valid.

    void insert(int val)
    {
        // Time complexity - O(logn)

        size = size + 1;
        int index = size;
        arr[index] = val;

        while (index > 1)
        {
            int parent = index / 2;

            if (arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
            {
                return;
            }
        }
    }

    void deletefromHeap()
    {
        // Time complexity - O(logn)

        if (size == 0)
        {
            cout << "Nothing to delete" << endl;
            return;
        }
        arr[1] = arr[size];
        size--;

        int i = 1;
        while (i < size)
        {
            int leftIndex = 2 * i;
            int rightIndex = 2 * i + 1;

            if (leftIndex < size && arr[i] < arr[leftIndex])
            {
                swap(arr[i], arr[leftIndex]);
                i = leftIndex;
            }
            else if (rightIndex < size && arr[i] < arr[rightIndex])
            {
                swap(arr[i], arr[rightIndex]);
                i = rightIndex;
            }
            else
            {
                return;
            }
        }
    }

    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left <= n && arr[largest] < arr[left])
    {
        largest = left;
    }
    if (right <= n && arr[largest] < arr[right])
    {
        largest = right;
    }

    // largest upfate hogaya hai
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

// Time complexity - O(nlogn)
//  In a max heap, we know that the root element is always the maximum element. So, we swap the maximum element, which is the root element, with the last node. Consequently, we get the maximum element at the last row. After this, we reduce the size of the heap. As a result, we have two parts of our heap: the first part contains the maximum element, and the second part contains the rest of the elements.

// We continue this process until the size of our heap is less than or equal to one. This means we keep finding the maximum element and appending it to the other side of our heap until we have sorted all elements. So, the process repeats until we have only one element left in our heap, indicating that all elements have been sorted.
void heapsort(int arr[], int n)
{
    int size = n;

    while (size > 1)
    {
        swap(arr[size], arr[1]);
        size--;
        heapify(arr, size, 1);
    }
}

int main()
{
    Heap h;

    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.print();

    h.deletefromHeap();
    h.print();

    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;

    for (int i = n / 2; i > 0; i--)
    {
        heapify(arr, n, i);
    }

    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    heapsort(arr, n);
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}