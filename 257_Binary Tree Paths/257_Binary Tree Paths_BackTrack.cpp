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
    找到所有root to leaf的path
note:
    backtracking
    same idea as recursive
    but send parameters: ret, path
improve:
    可以精簡 但我懶得弄ㄌ
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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ret;
        vector<int> path = {root->val};
        stack<TreeNode*> stk;
        pathFinder(root, ret, path);
        return ret;
    }

    void pathFinder(TreeNode* cur, vector<string>& ret, vector<int>& path) {
        if (!cur) return;
        if (!cur->left && !cur->right) ret.push_back(printPath(path));

        if (cur->left) { // 往左
            path.push_back(cur->left->val);
            pathFinder(cur->left, ret, path);
        }
        if (cur->right) { // 往右
            path.push_back(cur->right->val);
            pathFinder(cur->right, ret, path);
        }
        // 回朔
        path.pop_back();
    }

    string printPath(vector<int> path) {
        string str = "";
        str += to_string(path[0]);
        for (int i = 1; i < path.size(); i++)
        {
            str += "->";
            str += to_string(path[i]);
        }
        return str;
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