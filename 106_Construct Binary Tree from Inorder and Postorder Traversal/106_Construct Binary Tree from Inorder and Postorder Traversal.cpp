#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <unordered_map>;
#include <math.h>
#include <algorithm>
using namespace std;

/*
question:
note:
    
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
    typedef vector<int>::iterator vi;

    TreeNode* buildTreeHelper(vector<int>& postorder, vector<int>& inorder, int postEnd, int inStart, int inEnd, unordered_map<int, int>& map) {
        if (inStart > inEnd) return NULL;
        
        int val = postorder[postEnd];
        TreeNode* root = new TreeNode(val);
        
        int rootIndex = map[val];
        int rightSize = inEnd - rootIndex;
        
        root->left = buildTreeHelper(postorder, inorder, postEnd - rightSize - 1, inStart, rootIndex - 1, map);
        root->right = buildTreeHelper(postorder, inorder, postEnd - 1, rootIndex + 1, inEnd, map);
        
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> map;
        for (int i = 0; i < inorder.size(); i++) {
            map[inorder[i]] = i;
        }
        return buildTreeHelper(postorder, inorder, inorder.size() - 1, 0, inorder.size() - 1, map);
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

// postorder print
void postorder_print(TreeNode* root){
    cout << root->val;
    if(root->left) postorder_print(root->left);
    if(root->right) postorder_print(root->right);
}

int main(){

    vector<int> vec = {1,2,3,4,5,6,7};
    Builder builder;
    TreeNode* root = builder.build_tree(vec, 1);
    
    postorder_print(root); 

    return 0;
}