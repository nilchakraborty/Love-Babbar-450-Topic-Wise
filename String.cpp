/*//reverse a string
#include <bits/stdc++.h>
using namespace std;
int main() {
    string str="geeksforgeeks";
    reverse(str.begin(),str.end());
    cout<<str;
    return 0;
}*/
/*//Check whether a String is Palindrome or not
#include <iostream>
#include <string.h>
using namespace std;
int main()
{
    char a[100], b[100];

    cout << "Enter the string : ";
    cin >> a;
    int i, n = strlen(a);
    for (i = 0; i < n; i++)
    {
        b[n - 1 - i] = a[i];
    }

    if (strcmp(a, b) == 0)
        
        cout << "The string is a palindrome\n";
    else
        cout << "The string is not a palindrome\n";

    return 0;
}*/
/*//Find Duplicate characters in a string
#include <bits/stdc++.h>
using namespace std;
void printDups(string str)
{
    map<char, int> count;
    for (int i = 0; i < str.length(); i++)
    {
        count[str[i]]++;
    }

    for (auto it : count)
    {
        if (it.second > 1)
            cout << it.first << ", count = " << it.second
                 << "\n";
    }
}
int main()
{
    string str = "test string";
    printDups(str);
    return 0;
}*/
/*//Write a Code to check whether one string is a rotation of another
#include <bits/stdc++.h>
using namespace std;
bool rotation(string str1, string str2)
{
    if (str1.length() != str2.length())
        return false;
    string temp = str1 + str1;
    return (temp.find(str2) != string::npos);
}

int main()
{
    string str1 = "ABCD", str2 = "BCDA";
    if (rotation(str1, str2))
        cout << "String are rotation of each other";
    else
        cout << "string are not rotate";
    return 0;
}*/
/*//Write a Program to check whether a string is a valid shuffle of two strings or not
#include <bits/stdc++.h>
using namespace std;
bool ShuffledSubstring(string A, string B)
{
    int n = A.length();
    int m = B.length();
    if (n > m)
    {
        return false;
    }
    else
    {
        sort(A.begin(), A.end());
        for (int i = 0; i < m; i++)
        {
            if (i + n - 1 >= m)
            {
                return false;
            }
            string str = "";
            for (int j = 0; i < n; i++)
                str.push_back(B[i + j]);
            sort(str.begin(), str.end());
            if (str == A)
                return true;
        }
    }
}

int main()
{
    string str1 = "geekforgeeks";
    string str2 = "ekegorfkeegsgeek";
    bool a = ShuffledSubstring(str1, str2);
    if (a)
        cout << "Yes";
    else
        cout << "No";
    return 0;
}*/
/*//Count and Say problem
#include <bits/stdc++.h>
using namespace std;
string countnndSay(int n)
{
    if (n == 1)
        return "1";
    if (n == 2)
        return "11";
    string str = "11";
    for (int i = 3; i <= n; i++)
    {
        str += '$';
        int len = str.length();

        int cnt = 1;
        string tmp = "";
        for (int j = 1; j < len; j++)
        {
            if (str[j] != str[j - 1])
            {
                tmp += cnt + '0';
                tmp += str[j - 1];
                cnt = 1;
            }
            else
                cnt++;
        }
        str = tmp;
    }

    return str;
}
int main()
{
    int N = 3;
    cout << countnndSay(N) << endl;
    return 0;
}*/
/*//Write a program to find the longest Palindrome in a string
#include <bits/stdc++.h>
using namespace std;
void printSubStr(string str, int low, int high)
{
    for (int i = low; i <= high; ++i)
        cout << str[i];
}
int longestPalSubstr(string str)
{
    int n = str.size();
    int maxLength = 1, start = 0;
    for (int i = 0; i < str.length(); i++)
    {
        for (int j = i; j < str.length(); j++)
        {
            int flag = 1;
            for (int k = 0; k < (j - i + 1) / 2; k++)
                if (str[i + k] != str[j - k])
                    flag = 0;
            if (flag && (j - i + 1) > maxLength)
            {
                start = i;
                maxLength = j - i + 1;
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
    cout << "\nLength is: "<< longestPalSubstr(str);
    return 0;
}*/
/*//Longest Repeating Subsequence
#include <iostream>
#include <string>
using namespace std;
int findLongestRepeatingSubSeq(string str)
{
    int n = str.length();
    int dp[n+1][n+1];
    for (int i=0; i<=n; i++)
        for (int j=0; j<=n; j++)
            dp[i][j] = 0;
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=n; j++)
        {
            if (str[i-1] == str[j-1] && i != j)
                dp[i][j] =  1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
        }
    }
    return dp[n][n];
}
int main()
{
    string str = "aabb";
    cout << "The length of the largest subsequence that"
            " repeats itself is : "
        << findLongestRepeatingSubSeq(str);
    return 0;
}*/
/*//Print all Subsequences of a string.
#include <bits/stdc++.h>
using namespace std;
void printSubsequence(string input, string output)
{
    if (input.empty())
    {
        cout << output << endl;
        return;
    }
    printSubsequence(input.substr(1), output + input[0]);
    printSubsequence(input.substr(1), output);
}

int main()
{
    string output = " ";
    string input = "abcd"; 
    printSubsequence(input, output);
    return 0;
}*/
/*//Print all the permutations of the given string
#include <bits/stdc++.h>
using namespace std;
void permute(string a, int l, int r)
{
    if (l == r)
        cout<<a<<endl;
    else
    {
        for (int i = l; i <= r; i++)
        {
            swap(a[l], a[i]);
            permute(a, l+1, r);
            swap(a[l], a[i]);
        }
    }
}
int main()
{
    string str = "ABC";
    int n = str.size();
    permute(str, 0, n-1);
    return 0;
}*/
/*//Split the Binary string into two substring with equal 0’s and 1’s
#include <bits/stdc++.h>
using namespace std;
int maxSubStr(string str, int n)
{
    int count0 = 0, count1 = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (str[i] == '0')
        {
            count0++;
        }
        else
        {
            count1++;
        }
        if (count0 == count1)
        {
            cnt++;
        }
    }
    if (cnt == 0)
    {
        return -1;
    }
    return cnt;
}

int main()
{
    string str = "0100110101";
    int n = str.length();
    cout << maxSubStr(str, n);
    return 0;
}*/
/*//Word Wrap Problem [VERY IMP].
#include <bits/stdc++.h>
using namespace std;
void solveWordWrap(int arr[], int n, int k)
{
    int i, j, currlen, cost, dp[n], ans[n];
    dp[n - 1] = 0;
    ans[n - 1] = n - 1;
    for (i = n - 2; i >= 0; i--)
    {
        currlen = -1;
        dp[i] = INT_MAX;
        for (j = i; j < n; j++)
        {
            currlen += (arr[j] + 1);
            if (currlen > k)
                break;
            if (j == n - 1)
                cost = 0;
            else
                cost = (k - currlen) * (k - currlen) + dp[j + 1];
            if (cost < dp[i])
            {
                dp[i] = cost;
                ans[i] = j;
            }
        }
    }
    i = 0;
    while (i < n)
    {
        cout << i + 1 << " " << ans[i] + 1 << " ";
        i = ans[i] + 1;
    }
}
int main()
{
    int arr[] = {3, 2, 2, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int M = 6;
    solveWordWrap(arr, n, M);
    return 0;
}*/
/*//EDIT Distance [Very Imp]
#include <bits/stdc++.h>
using namespace std;
int min(int x, int y, int z)
{
    return min(min(x, y), z);
}
int editDist(string str1, string str2, int m, int n)
{
    if (m == 0)
        return n;
    if (n == 0)
        return m;
    if (str1[m - 1] == str2[n - 1])
        return editDist(str1, str2, m - 1, n - 1);
    return 1 + min(editDist(str1, str2, m, n - 1), editDist(str1, str2, m - 1, n), editDist(str1, str2, m - 1, n - 1));
}
int main()
{
    string str1 = "voldemort";
    string str2 = "dumbledore";
    cout << editDist(str1, str2, str1.length(), str2.length());
    return 0;
}*/
/*//Find next greater number with same set of digits. [Very Very IMP]
#include <bits/stdc++.h>
using namespace std;
vector<int> nextPurmutation(int n, vector<int> arr)
{
    if (n == 1)
        return arr;
    int i = 0;
    for (i = n - 1; i > 0; i--)
    {
        if (arr[i] > arr[i - 1])
            break;
    }
    if (i != 0)
    {
        for (int j = n - 1; j < i; j--)
        {
            if (arr[i - 1] < arr[j])
            {
                swap(arr[i - 1], arr[j]);
                break;
            }
        }
    }
    reverse(arr.begin() + i, arr.end());
    return arr;
}

int main()
{
    int n = 6;
    vector<int> v{5, 3, 4, 9, 7, 6};
    vector<int> res;
    res = nextPurmutation(n, v);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }

    return 0;
}*/
/*//Balanced Parenthesis problem.[Imp]
#include <bits/stdc++.h>
using namespace std;
bool areBrackets(string expr)
{
    stack<char> s;
    char x;
    for (int i = 0; i < expr.length(); i++)
    {
        if (expr[i] == '(' || expr[i] == '[' || expr[i] == '{')
        {
            s.push(expr[i]);
            continue;
        }
        if (s.empty())
            return false;

        switch (expr[i])
        {
        case ')':
            x = s.top();
            s.pop();
            if (x == '{' || x == '[')
                return false;
            break;

        case '}':
            x = s.top();
            s.pop();
            if (x == '[' || x == '(')
                return false;
            break;

        case ']':
            x = s.top();
            s.pop();
            if (x == '{' || x == '(')
                return false;
            break;
        }
    }
    return (s.empty());
}

int main()
{
    string expr = "{()}[]";
    if (areBrackets(expr))
        cout << "Balanced";
    else
        cout << "Not Balanced";
    return 0;
}*/
/*//Word break Problem[ Very Imp]
#include <iostream>
using namespace std;
int dictionaryContains(string word)
{
    string dictionary[] = {"mobile", "samsung", "sam", "sung",
                           "man", "mango", "icecream", "and",
                           "go", "i", "like", "ice", "cream"};
    int size = sizeof(dictionary) / sizeof(dictionary[0]);
    for (int i = 0; i < size; i++)
        if (dictionary[i].compare(word) == 0)
            return true;
    return false;
}
bool wordBreak(string str)
{
    int size = str.size();
    if (size == 0)
        return true;
    for (int i = 1; i <= size; i++)
    {
        if (dictionaryContains(str.substr(0, i)) &&
            wordBreak(str.substr(i, size - i)))
            return true;
    }
    return false;
}
int main()
{
    wordBreak("ilikesamsung") ? cout << "Yes\n" : cout << "No\n";
    wordBreak("iiiiiiii") ? cout << "Yes\n" : cout << "No\n";
    wordBreak("") ? cout << "Yes\n" : cout << "No\n";
    wordBreak("ilikelikeimangoiii") ? cout << "Yes\n" : cout << "No\n";
    wordBreak("samsungandmango") ? cout << "Yes\n" : cout << "No\n";
    wordBreak("samsungandmangok") ? cout << "Yes\n" : cout << "No\n";
    return 0;
}*/
/*//Rabin Karp Algo
#include <string.h>
#include <iostream>
using namespace std;

#define d 10

void rabinKarp(char pat[], char txt[], int q) {
  int m = strlen(pat);
  int n = strlen(txt);
  int i, j;
  int p = 0;
  int t = 0;
  int h = 1;

  for (i = 0; i < m - 1; i++)
    h = (h * d) % q;

  // Calculate hash value for pattern and text
  for (i = 0; i < m; i++) {
    p = (d * p + pat[i]) % q;
    t = (d * t + txt[i]) % q;
  }

  // Find the match
  for (i = 0; i <= n - m; i++) {
    if (p == t) {
      for (j = 0; j < m; j++) {
        if (txt[i + j] != pat[j])
          break;
      }

      if (j == m)
        cout << "Pattern is found at position: " << i + 1 << endl;
    }

    if (i < n - m) {
      t = (d * (t - txt[i] * h) + txt[i + m]) % q;

      if (t < 0)
        t = (t + q);
    }
  }
}

int main() {
  char text[] = "ABCCDDAEFG";
  char pattern[] = "CDD";
  int q = 13;
  rabinKarp(pattern, text, q);
}*/
/*//KMP Algo
#include <bits/stdc++.h>

void computeLPSArray(char *pat, int M, int *lps);
void KMPSearch(char *pat, char *txt)
{
    int M = strlen(pat);
    int N = strlen(txt);
    int lps[M];
    computeLPSArray(pat, M, lps);

    int i = 0;
    int j = 0;
    while (i < N)
    {
        if (pat[j] == txt[i])
        {
            j++;
            i++;
        }

        if (j == M)
        {
            printf("Found pattern at index %d ", i - j);
            j = lps[j - 1];
        }
        else if (i < N && pat[j] != txt[i])
        {
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
}
void computeLPSArray(char *pat, int M, int *lps)
{
    int len = 0;

    lps[0] = 0;
    int i = 1;
    while (i < M)
    {
        if (pat[i] == pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = lps[len - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}
int main()
{
    char txt[] = "ABABDABACDABABCABAB";
    char pat[] = "ABABCABAB";
    KMPSearch(pat, txt);
    return 0;
}*/
/*//Convert a Sentence into its equivalent mobile numeric keypad sequence.
#include <bits/stdc++.h>
using namespace std;
string printSequence(string arr[], string input)
{
    string output = "";
    int n = input.length();
    for (int i = 0; i < n; i++)
    {
        if (input[i] ==' ')
            output = output + "0";
        else
        {
            int position = input[i] - 'A';
            output = output + arr[position];
        }
    }
    return output;
}

int main()
{
    string str[] = {"2", "22", "222",
                    "3", "33", "333",
                    "4", "44", "444",
                    "5", "55", "555",
                    "6", "66", "666",
                    "7", "77", "777", "7777",
                    "8", "88", "888",
                    "9", "99", "999", "9999"};

    string input = "NILANJIT";
    cout << printSequence(str, input);
    return 0;
}*/
/*//Minimum number of bracket reversals needed to make an expression balanced.
#include <bits/stdc++.h>
using namespace std;
int countMinReversals(string expr)
{
    int len = expr.length();
    if (len % 2 != 0)
    {
        return -1;
    }
    int left_brac = 0, right_brac = 0;
    int ans;
    for (int i = 0; i < len; i++)
    {
        if (expr[i] == '{')
        {
            left_brac++;
        }
        else
        {
            if (left_brac == 0)
            {
                right_brac++;
            }
            else
            {
                left_brac--;
            }
        }
    }
    ans = ceil(left_brac / 2) + ceil(right_brac / 2);
    return ans;
}

int main()
{
    string expr = "}}{{"; 
    cout << countMinReversals(expr);
    return 0;
}*/
/*//Count All Palindromic Subsequence in a given String.
#include <bits/stdc++.h>
#include <cstring>
using namespace std;
int countPS(string str)
{
    int N = str.length();
    int cps[N + 1][N + 1];
    memset(cps, 0, sizeof(cps));
    for (int i = 0; i < N; i++)
        cps[i][i] = 1;
    for (int L = 2; L <= N; L++)
    {
        for (int i = 0; i <= N - L; i++)
        {
            int k = L + i - 1;
            if (str[i] == str[k])
                cps[i][k] = cps[i][k - 1] + cps[i + 1][k] + 1;
            else
                cps[i][k] = cps[i][k - 1] + cps[i + 1][k] - cps[i + 1][k - 1];
        }
    }

    return cps[0][N - 1];
}

int main()
{
    string str = "abcd";
    cout << "Total Palindromic subsequence are : " << countPS(str) << endl;
    return 0;
}*/
/*//Count of number of given string in 2D character array
#include <bits/stdc++.h>
using namespace std;
#define ARRAY_SIZE(a) (sizeof(a) / sizeof(*a))
int internalSearch(string needle, int row, int col,
                   string hay[], int row_max,
                   int col_max, int xx)
{
    int found = 0;
    	if (row >= 0 && row <= row_max && col >= 0 &&
		col <= col_max && needle[xx] == hay[row][col])
    {
        char match = needle[xx];
        xx += 1;
        hay[row][col] = 0;
        if (needle[xx] == 0)
        {
            found = 1;
        }
        else
        {
            found += internalSearch(needle, row, col + 1, hay,
                                    row_max, col_max, xx);
            found += internalSearch(needle, row, col - 1, hay,
                                    row_max, col_max, xx);
            found += internalSearch(needle, row + 1, col, hay,
                                    row_max, col_max, xx);
            found += internalSearch(needle, row - 1, col, hay,
                                    row_max, col_max, xx);
        }
        hay[row][col] = match;
    }
    return found;
}
int searchString(string needle, int row, int col,
                 string str[], int row_count, int col_count)
{
    int found = 0;
    int r, c;
    for (r = 0; r < row_count; ++r)
    {
        for (c = 0; c < col_count; ++c)
        {
            found += internalSearch(needle, r, c, str,
                                    row_count - 1, col_count - 1, 0);
        }
    }
    return found;
}

int main()
{
    string needle = "MAGIC";
    string input[] = {"BBABBM",
                      "CBMBBA",
                      "IBABBG",
                      "GOZBBI",
                      "ABBBBC",
                      "MCIGAM"};
    string str[ARRAY_SIZE(input)];
    int i;
    for (i = 0; i < ARRAY_SIZE(input); ++i)
    {
        str[i] = input[i];
    }
    cout << "count: " << searchString(needle, 0, 0, str, ARRAY_SIZE(str), str[0].size()) << endl;
    return 0;
}*/
/*//Search a Word in a 2D Grid of characters.
#include <bits/stdc++.h>
using namespace std;
int x[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int y[] = {-1, 0, 1, -1, 1, -1, 0, 1};
bool search2D(char *grid, int row, int col,
              string word, int R, int C)
{
    if (*(grid + row * C + col) != word[0])
        return false;

    int len = word.length();
    for (int dir = 0; dir < 8; dir++)
    {
        int k, rd = row + x[dir], cd = col + y[dir];
        for (k = 1; k < len; k++)
        {
            if (rd >= R || rd < 0 || cd >= C || cd < 0)
                break;
            if (*(grid + rd * C + cd) != word[k])
                break;
            rd += x[dir], cd += y[dir];
        }
        if (k == len)
            return true;
    }
    return false;
}
void patternSearch(char *grid, string word,
                   int R, int C)
{
    // point and search given word
    for (int row = 0; row < R; row++)
        for (int col = 0; col < C; col++)
            if (search2D(grid, row, col, word, R, C))
                cout << "pattern found at "
                     << row << ", "
                     << col << endl;
}
int main()
{
    int R = 3, C = 13;
    char grid[R][C] = {"GEEKSFORGEEKS",
                       "GEEKSQUIZGEEK",
                       "IDEQAPRACTICE"};

    patternSearch((char *)grid, "GEEKS", R, C);
    cout << endl;
    patternSearch((char *)grid, "EEE", R, C);
    return 0;
}*/
/*//Boyer Moore Algorithm for Pattern Searching.
#include <bits/stdc++.h>
using namespace std;
# define NO_OF_CHARS 256

void badCharHeuristic( string str, int size,
						int badchar[NO_OF_CHARS])
{
	int i;
	for (i = 0; i < NO_OF_CHARS; i++)
		badchar[i] = -1;
	for (i = 0; i < size; i++)
		badchar[(int) str[i]] = i;
}
void search( string txt, string pat)
{
	int m = pat.size();
	int n = txt.size();

	int badchar[NO_OF_CHARS];
	badCharHeuristic(pat, m, badchar);

	int s = 0;
	while(s <= (n - m))
	{
		int j = m - 1;
		while(j >= 0 && pat[j] == txt[s + j])
			j--;
		if (j < 0)
		{
			cout << "pattern occurs at shift = " << s << endl;
			s += (s + m < n)? m-badchar[txt[s + m]] : 1;
		}

		else
			s += max(1, j - badchar[txt[s + j]]);
	}
}
int main()
{
	string txt= "ABAAABCD";
	string pat = "ABC";
	search(txt, pat);
	return 0;
}*/
/*//Converting Roman Numerals to Decimal
#include <bits/stdc++.h>
using namespace std;
int romanToDecimal(string &str)
{
    map<char, int> m;
    m.insert({'I', 1});
    m.insert({'V', 5});
    m.insert({'X', 10});
    m.insert({'L', 50});
    m.insert({'C', 100});
    m.insert({'D', 500});
    m.insert({'M', 1000});
    int sum = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (m[str[i]] < m[str[i + 1]])
        {
            sum += m[str[i + 1]] - m[str[i]];
            i++;
        }
        sum += m[str[i]];
    }
    return sum;
}

int main()
{
    string str = "MMD";
    cout << "Integer form of Roman Numeral is "
         << romanToDecimal(str) << endl;
    return 0;
}*/
/*//Longest Common Prefix
#include <bits/stdc++.h>
using namespace std;
string commonPrefixUtil(string str1, string str2)
{
    string result;
    int n1 = str1.length(), n2 = str2.length();
    for (int i = 0, j = 0; i <= n1 - 1 &&j <= n2 - 1; i++, j++)
    {
        if (str1[i] != str2[i])
            break;
        result.push_back(str1[i]);
    }
    return (result);
}
string commonPrefix(string arr[], int n)
{
    string prefix = arr[0];
    for (int i = 1; i < n - 1; i++)
        prefix = commonPrefixUtil(prefix, arr[i]);
    return (prefix);
}
int main()
{
    string arr[] = {"geeksforgeeks", "geeks",
                    "gee", "geezer"};
    int n = sizeof(arr) / sizeof(arr[0]);

    string ans = commonPrefix(arr, n);

    if (ans.length())
        printf("The longest common prefix is - %s",
               ans.c_str());
    else
        printf("There is no common prefix");

    return 0;
}*/
/*//Number of flips to make binary string alternate
#include <bits/stdc++.h>
using namespace std;
char flip(char ch)
{
    return (ch == '0') ? '1' : '0';
}
int getFlipWithStringCharacter(string str, char expected)
{
    int flipCount = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] != expected)
            flipCount++;
        expected = flip(expected);
    }
    return flipCount;
}
int minFlipToMakeStringAlternate(string str)
{
    return min(getFlipWithStringCharacter(str, '0'),
               getFlipWithStringCharacter(str, '1'));
}
int main()
{
    string str = "0001010111";
    cout << minFlipToMakeStringAlternate(str);
    return 0;
}*/
/*//Find the first repeated word in string.
#include <bits/stdc++.h>
using namespace std;
string findFirstRepeated(string s)
{
    istringstream iss(s);
    string token;
    set<string> setofWords;
    while (getline(iss, token, ' '))
    {
        if (setofWords.find(token) != setofWords.end())
        {
            return token;
        }
        setofWords.insert(token);
    }
    return "NoRepetition";
}

int main()
{
    string s("Ravi had been saying that he had been there");
    string firstWord = findFirstRepeated(s);
    if (firstWord != "NoRepetition")
        cout << "First repeated word :: " << firstWord << endl;
    else
        cout << "No Repetition";
    return 0;
}*/
/*//Minimum number of swaps for bracket balancing.
#include <bits/stdc++.h>
using namespace std;
long swapCount(string chars)
{
    int countLeft = 0, countRight = 0, swap = 0, imbalance = 0;
    for (int i = 0; i < chars.length(); i++)
    {
        if (chars[i] == '[')
        {
            countLeft++;
            if (imbalance > 0)
            {
                swap += imbalance;
                imbalance--;
            }
        }
        else if (chars[i] == ']')
        {
            countRight++;
            imbalance = (countRight - countLeft);
        }
    }
    return swap;
}

int main()
{
    string s = "[]][][";
    cout << swapCount(s) << endl;

    s = "[[][]]";
    cout << swapCount(s) << endl;

    return 0;
}*/
/*//Find the longest common subsequence between two strings.
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
/*//Program to generate all possible valid IP addresses from given  string.
#include <iostream>
#include <vector>
using namespace std;
void GetAllValidIpAddress(vector<string> &result,
                          string givenString, int index,
                          int count, string ipAddress)
{
    if (givenString.size() == index && count == 4)
    {
        ipAddress.pop_back();
        result.push_back(ipAddress);
        return;
    }
    if (givenString.size() < index + 1)
        return;
    ipAddress = ipAddress + givenString.substr(index, 1) + '.';
    GetAllValidIpAddress(result, givenString, index + 1,
                         count + 1, ipAddress);
    ipAddress.erase(ipAddress.end() - 2, ipAddress.end());
    if (givenString.size() < index + 2 || givenString[index] == '0')
        return;
    ipAddress = ipAddress + givenString.substr(index, 2) + '.';
    GetAllValidIpAddress(result, givenString, index + 2,
                         count + 1, ipAddress);
    ipAddress.erase(ipAddress.end() - 3, ipAddress.end());
    if (givenString.size() < index + 3 || stoi(givenString.substr(index, 3)) > 255)
        return;
    ipAddress += givenString.substr(index, 3) + '.';
    GetAllValidIpAddress(result, givenString, index + 3,
                         count + 1, ipAddress);
    ipAddress.erase(ipAddress.end() - 4, ipAddress.end());
}
int main()
{
    string givenString = "25525511135";
    vector<string> result;
    GetAllValidIpAddress(result, givenString, 0, 0, "");
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << "\n";
    }
}*/
/*//Write a program tofind the smallest window that contains all characters of string itself.
#include <bits/stdc++.h>
using namespace std;
const int MAX_CHARS = 256;

string findSubString(string str)
{
    int n = str.length();
    if (n <= 1)
        return str;
    int dist_count = 0;
    bool visited[MAX_CHARS] = {false};
    for (int i = 0; i < n; i++)
    {
        if (visited[str[i]] == false)
        {
            visited[str[i]] = true;
            dist_count++;
        }
    }
    int start = 0, start_index = -1, min_len = INT_MAX;

    int count = 0;
    int curr_count[MAX_CHARS] = {0};
    for (int j = 0; j < n; j++)
    {
        curr_count[str[j]]++;

        if (curr_count[str[j]] == 1)
            count++;

        if (count == dist_count)
        {
            while (curr_count[str[start]] > 1)
            {
                if (curr_count[str[start]] > 1)
                    curr_count[str[start]]--;
                start++;
            }

            int len_window = j - start + 1;
            if (min_len > len_window)
            {
                min_len = len_window;
                start_index = start;
            }
        }
    }

    return str.substr(start_index, min_len);
}

int main()
{
    string str = "aabcbcdbca";
    cout << "Smallest window containing all distinct"
            " characters is: "
         << findSubString(str);
    return 0;
}*/
/*//Rearrange characters in a string such that no two adjacent are same
#include <bits/stdc++.h>
using namespace std;
char getMaxCountChar(const vector<int> &count)
{
    int max = 0;
    char ch;
    for (int i = 0; i < 26; i++)
    {
        if (count[i] > max)
        {
            max = count[i];
            ch = 'a' + i;
        }
    }

    return ch;
}

string rearrangeString(string S)
{

    int n = S.size();
    if (!n)
        return "";

    vector<int> count(26, 0);
    for (auto ch : S)
        count[ch - 'a']++;

    char ch_max = getMaxCountChar(count);
    int maxCount = count[ch_max - 'a'];

    if (maxCount > (n + 1) / 2)
        return "";

    string res(n, ' ');

    int ind = 0;

    while (maxCount)
    {
        res[ind] = ch_max;
        ind = ind + 2;
        maxCount--;
    }
    count[ch_max - 'a'] = 0;

    for (int i = 0; i < 26; i++)
    {
        while (count[i] > 0)
        {
            ind = (ind >= n) ? 1 : ind;
            res[ind] = 'a' + i;
            ind += 2;
            count[i]--;
        }
    }
    return res;
}

int main()
{
    string str = "bbbaa";
    string res = rearrangeString(str);
    if (res == "")
        cout << "Not valid string" << endl;
    else
        cout << res << endl;
    return 0;
}*/
/*//Minimum characters to be added at front to make string palindrome
#include <bits/stdc++.h>
using namespace std;
bool ispalindrome(string s)
{
    int l = s.length();
    int j;
    for (int i = 0, j = l - 1; i <= j; i++, j--)
    {
        if (s[i] != s[j])
            return false;
    }
    return true;
}

int main()
{
    string s = "BABABAA";
    int cnt = 0;
    int flag = 0;
    while (s.length() > 0)
    {
        if (ispalindrome(s))
        {
            flag = 1;
            break;
        }
        else
        {
            cnt++;
            s.erase(s.begin() + s.length() - 1);
        }
    }
    if (flag)
        cout << cnt;
}*/
/*//Given a sequence of words, print all anagrams together
#include <bits/stdc++.h>
using namespace std;

void printAnagrams(string arr[], int size)
{
    unordered_map<string, vector<string>> map;

    for (int i = 0; i < size; i++)
    {

        string word = arr[i];
        char letters[word.size() + 1];
        strcpy(letters, word.c_str());
        sort(letters, letters + word.size() + 1);
        string newWord = "";
        for (int i = 0; i < word.size() + 1; i++)
        {
            newWord += letters[i];
        }
        if (map.find(newWord) != map.end())
        {
            map[newWord].push_back(word);
        }
        else
        {

            vector<string> words;
            words.push_back(word);
            map[newWord] = words;
        }
    }

    unordered_map<string, vector<string>>::iterator it;
    for (it = map.begin(); it != map.end(); it++)
    {
        vector<string> values = map[it->first];
        if (values.size() > 1)
        {
            cout << "[";
            for (int i = 0; i < values.size() - 1; i++)
            {
                cout << values[i] << ", ";
            }
            cout << values[values.size() - 1];
            cout << "]";
        }
    }
}
int main()
{
    string arr[] = {"cat", "dog", "tac",
                    "god", "act"};
    int size = sizeof(arr) / sizeof(arr[0]);

    printAnagrams(arr, size);

    return 0;
}*/
/*//Find the smallest window in a string containing all characters of another string
#include <bits/stdc++.h>
using namespace std;

string Minimum_Window(string s, string t)
{

    int m[256] = {0};

    int ans = INT_MAX;
    int start = 0;
    int count = 0;

    for (int i = 0; i < t.length(); i++)
    {
        if (m[t[i]] == 0)
            count++;
        m[t[i]]++;
    }

    int i = 0;
    int j = 0;

    while (j < s.length())
    {
        m[s[j]]--;
        if (m[s[j]] == 0)
            count--;

        if (count == 0)
        {
            while (count == 0)
            {
                if (ans > j - i + 1)
                {
                    ans = min(ans, j - i + 1);
                    start = i;
                }

                m[s[i]]++;
                if (m[s[i]] > 0)
                    count++;

                i++;
            }
        }
        j++;
    }

    if (ans != INT_MAX)
        return s.substr(start, ans);
    else
        return "-1";
}

main()
{
    string s = "ADOBECODEBANC";
    string t = "ABC";

    cout << "-->Smallest window that contain all character : " << endl;
    cout << Minimum_Window(s, t);
}*/
/*//Recursively remove all adjacent duplicates
#include <bits/stdc++.h>
using namespace std;
string removeDuplicates(string s, char ch)
{
    if (s.length() <= 1)
    {
        return s;
    }
    int i = 0;
    while (i < s.length())
    {
        if (i + 1 < s.length() && s[i] == s[i + 1])
        {
            int j = i;
            while (j + 1 < s.length() && s[j] == s[j + 1])
            {
                j++;
            }
            char lastChar = i > 0 ? s[i - 1] : ch;
            string remStr = removeDuplicates(s.substr(j + 1, s.length()), lastChar);
            s = s.substr(0, i);
            int k = s.length(), l = 0;
            while (remStr.length() > 0 && s.length() > 0 && remStr[0] == s[s.length() - 1])
            {
                while (remStr.length() > 0 && remStr[0] != ch && remStr[0] == s[s.length() - 1])
                {
                    remStr = remStr.substr(1, remStr.length());
                }
                s = s.substr(0, s.length() - 1);
            }
            s = s + remStr;
            i = j;
        }
        else
        {
            i++;
        }
    }
    return s;
}
int main()
{
    string str1 = "mississipie";
    cout << removeDuplicates(str1, ' ') << endl;

    string str2 = "ocvvcolop";
    cout << removeDuplicates(str2, ' ') << endl;
}*/
/*//String matching where one string contains wildcard characters
#include <bits/stdc++.h>
using namespace std;
bool match(char *first, char *second)
{
    if (*first == '\0' && *second == '\0')
        return true;
    if (*first == '*' && *(first + 1) != '\0' && *second == '\0')
        return false;
    if (*first == '?' || *first == *second)
        return match(first + 1, second + 1);
    if (*first == '*')
        return match(first + 1, second) || match(first, second + 1);
    return false;
}
void test(char *first, char *second)
{
    match(first, second) ? puts("Yes") : puts("No");
}

int main()
{
    test("g*ks", "geeks");
    test("ge?ks*", "geeksforgeeks");
    test("g*k", "gee");
    test("*pqrs", "pqrst");
    test("abc*bcd", "abcdhghgbcd");
    test("abc*c?d", "abcd");
    test("*c*d", "abcd");
    test("*?c*d", "abcd");
    return 0;
}*/
/*//Function to find Number of customers who could not get a computer
#include<iostream>
#include<cstring>
using namespace std;

#define MAX_CHAR 26

// n is number of computers in cafe.
// 'seq' is given sequence of customer entry, exit events
int runCustomerSimulation(int n, const char *seq)
{
	// seen[i] = 0, indicates that customer 'i' is not in cafe
	// seen[1] = 1, indicates that customer 'i' is in cafe but
	//			 computer is not assigned yet.
	// seen[2] = 2, indicates that customer 'i' is in cafe and
	//			 has occupied a computer.
	char seen[MAX_CHAR] = {0};

	// Initialize result which is number of customers who could
	// not get any computer.
	int res = 0;

	int occupied = 0; // To keep track of occupied computers

	// Traverse the input sequence
	for (int i=0; seq[i]; i++)
	{
		// Find index of current character in seen[0...25]
		int ind = seq[i] - 'A';

		// If First occurrence of 'seq[i]'
		if (seen[ind] == 0)
		{
			// set the current character as seen
			seen[ind] = 1;

			// If number of occupied computers is less than
			// n, then assign a computer to new customer
			if (occupied < n)
			{
				occupied++;

				// Set the current character as occupying a computer
				seen[ind] = 2;
			}

			// Else this customer cannot get a computer,
			// increment result
			else
				res++;
		}

		// If this is second occurrence of 'seq[i]'
		else
		{
		// Decrement occupied only if this customer
		// was using a computer
		if (seen[ind] == 2)
			occupied--;
		seen[ind] = 0;
		}
	}
	return res;
}

// Driver program
int main()
{
	cout << runCustomerSimulation(2, "ABBAJJKZKZ") << endl;
	cout << runCustomerSimulation(3, "GACCBDDBAGEE") << endl;
	cout << runCustomerSimulation(3, "GACCBGDDBAEE") << endl;
	cout << runCustomerSimulation(1, "ABCBCA") << endl;
	cout << runCustomerSimulation(1, "ABCBCADEED") << endl;
	return 0;
}*/
/*//Transform One String to Another using Minimum Number of Given Operation
#include <bits/stdc++.h>
using namespace std;
int lcs(string str1, string str2, int m, int n)
{
    int L[m + 1][n + 1];
    int i, j;

    for (i = 0; i <= m; i++)
    {
        for (j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                L[i][j] = 0;

            else if (str1.at(i - 1) == str2.at(j - 1))
                L[i][j] = L[i - 1][j - 1] + 1;

            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }
    }
    return L[m][n];
}

void printMinDelAndInsert(string str1, string str2)
{
    int m = str1.size();
    int n = str2.size();

    int len = lcs(str1, str2, m, n);

    cout << "Minimum number of deletions = " << (m - len)
         << endl;

    cout << "Minimum number of insertions = " << (n - len)
         << endl;
}
int main()
{
    string str1 = "heap";
    string str2 = "pea";
    printMinDelAndInsert(str1, str2);
    return 0;
}*/
/*//Check if two given strings are isomorphic to each other
#include <bits/stdc++.h>
using namespace std;
#define MAX_CHARS 256
bool areIsomorphic(string str1, string str2)
{
    int n = str1.length(), m = str2.length();
    if (n != m)
        return false;
    int count[MAX_CHARS] = {0};
    int dcount[MAX_CHARS] = {0};
    for (int i = 0; i < n; i++)
    {
        count[str1[i]]++;
        dcount[str2[i]]++;
        if (count[str1[i]] != dcount[str2[i]])
            return false;
    }
    return true;
}
int main()
{
    cout << areIsomorphic("aab", "xxy") << endl;
    cout << areIsomorphic("aab", "xyz") << endl;
    return 0;
}*/
/*//Recursively print all sentences that can be formed from list of word lists
#include <bits/stdc++.h>
#include <string>
#define R 3
#define C 4
using namespace std;
void printUtil(string arr[R][C], int m, int n, string output[R])
{
    output[m] = arr[m][n];
    if (m == R - 1)
    {
        for (int i = 0; i < R; i++)

            cout << output[i] << " ";
        cout << endl;
        return;
    }

    for (int i = 0; i < C; i++)
        if (arr[m + 1][i] != "")
            printUtil(arr, m + 1, i, output);
}
void print(string arr[R][C])
{
    string output[R];

    for (int i = 0; i < C; i++)
        if (arr[0][i] != "")
            printUtil(arr, 0, i, output);
}

int main()
{
    string arr[R][C] = {{"you", "we"},
                        {"have", "are"},
                        {"sleep", "eat", "drink"}};

    print(arr);
    return 0;
}*/
