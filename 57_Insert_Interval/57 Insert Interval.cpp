#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

/*

請重寫一遍 媽的

*/

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        
        // empty condition
        if (intervals.empty()) {
            intervals.push_back(newInterval);
            return intervals;
        }

        // head test
        if (intervals[0][0] > newInterval[1])
        {
            intervals.insert(intervals.begin(), newInterval);
            return intervals;
        }
        
        // first find insert spot
        int insertPoint;
        for (insertPoint = 0; insertPoint < intervals.size(); insertPoint++)
        {
            if (intervals[insertPoint][0] <= newInterval[1] && 
                (insertPoint == intervals.size()-1 || intervals[insertPoint+1][0] > newInterval[0])) {
                if (intervals[insertPoint][1] >=  newInterval[0])
                {
                    intervals[insertPoint][0] = min(intervals[insertPoint][0], newInterval[0]);
                    intervals[insertPoint][1] = max(intervals[insertPoint][1], newInterval[1]);
                    break;
                }
                else
                {
                    if (insertPoint == intervals.size()-1)
                    {
                        intervals.push_back(newInterval);
                        return intervals;
                    }
                    else
                    {
                        insertPoint++;
                        intervals.insert(intervals.begin() + insertPoint, newInterval);
                        break;
                    }
                }
            }
        }
        

        // merge intervals
        while (insertPoint != intervals.size()-1 && intervals[insertPoint][1] >= intervals[insertPoint+1][0])
        {
            intervals[insertPoint][0] = min(intervals[insertPoint][0], intervals[insertPoint+1][0]);
            intervals[insertPoint][1] = max(intervals[insertPoint][1], intervals[insertPoint+1][1]);
            intervals.erase(intervals.begin()+insertPoint+1);
        }
        
        return intervals;
    }
};

// test function
int main(){
    // given values
    vector<vector<int>> nums;
    int target = 0;
    string s = "";

    // call solution function
    /*
    Solution sol;
    int ans = sol.function("arguments");

    // print out answers 
    cout << ans;
    */

    return 0;
}