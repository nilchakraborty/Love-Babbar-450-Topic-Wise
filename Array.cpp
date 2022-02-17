/*//reverse the array
#include <iostream>
using namespace std;
void reverseArray(int arr[], int start, int end)
{
    while (start < end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
int main()
{
    int arr[] = {1,2,3,4,5,6};
    int n = sizeof(arr) / sizeof(arr[0]);
    printArray(arr, n);
    reverseArray(arr, 0, n - 1);
    cout << "Reversed array is " << endl;
    printArray(arr, n);
    return 0;
}*/
/*//Maximum and minimum of an array
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
/*//K’th Smallest/Largest Element in Unsorted Array
#include <iostream>
#include <algorithm>
using namespace std;
int kthSmallest(int arr[],int n,int k){
    sort(arr,arr+n);
    return arr[k-1];
}
int main() {
    int arr[]={12,3,5,7,19};
    int n=sizeof(arr)/sizeof(arr[0]),k=2;
    cout<<"K'th smallest element is "<<kthSmallest(arr,n,k);
    return 0;
}*/
/*//Sort an array of 0s, 1s and 2s
#include <iostream>
using namespace std;
void printArr(int arr[], int n)
{
    for (int i = 0; i, n; i++)
        cout << arr[i] << " ";
}
void sortArr(int arr[], int n)
{
    int i, cnt0 = 0, cnt1 = 0, cnt2 = 0;
    for (i = 0; i < n; i++)
    {
        switch (arr[i])
        {
        case 0:
            cnt0++;
            break;
        case 1:
            cnt1++;
            break;
        case 3:
            cnt2++;
            break;
        }
    }
    i = 0;
    while (cnt0 > 0)
    {
        arr[i++] = 0;
        cnt0--;
    }
    while (cnt1 > 0)
    {
        arr[i++] = 1;
        cnt1--;
    }
    while (cnt2 > 0)
    {
        arr[i++] = 2;
        cnt2--;
    }
}
int main()
{
    int arr[] = {0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    sortArr(arr, n);
    cout << "array after segregation "<< printArr(arr,n);
    return 0;
}*/
/*//Move all negative numbers to beginning
#include <iostream>
using namespace std;
void rearrange(int arr[], int n)
{
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0)
        {
            if (i != j)
            {
                swap(arr[i], arr[j]);
                j++;
            }
        }
    }
}
void printArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}
    int main()
    {
        int arr[]={ -1, 2, -3, 4, 5, 6, -7, 8, 9 };
        int n=sizeof(arr)/sizeof(arr[0]);
        rearrange(arr,n);
        printArr(arr,n);
        return 0;
    }*/
/*//Union and Intersection of two sorted arrays
#include <bits/stdc++.h>
using namespace std;
//For union
void printUnion(int arr1[], int arr2[], int m, int n)
{
    int i = 0, j = 0;
    while (i < m && j < n)
    {
        if (arr1[i] < arr2[j])
            cout << arr1[i++] << " ";
        else if (arr2[j] < arr1[i])
            cout << arr2[j++] << " ";
        else
        {
            cout << arr2[j++] << " ";
            i++;
        }
    }
    while (i < m)
        cout << arr1[i++] << " ";
    while (j < n)
        cout << arr2[j++] << " ";
}
//For intersection
void printIntersection(int arr1[], int arr2[], int m, int n)
{
    int i = 0, j = 0;
    while (i < m && j < n)
    {
        if (arr1[i] < arr2[j])
            i++;
        else if (arr2[j] < arr1[i])
            j++;
        else{
            cout << arr2[j++] << " ";
        i++;
        j++;
        }
    }
}
        int main()
        {
            int arr1[] = {1, 2, 4, 5, 6};
            int arr2[] = {2, 3, 5, 7};

            int m = sizeof(arr1) / sizeof(arr1[0]);
            int n = sizeof(arr2) / sizeof(arr2[0]);

            printUnion(arr1, arr2, m, n); //union
            printIntersection(arr1, arr2, m, n); //intersection
            return 0;
        }*/
