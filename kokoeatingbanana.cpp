#include <bits/stdc++.h>
using namespace std;

/*
Problem: Koko Eating Bananas

- You have n piles of bananas (piles[i] = number of bananas in the i-th pile).
- Koko can eat bananas at a fixed speed 'k' (bananas/hour).
- Each hour, Koko eats from one pile only.
  - If the pile has fewer than 'k' bananas, she eats all of them and moves to next pile in the next hour.
- Given h hours, find the minimum integer speed k such that Koko can eat all bananas in h hours.

Example:
Input: piles = [3,6,7,11], h = 8
Output: 4
Explanation: At speed k = 4, Koko can finish all piles within 8 hours.
*/

 // Function to check if Koko can eat all bananas at speed 'speed' within 'h' hours
bool canEatAll(vector<int>& piles, int speed, int h) {
    int hours = 0;
    for (int pile : piles) {
        // Count full hours for this pile
        hours += pile / speed;
        // If there are remaining bananas, take extra hour
        if (pile % speed != 0) hours++;
    }
    return hours <= h; // return true if total hours <= h
}

// Function to find minimum eating speed
int minEatingSpeed(vector<int>& piles, int h) {
    int low = 1; // Minimum possible speed
    int high = *max_element(piles.begin(), piles.end()); // Maximum speed: largest pile

    while (low < high) {
        int mid = low + (high - low) / 2;
        // Check if this speed allows finishing all bananas
        if (canEatAll(piles, mid, h)) {
            high = mid; // try smaller speed
        } else {
            low = mid + 1; // need bigger speed
        }
    }
    return low; // minimum speed to finish all bananas
}

int main() {
    int n, h;
    cout << "Enter number of piles: ";
    cin >> n;

    vector<int> piles(n);
    cout << "Enter pile sizes: ";
    for (int i = 0; i < n; i++) cin >> piles[i];

    cout << "Enter hours: ";
    cin >> h;

    int speed = minEatingSpeed(piles, h);
    cout << "Minimum eating speed: " << speed << endl;

    return 0;
}
