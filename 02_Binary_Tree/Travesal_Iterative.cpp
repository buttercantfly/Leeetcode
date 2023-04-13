#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <stack>
using namespace std;

/*
note: 
    1. preorder : Rlr
        Stack方法
        a. 先把root push進stack
        b. 接下來不斷重複
            (1) pop top (中)
            (2) push right (這樣right會在底下)
            (3) push left  (left在上面)
        注意空node不要push

    2. inorder  : lRr ***********
        Stack + pointer
        a. 一路往left child push到底
        接下來不斷重複
        b. pop top
        c. 找這個pop掉的是否有right child，有的話push進，並一路往left child push到底

    3. postorder: lrR
        => 用preorder的想法跑Rrl
        => 再把它翻轉就好ㄌ

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
class PreorderSolution {
public:
    vector<int> PreorderTraversal(TreeNode* root) {
        stack<TreeNode*> stk;
        TreeNode* node = root;
        vector<int> ret;

        if (root == NULL) return ret; // 空樹直接回傳空vector
        
        stk.push(root);
        while (!stk.empty())
        {
            node = stk.top();
            ret.push_back(node->val);
            stk.pop();
            if (node->left) stk.push(node->left);
            if (node->right) stk.push(node->right);
        }
        return ret;
    }
};


class InorderSolution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;
        TreeNode* cur = root;
        while (cur != NULL || !st.empty()) {
            if (cur != NULL) { // 指针来访问节点，访问到最底层
                st.push(cur); // 将访问的节点放进栈
                cur = cur->left;                // 左
            } else {
                cur = st.top(); // 从栈里弹出的数据，就是要处理的数据（放进result数组里的数据）
                st.pop();
                result.push_back(cur->val);     // 中
                cur = cur->right;               // 右
            }
        }
        return result;
    }
};


class PostorderSolution {
public:
    vector<int> PostorderTraversal(TreeNode* root) {
        stack<TreeNode*> stk;
        TreeNode* node = root;
        vector<int> ret;

        if (root == NULL) return ret; // 空樹直接回傳空vector
        
        stk.push(root);
        while (!stk.empty())
        {
            node = stk.top();
            ret.push_back(node->val); // 中
            stk.pop();
            
            if (node->right) stk.push(node->right); // 右
            if (node->left) stk.push(node->left); // 左
        }

        std::reverse(ret.begin(), ret.end());

        return ret;
    }
};

// test function
int main(){

    return 0;
}