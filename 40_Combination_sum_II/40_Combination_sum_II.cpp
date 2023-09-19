#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

/*
question:

note: 
    
improve:
    
*/

// Class Solution copy here
class Solution {
private:
    vector<vector<int>> ret;
    vector<int> vec;
    int current_sum = 0;

    void combiner(int current_index, vector<int>& candidates, int target) {
        if (current_sum >  target) return;
        if (current_sum == target)
        {
            ret.push_back(vec);
            return;
        }
        for (int i = current_index; i < candidates.size(); i++)
        {
            if (i > current_index && candidates[i-1] == candidates[i]) continue;
            current_sum += candidates.at(i);
            vec.push_back(candidates.at(i));
            combiner(i+1, candidates, target); // i+1?
            current_sum -= candidates.at(i);
            vec.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        combiner(0, candidates, target);
        return ret;
    }
};

// test function
int main(){
    // given values
    vector<int> candidates = {2,3,6,7};
    int target = 7;
    string s = "";

    // call solution function
    
    Solution sol;
    vector<vector<int>> ans = sol.combinationSum2(candidates, target);

    // print out answers 
    for (vector<int> vec:ans)
    {
        for (auto it = vec.begin(); it != vec.end(); it++)
        {
            cout << *it << " ";
        }
        cout << endl;
    }

    return 0;
}