/*// Implement a Maxheap/MinHeap using arrays and recursion.
#include <bits/stdc++.h>
using namespace std;
void heapify(int arr[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = i * 2 + 2;
    if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}
void buildHeap(int arr[], int n)
{
    int startIdx = (n / 2) - 1;
    for (int i = startIdx; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
}
void printHeap(int arr[], int n)
{
    cout << "Array represenatation of Heap is:\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";
}
int main()
{
    int arr[] = {1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17};

    int n = sizeof(arr) / sizeof(arr[0]);

    buildHeap(arr, n);

    printHeap(arr, n);
    return 0;
}*/
/*// Sort an Array using heap. (HeapSort)
#include <iostream>
using namespace std;
void heapify(int arr[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}
void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}
int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    heapSort(arr, n);

    cout << "Sorted array is \n";
    printArray(arr, n);
}*/
/*// Maximum of all subarrays of size k.
#include <bits/stdc++.h>
using namespace std;
void printKMax(int arr[], int n, int k)
{
    int j, max;
    for (int i = 0; i <= n - k; i++)
    {
        max = arr[i];
        for (int j = 1; j < k; j++)
        {
            if (arr[i + j] > max)
                max = arr[i + j];
        }
        cout << max << " ";
    }
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    printKMax(arr, n, k);
    return 0;
}*/
/*// “k” largest element in an array
#include <bits/stdc++.h>
using namespace std;
void kLargest(int arr[], int n, int k)
{
    sort(arr, arr + n, greater<int>());
    for (int i = 0; i < k; i++)
        cout << arr[i] << " ";
}
int main()
{
    int arr[] = {1, 23, 12, 9, 30, 2, 50};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    kLargest(arr, n, k);
    return 0;
}*/
/*// Kth smallest and largest element in an unsorted array
#include <algorithm>
#include <iostream>
using namespace std;
int kthSmallest(int arr[], int n, int k)
{
	sort(arr, arr + n);
	return arr[k - 1];
}
int main()
{
	int arr[] = { 12, 3, 5, 7, 19 };
	int n = sizeof(arr) / sizeof(arr[0]), k = 2;
	cout << "K'th smallest element is " << kthSmallest(arr, n, k);
	return 0;
}*/
/*// Merge “K” sorted arrays. [ IMP ]
#include<bits/stdc++.h>
using namespace std;
#define n 4
struct MinHeapNode
{
	int element;
	int i,j;
};
void swap(MinHeapNode *x, MinHeapNode *y);
class MinHeap
{
	MinHeapNode *harr;
	int heap_size;
public:
	MinHeap(MinHeapNode a[], int size);
	void MinHeapify(int );
	int left(int i) { return (2*i + 1); }
	int right(int i) { return (2*i + 2); }
	MinHeapNode getMin() { return harr[0]; }
	void replaceMin(MinHeapNode x) { harr[0] = x; MinHeapify(0); }
};
int *mergeKArrays(int arr[][n], int k)
{
	int *output = new int[n*k];
	MinHeapNode *harr = new MinHeapNode[k];
	for (int i = 0; i < k; i++)
	{
		harr[i].element = arr[i][0];
		harr[i].i = i;
		harr[i].j = 1;
	}
	MinHeap hp(harr, k);
	for (int count = 0; count < n*k; count++)
	{
		MinHeapNode root = hp.getMin();
		output[count] = root.element;
		if (root.j < n)
		{
			root.element = arr[root.i][root.j];
			root.j += 1;
		}
else root.element = INT_MAX;
		hp.replaceMin(root);
	}
	return output;
}
MinHeap::MinHeap(MinHeapNode a[], int size)
{
	heap_size = size;
	harr = a; 
	int i = (heap_size - 1)/2;
	while (i >= 0)
	{
		MinHeapify(i);
		i--;
	}
}
void MinHeap::MinHeapify(int i)
{
	int l = left(i);
	int r = right(i);
	int smallest = i;
	if (l < heap_size && harr[l].element < harr[i].element)
		smallest = l;
	if (r < heap_size && harr[r].element < harr[smallest].element)
		smallest = r;
	if (smallest != i)
	{
		swap(&harr[i], &harr[smallest]);
		MinHeapify(smallest);
	}
}
void swap(MinHeapNode *x, MinHeapNode *y)
{
	MinHeapNode temp = *x; *x = *y; *y = temp;
}
void printArray(int arr[], int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}
int main()
{
	int arr[][n] = {{2, 6, 12, 34},
					{1, 9, 20, 1000},
					{23, 34, 90, 2000}};
	int k = sizeof(arr)/sizeof(arr[0]);

	int *output = mergeKArrays(arr, k);

	cout << "Merged array is " << endl;
	printArray(output, n*k);
	return 0;
}*/
/*// Merge 2 Binary Max Heaps
#include <bits/stdc++.h>
using namespace std;
void maxHeapify(int arr[], int n, int idx)
{
    if (idx >= n)
        return;
    int l = 2 * idx + 1;
    int r = 2 * idx + 2;
    int max;
    if (l < n && arr[l] > arr[idx])
        max = l;
    else
        max = idx;
    if (r < n && arr[r] > arr[max])
        max = r;
    if (max != idx)
    {
        swap(arr[max], arr[idx]);
        maxHeapify(arr, n, max);
    }
}
void buildMaxHeap(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        maxHeapify(arr, n, i);
}
void mergeHeaps(int merged[], int a[], int b[],
                int n, int m)
{
    for (int i = 0; i < n; i++)
        merged[i] = a[i];
    for (int i = 0; i < m; i++)
        merged[n + i] = b[i];
    buildMaxHeap(merged, n + m);
}
int main()
{
    int a[] = {10, 5, 6, 2};
    int b[] = {12, 7, 9};

    int n = sizeof(a) / sizeof(a[0]);
    int m = sizeof(b) / sizeof(b[0]);

    int merged[m + n];
    mergeHeaps(merged, a, b, n, m);

    for (int i = 0; i < n + m; i++)
        cout << merged[i] << " ";

    return 0;
}*/
/*// Kth largest sum continuous subarrays
#include <bits/stdc++.h>
using namespace std;
int kthLargestSum(int arr[], int n, int k)
{
    int sum[n + 1];
    sum[0] = 0;
    sum[1] = arr[0];
    for (int i = 2; i <= n; i++)
        sum[i] = sum[i - 1] + arr[i - 1];
    priority_queue<int, vector<int>, greater<int>> Q;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            int x = sum[j] - sum[i - 1];
            if (Q.size() < k)
                Q.push(x);
            else
            {
                if (Q.top() < x)
                {
                    Q.pop();
                    Q.push(x);
                }
            }
        }
    }
    return Q.top();
}

int main()
{
    int a[] = {10, -10, 20, -40};
    int n = sizeof(a) / sizeof(a[0]);
    int k = 6;
    cout << kthLargestSum(a, n, k);
    return 0;
}*/
/*// Leetcode- reorganize strings
string 1198*/
/*// Merge “K” Sorted Linked Lists [V.IMP]
LinkedList 1900*/
/*// Smallest range in “K” Lists
#include <bits/stdc++.h>
using namespace std;
#define N 5
struct MinHeapNode
{
    int element;
    int i;
    int j;
};
void swap(MinHeapNode *x, MinHeapNode *y);
class MinHeap
{
    MinHeapNode *harr;
    int heap_size;

public:
    MinHeap(MinHeapNode a[], int size);
    void MinHeapify(int);
    int left(int i) { return (2 * i + 1); }
    int right(int i) { return (2 * i + 2); }
    MinHeapNode getMin() { return harr[0]; }
    void replaceMin(MinHeapNode x)
    {
        harr[0] = x;
        MinHeapify(0);
    }
};
MinHeap::MinHeap(MinHeapNode a[], int size)
{
    heap_size = size;
    harr = a;
    int i = (heap_size - 1) / 2;
    while (i >= 0)
    {
        MinHeapify(i);
        i--;
    }
}
void MinHeap::MinHeapify(int i)
{
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < heap_size && harr[l].element < harr[i].element)
        smallest = l;
    if (r < heap_size && harr[r].element < harr[smallest].element)
        smallest = r;
    if (smallest != i)
    {
        swap(harr[i], harr[smallest]);
        MinHeapify(smallest);
    }
}
void findSmallestRange(int arr[][N], int k)
{
    int range = INT_MAX;
    int min = INT_MAX, max = INT_MIN;
    int start, end;

    MinHeapNode *harr = new MinHeapNode[k];
    for (int i = 0; i < k; i++)
    {
        harr[i].element = arr[i][0];
        harr[i].i = i;
        harr[i].j = 1;
        if (harr[i].element > max)
            max = harr[i].element;
    }
    MinHeap hp(harr, k);
    while (1)
    {
        MinHeapNode root = hp.getMin();
        min = hp.getMin().element;
        if (range > max - min + 1)
        {
            range = max - min + 1;
            start = min;
            end = max;
        }
        if (root.j < N)
        {
            root.element = arr[root.i][root.j];
            root.j += 1;
            if (root.element > max)
                max = root.element;
        }
        else
            break;
        hp.replaceMin(root);
    }
    cout << "The smallest range is "
         << "["
         << start << " " << end << "]" << endl;
    ;
}
int main()
{
    int arr[][N] = {
        {4, 7, 9, 12, 15},
        {0, 8, 10, 14, 20},
        {6, 12, 16, 30, 50}};
    int k = sizeof(arr) / sizeof(arr[0]);

    findSmallestRange(arr, k);
    return 0;
}*/
/*// Median in a stream of Integers
#include <iostream>
using namespace std;

// Heap capacity
#define MAX_HEAP_SIZE (128)
#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])

//// Utility functions

// exchange a and b
inline
void Exch(int &a, int &b)
{
	int aux = a;
	a = b;
	b = aux;
}

// Greater and Smaller are used as comparators
bool Greater(int a, int b)
{
	return a > b;
}

bool Smaller(int a, int b)
{
	return a < b;
}

int Average(int a, int b)
{
	return (a + b) / 2;
}

// Signum function
// = 0 if a == b - heaps are balanced
// = -1 if a < b - left contains less elements than right
// = 1 if a > b - left contains more elements than right
int Signum(int a, int b)
{
	if( a == b )
		return 0;

	return a < b ? -1 : 1;
}

// Heap implementation
// The functionality is embedded into
// Heap abstract class to avoid code duplication
class Heap
{
public:
	// Initializes heap array and comparator required
	// in heapification
	Heap(int *b, bool (*c)(int, int)) : A(b), comp(c)
	{
		heapSize = -1;
	}

	// Frees up dynamic memory
	virtual ~Heap()
	{
		if( A )
		{
			delete[] A;
		}
	}

	// We need only these four interfaces of Heap ADT
	virtual bool Insert(int e) = 0;
	virtual int GetTop() = 0;
	virtual int ExtractTop() = 0;
	virtual int GetCount() = 0;

protected:

	// We are also using location 0 of array
	int left(int i)
	{
		return 2 * i + 1;
	}

	int right(int i)
	{
		return 2 * (i + 1);
	}

	int parent(int i)
	{
		if( i <= 0 )
		{
			return -1;
		}

		return (i - 1)/2;
	}

	// Heap array
	int *A;
	// Comparator
	bool (*comp)(int, int);
	// Heap size
	int heapSize;

	// Returns top element of heap data structure
	int top(void)
	{
		int max = -1;

		if( heapSize >= 0 )
		{
			max = A[0];
		}

		return max;
	}

	// Returns number of elements in heap
	int count()
	{
		return heapSize + 1;
	}

	// Heapification
	// Note that, for the current median tracing problem
	// we need to heapify only towards root, always
	void heapify(int i)
	{
		int p = parent(i);

		// comp - differentiate MaxHeap and MinHeap
		// percolates up
		if( p >= 0 && comp(A[i], A[p]) )
		{
			Exch(A[i], A[p]);
			heapify(p);
		}
	}

	// Deletes root of heap
	int deleteTop()
	{
		int del = -1;

		if( heapSize > -1)
		{
			del = A[0];

			Exch(A[0], A[heapSize]);
			heapSize--;
			heapify(parent(heapSize+1));
		}

		return del;
	}

	// Helper to insert key into Heap
	bool insertHelper(int key)
	{
		bool ret = false;

		if( heapSize < MAX_HEAP_SIZE )
		{
			ret = true;
			heapSize++;
			A[heapSize] = key;
			heapify(heapSize);
		}

		return ret;
	}
};

// Specilization of Heap to define MaxHeap
class MaxHeap : public Heap
{
private:

public:
	MaxHeap() : Heap(new int[MAX_HEAP_SIZE], &Greater) { }

	~MaxHeap() { }

	// Wrapper to return root of Max Heap
	int GetTop()
	{
		return top();
	}

	// Wrapper to delete and return root of Max Heap
	int ExtractTop()
	{
		return deleteTop();
	}

	// Wrapper to return # elements of Max Heap
	int GetCount()
	{
		return count();
	}

	// Wrapper to insert into Max Heap
	bool Insert(int key)
	{
		return insertHelper(key);
	}
};

// Specilization of Heap to define MinHeap
class MinHeap : public Heap
{
private:

public:

	MinHeap() : Heap(new int[MAX_HEAP_SIZE], &Smaller) { }

	~MinHeap() { }

	// Wrapper to return root of Min Heap
	int GetTop()
	{
		return top();
	}

	// Wrapper to delete and return root of Min Heap
	int ExtractTop()
	{
		return deleteTop();
	}

	// Wrapper to return # elements of Min Heap
	int GetCount()
	{
		return count();
	}

	// Wrapper to insert into Min Heap
	bool Insert(int key)
	{
		return insertHelper(key);
	}
};

// Function implementing algorithm to find median so far.
int getMedian(int e, int &m, Heap &l, Heap &r)
{
	// Are heaps balanced? If yes, sig will be 0
	int sig = Signum(l.GetCount(), r.GetCount());
	switch(sig)
	{
	case 1: // There are more elements in left (max) heap

		if( e < m ) // current element fits in left (max) heap
		{
			// Remore top element from left heap and
			// insert into right heap
			r.Insert(l.ExtractTop());

			// current element fits in left (max) heap
			l.Insert(e);
		}
		else
		{
			// current element fits in right (min) heap
			r.Insert(e);
		}

		// Both heaps are balanced
		m = Average(l.GetTop(), r.GetTop());

		break;

	case 0: // The left and right heaps contain same number of elements

		if( e < m ) // current element fits in left (max) heap
		{
			l.Insert(e);
			m = l.GetTop();
		}
		else
		{
			// current element fits in right (min) heap
			r.Insert(e);
			m = r.GetTop();
		}

		break;

	case -1: // There are more elements in right (min) heap

		if( e < m ) // current element fits in left (max) heap
		{
			l.Insert(e);
		}
		else
		{
			// Remove top element from right heap and
			// insert into left heap
			l.Insert(r.ExtractTop());

			// current element fits in right (min) heap
			r.Insert(e);
		}

		// Both heaps are balanced
		m = Average(l.GetTop(), r.GetTop());

		break;
	}

	// No need to return, m already updated
	return m;
}

void printMedian(int A[], int size)
{
	int m = 0; // effective median
	Heap *left = new MaxHeap();
	Heap *right = new MinHeap();

	for(int i = 0; i < size; i++)
	{
		m = getMedian(A[i], m, *left, *right);

		cout << m << endl;
	}

	// C++ more flexible, ensure no leaks
	delete left;
	delete right;
}
// Driver code
int main()
{
	int A[] = {5, 15, 1, 3, 2, 8, 7, 9, 10, 6, 11, 4};
	int size = ARRAY_SIZE(A);

	// In lieu of A, we can also use data read from a stream
	printMedian(A, size);

	return 0;
}*/
/*// Check if a Binary Tree is Heap
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
};
struct Node *newNode(int k)
{
    struct Node *node = new Node;
    node->key = k;
    node->right = node->left = NULL;
    return node;
}
unsigned int countNodes(struct Node *root)
{
    if (root == NULL)
        return (0);
    return (1 + countNodes(root->left) + countNodes(root->right));
}
bool isCompleteUtil(struct Node *root,
                    unsigned int index,
                    unsigned int number_nodes)
{
    if (root == NULL)
        return (true);
    if (index >= number_nodes)
        return (false);
    return (isCompleteUtil(root->left, 2 * index + 1,
                           number_nodes) &&
            isCompleteUtil(root->right, 2 * index + 2,
                           number_nodes));
}
bool isHeapUtil(struct Node *root)
{
    if (root->left == NULL && root->right == NULL)
        return (true);
    if (root->right == NULL)
    {
        return (root->key >= root->left->key);
    }
    else
    {
        if (root->key >= root->left->key &&
            root->key >= root->right->key)
            return ((isHeapUtil(root->left)) &&
                    (isHeapUtil(root->right)));
        else
            return (false);
    }
}
bool isHeap(struct Node *root)
{
    unsigned int node_count = countNodes(root);
    unsigned int index = 0;

    if (isCompleteUtil(root, index,
                       node_count) &&
        isHeapUtil(root))
        return true;
    return false;
}
int main()
{
    struct Node *root = NULL;
    root = newNode(10);
    root->left = newNode(9);
    root->right = newNode(8);
    root->left->left = newNode(7);
    root->left->right = newNode(6);
    root->right->left = newNode(5);
    root->right->right = newNode(4);
    root->left->left->left = newNode(3);
    root->left->left->right = newNode(2);
    root->left->right->left = newNode(1);

    if (isHeap(root))
        cout << "Given binary tree is a Heap\n";
    else
        cout << "Given binary tree is not a Heap\n";

    return 0;
}*/
/*// Connect “n” ropes with minimum cost
greedy 1021*/
/*// Convert BST to Min Heap
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left, *right;
};

struct Node *getNode(int data)
{
    struct Node *newNode = new Node;
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void preorderTraversal(Node *);

void inorderTraversal(Node *root, vector<int> &arr)
{
    if (root == NULL)
        return;
    inorderTraversal(root->left, arr);
    arr.push_back(root->data);
    inorderTraversal(root->right, arr);
}

void BSTToMinHeap(Node *root, vector<int> arr, int *i)
{
    if (root == NULL)
        return;
    root->data = arr[++*i];
    BSTToMinHeap(root->left, arr, i);
    BSTToMinHeap(root->right, arr, i);
}

void convertToMinHeapUtil(Node *root)
{
    vector<int> arr;
    int i = -1;
    inorderTraversal(root, arr);
    BSTToMinHeap(root, arr, &i);
}

void preorderTraversal(Node *root)
{
    if (!root)
        return;
    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

int main()
{
    struct Node *root = getNode(4);
    root->left = getNode(2);
    root->right = getNode(6);
    root->left->left = getNode(1);
    root->left->right = getNode(3);
    root->right->left = getNode(5);
    root->right->right = getNode(7);

    convertToMinHeapUtil(root);
    cout << "Preorder Traversal:" << endl;
    preorderTraversal(root);
    return 0;
}*/
/*// Convert min heap to max heap
#include <bits/stdc++.h>
using namespace std;
void MaxHeapify(int arr[], int i, int n)
{
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int largest = i;
    if (l < n && arr[l] > arr[i])
        largest = l;
    if (r < n && arr[r] > arr[i])
        largest = r;
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        MaxHeapify(arr, largest, n);
    }
}
void convertMaxHeap(int arr[],int n){
    for (int i = (n-2)/2; i >=0; --i)
    MaxHeapify(arr,i,n);
}
void printArray(int* arr,int size){
    for (int i = 0; i < size; i++)
        cout<<arr[i];
}
int main()
{
     int arr[] = {3, 5, 9, 6, 8, 20, 10, 12, 18, 9};
    int n = sizeof(arr)/sizeof(arr[0]);
 
    cout<<"Min Heap array : ";
    printArray(arr, n);
 
    convertMaxHeap(arr, n);
 
    cout<<"\nMax Heap array : ";
    printArray(arr, n);
    return 0;
}*/
/*// Rearrange characters in a string such that no two adjacent are same.
string 1198*/
/*// Minimum sum of two numbers formed from digits of an array
#include <bits/stdc++.h>
using namespace std;
int solve(int arr[], int n)
{
	sort(arr, arr + n);
	int a = 0, b = 0;
	for (int i = 0; i < n; i++)
	{
		if (i & 1)
			a = a*10 + arr[i];
		else
			b = b*10 + arr[i];
	}
	return a + b;
}
int main()
{
	int arr[] = {6, 8, 4, 5, 2, 3};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout << "Sum is " << solve(arr, n);
	return 0;
}*/
