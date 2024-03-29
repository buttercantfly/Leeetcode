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
    其實就照題意寫(找max沒效率?)
    
improve:
    如果先排序呢? 想不到怎做(因為index與)

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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return construct(nums, 0, nums.size());
    }

    TreeNode* construct(vector<int>& nums, int begin, int end) {
        if (begin >= end) return nullptr;
        
        int level_max = begin;
        for (int i = begin; i < end; i++)
        {
            if (nums[i] > nums[level_max]) level_max = i;
        }
        TreeNode* cur = new TreeNode(nums[level_max]);
        cur->left  = construct(nums, begin, level_max);
        cur->right = construct(nums, level_max + 1, end);
        return cur;
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