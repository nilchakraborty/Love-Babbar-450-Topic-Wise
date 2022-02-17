/*// Count set bits in an integer
#include <bits/stdc++.h>
using namespace std;
int countSetBits(int N)
{
    int count = 0;
    for (int i = 0; i < sizeof(int) * 8; i++)
    {
        if (N & (1 << i))
            count++;
    }
    return count;
}

int main()
{
    int N = 15;
    cout << countSetBits(N) << endl;
    return 0;
}*/
/*// Find the two non-repeating elements in an array of repeating elements
#include <bits/stdc++.h>
using namespace std;
void get2NonRepeatingNos(int arr[], int n, int *x, int *y)
{
    int Xor = arr[0];
    int set_bit_no;
    int i;
    *x = 0;
    *y = 0;
    for (i = 1; i < n; i++)
        Xor ^= arr[i];
    set_bit_no = Xor & ~(Xor - 1);
    for (i = 0; i < n; i++)
    {
        if (arr[i] & set_bit_no)
            *x = *x ^ arr[i];
        else
            *y = *y ^ arr[i];
    }
}

int main()
{
    int arr[] = {2, 3, 7, 9, 11, 2, 3, 11};
    int n = sizeof(arr) / sizeof(*arr);
    int *x = new int[(sizeof(int))];
    int *y = new int[(sizeof(int))];
    get2NonRepeatingNos(arr, n, x, y);
    cout << "The non-repeating elements are " << *x
         << " and " << *y;
    return 0;
}*/
/*// Count number of bits to be flipped to convert A to B
#include <bits/stdc++.h>
using namespace std;
int countSetBits(int n)
{
    int count = 0;
    while (n > 0)
    {
        count++;
        n &= (n - 1);
    }
    return count;
}
int FlippedCount(int a, int b)
{
    return countSetBits(a ^ b);
}
int main()
{
    int a = 10;
    int b = 20;
    cout << FlippedCount(a, b) << endl;
    return 0;
}*/
/*// Count total set bits in all numbers from 1 to n
#include <stdio.h>
unsigned int countSetBitsUtil(unsigned int x);
unsigned int countSetBits(unsigned int n)
{
    int bitCount = 0;

    for (int i = 1; i <= n; i++)
        bitCount += countSetBitsUtil(i);

    return bitCount;
}
unsigned int countSetBitsUtil(unsigned int x)
{
    if (x <= 0)
        return 0;
    return (x % 2 == 0 ? 0 : 1) + countSetBitsUtil(x / 2);
}
int main()
{
    int n = 4;
    printf("Total set bit count is %d", countSetBits(n));
    return 0;
}*/
/*// Program to find whether a no is power of two
#include <bits/stdc++.h>
using namespace std;
bool isPowerOfTwo(int n)
{
    if (n == 0)
        return false;
    return (ceil(log2(n)) == floor(log2(n)));
}

int main()
{
    isPowerOfTwo(31) ? cout << "Yes" << endl : cout << "No" << endl;
    isPowerOfTwo(64) ? cout << "Yes" << endl : cout << "No" << endl;
    return 0;
}*/
/*// Find position of the only set bit
#include <bits/stdc++.h>
using namespace std;

int isPowerOfTwo(unsigned n)
{
    return n && (!(n & (n - 1)));
}
int findPosition(unsigned n)
{
    if (!isPowerOfTwo(n))
        return -1;
    unsigned count = 0;
    while (n)
    {
        n = n >> 1;
        ++count;
    }
    return count;
}
int main(void)
{
    int n = 0;
    int pos = findPosition(n);
    (pos == -1) ? cout << "n = " << n << ", Invalid number\n" : cout << "n = " << n << ", Position " << pos << endl;

    n = 12;
    pos = findPosition(n);
    (pos == -1) ? cout << "n = " << n << ", Invalid number\n" : cout << "n = " << n << ", Position " << pos << endl;

    n = 128;
    pos = findPosition(n);
    (pos == -1) ? cout << "n = " << n << ", Invalid number\n" : cout << "n = " << n << ", Position " << pos << endl;

    return 0;
}*/
/*// Copy set bits in a range
#include <bits/stdc++.h>
using namespace std;
void copySetBits(unsigned &x, unsigned y, unsigned l, unsigned r)
{
    if (l < 1 || r > 32)
        return;
    for (int i = l; i <= r; i++)
    {
        int mask = 1 << (i - 1);
        if (y & mask)
            x = x | mask;
    }
}

int main()
{
    unsigned x = 10, y = 13, l = 2, r = 3;
    copySetBits(x, y, l, r);
    cout << "Modified x is " << x;
    return 0;
}*/
/*// Divide two integers without using multiplication, division and mod operator
#include <bits/stdc++.h>
using namespace std;
int divide(int dividend, int divisor)
{
    int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;

    dividend = abs(dividend);
    divisor = abs(divisor);

    int quotient = 0;
    while (dividend >= divisor)
    {
        dividend -= divisor;
        ++quotient;
    }
    if (sign == -1)
        quotient = -quotient;

    return quotient;
}

int main()
{
    int a = 10, b = 3;
    cout << divide(a, b) << "\n";
    a = 43, b = -8;
    cout << divide(a, b);
    return 0;
}*/
/*// Calculate square of a number without using *, / and pow()
#include <bits/stdc++.h>
using namespace std;
int square(int n)
{
    if (n == 0)
        return 0;
    if (n < 0)
        n = -n;
    int x = n >> 1;
    if (n & 1)
        return ((square(x) << 2) + (x << 2) + 1);
}
int main()
{
    for (int n = 1; n <= 5; n++)
        cout << "n = " << n << ", n^2 = " << square(n)
             << endl;
    return 0;
}*/
/*// Power Set
#include <iostream>
#include <math.h>
using namespace std;
class gfg
{

public:
    void printPowerSet(char *set, int set_size)
    {
        unsigned int pow_set_size = pow(2, set_size);
        int counter, j;
        for (counter = 0; counter < pow_set_size; counter++)
        {
            for (j = 0; j < set_size; j++)
            {
                if (counter & (1 << j))
                    cout << set[j];
            }
            cout << endl;
        }
    }
};
int main()
{
    gfg g;
    char set[] = {'a', 'b', 'c'};
    g.printPowerSet(set, 3);
    return 0;
}*/
/*//Generate 0 and 1 with 25% and 75% probability
#include <bits/stdc++.h>
using namespace std;
int rand50()
{
    return rand() & 1;
}
bool rand75()
{
    return rand50() | rand50();
}
int main()
{
    srand(time(NULL));
    for (int i = 0; i < 50; i++)
        cout << rand75();
    return 0;
}*/
