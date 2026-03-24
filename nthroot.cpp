/*
=====================================================================
NTH ROOT OF A NUMBER
=====================================================================

Problem:
--------
Given two integers N and M, find the integer X such that:

    X^N = M

Return X if it exists, otherwise return -1.

---------------------------------------------------------------------

Example:
--------
Input:
N = 3, M = 27

Output:
3

Explanation:
3^3 = 27

---------------------------------------------------------------------

Company Tags:
-------------
Swiggy, DoorDash, American Express, Morgan Stanley,
Broadcom, Stripe, Qualcomm, Rockstar Games,
Micron Technology, Riot Games, Splunk, Bungie,
Pinterest, Philips Healthcare, Nutanix, Salesforce,
PayPal, Visa, Lyft, Target, OYO Rooms, Epic Systems,
Shopify, Goldman Sachs, McKinsey & Company,
TCS, Cognizant, Accenture, Infosys, Capgemini, Wipro

=====================================================================
*/

#include <iostream>
using namespace std;

/*
=====================================================================
1️⃣ BRUTE FORCE (LINEAR SEARCH)
=====================================================================

Time Complexity:
----------------
O(M * log N)  (due to exponentiation)

Space Complexity:
-----------------
O(1)

*/

// Power function (Exponentiation by squaring)
long long power(long long base, int exp)
{
    long long ans = 1;

    while (exp > 0)
    {
        if (exp % 2)
        {
            ans *= base;
            exp--;
        }
        else
        {
            base *= base;
            exp /= 2;
        }
    }
    return ans;
}

int nthRootBrute(int N, int M)
{
    for (int i = 1; i <= M; i++)
    {
        long long val = power(i, N);

        if (val == M)
            return i;
        if (val > M)
            break;
    }

    return -1;
}

/*
=====================================================================
2️⃣ OPTIMAL (BINARY SEARCH)
=====================================================================

Time Complexity:
----------------
O(log M * N)

Space Complexity:
-----------------
O(1)

*/

// Helper function:
// 1 → equal
// 0 → less than M
// 2 → greater than M
int check(long long mid, int N, int M)
{
    long long ans = 1;

    for (int i = 1; i <= N; i++)
    {
        ans *= mid;

        if (ans > M)
            return 2;
    }

    if (ans == M)
        return 1;

    return 0;
}

int nthRootOptimal(int N, int M)
{
    int low = 1, high = M;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        int res = check(mid, N, M);

        if (res == 1)
            return mid;
        else if (res == 0)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

/*
=====================================================================
MAIN FUNCTION
=====================================================================
*/

int main()
{
    int N, M;
    cout << "Enter N (root): ";
    cin >> N;

    cout << "Enter M (number): ";
    cin >> M;

    int brute = nthRootBrute(N, M);
    int optimal = nthRootOptimal(N, M);

    cout << "\nBrute Answer: " << brute << endl;
    cout << "Optimal Answer: " << optimal << endl;

    return 0;
}