/*//cyclically rotate an array by one
#include <iostream>
using namespace std;
void rotate(int arr[], int n)
{
    int i = 0;
    int j = (n - 1);
    while (i != j)
    {
        swap(arr[i], arr[j]);
        i++;
    }
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5}, i;
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Given array is ";
    for (i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    rotate(arr, n);
    cout << "rotated array is \n";
    for (i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}*/
/*//Largest Sum Contiguous Subarray
#include <iostream>
using namespace std;
int maxSubArraySum(int arr[], int n)
{
    int maxSum = 0;
    int curSum = 0;
    for (int i = 0; i < n; i++)
    {
        curSum = curSum + arr[i];
        if (curSum > maxSum)
        {
            maxSum = curSum;
        }
        if(curSum < 0)
        {
            curSum = 0;
        }
    }
    return maxSum;
}
int main()
{
    int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int maximum = maxSubArraySum(arr, n);
    cout << "Sum of largest Sub array: " << maximum;
    return 0;
}*/
/*//Minimize the maximum difference between the heights
#include <bits/stdc++.h>
using namespace std;
int getMinDiff(int arr[], int n, int k)
{
    if (n == 1)
        return 0;
    sort(arr, arr + n);
    int ans = arr[n - 1] - arr[0];
    int small = arr[0] + k;
    int big = arr[n - 1] - k;
    if (small > big)
        swap(small, big);
    for (int i = 1; i < n - 1; i++)
    {
        int subtract = arr[i] - k;
        int add = arr[i] + k;
        if (subtract >= small || add <= big)
            continue;
        if (big - subtract <= add - small)
            small = subtract;
        else
            big = add;
    }

    return min(ans, big - small);
}
int main()
{
    int arr[] = {4, 20, 15, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 10;
    cout << "Maximum difference is " << getMinDiff(arr, n, k);
    return 0;
}*/
/*//Minimum number of jumps to reach end
#include <iostream>
using namespace std;
int minJumps(int arr[], int n);
{
    if (n == 1)
        return 0;
    int res = INT_MAX;
    for (int i = n - 2; i >= 0; i--)
    {
        if (i + arr[i] >= n - 1)
        {
            int sub_res = minJumps(arr, i + 1);
            if (sub_res != INT_MAX)
                res = min(res, sub_res + 1);
        }
    }

    return res;
}
}
int main()
{
    int arr[] = {1, 3, 6, 3, 2, 3, 6, 8, 9, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Minimum number of jumps to";
    cout << " reach the end is " << minJumps(arr, n);
    return 0;
}*/
/*//Find duplicates in array
#include <iostream>
using namespace std;
void printRepeating(int arr[], int n)
{
    cout << "Repeating element are " << endl;
    for (int i = 0; i < n; i++)
    {
        if (arr[abs(arr[i])] >= 0)
            arr[abs(arr[i])] = -arr[abs(arr[i])];
        else
            cout << abs(arr[i]) << " ";
    }
}
int main()
{
    int arr[] = {1, 2, 3, 4, 2, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    printRepeating(arr, n);
    return 0;
}*/
/*//Merge two sorted arrays without extra space
#include <bits/stdc++.h>
using namespace std;
void merge(int arr1[], int arr2[], int n, int m)
{
    int i = 0, j = 0, k = n - 1;
    while (i <= k and j < m)
    {
        if (arr1[i] < arr2[j])
            i++;
        else
        {
            swap(arr2[j++], arr1[k--]);
        }
    }
    sort(arr1, arr1 + n);
    sort(arr2, arr2 + m);
}
int main()
{
    int arr1[] = {1, 5, 9, 10, 15, 20};
    int arr2[] = {2, 3, 8, 13};
    int m = sizeof(arr1) / sizeof(arr1[0]);
    int n = sizeof(arr2) / sizeof(arr2[0]);
    merge(arr1, arr2, m, n);
    cout << "After merging \nFirst Array: ";
    for (int i = 0; i < m; i++)
        cout << arr1[i] << " ";
    cout << "\nSecond Array: ";
    for (int i = 0; i < n; i++)
        cout << arr2[i] << " ";
    return 0;
}*/
/*//Merge Intervals
#include <bits/stdc++.h>
using namespace std;
struct Interval
{
    int s, e;
};
bool mycomp(Interval a, Interval b)
{
    return a.s < b.s;
}

void mergeIntervals(Interval arr[], int n)
{
    sort(arr, arr + n, mycomp);

    int index = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[index].e >= arr[i].s)
        {
            arr[index].e = max(arr[index].e, arr[i].e);
            arr[index].s = min(arr[index].s, arr[i].s);
        }
        else
        {
            index++;
            arr[index] = arr[i];
        }
    }
    cout << "\n The Merged Intervals are: ";
    for (int i = 0; i <= index; i++)
        cout << "[" << arr[i].s << ", " << arr[i].e << "] ";
}
int main()
{
    Interval arr[] = {{6, 8}, {1, 9}, {2, 4}, {4, 7}};
    int n = sizeof(arr) / sizeof(arr[0]);
    mergeIntervals(arr, n);
    return 0;
}*/
/*//next_permutation
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int arr[] = {1, 2, 3};
    sort(arr, arr + 3);
    cout << "The 3! possible permutations with 3 elements:\n";
    do
    {
        cout << arr[0] << " " << arr[1] << " " << arr[2] << " \n";
    } while (next_permutation(arr, arr + 3));
    cout <<"After loop: "<< arr[0] << ' ' << arr[1] << ' ' << arr[2] << '\n';

    return 0;
}*/
/*//Count Inversions
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
    cout << "Number of inversions are " << getInvCount(arr, n);
    return 0;
}*/
/*//Stock Buy Sell to Maximize Profit
#include <bits/stdc++.h>
using namespace std;
int maxProfit(int price[], int start, int end)
{
    if (end <= start)
        return 0;
    int profit = 0;
    for (int i = start; i < end; i++)
    {
        for (int j = i + 1; j < end; j++)
        {
            if (price[j] > price[i])
            {
                int curr_profit = price[j] - price[i] + maxProfit(price, start, i - 1) + maxProfit(price, j + 1, end);
                profit = max(profit, curr_profit);
            }
        }
    }
    return profit;
}
int main()
{
    int price[] = {100, 180, 260, 310, 40, 535, 695};
    int n = sizeof(price) / sizeof(price[0]);
    cout << maxProfit(price, 0, n - 1);
    return 0;
}*/
/*//Count pairs with given sum
#include <iostream>
using namespace std;
int getPairCount(int arr[], int n, int sum)
{
    int count = 0;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (arr[i] + arr[j] == sum)
                count++;
    return count;
}
int main()
{
    int arr[] = {1, 5, 7, -1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 6;
    cout << "Count of pairs is " << getPairCount(arr, n, sum);
    return 0;
}*/
/*//Rearrange array in alternating positive & negative items with O(1) extra space
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
int partition(int arr[], int n)
{
    int j = 0;
    int pivot = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < pivot)
        {
            swap(arr[i], arr[j]);
            j++;
        }
    }
    return j;
}
int rearrange(int arr[], int size)
{
    int p = partition(arr, size);

    for (int n = 0; (p < size && n < p); p++, n += 2)
    {
        swap(arr[n], arr[p]);
    }
    return p;
}

int main()
{
    int arr[] = {9, -3, 5, -2, -8, -6, 1, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    rearrange(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << setw(3) << arr[i];
    }

    return 0;
}*/
/*//Find if there is a subarray with 0 sum
#include <bits/stdc++.h>
using namespace std;
bool subArrayExists(int arr[], int n)
{
    unordered_set<int> sumSet;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum == 0 || sumSet.find(sum) != sumSet.end())
            return true;
        sumSet.insert(sum);
    }
    return false;
}
    int main()
    {
        int arr[] = {-3, 2, 3, 1, 6};
        int n = sizeof(arr) / sizeof(arr[0]);
        if (subArrayExists(arr, n))
            cout << "Found a subarray with 0 sum";
        else
            cout << "No Such Sub Array Exists!";
        return 0;
    }*/
