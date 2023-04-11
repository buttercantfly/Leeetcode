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

// 完全不知道怎麼做的
class Solution {
public:
    // 連接左子樹以及右子樹
    void connectBetween(Node* left, Node* right) {
        connect(left);
        connect(right);

        // 連接左子樹和右子樹間的next
        // 只有right next node才會是next
        for (; left != nullptr; left = left->right) {
            left->next = right;
            right = right->left; // 可以是null->left?
            // 測資沒側到問題?
            // *************題目給的是 "perfect binary tree" ****************************
            // right = null->left?
            // null access?
        }
    }

    Node* connect(Node* root) {
        if (root != nullptr) {
            connectBetween(root->left, root->right);
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