/*// Coin ChangeProblem
#include <bits/stdc++.h>
using namespace std;
int count(int S[], int m, int n)
{
    int i, j, x, y;
    int table[n + 1][m];
    for (i = 0; i < m; i++)
        table[0][i] = 1;
    for (i = 1; i < n + 1; i++)
    {
        for (j = 0; j < m; j++)
        {
            x = (i - S[j] >= 0) ? table[i - S[j]][j] : 0;
            y = (j >= 1) ? table[i][j - 1] : 0;
            table[i][j] = x + y;
        }
    }
    return table[n][m - 1];
}

int main()
{
    int arr[] = {1, 2, 3};
    int m = sizeof(arr) / sizeof(arr[0]);
    int n = 4;
    cout << count(arr, m, n);
    return 0;
}*/
/*// Knapsack Problem
#include <bits/stdc++.h>
using namespace std;
int max(int a, int b)
{
    return (a > b) ? a : b;
}
int knapSack(int W, int wt[], int val[], int n)
{
    int i, w;
    vector<vector<int>> K(n + 1, vector<int>(W + 1));
    for (i = 0; i <= n; i++)
    {
        for (w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]],
                              K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }
    return K[n][W];
}
int main()
{
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);

    cout << knapSack(W, wt, val, n);
    return 0;
}*/
/*// Binomial CoefficientProblem
#include <bits/stdc++.h>
using namespace std;
int min(int a, int b);
int binomialCoeff(int n, int k)
{
    int C[n + 1][k + 1];
    int i, j;
    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= min(i, k); j++)
        {
            if (j == 0 || j == i)
                C[i][j] = 1;
            else
                C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
        }
    }
    return C[n][k];
}
int min(int a, int b) { return (a < b) ? a : b; }

int main()
{
    int n = 5, k = 2;
    cout << "Value of C[" << n << "][" << k << "] is "
         << binomialCoeff(n, k);
}*/
/*// Permutation CoefficientProblem
#include <bits/stdc++.h>
using namespace std;
int PermutationCoeff(int n, int k)
{
    int P = 1;
    for (int i = 0; i < k; i++)
    {
        P *= (n - i);
    }
    return P;
}

int main()
{
    int n = 10, k = 2;
    cout << "Value of P(" << n << ", " << k
         << ") is " << PermutationCoeff(n, k);
    return 0;
}*/
/*// Program for nth Catalan Number
#include <bits/stdc++.h>
using namespace std;
unsigned long int catalanDP(unsigned int n)
{
    unsigned long int catalan[n + 1];
    catalan[0] = catalan[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        catalan[i] = 0;
        for (int j = 0; j < i; j++)
            catalan[i] += catalan[j] * catalan[i - j - 1];
    }
    return catalan[n];
}

int main()
{
    for (int i = 0; i < 10; i++)
        cout << catalanDP(i) << " ";
    return 0;
}*/
/*// Matrix Chain Multiplication 
#include <bits/stdc++.h>
using namespace std;
int dp[100][100];
int matrixChainMemoised(int *p, int i, int j)
{
    if (i == j)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    dp[i][j] = INT_MAX;
    for (int k = i; k < j; k++)
    {
        dp[i][j] = min(dp[i][j],
                       matrixChainMemoised(p, i, k) +
                           matrixChainMemoised(p, k + 1, j) + p[i - 1] * p[k] * p[j]);
    }
    return dp[i][j];
}
int MatrixChainOrder(int *p, int n)
{
    int i = 1, j = n - 1;
    return matrixChainMemoised(p, i, j);
}
int main()
{
    int arr[] = {1, 2, 3, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    memset(dp, -1, sizeof dp);

    cout << "Minimum number of multiplications is "
         << MatrixChainOrder(arr, n);
    return 0;
}*/
/*// Edit Distance
#include <bits/stdc++.h>
using namespace std;
int min(int x, int y, int z) { return min(min(x, y), z); }

int editDistDP(string str1, string str2, int m, int n)
{
    int dp[m + 1][n + 1];
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0)
                dp[i][j] = j;
            else if (j == 0)
                dp[i][j] = i;
            else if (str1[i - 1] == str2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = 1 + min(dp[i][j - 1],
                                    dp[i - 1][j],
                                    dp[i - 1][j - 1]);
        }
    }
    return dp[m][n];
}
int main()
{
    string str1 = "sunday";
    string str2 = "saturday";

    cout << editDistDP(str1, str2, str1.length(),
                       str2.length());
    return 0;
}*/
/*// Subset Sum Problem
#include <bits/stdc++.h>
using namespace std;
int tab[2000][2000];
int subsetSum(int a[], int n, int sum)
{
    if (sum == 0)
        return 1;
    if (n <= 0)
        return 0;
    if (tab[n - 1][sum] != -1)
        return tab[n - 1][sum];
    if (a[n - 1] > sum)
        return tab[n - 1][sum] = subsetSum(a, n - 1, sum);
    else
    {
        return tab[n - 1][sum] = subsetSum(a, n - 1, sum) ||
                                 subsetSum(a, n - 1, sum - a[n - 1]);
    }
}

int main()
{
    memset(tab, -1, sizeof(tab));
    int n = 5;
    int a[] = {1, 5, 3, 7, 4};
    int sum = 12;

    if (subsetSum(a, n, sum))
    {
        cout << "YES" << endl;
    }
    else
        cout << "NO" << endl;
    return 0;
}*/
/*// Friends Pairing Problem
#include <bits/stdc++.h>
using namespace std;
int countFriendsPairings(int n)
{
    int dp[n + 1];
    for (int i = 0; i <= n; i++)
    {
        if (i <= 2)
            dp[i] = i;
        else
            dp[i] = dp[i - 1] + (i - 1) * dp[i - 2];
    }
    return dp[n];
}

int main()
{
    int n = 4;
    cout << countFriendsPairings(n) << endl;
    return 0;
}*/
/*// Gold Mine Problem
#include <bits/stdc++.h>
using namespace std;
const int MAX = 100;
int getMaxGold(int gold[][MAX], int m, int n)
{
    int goldTable[m][n];
    memset(goldTable, 0, sizeof(goldTable));
    for (int col = n - 1; col >= 0; col--)
    {
        for (int row = 0; row < m; row++)
        {
            int right = (col == n - 1) ? 0 : goldTable[row][col + 1];
            int right_up = (row == 0 || col == n - 1) ? 0 : goldTable[row - 1][col + 1];
            int right_down = (row == m - 1 || col == n - 1) ? 0 : goldTable[row + 1][col + 1];
            goldTable[row][col] = gold[row][col] +
                                  max(right, max(right_up, right_down));
        }
    }
    int res = goldTable[0][0];
    for (int i = 1; i < m; i++)
        res = max(res, goldTable[i][0]);
    return res;
}

int main()
{
    int gold[MAX][MAX] = {{1, 3, 1, 5},
                          {2, 2, 4, 1},
                          {5, 0, 2, 3},
                          {0, 6, 1, 2}};
    int m = 4, n = 4;
    cout << getMaxGold(gold, m, n);
    return 0;
}*/
/*// Assembly Line SchedulingProblem
#include <bits/stdc++.h>
using namespace std;
#define NUM_LINE 2
#define NUM_STATION 4
int min(int a, int b)
{
    return a < b ? a : b;
}

int carAssembly(int a[][NUM_STATION],
                int t[][NUM_STATION],
                int *e, int *x)
{
    int T1[NUM_STATION], T2[NUM_STATION], i;
    T1[0] = e[0] + a[0][0];
    T2[0] = e[1] + a[1][0];
    for (i = 1; i < NUM_STATION; ++i)
    {
        T1[i] = min(T1[i - 1] + a[0][i],
                    T2[i - 1] + t[1][i] + a[0][i]);
        T2[i] = min(T2[i - 1] + a[1][i],
                    T1[i - 1] + t[0][i] + a[1][i]);
    }
    return min(T1[NUM_STATION - 1] + x[0],
               T2[NUM_STATION - 1] + x[1]);
}

int main()
{
    int a[][NUM_STATION] = {{4, 5, 3, 2},
                            {2, 10, 1, 4}};
    int t[][NUM_STATION] = {{0, 7, 4, 5},
                            {0, 9, 2, 8}};
    int e[] = {10, 12}, x[] = {18, 7};

    cout << carAssembly(a, t, e, x);

    return 0;
}*/
/*// Painting the Fenceproblem
#include <bits/stdc++.h>
using namespace std;
long countWays(int n, int k)
{
    long dp[n + 1];
    memset(dp, 0, sizeof(dp));
    long long mod = 1000000007;
    dp[1] = k;
    dp[2] = k * k;
    for (int i = 3; i <= n; i++)
    {
        dp[i] = ((k - 1) * (dp[i - 1] + dp[i - 2])) % mod;
    }
    return dp[n];
}

int main()
{
    int n = 3, k = 2;
    cout << countWays(n, k) << endl;
    return 0;
}*/
/*// Maximize The Cut Segments
#include <bits/stdc++.h>
using namespace std;
int findMaximum(int l, int p, int q, int r)
{
    int dp[l + 1];
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;

    for (int i = 0; i <= l; i++)
    {

        if (dp[i] == -1)
            continue;

        if (i + p <= l)
            dp[i + p] = max(dp[i + p], dp[i] + 1);
        if (i + q <= l)
            dp[i + q] = max(dp[i + q], dp[i] + 1);
        if (i + r <= l)
            dp[i + r] = max(dp[i + r], dp[i] + 1);
    }
    if (dp[l] == -1)
    {
        dp[l] = 0;
    }
    return dp[l];
}
int main()
{
    int l = 11, p = 2, q = 3, r = 5;
    int ans = findMaximum(l, p, q, r);
    cout << ans;
    return 0;
}*/
/*// Longest Common Subsequence
#include <bits/stdc++.h>
using namespace std;
int max(int a, int b);
int lcs(char *X, char *Y, int m, int n)
{
    if (m == 0 || n == 0)
        return 0;
    if (X[m - 1] == Y[n - 1])
        return 1 + lcs(X, Y, m - 1, n - 1);
    else
        return max(lcs(X, Y, m, n - 1), lcs(X, Y, m - 1, n));
}
int max(int a, int b)
{
    return (a > b) ? a : b;
}
int main()
{
    char X[] = "AGGTAB";
    char Y[] = "GXTXAYB";

    int m = strlen(X);
    int n = strlen(Y);

    cout << "Length of LCS is " << lcs(X, Y, m, n);
    return 0;
}*/
/*// Longest Repeated Subsequence
#include <bits/stdc++.h>
using namespace std;
string longestRepeatedSubSeq(string str)
{
    int n = str.length();
    int dp[n + 1][n + 1];
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
            dp[i][j] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (str[i - 1] == str[j - 1] && i != j)
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
    string res = "";
    int i = n, j = n;
    while (i > 0 && j > 0)
    {
        if (dp[i][j] == dp[i - 1][j - 1] + 1)
        {
            res = res + str[i - 1];
            i--;
            j--;
        }
        else if (dp[i][j] == dp[i - 1][j])
            i--;
        else
            j--;
    }
    reverse(res.begin(), res.end());

    return res;
}

int main()
{
    string str = "AABEBCDD";
    cout << longestRepeatedSubSeq(str);
    return 0;
}*/
/*// Longest Increasing Subsequence
#include <bits/stdc++.h>
using namespace std;
int lis(int arr[], int n)
{
    int lis[n];
    lis[0] = 1;
    for (int i = 1; i < n; i++)
    {
        lis[i] = 1;
        for (int j = 0; j < i; j++)
            if (arr[i] > arr[j] && lis[i] < lis[j] + 1)
                lis[i] = lis[j] + 1;
    }
    return *max_element(lis, lis + n);
}

int main()
{
    int arr[] = {10, 22, 9, 33, 21, 50, 41, 60};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Length of lis is %d\n", lis(arr, n));
    return 0;
}*/
/*// Space Optimized Solution of LCS
#include <bits/stdc++.h>
using namespace std;
int lcs(string &X, string &Y)
{
    int m = X.length(), n = Y.length();
    int L[2][n + 1];
    bool bi;
    for (int i = 0; i <= m; i++)
    {
        bi = i & 1;
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                L[bi][j] = 0;
            else if (X[i - 1] == Y[j - 1])
                L[bi][j] = L[1 - bi][j - 1] + 1;
            else
                L[bi][j] = max(L[1 - bi][j],
                               L[bi][j - 1]);
        }
    }
    return L[bi][n];
}

int main()
{
    string X = "AGGTAB";
    string Y = "GXTXAYB";

    printf("Length of LCS is %d\n", lcs(X, Y));
    return 0;
}*/
/*// LCS (Longest Common Subsequence) of three strings
#include <bits/stdc++.h>
using namespace std;
int lcsOf3(string X, string Y, string Z, int m,
           int n, int o)
{
    int L[m + 1][n + 1][o + 1];
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            for (int k = 0; k <= o; k++)
            {
                if (i == 0 || j == 0 || k == 0)
                    L[i][j][k] = 0;

                else if (X[i - 1] == Y[j - 1] && X[i - 1] == Z[k - 1])
                    L[i][j][k] = L[i - 1][j - 1][k - 1] + 1;

                else
                    L[i][j][k] = max(max(L[i - 1][j][k],
                                         L[i][j - 1][k]),
                                     L[i][j][k - 1]);
            }
        }
    }
    return L[m][n][o];
}

int main()
{
    string X = "AGGT12";
    string Y = "12TXAYB";
    string Z = "12XBA";

    int m = X.length();
    int n = Y.length();
    int o = Z.length();

    cout << "Length of LCS is " << lcsOf3(X, Y, Z, m, n, o);
    return 0;
}*/
/*// Maximum Sum Increasing Subsequence
#include <bits/stdc++.h>
using namespace std;
int maxSumIS(int arr[], int n)
{
    int i, j, max = 0;
    int msis[n];
    for (i = 0; i < n; i++)
        msis[i] = arr[i];
    for (i = 1; i < n; i++)
        for (j = 0; j < i; j++)
            if (arr[i] > arr[j] && msis[i] < msis[j] + arr[i])
                msis[i] = msis[j] + arr[i];
    for (i = 0; i < n; i++)
        if (max < msis[i])
            max = msis[i];

    return max;
}

int main()
{
    int arr[] = {1, 101, 2, 3, 100, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Sum of maximum sum increasing "
            "subsequence is "
         << maxSumIS(arr, n) << endl;
    return 0;
}*/
/*// Count all subsequences having product less than K
#include <bits/stdc++.h>
using namespace std;
int productSubSeqCount(vector<int> &arr, int k)
{
    int n = arr.size();
    int dp[k + 1][n + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= k; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dp[i][j] = dp[i][j - 1];
            if (arr[j - 1] <= i && arr[j - 1] > 0)
                dp[i][j] += dp[i / arr[j - 1]][j - 1] + 1;
        }
    }
    return dp[k][n];
}

int main()
{
    vector<int> A;
    A.push_back(1);
    A.push_back(2);
    A.push_back(3);
    A.push_back(4);
    int k = 10;
    cout << productSubSeqCount(A, k) << endl;
    return 0;
}*/
/*// Longest subsequence such that difference between adjacent is one
#include <bits/stdc++.h>
using namespace std;
int longestSubseqWithDiffOne(int arr[], int n)
{
    int dp[n];
    for (int i = 0; i < n; i++)
        dp[i] = 1;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if ((arr[i] == arr[j] + 1) ||
                (arr[i] == arr[j] - 1))

                dp[i] = max(dp[i], dp[j] + 1);
        }
    }
    int result = 1;
    for (int i = 0; i < n; i++)
        if (result < dp[i])
            result = dp[i];
    return result;
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 3, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << longestSubseqWithDiffOne(arr, n);
    return 0;
}*/
/*// Maximum subsequence sum such that no three are consecutive
#include <bits/stdc++.h>
using namespace std;
int maxSumWO3Consec(int arr[], int n)
{
    int sum[n];
    if (n >= 1)
        sum[0] = arr[0];
    if (n >= 2)
        sum[1] = arr[0] + arr[1];
    if (n > 2)
        sum[2] = max(sum[1], max(arr[1] +
                                     arr[2],
                                 arr[0] + arr[2]));
    for (int i = 3; i < n; i++)
        sum[i] = max(max(sum[i - 1], sum[i - 2] + arr[i]),
                     arr[i] + arr[i - 1] + sum[i - 3]);

    return sum[n - 1];
}
int main()
{
    int arr[] = {100, 1000};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << maxSumWO3Consec(arr, n);
    return 0;
}*/
/*// Egg Dropping Problem
#include <bits/stdc++.h>
using namespace std;
int max(int a, int b)
{
    return (a > b) ? a : b;
}
int eggDrop(int n, int k)
{
    if (k == 1 || k == 0)
        return k;
    if (n == 1)
        return k;

    int min = INT_MAX, x, res;

    for (x = 1; x <= k; x++)
    {
        res = max(
            eggDrop(n - 1, x - 1),
            eggDrop(n, k - x));
        if (res < min)
            min = res;
    }
    return min + 1;
}

int main()
{
    int n = 2, k = 10;
    cout << "Minimum number of trials "
            "in worst case with "
         << n << " eggs and " << k
         << " floors is "
         << eggDrop(n, k) << endl;
    return 0;
}*/
/*// Maximum Length Chain of Pairs
#include <bits/stdc++.h>
using namespace std;
class Pair
{
public:
    int a;
    int b;
};
int maxChainLength(Pair arr[], int n)
{
    int i, j, max = 0;
    int *mcl = new int[sizeof(int) * n];

    for (i = 0; i < n; i++)
        mcl[i] = 1;

    for (i = 1; i < n; i++)
        for (j = 0; j < i; j++)
            if (arr[i].a > arr[j].b &&
                mcl[i] < mcl[j] + 1)
                mcl[i] = mcl[j] + 1;

    for (i = 0; i < n; i++)
        if (max < mcl[i])
            max = mcl[i];

    return max;
}
int main()
{
    Pair arr[] = {{5, 24}, {15, 25}, {27, 40}, {50, 60}};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Length of maximum size chain is "
         << maxChainLength(arr, n);
    return 0;
}*/
/*// Maximum size square sub-matrix with all 1s
#include <bits/stdc++.h>
#define bool int
#define R 6
#define C 5
using namespace std;
void printMaxSubSquare(bool M[R][C])
{
    int i, j;
    int S[R][C];
    int max_of_s, max_i, max_j;
    //Set first column of S[][]
    for (i = 0; i < R; i++)
        S[i][0] = M[i][0];
    for (j = 0; j < C; j++)
        S[0][j] = M[0][j];
    for (i = 1; i < R; i++)
    {
        for (j = 1; j < C; j++)
        {
            if (M[i][j] == 1)
                S[i][j] = min(S[i][j - 1], min(S[i - 1][j],
                                               S[i - 1][j - 1])) +
                          1;
            else
                S[i][j] = 0;
        }
    }
    max_of_s = S[0][0];
    max_i = 0;
    max_j = 0;
    for (i = 0; i < R; i++)
    {
        for (j = 0; j < C; j++)
        {
            if (max_of_s < S[i][j])
            {
                max_of_s = S[i][j];
                max_i = i;
                max_j = j;
            }
        }
    }

    cout << "Maximum size sub-matrix is: \n";
    for (i = max_i; i > max_i - max_of_s; i--)
    {
        for (j = max_j; j > max_j - max_of_s; j--)
        {
            cout << M[i][j] << " ";
        }
        cout << "\n";
    }
}

int main()
{
    bool M[R][C] = {{0, 1, 1, 0, 1},
                    {1, 1, 0, 1, 0},
                    {0, 1, 1, 1, 0},
                    {1, 1, 1, 1, 0},
                    {1, 1, 1, 1, 1},
                    {0, 0, 0, 0, 0}};

    printMaxSubSquare(M);
}*/
/*// Maximum sum of pairs with specific difference
#include <bits/stdc++.h>
using namespace std;
int maxSumPairWithDifferenceLessThanK(int arr[], int N, int K)
{
    sort(arr, arr + N);
    int dp[N];
    dp[0] = 0;
    for (int i = 1; i < N; i++)
    {
        dp[i] = dp[i - 1];
        if (arr[i] - arr[i - 1] < K)
        {
            if (i >= 2)
                dp[i] = max(dp[i], dp[i - 2] + arr[i] + arr[i - 1]);
            else
                dp[i] = max(dp[i], arr[i] + arr[i - 1]);
        }
    }
    return dp[N - 1];
}

int main()
{
    int arr[] = {3, 5, 10, 15, 17, 12, 9};
    int N = sizeof(arr) / sizeof(int);
    int K = 4;
    cout << maxSumPairWithDifferenceLessThanK(arr, N, K);
    return 0;
}*/
/*// Min Cost PathProblem
#include <bits/stdc++.h>
using namespace std;
#define R 3
#define C 3
int min(int x, int y, int z);
int minCost(int cost[R][C], int m, int n)
{
    if (n < 0 || m < 0)
        return INT_MAX;
    else if (m == 0 && n == 0)
        return cost[m][n];
    else
        return cost[m][n] + min(minCost(cost, m - 1, n - 1),
                minCost(cost, m - 1, n), minCost(cost, m, n - 1));
}
int min(int x, int y, int z)
{
    if (x < y)
        return (x < z) ? x : z;
    else
        return (y < z) ? y : z;
}
int main()
{
    int cost[R][C] = {{1, 2, 3},
                      {4, 8, 2},
                      {1, 5, 3}};

    cout << minCost(cost, 2, 2) << endl;
    return 0;
}*/
/*// Maximum difference of zeros and ones in binary string
#include <bits/stdc++.h>
#define MAX 100
using namespace std;
bool allones(string s, int n)
{
    int co = 0;
    for (int i = 0; i < s.size(); i++)
        co += (s[i] == '1');

    return (co == n);
}
int findlength(int arr[], string s, int n,
               int ind, int st, int dp[][3])
{
    if (ind >= n)
        return 0;

    if (dp[ind][st] != -1)
        return dp[ind][st];

    if (st == 0)
        return dp[ind][st] = max(arr[ind] +
                                     findlength(arr, s, n, ind + 1, 1, dp),
                                 findlength(arr, s, n, ind + 1, 0, dp));

    else
        return dp[ind][st] = max(arr[ind] +
                                     findlength(arr, s, n, ind + 1, 1, dp),
                                 0);
}

int maxLen(string s, int n)
{
    if (allones(s, n))
        return -1;

    int arr[MAX] = {0};
    for (int i = 0; i < n; i++)
        arr[i] = (s[i] == '0' ? 1 : -1);

    int dp[MAX][3];
    memset(dp, -1, sizeof dp);
    return findlength(arr, s, n, 0, 0, dp);
}
int main()
{
    string s = "11000010001";
    int n = 11;
    cout << maxLen(s, n) << endl;
    return 0;
}*/
/*// Minimum number of jumps to reach end
#include <bits/stdc++.h>
using namespace std;
int minJumps(int arr[], int n)
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

int main()
{
    int arr[] = {1, 3, 6, 3, 2,
                 3, 6, 8, 9, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Minimum number of jumps to";
    cout << " reach the end is " << minJumps(arr, n);
    return 0;
}*/
/*// Minimum cost to fill given weight in a bag
#include <bits/stdc++.h>
using namespace std;
int minCost(int cost[], int n)
{
    int dp[n + 1];
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        int min_cost = INT_MAX;
        for (int j = 0; j < i; j++)
            if (j < n && cost[j] != -1)
                min_cost = min(min_cost, cost[j] + dp[i - j - 1]);
        dp[i] = min_cost;
    }

    return dp[n];
}
int main()
{
    int cost[] = {20, 10, 4, 50, 100};
    int W = sizeof(cost) / sizeof(cost[0]);
    cout << minCost(cost, W);
    return 0;
}*/
/*// Minimum removals from array to make max –min <= K
#include <bits/stdc++.h>
using namespace std;
int removals(int arr[], int n, int k)
{
    sort(arr, arr + n);
    int dp[n];
    for (int i = 0; i < n; i++)
        dp[i] = -1;
    int ans = n - 1;
    dp[0] = 0;
    for (int i = 1; i < n; i++)
    {
        dp[i] = i;
        int j = dp[i - 1];
        while (j != i && arr[i] - arr[j] > k)
        {
            j++;
        }
        dp[i] = min(dp[i], j);
        ans = min(ans, (n - (i - j + 1)));
    }
    return ans;
}

int main()
{
    int a[] = {1, 3, 4, 9, 10, 11, 12, 17, 20};
    int n = sizeof(a) / sizeof(a[0]);
    int k = 4;
    cout << removals(a, n, k);
    return 0;
}*/
/*// Longest Common Substring
#include <iostream>
using namespace std;
string X, Y;
int lcs(int i, int j, int count)
{
    if (i == 0 || j == 0)
        return count;

    if (X[i - 1] == Y[j - 1])
    {
        count = lcs(i - 1, j - 1, count + 1);
    }
    count = max(count,
                max(lcs(i, j - 1, 0),
                    lcs(i - 1, j, 0)));
    return count;
}

int main()
{
    int n, m;
    X = "abcdxyz";
    Y = "xyzabcd";
    n = X.size();
    m = Y.size();
    cout << lcs(n, m, 0);
    return 0;
}*/
/*// Count number of ways to reacha given score in a game
#include <bits/stdc++.h>
using namespace std;
int count(int n)
{
    int table[n + 1], i;
    for (int j = 0; j < n + 1; j++)
        table[j] = 0;

    table[0] = 1;

    for (i = 3; i <= n; i++)
        table[i] += table[i - 3];
    for (i = 5; i <= n; i++)
        table[i] += table[i - 5];
    for (i = 10; i <= n; i++)
        table[i] += table[i - 10];
    return table[n];
}

int main()
{
    int n = 20;
    cout << "Count for " << n
         << " is " << count(n) << endl;

    n = 13;
    cout << "Count for " << n << " is "
         << count(n) << endl;
    return 0;
}*/
/*// Count Balanced Binary Trees of Height h
#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
long long int countBT(int h)
{
    long long int dp[h + 1];
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= h; i++)
    {
        dp[i] = (dp[i - 1] * ((2 * dp[i - 2]) % mod + dp[i - 1]) % mod) % mod;
    }
    return dp[h];
}

int main()
{
    int h = 3;
    cout << "No. of balanced binary trees"
            " of height h is: "
         << countBT(h) << endl;
    return 0;
}*/
/*// LargestSum Contiguous Subarray [V>V>V>V IMP ]
#include <iostream>
using namespace std;

int maxSubArraySum(int a[], int size)
{
    int max_so_far = a[0];
    int curr_max = a[0];

    for (int i = 1; i < size; i++)
    {
        curr_max = max(a[i], curr_max + a[i]);
        max_so_far = max(max_so_far, curr_max);
    }
    return max_so_far;
}

int main()
{
    int a[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(a) / sizeof(a[0]);
    int max_sum = maxSubArraySum(a, n);
    cout << "Maximum contiguous sum is " << max_sum;
    return 0;
}*/
/*// Smallest sum contiguous subarray
#include <bits/stdc++.h>
using namespace std;
int smallestSumSubarr(int arr[], int n)
{
    int min_ending_here = INT_MAX;
    int min_so_far = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (min_ending_here > 0)
            min_ending_here = arr[i];

        else
            min_ending_here += arr[i];

        min_so_far = min(min_so_far, min_ending_here);
    }
    return min_so_far;
}

int main()
{
    int arr[] = {3, -4, 2, -3, -1, 7, -5};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Smallest sum: "
         << smallestSumSubarr(arr, n);
    return 0;
}*/
/*// Unbounded Knapsack (Repetition of items allowed)
#include <bits/stdc++.h>
using namespace std;
int unboundedKnapsack(int W, int n,
                      int val[], int wt[])
{
    int dp[W + 1];
    memset(dp, 0, sizeof dp);
    for (int i = 0; i <= W; i++)
        for (int j = 0; j < n; j++)
            if (wt[j] <= i)
                dp[i] = max(dp[i], dp[i - wt[j]] + val[j]);

    return dp[W];
}

int main()
{
    int W = 100;
    int val[] = {10, 30, 20};
    int wt[] = {5, 10, 15};
    int n = sizeof(val) / sizeof(val[0]);

    cout << unboundedKnapsack(W, n, val, wt);
    return 0;
}*/
/*// Word Break Problem
#include <bits/stdc++.h>
using namespace std;
int dictionaryContains(string word)
{
    string dictionary[] = {"mobile", "samsung", "sam", "sung", "man",
                           "mango", "icecream", "and", "go", "i",
                           "like", "ice", "cream"};
    int size = sizeof(dictionary) / sizeof(dictionary[0]);
    for (int i = 0; i < size; i++)
        if (dictionary[i].compare(word) == 0)
            return true;
    return false;
}
bool wordBreak(string s)
{
    int n = s.size();
    if (n == 0)
        return true;

    vector<bool> dp(n + 1, 0);

    vector<int> matched_index;
    matched_index.push_back(-1);

    for (int i = 0; i < n; i++)
    {
        int msize = matched_index.size();

        int f = 0;

        for (int j = msize - 1; j >= 0; j--)
        {

            string sb = s.substr(matched_index[j] + 1,
                                 i - matched_index[j]);

            if (dictionaryContains(sb))
            {
                f = 1;
                break;
            }
        }
        if (f == 1)
        {
            dp[i] = 1;
            matched_index.push_back(i);
        }
    }
    return dp[n - 1];
}

int main()
{
    wordBreak("ilikesamsung") ? cout << "Yes\n"
                              : cout << "No\n";
    wordBreak("iiiiiiii") ? cout << "Yes\n"
                          : cout << "No\n";
    wordBreak("") ? cout << "Yes\n" : cout << "No\n";
    wordBreak("ilikelikeimangoiii") ? cout << "Yes\n"
                                    : cout << "No\n";
    wordBreak("samsungandmango") ? cout << "Yes\n"
                                 : cout << "No\n";
    wordBreak("samsungandmangok") ? cout << "Yes\n"
                                  : cout << "No\n";
    return 0;
}*/
/*// Largest Independent Set Problem
#include <bits/stdc++.h>
using namespace std;
int max(int x, int y) { return (x > y) ? x : y; }

class node
{
public:
    int data;
    int liss;
    node *left, *right;
};
int LISS(node *root)
{
    if (root == NULL)
        return 0;

    if (root->liss)
        return root->liss;

    if (root->left == NULL && root->right == NULL)
        return (root->liss = 1);

    int liss_excl = LISS(root->left) + LISS(root->right);

    int liss_incl = 1;
    if (root->left)
        liss_incl += LISS(root->left->left) + LISS(root->left->right);
    if (root->right)
        liss_incl += LISS(root->right->left) + LISS(root->right->right);

    root->liss = max(liss_incl, liss_excl);

    return root->liss;
}

node *newNode(int data)
{
    node *temp = new node();
    temp->data = data;
    temp->left = temp->right = NULL;
    temp->liss = 0;
    return temp;
}

int main()
{
    node *root = newNode(20);
    root->left = newNode(8);
    root->left->left = newNode(4);
    root->left->right = newNode(12);
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(14);
    root->right = newNode(22);
    root->right->right = newNode(25);

    cout << "Size of the Largest Independent Set is " << LISS(root);
    return 0;
}*/
/*// Partition problem
#include <bits/stdc++.h>
using namespace std;
bool findPartiion(int arr[], int n)
{
    int sum = 0;
    int i, j;

    for (i = 0; i < n; i++)
        sum += arr[i];

    if (sum % 2 != 0)
        return false;

    bool part[sum / 2 + 1];

    for (i = 0; i <= sum / 2; i++)
    {
        part[i] = 0;
    }

    for (i = 0; i < n; i++)
    {
        for (j = sum / 2; j >= arr[i]; j--)
        {
            if (part[j - arr[i]] == 1 || j == arr[i])
                part[j] = 1;
        }
    }

    return part[sum / 2];
}

int main()
{
    int arr[] = {1, 3, 3, 2, 3, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    if (findPartiion(arr, n) == true)
        cout << "Can be divided into two subsets of equal "
                "sum";
    else
        cout << "Can not be divided into"
             << " two subsets of equal sum";
    return 0;
}*/
/*// Longest Palindromic Subsequence
#include <bits/stdc++.h>
int max(int x, int y) { return (x > y) ? x : y; }

int lps(char *str)
{
    int n = strlen(str);
    int i, j, cl;
    int L[n][n];

    for (i = 0; i < n; i++)
        L[i][i] = 1;
    for (cl = 2; cl <= n; cl++)
    {
        for (i = 0; i < n - cl + 1; i++)
        {
            j = i + cl - 1;
            if (str[i] == str[j] && cl == 2)
                L[i][j] = 2;
            else if (str[i] == str[j])
                L[i][j] = L[i + 1][j - 1] + 2;
            else
                L[i][j] = max(L[i][j - 1], L[i + 1][j]);
        }
    }

    return L[0][n - 1];
}

int main()
{
    char seq[] = "GEEKS FOR GEEKS";
    int n = strlen(seq);
    printf("The length of the LPS is %d", lps(seq));
    getchar();
    return 0;
}*/
/*// Count All Palindromic Subsequence in a given String
#include <bits/stdc++.h>
using namespace std;
int n, dp[1000][1000];
string str = "abcb";

int countPS(int i, int j)
{
    if (i > j)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    if (i == j)
        return dp[i][j] = 1;

    else if (str[i] == str[j])
        return dp[i][j] = countPS(i + 1, j) +
                          countPS(i, j - 1) + 1;

    else
        return dp[i][j] = countPS(i + 1, j) +
                          countPS(i, j - 1) -
                          countPS(i + 1, j - 1);
}

int main()
{
    memset(dp, -1, sizeof(dp));
    n = str.size();
    cout << "Total palindromic subsequence are : "
         << countPS(0, n - 1) << endl;
    return 0;
}*/
/*// Longest Palindromic Substring
#include <bits/stdc++.h>
using namespace std;
void printSubStr(
    string str, int low, int high)
{
    for (int i = low; i <= high; ++i)
        cout << str[i];
}
int longestPalSubstr(string str)
{
    int n = str.size();

    bool table[n][n];

    memset(table, 0, sizeof(table));

    int maxLength = 1;

    for (int i = 0; i < n; ++i)
        table[i][i] = true;

    int start = 0;
    for (int i = 0; i < n - 1; ++i)
    {
        if (str[i] == str[i + 1])
        {
            table[i][i + 1] = true;
            start = i;
            maxLength = 2;
        }
    }

    for (int k = 3; k <= n; ++k)
    {
        for (int i = 0; i < n - k + 1; ++i)
        {
            int j = i + k - 1;

            if (table[i + 1][j - 1] && str[i] == str[j])
            {
                table[i][j] = true;

                if (k > maxLength)
                {
                    start = i;
                    maxLength = k;
                }
            }
        }
    }

    cout << "Longest palindrome substring is: ";
    printSubStr(str, start, start + maxLength - 1);

    return maxLength;
}
int main()
{
    string str = "forgeeksskeegfor";
    cout << "\nLength is: "
         << longestPalSubstr(str);
    return 0;
}*/
/*// Longest alternating subsequence
#include <bits/stdc++.h>
using namespace std;
int LAS(int arr[], int n)
{
    int inc = 1;
    int dec = 1;

    for (int i = 1; i < n; i++)
    {
        if (arr[i] > arr[i - 1])
        {
            inc = dec + 1;
        }
        else if (arr[i] < arr[i - 1])
        {
            dec = inc + 1;
        }
    }
    return max(inc, dec);
}
int main()
{
    int arr[] = {10, 22, 9, 33, 49,
                 50, 31, 60};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << LAS(arr, n) << endl;
    return 0;
}*/
/*// Weighted Job Scheduling
#include <bits/stdc++.h>
using namespace std;
struct Job
{
    int start, finish, profit;
};

bool jobComparataor(Job s1, Job s2)
{
    return (s1.finish < s2.finish);
}

int latestNonConflict(Job arr[], int i)
{
    for (int j = i - 1; j >= 0; j--)
    {
        if (arr[j].finish <= arr[i].start)
            return j;
    }
    return -1;
}
int findMaxProfit(Job arr[], int n)
{
    sort(arr, arr + n, jobComparataor);
    int *table = new int[n];
    table[0] = arr[0].profit;

    for (int i = 1; i < n; i++)
    {
        int inclProf = arr[i].profit;
        int l = latestNonConflict(arr, i);
        if (l != -1)
            inclProf += table[l];
        table[i] = max(inclProf, table[i - 1]);
    }

    int result = table[n - 1];
    delete[] table;

    return result;
}

int main()
{
    Job arr[] = {{3, 10, 20}, {1, 2, 50}, {6, 19, 100}, {2, 100, 200}};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "The optimal profit is " << findMaxProfit(arr, n);
    return 0;
}*/
/*// Coin game winner where every player has three choices
#include <bits/stdc++.h>
using namespace std;

bool findWinner(int x, int y, int n)
{
    int dp[n + 1];
    dp[0] = false;
    dp[1] = true;
    for (int i = 2; i <= n; i++)
    {
        if (i - 1 >= 0 and !dp[i - 1])
            dp[i] = true;
        else if (i - x >= 0 and !dp[i - x])
            dp[i] = true;
        else if (i - y >= 0 and !dp[i - y])
            dp[i] = true;

        // Else A loses game.
        else
            dp[i] = false;
    }

    return dp[n];
}

int main()
{
    int x = 3, y = 4, n = 5;
    if (findWinner(x, y, n))
        cout << 'A';
    else
        cout << 'B';
    return 0;
}*/
/*// Count Derangements (Permutation such that no element appears in its original position) [ IMPORTANT ]
#include <bits/stdc++.h>
using namespace std;
int countDer(int n)
{
    int der[n + 1] = {0};

    der[1] = 0;
    der[2] = 1;

    for (int i = 3; i <= n; ++i)
        der[i] = (i - 1) * (der[i - 1] +
                            der[i - 2]);
    return der[n];
}
int main()
{
    int n = 4;
    cout << "Count of Derangements is "
         << countDer(n);
    return 0;
}*/
/*// Maximum profit by buying and selling a share at most twice [ IMP ]
#include <iostream>
using namespace std;
int main()
{
    int price[] = {2, 30, 15, 10, 8, 25, 80};
    int n = 7;
    int profit = 0;
    for (int i = 1; i < n; i++)
    {
        int sub = price[i] - price[i - 1];
        if (sub > 0)
            profit += sub;
    }

    cout << "Maximum Profit=" << profit;
    return 0;
}*/
/*// Optimal Strategy for a Game
#include <bits/stdc++.h>
using namespace std;
int optimalStrategyOfGame(int *arr, int n)
{
    int table[n][n];
    for (int gap = 0; gap < n; ++gap)
    {
        for (int i = 0, j = gap; j < n; ++i, ++j)
        {
            int x = ((i + 2) <= j) ? table[i + 2][j] : 0;
            int y = ((i + 1) <= (j - 1)) ? table[i + 1][j - 1] : 0;
            int z = (i <= (j + 2)) ? table[i][j + 2] : 0;
            table[i][j] = max(arr[i] + min(x, y), arr[j] + min(y, z));
        }
    }
    return table[0][n - 1];
}

int main()
{
    int arr1[] = {8, 15, 3, 7};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    printf("%d\n",
           optimalStrategyOfGame(arr1, n));

    int arr2[] = {2, 2, 2, 2};
    n = sizeof(arr2) / sizeof(arr2[0]);
    printf("%d\n",
           optimalStrategyOfGame(arr2, n));

    int arr3[] = {20, 30, 2, 2, 2, 10};
    n = sizeof(arr3) / sizeof(arr3[0]);
    printf("%d\n",
           optimalStrategyOfGame(arr3, n));
    return 0;
}*/
/*// Optimal Binary Search Tree
#include <bits/stdc++.h>
using namespace std;
int sum(int freq[], int i, int j);
int optimalSearchTree(int keys[], int freq[], int n)
{
    int cost[n][n];

    for (int i = 0; i < n; i++)
        cost[i][i] = freq[i];

    for (int L = 2; L <= n; L++)
    {
        for (int i = 0; i <= n - L + 1; i++)
        {
            int j = i + L - 1;
            cost[i][j] = INT_MAX;
            for (int r = i; r <= j; r++)
            {
                int c = ((r > i) ? cost[i][r - 1] : 0) +
                        ((r < j) ? cost[r + 1][j] : 0) +
                        sum(freq, i, j);
                if (c < cost[i][j])
                    cost[i][j] = c;
            }
        }
    }
    return cost[0][n - 1];
}

int sum(int freq[], int i, int j)
{
    int s = 0;
    for (int k = i; k <= j; k++)
        s += freq[k];
    return s;
}

int main()
{
    int keys[] = {10, 12, 20};
    int freq[] = {34, 8, 50};
    int n = sizeof(keys) / sizeof(keys[0]);
    cout << "Cost of Optimal BST is " << optimalSearchTree(keys, freq, n);
    return 0;
}*/
/*// Palindrome PartitioningProblem
#include <bits/stdc++.h>
using namespace std;
int min(int a, int b) { return (a < b) ? a : b; }
int minPalPartion(char *str)
{
    int n = strlen(str);
    int C[n];
    bool P[n][n];
    int i, j, k, L;
    for (i = 0; i < n; i++)
    {
        P[i][i] = true;
    }
    for (L = 2; L <= n; L++)
    {
        for (i = 0; i < n - L + 1; i++)
        {
            j = i + L - 1;
            if (L == 2)
                P[i][j] = (str[i] == str[j]);
            else
                P[i][j] = (str[i] == str[j]) && P[i + 1][j - 1];
        }
    }
    for (i = 0; i < n; i++)
    {
        if (P[0][i] == true)
            C[i] = 0;
        else
        {
            C[i] = INT_MAX;
            for (j = 0; j < i; j++)
            {
                if (P[j + 1][i] == true && 1 + C[j] < C[i])
                    C[i] = 1 + C[j];
            }
        }
    }
    return C[n - 1];
}

int main()
{
    char str[] = "ababbbabbababa";
    printf("Min cuts needed for Palindrome Partitioning is %d",
           minPalPartion(str));
    return 0;
}*/
/*// Word Wrap Problem
#include <bits/stdc++.h>
using namespace std;
#define INF INT_MAX
int printSolution(int p[], int n);
void solveWordWrap(int l[], int n, int M)
{
    int extras[n + 1][n + 1];
    int lc[n + 1][n + 1]; // lc[i][j] will have cost of a line
    int c[n + 1];         // c[i] will have total cost
    int p[n + 1];         // p[] is used to print the solution
    int i, j;

    for (i = 0; i <= n; i++)
    {
        extras[i][i] = M - l[i - 1];
        for (j = i + 1; j <= n; j++)
            extras[i][j] = extras[i][j - 1] - extras[i - 1][j] - 1;
    }

    for (i = 0; i <= n; i++)
    {
        for (j = i; j <= n; j++)
        {
            if (extras[i][j] < 0)
                lc[i][j] = INF;
            else if (j == n && extras[i][j] >= 0)
                lc[i][j] = 0;
            else
                lc[i][j] = extras[i][j] * extras[i][j];
        }
    }

    c[0] = 0;
    for (j = 1; j <= n; j++)
    {
        c[j] = INF;
        for (i = 1; i <= j; i++)
        {
            if (c[i - 1] != INF && lc[i][j] != INF &&
                (c[i - 1] + lc[i][j] < c[j]))
            {
                c[j] = c[i - 1] + lc[i][j];
                p[j] = i;
            }
        }
    }
    printSolution(p, n);
}

int printSolution(int p[], int n)
{
    int k;
    if (p[n] == 1)
        k = 1;
    else
        k = printSolution(p, p[n] - 1) + 1;
    cout << "Line number " << k << ": From word no. " << p[n] << " to " << n << endl;
    return k;
}

int main()
{
    int l[] = {3, 2, 2, 5};
    int n = sizeof(l) / sizeof(l[0]);
    int M = 6;
    solveWordWrap(l, n, M);
    return 0;
}*/
/*// Mobile Numeric Keypad Problem [ IMP ]
#include <bits/stdc++.h>
using namespace std;

int getCount(char keypad[][3], int n)
{
    if (keypad == NULL || n <= 0)
        return 0;
    if (n == 1)
        return 10;

    int odd[10], even[10];
    int i = 0, j = 0, useOdd = 0, totalCount = 0;

    for (i = 0; i <= 9; i++)
        odd[i] = 1;

    for (j = 2; j <= n; j++)
    {
        useOdd = 1 - useOdd;
        if (useOdd == 1)
        {
            even[0] = odd[0] + odd[8];
            even[1] = odd[1] + odd[2] + odd[4];
            even[2] = odd[2] + odd[1] + odd[3] + odd[5];
            even[3] = odd[3] + odd[2] + odd[6];
            even[4] = odd[4] + odd[1] + odd[5] + odd[7];
            even[5] = odd[5] + odd[2] + odd[4] + odd[8] + odd[6];
            even[6] = odd[6] + odd[3] + odd[5] + odd[9];
            even[7] = odd[7] + odd[4] + odd[8];
            even[8] = odd[8] + odd[0] + odd[5] + odd[7] + odd[9];
            even[9] = odd[9] + odd[6] + odd[8];
        }
        else
        {
            odd[0] = even[0] + even[8];
            odd[1] = even[1] + even[2] + even[4];
            odd[2] = even[2] + even[1] + even[3] + even[5];
            odd[3] = even[3] + even[2] + even[6];
            odd[4] = even[4] + even[1] + even[5] + even[7];
            odd[5] = even[5] + even[2] + even[4] + even[8] + even[6];
            odd[6] = even[6] + even[3] + even[5] + even[9];
            odd[7] = even[7] + even[4] + even[8];
            odd[8] = even[8] + even[0] + even[5] + even[7] + even[9];
            odd[9] = even[9] + even[6] + even[8];
        }
    }

    totalCount = 0;
    if (useOdd == 1)
    {
        for (i = 0; i <= 9; i++)
            totalCount += even[i];
    }
    else
    {
        for (i = 0; i <= 9; i++)
            totalCount += odd[i];
    }
    return totalCount;
}

int main()
{
    char keypad[4][3] = {{'1', '2', '3'},
                         {'4', '5', '6'},
                         {'7', '8', '9'},
                         {'*', '0', '#'}};
    cout << "Count for numbers of length 1: " << getCount(keypad, 1) << endl;
    cout << "Count for numbers of length 2: " << getCount(keypad, 2) << endl;
    cout << "Count for numbers of length 3: " << getCount(keypad, 3) << endl;
    cout << "Count for numbers of length 4: " << getCount(keypad, 4) << endl;
    cout << "Count for numbers of length 5: " << getCount(keypad, 5) << endl;

    return 0;
}*/
/*// Boolean Parenthesization Problem
#include <bits/stdc++.h>
using namespace std;

int dp[101][101][2];
int parenthesis_count(string s,
                      int i,
                      int j,
                      int isTrue)
{
    // Base Condition
    if (i > j)
        return false;
    if (i == j)
    {
        if (isTrue == 1)
            return s[i] == 'T';
        else
            return s[i] == 'F';
    }

    if (dp[i][j][isTrue] != -1)
        return dp[i][j][isTrue];
    int ans = 0;
    for (int k = i + 1; k <= j - 1; k = k + 2)
    {
        int leftF, leftT, rightT, rightF;
        if (dp[i][k - 1][1] == -1)
        {
            leftT = parenthesis_count(s, i, k - 1, 1);
        } // Count no. of T in left partition
        else
        {
            leftT = dp[i][k - 1][1];
        }

        if (dp[k + 1][j][1] == -1)
        {
            rightT = parenthesis_count(s, k + 1, j, 1);
        } // Count no. of T in right partition
        else
        {
            rightT = dp[k + 1][j][1];
        }

        if (dp[i][k - 1][0] == -1)
        {
            // Count no. of F in left partition
            leftF = parenthesis_count(s, i, k - 1, 0);
        }
        else
        {
            leftF = dp[i][k - 1][0];
        }

        if (dp[k + 1][j][0] == -1)
        {
            // Count no. of F in right partition
            rightF = parenthesis_count(s, k + 1, j, 0);
        }
        else
        {
            rightF = dp[k + 1][j][0];
        }

        if (s[k] == '&')
        {
            if (isTrue == 1)
                ans += leftT * rightT;
            else
                ans += leftF * rightF + leftT * rightF + leftF * rightT;
        }
        else if (s[k] == '|')
        {
            if (isTrue == 1)
                ans += leftT * rightT + leftT * rightF + leftF * rightT;
            else
                ans = ans + leftF * rightF;
        }
        else if (s[k] == '^')
        {
            if (isTrue == 1)
                ans = ans + leftF * rightT + leftT * rightF;
            else
                ans = ans + leftT * rightT + leftF * rightF;
        }
        dp[i][j][isTrue] = ans;
    }
    return ans;
}

// Driver Code
int main()
{
    string symbols = "TTFT";
    string operators = "|&^";
    string s;
    int j = 0;

    for (int i = 0; i < symbols.length(); i++)
    {
        s.push_back(symbols[i]);
        if (j < operators.length())
            s.push_back(operators[j++]);
    }

    // We obtain the string T|T&F^T
    int n = s.length();

    // There are 4 ways
    // ((T|T)&(F^T)), (T|(T&(F^T))), (((T|T)&F)^T) and
    // (T|((T&F)^T))
    memset(dp, -1, sizeof(dp));
    cout << parenthesis_count(s, 0, n - 1, 1);
    return 0;
}*/
/*// Largest rectangular sub-matrix whose sum is 0
#include <bits/stdc++.h>
using namespace std;

const int MAX = 100;

// This function basically finds largest 0
// sum subarray in temp[0..n-1]. If 0 sum
// does't exist, then it returns false. Else
// it returns true and sets starting and
// ending indexes as starti and endj.
bool sumZero(int temp[], int *starti,
             int *endj, int n)
{
    // Map to store the previous sums
    map<int, int> presum;
    int sum = 0; // Initialize sum of elements

    // Initialize length of sub-array with sum 0
    int max_length = 0;

    // Traverse through the given array
    for (int i = 0; i < n; i++)
    {
        // Add current element to sum
        sum += temp[i];

        if (temp[i] == 0 && max_length == 0)
        {
            *starti = i;
            *endj = i;
            max_length = 1;
        }
        if (sum == 0)
        {
            if (max_length < i + 1)
            {
                *starti = 0;
                *endj = i;
            }
            max_length = i + 1;
        }

        // Look for this sum in Hash table
        if (presum.find(sum) != presum.end())
        {
            // store previous max_length so
            // that we can check max_length
            // is updated or not
            int old = max_length;

            // If this sum is seen before,
            // then update max_len
            max_length = max(max_length, i - presum[sum]);

            if (old < max_length)
            {
                // If max_length is updated then
                // enter and update start and end
                // point of array
                *endj = i;
                *starti = presum[sum] + 1;
            }
        }
        else

            // Else insert this sum with
            // index in hash table
            presum[sum] = i;
    }

    // Return true if max_length is non-zero
    return (max_length != 0);
}

// The main function that finds Largest rectangle
// sub-matrix in a[][] whose sum is 0.
void sumZeroMatrix(int a[][MAX], int row, int col)
{
    int temp[row];

    // Variables to store the final output
    int fup = 0, fdown = 0, fleft = 0, fright = 0;
    int sum;
    int up, down;
    int maxl = INT_MIN;

    // Set the left column
    for (int left = 0; left < col; left++)
    {
        // Initialize all elements of temp as 0
        memset(temp, 0, sizeof(temp));

        // Set the right column for the left column
        // set by outer loop
        for (int right = left; right < col; right++)
        {
            // Calculate sum between current left
            // and right for every row 'i'
            for (int i = 0; i < row; i++)
                temp[i] += a[i][right];

            // Find largest subarray with 0 sum in
            // temp[]. The sumZero() function also
            // sets values of start and finish. So
            // 'sum' is sum of rectangle between (start,
            // left) and (finish, right) which is
            // boundary columns strictly as left and right.
            bool sum = sumZero(temp, &up, &down, row);
            int ele = (down - up + 1) * (right - left + 1);

            // Compare no. of elements with previous
            // no. of elements in sub-Matrix.
            // If new sub-matrix has more elements
            // then update maxl and final boundaries
            // like fup, fdown, fleft, fright
            if (sum && ele > maxl)
            {
                fup = up;
                fdown = down;
                fleft = left;
                fright = right;
                maxl = ele;
            }
        }
    }

    // If there is no change in boundaries
    // than check if a[0][0] is 0
    // If it not zero then print
    // that no such zero-sum sub-matrix exists
    if (fup == 0 && fdown == 0 && fleft == 0 &&
        fright == 0 && a[0][0] != 0)
    {
        cout << "No zero-sum sub-matrix exists";
        return;
    }

    // Print final values
    for (int j = fup; j <= fdown; j++)
    {
        for (int i = fleft; i <= fright; i++)
            cout << a[j][i] << " ";
        cout << endl;
    }
}

// Driver program to test above functions
int main()
{
    int a[][MAX] = {{9, 7, 16, 5}, {1, -6, -7, 3}, {1, 8, 7, 9}, {7, -2, 0, 10}};

    int row = 4, col = 4;
    sumZeroMatrix(a, row, col);
    return 0;
}*/
/*// Largest area rectangular sub-matrix with equal number of 1’s and 0’s [ IMP ]
#include <bits/stdc++.h>

using namespace std;

#define MAX_ROW 10
#define MAX_COL 10

// This function basically finds largest 0
// sum subarray in arr[0..n-1]. If 0 sum
// does't exist, then it returns false. Else
// it returns true and sets starting and
// ending indexes as start and end.
bool subArrWithSumZero(int arr[], int &start,
                       int &end, int n)
{
    // to store cumulative sum
    int sum[n];

    // Initialize all elements of sum[] to 0
    memset(sum, 0, sizeof(sum));

    // map to store the indexes of sum
    unordered_map<int, int> um;

    // build up the cumulative sum[] array
    sum[0] = arr[0];
    for (int i = 1; i < n; i++)
        sum[i] = sum[i - 1] + arr[i];

    // to store the maximum length subarray
    // with sum equal to 0
    int maxLen = 0;

    // traverse to the sum[] array
    for (int i = 0; i < n; i++)
    {
        // if true, then there is a subarray
        // with sum equal to 0 from the
        // beginning up to index 'i'
        if (sum[i] == 0)
        {
            // update the required variables
            start = 0;
            end = i;
            maxLen = (i + 1);
        }

        // else if true, then sum[i] has not
        // seen before in 'um'
        else if (um.find(sum[i]) == um.end())
            um[sum[i]] = i;

        // sum[i] has been seen before in the
        // unordered_map 'um'
        else
        {
            // if previous subarray length is smaller
            // than the current subarray length, then
            // update the required variables
            if (maxLen < (i - um[sum[i]]))
            {
                maxLen = (i - um[sum[i]]);
                start = um[sum[i]] + 1;
                end = i;
            }
        }
    }

    // if true, then there is no
    // subarray with sum equal to 0
    if (maxLen == 0)
        return false;

    // else return true
    return true;
}

// function to find largest area rectangular
// submatrix with equal number of 1's and 0's
void maxAreaRectWithSumZero(int mat[MAX_ROW][MAX_COL],
                            int row, int col)
{
    // to store intermediate values
    int temp[row], startRow, endRow;

    // to store the final outputs
    int finalLeft, finalRight, finalTop, finalBottom;
    finalLeft = finalRight = finalTop = finalBottom = -1;
    int maxArea = 0;

    // Set the left column
    for (int left = 0; left < col; left++)
    {
        // Initialize all elements of temp as 0
        memset(temp, 0, sizeof(temp));

        // Set the right column for the left column
        // set by outer loop
        for (int right = left; right < col; right++)
        {
            // Calculate sum between current left
            // and right for every row 'i'
            // consider value '1' as '1' and
            // value '0' as '-1'
            for (int i = 0; i < row; i++)
                temp[i] += mat[i][right] ? 1 : -1;

            // Find largest subarray with 0 sum in
            // temp[]. The subArrWithSumZero() function
            // also sets values of finalTop, finalBottom,
            // finalLeft and finalRight if there exists
            // a subarray with sum 0 in temp
            if (subArrWithSumZero(temp, startRow, endRow, row))
            {
                int area = (right - left + 1) *
                           (endRow - startRow + 1);

                // Compare current 'area' with previous area
                // and accodingly update final values
                if (maxArea < area)
                {
                    finalTop = startRow;
                    finalBottom = endRow;
                    finalLeft = left;
                    finalRight = right;
                    maxArea = area;
                }
            }
        }
    }

    // if true then there is no rectangular submatrix
    // with equal number of 1's and 0's
    if (maxArea == 0)
        cout << "No such rectangular submatrix exists:";

    // displaying the top left and bottom right boundaries
    // with the area of the rectangular submatrix
    else
    {
        cout << "(Top, Left): "
             << "(" << finalTop << ", " << finalLeft
             << ")" << endl;

        cout << "(Bottom, Right): "
             << "(" << finalBottom << ", " << finalRight
             << ")" << endl;

        cout << "Area: " << maxArea << " sq.units";
    }
}

// Driver program to test above
int main()
{
    int mat[MAX_ROW][MAX_COL] = {{0, 0, 1, 1},
                                 {0, 1, 1, 0},
                                 {1, 1, 1, 0},
                                 {1, 0, 0, 1}};
    int row = 4, col = 4;
    maxAreaRectWithSumZero(mat, row, col);
    return 0;
}*/
/*// Maximum sum rectangle in a 2D matrix
#include <bits/stdc++.h>
using namespace std;

#define ROW 4
#define COL 5

// Implementation of Kadane's algorithm for
// 1D array. The function returns the maximum
// sum and stores starting and ending indexes
// of the maximum sum subarray at addresses
// pointed by start and finish pointers
// respectively.
int kadane(int* arr, int* start, int* finish, int n)
{
	// initialize sum, maxSum and
	int sum = 0, maxSum = INT_MIN, i;

	// Just some initial value to check
	// for all negative values case
	*finish = -1;

	// local variable
	int local_start = 0;

	for (i = 0; i < n; ++i)
	{
		sum += arr[i];
		if (sum < 0)
		{
			sum = 0;
			local_start = i + 1;
		}
		else if (sum > maxSum)
		{
			maxSum = sum;
			*start = local_start;
			*finish = i;
		}
	}

	// There is at-least one
	// non-negative number
	if (*finish != -1)
		return maxSum;

	// Special Case: When all numbers
	// in arr[] are negative
	maxSum = arr[0];
	*start = *finish = 0;

	// Find the maximum element in array
	for (i = 1; i < n; i++)
	{
		if (arr[i] > maxSum)
		{
			maxSum = arr[i];
			*start = *finish = i;
		}
	}
	return maxSum;
}

// The main function that finds
// maximum sum rectangle in M[][]
void findMaxSum(int M[][COL])
{
	// Variables to store the final output
	int maxSum = INT_MIN,
				finalLeft,
				finalRight,
				finalTop,
				finalBottom;

	int left, right, i;
	int temp[ROW], sum, start, finish;

	// Set the left column
	for (left = 0; left < COL; ++left) {
		// Initialize all elements of temp as 0
		memset(temp, 0, sizeof(temp));

		// Set the right column for the left
		// column set by outer loop
		for (right = left; right < COL; ++right) {

			// Calculate sum between current left
			// and right for every row 'i'
			for (i = 0; i < ROW; ++i)
				temp[i] += M[i][right];

			// Find the maximum sum subarray in temp[].
			// The kadane() function also sets values
			// of start and finish. So 'sum' is sum of
			// rectangle between (start, left) and
			// (finish, right) which is the maximum sum
			// with boundary columns strictly as left
			// and right.
			sum = kadane(temp, &start, &finish, ROW);

			// Compare sum with maximum sum so far.
			// If sum is more, then update maxSum and
			// other output values
			if (sum > maxSum) {
				maxSum = sum;
				finalLeft = left;
				finalRight = right;
				finalTop = start;
				finalBottom = finish;
			}
		}
	}

	// Print final values
	cout << "(Top, Left) ("
		<< finalTop << ", "
		<< finalLeft
		<< ")" << endl;
	cout << "(Bottom, Right) ("
		<< finalBottom << ", "
		<< finalRight << ")" << endl;
	cout << "Max sum is: " << maxSum << endl;
}

// Driver Code
int main()
{
	int M[ROW][COL] = { { 1, 2, -1, -4, -20 },
						{ -8, -3, 4, 2, 1 },
						{ 3, 8, 10, 1, 3 },
						{ -4, -1, 1, 7, -6 } };

	// Function call
	findMaxSum(M);

	return 0;
}*/
/*// Maximum profit by buying and selling a share at most k times
#include <bits/stdc++.h>
using namespace std;

int maxProfit(int price[], int n, int k)
{
    int profit[k + 1][n + 1];
    for (int i = 0; i <= k; i++)
        profit[i][0] = 0;

    for (int j = 0; j <= n; j++)
        profit[0][j] = 0;

    for (int i = 1; i <= k; i++)
    {
        int prevDiff = INT_MIN;
        for (int j = 1; j < n; j++)
        {
            prevDiff = max(prevDiff,
                           profit[i - 1][j - 1] - price[j - 1]);
            profit[i][j] = max(profit[i][j - 1],
                               price[j] + prevDiff);
        }
    }
    return profit[k][n - 1];
}
int main()
{
    int k = 3;
    int price[] = {12, 14, 17, 10, 14, 13, 12, 15};

    int n = sizeof(price) / sizeof(price[0]);
    cout << "Maximum profit is: "
         << maxProfit(price, n, k);
    return 0;
}*/
/*// Find if a string is interleaved of two other strings
#include <iostream>
#include <string.h>
using namespace std;

// The main function that
// returns true if C is
// an interleaving of A
// and B, otherwise false.
bool isInterleaved(
    char *A, char *B, char *C)
{
    // Find lengths of the two strings
    int M = strlen(A), N = strlen(B);

    // Let us create a 2D table
    // to store solutions of
    // subproblems. C[i][j] will
    // be true if C[0..i+j-1]
    // is an interleaving of
    // A[0..i-1] and B[0..j-1].
    bool IL[M + 1][N + 1];

    // Initialize all values as false.
    memset(IL, 0, sizeof(IL));

    // C can be an interleaving of
    // A and B only of the sum
    // of lengths of A & B is equal
    // to the length of C.
    if ((M + N) != strlen(C))
        return false;

    // Process all characters of A and B
    for (int i = 0; i <= M; ++i)
    {
        for (int j = 0; j <= N; ++j)
        {
            // two empty strings have an
            // empty string as interleaving
            if (i == 0 && j == 0)
                IL[i][j] = true;

            // A is empty
            else if (i == 0)
            {
                if (B[j - 1] == C[j - 1])
                    IL[i][j] = IL[i][j - 1];
            }

            // B is empty
            else if (j == 0)
            {
                if (A[i - 1] == C[i - 1])
                    IL[i][j] = IL[i - 1][j];
            }

            // Current character of C matches
            // with current character of A,
            // but doesn't match with current
            // character of B
            else if (
                A[i - 1] == C[i + j - 1] && B[j - 1] != C[i + j - 1])
                IL[i][j] = IL[i - 1][j];

            // Current character of C matches
            // with current character of B,
            // but doesn't match with current
            // character of A
            else if (
                A[i - 1] != C[i + j - 1] && B[j - 1] == C[i + j - 1])
                IL[i][j] = IL[i][j - 1];

            // Current character of C matches
            // with that of both A and B
            else if (
                A[i - 1] == C[i + j - 1] && B[j - 1] == C[i + j - 1])
                IL[i][j] = (IL[i - 1][j] || IL[i][j - 1]);
        }
    }

    return IL[M][N];
}

// A function to run test cases
void test(char *A, char *B, char *C)
{
    if (isInterleaved(A, B, C))
        cout << C << " is interleaved of "
             << A << " and " << B << endl;
    else
        cout << C << " is not interleaved of "
             << A << " and " << B << endl;
}

// Driver program to test above functions
int main()
{
    test("XXY", "XXZ", "XXZXXXY");
    test("XY", "WZ", "WZXY");
    test("XY", "X", "XXY");
    test("YX", "X", "XXY");
    test("XXY", "XXZ", "XXXXZY");
    return 0;
}*/
/*// Maximum Length of Pair Chain
DP 720*/