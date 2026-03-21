/*
=====================================================================
SEARCH IN ROTATED SORTED ARRAY II (WITH DUPLICATES)
=====================================================================

Problem:
--------
Given a rotated sorted array `arr` that may contain duplicates,
determine if a target element exists in the array.

Return true if found, otherwise false.

---------------------------------------------------------------------

Example:
--------
Input:
arr = [2,5,6,0,0,1,2]
target = 0

Output:
true

---------------------------------------------------------------------

Company Tags:
-------------
Robinhood, Twilio, Walmart, Wayfair, Unity Technologies,
Intel, Mastercard, Bain & Company, HashiCorp, Nutanix,
Goldman Sachs, Qualcomm, Epic Systems, Stripe, Etsy,
McKinsey & Company, Databricks, ARM, HCL Technologies,
Freshworks, MongoDB, Byju's, Riot Games, NVIDIA,
GE Healthcare,
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
bool searchBrute(vector<int> &arr, int target)
{
    for (int x : arr)
    {
        if (x == target)
            return true;
    }
    return false;
}

/*
=====================================================================
2️⃣ OPTIMAL (MODIFIED BINARY SEARCH WITH DUPLICATES)
=====================================================================

Key Difference from previous problem:
-------------------------------------
Duplicates may break sorted structure.

So we add this condition:
if(arr[low] == arr[mid] == arr[high])
    shrink search space

Time Complexity:
----------------
Average: O(log n)
Worst:   O(n)   (due to duplicates)

Space Complexity:
-----------------
O(1)

*/
bool searchOptimal(vector<int> &arr, int target)
{
    int low = 0, high = arr.size() - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        // Found target
        if (arr[mid] == target)
            return true;

        // Handle duplicates
        if (arr[low] == arr[mid] && arr[mid] == arr[high])
        {
            low++;
            high--;
            continue;
        }

        // Left sorted
        if (arr[low] <= arr[mid])
        {
            if (arr[low] <= target && target <= arr[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        // Right sorted
        else
        {
            if (arr[mid] <= target && target <= arr[high])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }

    return false;
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

    vector<int> arr(n);

    cout << "Enter rotated sorted array (with duplicates):\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int target;
    cout << "Enter target: ";
    cin >> target;

    bool brute = searchBrute(arr, target);
    bool optimal = searchOptimal(arr, target);

    cout << "\nBrute Force: " << (brute ? "Found" : "Not Found") << endl;
    cout << "Optimal: " << (optimal ? "Found" : "Not Found") << endl;

    return 0;
}