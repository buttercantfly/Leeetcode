#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <math.h>
#include <algorithm>
using namespace std;

/*
question:
note:
    重點是找到最底層 然後再看最左
improve:
    
*/

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Class Solution copy here
// 層序遍歷?
// bfs => recursive

class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        pair<int, int> pr = findBottomLeftNode(root);
        return pr.second;        
    }

    // pari<height(depth), node value>
    pair<int, int> findBottomLeftNode(TreeNode* root) {
        if (!root) return pair<int, int>(-1, -1); // 設為負一讓其高度一定小於右兄弟（強至選右node的概念）
        else if (!root->left && !root->right) return pair<int, int>(0, root->val);
        else
        {
            pair<int, int> p = findBottomLeftNode(root->left);
            pair<int, int> q = findBottomLeftNode(root->right);
            p.first++;
            q.first++;

            if (q.first > p.first) return q;
            else return p;
        }
    }
};

// test function
class Builder
{
private:
    /* data */
public:
    TreeNode* build_tree(vector<int>& vec, int position)
    {
        if(position > vec.size()) return nullptr;
        TreeNode* root = new TreeNode(vec[position - 1]);
        root->left  = build_tree(vec, position*2);     
        root->right = build_tree(vec, position*2+1);

        return root;
    }
};

// preorder print
void preorder_print(TreeNode* root){
    cout << root->val;
    if(root->left) preorder_print(root->left);
    if(root->right) preorder_print(root->right);
}

int main(){

    vector<int> vec = {1,2,3,4,5,6,7};
    Builder builder;
    TreeNode* root = builder.build_tree(vec, 1);
    
    preorder_print(root); 

    return 0;
}