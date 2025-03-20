#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <unordered_map>
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
    int findRoot(int i) {
        if(mpToSetRoot[i] == i) return i;
        else {
            mpToSetRoot[i] = findRoot(mpToSetRoot[i]);
            return mpToSetRoot[i];
        }
    }

public:
    unordered_map<int, int> mpToSetRoot;
    unordered_map<int, int> setCost; // record set cost
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        // floyd warshall
        // nope it's & operation, not the shortest path
        // find connected component
        // any two vertexes in the same cc would have the same output
        // and if in different cc, means there is no path for them

        // initailization
        for(int i = 0; i < n; i++) {
            mpToSetRoot[i] = i;
        }

        // traverse through the graph
        for(int i = 0; i < edges.size(); i++) {
            int set1 = findRoot(edges[i][0]);
            int set2 = findRoot(edges[i][1]);
            if(!setCost.count(set1)) setCost[set1] = edges[i][2];
            if(!setCost.count(set2)) setCost[set2] = edges[i][2];
            int cost = setCost[set1] & setCost[set2] & edges[i][2];
            // merge sets (1 to 2)
            mpToSetRoot[set1] = set2;
            // update Costs
            setCost[set1] = cost;
            setCost[set2] = cost;
        }

        // now we have all the sets

        vector<int> ret;
        // process answer
        for(vector<int> walk: query) {
            int set1 = findRoot(walk[0]);
            int set2 = findRoot(walk[1]);
            if(set1 != set2) ret.push_back(-1);
            else ret.push_back(setCost[set1]);
        }

        return ret;
    }
};

// test function
int main(){
    // given values
    vector<vector<int>> edges = {{0,1,7},{1,3,7},{1,2,1}};
    vector<vector<int>> query = {{0,3},{3,4}};
    int n = 5;

    // call solution function
    
    Solution sol;
    vector<int> ans = sol.minimumCost(n, edges, query);

    // print out answers 
    for(int i: ans) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}