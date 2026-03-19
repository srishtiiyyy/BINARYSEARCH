/*
=====================================================================
FIND FLOOR AND CEIL IN SORTED ARRAY
=====================================================================

Problem:
--------
Given a sorted array `nums` and a number `x`, find:

1. Floor → Largest element ≤ x
2. Ceil  → Smallest element ≥ x

If floor or ceil does not exist, return -1 for that value.

---------------------------------------------------------------------

Example:
--------
Input:
nums = [3, 4, 4, 7, 8, 10]
x = 5

Output:
Floor = 4
Ceil  = 7

---------------------------------------------------------------------

Company Tags:
-------------
Etsy, Lyft, Red Hat, GE Healthcare, KPMG, McKinsey & Company,
Twilio, Chewy, Mastercard, American Express, Cloudflare,
Nutanix, Wayfair, Ubisoft, Johnson & Johnson, PwC, Uber,
Snowflake, Target, Ernst & Young, PayPal, Roblox, Zomato,
Instacart, HashiCorp,
TCS, Cognizant, Accenture, Infosys, Capgemini, Wipro

=====================================================================
*/

#include <iostream>
#include <vector>
using namespace std;

/*
=====================================================================
BRUTE FORCE APPROACH
=====================================================================

Approach:
---------
Traverse the array:
- Track largest element ≤ x (floor)
- Track smallest element ≥ x (ceil)

Time Complexity:
----------------
O(n)

Space Complexity:
-----------------
O(1)

*/
pair<int, int> floorCeilBrute(vector<int> &nums, int x)
{
    int floor = -1, ceil = -1;

    for (int num : nums)
    {
        if (num <= x)
            floor = max(floor, num);

        if (num >= x)
        {
            if (ceil == -1 || num < ceil)
                ceil = num;
        }
    }

    return {floor, ceil};
}

/*
=====================================================================
OPTIMAL APPROACH (BINARY SEARCH)
=====================================================================

Time Complexity:
----------------
O(log n)

Space Complexity:
-----------------
O(1)

*/
int findFloor(vector<int> &nums, int x)
{
    int low = 0, high = nums.size() - 1;
    int ans = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (nums[mid] <= x)
        {
            ans = nums[mid];
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return ans;
}

int findCeil(vector<int> &nums, int x)
{
    int low = 0, high = nums.size() - 1;
    int ans = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (nums[mid] >= x)
        {
            ans = nums[mid];
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return ans;
}

pair<int, int> floorCeilOptimal(vector<int> &nums, int x)
{
    int floor = findFloor(nums, x);
    int ceil = findCeil(nums, x);
    return {floor, ceil};
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
    cout << "Enter value x: ";
    cin >> x;

    // Brute Force
    pair<int, int> brute = floorCeilBrute(nums, x);

    // Optimal
    pair<int, int> optimal = floorCeilOptimal(nums, x);

    cout << "\nBrute Force -> Floor: " << brute.first
         << ", Ceil: " << brute.second << endl;

    cout << "Optimal -> Floor: " << optimal.first
         << ", Ceil: " << optimal.second << endl;

    return 0;
}