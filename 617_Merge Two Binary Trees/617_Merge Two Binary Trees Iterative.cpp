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
    就traversal就好了
    這邊用層遍例比較好

    !問題
    null的位置怎麼處理?

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
// 在拉node進stack的時候就先處理
// 如果t1沒有t2有
// 則把t1 link到t2 然後把該node直接拿掉(因為底下都會是跟t2一樣)
// 如果t1有t2沒有
// 直接把該node拿掉(因為底下就是t1了 t2不影響)
// 兩者都有就繼續
// "所以stack裡只有t1 t2的情況而已"
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (!root1) return root2;
        if (!root2) return root1;
        
        stack<TreeNode*> stk1;
        stack<TreeNode*> stk2;
        TreeNode* tmp1;
        TreeNode* tmp2;

        stk1.push(root1);
        stk2.push(root2);

        while (!stk1.empty() && !stk2.empty())
        {
            tmp1 = stk1.top();
            tmp2 = stk2.top();
            stk1.pop();
            stk2.pop();
            tmp1->val += tmp2->val;
            if (tmp1->right && tmp2->right)
            {
                stk1.push(tmp1->right);
                stk2.push(tmp2->right);
            }
            else if(tmp2->right)
            {
                tmp1->right = tmp2->right;
            }

            if (tmp1->left && tmp2->left)
            {
                stk1.push(tmp1->left);
                stk2.push(tmp2->left);
            }
            else if(tmp2->left)
            {
                tmp1->left = tmp2->left;
            }
        }

        return root1;
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