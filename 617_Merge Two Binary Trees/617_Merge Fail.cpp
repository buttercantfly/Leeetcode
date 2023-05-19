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
// 錯誤 這樣 tree1 沒有的 node 不會有值
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        stack<TreeNode*> stk1;
        stack<TreeNode*> stk2;
        TreeNode* tmp1;
        TreeNode* tmp2;
        TreeNode* par1;
        TreeNode* par2;

        int ept = INT_MIN/2;
        bool b1;
        bool b2;

        stk1.push(root1);
        stk2.push(root2);

        while (!stk1.empty() && !stk2.empty())
        {
            tmp1 = stk1.top();
            tmp2 = stk2.top();
            stk1.pop();
            stk2.pop();
            
            // 空點要怎麼表示?
            // val 設成極小值 (INT_MIN/2 < -10^4*2)
            // case 1 兩者為空 => 跳過
            if (tmp1->val == ept && tmp2->val == ept) continue;
            // case 2 tmp1空 => 
            else if(tmp1->val == ept) {
                stk1.push(new TreeNode(ept));
                stk1.push(new TreeNode(ept));
                stk2.push(tmp2->right);
                stk2.push(tmp2->left);
                tmp1->val = tmp2->val;
            }
            else if(tmp2->val == ept) {
                stk1.push(tmp1->right);
                stk1.push(tmp1->left);
                stk2.push(new TreeNode(ept));
                stk2.push(new TreeNode(ept));
                // tmp1->val = tmp1->val;
            }
            else tmp1->val += tmp2->val;

            par1 = tmp1;
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