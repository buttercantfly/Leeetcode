#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <cmath>
#include <algorithm>
using namespace std;

/*
question:
    You are given an integer array ranks representing the ranks of some mechanics. ranksi is the rank of the ith mechanic. 
    A mechanic with a rank r can repair n cars in r * n2 minutes.
    You are also given an integer cars representing the total number of cars waiting in the garage to be repaired.

    Return the minimum time taken to repair all the cars.
    Note: All the mechanics can repair the cars simultaneously.

    ranks = [4,2,3,1], cars = 10
    ans = 16

    ranks = [5,1,8], cars = 6
    ans = 16

note: 
    so with rank r means that mechanic can fix 1 car in r minites

* guessing it is a binary search problem

    1. how to check if an time (possible answer) is valid?
        - calculate how many cars can be fixed in that time with ranks
        - we can compare this number with the time (possible answer)
        - aware: the time is exponentially increasing with the number of cars to fix

    2. kept doing this to find the minimum time

improve:
    
*/

// Class Solution copy here
// so with rank r means that mechanic can fix 1 car in r minites
class Solution {
private:
    // O(N)
    bool carsFixedInTime(vector<int>& ranks, long long time, int cars){
        for(int i = 0; i < ranks.size(); i++){
            cars -= (int)sqrt(time / ranks[i]);
            if(cars <= 0) return true;
        }
        return false;
    }

public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long min = LONG_MAX, max = 0; // min for minimum rank (fastes), max for maximum rank (slowest)
        for(long long i = 0; i < ranks.size(); i++) {
            min = (ranks[i] < min) ? ranks[i] : min;
            max = (ranks[i] > max) ? ranks[i] : max;
        }
        long long div = cars/ranks.size()+1;
        min = min * (div-1) * (div-1);
        max = max * (div) * (div);
        // cars is target number of cars to be fixed
        // 
        while(min < max) {
            long long mid = min / 2 + max / 2;
            if(carsFixedInTime(ranks, mid, cars)) {
                max = mid;
            } else {
                min = mid + 1;
            }
        }

        return min;
    }
};

// test function
int main(){
    // given values
    vector<int> ranks = {3,1,1,1,1,2,2,3,2};
    int cars = 9;
    string s = "";

    // call solution function
    
    Solution sol;
    int ans = sol.repairCars(ranks, cars);

    // print out answers 
    cout << ans;
    

    return 0;
}