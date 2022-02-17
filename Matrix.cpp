/*//Spiral traversal on a Matrix
#include <bits/stdc++.h>
using namespace std;
vector<int> spiralOrder(const vector<vector<int>> &A)
{

    int T, B, L, R, dir;
    T = 0;
    B = A.size() - 1;
    L = 0;
    R = A[0].size() - 1;
    dir = 0;
    int i;
    vector<int> ans;

    while (T <= B && L <= R)
    {
        if (dir == 0)
        {
            for (i = L; i <= R; i++)
                ans.push_back(A[T][i]);
            T++;
        }
        else if (dir == 1)
        {
            for (i = T; i <= B; i++)
                ans.push_back(A[i][R]);
            R--;
        }
        else if (dir == 2)
        {
            for (i = R; i >= L; i--)
                ans.push_back(A[B][i]);
            B--;
        }
        else if (dir == 3)
        {
            for (i = B; i >= T; i--)
                ans.push_back(A[i][L]);
            L++;
        }
        dir = (dir + 1) % 4;
    }
    return ans;
}
int main()
{
    vector<vector<int>> a{{1, 2, 3, 4},
                          {5, 6, 7, 8},
                          {9, 10, 11, 12},
                          {13, 14, 15, 16}};

    for (int x : spiralOrder(a))
    {
        cout << x << " ";
    }
    return 0;
}*/
/*//Search an element in a matrix
#include <bits/stdc++.h>
using namespace std;
#define MAX 100
bool search(int mat[][MAX], int m, int n, int x)
{
    int i = m - 1, j = 0;
    while (i >= 0 && j < n)
    {
        if (mat[i][j] == x)
            return true;
        if (mat[i][j] > x)
            i--;
        else
            j++;
    }
    return false;
}
int main()
{
    int mat[][MAX] = {
        {10, 20, 30, 40},
        {15, 25, 35, 45},
        {27, 29, 37, 48},
        {32, 33, 39, 50},
        {50, 60, 70, 80},
    };
    if (search(mat, 5, 4, 29))
        cout << "Yes";
    else
        cout << "No";
    return 0;
}*/
/*//Find median in a row wise sorted matrix
#include <bits/stdc++.h>
using namespace std;
const int MAX = 100;
int binaryMedian(int m[][MAX], int r, int c)
{
    int min = INT_MAX, max = INT_MIN;
    for (int i = 0; i < r; i++)
    {
        if (m[i][0] < min)
            min = m[i][0];
        if (m[i][c - 1] > max)
            max = m[i][c - 1];
    }
    int desired = (r * c + 1) / 2;
    while (min < max)
    {
        int mid = min + (max - min) / 2;
        int place = 0;
        for (int i = 0; i < r; ++i)
            place += upper_bound(m[i], m[i] + c, mid) - m[i];
        if (place < desired)
            min = mid + 1;
        else
            max = mid;
    }
    return min;
}
int main()
{
    int r = 3, c = 3;
    int m[][MAX] = {{1, 3, 5}, {2, 6, 9}, {3, 6, 9}};
    cout << "Median is " << binaryMedian(m, r, c) << endl;
    return 0;
}*/
/*//Find row with maximum no. of 1's
#include <bits/stdc++.h>
using namespace std;
#define R 4
#define C 4
int rowWithMax1s(bool mat[R][C])
{
    int j, max_row_index = 0;
    j = C - 1;

    for (int i = 0; i < R; i++)
    {
        bool flag = false;
        while (j >= 0 && mat[i][j] == 1)
        {
            j = j - 1;
            flag = true;
        }
        if (flag)
        {
            max_row_index = i;
        }
    }
    if (max_row_index == 0 && mat[0][C - 1] == 0)
        return -1;
    return max_row_index;
}
int main()
{
    bool mat[R][C] = {{0, 0, 0, 1},
                      {0, 1, 1, 1},
                      {1, 1, 1, 1},
                      {0, 0, 0, 0}};

    cout << "Index of row with maximum 1s is " << rowWithMax1s(mat);
    return 0;
}*/
/*//Print elements in sorted order using row-column wise sorted matrix
#include <iostream>
#include <climits>
using namespace std;
#define INF INT_MAX
#define N 4

void youngify(int mat[][N], int i, int j)
{
    int downval = (i + 1 < N) ? mat[i + 1][j] : INF;
    int rightval = (j + 1 < N) ? mat[i][j + 1] : INF;
    if (downval == INF && rightval == INF)
        return;
    if (downval < rightval)
    {
        mat[i][j] = downval;
        mat[i + 1][j] = INF;
        youngify(mat, i + 1, j);
    }
    else
    {
        mat[i][j] = rightval;
        mat[i][j + 1] = INF;
        youngify(mat, i, j + 1);
    }
}
int extractMin(int mat[][N])
{
    int rat = mat[0][0];
    mat[0][0] = INF;
    youngify(mat, 0, 0);
    return rat;
}
void printSorted(int mat[][N])
{
    cout << "Elements of matrix in sorted order: ";
    for (int i = 0; i < N * N; i++)
        cout << extractMin(mat) << " ";
}
int main()
{
    int mat[N][N] = {
        {10, 20, 30, 40},
        {15, 25, 35, 45},
        {27, 29, 37, 48},
        {32, 33, 39, 50},
    };
    printSorted(mat);
    return 0;
}*/
/*//Maximum size rectangle
// C++ program to find largest
// rectangle with all 1s
// in a binary matrix
#include <bits/stdc++.h>
using namespace std;

// Rows and columns in input matrix
#define R 4
#define C 4

// Finds the maximum area under
// the histogram represented
// by histogram. See below article for details.


int maxHist(int row[])
{
	// Create an empty stack.
	// The stack holds indexes of
	// hist[] array/ The bars stored
	// in stack are always
	// in increasing order of their heights.
	stack<int> result;

	int top_val; // Top of stack

	int max_area = 0; // Initialize max area in current
	// row (or histogram)

	int area = 0; // Initialize area with current top

	// Run through all bars of given histogram (or row)
	int i = 0;
	while (i < C) {
		// If this bar is higher than the bar on top stack,
		// push it to stack
		if (result.empty() || row[result.top()] <= row[i])
			result.push(i++);

		else {
			// If this bar is lower than top of stack, then
			// calculate area of rectangle with stack top as
			// the smallest (or minimum height) bar. 'i' is
			// 'right index' for the top and element before
			// top in stack is 'left index'
			top_val = row[result.top()];
			result.pop();
			area = top_val * i;

			if (!result.empty())
				area = top_val * (i - result.top() - 1);
			max_area = max(area, max_area);
		}
	}

	// Now pop the remaining bars from stack and calculate
	// area with every popped bar as the smallest bar
	while (!result.empty()) {
		top_val = row[result.top()];
		result.pop();
		area = top_val * i;
		if (!result.empty())
			area = top_val * (i - result.top() - 1);

		max_area = max(area, max_area);
	}
	return max_area;
}

// Returns area of the largest rectangle with all 1s in
// A[][]
int maxRectangle(int A[][C])
{
	// Calculate area for first row and initialize it as
	// result
	int result = maxHist(A[0]);

	// iterate over row to find maximum rectangular area
	// considering each row as histogram
	for (int i = 1; i < R; i++) {

		for (int j = 0; j < C; j++)

			// if A[i][j] is 1 then add A[i -1][j]
			if (A[i][j])
				A[i][j] += A[i - 1][j];

		// Update result if area with current row (as last
		// row) of rectangle) is more
		result = max(result, maxHist(A[i]));
	}

	return result;
}

// Driver code
int main()
{
	int A[][C] = {
		{ 0, 1, 1, 0 },
		{ 1, 1, 1, 1 },
		{ 1, 1, 1, 1 },
		{ 1, 1, 0, 0 },
	};

	cout << "Area of maximum rectangle is "
		<< maxRectangle(A);

	return 0;
}
*/
/*//Find a specific pair in Matrix
#include <bits/stdc++.h>
using namespace std;
#define N 5
int findMaxValue(int mat[][N])
{
    int maxvalue = INT_MIN;
    for (int a = 0; a < N - 1; a++)
        for (int b = 0; b < N - 1; b++)
            for (int d = a + 1; d < N; d++)
                for (int e = b + 1; e < N; e++)
                    if (maxvalue < (mat[d][e] - mat[a][b]))
                        maxvalue = mat[d][e] - mat[a][b];
    return maxvalue;
}

int main()
{
    int mat[N][N] = {
        {1, 2, -1, -4, -20},
        {-8, -3, 4, 2, 1},
        {3, 8, 6, 1, 3},
        {-4, -1, 1, 7, -6},
        {0, -4, 10, -5, 1}};
    cout << "Maximum Value is "
         << findMaxValue(mat);

    return 0;
}*/
/*//Rotate matrix by 90 degrees
#include <bits/stdc++.h>
using namespace std;
#define N 4

void rotate90Clockwise(int a[N][N])
{
    for (int i = 0; i < N / 2; i++)
    {
        for (int j = i; j < N - i - 1; j++)
        {
            int temp = a[i][j];
            a[i][j] = a[N - 1 - j][i];
            a[N - 1 - j][i] = a[N - 1 - i][N - 1 - j];
            a[N - 1 - i][N - 1 - j] = a[j][N - 1 - i];
            a[j][N - 1 - i] = temp;
        }
    }
}
void printMatrix(int arr[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << arr[i][j] << " ";
        cout << '\n';
    }
}

int main()
{
    int arr[N][N] = {{1, 2, 3, 4},
                     {5, 6, 7, 8},
                     {9, 10, 11, 12},
                     {13, 14, 15, 16}};
    rotate90Clockwise(arr);
    printMatrix(arr);
    return 0;
}*/
/*//Kth smallest element in a row-cpumn wise sorted matrix
// kth largest element in a 2d array sorted row-wise and
// column-wise
#include <bits/stdc++.h>
using namespace std;

// A structure to store entry of heap. The entry contains
// value from 2D array, row and column numbers of the value
struct HeapNode {
	int val; // value to be stored
	int r; // Row number of value in 2D array
	int c; // Column number of value in 2D array
};

// A utility function to minheapify the node harr[i] of a
// heap stored in harr[]
void minHeapify(HeapNode harr[], int i, int heap_size)
{
	int l = i * 2 + 1;
	int r = i * 2 + 2;
	if(l < heap_size&& r<heap_size && harr[l].val < harr[i].val && harr[r].val < harr[i].val){
			HeapNode temp=harr[r];
			harr[r]=harr[i];
			harr[i]=harr[l];
			harr[l]=temp;
			minHeapify(harr ,l,heap_size);
			minHeapify(harr ,r,heap_size);
		}
		if (l < heap_size && harr[l].val < harr[i].val){
			HeapNode temp=harr[i];		
			harr[i]=harr[l];
			harr[l]=temp;
			minHeapify(harr ,l,heap_size);
		}
}

// This function returns kth
// smallest element in a 2D array
// mat[][]
int kthSmallest(int mat[4][4], int n, int k)
{
	// k must be greater than 0 and smaller than n*n
	if (k < 0 && k >= n * n)
		return INT_MAX;

	// Create a min heap of elements from first row of 2D
	// array
	HeapNode harr[n];
	for (int i = 0; i < n; i++)
		harr[i] = { mat[0][i], 0, i };

	HeapNode hr;
	for (int i = 0; i < k; i++) {
		// Get current heap root
		hr = harr[0];

		// Get next value from column of root's value. If
		// the value stored at root was last value in its
		// column, then assign INFINITE as next value
		int nextval = (hr.r < (n - 1)) ? mat[hr.r + 1][hr.c]: INT_MAX;

		// Update heap root with next value
		harr[0] = { nextval, (hr.r) + 1, hr.c };

		// Heapify root
		minHeapify(harr, 0, n);
	}

	// Return the value at last extracted root
	return hr.val;
}

// driver program to test above function
int main()
{
	int mat[4][4] = {
		{ 10, 20, 30, 40 },
		{ 15, 25, 35, 45 },
		{ 25, 29, 37, 48 },
		{ 32, 33, 39, 50 },
	};
	cout << "7th smallest element is "
		<< kthSmallest(mat, 4, 7);
	return 0;
}

// this code is contributed by Rishabh Chauhan
*/
/*//Common elements in all rows of a given matrix
#include <bits/stdc++.h>
using namespace std;

#define M 4
#define N 5
void printCommonElements(int mat[M][N])
{
    unordered_map<int, int> mp;
    for (int j = 0; j < N; j++)
        mp[mat[0][j]] = 1;
    for (int i = 1; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (mp[mat[i][j]] == i)
            {
                mp[mat[i][j]] = i + 1;

                if (i == M - 1 && mp[mat[i][j]] == M)
                    cout << mat[i][j] << " ";
            }
        }
    }
}
int main()
{
    int mat[M][N] =
        {
            {1, 2, 1, 4, 8},
            {3, 7, 8, 5, 1},
            {8, 7, 7, 3, 1},
            {8, 1, 2, 7, 9},
        };

    printCommonElements(mat);

    return 0;
}*/
