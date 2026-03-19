/*
=====================================================================
FIRST AND LAST OCCURRENCE OF ELEMENT (SEARCH RANGE)
=====================================================================

Problem:
--------
Given a sorted array `nums` and a target value `target`,
return the first and last position of target.

If target is not found → return {-1, -1}

---------------------------------------------------------------------

Example:
--------
Input:
nums = [5,7,7,8,8,10]
target = 8

Output:
[3,4]

---------------------------------------------------------------------

Company Tags:
-------------
PayPal, Qualcomm, Zoho, Western Digital, Johnson & Johnson,
Ernst & Young, Roblox, eBay, Walmart, Shopify, Deloitte,
NVIDIA, Goldman Sachs, MongoDB, Etsy, Dropbox, Riot Games,
Flipkart, Bain & Company, Freshworks, Boston Consulting Group,
Philips Healthcare, IBM, Roche, Robinhood,
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

Time Complexity: O(n)
Space Complexity: O(1)

*/
vector<int> searchRangeBrute(vector<int> &nums, int target)
{
    int first = -1, last = -1;

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == target)
        {
            if (first == -1)
                first = i;
            last = i;
        }
    }

    return {first, last};
}

/*
=====================================================================
2️⃣ BINARY SEARCH (FIRST & LAST SEPARATELY)
=====================================================================

Time Complexity: O(log n)
Space Complexity: O(1)

*/
int firstOccurrence(vector<int> &nums, int target)
{
    int low = 0, high = nums.size() - 1;
    int first = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (nums[mid] == target)
        {
            first = mid;
            high = mid - 1; // move left
        }
        else if (nums[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return first;
}

int lastOccurrence(vector<int> &nums, int target)
{
    int low = 0, high = nums.size() - 1;
    int last = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (nums[mid] == target)
        {
            last = mid;
            low = mid + 1; // move right
        }
        else if (nums[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return last;
}

vector<int> searchRangeBetter(vector<int> &nums, int target)
{
    int first = firstOccurrence(nums, target);
    if (first == -1)
        return {-1, -1};

    int last = lastOccurrence(nums, target);
    return {first, last};
}

/*
=====================================================================
3️⃣ OPTIMAL (USING LOWER & UPPER BOUND)
=====================================================================

Time Complexity: O(log n)
Space Complexity: O(1)

*/
int lowerBound(vector<int> &nums, int target)
{
    int low = 0, high = nums.size() - 1;
    int ans = nums.size();

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

int upperBound(vector<int> &nums, int target)
{
    int low = 0, high = nums.size() - 1;
    int ans = nums.size();

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (nums[mid] > target)
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

vector<int> searchRangeOptimal(vector<int> &nums, int target)
{
    int first = lowerBound(nums, target);

    if (first == nums.size() || nums[first] != target)
        return {-1, -1};

    int last = upperBound(nums, target) - 1;

    return {first, last};
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

    int target;
    cout << "Enter target: ";
    cin >> target;

    vector<int> brute = searchRangeBrute(nums, target);
    vector<int> better = searchRangeBetter(nums, target);
    vector<int> optimal = searchRangeOptimal(nums, target);

    cout << "\nBrute: " << brute[0] << " " << brute[1] << endl;
    cout << "Better: " << better[0] << " " << better[1] << endl;
    cout << "Optimal: " << optimal[0] << " " << optimal[1] << endl;

    return 0;
}