#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <algorithm>
using namespace std;

/*
question:

note:
    又沒注意到null case
improve:

*/

// Class Solution copy here

// Definition for a Node.
class Node
{
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};

class Solution
{
public:
    vector<vector<int>> levelOrder(Node *root)
    {
        queue<Node *> que;
        vector<vector<int>> ret;
        if(!root) return ret;
        vector<int> tmp;
        que.push(root);

        while (!que.empty())
        {
            int level_size = que.size();
            tmp.clear();
            for (int i = 0; i < level_size; i++)
            {
                for (Node *n : que.front()->children)
                    que.push(n);
                tmp.push_back(que.front()->val);
                que.pop();
            }
            ret.push_back(tmp);
        }
        return ret;
    }
};

// test function
int main()
{
    // given values
    vector<int> nums = {0};
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