#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <deque>
#include <math.h>
#include <algorithm>
using namespace std;

/*
question:
note:
    
improve:
    遇到在二叉搜索树上求什么最值啊，差值之类的，
    就把它想成在一个有序数组上求最值，求差值，这样就简单多了。

    key point: 問題轉換
    => 如何把一個複雜問題轉換成另一個簡單的問題

    原始的idea是將bst轉成一個排序好的vector(中序)
    然後一個一個比較差值即可

    這題用的是在中序遍歷的過程中就直接比較

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
// review: 中序遍歷
// 兩種做法 1. 遞迴 2. stack
class Solution {
public:
    int mini_d = INT_MAX;
    int last_i = INT_MIN/2; // /2防止 overflow

    void traversal(TreeNode* n) {
        if (!n) return;
        traversal(n->left);
        if (n->val - last_i < mini_d) mini_d = n->val - last_i; // 不要用min() 超慢的 請用判斷式判斷
        last_i = n->val;
        traversal(n->right);
    }

    int getMinimumDifference(TreeNode* root) {
        traversal(root);
        return mini_d;
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