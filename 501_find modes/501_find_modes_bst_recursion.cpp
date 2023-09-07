#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <math.h>
#include <algorithm>
#include <unordered_map>
using namespace std;

/*
    question: 找眾數
    note:
        利用bst的特性    
        
    improve:
        Follow up: Could you do that without using any extra space?
        (Assume that the implicit stack space incurred due to recursion does not count).
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
    pair<int, int> current_num = make_pair(-1, 0); // <number, how many>
    vector<pair<int, int>> ret;
    vector<int> ret_vec;
    
    vector<int> findMode(TreeNode* root) {
        traversal(root);
        
        if (ret.empty())
        {
            if (current_num.first == -1) return ret_vec;
            else {
                ret_vec.push_back(current_num.first);
                return ret_vec;
            }
        }
        else if (current_num.second > ret[0].second)
        {
            ret.clear();
            ret.push_back(current_num);
        }
        else if (current_num.second == ret[0].second)
        {
            ret.push_back(current_num);
        }
        else if (ret.empty())
        {
            ret.push_back(current_num);
        }

        for (pair<int, int> pr: ret) ret_vec.push_back(pr.first);
        return ret_vec;
    }

    void traversal(TreeNode* node) {
        if (node->left) traversal(node->left);
        if (node->val == current_num.first) current_num.second++;
        else {
            if (current_num.first == -1) {}
            else if (ret.empty())
            {
                ret.push_back(current_num);
            }
            else if (current_num.second > ret[0].second)
            {
                ret.clear();
                ret.push_back(current_num);
            }
            else if(current_num.second == ret[0].second)
            {
                ret.push_back(current_num);
            }
            current_num.first  = node->val;
            current_num.second = 1;
        }
        if (node->right) traversal(node->right);
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