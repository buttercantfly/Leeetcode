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
    遞迴：
    找到超出範圍的node，超出更多的子代直接刪除，而該node另一側的子代代替其位置

    開始終止過程
    
    開始:
    TreeNode* trimBST(TreeNode* root, int low, int high)

    終止: 
    if root is nullptr return nullptr;

    過程:
    if(root->val < low) {
        delete root and root left child tree;
        return trimBST(root->right);
    }
    else if(root->val > high) {
        delete root and root right child tree;
        return trimBST(root->left);
    }
    else if root val in range(low, high) {
        root->right = trimBST(root->right);
        root->left  = trimBST(root->left);
        return root;
    }

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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(!root) return nullptr;

        if(root->val < low) {
            return trimBST(root->right, low, high);
        }
        else if(root->val > high) {
            return trimBST(root->left, low, high);
        }
        else {
            root->right = trimBST(root->right, low, high);
            root->left  = trimBST(root->left,  low, high);
            return root;
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