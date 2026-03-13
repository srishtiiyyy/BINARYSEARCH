/*
=====================================================================
LOWER BOUND USING BINARY SEARCH
=====================================================================

Problem:
--------
Given a sorted array `nums` of size n and a number `x`,
find the **lower bound** of `x`.

Lower Bound Definition:
-----------------------
The lower bound of x is the **smallest index such that**
nums[index] >= x.

If no such index exists, return n.

---------------------------------------------------------------------

Example:
--------
Input:
nums = [1, 2, 4, 4, 5, 7]
x = 4

Output:
2

Explanation:
nums[2] = 4 which is the first element >= 4.

---------------------------------------------------------------------

Company Tags:
-------------
Morgan Stanley, Western Digital, Qualcomm, Broadcom, Ubisoft,
ARM, Etsy, Instacart, Lyft, Chewy, GE Healthcare,
Siemens Healthineers, Docker, HashiCorp, JPMorgan Chase,
Epic Games, Twilio, Robinhood, Teladoc Health, Optum,
Swiggy, Salesforce, Target, Goldman Sachs, AMD,
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
   ans = n (default if lower bound doesn't exist)

2. Perform Binary Search:
   - If nums[mid] >= x
       → this could be a valid answer
       → store mid in ans
       → search left part for smaller index
   - Else
       → search right half

3. Return ans

=====================================================================
*/

#include <iostream>
#include <vector>
using namespace std;

/*
------------------------------------------------------------
Function: lowerBound
Purpose : Find first index where nums[index] >= x
------------------------------------------------------------
*/
int lowerBound(vector<int> &nums, int x)
{
    int n = nums.size();
    int low = 0;
    int high = n - 1;
    int ans = n;

    while (low <= high)
    {
        // safer mid calculation
        int mid = low + (high - low) / 2;

        // possible answer
        if (nums[mid] >= x)
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
    cout << "Enter element to find lower bound: ";
    cin >> x;

    int result = lowerBound(nums, x);

    if (result == n)
        cout << "Lower bound does not exist in the array\n";
    else
        cout << "Lower bound index: " << result << endl;

    return 0;
}