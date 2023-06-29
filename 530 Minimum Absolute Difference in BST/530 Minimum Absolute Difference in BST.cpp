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
    int mini_d = INT_MAX;
    int tmp_d  = INT_MAX;
    int l_max;
    int r_min;

    int getMinimumDifference(TreeNode* root) {
        helper(root);
        return mini_d;
    }

    int get_min(TreeNode* r) {
        if (!r) return INT_MAX/2; // 題目 node.val最大值為 10^5 100001同下意義
        while (r->left)
        {
            r = r->left;
        }
        return r->val;
    }

    int get_max(TreeNode* r) {
        if (!r) return INT_MIN/2;  // 題目 node.val最小值為 0 將回傳值小於0可以將該點排出確定範圍
        while (r->right)
        {
            r = r->right;
        }
        return r->val;
    }

    void helper(TreeNode* root) {
        if (!root) return;

        l_max = get_max(root->left);
        r_min = get_min(root->right);
        tmp_d = min(root->val - l_max, r_min-root->val);
        if (tmp_d < mini_d) mini_d = tmp_d;
        
        getMinimumDifference(root->left) ;
        getMinimumDifference(root->right);
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