/*//find the factorial of a large number
#include <iostream>
using namespace std;
#define MAX 500
int multiply(int x, int res[], int res_size) void factorial(int n)
{
    int res[MAX];
    res[0] = 1;
    int res_size = 1;
    for (int x = 2; x <= n; x++)
        res_size = multiply(x, res, res_size);
    cout << "Factorial of given number is \n";
    for (int i = res_size - 1; i >= 0; i--)
        cout << res[i];
}
int multiply(int x, int res[], int res_size)
{
    int carry = 0;
    for (int i = 0; i < res_size; i++)
    {
        int prod = res[i] * x + carry;
        res[i] = prod % 10;
        carry = prod / 10;
    }
    while (carry)
    {
        res[res_size] = carry % 10;
        carry = carry / 10;
        res_size++;
    }
    return res_size;
}
int main()
{
    factorial(100);
    return 0;
}*/
/*//Maximum Product Subarray
#include<bits/stdc++.h>
using namespace std;

int maxProductSubArray(vector<int>& nums) {
    int prod1 = nums[0],prod2 = nums[0],result = nums[0];
    
    for(int i=1;i<nums.size();i++) {
        int temp = max({nums[i],prod1*nums[i],prod2*nums[i]});
        prod2 = min({nums[i],prod1*nums[i],prod2*nums[i]});
        prod1 = temp;
        
        result = max(result,prod1);
    }
    
    return result;
}

int main() {
    vector<int> nums = {1,2,-3,0,-4,-5};
    cout<<"The maximum product subarray: "<<maxProductSubArray(nums);
    return 0;
}*/
/*//Longest Consecutive Subsequence
#include <bits/stdc++.h>
using namespace std;
int findLongestSub(int arr[], int n)
{
    int ans = 0, count = 0;
    sort(arr, arr + n);
    vector<int> v;
    v.push_back(arr[0]);
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != arr[i - 1])
            v.push_back(arr[i]);
    }
    for (int i = 0; i < v.size(); i++)
    {
        if (i > 0 && v[i] == v[i - 1] + 1)
            count++;
        else
            count = 1;
        ans = max(ans, count);
    }
    return ans;
}
int main()
{
    int arr[] = {1, 2, 2, 3};
    int n = sizeof arr / sizeof arr[0];
    cout << "Length of the Longest contiguous subsequence is " << findLongestSub(arr, n);
    return 0;
}*/
/*//Given an array of size n and a number k, find all elements that appear more than n/k times
#include <bits/stdc++.h>
using namespace std;
void moreThanNbyk(int arr[], int n, int k)
{
    int x = n / k;
    unordered_map<int, int> freq;
    for (int i = 0; i < n; i++)
    {
        freq[arr[i]]++;
    }
    for (auto i : freq)
    {
        if (i.second > x)
        {
            cout << i.first << endl;
        }
    }
}
int main()
{
    int arr[] = {1, 1, 2, 2, 3, 5, 4, 2, 2, 3, 1, 1, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 4;
    moreThanNbyk(arr, n, k);
    return 0;
}*/
/*//Maximum profit by buying and selling a share at most twice
#include <iostream>
using namespace std;

int main()
{
    int price[] = {10, 22, 5, 75, 65, 80};
    int n = 7;
    int profit = 0;
    for (int i = 0; i < n; i++)
    {
        int sub = price[i] - price[i - 1];
        if (sub > 0)
            profit += sub;
    }
    cout << "Maximum profit " << profit; 
    return 0;
}*/
/*//Find whether an array is a subset of another array
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr1[] = {11, 1, 13, 21, 3, 7};
    int arr2[] = {11, 3, 7, 1};
    int m = sizeof(arr1) / sizeof(arr1[0]);
    int n = sizeof(arr2) / sizeof(arr2[0]);
    unordered_set<int> s;
    for (int i = 0; i < m; i++)
    {
        s.insert(arr1[i]);
    }
    int p = s.size();
    for (int i = 0; i < m; i++)
    {
        s.insert(arr2[i]);
    }
    if (s.size() == p)
    {
        cout << "arr2[] is subset of arr1[]" << endl;
    }
    else
    {
        cout << "arr2[] is not a subset of arr1[]" << endl;
    }

    return 0;
}*/
/*//Find the triplet that sum to a given value
#include <bits/stdc++.h>
using namespace std;
bool find3Numbers(int arr[], int n, int sum)
{   
    for (int i = 0; i < n - 2; i++)
    {
        for (int j = i + 1; j < n - 1; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (arr[i] + arr[j] + arr[k] == sum)
                {
                    cout << "triplet is" << arr[i] << "," << arr[j] << "," << arr[k];
                    return true;
                }
            }
        }
    }
    return false;
}
int main()
{
    int arr[] = {1, 4, 45, 6, 10, 8};
    int sum = 22;
    int n = sizeof(arr) / sizeof(arr[0]);
    find3Numbers(arr, n, sum);
    return 0;
}*/
/*//Trapping Rain Water
#include <bits/stdc++.h>
using namespace std;
int maxWater(int arr[], int n)
{
    int res = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int left = arr[i];
        for (int j = 0; j < i; j++)
            left = max(left, arr[j]);

        int right = arr[i];
        for (int j = i + 1; j < n; j++)

            right = max(right, arr[j]);
        res = res + (min(left, right) - arr[i]);
    }
    return res;
}
int main()
{
    int arr[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout<< maxWater(arr, n);
    return 0;
}*/
/*//Chocolate Distribution Problem
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
    int arr[] = {12, 4, 7, 9, 2, 23, 25, 41, 30, 40, 28, 42, 30, 44, 48, 43, 50};
    int m = 7;
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Minimum difference is " << findMinDiff(arr, n, m);
    return 0;
}*/
/*//Smallest Subarray with sum greater than a given value
#include <bits/stdc++.h>
using namespace std;
int smallestSubarraywithSum(int arr[], int n, int x)
{
    int sum = 0, minLength = n + 1, start = 0, end = 0;
    while (end < n)
    {
        while (sum <= x && end < n)
        {
            sum += arr[end++];
        }
        while (sum > x && start < n)
        {
            if (end - start < minLength)
            {
                minLength = end - start;
            }
            sum -= arr[start++];
        }
    }
    return minLength;
}
int main()
{
    int arr[] = {1, 4, 45, 6, 10, 19};
    int x = 51;
    int n = 6;
    int minLength = smallestSubarraywithSum(arr, n, x);
    if (minLength == n + 1)
    {
        cout << "No such subarray exists" << endl;
    }
    else
    {
        cout << "Smallest length Subarray is: " << minLength << endl;
    }
    return 0;
}*/
/*//Three way partitioning of an array
#include <iostream>
using namespace std;
void threeWayPartition(int arr[], int n, int lowVal, int highVal){
int start = 0, end = n - 1;
for (int i = 0; i <= end;)
{
    if (arr[i] < lowVal)
        swap(arr[i++], arr[start++]);
    else if (arr[i] > highVal)
        swap(arr[i], arr[end--]);

    else
        i++;
}
}
int main()
{
    int arr[] = {1, 14, 5, 20, 4, 2, 54, 20, 87, 98, 3, 1, 32};
    int n = sizeof(arr) / sizeof(arr[0]);
    threeWayPartition(arr, n, 10, 20);
    cout << "Modified array \n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}*/
