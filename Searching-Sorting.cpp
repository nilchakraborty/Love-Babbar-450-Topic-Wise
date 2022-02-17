/*//Find first and last positions of an element in a sorted array   
#include <bits/stdc++.h>
using namespace std;
void firstAndlast(int arr[], int n, int x)
{
    int first, last;
    first = lower_bound(arr, arr + n, x) - arr;
    last = upper_bound(arr, arr + n, x) - arr - 1;
    if (first == n)
    {
        first = -1;
        last = -1;
    }
    cout << "First Occurence= " << first << "\nLast Occurence= " << last;
}

int main()
{
    int arr[] = {1, 2, 2, 2, 2, 3, 4, 7, 8, 8};
    int n = 10;
    int x = 2;
    firstAndlast(arr, n, x);
    return 0;
}*/
/*//Find a Fixed Point (Value equal to index) in a given array
#include <bits/stdc++.h>
using namespace std;
int linearSearch(int arr[], int n)
{
    int i;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == i)
            return i;
    }
    return -1;
}

int main()
{
    int arr[] = {-10, -1, 0, 3, 10, 11, 30, 50, 100};
    int n = 9;
    cout << "Fixed point is " << linearSearch(arr, n);
    return 0;
}*/
/*//Search an element in a sorted and rotated array
#include <bits/stdc++.h>
using namespace std;

int search(int arr[], int l, int h, int k)
{
    if (l > h)
        return -1;
    int mid = (l + h) / 2;
    if (arr[mid] == k)
        return mid;
    if (arr[l] <= arr[mid])
    {
        if (k >= arr[l] && k <= arr[mid])
            return search(arr, l, mid - 1, k);
        return search(arr, mid + 1, h, k);
    }
    if (k >= arr[mid] && k <= arr[h])
        return search(arr, mid + 1, h, k);
    return search(arr, l, mid - 1, k);
}

int main()
{
    int arr[] = {4, 5, 6, 7, 8, 9, 1, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 6;
    int i = search(arr, 0, n - 1, k);
    if (i != -1)
        cout << "Index: " << i << endl;
    else
        cout << "Key not found";
    return 0;
}*/
/*//square root of an integer
#include <bits/stdc++.h>
using namespace std;
int floorsqrt(int x){
    if(x==0||x==1)
    return x;
    int i=1,result=1;
    while(result<=x){
        i++;
        result=i*i;
    }
    return i-1;
}

int main() {
    int x=11;
    cout<<floorsqrt(x)<<endl;
    return 0;
}*/
/*//Maximum and minimum of an array using minimum number of comparisons
#include <iostream>
using namespace std;
struct Pair
{
    int min;
    int max;
};
struct Pair getMinMax(int arr[], int n)
{
    struct Pair minmax;
    int i;
    if (n == 1)
    {
        minmax.min = arr[0];
        minmax.max = arr[0];
        return minmax;
    };
    if (arr[0] > arr[1])
    {
        minmax.min = arr[1];
        minmax.max = arr[0];
    }
    else
    {
        minmax.min = arr[0];
        minmax.max = arr[1];
    }
    for (i = 2; i < n; i++)
    {
        if (arr[i] > minmax.max)
            minmax.max = arr[i];
        else if (arr[i] < minmax.min)
            minmax.min = arr[i];
    }
    return minmax;
}
int main()
{
    int arr[] = {1000, 11, 445, 1, 330, 3000};
    int arr_size = 6;
    struct Pair minmax = getMinMax(arr, arr_size);
    cout << "Minimum element is " << minmax.min << endl;
    cout << "Maximum element is " << minmax.max;
    return 0;
}*/
/*//Optimum location of point to minimize total distance
#include <bits/stdc++.h>
using namespace std;
#define sq(x) ((x)*(x))
#define EPS 1e-6
#define N 5
struct point
{
    int x, y;
    point() {}
    point(int x, int y) : x(x), y(y) {}
};
struct line
{
    int a, b, c;
    line(int a, int b, int c) : a(a), b(b), c(c) {}
};
double dist(double x, double y, point p) 
{ 
    return sqrt(sq(x - p.x) + sq(y - p.y)); 
} 
double compute(point p[], int n, line l, double X)
{
    double res = 0;
      double Y = -1 * (l.c + l.a*X) / l.b; 
    for (int i = 0; i < n; i++)
        res += dist(X, Y, p[i]);
    return res;
}
double findOptimumCosUtil(point p[], int n, line l)
{
    double low = -1e6;
    double high = 1e6;
    while ((high - low) > EPS)
    {
        double mid1 = low + (high - low) / 3;
        double mid2 = high - (high - low) / 3;
        double dist1 = compute(p, n, l, mid1);
        double dist2 = compute(p, n, l, mid2);
        if (dist1 < dist2)
            high = mid2;
        else
            low = mid1;
    }
    return compute(p, n, l, (low + high) / 2);
}
double findOptimumCost(int points[N][2], line l)
{
    point p[N];
    for (int i = 0; i < N; i++)
        p[i] = point(points[i][0], points[i][1]);
    return findOptimumCosUtil(p, N, l);
}
int main()
{
    line l(1, -1, -3);
    int points[N][2] = {{-3, -2}, {-1, 0}, {-1, 2}, {1, 2}, {3, 4}};
    cout << findOptimumCost(points, l) << endl;
    return 0;
}*/
/*//Find the repeating and the missing
#include <iostream>
using namespace std;
void printTwoElement(int arr[], int n)
{
    int i;
    cout << "Repeating element is ";
    for (int i = 0; i < n; i++)
    {
        if (arr[abs(arr[i]) - 1] >= 0)
            arr[abs(arr[i]) - 1] = -arr[abs(arr[i]) - 1];
        else
            cout << abs(arr[i]) << "\n";
    }
    cout << "and the missisng element is ";
    for (i = 0; i < n; i++)
    {
        if (arr[i] > 0)
            cout << (i + 1);
    }
}
int main()
{
    int arr[] = { 7, 3, 4, 5, 5, 6, 2};
    int n =7;
    printTwoElement(arr, n);
    return 0;
}*/
/*//find majority element
#include <bits/stdc++.h>
using namespace std;
void findMajority(int arr[], int n)
{
    int maxCount = 0;
    int index = -1;
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[i] == arr[j])
                count++;
        }
        if (count > maxCount)
        {
            maxCount = count;
            index = i;
        }
    }
    if (maxCount > n / 2)
        cout << arr[index] << endl;
    else
        cout << "No Majority Element" << endl;
}

int main()
{
    int arr[] = {1, 1, 2, 1, 3, 5, 1};
    int n = 7;
    findMajority(arr, n);
    return 0;
}*/
/*//Searching in an array where adjacent differ by at most k
#include <bits/stdc++.h>
using namespace std;
int search(int arr[], int n, int x, int k)
{
    int i = 0;
    while (i < n)
    {
        if (arr[i] == x)
            return i;
        i = i + max(1, abs(arr[i] - x) / k);
    }
    cout << "number is not present! ";
    return -1;
}

int main()
{
    int arr[] = {2, 4, 5, 7, 7, 6};
    int x = 6;
    int k = 2;
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Element " << x << " is present at index "
         << search(arr, n, x, k);
    return 0;
}*/
/*//find a pair with a given difference
#include <bits/stdc++.h>
using namespace std;
bool findPair(int arr[], int n, int k)
{
    int i = 0;
    int j = 0;
    while (i < n && j < n)
    {
        if (i != j && arr[j] - arr[i] == k)
        {
            cout << "Pair found: (" << arr[i] << ", " << arr[j] << ")";
            return true;
        }
        else if (arr[j] - arr[i] < n)
            j++;
        else
            i++;
    }
    cout << " No such pair";
    return false;
}

int main()
{
    int arr[] = {1, 8, 30, 40, 100};
    int n = 5;
    int k = 60;
    findPair(arr, n, k);
    return 0;
}*/
/*//find four elements that sum to a given value
#include <bits/stdc++.h>
using namespace std;
void findFourElements(int arr[], int n, int X)
{
    unordered_map<int, pair<int, int>> mp;
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            mp[arr[i] + arr[j]] = {i, j};
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int sum = arr[i] + arr[j];
            if (mp.find(X - sum) != mp.end())
            {
                pair<int, int> p = mp[X - sum];
                if (p.first != i && p.first != j &&
                    p.second != i && p.second != j)
                {
                    cout << arr[i] << ", " << arr[j] << ", "
                         << arr[p.first] << ", " << arr[p.second];
                    return;
                }
            }
        }
    }
}

int main()
{
    int arr[] = {10, 20, 30, 40, 1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int X = 91;
    findFourElements(arr, n, X);
    return 0;
}*/
/*//maximum sum such that no 2 elements are adjacent
#include <bits/stdc++.h>
#define maxLen 10
using namespace std;
int dp[maxLen];
bool v[maxLen];
int maxSum(int arr[], int i, int n)
{
    if (i >= n)
        return 0;
    if (v[i])
        return dp[i];
    v[i] = 1;
    dp[i] = max(maxSum(arr, i + 1, n), arr[i] + maxSum(arr, i + 2, n));
    return dp[i];
}
int main()
{
    int arr[] = {12, 9, 7, 33};
    int n = sizeof(arr) / sizeof(int);
    cout << maxSum(arr, 0, n);
    return 0;
}*/
/*//Count triplet with sum smaller than a given value
#include <bits/stdc++.h>
using namespace std;
int countTriplets(int arr[], int n, int sum)
{
    int ans = 0;
    for (int i = 0; i < n - 2; i++)
    {
        for (int j = i+1; j < n - 1; j++)
        {
            for (int k = j+1; k < n; k++)
                if (arr[i] + arr[j] + arr[k] < sum)
                    ans++;
        }
    }
    return ans;
}

int main()
{
    int arr[] = {5, 1, 3, 4, 7};
    int n = 5;
    int sum = 12;
    cout << countTriplets(arr, n, sum) << endl;
    return 0;
}*/
/*//merge 2 sorted arrays
#include <bits/stdc++.h>
using namespace std;
void mergeArray(int arr1[], int arr2[], int n1, int n2, int arr3[])
{
    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2)
    {
        if (arr1[i] < arr2[j])
            arr3[k++] = arr1[i++];
        else
            arr3[k++] = arr2[j++];
    }
    while (i < n1)
        arr3[k++] = arr1[i++];
    while (j < n2)
        arr3[k++] = arr2[j++];
}

int main()
{
    int arr1[] = {1, 3, 5, 7};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);

    int arr2[] = {2, 4, 6, 8};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    int arr3[n1 + n2];
    mergeArray(arr1, arr2, n1, n2, arr3);
    cout << "Array after merging" << endl;
    for (int i = 0; i < n1 + n2; i++)
        cout << arr3[i] << " ";

    return 0;
}*/
/*//print all subarrays with 0 sum
#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> findSubArrays(int arr[], int n)
{
    unordered_map<int, vector<int>> map;

    vector<pair<int, int>> out;
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum == 0)
            out.push_back(make_pair(0, i));

        if (map.find(sum) != map.end())
        {
            vector<int> vc = map[sum];
            for (auto it = vc.begin(); it != vc.end(); it++)
                out.push_back(make_pair(*it + 1, i));
        }
        map[sum].push_back(i);
    }
    return out;
}
void print(vector<pair<int, int>> out)
{
    for (auto it = out.begin(); it != out.end(); it++)
        cout << "Subarray found from Index " << it->first << " to " << it->second << endl;
}
int main()
{
    int arr[] = {6, 3, -1, -3, 4, -2, 2, 4, 6, -12, -7};
    int n = sizeof(arr) / sizeof(arr[0]);

    vector<pair<int, int>> out = findSubArrays(arr, n);
    if (out.size() == 0)
        cout << "No subarray exists";
    else
        print(out);

    return 0;
}*/
/*//Product array Puzzle
#include <iostream>
using namespace std;
long *productExceptSelf(int a[], int n)
{
    long prod = 1;
    long flag = 0;

    for (int i = 0; i < n; i++)
    {

        if (a[i] == 0)
            flag++;
        else
            prod *= a[i];
    }

    long *arr = new long[n];

    for (int i = 0; i < n; i++)
    {
        if (flag > 1)
        {
            arr[i] = 0;
        }
        else if (flag == 0)
            arr[i] = (prod / a[i]);
        else if (flag == 1 && a[i] != 0)
        {
            arr[i] = 0;
        }
        else
            arr[i] = prod;
    }
    return arr;
}
int main()
{
    int n = 5;
    int array[] = {10, 3, 5, 6, 2};

    long *ans;
    ans = productExceptSelf(array, n);

    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}*/
