#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <unordered_map>
using namespace std;

/*
note:
    首先設計[遞迴]必須要緊抓的三個要素
    1. parameters and return value
    => 什麼parameter會傳下去，以及傳下去後會return什麼

    2. terminate situation
    => 什麼時候會到底

    3. logic of single layer
    => 每次call function要做什麼

    設計construct的recursive function
    =>
    1. TreeNode* buildTreeHelper(vi preStart, vi inStart, vi inEnd)
        => 只要知道子樹的範圍就夠(在兩個travesal上的範圍)
        => in有start end pre的end用 in的差距去推出來就可

    2. if (inStart == inEnd) return NULL;
        => 當子樹為空時回傳NULL
        (left/right = nullptr)

    3. Logic of Single Layer # 用子樹去想
        最後 找root回傳即可

improve:
    

*/

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*
    post:
    4213657
    In:
    1234567

    => repeatedly to find the root of subtresses

    1.
    build(preorder, inorder)
    find 4 is the root
    split vectors into:
        post: 213 and 657
        in:   123 and 567
    and then call:

    cur.left = build(leftpost, leftin);
    cur.rihgt = build(rightpost, rightin);

    return cur;
*/

/*
    Rllllrrrr
    llllRrrrr

     RllrRlrr
    llRr lRrr

    build(begin_pre, end_pre, begin_in, end_in, preorder, inorder)

*/

// chatGPT 超鬼= =
class Solution {
public:
    typedef vector<int>::iterator vi;

    TreeNode* buildTreeHelper(vector<int>& preorder, vector<int>& inorder, int preStart, int inStart, int inEnd, unordered_map<int, int>& map) {
        if (inStart > inEnd) return NULL;
        
        int val = preorder[preStart];
        TreeNode* root = new TreeNode(val);
        
        int rootIndex = map[val];
        int leftSize = rootIndex - inStart;
        
        root->left = buildTreeHelper(preorder, inorder, preStart + 1, inStart, rootIndex - 1, map);
        root->right = buildTreeHelper(preorder, inorder, preStart + leftSize + 1, rootIndex + 1, inEnd, map);
        
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> map;
        for (int i = 0; i < inorder.size(); i++) {
            map[inorder[i]] = i;
        }
        return buildTreeHelper(preorder, inorder, 0, 0, inorder.size() - 1, map);
    }
};

// test function
int main()
{

    return 0;
}