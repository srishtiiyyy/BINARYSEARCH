/*
=====================================================================
COUNT OCCURRENCES IN A SORTED ARRAY
=====================================================================

Problem:
--------
Given a sorted array `nums` and a target value `x`,
find the number of times x appears in the array.

---------------------------------------------------------------------

Example:
--------
Input:
nums = [1,2,4,4,4,6,8]
x = 4

Output:
3

---------------------------------------------------------------------

Company Tags:
-------------
Zoho, Amazon, MakeMyTrip

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
Traverse the array and count occurrences of x

Time Complexity:
----------------
O(n)

Space Complexity:
-----------------
O(1)

*/
int countBrute(vector<int> &nums, int x)
{
    int count = 0;
    for (int num : nums)
    {
        if (num == x)
            count++;
    }
    return count;
}

/*
=====================================================================
2️⃣ OPTIMAL (USING BINARY SEARCH)
=====================================================================

Key Idea:
---------
count = upperBound(x) - lowerBound(x)

Time Complexity:
----------------
O(log n)

Space Complexity:
-----------------
O(1)

*/

// Lower Bound → first index where nums[i] >= x
int lowerBound(vector<int> &nums, int x)
{
    int low = 0, high = nums.size() - 1;
    int ans = nums.size();

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

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

// Upper Bound → first index where nums[i] > x
int upperBound(vector<int> &nums, int x)
{
    int low = 0, high = nums.size() - 1;
    int ans = nums.size();

    while (low <= high)
    {
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

int countOptimal(vector<int> &nums, int x)
{
    int lb = lowerBound(nums, x);
    int ub = upperBound(nums, x);

    // If element not present
    if (lb == nums.size() || nums[lb] != x)
        return 0;

    return ub - lb;
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

    cout << "Enter sorted array:\n";
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    int x;
    cout << "Enter element to count: ";
    cin >> x;

    int brute = countBrute(nums, x);
    int optimal = countOptimal(nums, x);

    cout << "\nBrute Force Count: " << brute << endl;
    cout << "Optimal Count: " << optimal << endl;

    return 0;
}