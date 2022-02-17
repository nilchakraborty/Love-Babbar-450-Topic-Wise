/*// Rat in a maze Problem
#include <bits/stdc++.h>
#define MAX 5
using namespace std;
bool isSafe(int row, int col, int m[][MAX], int n, bool visited[][MAX])
{
    if (row == -1 || row == n || col == -1 || col == n || visited[row][col] ||
        m[row][col] == 0)
        return false;
    return true;
}
void printPathUtil(int row, int col, int m[][MAX], int n,
                   string &path, vector<string> &possiblePaths, bool visited[][MAX])
{
    if (row == -1 || row == n || col == -1 || col == n || visited[row][col] || m[row][col] == 0)
        return;
    if (row == n - 1 && col == n - 1)
    {
        possiblePaths.push_back(path);
        return;
    }
    visited[row][col] = true;
    if (isSafe(row + 1, col, m, n, visited))
    {
        path.push_back('D');
        printPathUtil(row + 1, col, m, n, path, possiblePaths, visited);
        path.pop_back();
    }
    if (isSafe(row, col - 1, m, n, visited))
    {
        path.push_back('L');
        printPathUtil(row, col - 1, m, n, path, possiblePaths, visited);
        path.pop_back();
    }
    if (isSafe(row, col + 1, m, n, visited))
    {
        path.push_back('R');
        printPathUtil(row, col + 1, m, n, path, possiblePaths, visited);
        path.pop_back();
    }
    if (isSafe(row - 1, col, m, n, visited))
    {
        path.push_back('U');
        printPathUtil(row - 1, col, m, n, path, possiblePaths, visited);
        path.pop_back();
    }
    visited[row][col] = false;
}
void printPath(int m[MAX][MAX], int n)
{
    vector<string> possiblePaths;
    string path;
    bool visited[n][MAX];
    memset(visited, false, sizeof(visited));
    printPathUtil(0, 0, m, n, path, possiblePaths, visited);
    for (int i = 0; i < possiblePaths.size(); i++)
        cout << possiblePaths[i] << " ";
}
int main()
{
    int m[MAX][MAX] = {{1, 0, 0, 0, 0},
                       {1, 1, 1, 1, 1},
                       {1, 1, 1, 0, 1},
                       {0, 0, 0, 0, 1},
                       {0, 0, 0, 0, 1}};
    int n = sizeof(m) / sizeof(m[0]);
    printPath(m, n);
    return 0;
}*/
/*// Printing all solutions in N-Queen Problem
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> result;
bool isSafe(vector<vector<int>> board,
            int row, int col)
{
    int i, j;
    int N = board.size();
    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;
    for (i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j])
            return false;

    return true;
}
bool solveNQUtil(vector<vector<int>> &board, int col)
{
    int N = board.size();
    if (col == N)
    {
        vector<int> v;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (board[i][j] == 1)
                    v.push_back(j + 1);
            }
        }
        result.push_back(v);
        return true;
    }
    bool res = false;
    for (int i = 0; i < N; i++)
    {
        if (isSafe(board, i, col))
        {
            board[i][col] = 1;
            res = solveNQUtil(board, col + 1) || res;
            board[i][col] = 0;
        }
    }
    return res;
}
vector<vector<int>> nQueen(int n)
{
    result.clear();
    vector<vector<int>> board(n, vector<int>(n, 0));

    if (solveNQUtil(board, 0) == false)
    {
        return {};
    }

    sort(result.begin(), result.end());
    return result;
}
int main()
{
    int n = 4;
    vector<vector<int>> v = nQueen(n);

    for (auto ar : v)
    {
        cout << "[";
        for (auto it : ar)
            cout << it << " ";
        cout << "]";
    }

    return 0;
}*/
/*// Word Break Problem using Backtracking
same as string 469*/
/*// Remove Invalid Parentheses
#include <bits/stdc++.h>
using namespace std;
bool isParenthesis(char c)
{
    return ((c == '(') || (c == ')'));
}
bool isValidString(string str)
{
    int cnt = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '(')
            cnt++;
        else if (str[i] == ')')
            cnt--;
        if (cnt < 0)
            return false;
    }
    return (cnt == 0);
}
void removeInvalidParenthesis(string str)
{
    if (str.empty())
        return;
    set<string> visit;
    queue<string> q;
    string temp;
    bool level;
    q.push(str);
    visit.insert(str);
    while (!q.empty())
    {
        str = q.front();
        q.pop();
        if (isValidString(str))
        {
            cout << str << endl;
            level = true;
        }
        if (level)
            continue;
        for (int i = 0; i < str.length(); i++)
        {
            if (!isParenthesis(str[i]))
                continue;
            temp = str.substr(0, i) + str.substr(i + 1);
            if (visit.find(temp) == visit.end())
            {
                q.push(temp);
                visit.insert(temp);
            }
        }
    }
}
int main()
{
    string expression = "()())()";
    removeInvalidParenthesis(expression);

    expression = "()v)";
    removeInvalidParenthesis(expression);

    return 0;
}*/
/*// Sudoku Solver
#include <bits/stdc++.h>
using namespace std;
#define N 9
void print(int arr[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
}
bool isSafe(int grid[N][N], int row, int col, int num)
{
    for (int x = 0; x <= 8; x++)
        if (grid[row][x] == num)
            return false;
    for (int x = 0; x <= 8; x++)
        if (grid[x][col] == num)
            return false;
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (grid[i + startRow][j + startCol] == num)
                return false;
    return true;
}
bool solveSuduko(int grid[N][N], int row, int col)
{
    if (row == N - 1 && col == N)
        return true;
    if (col == N)
    {
        row++;
        col = 0;
    }
    if (grid[row][col] > 0)
        return solveSuduko(grid, row, col + 1);
    for (int num = 1; num <= N; num++)
    {
        if (isSafe(grid, row, col, num))
        {
            grid[row][col] = num;
            if (solveSuduko(grid, row, col + 1))
                return true;
        }
        grid[row][col] = 0;
    }
    return false;
}
int main()
{
    int grid[N][N] = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
                      {5, 2, 0, 0, 0, 0, 0, 0, 0},
                      {0, 8, 7, 0, 0, 0, 0, 3, 1},
                      {0, 0, 3, 0, 1, 0, 0, 8, 0},
                      {9, 0, 0, 8, 6, 3, 0, 0, 5},
                      {0, 5, 0, 0, 9, 0, 6, 0, 0},
                      {1, 3, 0, 0, 0, 0, 2, 5, 0},
                      {0, 0, 0, 0, 0, 0, 0, 7, 4},
                      {0, 0, 5, 2, 0, 6, 3, 0, 0}};

    if (solveSuduko(grid, 0, 0))
        print(grid);
    else
        cout << "no solution  exists " << endl;
    return 0;
}*/
/*// m Coloring Problem
#include <bits/stdc++.h>
using namespace std;
#define V 4
void printSolution(int color[]);
bool isSafe(bool graph[V][V], int color[])
{
    for (int i = 0; i < V; i++)
        for (int j = i + 1; j < V; j++)
            if (graph[i][j] && color[j] == color[i])
                return false;
    return true;
}
bool graphColoring(bool graph[V][V], int m, int i,
                   int color[V])
{
    if (i == V)
    {
        if (isSafe(graph, color))
        {
            printSolution(color);
            return true;
        }
        return false;
    }
    for (int j = 1; j <= m; j++)
    {
        color[i] = j;
        if (graphColoring(graph, m, i + 1, color))
            return true;
        color[i] = 0;
    }
    return false;
}
void printSolution(int color[])
{
    cout << "Solution Exists:"
            " Following are the assigned colors \n";
    for (int i = 0; i < V; i++)
        cout << " " << color[i];
    cout << "\n";
}
int main()
{
    bool graph[V][V] = {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0},
    };
    int m = 3;
    int color[V];
    for (int i = 0; i < V; i++)
        color[i] = 0;

    if (!graphColoring(graph, m, 0, color))
        cout << "Solution does not exist";

    return 0;
}*/
/*// Print all palindromic partitions of a string
#include <bits/stdc++.h>
using namespace std;
bool isPalindrome(string str, int low, int high)
{
    while (low < high)
    {
        if (str[low] != str[high])
            return false;
        low++;
        high--;
    }
    return true;
}
void allPalPartUtil(vector<vector<string>> &allPart, vector<string> &currPart,
                    int start, int n, string str)
{
    if (start >= n)
    {
        allPart.push_back(currPart);
        return;
    }
    for (int i = start; i < n; i++)
    {
        if (isPalindrome(str, start, i))
        {
            currPart.push_back(str.substr(start, i - start + 1));
            allPalPartUtil(allPart, currPart, i + 1, n, str);
            currPart.pop_back();
        }
    }
}
void allPalPartitions(string str)
{
    int n = str.length();
    vector<vector<string>> allPart;
    vector<string> currPart;
    allPalPartUtil(allPart, currPart, 0, n, str);
    for (int i = 0; i < allPart.size(); i++)
    {
        for (int j = 0; j < allPart[i].size(); j++)
            cout << allPart[i][j] << " ";
        cout << "\n";
    }
}
int main()
{
    string str = "gekeg";
    allPalPartitions(str);
    return 0;
}*/
/*// Subset Sum Problem
#include <bits/stdc++.h>
using namespace std;
bool isSubsetSum(int set[], int n, int sum)
{
    if (sum == 0)
        return true;
    if (n == 0)
        return false;
    if (set[n - 1] > sum)
        return isSubsetSum(set, n - 1, sum);
    return isSubsetSum(set, n - 1, sum) 
    || isSubsetSum(set, n - 1, sum - set[n - 1]);
}

int main()
{
    int set[] = { 3, 34, 4, 12, 5, 2 };
    int sum = 9;
    int n = sizeof(set) / sizeof(set[0]);
    if (isSubsetSum(set, n, sum) == true)
        printf("Found a subset with given sum");
    else
        printf("No subset with given sum");
    return 0;
}*/
/*// The Knight’s tour problem
#include <bits/stdc++.h>
using namespace std;
#define N 8
int solveKTUtil(int x, int y, int movei, int sol[N][N],
                int xMove[], int yMove[]);
int isSafe(int x, int y, int sol[N][N])
{
    return (x >= 0 && x < N && y >= 0 && y < N && sol[x][y] == -1);
}
void printSolution(int sol[N][N])
{
    for (int x = 0; x < N; x++)
    {
        for (int y = 0; y < N; y++)
            cout << " " << setw(2) << sol[x][y] << " ";
        cout << endl;
    }
}
int solveKT()
{
    int sol[N][N];
    for (int x = 0; x < N; x++)
        for (int y = 0; y < N; y++)
            sol[x][y] = -1;
    int xMove[8] = {2, 1, -1, -2, -2, -1, 1, 2};
    int yMove[8] = {1, 2, 2, 1, -1, -2, -2, -1};
    sol[0][0] = 0;
    if (solveKTUtil(0, 0, 1, sol, xMove, yMove) == 0)
    {
        cout << "Solution does not exist";
        return 0;
    }
    else
        printSolution(sol);
    return 1;
}
int solveKTUtil(int x, int y, int movei, int sol[N][N],
                int xMove[N], int yMove[N])
{
    int k, next_x, next_y;
    if (movei == N * N)
        return 1;
    for (k = 0; k < 8; k++)
    {
        next_x = x + xMove[k];
        next_y = y + yMove[k];
        if (isSafe(next_x, next_y, sol))
        {
            sol[next_x][next_y] = movei;
            if (solveKTUtil(next_x, next_y, movei + 1, sol,
                            xMove, yMove) == 1)
                return 1;
            else
                sol[next_x][next_y] = -1;
        }
    }
    return 0;
}
int main()
{
    solveKT();
    return 0;
}*/
/*// Tug of War
#include <bits/stdc++.h>
using namespace std;
void TOWUtil(int *arr, int n, bool *curr_elements, int no_of_selected_elements,
             bool *soln, int *min_diff, int sum, int curr_sum, int curr_position)
{
    if (curr_position == n)
        return;
    if ((n / 2 - no_of_selected_elements) > (n - curr_position))
        return;
    TOWUtil(arr, n, curr_elements, no_of_selected_elements,
            soln, min_diff, sum, curr_sum, curr_position + 1);
    no_of_selected_elements++;
    curr_sum = curr_sum + arr[curr_position];
    curr_elements[curr_position] = true;
    if (no_of_selected_elements == n / 2)
    {
        if (abs(sum / 2 - curr_sum) < *min_diff)
        {
            *min_diff = abs(sum / 2 - curr_sum);
            for (int i = 0; i < n; i++)
                soln[i] = curr_elements[i];
        }
    }
    else
    {
        TOWUtil(arr, n, curr_elements, no_of_selected_elements, soln,
                min_diff, sum, curr_sum, curr_position + 1);
    }
    curr_elements[curr_position] = false;
}
void tugOfWar(int *arr, int n)
{
    bool *curr_elements = new bool[n];
    bool *soln = new bool[n];
    int min_diff = INT_MAX;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        curr_elements[i] = soln[i] = false;
    }
    TOWUtil(arr, n, curr_elements, 0, soln, &min_diff, sum, 0, 0);
    cout << "The first subset is: ";
    for (int i = 0; i < n; i++)
    {
        if (soln[i] == true)
            cout << arr[i] << " ";
    }
    cout << "\nThe second subset is: ";
    for (int i = 0; i < n; i++)
    {
        if (soln[i] == false)
            cout << arr[i] << " ";
    }
}
int main()
{
    int arr[] = {23, 45, -34, 12, 0, 98, -99, 4, 189, -1, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    tugOfWar(arr, n);
    return 0;
}*/
/*// Find shortest safe route in a path with landmines
#include <bits/stdc++.h>
using namespace std;
#define R 12
#define C 10
int rowNum[] = {-1, 0, 0, 1};
int colNum[] = {0, -1, 1, 0};
bool isSafe(int mat[R][C], int visited[R][C],
            int x, int y)
{
    if (mat[x][y] == 0 || visited[x][y])
        return false;
    return true;
}
bool isValid(int x, int y)
{
    if (x < R && y < C && x >= 0 && y >= 0)
        return true;
    return false;
}
void markUnsafeCells(int mat[R][C])
{
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (mat[i][j] == 0)
            {
                for (int k = 0; k < 4; k++)
                    if (isValid(i + rowNum[k], j + colNum[k]))
                        mat[i + rowNum[k]][j + colNum[k]] = -1;
            }
        }
    }
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (mat[i][j] == -1)
                mat[i][j] = 0;
        }
    }
}
void findShortestPathUtil(int mat[R][C], int visited[R][C],
                          int i, int j, int &min_dist, int dist)
{
    if (j == C - 1)
    {
        min_dist = min(dist, min_dist);
        return;
    }
    if (dist > min_dist)
        return;
    visited[i][j] = 1;
    for (int k = 0; k < 4; k++)
    {
        if (isValid(i + rowNum[k], j + colNum[k]) &&
            isSafe(mat, visited, i + rowNum[k], j + colNum[k]))
        {
            findShortestPathUtil(mat, visited, i + rowNum[k],
                                 j + colNum[k], min_dist, dist + 1);
        }
    }
    visited[i][j] = 0;
}
void findShortestPath(int mat[R][C])
{
    int min_dist = INT_MAX;
    int visited[R][C];
    markUnsafeCells(mat);
    for (int i = 0; i < R; i++)
    {
        if (mat[i][0] == 1)
        {
            memset(visited, 0, sizeof visited);
            findShortestPathUtil(mat, visited, i, 0,
                                 min_dist, 0);
            if (min_dist == C - 1)
                break;
        }
    }
    if (min_dist != INT_MAX)
        cout << "Length of shortest safe route is "
             << min_dist;
    else
        cout << "Destination not reachable from "
             << "given source";
}
int main()
{
    int mat[R][C] =
        {
            {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
            {1, 0, 1, 1, 1, 1, 1, 1, 1, 1},
            {1, 1, 1, 0, 1, 1, 1, 1, 1, 1},
            {1, 1, 1, 1, 0, 1, 1, 1, 1, 1},
            {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
            {1, 1, 1, 1, 1, 0, 1, 1, 1, 1},
            {1, 0, 1, 1, 1, 1, 1, 1, 0, 1},
            {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
            {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
            {0, 1, 1, 1, 1, 0, 1, 1, 1, 1},
            {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
            {1, 1, 1, 0, 1, 1, 1, 1, 1, 1}};
    findShortestPath(mat);
    return 0;
}*/
/*// Combinational Sum
#include <bits/stdc++.h>
using namespace std;
void findNumbers(vector<int> &ar, int sum, vector<vector<int>> &res,
                 vector<int> &r, int i)
{
    if (sum == 0)
    {
        res.push_back(r);
        return;
    }
    while (i < ar.size() && sum - ar[i] >= 0)
    {
        r.push_back(ar[i]);
        findNumbers(ar, sum - ar[i], res, r, i);
        i++;
        r.pop_back();
    }
}
vector<vector<int>> combinationSum(vector<int> &ar, int sum)
{
    sort(ar.begin(), ar.end());
    ar.erase(unique(ar.begin(), ar.end()), ar.end());

    vector<int> r;
    vector<vector<int>> res;
    findNumbers(ar, sum, res, r, 0);

    return res;
}
int main()
{
    vector<int> ar;
    ar.push_back(2);
    ar.push_back(4);
    ar.push_back(6);
    ar.push_back(8);
    int n = ar.size();

    int sum = 8; 
    vector<vector<int>> res = combinationSum(ar, sum);

    if (res.size() == 0)
    {
        cout << "Emptyn";
        return 0;
    }
    for (int i = 0; i < res.size(); i++)
    {
        if (res[i].size() > 0)
        {
            cout << " ( ";
            for (int j = 0; j < res[i].size(); j++)
                cout << res[i][j] << " ";
            cout << ")";
        }
    }
}*/
/*// Find Maximum number possible by doing at-most K swaps
#include <bits/stdc++.h>
using namespace std;
void findMaximumNum(string str, int k, string &max)
{
    if (k == 0)
        return;
    int n = str.length();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (str[i] < str[j])
            {
                swap(str[i], str[j]);
                if (str.compare(max) > 0)
                    max = str;
                findMaximumNum(str, k - 1, max);
                swap(str[i], str[j]);
            }
        }
    }
}

int main()
{
    string str = "129814999";

    int k = 4;

    string max = str;
    findMaximumNum(str, k, max);

    cout << max << endl;
    return 0;
}*/
/*// Print all permutations of a string
same as string 248*/
/*// Find if there is a path of more than k length from a source
graph problem*/
/*// Longest Possible Route in a Matrix with Hurdles
#include <bits/stdc++.h>
using namespace std;
#define R 3
#define C 10
struct Pair
{
    bool found;
    int value;
};
Pair findLongestPathUtil(int mat[R][C], int i, int j,
                         int x, int y, bool visited[R][C])
{
    if (i == x && j == y)
    {
        Pair p = {true, 0};
        return p;
    }
    if (i < 0 || i >= R || j < 0 || j >= C ||
        mat[i][j] == 0 || visited[i][j])
    {
        Pair p = {false, INT_MAX};
        return p;
    }
    visited[i][j] = true;
    int res = INT_MIN;
    Pair sol = findLongestPathUtil(mat, i, j - 1, x, y, visited);
    if (sol.found)
        res = max(res, sol.value);
    sol = findLongestPathUtil(mat, i, j + 1, x, y, visited);
    if (sol.found)
        res = max(res, sol.value);
    sol = findLongestPathUtil(mat, i - 1, j, x, y, visited);
    if (sol.found)
        res = max(res, sol.value);
    sol = findLongestPathUtil(mat, i + 1, j, x, y, visited);
    if (sol.found)
        res = max(res, sol.value);
    visited[i][j] = false;
    if (res != INT_MIN)
    {
        Pair p = {true, 1 + res};
        return p;
    }
    else
    {
        Pair p = {false, INT_MAX};
        return p;
    }
}
void findLongestPath(int mat[R][C], int i, int j, int x,
                     int y)
{
    bool visited[R][C];
    memset(visited, false, sizeof visited);
    Pair p = findLongestPathUtil(mat, i, j, x, y, visited);
    if (p.found)
        cout << "Length of longest possible route is "
             << p.value;
    else
        cout << "Destination not reachable from given source";
}
int main()
{
    int mat[R][C] =
        {
            {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
            {1, 1, 0, 1, 1, 0, 1, 1, 0, 1},
            {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};
    findLongestPath(mat, 0, 0, 1, 7);
    return 0;
}*/
/*// Print all possible paths from top left to bottom right of a mXn matrix
#include <bits/stdc++.h>
using namespace std;
void printAllPathsUtil(int *mat, int i, int j, int m, int n, int *path,
                       int pi)
{
    if (i == m - 1)
    {
        for (int k = j; k < n; k++)
            path[pi + k - j] = *((mat + i * n) + k);
        for (int l = 0; l < pi + n - j; l++)
            cout << path[l] << " ";
        cout << endl;
        return;
    }
    if (j == n - 1)
    {
        for (int k = i; k < m; k++)
            path[pi + k - i] = *((mat + k * n) + j);
        for (int l = 0; l < pi + m - i; l++)
            cout << path[l] << " ";
        cout << endl;
        return;
    }
    path[pi] = *((mat + i * n) + j);
    printAllPathsUtil(mat, i + 1, j, m, n, path, pi + 1);
    printAllPathsUtil(mat, i, j + 1, m, n, path, pi + 1);
}
void printAllPaths(int *mat, int m, int n)
{
    int *path = new int[m + n];
    printAllPathsUtil(mat, 0, 0, m, n, path, 0);
}
int main()
{
    int mat[2][3] = {{1, 2, 3}, {4, 5, 6}};
    printAllPaths(*mat, 2, 3);
    return 0;
}*/
/*// Partition of a set intoK subsets with equal sum
#include <bits/stdc++.h>
using namespace std;
bool isKPartitionPossibleRec(int arr[], int subsetSum[], bool taken[],
                             int subset, int K, int N, int curIdx, int limitIdx)
{
    if (subsetSum[curIdx] == subset)
    {
        if (curIdx == K - 2)
            return true;
        return isKPartitionPossibleRec(arr, subsetSum, taken, subset,
                                       K, N, curIdx + 1, N - 1);
    }
    for (int i = limitIdx; i >= 0; i--)
    {
        if (taken[i])
            continue;
        int tmp = subsetSum[curIdx] + arr[i];
        if (tmp <= subset)
        {
            taken[i] = true;
            subsetSum[curIdx] += arr[i];
            bool nxt = isKPartitionPossibleRec(arr, subsetSum, taken,
                                               subset, K, N, curIdx, i - 1);
            taken[i] = false;
            subsetSum[curIdx] -= arr[i];
            if (nxt)
                return true;
        }
    }
    return false;
}
bool isKPartitionPossible(int arr[], int N, int K)
{
    if (K == 1)
        return true;
    if (N < K)
        return false;
    int sum = 0;
    for (int i = 0; i < N; i++)
        sum += arr[i];
    if (sum % K != 0)
        return false;
    int subset = sum / K;
    int subsetSum[K];
    bool taken[N];
    for (int i = 0; i < K; i++)
        subsetSum[i] = 0;
    for (int i = 0; i < N; i++)
        taken[i] = false;
    subsetSum[0] = arr[N - 1];
    taken[N - 1] = true;
    return isKPartitionPossibleRec(arr, subsetSum, taken,
                                   subset, K, N, 0, N - 1);
}
int main()
{
    int arr[] = {2, 1, 4, 5, 3, 3};
    int N = sizeof(arr) / sizeof(arr[0]);
    int K = 3;

    if (isKPartitionPossible(arr, N, K))
        cout << "Partitions into equal sum is possible.\n";
    else
        cout << "Partitions into equal sum is not possible.\n";
}*/
/*// Find the K-th Permutation Sequence of first N natural numbers
#include <bits/stdc++.h>
using namespace std;
int findFirstNumIndex(int &k, int n)
{
    if (n == 1)
        return 0;
    n--;

    int first_num_index;
    int n_partial_fact = n;
    while (k >= n_partial_fact && n > 1)
    {
        n_partial_fact = n_partial_fact * (n - 1);
        n--;
    }
    first_num_index = k / n_partial_fact;

    k = k % n_partial_fact;

    return first_num_index;
}
string findKthPermutation(int n, int k)
{
    string ans = "";
    set<int> s;
    for (int i = 1; i <= n; i++)
        s.insert(i);
    set<int>::iterator itr;
    itr = s.begin();
    k = k - 1;
    for (int i = 0; i < n; i++)
    {

        int index = findFirstNumIndex(k, n - i);

        advance(itr, index);
        ans += (to_string(*itr));
        s.erase(itr);
        itr = s.begin();
    }
    return ans;
}
int main()
{
    int n = 3, k = 5;
    string kth_perm_seq = findKthPermutation(n, k);
    cout << kth_perm_seq << endl;
    return 0;
}*/