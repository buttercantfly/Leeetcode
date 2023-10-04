#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <map>
#include <unordered_map>
#include <algorithm>
using namespace std;

/*
question:
    You may assume all tickets form 
    at least one valid itinerary. 
    You must use all the tickets once and only once.
 
note: 
    先想intuitive way
    1. JFK 出發
    2. for 迴圈走過所有JFK機票
        2-1. 該機票設為visited
        2-2. for 迴圈走過所有該機場機票
            3-1......
    
    problem:
        1. NlogN sort (應該沒問題?)
        2. worse N^2 traversal time (N + N-1 + N-2 + ... + 1)
        => 因此需要更快的lookup方式

improve:
    使用map進行"自動排序"
    => insert time complexity O(logn)
    所以整體sort time為 O(nlogn)
    
    而透過 unordered map (hash)在提取(search)航班出發地時變為O(1)
    所以尋找單個航班的複雜度為:O(logn) * O(1)
    整體 traversal complexity = O(nlogn)
    
    完整演算法的complexity同為O(nlogn)

*/

// Class Solution copy here
class Solution {
private:
    vector<string> ret = {"JFK"};
    unordered_map<string, map<string, int>> map;

    bool helper(int size, string departure) {
        if (ret.size() == size+1) return true;
        
        for (auto map_it = map[departure].begin(); map_it != map[departure].end();map_it++)
        {
            if (map_it->second > 0)
            {
                map_it->second--;
                ret.push_back(map_it->first);
                if(helper(size, map_it->first)) return true;
                map_it->second++;
                ret.pop_back();
            }
        }

        return false;
    }
    
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        
        for (auto vec: tickets)
        {
            map[vec[0]][vec[1]]++;
        }
        
        helper(tickets.size(), "JFK");
        return ret;
    }
};

// test function
int main(){
    // given values
    vector<vector<string>> tickets = {{"JFK","SFO"},{"JFK","ATL"},{"SFO","ATL"},{"ATL","JFK"},{"ATL","SFO"}};
    

    // call solution function
    
    Solution sol;
    vector<string> ans = sol.findItinerary(tickets);

    for (vector<string> vc:tickets)
    {
        for (string s:vc)
        {
            cout << s << " ";
        }
        cout << endl;
    }
    

    cout << "itinerary" << endl;
    // print out answers 
    for (string str:ans)
    {
        cout << str << ", ";
    }

    return 0;
}