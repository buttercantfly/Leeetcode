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
    講義解答是用pair

improve:
    其實這個利用!root回傳false的情況就好了
    就不用那麼多if else if
    但構思的方式是好的 從複雜到精簡 不要追求精簡導致不知道問題在那
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
private:
    vector<vector<int>> ret;
    vector<int> path;
    // count:剩下的target sum
    void traversal(TreeNode* root, int count) {
        if (!root->left && !root->right && count == 0)
        {
            ret.push_back(path);
            return;
        }
        if (!root->left && !root->right) return;

        if (root->left)
        {
            path.push_back(root->left->val);
            traversal(root->left, count - root->left->val);
            path.pop_back(); // 記得回朔
        }
        if (root->right)
        {
            path.push_back(root->right->val);
            traversal(root->right, count - root->right->val);
            path.pop_back(); // 記得回朔
        }
    }

public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        ret.clear();
        path.clear();
        if (!root) return ret;
        path.push_back(root->val);
        traversal(root, targetSum - root->val);
        return ret;
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