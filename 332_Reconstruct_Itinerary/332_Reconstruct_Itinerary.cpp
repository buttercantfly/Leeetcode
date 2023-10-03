#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <unordered_set>
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
    

improve:
    
*/

// Class Solution copy here
class Solution {
private:
    vector<string> ret = {"JFK"};

    bool helper(vector<vector<string>>& tickets, string departure) {
        if (ret.size() == tickets.size()+1) return true;

        for (vector<string>& tk: tickets)
        {
            if (tk[0]!="USED" && tk[0]==departure)
            {
                string tmp = tk[0];
                tk[0] = "USED";
                ret.push_back(tk[1]);
                if(helper(tickets, tk[1])) return true;
                ret.pop_back();
                tk[0] = tmp;
            }
        }

        return false;
    }
    
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        
        auto sorting_fct = [](const vector<string>& s1, const vector<string>& s2) {
            return lexicographical_compare(s1[1].cbegin(), s1[1].cend(), s2[1].cbegin(), s2[1].cend());
        };

        sort(tickets.begin(), tickets.end(), sorting_fct);
        
        helper(tickets, "JFK");
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