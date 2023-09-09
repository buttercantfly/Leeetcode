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
    1. find node
    2. delete node
    3. fix tree
        recursive

    開始 終止 中間
    請多用平板= =
    圖論題尤其是

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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr; // case 1
        if (root->val >  key) root->left  = deleteNode(root->left, key);
        if (root->val <  key) root->right = deleteNode(root->right, key);
        if (root->val == key){
            if (!root->left && !root->right) return nullptr; // case 2
            if (root->left  && !root->right) // case 3
            {
                TreeNode* ret = root->left;
                delete root;
                return ret;
            }
            if (!root->left &&  root->right) // case 4
            {
                TreeNode* ret = root->right;
                delete root;
                return ret;
            }
            if (root->left  &&  root->right) // case 5
            {
                TreeNode* tmp = root->right;

                // 第一步 將右子樹最小值移到 root 位置
                // 第二步 將該最小值之右子移至最小值之位置
                
                if (!tmp->left) // case 5-1
                {
                    tmp->left = root->left;
                    delete root;
                    return tmp;
                }
                
                while (tmp->left->left) tmp = tmp->left;
                TreeNode* rtsNode = tmp->left;

                tmp->left = rtsNode->right;

                rtsNode->left  = root->left;
                rtsNode->right = root->right;

                delete root;
                return rtsNode;
            }
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

    vector<int> vec = {1,2,3,4,5,6,7};
    Builder builder;
    TreeNode* root = builder.build_tree(vec, 1);
    
    preorder_print(root); 

    return 0;
}