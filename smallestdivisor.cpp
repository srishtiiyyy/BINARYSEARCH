/*
=====================================================================
FIND SMALLEST DIVISOR GIVEN A THRESHOLD
=====================================================================

Problem:
--------
Given an array nums and an integer limit,
find the smallest divisor such that:

    sum( ceil(nums[i] / divisor) ) <= limit

Return that divisor.

---------------------------------------------------------------------

Example:
--------
Input:
nums = [1,2,3,4,5]
limit = 8

Output:
3

---------------------------------------------------------------------

Company Tags:
-------------
NVIDIA, Square, Byju's, Mastercard, Riot Games, DoorDash,
Zynga, Dropbox, Pinterest, Swiggy, HCL Technologies,
Epic Systems, Goldman Sachs, Rakuten, Cloudflare, KPMG,
Broadcom, Unity Technologies, ARM, Zomato, Western Digital,
Epic Games, eBay, PwC, Intel, Google, Microsoft, Amazon,
Meta, Apple, Netflix, Adobe

=====================================================================
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
=====================================================================
1️⃣ BRUTE FORCE
=====================================================================

Time Complexity:
----------------
O(n * max(nums))

Space Complexity:
-----------------
O(1)

*/
int smallestDivisorBrute(vector<int> &nums, int limit)
{
    int maxi = *max_element(nums.begin(), nums.end());

    for (int d = 1; d <= maxi; d++)
    {
        int sum = 0;

        for (int x : nums)
        {
            sum += (x + d - 1) / d; // ceil(x/d)
        }

        if (sum <= limit)
            return d;
    }

    return -1;
}

/*
=====================================================================
2️⃣ OPTIMAL (BINARY SEARCH)
=====================================================================

Time Complexity:
----------------
O(n * log(max(nums)))

Space Complexity:
-----------------
O(1)

*/

// Helper function
int sumByD(vector<int> &nums, int d)
{
    int sum = 0;

    for (int x : nums)
    {
        sum += (x + d - 1) / d; // integer ceil
    }

    return sum;
}

int smallestDivisorOptimal(vector<int> &nums, int limit)
{
    int low = 1;
    int high = *max_element(nums.begin(), nums.end());

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (sumByD(nums, mid) <= limit)
        {
            high = mid - 1; // try smaller divisor
        }
        else
        {
            low = mid + 1; // need bigger divisor
        }
    }

    return low;
}

/*
=====================================================================
MAIN FUNCTION
=====================================================================
*/

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter array:\n";
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    int limit;
    cout << "Enter limit: ";
    cin >> limit;

    int brute = smallestDivisorBrute(nums, limit);
    int optimal = smallestDivisorOptimal(nums, limit);

    cout << "\nBrute Answer: " << brute << endl;
    cout << "Optimal Answer: " << optimal << endl;

    return 0;
}