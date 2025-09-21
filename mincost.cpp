/*
Problem: Minimum Cost to Make Array Equal

You are given:
- nums[]: array of numbers
- cost[]: cost associated with each element

Goal:
- Choose a number 'target' such that changing all elements in nums to 'target'
  incurs the **minimum total cost**, where the cost of changing nums[i] to target
  is |nums[i] - target| * cost[i].

Example:
nums = [1,3,5], cost = [10,100,1000]
If target = 3:
    total cost = |1-3|*10 + |3-3|*100 + |5-3|*1000 = 20 + 0 + 2000 = 2020
We need to find the target that minimizes this cost.
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// Function to calculate total cost for a given target
ll findCost(vector<int>& nums, vector<int>& cost, int target) {
    ll total = 0;
    for (int i = 0; i < nums.size(); i++) {
        // Cost to change nums[i] to target
        total += (ll)abs(target - nums[i]) * cost[i];
    }
    return total;
}

// Function to find minimum total cost
long long minCost(vector<int>& nums, vector<int>& cost) {
    // Search space: between smallest and largest number in nums
    int l = *min_element(nums.begin(), nums.end());
    int h = *max_element(nums.begin(), nums.end());
    ll ans = LLONG_MAX;

    // Binary search to find optimal target
    while (l <= h) {
        int mid = l + (h - l) / 2;

        // Cost for choosing mid and mid+1 as target
        ll cost1 = findCost(nums, cost, mid);
        ll cost2 = findCost(nums, cost, mid + 1);

        // Update answer with minimum cost
        ans = min(cost1, cost2);

        // Move the search space towards smaller cost
        if (cost2 >= cost1) {
            h = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    return (ans == LLONG_MAX) ? 0 : ans;
}

int main() {
    // Example usage
    vector<int> nums = {1, 3, 5};
    vector<int> cost = {10, 100, 1000};

    cout << "Minimum total cost: " << minCost(nums, cost) << endl;  // Output: 2020

    return 0;
}
