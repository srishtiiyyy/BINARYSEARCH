/*
=====================================================================
SEARCH INSERT POSITION
=====================================================================

Problem:
--------
Given a sorted array of distinct integers and a target value,
return the index if the target is found.

If not found, return the index where it would be inserted 
to maintain sorted order.

---------------------------------------------------------------------

Example:
--------
Input:
nums = [1,3,5,6]
target = 2

Output:
1

---------------------------------------------------------------------

Company Tags:
-------------
Oracle, Morgan Stanley, IBM, Shopify, Salesforce, Airbnb,
Rakuten, Western Digital, Alibaba, Zoho, Byju's, OYO Rooms,
Teladoc Health, Intel, Cloudflare, JPMorgan Chase, Square,
Roche, Riot Games, Etsy, MongoDB, Stripe, Robinhood, Optum,
Splunk, TCS, Cognizant, Accenture, Infosys, Capgemini, Wipro

=====================================================================
*/

#include <iostream>
#include <vector>
using namespace std;

/*
=====================================================================
BRUTE FORCE APPROACH (LINEAR SEARCH)
=====================================================================

Approach:
---------
Traverse the array and return the first index where:
nums[i] >= target

If no such element exists → return n

Time Complexity:
----------------
O(n)

Space Complexity:
-----------------
O(1)

*/
int searchInsertBrute(vector<int> &nums, int target)
{
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] >= target)
            return i;
    }
    return nums.size();
}

/*
=====================================================================
OPTIMAL APPROACH (BINARY SEARCH)
=====================================================================

Approach:
---------
This is equivalent to LOWER BOUND:
Find first index where nums[i] >= target

Time Complexity:
----------------
O(log n)

Space Complexity:
-----------------
O(1)

*/
int searchInsertOptimal(vector<int> &nums, int target)
{
    int n = nums.size();
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (nums[mid] >= target)
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

    int target;
    cout << "Enter target: ";
    cin >> target;

    // Brute Force Result
    int bruteAns = searchInsertBrute(nums, target);

    // Optimal Result
    int optimalAns = searchInsertOptimal(nums, target);

    cout << "\nBrute Force Index: " << bruteAns << endl;
    cout << "Optimal Index: " << optimalAns << endl;

    return 0;
}