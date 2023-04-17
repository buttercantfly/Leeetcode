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
    這邊用 complete binary tree 的特性去思考
    => complete 是由 full binary trees去構成的
    => 一直call subtree確認是不是full binary tree
    => 再把所有subtree node加總

    when to stop?
    single node or full binary tree


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
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        
        int depth = 1;
        TreeNode* cur_l = root;
        TreeNode* cur_r = root;
        while (cur_l->left)
        {
            cur_l = cur_l->left;
            depth++;

            if(!cur_r->right) 
                return 1 + countNodes(root->left) + countNodes(root->right); // recursive
            else cur_r = cur_r->right;
            
            if (!cur_l->left) return pow(2, depth)-1; // full tree
        }
        return 1;  // single node
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