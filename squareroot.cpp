/*
=====================================================================
FLOOR OF SQUARE ROOT (√n)
=====================================================================

Problem:
--------
Given a non-negative integer n, find the floor value of √n.

👉 Return the largest integer such that:
   (ans * ans) <= n

---------------------------------------------------------------------

Example:
--------
Input:
n = 28

Output:
5

Explanation:
5*5 = 25 ≤ 28
6*6 = 36 > 28

---------------------------------------------------------------------

Company Tags:
-------------
Salesforce, Nutanix, Johnson & Johnson, Oracle, Instacart,
Riot Games, Texas Instruments, McKinsey & Company, Deloitte,
Roblox, Wayfair, Red Hat, Splunk, IBM, Zomato, Freshworks,
Unity Technologies, Bain & Company, Teladoc Health, Airbnb,
Activision Blizzard, Goldman Sachs, Square, Epic Systems, PwC,
TCS, Cognizant, Accenture, Infosys, Capgemini, Wipro

=====================================================================
*/

#include <iostream>
using namespace std;

/*
=====================================================================
1️⃣ BRUTE FORCE (LINEAR SEARCH)
=====================================================================

Time Complexity: O(n)
Space Complexity: O(1)

*/
int floorSqrtBrute(int n)
{
    int ans = 0;

    for (int i = 1; i <= n; i++)
    {
        long long val = 1LL * i * i;

        if (val <= n)
            ans = i;
        else
            break;
    }

    return ans;
}

/*
=====================================================================
2️⃣ OPTIMAL (BINARY SEARCH)
=====================================================================

Time Complexity: O(log n)
Space Complexity: O(1)

Idea:
-----
Search in range [1, n]

*/
int floorSqrtOptimal(int n)
{
    int low = 1, high = n;
    int ans = 0;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        long long val = 1LL * mid * mid;

        if (val <= n)
        {
            ans = mid;      // possible answer
            low = mid + 1;  // try bigger
        }
        else
        {
            high = mid - 1; // reduce
        }
    }

    return ans;
}

/*
=====================================================================
MAIN FUNCTION
=====================================================================
*/

int main()
{
    int n;
    cout << "Enter number: ";
    cin >> n;

    int brute = floorSqrtBrute(n);
    int optimal = floorSqrtOptimal(n);

    cout << "\nBrute Force √n: " << brute << endl;
    cout << "Optimal √n: " << optimal << endl;

    return 0;
}