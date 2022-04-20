#include <vector>
#include <algorithm>

/*

    1. naive
        (1) 每個column先自己排一次 matrix*n*logn
        (2) 再來跟隔壁的row比較，找到適合的排名

    e.g.
    2 2 1   3 1 2     4 2 3    
    1 3 2   1 2 3     1 3 4    
    3 1 3   2 1 3  => 3 1 4 => xxxxx這樣永遠做不好
    1 3 2   1 2 3     1 3 4    

    => n*matrix*logn + n*matrix*logm

    how about sort all elements fisrt?
    => n*matrix*log(n*matrix)
    =>
    7 2 5
    3 4 6
    8 1 9
    3 4 6

    => 要怎樣才能拉到最低?
    => 上下限?
    => 從最小開始定下來
    => 1最小，把c=1的lb(lower_bound)訂為2(1+1), r=2的lb訂為2(1+1) 
    => 2不能動，因為
    => 3可以降成1因為不跟1,2同row/col
    => 4可以降到3 因為同row/col最低是2
    => 依序進行

    => complexity多少? 

    nope

    2. one sort and then a lot of comparison

    => 第二欄的1 2很直接可以安排進去(只需跟第一欄同行數字做比較)
    => 第三欄的發現2跟1都已經有了
    (1)   (2)
    2 1   2 1 2
    1 2   1 2 3+1
    3     3 0 4+1
    1     1 2 3

    => 發現說 會不斷的去做插入的動作(類似樹狀結構node的加入)

    3. 樹狀結構(?)

    用紅黑樹?

    key: 要在加入/更改rank時連動的更改row/column的其他rank


    4. Solution from Discussion:
        key1: group changing for with same value numbers
        key2: same numbers might not in the same group => use union find to group
*/


// 底下的code為 discussion解答，沒自己實作是因為很多部分不知道怎麼實作...
// 比如 1. iterator加入類別&判斷式sort的方式
//     2. union find的意義與用法(這題是用來分組)


// UnionFind是抄discussion的 請仔細看懂find跟union兩個地方
class UnionFind{
public:
    std::unordered_map<int, int> parent;
    int Find(int u) {
        if (u == parent[u]) return u;
        return parent[u] = Find(parent[u]);
    }
    void Union(int u, int v) {
        if (parent.count(u) == 0) parent[u] = u; // 如果沒有該col/row則建立一個
        if (parent.count(v) == 0) parent[v] = v;
        int pu = Find(u), pv = Find(v); 
        if (pu != pv) parent[pu] = pv; // 將x parent指向y (都已經去找root了)
    }
    std::unordered_map<int, vector<int>> getGroups() {
        std::unordered_map<int, vector<int>> groups;
        for (auto const& [u, _] : parent) groups[Find(u)].push_back(u);
        return groups;
    }
};


class Solution {
public:

    // union find(disjoint set)請參考 https://www.notion.so/Union-find-data-structure-Class-bb7214b4967446a087172d230e488b84
    // 把rows跟cols一起處理(反正就cols[i] = rows+cols，就不會撞了)

    std::vector<std::vector<int>> matrixRankTransform(std::vector<std::vector<int>>& matrix) {
        int row = matrix.size(), col = matrix[0].size();
        std::vector<array<int, 3>> elements;       // 全部的元素(包含coordinate)
        std::vector<int> lbs(row + col, 0);  // 包含所有row/col的lower_bound

        for (auto i = 0; i < row; ++i)
            for (auto j = 0; j < col; ++j)
                elements.push_back({matrix[i][j], i, j+row}); // 將元素放進elements中 這邊把col+row 方便後面全部看的時候操作
        
        // 並進行排列
        std::sort(begin(elements), end(elements), [](array<int, 3> &a, array<int, 3> &b){ return a[0] < b[0]; });
        
        // same_v_crds 用來存同樣數字的crd
        std::vector<pair<int, int>> same_v_crds;
        // last_val 則用來找同數字
        int last_val = INT_MIN;
        // for 迴圈開跑所有elements

        // 加一個尾巴 不然底下for迴圈最後一個element會丟失
        elements.push_back({0, INT_MAX, INT_MAX});

        for (auto [val, i, j] : elements) {

            // 確定沒有新元素(當前的element是下次才要處理)
            if ((val != last_val && last_val != INT_MIN) ||
            (i == INT_MAX && j == INT_MAX)) {

                // UnionFind用來分組所有已經放入same_v_crds的crds
                UnionFind uf;
                // 將crds放入uf中(會自動分組)
                for(auto const&[x, y]: same_v_crds) uf.Union(x, y);

                // 把分組結果提出，並找出lower_bound
                // for迴圈跑過一個一個不同root的sets
                for(auto const&[root, group]: uf.getGroups()){

                    int max_lb = 0;

                    max_lb = max(max_lb, lbs[root]); // 跟root的lbs比較
                    for(auto it = group.begin(); it != group.end(); it++){
                        max_lb = max(max_lb, lbs[*it]);// 跟group內所有row/col比較
                    }
                    
                    // 因為max_lb要是"下一個"的lb所以要+1
                    max_lb++;
                    
                    // 把所有max_lb指派給set裡的row/col
                    lbs[root] = max_lb;
                    for(auto it = group.begin(); it != group.end(); it++){
                        lbs[*it] = max_lb;
                    }
                }

                // 跑過所有crds 把matrix內的值更新成lb(lbs已經更新過了)
                // 注意y要-row因為前面是lbs的index 這邊要換成matrix的index
                for(auto[x, y]:same_v_crds) matrix[x][y-row] = lbs[x];

                last_val = val;
                same_v_crds.clear();
            }
            // 先把同樣大小的coordinate收集起來

            // 初始的last_val設置
            if(last_val == INT_MIN) last_val = val;
            same_v_crds.push_back({i, j});
        }
        
        return matrix;
    }
};

/*

    本題檢討:
    1. observation不夠深入，所以沒發現到不同行列的同個數字要分成不同組
    2. union find/ disjoint set學習
    3. 觀察"分組分類"的東西要敏銳一點
    4. trace code要完整的trace 不然會東漏西漏 反而debug搞很久

*/