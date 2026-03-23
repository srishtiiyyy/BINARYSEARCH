/*
=====================================================================
SINGLE ELEMENT IN SORTED ARRAY
=====================================================================

Problem:
--------
Given a sorted array where every element appears exactly twice
except one element which appears only once,
find that single element.

---------------------------------------------------------------------

Example:
--------
Input:
nums = [1,1,2,2,3,3,4]

Output:
4

---------------------------------------------------------------------

Company Tags:
-------------
McKinsey & Company, GE Healthcare, Roche, Bain & Company,
Visa, OYO Rooms, Intel, Alibaba, Electronic Arts,
HCL Technologies, Morgan Stanley, Rockstar Games, Bungie,
Snowflake, Zoho, Twilio, Uber, Walmart, Salesforce, ARM,
Dropbox, Flipkart, Broadcom, Zomato, Ubisoft,
TCS, Cognizant, Accenture, Infosys, Capgemini, Wipro

=====================================================================
*/

#include <iostream>
#include <vector>
using namespace std;

/*
=====================================================================
1️⃣ BRUTE FORCE (NEIGHBOR CHECK)
=====================================================================

Time Complexity: O(n)
Space Complexity: O(1)

*/
int singleBrute1(vector<int> &nums)
{
    int n = nums.size();

    if (n == 1) return nums[0];

    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            if (nums[i] != nums[i + 1])
                return nums[i];
        }
        else if (i == n - 1)
        {
            if (nums[i] != nums[i - 1])
                return nums[i];
        }
        else
        {
            if (nums[i] != nums[i - 1] && nums[i] != nums[i + 1])
                return nums[i];
        }
    }

    return -1;
}

/*
=====================================================================
2️⃣ BRUTE FORCE (XOR METHOD)
=====================================================================

Time Complexity: O(n)
Space Complexity: O(1)

Key Idea:
---------
a ^ a = 0
0 ^ x = x

*/
int singleBrute2(vector<int> &nums)
{
    int ans = 0;

    for (int x : nums)
        ans ^= x;

    return ans;
}

/*
=====================================================================
3️⃣ OPTIMAL (BINARY SEARCH)
=====================================================================

Time Complexity: O(log n)
Space Complexity: O(1)

Key Idea:
---------
Before single element → pairs start at EVEN index
After single element  → pairs start at ODD index

*/
int singleOptimal(vector<int> &nums)
{
    int n = nums.size();

    // Edge cases
    if (n == 1) return nums[0];
    if (nums[0] != nums[1]) return nums[0];
    if (nums[n - 1] != nums[n - 2]) return nums[n - 1];

    int low = 1, high = n - 2;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        // Found single element
        if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1])
            return nums[mid];

        // Left side correct pattern
        if ((mid % 2 == 0 && nums[mid] == nums[mid + 1]) ||
            (mid % 2 == 1 && nums[mid] == nums[mid - 1]))
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
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

    cout << "Enter sorted array:\n";
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    int b1 = singleBrute1(nums);
    int b2 = singleBrute2(nums);
    int opt = singleOptimal(nums);

    cout << "\nBrute1 Answer: " << b1 << endl;
    cout << "Brute2 (XOR) Answer: " << b2 << endl;
    cout << "Optimal Answer: " << opt << endl;

    return 0;
}