/*//Sort array according to count of set bits
#include <bits/stdc++.h>
using namespace std;
int countBits(int a)
{
    int count = 0;
    while (a)
    {
        if (a & 1)
            count += 1;
        a = a >> 1;
    }
    return count;
}
void insertionSort(int arr[], int aux[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int key1 = aux[i];
        int key2 = arr[i];
        int j = i - 1;
        while (j >= 0 && aux[j] < key1)
        {
            aux[j + 1] = aux[j];
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        aux[j + 1] = key1;
        arr[j + 1] = key2;
    }
}
void sortBySetBitCount(int arr[], int n)
{
    int aux[n];
    for (int i = 0; i < n; i++)
        aux[i] = countBits(arr[i]);
    insertionSort(arr, aux, n);
}
void printArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    sortBySetBitCount(arr, n);
    printArr(arr, n);
    return 0;
}*/
/*//minimum no. of swaps required to sort the array
#include <bits/stdc++.h>
using namespace std;
void swap(vector<int> &arr, int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
int indexOf(vector<int> &arr, int ele)
{
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == ele)
        {
            return i;
        }
    }
    return -1;
}
int minSwap(vector<int> arr, int N)
{
    int ans = 0;
    vector<int> temp(arr.begin(), arr.end());
    sort(temp.begin(), temp.end());
    for (int i = 0; i < N; i++)
    {
        if (arr[i] != temp[i])
        {
            ans++;
            swap(arr, i, indexOf(arr, temp[i]));
        }
    }
    return ans;
}
int main()
{
    vector<int> a = {101, 758, 315, 730,
                     472, 619, 460, 479};

    int n = a.size();
    cout << minSwap(a, n);
    return 0;
}*/
/*//Kth smallest number again
#include <bits/stdc++.h>
using namespace std;
struct Interval
{
	int s;
	int e;
};
bool comp(Interval a, Interval b)
{
	return a.s < b.s;
}
int kthSmallestNum(vector<Interval> merged, int k)
{
	int n = merged.size();

	for (int j = 0; j < n; j++)
	{
		if (k <= abs(merged[j].e -
					merged[j].s + 1))
			return (merged[j].s + k - 1);

		k = k - abs(merged[j].e -
					merged[j].s + 1);
	}
	if (k)
	return -1;
}
void mergeIntervals(vector<Interval> &merged,
				Interval arr[], int n)
{
	sort(arr, arr + n, comp);
	merged.push_back(arr[0]);
	for (int i = 1; i < n; i++)
	{
		Interval prev = merged.back();
		Interval curr = arr[i];
		if ((curr.s >= prev.s &&
			curr.s <= prev.e) &&
			(curr.e > prev.e))

		merged.back().e = curr.e;

		else
		{
			if (curr.s > prev.e)
				merged.push_back(curr);
		}
	}
}
int main()
{
	Interval arr[] = {{2, 6}, {4, 7}};
	int n = sizeof(arr)/sizeof(arr[0]);
	int query[] = {5, 8};
	int q = sizeof(query)/sizeof(query[0]);
	vector<Interval>merged;
	mergeIntervals(merged, arr, n);

	for (int i = 0; i < q; i++)
		cout << kthSmallestNum(merged, query[i])
			<< endl;
	return 0;
}*/
/*//Find pivot element in a sorted array
Same as 46- Search an element in a sorted and rotated array*/
/*//K-th Element of Two Sorted Arrays
#include <bits/stdc++.h>
using namespace std;
int kth(int arr1[], int arr2[], int m, int n, int k)
{
    int sorted[m + n];
    int i = 0, j = 0, d = 0;
    while (i < m && j < n)
    {
        if (arr1[i] < arr2[j])
            sorted[d++] = arr1[i++];
        else
            sorted[d++] = arr2[j++];
    }
    while (i < m)
        sorted[d++] = arr1[i++];
    while (j < n)
        sorted[d++] = arr2[j++];
    return sorted[k - 1];
}

int main()
{
    int arr1[5] = {2, 3, 6, 7, 9};
    int arr2[4] = {1, 4, 8, 10};
    int k = 5;
    cout << kth(arr1, arr2, 5, 4, k);
    return 0;
}*/
/*//book allocation problem
#include <bits/stdc++.h>
using namespace std;
bool isPossible(int arr[], int n, int m, int curr_min)
{
    int studentsRequired = 1;
    int curr_sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > curr_min)
            return false;
        if (curr_sum + arr[i] > curr_min)
        {
            studentsRequired++;
            curr_sum = arr[i];
            if (studentsRequired > m)
                return false;
        }
        else
            curr_sum += arr[i];
    }
    return true;
}
int findPages(int arr[], int n, int m)
{
    long long sum = 0;
    if (n < m)
        return -1;
    for (int i = 0; i < n; i++)
        sum += arr[i];
    int start = 0, end = sum;
    int result = INT_MAX;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (isPossible(arr, n, m, mid))
        {
            result = mid;
            end = mid - 1;
        }
        else
            start = mid + 1;
    }
    return result;
}
int main()
{
    int arr[] = {12, 34, 67, 90};
    int n = sizeof arr / sizeof arr[0];
    int m = 2;
    cout << "Minimum number of pages = "
         << findPages(arr, n, m) << endl;
    return 0;
}*/
/*//Job Scheduling Algo
#include <iostream>
#include <algorithm>
using namespace std;
struct Job
{
	int start, finish, profit;
};
bool myfunction(Job s1, Job s2)
{
	return (s1.finish < s2.finish);
}
int binarySearch(Job jobs[], int index)
{
	int lo = 0, hi = index - 1;
	while (lo <= hi)
	{
		int mid = (lo + hi) / 2;
		if (jobs[mid].finish <= jobs[index].start)
		{
			if (jobs[mid + 1].finish <= jobs[index].start)
				lo = mid + 1;
			else
				return mid;
		}
		else
			hi = mid - 1;
	}

	return -1;
}
int findMaxProfit(Job arr[], int n)
{
	sort(arr, arr+n, myfunction);
	int *table = new int[n];
	table[0] = arr[0].profit;
	for (int i=1; i<n; i++)
	{
		int inclProf = arr[i].profit;
		int l = binarySearch(arr, i);
		if (l != -1)
			inclProf += table[l];
		table[i] = max(inclProf, table[i-1]);
	}
	int result = table[n-1];
	delete[] table;

	return result;
}

int main()
{
	Job arr[] = {{3, 10, 20}, {1, 2, 50}, {6, 19, 100}, {2, 100, 200}};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout << "Optimal profit is " << findMaxProfit(arr, n);
	return 0;
}*/
/*//Missing Number in AP
#include <iostream>
using namespace std;
#define INT_MAX 2147483647;
class FIND
{
public:
    int findMissingUtil(int arr[], int low,
                        int high, int diff)
    {
        if (high <= low)
            return INT_MAX;
        int mid = low + (high - low) / 2;
        if (arr[mid + 1] - arr[mid] != diff)
            return (arr[mid] + diff);
        if (mid > 0 && arr[mid] - arr[mid - 1] != diff)
            return (arr[mid - 1] + diff);
        if (arr[mid] == arr[0] + mid * diff)
            return findMissingUtil(arr, mid + 1,
                                   high, diff);
        return findMissingUtil(arr, low, mid - 1, diff);
    }
    int findMissing(int arr[], int n)
    {
        int diff = (arr[n - 1] - arr[0]) / n;
        return findMissingUtil(arr, 0, n - 1, diff);
    }
};
int main()
{
    FIND g;
    int arr[] = {2, 4, 8, 10, 12, 14};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "The missing element is "
         << g.findMissing(arr, n);
    return 0;
}*/
/*//Smallest number with atleast n trailing zeroes infactorial
#include <bits/stdc++.h>
using namespace std;
bool check(int p, int n)
{
    int temp = p, count = 0, f = 5;
    while (f <= temp)
    {
        count += temp/f;
        f = f*5;
    }
    return (count >= n);
}
int findNum(int n)
{
    if (n == 1)
        return 5;
    int low = 0;
    int high = 5 * n;
    while (low < high)
    {
        int mid = (low + high) >> 1;
        if (check(mid, n))
            high = mid;
        else
            low = mid + 1;
    }
    return low;
}
int main()
{
    int n = 6;
    cout << findNum(n) << endl;
    return 0;
}*/
/*//Painters Partition Problem:
#include <bits/stdc++.h>
using namespace std;
int sum(int arr[], int start, int end)
{
    int total = 0;
    for (int i = start; i <= end; i++)
        total += arr[i];
    return total;
}
int partition(int arr[], int n, int k)
{
    if (k == 1)
        return sum(arr, 0, n - 1);
    if (n == 1)
        return arr[0];
    int best = INT_MAX;
    for (int i = 0; i < n; i++)
        best = min(best, max(partition(arr, i, k - 1), sum(arr, i, n - 1)));
    return best;
}
int main()
{
    int arr[] = {10, 20, 60, 50, 30, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    cout << partition(arr, n, k) << endl;
    return 0;
}*/
/*//Subset Sums
#include <bits/stdc++.h>
using namespace std;
int tab[2000][2000];
int subsetSum(int arr[], int n, int sum)
{
    if (sum == 0)
        return 1;
    if (n <= 0)
        return 0;
    if (tab[n - 1][sum] != -1)
        return tab[n - 1][sum];
    if (arr[n - 1] > sum)
        return tab[n - 1][sum] = subsetSum(arr, n - 1, sum);
    else
    {
        return tab[n - 1][sum] = subsetSum(arr, n - 1, sum) ||
                                 subsetSum(arr, n - 1, sum - arr[n - 1]);
    }
}

int main()
{
    memset(tab, -1, sizeof(tab));
    int n = 5;
    int arr[] = {1, 5, 3, 7, 4};
    int sum = 12;
    if (subsetSum(arr, n, sum))
    {
        cout << "Yes" << endl;
    }
    else cout << "No" << endl;
    
    return 0;
}*/
/*//Findthe inversion count
#include <bits/stdc++.h>
using namespace std;
int getInvCount(int arr[], int n)
{
    int inv_count = 0;
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (arr[i] > arr[j])
                inv_count++;
    return inv_count;
}

int main()
{
    int arr[] = {1, 20, 6, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << " Number of inversions are " << getInvCount(arr, n);
    return 0;
}*/
/*//Merge-sort
#include <iostream>
using namespace std;

// Merges two subarrays of array[].
// First subarray is arr[begin..mid]
// Second subarray is arr[mid+1..end]
void merge(int array[], int const left, int const mid, int const right)
{
	auto const subArrayOne = mid - left + 1;
	auto const subArrayTwo = right - mid;

	// Create temp arrays
	auto *leftArray = new int[subArrayOne],
		*rightArray = new int[subArrayTwo];

	// Copy data to temp arrays leftArray[] and rightArray[]
	for (auto i = 0; i < subArrayOne; i++)
		leftArray[i] = array[left + i];
	for (auto j = 0; j < subArrayTwo; j++)
		rightArray[j] = array[mid + 1 + j];

	auto indexOfSubArrayOne = 0, // Initial index of first sub-array
		indexOfSubArrayTwo = 0; // Initial index of second sub-array
	int indexOfMergedArray = left; // Initial index of merged array

	// Merge the temp arrays back into array[left..right]
	while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
		if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
			array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
			indexOfSubArrayOne++;
		}
		else {
			array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
			indexOfSubArrayTwo++;
		}
		indexOfMergedArray++;
	}
	// Copy the remaining elements of
	// left[], if there are any
	while (indexOfSubArrayOne < subArrayOne) {
		array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
		indexOfSubArrayOne++;
		indexOfMergedArray++;
	}
	// Copy the remaining elements of
	// right[], if there are any
	while (indexOfSubArrayTwo < subArrayTwo) {
		array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
		indexOfSubArrayTwo++;
		indexOfMergedArray++;
	}
}

// begin is for left index and end is
// right index of the sub-array
// of arr to be sorted 
void mergeSort(int array[], int const begin, int const end)
{
	if (begin >= end)
		return; // Returns recursivly

	auto mid = begin + (end - begin) / 2;
	mergeSort(array, begin, mid);
	mergeSort(array, mid + 1, end);
	merge(array, begin, mid, end);
}

// UTILITY FUNCTIONS
// Function to print an array
void printArray(int A[], int size)
{
	for (auto i = 0; i < size; i++)
		cout << A[i] << " ";
}

// Driver code
int main()
{
	int arr[] = { 12, 11, 13, 5, 6, 7 };
	auto arr_size = sizeof(arr) / sizeof(arr[0]);

	cout << "Given array is \n";
	printArray(arr, arr_size);

	mergeSort(arr, 0, arr_size - 1);

	cout << "\nSorted array is \n";
	printArray(arr, arr_size);
	return 0;
}*/
/*//Partitioning and Sorting Arrays with Many Repeated Entries
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

void sort(int arr[], int n)
{
    map<int, int> count;
    for (int i = 0; i < n; i++)
        count[arr[i]]++;
    map<int, int>::iterator it;
    int index = 0;
    for (it = count.begin(); it != count.end(); ++it)
    {
        while (it->second--)
            arr[index++] = it->first;
    }
}
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
int main()
{
    int arr[] = {100, 12, 100, 1, 1, 12, 100, 1, 12, 100, 1, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Input array is\n";
    printArray(arr, n);

    sort(arr, n);

    cout << "Sorted array is\n";
    printArray(arr, n);

    return 0;
}*/
