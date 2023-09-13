#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <math.h>
#include <algorithm>
using namespace std;

/*
question: height-balanced BST
note:
    1. 找 index = length/2 的node作為root 遞迴下去
    2. 
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sorter(nums, 0, nums.size());
    }

    TreeNode* sorter(vector<int>& nums, int low_bound, int high_bound) {
        if (high_bound - low_bound == 0) return nullptr;

        int index = (low_bound+high_bound)/2;
        TreeNode* root = new TreeNode(nums[index]);
        root->left  = sorter(nums, low_bound, index);
        root->right = sorter(nums, index+1, high_bound);

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

    vector<int> vec = {1,2,3,4,5,6,7};
    Builder builder;
    TreeNode* root = builder.build_tree(vec, 1);
    
    preorder_print(root); 

    return 0;
}