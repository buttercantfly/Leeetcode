#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <math.h>
#include <stack>
#include <algorithm>
using namespace std;

/*
question:

note:
    可以從迭代法的跑法去想
    => 會是bottom up的iterative
    => DFS
    => stack
    => 用preorder traversal跑過一遍即可(不需要bottom up，由上往下沒差)

    *** 其實這題用啥traversal跑都沒差 ***
    因為本題的要點就是所有node的left right互換就對了
    所以用BFS也可以

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

// preorder traversal
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        stack<TreeNode*> st;
        if (!root) return root;
        st.push(root);
        
        while (!st.empty())
        {
            TreeNode* node = st.top();
            swap(node->left, node->right);
            st.pop();
            if (node->left) st.push(node->left);
            if (node->right) st.push(node->right);
        }

        return root;
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

    vector<int> vec = {4,2,7,1,3,6,9};
    Builder builder;
    TreeNode* root = builder.build_tree(vec, 1);
    
    preorder_print(root); 

    Solution sol;
    sol.invertTree(root);
    cout << endl;
    preorder_print(root);

    return 0;
}