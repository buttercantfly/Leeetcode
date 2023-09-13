#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

/*
question:

note: 
    backtracking都需要確定元素是否已經使用
    這題的話可以用夾的(start <-> n)
    多加一個startindex就可以了
    why? 因為這題的"順序"不影響結果
    且startindex to n 的意思是範圍(不代表真正代表選了什麼)
    另外本題重點是「窮舉」所以從startindex一個一個走過是很intuitive的想法
    (並沒有限制constrain什麼東西)

    回朔使用遞迴，所以基本也一樣要看 開始 終止 過程

improve:
    
*/

// Class Solution copy here
class Solution {
private:
    vector<vector<int>> result; // 存放符合条件结果的集合
    vector<int> path; // 用来存放符合条件结果
    void backtracking(int n, int k, int startIndex) {
        if (path.size() == k) {
            result.push_back(path);
            return;
        }
        for (int i = startIndex; i <= n; i++) { // 可以跟樹中的單node寬度比較
            path.push_back(i); // 处理节点
            backtracking(n, k, i + 1); // 递归
            path.pop_back(); // 回溯，撤销处理的节点
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        result.clear(); // 可以不写
        path.clear();   // 可以不写
        backtracking(n, k, 1);
        return result;
    }
};

// test function
int main(){
    // given values
    vector<int> nums = {0};
    int target = 0;
    string s = "";

    // call solution function
    /*
    Solution sol;
    int ans = sol.function("arguments");

    // print out answers 
    cout << ans;
    */

    return 0;
}