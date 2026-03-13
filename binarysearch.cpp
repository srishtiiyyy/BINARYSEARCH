/*
=====================================================================
BINARY SEARCH
=====================================================================

Problem:
--------
Given a sorted array of integers `nums` and a target value `target`,
return the index of the target if it exists in the array.
Otherwise return -1.

Binary Search works only on SORTED arrays.

---------------------------------------------------------------------
Example:
---------------------------------------------------------------------
Input:
n = 5
nums = [1,3,5,7,9]
target = 7

Output:
3

Explanation:
7 exists at index 3.

---------------------------------------------------------------------
Company Tags:
---------------------------------------------------------------------
Mastercard, Epic Systems, Walmart, PwC, Morgan Stanley,
Rockstar Games, Western Digital, JPMorgan Chase, Byju's,
Ernst & Young, OYO Rooms, Splunk, DoorDash, GE Healthcare,
Stripe, Wayfair, Lyft, Dropbox, NVIDIA, Shopify, Red Hat,
Ubisoft, McKinsey & Company, KPMG, Teladoc Health,
TCS, Cognizant, Accenture, Infosys, Capgemini, Wipro

---------------------------------------------------------------------
Time Complexity:
---------------------------------------------------------------------
Best Case    : O(1)
Average Case : O(log n)
Worst Case   : O(log n)

---------------------------------------------------------------------
Space Complexity:
---------------------------------------------------------------------
O(1)   (Iterative approach uses constant space)

---------------------------------------------------------------------
Approach:
---------------------------------------------------------------------
1. Initialize two pointers:
   low = 0
   high = n - 1

2. Find middle element:
   mid = (low + high) / 2

3. Compare nums[mid] with target:
   - If equal → return index
   - If nums[mid] < target → search right half
   - If nums[mid] > target → search left half

4. Repeat until low > high

5. If target not found → return -1
=====================================================================
*/

#include <iostream>
#include <vector>
using namespace std;

/*
---------------------------------------------------------------------
Function: binarySearch
Purpose : Searches target element in a sorted array
---------------------------------------------------------------------
Parameters:
nums   -> sorted array
target -> element to search

Returns:
Index of target if found
Otherwise -1
---------------------------------------------------------------------
*/
int binarySearch(vector<int> &nums, int target)
{
    int n = nums.size();
    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        // Calculate middle index
        int mid = (low + high) / 2;

        // Target found
        if (nums[mid] == target)
            return mid;

        // Search in right half
        if (nums[mid] < target)
            low = mid + 1;

        // Search in left half
        else
            high = mid - 1;
    }

    // Target not found
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

    cout << "Enter sorted array elements:\n";
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    int target;
    cout << "Enter target element: ";
    cin >> target;

    int result = binarySearch(nums, target);

    if (result != -1)
        cout << "Target found at index: " << result << endl;
    else
        cout << "Target not found" << endl;

    return 0;
}