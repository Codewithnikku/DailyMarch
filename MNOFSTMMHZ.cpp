#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class minimizeMaxNumberOfSecondsToMakeMountainHeightZero {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long left = 1, right = 1e18;
        
        while (left < right) {
            long long mid = left + (right - left) / 2;
            
            if (can(mid, mountainHeight, workerTimes))
                right = mid;
            else
                left = mid + 1;
        }
        
        return left;
    }
    
    bool can(long long mid, int mountainHeight, vector<int>& workerTimes) {
        long long removed = 0;
        
        for (long long t : workerTimes) {
            
            long long k = (sqrt(1 + (8.0 * mid) / t) - 1) / 2;
            removed += k;
            
            if (removed >= mountainHeight)
                return true;
        }
        
        return false;
    }
};

int main() {
    int mountainHeight = 10;
    vector<int> workerTimes = {3, 2, 2, 4};
    minimizeMaxNumberOfSecondsToMakeMountainHeightZero sol;
    cout << sol.minNumberOfSeconds(mountainHeight, workerTimes) << endl;
    return 0;
}   

/*
Given :
    mountainHeight : the height of the mountain
    workerTimes : the time each worker takes to reduce the height of the mountain by 1 unit
Return :
    the minimum number of seconds required to reduce the height of the mountain to 0

    Constraints :
        1 <= mountainHeight <= 10^9
        1 <= workerTimes.length <= 10^5
        1 <= workerTimes[i] <= 10^6

    Example :
        Input : mountainHeight = 10, workerTimes = [3, 2, 2, 4]
        Output : 12

    Intuition :
        We can use binary search to find the minimum number of seconds required to reduce the height of the mountain to 0.
        We can check if it is possible to reduce the height of the mountain to 0 in mid seconds using the function can.
        If it is possible, we update the right pointer to mid.
        Otherwise, we update the left pointer to mid + 1.

    Approach steps:
        1. Initialize the left pointer to 1 and the right pointer to 1e18.
        2. While the left pointer is less than the right pointer:
            a. Calculate the mid point as (left + right) / 2.
            b. If it is possible to reduce the height of the mountain to 0 in mid seconds, update the right pointer to mid.
            c. Otherwise, update the left pointer to mid + 1.
        3. Return the left pointer.

    Complexity :
        Time : O(n * log(m))
        Space : O(1)

    Code Steps :
        1. Define the function can to check if it is possible to reduce the height of the mountain to 0 in mid seconds.
        2. In the function can, for each worker time t, calculate the maximum number of units of height they can reduce in mid seconds using the formula (sqrt(1 + (8.0 * mid) / t) - 1) / 2.
        3. Add the maximum number of units of height reduced by each worker to the removed variable.
        4. If the removed variable is greater than or equal to the mountainHeight, return true.
        5. Otherwise, return false.
        6. In the main function, initialize the left pointer to 1 and the right pointer to 1e18.
        7. While the left pointer is less than the right pointer:
            a. Calculate the mid point as (left + right) / 2.
            b. If it is possible to reduce the height of the mountain to 0 in mid seconds, update the right pointer to mid.
            c. Otherwise, update the left pointer to mid + 1.
