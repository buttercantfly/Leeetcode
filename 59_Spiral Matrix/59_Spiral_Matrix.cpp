#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

/*
note: 
    這題主要要傳達的概念是:

    當有需要很多步驟/判斷式時，先做好情境分析再開始，否則很容易一團亂
    
    基本上用轉一圈當一個循環(跑出一個正方形)
    此外有兩種結束方式
    奇數 => 繞到剩下中心一個點
    偶數 => 以2x2的matrix結束
    
    ***坐標軸的(x,y) 對應的是 程式語言的[y(col)][x(row)]***

improve:
    沒啥好進步

*/

// Class Solution copy here
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n,0));

        int wrx= 0, wry= 0, wrn= 1;

        for (int loop = n-1; loop > 1;loop -= 2)
        {
            // 上
            for (int u = wrx; u < wrx + loop; u++)
            {
                matrix[wry][u] = wrn++;
            }

            // 右 [wrx + loop][r]
            for (int r = wry; r < wry + loop; r++)
            {
                matrix[r][wrx + loop] = wrn++;
            }

            // 下 [d][wry + loop]
            for (int d = wrx + loop; d > wrx; d--)
            {
                matrix[wry + loop][d] = wrn++;
            }

            // 左 [wrx][l]
            for (int l = wry + loop; l > wry; l--)
            {
                matrix[l][wrx] = wrn++;
            }

            wrx++;
            wry++;
        }

        if(n%2 == 0){
            matrix[wry][wrx]     = wrn++;
            matrix[wry][wrx+1]   = wrn++;
            matrix[wry+1][wrx+1] = wrn++;
            matrix[wry+1][wrx]   = wrn;
        }
        else{
            matrix[wrx][wry]     = wrn;
        }

        return matrix;
    }
};


// test function
int main(){
    // given values
    int n = 2;

    // call solution function
    Solution s;
    vector<vector<int>> ans = s.generateMatrix(n);

    // print out answers
    for(int i = 0;i < n;i++){
        cout << "[";
        for (int j: ans[i])
        {
            cout << j <<" ";
        }
        cout << "]" << endl;
    }

    return 0;
}