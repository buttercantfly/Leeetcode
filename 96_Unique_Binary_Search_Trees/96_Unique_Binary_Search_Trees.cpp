#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <math.h>
#include <algorithm>
using namespace std;

/*
question:
    given n
    return how many n nodes' unique bst

note:
    n = 1
    a = 1

    n = 2 => 12
    a = 1 + 1 = 2
    1   2
     2 1

    n = 3 => 123
    a = 5
    3*2*1
    重複: -1
     1   1
      3 2
    2     3

    n = 4 => 1234
    a = 9? x14
    1       1       1
     2        3
      3      2
       4       4

    規律找不到
    從dp思考
    把問題先重寫
    完整1~n代表的是不會有"相等"且每種樹有唯一性，所以其實就是找n個node可以構成幾種樹就對了

    完全沒想出來
    slove:
    選第一個node，左子樹和右子樹的會已經先看過(<n)，因此每個dp[n]都是:
    dp[n] = dp[0]dp[n-1] + ... + dp[n-1]dp[0]

improve:
    寫到dp的題目別只想者dp = dp+dp 而是如何從小的dp組到大的dp(正確的!)

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
    int numTrees(int n) {
        vector<int> dp = {1,1};
        for (int i = 2; i <= n; i++)
        {
            int dp_i = 0;
            for (int j = 0; j < i; j++)
            {
                dp_i += dp[j]*dp[i-j-1];
            }
            dp.push_back(dp_i);
        }
        return dp[n];
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

    Solution sol;
    cout << sol.numTrees(5) << endl;
    return 0;
}