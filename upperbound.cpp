/*
=====================================================================
UPPER BOUND USING BINARY SEARCH
=====================================================================

Problem:
--------
Given a sorted array `nums` and a value `x`, find the **upper bound**
of `x`.

Upper Bound Definition:
-----------------------
The upper bound of x is the **smallest index such that**
nums[index] > x.

If no such element exists, return n.

---------------------------------------------------------------------

Example:
--------
Input:
nums = [1,2,4,4,5,7]
x = 4

Output:
4

Explanation:
nums[4] = 5 which is the first element greater than 4.

---------------------------------------------------------------------

Company Tags:
-------------
American Express, Shopify, Stripe, Micron Technology, Intel,
Siemens Healthineers, Square, Bloomberg, Western Digital,
Teladoc Health, Docker, Airbnb, Red Hat, Roblox, Target,
Swiggy, Deloitte, Broadcom, HashiCorp, Pinterest, Optum,
NVIDIA, Zomato, Splunk, Activision Blizzard,
TCS, Cognizant, Accenture, Infosys, Capgemini, Wipro

---------------------------------------------------------------------

Time Complexity:
----------------
O(log n)

Space Complexity:
-----------------
O(1)

---------------------------------------------------------------------

Approach:
---------
1. Initialize:
   low = 0
   high = n - 1
   ans = n (default if upper bound doesn't exist)

2. Perform Binary Search:
   - If nums[mid] > x
        → this could be the answer
        → store mid in ans
        → move left to find smaller valid index
   - Else
        → move right

3. Return ans.

=====================================================================
*/

#include <iostream>
#include <vector>
using namespace std;

/*
------------------------------------------------------------
Function: upperBound
Purpose : Find first index where nums[index] > x
------------------------------------------------------------
*/
int upperBound(vector<int> &nums, int x)
{
    int n = nums.size();
    int low = 0;
    int high = n - 1;
    int ans = n;

    while (low <= high)
    {
        // safer mid calculation to avoid overflow
        int mid = low + (high - low) / 2;

        if (nums[mid] > x)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
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

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter sorted array elements:\n";
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    int x;
    cout << "Enter element to find upper bound: ";
    cin >> x;

    int result = upperBound(nums, x);

    if (result == n)
        cout << "Upper bound does not exist in the array\n";
    else
        cout << "Upper bound index: " << result << endl;

    return 0;
}