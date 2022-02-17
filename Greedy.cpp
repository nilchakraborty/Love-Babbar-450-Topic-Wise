/*// Activity Selection Problem
#include <bits/stdc++.h>
using namespace std;
void printMaxActivities(int s[], int f[], int n)
{
    int i, j;
    cout << "Following activities are selected " << endl;
    i = 0;
    cout << " " << i;
    for (j = 1; j < n; j++)
    {
        if (s[j] >= f[i])
        {
            cout << " " << j;
            i = j;
        }
    }
}
int main()
{
    int s[] = {1, 3, 0, 5, 8, 5};
    int f[] = {2, 4, 6, 7, 9, 9};
    int n = sizeof(s) / sizeof(s[0]);
    printMaxActivities(s, f, n);
    return 0;
}*/
/*// Job SequencingProblem
#include <iostream>
#include <algorithm>
using namespace std;
struct Job
{
    char id;
    int dead;
    int profit;
};
bool comparison(Job a, Job b)
{
    return (a.profit > b.profit);
}
void printJobScheduling(Job arr[], int n)
{
    sort(arr, arr + n, comparison);

    int result[n];
    bool slot[n];
    for (int i = 0; i < n; i++)
        slot[i] = false;
    for (int i = 0; i < n; i++)
    {
        for (int j = min(n, arr[i].dead) - 1; j >= 0; j--)
        {
            if (slot[j] == false)
            {
                result[j] = i;
                slot[j] = true;
                break;
            }
        }
    }
    for (int i = 0; i < n; i++)
        if (slot[i])
            cout << arr[result[i]].id << " ";
}
int main()
{
    Job arr[] = {{'a', 2, 100}, {'b', 1, 19}, {'c', 2, 27}, {'d', 1, 25}, {'e', 3, 15}};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Following is maximum profit sequence of jobs \n";
    printJobScheduling(arr, n);
    return 0;
}*/
/*// Huffman Coding
#include <bits/stdc++.h>
using namespace std;
struct MinHeapNode
{
    char data;
    unsigned freq;
    MinHeapNode *left, *right;
    MinHeapNode(char data, unsigned freq)
    {
        left = right = NULL;
        this->data = data;
        this->freq = freq;
    }
};
struct compare
{
    bool operator()(MinHeapNode *l, MinHeapNode *r)
    {
        return (l->freq > r->freq);
    }
};
void printCodes(struct MinHeapNode *root, string str)
{
    if (!root)
        return;
    if (root->data != '$')
        cout << root->data << ": " << str << "\n";
    printCodes(root->left, str + "0");
    printCodes(root->right, str + "1");
}
void HuffmanCodes(char data[], int freq[], int size)
{
    struct MinHeapNode *left, *right, *top;
    priority_queue<MinHeapNode *, vector<MinHeapNode *>, compare> minHeap;
    for (int i = 0; i < size; ++i)
        minHeap.push(new MinHeapNode(data[i], freq[i]));
    while (minHeap.size() != 1)
    {
        left = minHeap.top();
        minHeap.pop();

        right = minHeap.top();
        minHeap.pop();

        top = new MinHeapNode('$', left->freq + right->freq);

        top->left = left;
        top->right = right;
        minHeap.push(top);
    }
    printCodes(minHeap.top(), "");
}
int main()
{
    char arr[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(arr) / sizeof(arr[0]);
    HuffmanCodes(arr, freq, size);
    return 0;
}*/
/*// Water Connection Problem
// C++ program to find efficient
// solution for the network
#include <bits/stdc++.h>
using namespace std;

// number of houses and number
// of pipes
int n, p;

// Array rd stores the
// ending vertex of pipe
int rd[1100];

// Array wd stores the value
// of diameters between two pipes
int wt[1100];

// Array cd stores the
// starting end of pipe
int cd[1100];

// Vector a, b, c are used
// to store the final output
vector<int> a;
vector<int> b;
vector<int> c;

int ans;

int dfs(int w)
{
	if (cd[w] == 0)
		return w;
	if (wt[w] < ans)
		ans = wt[w];
	return dfs(cd[w]);
}

// Function performing calculations.
void solve(int arr[][3])
{
	int i = 0;

	while (i < p) {
		
		int q = arr[i][0], h = arr[i][1],
			t = arr[i][2];
		
		cd[q] = h;
		wt[q] = t;
		rd[h] = q;
		i++;
	}
	
	a.clear();
	b.clear();
	c.clear();
	
	for (int j = 1; j <= n; ++j)
	
		//If a pipe has no ending vertex
		but has starting vertex i.e is
		an outgoing pipe then we need
		to start DFS with this vertex.
		if (rd[j] == 0 && cd[j]) {
			ans = 1000000000;
			int w = dfs(j);
			
			// We put the details of component
			// in final output array
			a.push_back(j);
			b.push_back(w);
			c.push_back(ans);
		}
		
	cout << a.size() << endl;
	for (int j = 0; j < a.size(); ++j)
		cout << a[j] << " " << b[j]
			<< " " << c[j] << endl;
}

// driver function
int main()
{
	n = 9, p = 6;

	memset(rd, 0, sizeof(rd));
	memset(cd, 0, sizeof(cd));
	memset(wt, 0, sizeof(wt));

	int arr[][3] = { { 7, 4, 98 },
					{ 5, 9, 72 },
					{ 4, 6, 10 },
					{ 2, 8, 22 },
					{ 9, 7, 17 },
					{ 3, 1, 66 } };

	solve(arr);
	return 0;
}*/
/*// Fractional Knapsack Problem
#include <bits/stdc++.h>
using namespace std;
struct Item
{
    int value, weight;
    Item(int value, int weight)
    {
        this->value = value;
        this->weight = weight;
    }
};
bool cmp(struct Item a, struct Item b)
{
    double r1 = (double)a.value / (double)a.weight;
    double r2 = (double)b.value / (double)b.weight;
    return r1 > r2;
}
double fractionalKnapsack(int W, struct Item arr[], int n)
{
    sort(arr, arr + n, cmp);
    int curWeight = 0;
    double finalValue = 0.0;
    for (int i = 0; i < n; i++)
    {
        if (curWeight + arr[i].weight <= W)
        {
            curWeight += arr[i].weight;
            finalValue += arr[i].value;
        }
        else
        {
            int remain = W - curWeight;
            finalValue += arr[i].value *
                          ((double)remain / (double)arr[i].weight);
            break;
        }
    }
    return finalValue;
}
int main()
{
    int W = 50;
    Item arr[] = {{60, 10}, {100, 20}, {120, 30}};

    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Maximum value we can obtain = "
         << fractionalKnapsack(W, arr, n);
    return 0;
}*/
/*// Greedy Algorithm to find Minimum number of Coins
#include <bits/stdc++.h>
using namespace std;
int rup[] = {1, 2, 5, 10, 20, 50, 100, 500, 1000, 2000};
int n = sizeof(rup) / sizeof(rup[0]);
void findMin(int V)
{
    sort(rup, rup + n);
    vector<int> ans;
    for (int i = n - 1; i >= 0; i--)
    {
        while (V >= rup[i])
        {
            V -= rup[i];
            ans.push_back(rup[i]);
        }
    }
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
}
int main()
{
    int n = 4621;
    cout << "Following is minimal number of change for " << n << ": ";
    findMin(n);
    return 0;
}*/
/*// Maximum trains for which stoppage can be provided
#include <bits/stdc++.h>
using namespace std;
#define n 2
#define m 5
int maxStop(int arr[][3])
{
    vector<pair<int, int>> vect[n + 1];
    for (int i = 0; i < m; i++)
        vect[arr[i][2]].push_back(
            make_pair(arr[i][1], arr[i][0]));
    for (int i = 0; i <= n; i++)
    {
        sort(vect[i].begin(), vect[i].end());
    }
    int count = 0;
    for (int i = 0; i <= n; i++)
    {
        if (vect[i].size() == 0)
            continue;
        int x = 0;
        count++;
        for (int j = 1; j < vect[i].size(); j++)
        {
            if (vect[i][j].second >=
                vect[i][x].first)
            {
                x = j;
                count++;
            }
        }
    }
    return count;
}
int main()
{
    int arr[m][3] = {1000, 1030, 1,
                     1010, 1020, 1,
                     1025, 1040, 1,
                     1130, 1145, 2,
                     1130, 1140, 2};
    cout << "Maximum Stopped Trains = "
         << maxStop(arr);
    return 0;
}*/
/*// Minimum Platforms Problem
#include <algorithm>
#include <iostream>
using namespace std;
int findPlatform(int arr[], int dep[], int n)
{
    int plat_needed = 1, result = 1;
    int i = 1, j = 0;
    for (int i = 0; i < n; i++)
    {
        plat_needed = 1;
        for (int j = i + 1; j < n; j++)
        {
            if ((arr[i] >= arr[j] && arr[i] <= dep[j]) ||
                (arr[j] >= arr[i] && arr[j] <= dep[i]))
                plat_needed++;
        }
        result = max(result, plat_needed);
    }
    return result;
}
int main()
{
    int arr[] = {900, 940, 950, 1100, 1500, 1800};
    int dep[] = {910, 1200, 1120, 1130, 1900, 2000};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Minimum Number of Platforms Required = "
         << findPlatform(arr, dep, n);
    return 0;
}*/
/*// Buy Maximum Stocks if i stocks can be bought on i-th day
#include <bits/stdc++.h>
using namespace std;
int buyMaximumProducts(int n, int k, int price[])
{
    vector<pair<int, int>> v;
    for (int i = 0; i < n; ++i)
        v.push_back(make_pair(price[i], i + 1));
    sort(v.begin(), v.end());
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        ans += min(v[i].second, k / v[i].first);
        k -= v[i].first * min(v[i].second,
                              (k / v[i].first));
    }
    return ans;
}
int main()
{
    int price[] = {10, 7, 19};
    int n = sizeof(price) / sizeof(price[0]);
    int k = 45;
    cout << buyMaximumProducts(n, k, price) << endl;
    return 0;
}*/
/*// Find the minimum and maximum amount to buy all N candies
#include <bits/stdc++.h>
using namespace std;
int findMinimum(int arr[], int n, int k)
{
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        res += arr[i];
        n = n - k;
    }
    return res;
}
int findMaximum(int arr[], int n, int k)
{
    int res = 0, index = 0;
    for (int i = n - 1; i >= index; i--)
    {
        res += arr[i];
        index += k;
    }
    return res;
}
int main()
{
    int arr[] = {3, 2, 1, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;
    sort(arr, arr + n);

    cout << findMinimum(arr, n, k) << " "
         << findMaximum(arr, n, k) << endl;
    return 0;
}*/
/*// Minimize Cash Flow among a given set of friends who have borrowed money from each other
#include <iostream>
using namespace std;
#define N 3
int getMin(int arr[])
{
    int minInd = 0;
    for (int i = 1; i < N; i++)
        if (arr[i] < arr[minInd])
            minInd = i;
    return minInd;
}
int getMax(int arr[])
{
    int maxInd = 0;
    for (int i = 1; i < N; i++)
        if (arr[i] > arr[maxInd])
            maxInd = i;
    return maxInd;
}
int minOf2(int x, int y)
{
    return (x < y) ? x : y;
}
void minCashFlowRec(int amount[])
{
    int mxCredit = getMax(amount), mxDebit = getMin(amount);
    if (amount[mxCredit] == 0 && amount[mxDebit] == 0)
        return;
    int min = minOf2(-amount[mxDebit], amount[mxCredit]);
    amount[mxCredit] -= min;
    amount[mxDebit] += min;
    cout << "Person " << mxDebit << " pays " << min
         << " to "
         << "Person " << mxCredit << endl;
    minCashFlowRec(amount);
}
void minCashFlow(int graph[][N])
{
    int amount[N] = {0};
    for (int p = 0; p < N; p++)
        for (int i = 0; i < N; i++)
            amount[p] += (graph[i][p] - graph[p][i]);
    minCashFlowRec(amount);
}
int main()
{
    int graph[N][N] = {
        {0, 1000, 2000},
        {0, 0, 5000},
        {0, 0, 0},
    };
    minCashFlow(graph);
    return 0;
}
*/
/*// Minimum Cost to cut a board into squares
#include <bits/stdc++.h>
using namespace std;
int minimumCostOfBreaking(int X[], int Y[], int m, int n)
{
    int res = 0;
    sort(X, X + m, greater<int>());
    sort(Y, Y + n, greater<int>());
    int hzntl = 1, vert = 1;
    int i = 0, j = 0;
    while (i < m && j < n)
    {
        if (X[i] > Y[j])
        {
            res += X[i] * vert;
            hzntl++;
            i++;
        }
        else
        {
            res += Y[j] * hzntl;
            vert++;
            j++;
        }
    }
    int total = 0;
    while (i < m)
        total += X[i++];
    res += total * vert;
    total = 0;
    while (j < n)
        total += Y[j++];
    res += total * hzntl;

    return res;
}
int main()
{
    int m = 6, n = 4;
    int X[m - 1] = {2, 1, 3, 1, 4};
    int Y[n - 1] = {4, 1, 2};
    cout << minimumCostOfBreaking(X, Y, m - 1, n - 1);
    return 0;
}*/
/*// Check if it is possible to survive on Island
#include <bits/stdc++.h>
using namespace std;
void survival(int S, int N, int M)
{
    if (((N * 6) < (M * 7) && S > 6) || M > N)
        cout << "No\n";
    else
    {
        int days = (M * S) / N;
        if (((M * S) % N) != 0)
            days++;
        cout << "Yes " << days << endl;
    }
}
int main()
{
    int S = 10, N = 16, M = 2;
    survival(S, N, M);
    return 0;
}*/
/*// Find maximum meetings in one room
#include <bits/stdc++.h>
using namespace std;
struct meeting
{
    int start;
    int end;
    int pos;
};
bool comparator(struct meeting m1, meeting m2)
{
    return (m1.end < m2.end);
}
void maxMeeting(int s[], int f[], int n)
{
    struct meeting meet[n];
    for (int i = 0; i < n; i++)
    {
        meet[i].start = s[i];
        meet[i].end = f[i];
        meet[i].pos = i + 1;
    }
    sort(meet, meet + n, comparator);
    vector<int> m;
    m.push_back(meet[0].pos);
    int time_limit = meet[0].end;
    for (int i = 1; i < n; i++)
    {
        if (meet[i].start >= time_limit)
        {
            m.push_back(meet[i].pos);
            time_limit = meet[i].end;
        }
    }
    for (int i = 0; i < m.size(); i++)
    {
        cout << m[i] << " ";
    }
}
int main()
{
    int s[] = {1, 3, 0, 5, 8, 5};
    int f[] = {2, 4, 6, 7, 9, 9};
    int n = sizeof(s) / sizeof(s[0]);
    maxMeeting(s, f, n);
    return 0;
}*/
/*// Maximum product subset of an array
#include <bits/stdc++.h>
using namespace std;
int maxProductSubset(int a[], int n)
{
    if (n == 1)
        return a[0];
    int max_neg = INT_MIN;
    int count_neg = 0, count_zero = 0;
    int prod = 1;
    for (int i = 0; i < n; i++)
    {
        if (!a[i])
        {
            count_zero++;
            continue;
        }

        if (a[i] < 0)
        {
            count_neg++;
            max_neg = max(max_neg, a[i]);
        }
        prod = prod * a[i];
    }
    if (count_zero == n)
        return 0;
    if (count_neg & 1)
    {
        if (count_neg == 1 && count_zero > 0 && count_neg + count_zero == n)
            return 0;
        prod = prod / max_neg;
    }
    return prod;
}
int main()
{
    int a[] = {-1, -1, -2, 4, 3};
    int n = sizeof(a) / sizeof(a[0]);
    cout << maxProductSubset(a, n);
    return 0;
}*/
/*// Maximize array sum after K negations
#include <bits/stdc++.h>
using namespace std;
int maximumSum(int arr[], int n, int k)
{
    for (int i = 1; i <= k; i++)
    {
        int min = INT_MAX;
        int index = -1;
        for (int j = 0; j < n; j++)
        {
            if (arr[j] < min)
            {
                min = arr[j];
                index = j;
            }
        }
        if (min == 0)
            break;
        arr[index] = -arr[index];
    }
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];
    return sum;
}
int main()
{
    int arr[] = {-2, 0, 5, -1, 2};
    int k = 4;
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << maximumSum(arr, n, k);
    return 0;
}*/
/*// Maximize the sum of arr[i]*i
#include <bits/stdc++.h>
using namespace std;
int maxSum(int arr[], int n)
{
    sort(arr, arr + n);
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += (arr[i] * i);
    return sum;
}
int main()
{
    int arr[] = {3, 5, 6, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << maxSum(arr, n) << endl;
    return 0;
}*/
/*// Maximum sum of absolute difference of an array
#include <bits/stdc++.h>
using namespace std;
int sumPairs(int arr[], int n)
{
    int sum = 0;
    for (int i = n - 1; i >= 0; i--)
        sum += i * arr[i] - (n - 1 - i) * arr[i];
    return sum;
}
int main()
{
    int arr[] = {1, 8, 9, 15, 16};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << sumPairs(arr, n);
    return 0;
}*/
/*// Maximize sum of consecutive differences in a circular array
#include <bits/stdc++.h>
using namespace std;
int maxSum(int arr[], int n)
{
    int sum = 0;
    sort(arr, arr + n);
    for (int i = 0; i < n / 2; i++)
    {
        sum -= (2 * arr[i]);
        sum += (2 * arr[n - 1 - i]);
    }
    return sum;
}
int main()
{
    int arr[] = {4, 2, 1, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << maxSum(arr, n) << endl;
    return 0;
}*/
/*// Minimum sum of absolute difference of pairs of two arrays
#include <bits/stdc++.h>
using namespace std;
int findMinSum(int a[], int b[], int n)
{
    sort(a, a + n);
    sort(b, b + n);
    long long int sum = 0;
    for (int i = 0; i < n; i++)
        sum = sum + abs(a[i] - b[i]);
    return sum;
}
int main()
{
    int a[] = {4, 1, 8, 7};
    int b[] = {2, 3, 6, 5};
    int n = sizeof(a) / sizeof(a[0]);
    cout<<findMinSum(a,b,n)<<endl;
    return 0;
}*/
/*// Program for Shortest Job First (or SJF) CPU Scheduling
#include <iostream>
using namespace std;
int mat[10][6];

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void arrangeArrival(int num, int mat[][6])
{
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num - i - 1; j++)
        {
            if (mat[j][1] > mat[j + 1][1])
            {
                for (int k = 0; k < 5; k++)
                {
                    swap(mat[j][k], mat[j + 1][k]);
                }
            }
        }
    }
}

void completionTime(int num, int mat[][6])
{
    int temp, val;
    mat[0][3] = mat[0][1] + mat[0][2];
    mat[0][5] = mat[0][3] - mat[0][1];
    mat[0][4] = mat[0][5] - mat[0][2];

    for (int i = 1; i < num; i++)
    {
        temp = mat[i - 1][3];
        int low = mat[i][2];
        for (int j = i; j < num; j++)
        {
            if (temp >= mat[j][1] && low >= mat[j][2])
            {
                low = mat[j][2];
                val = j;
            }
        }
        mat[val][3] = temp + mat[val][2];
        mat[val][5] = mat[val][3] - mat[val][1];
        mat[val][4] = mat[val][5] - mat[val][2];
        for (int k = 0; k < 6; k++)
        {
            swap(mat[val][k], mat[i][k]);
        }
    }
}

int main()
{
    int num, temp;

    cout << "Enter number of Process: ";
    cin >> num;

    cout << "...Enter the process ID...\n";
    for (int i = 0; i < num; i++)
    {
        cout << "...Process " << i + 1 << "...\n";
        cout << "Enter Process Id: ";
        cin >> mat[i][0];
        cout << "Enter Arrival Time: ";
        cin >> mat[i][1];
        cout << "Enter Burst Time: ";
        cin >> mat[i][2];
    }

    cout << "Before Arrange...\n";
    cout << "Process ID\tArrival Time\tBurst Time\n";
    for (int i = 0; i < num; i++)
    {
        cout << mat[i][0] << "\t\t" << mat[i][1] << "\t\t" << mat[i][2] << "\n";
    }

    arrangeArrival(num, mat);
    completionTime(num, mat);
    cout << "Final Result...\n";
    cout << "Process ID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n";
    for (int i = 0; i < num; i++)
    {
        cout << mat[i][0] << "\t\t" << mat[i][1] << "\t\t" << mat[i][2] << "\t\t" << mat[i][4] << "\t\t" << mat[i][5] << "\n";
    }
}*/
/*// Program for Least Recently Used (LRU) Page Replacement algorithm
#include <bits/stdc++.h>
using namespace std;
int pageFaults(int pages[], int n, int capacity)
{
    unordered_set<int> s;
    unordered_map<int, int> indexes;
    int page_faults = 0;
    for (int i = 0; i < n; i++)
    {
        if (s.size() < capacity)
        {
            if (s.find(pages[i]) == s.end())
            {
                s.insert(pages[i]);
                page_faults++;
            }
            indexes[pages[i]] = i;
        }
        else
        {
            if (s.find(pages[i]) == s.end())
            {
                int lru = INT_MAX, val;
                for (auto it = s.begin(); it != s.end(); it++)
                {
                    if (indexes[*it] < lru)
                    {
                        lru = indexes[*it];
                        val = *it;
                    }
                }
                s.erase(val);
                s.insert(pages[i]);
                page_faults++;
            }
            indexes[pages[i]] = i;
        }
    }
    return page_faults;
}
int main()
{
    int pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2};
    int n = sizeof(pages) / sizeof(pages[0]);
    int capacity = 4;
    cout << pageFaults(pages, n, capacity);
    return 0;
}*/
/*// Smallest subset with sum greater than all other elements
#include <bits/stdc++.h>
using namespace std;
int minElements(int arr[], int n)
{
    int halfSum = 0;
    for (int i = 0; i < n; i++)
        halfSum = halfSum + arr[i];
    halfSum = halfSum / 2;
    sort(arr, arr + n, greater<int>());
    int res = 0, curr_sum = 0;
    for (int i = 0; i < n; i++)
    {
        curr_sum += arr[i];
        res++;
        if (curr_sum > halfSum)
            return res++;
    }
    return res;
}
int main()
{
    int arr[] = {3, 1, 7, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << minElements(arr, n) << endl;
    return 0;
}*/
/*// Chocolate Distribution Problem
#include <bits/stdc++.h>
using namespace std;
int findMinDiff(int arr[], int n, int m)
{
    if (m == 0 || n == 0)
        return 0;
    sort(arr, arr + n);
    if (n < m)
        return -1;
    int min_diff = INT_MAX;
    for (int i = 0; i + m - 1 < n; i++)
    {
        int diff = arr[i + m - 1] - arr[i];
        if (diff < min_diff)
            min_diff = diff;
    }
    return min_diff;
}
int main()
{
    int arr[] = {12, 4, 7, 9, 2, 23, 25, 41, 30,
                 40, 28, 42, 30, 44, 48, 43, 50};
    int m = 7; // Number of students
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Minimum difference is "
         << findMinDiff(arr, n, m);
    return 0;
}*/
// DEFKIN -Defense of a Kingdom
// DIEHARD -DIE HARD
// GERGOVIA -Wine trading in Gergovia
// Picking Up Chicks
// CHOCOLA –Chocolate
// ARRANGE -Arranging Amplifiers
/*// K Centers Problem
#include <bits/stdc++.h>
using namespace std;

int maxindex(int *dist, int n)
{
    int mi = 0;
    for (int i = 0; i < n; i++)
    {
        if (dist[i] > dist[mi])
            mi = i;
    }
    return mi;
}
void selectKcities(int n, int weights[4][4], int k)
{
    int *dist = new int[n];
    vector<int> centers;
    for (int i = 0; i < n; i++)
    {
        dist[i] = INT_MAX;
    }
    int max = 0;
    for (int i = 0; i < k; i++)
    {
        centers.push_back(max);
        for (int j = 0; j < n; j++)
        {
            dist[j] = min(dist[j], weights[max][j]);
        }
        max = maxindex(dist, n);
    }
    cout << endl
         << dist[max] << endl;
    for (int i = 0; i < centers.size(); i++)
    {
        cout << centers[i] << " ";
    }
    cout << endl;
}
int main()
{
    int n = 4;
    int weights[4][4] = {{0, 4, 8, 5},
                         {4, 0, 10, 7},
                         {8, 10, 0, 9},
                         {5, 7, 9, 0}};
    int k = 2;
    selectKcities(n, weights, k);
}*/
/*// Minimum Cost of ropes
#include <bits/stdc++.h>
using namespace std;
int minCost(int arr[], int n)
{
    priority_queue<int, vector<int>, greater<int>> 
    pq(arr, arr + n);
    int res = 0;
    while (pq.size() > 1)
    {
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();
        res += first + second;
        pq.push(first + second);
    }
    return res;
}
int main()
{
    int len[] = {4, 3, 2, 6};
    int size = sizeof(len) / sizeof(len[0]);
    cout << "Total cost for connecting ropes is " 
    << minCost(len, size);
    return 0;
}*/
/*// Find smallest number with given number of digits and sum of digits
#include <iostream>
using namespace std;
void findSmallest(int m, int s)
{
    if (s == 0)
    {
        (m == 1) ? cout << "Smallest number is " << 0
                 : cout << "Not possible";
        return;
    }
    if (s > 9 * m)
    {
        cout << "Not possible";
        return;
    }
    int res[m];
    s -= 1;
    for (int i = m - 1; i > 0; i--)
    {
        if (s > 9)
        {
            res[i] = 9;
            s -= 9;
        }
        else
        {
            res[i] = s;
            s = 0;
        }
    }
    res[0] = s + 1;
    cout << "Smallest number is ";
    for (int i = 0; i < m; i++)
        cout << res[i];
}
int main()
{
    int s = 20, m = 3;
    findSmallest(m, s);
    return 0;
}*/
/*// Rearrange characters in a string such that no two adjacent are same
same as string 1198*/
/*// Find maximum sum possible equal sum of three stacks
#include <bits/stdc++.h>
using namespace std;
int maxSum(int stack1[], int stack2[], int stack3[], int n1,
           int n2, int n3)
{
    int sum1 = 0, sum2 = 0, sum3 = 0;
    for (int i = 0; i < n1; i++)
        sum1 += stack1[i];
    for (int i = 0; i < n2; i++)
        sum2 += stack2[i];
    for (int i = 0; i < n3; i++)
        sum3 += stack3[i];

    int top1 = 0, top2 = 0, top3 = 0;
    while (1)
    {
        if (top1 == n1 || top2 == n2 || top3 == n3)
            return 0;
        if (sum1 == sum2 && sum2 == sum3)
            return sum1;
        if (sum1 >= sum2 && sum1 >= sum3)
            sum1 -= stack1[top1++];
        else if (sum2 >= sum1 && sum2 >= sum3)
            sum2 -= stack2[top2++];
        else if (sum3 >= sum2 && sum3 >= sum1)
            sum3 -= stack3[top3++];
    }
}
int main()
{
    int stack1[] = {3, 2, 1, 1, 1};
    int stack2[] = {4, 3, 2};
    int stack3[] = {1, 1, 4, 1};

    int n1 = sizeof(stack1) / sizeof(stack1[0]);
    int n2 = sizeof(stack2) / sizeof(stack2[0]);
    int n3 = sizeof(stack3) / sizeof(stack3[0]);

    cout << maxSum(stack1, stack2, stack3, n1, n2, n3)
         << endl;
    return 0;
}*/
