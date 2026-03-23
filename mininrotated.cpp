/*
=====================================================================
FIND MINIMUM IN ROTATED SORTED ARRAY
=====================================================================

Problem:
--------
Given a sorted array that has been rotated,
find the minimum element.

Array contains DISTINCT elements.

---------------------------------------------------------------------

Example:
--------
Input:
arr = [4,5,6,7,0,1,2]

Output:
0

---------------------------------------------------------------------

Company Tags:
-------------
Ernst & Young, Nutanix, Red Hat, Optum, HashiCorp,
Philips Healthcare, DoorDash, Target, Ubisoft, Zomato,
Airbnb, Reddit, KPMG, Morgan Stanley, OYO Rooms, Zynga,
Snowflake, Databricks, IBM, Uber, Siemens Healthineers,
Splunk, Shopify, American Express, Twilio,
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
Traverse the array and return the minimum element

Time Complexity:
----------------
O(n)

Space Complexity:
-----------------
O(1)

*/
int findMinBrute(vector<int> &arr)
{
    int mini = INT_MAX;

    for (int x : arr)
        mini = min(mini, x);

    return mini;
}

/*
=====================================================================
2️⃣ OPTIMAL (BINARY SEARCH)
=====================================================================

Approach:
---------
At least one half is always sorted.

If left part is sorted:
    minimum lies at arr[low]

Else:
    minimum lies in unsorted part

Time Complexity:
----------------
O(log n)

Space Complexity:
-----------------
O(1)

*/
int findMinOptimal(vector<int> &arr)
{
    int low = 0, high = arr.size() - 1;
    int ans = INT_MAX;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        // If left half is sorted
        if (arr[low] <= arr[mid])
        {
            ans = min(ans, arr[low]);
            low = mid + 1;
        }
        // Right half sorted OR pivot in left
        else
        {
            ans = min(ans, arr[mid]);
            high = mid - 1;
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

    vector<int> arr(n);

    cout << "Enter rotated sorted array:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int brute = findMinBrute(arr);
    int optimal = findMinOptimal(arr);

    cout << "\nBrute Force Min: " << brute << endl;
    cout << "Optimal Min: " << optimal << endl;

    return 0;
}