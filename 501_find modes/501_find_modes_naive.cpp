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
    因為有多個眾數
    => 需要儲存當前travel過的眾數資料

    1. 最直接的方式: travel整個樹，用map<int,int>紀錄數量並排序，即可得出答案
        => 任何資料儲存方式都可以用這種方式
    2. 利用bst的特性    
        => 中序遍歷的特性
    
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
    unordered_map<int, int> map;

    vector<int> findMode(TreeNode* root) {
        // 遍歷bst 每看過一個數就++對應的樹
        traversal(root);
        // 這邊的用法請記住 => 怎麼把pair排序(依照first or second)
        vector<pair<int, int>> vec(map.begin(), map.end());
        sort(vec.begin(), vec.end(), cmp);
        // 將最大的先放進去
        vector<int> ret = {vec[0].first};
        // 檢查有沒有同樣數量的數字
        for (int i = 1; i < vec.size(); i++)
        {
            if (vec[i].second == vec[0].second) ret.push_back(vec[i].first);
            else break;
        }
        // 回傳
        return ret;
    }

    // 多建一個函式供判斷
    bool static cmp (const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    }

    void traversal(TreeNode* node) {
        if (!node) return;
        // 直接用++沒問題(value 預設會是零)
        map[node->val]++; // 遍歷過程將各個數字的數量紀錄下來
        traversal(node->left);
        traversal(node->right);
        return;
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