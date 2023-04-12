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
    注意此題就不只是perfect tree

improve:
    
*/

// Class Solution copy here

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> que;
        vector<Node*> level_vec;
        if (!root) return NULL;
        que.push(root);
        while (!que.empty())
        {
            int level_size = que.size();

            for (int i = 0; i < level_size; i++)
            {
                if (que.front()->left) que.push(que.front()->left);
                if (que.front()->right) que.push(que.front()->right);
                level_vec.push_back(que.front());
                que.pop();
            }

            for (int j = 0; j < level_vec.size(); j++)
            {
                if (j == level_vec.size() - 1) level_vec[j]->next = NULL;
                else level_vec[j]->next = level_vec[j+1];
            }
            
            level_vec.clear();
        }
        return root;
    }
};

// test function
int main(){
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