/*//Minimum swaps required bring elements less equal K together
#include <iostream>
using namespace std;
int minSwap(int *arr, int n, int k)
{
    int count = 0;
    for (int i = 0; i < n; ++i)
        if (arr[i] <= k)
            ++count;
    int waste = 0;
    for (int i = 0; i < count; i++)
        if (arr[i] > k)
            ++waste;
    int ans = waste;
    for (int i = 0, j = count; j < n; ++i, ++j)
    {
        if (arr[i] > k)
            --waste;
        if (arr[j] > k)
            ++waste;
        ans = min(ans, waste);
    }
    return ans;
}
int main()
{
    int arr[] = {2, 1, 5, 6, 3};
    int n = 5;
    int k = 3;
    cout << minSwap(arr, n, k) << "\n";
    return 0;
}*/
/*//Minimum no. of operations required to make an array palindrome
#include <bits/stdc++.h>
using namespace std;
int minOps(int arr[], int n)
{
    int ans = 0;
    for (int i = 0, j = n - 1; i <= j;)
    {
        if (arr[i] == arr[j])
        {
            i++;
            j--;
        }
        else if (arr[i] > arr[j])
        {
            i--;
            arr[j] += arr[j + 1];
            ans++;
        }
        else
        {
            i++;
            arr[i] += arr[i - 1];
            ans++;
        }
    }
    return ans;
}
int main()
{
    int arr[] = {1, 4, 5, 9, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Count of minimum operations is " << minOps(arr, n) << endl;
    return 0;
}*/
/*//Median of two sorted arrays
#include <bits/stdc++.h>
using namespace std;
int getMedian(int ar1[], int ar2[], int n, int m)
{
    int i = 0;
    int j = 0;
    int count;
    int m1 = -1, m2 = -1;
    if ((m + n) % 2 == 1)
    {
        for (count = 0; count <= (n + m) / 2; count++)
        {
            if (i != n && j != m)
            {
                m1 = (ar1[i] > ar2[j]) ? ar2[j++] : ar1[i++];
            }
            else if (i < n)
            {
                m1 = ar1[i++];
            }
            else
            {
                m1 = ar2[j++];
            }
        }
        return m1;
    }
    else
    {
        for (count = 0; count <= (n + m) / 2; count++)
        {
            m2 = m1;
            if (i != n && j != m)
            {
                m1 = (ar1[i] > ar2[j]) ? ar2[j++] : ar1[i++];
            }
            else if (i < n)
            {
                m1 = ar1[i++];
            }
            else
            {
                m1 = ar2[j++];
            }
        }
        return (m1 + m2) / 2;
    }
}
int main()
{
    int ar1[] = {900};
    int ar2[] = {5, 8, 10, 20};

    int n1 = sizeof(ar1) / sizeof(ar1[0]);
    int n2 = sizeof(ar2) / sizeof(ar2[0]);
    cout << getMedian(ar1, ar2, n1, n2);
    return 0;
}*/
/*Repeat and Missing Number
vector<int>missing_repeated_number(const vector<int> &A) {
    long long int len = A.size();
    long long int S = (len * (len+1) ) /2;
    long long int P = (len * (len +1) *(2*len +1) )/6;
    long long int missingNumber=0, repeating=0;    
    for(int i=0;i<A.size(); i++){
       S -= (long long int)A[i];
       P -= (long long int)A[i]*(long long int)A[i];
    }    
    missingNumber = (S + P/S)/2;
    repeating = missingNumber - S;
    vector <int> ans;
    ans.push_back(repeating);
    ans.push_back(missingNumber);
    return ans;
}*/
/*Count Subarrays with Xor as K
int Solution::solve(vector<int> &A,int B){
    map<int,int> freq;
    int cnt=0;
    int xorr=0;
    for(auto it:A){
        xorr^=it;
        if(xorr==B) cnt++;
        if(freq.find(xorr^B)!=freq.end())
            cnt+=freq[xorr^B];
        freq[xorr]+=1;
    }
    return cnt;
}*/
