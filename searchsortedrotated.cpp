/*
=====================================================================
SEARCH IN ROTATED SORTED ARRAY
=====================================================================

Problem:
--------
Given a sorted array that is rotated at some pivot,
find the index of target element k.

If not found → return -1

Array has DISTINCT elements.

---------------------------------------------------------------------

Example:
--------
Input:
nums = [4,5,6,7,0,1,2]
k = 0

Output:
4

---------------------------------------------------------------------

Company Tags:
-------------
Deloitte, Square, Reddit, Roblox, MongoDB, Zynga,
Teladoc Health, Ernst & Young, Nutanix, GE Healthcare,
Western Digital, Medtronic, ARM, Snowflake, Cloudflare,
Qualcomm, McKinsey & Company, IBM, Twilio, Chewy,
Lyft, Seagate Technology, NVIDIA, Epic Games, Walmart,
TCS, Cognizant, Accenture, Infosys, Capgemini, Wipro

=====================================================================
*/

#include <iostream>
#include <vector>
using namespace std;

/*
=====================================================================
1️⃣ BRUTE FORCE
=====================================================================

Approach:
---------
Linear search

Time Complexity:
----------------
O(n)

Space Complexity:
-----------------
O(1)

*/
int searchBrute(vector<int> &nums, int k)
{
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == k)
            return i;
    }
    return -1;
}

/*
=====================================================================
2️⃣ OPTIMAL (MODIFIED BINARY SEARCH)
=====================================================================

Approach:
---------
At least one half is always sorted.

1. Check if left half is sorted
2. If yes → check if target lies in left
3. Else → search right
4. Else case → right half sorted

Time Complexity:
----------------
O(log n)

Space Complexity:
-----------------
O(1)

*/
int searchOptimal(vector<int> &nums, int k)
{
    int low = 0, high = nums.size() - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        // Found target
        if (nums[mid] == k)
            return mid;

        // Left half sorted
        if (nums[low] <= nums[mid])
        {
            if (nums[low] <= k && k <= nums[mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        // Right half sorted
        else
        {
            if (nums[mid] <= k && k <= nums[high])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
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
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter rotated sorted array:\n";
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    int k;
    cout << "Enter target: ";
    cin >> k;

    int brute = searchBrute(nums, k);
    int optimal = searchOptimal(nums, k);

    cout << "\nBrute Force Index: " << brute << endl;
    cout << "Optimal Index: " << optimal << endl;

    return 0;
}