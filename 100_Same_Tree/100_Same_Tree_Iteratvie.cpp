#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <stack>
#include <math.h>
#include <algorithm>
using namespace std;

/*
question:
note:
    
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
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        else if (!p || !q) return false;
        
        stack<TreeNode*> stk_p;
        stack<TreeNode*> stk_q;
        stk_p.push(p);
        stk_q.push(q);

        while (!stk_p.empty())
        {
            TreeNode* cur_p = stk_p.top();
            stk_p.pop();
            TreeNode* cur_q = stk_q.top();
            stk_q.pop();
            if (cur_p->val != cur_q->val) return false;

            if (cur_p->left && cur_q->left) {
                stk_p.push(cur_p->left);
                stk_q.push(cur_q->left);
            }
            else if(cur_p->left || cur_q->left) return false;

            if (cur_p->right && cur_q->right) {
                stk_p.push(cur_p->right);
                stk_q.push(cur_q->right);
            }
            else if(cur_p->right || cur_q->right) return false;
            
            if (stk_p.size() != stk_q.size()) return false;
        }
        
        return true;
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