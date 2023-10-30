#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <math.h>
#include <algorithm>
using namespace std;

/*
question:
    You are given the root of a binary tree. 
    We install cameras on the tree nodes where each camera at a node can monitor its parent, itself, and its immediate children.
    Return the minimum number of cameras needed to monitor all nodes of the tree.

note:
    第一直覺就是greedy
    能填滿就填滿
    => 證明?
    
    1. leaf node為camera會浪費最多空間
    因此應該以buttom up的方式執行
    => 從leaf node開始檢查
    => 以recursive方式執行
    
    2. 如何隔兩個node放置攝影機?
    => 利用recursive狀態回傳讓parent能夠知道child經過操作後的狀態
    
    另解: 將node value改掉呢?

    attention: 極端情況
    整棵樹只有一個node

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
private:
    int counter;
    // return 四種情況:
    // 0.   leaf node =>將parent設為 
    //      camera parent =>將parent設為empty node
    // 1.   empty node =>叫parent裝camera
    // 2.   camera =>裝完監視器後，叫parent return 2.

    int placeCamera(TreeNode* root) {
        if (!root) return 0;
        int left  = placeCamera(root->left);
        int right = placeCamera(root->right);
        // 這邊處理的順序很重要        
        if (left == 1||right == 1) { // 小孩為空ndoe
            counter++;
            return 2;
        }
        if (left == 2||right == 2) return 0; // 小孩為camera
        if (left == 0||right == 0) return 1; // 小孩為null或camera parent
        return -1;
    }

public:
    int minCameraCover(TreeNode* root) {
        counter = 0;
        if(placeCamera(root) == 1) counter++;
        return counter;
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

    vector<int> vec = {0,0,-1,0,-1,0,-1,0,-1};
    Builder builder;
    TreeNode* root = builder.build_tree(vec, 1);
    
    preorder_print(root); 

    Solution sol;
    cout << sol.minCameraCover(root) << endl;
    cout << "What is happening" << endl;

    return 0;
}