/*
=====================================================================
FIND ROTATION COUNT IN ROTATED SORTED ARRAY
=====================================================================

Problem:
--------
Given a sorted array that has been rotated k times,
find the number of rotations.

👉 Rotation count = index of minimum element

---------------------------------------------------------------------

Example:
--------
Input:
nums = [4,5,6,7,0,1,2]

Output:
4

Explanation:
Array is rotated 4 times → minimum element (0) at index 4

---------------------------------------------------------------------

Company Tags:
-------------
PwC, Philips Healthcare, Airbnb, Byju's, HCL Technologies,
ARM, Pinterest, Riot Games, Splunk, Goldman Sachs,
Boston Consulting Group, Oracle, Docker, Johnson & Johnson,
Siemens Healthineers, Nutanix, Roblox, Deloitte,
Databricks, Intel, Zoho, Chewy, Epic Games,
Unity Technologies, Salesforce,
TCS, Cognizant, Accenture, Infosys, Capgemini, Wipro

=====================================================================
*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

/*
=====================================================================
1️⃣ BRUTE FORCE
=====================================================================

Approach:
---------
Find minimum element and return its index

Time Complexity:
----------------
O(n)

Space Complexity:
-----------------
O(1)

*/
int findKRotationBrute(vector<int> &nums)
{
    int mini = INT_MAX, index = -1;

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] < mini)
        {
            mini = nums[i];
            index = i;
        }
    }

    return index;
}

/*
=====================================================================
2️⃣ OPTIMAL (BINARY SEARCH)
=====================================================================

Approach:
---------
Find index of minimum element

Time Complexity:
----------------
O(log n)

Space Complexity:
-----------------
O(1)

*/
int findKRotationOptimal(vector<int> &nums)
{
    int low = 0, high = nums.size() - 1;
    int ans = INT_MAX;
    int index = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        // If already sorted
        if (nums[low] <= nums[high])
        {
            if (nums[low] < ans)
            {
                ans = nums[low];
                index = low;
            }
            break;
        }

        // Left sorted
        if (nums[low] <= nums[mid])
        {
            if (nums[low] < ans)
            {
                ans = nums[low];
                index = low;
            }
            low = mid + 1;
        }
        // Right sorted
        else
        {
            if (nums[mid] < ans)
            {
                ans = nums[mid];
                index = mid;
            }
            high = mid - 1;
        }
    }

    return index;
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

    int brute = findKRotationBrute(nums);
    int optimal = findKRotationOptimal(nums);

    cout << "\nBrute Rotation Count: " << brute << endl;
    cout << "Optimal Rotation Count: " << optimal << endl;

    return 0;
}