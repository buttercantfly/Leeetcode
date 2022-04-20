#include <iostream> // STL與iostream都包含在此行中


/*

    怎樣寫code
    => 可以先在main/ 主要程式把各種我想做到的事寫成pseucode
    => 再去implement所有東西

*/

/*

管上下左右太麻煩ㄌ 放棄

設棋盤如下

ASCII:
  616263.....
  a b c ..... f g h
1
2
.
.
.
7
8

dimension 標示end的位置
0 為 正上方
1 為 右上方
2 為 正右方
依此類推
7 為 左上方

int dimenesion(char[] begin, char[] end){
    if(begin[0] == end[0]){
        if(begin[1] < end[1])      return 0;  // 正上
        else if(begin[1] < end[1]) return 4;  // 正下
        else                       return -1; // 原點
    }
    else if(begin[0] > end[0]){ //end在右邊
        if(begin[1] < end[1])      return 1;  // 右上
        else if(begin[1]== end[1]) return 2;  // 正右
        else                       return 3;  // 右下
    }
    else{
        if(begin[1] > end[1])      return 5;  // 左下
        else if(begin[1]== end[1]) return 6;  // 正左
        else                       return 7;  // 左上
    }
}
*/

/*

    怎樣寫code
    => 可以先在main/ 主要程式把各種我想做到的事寫成pseucode
    => 再去implement所有東西

*/


int main()
{
    std::ios_base::sync_with_stdio(false);
		// 解決synchronization的效率問題
    std::cin.tie(NULL);
		// 確保cout flush before cin 接收input
		// 常用在需要對話的program
	cout << "Hello World!";
    return 0;
}


/*

4 3 2 3 2 3 2 3 4
3 2 3 2 3 2 3 2 3
2 3 2 1 2 1 2 3 2
3 2 1 2 3 2 1 2 3
2 3 2 3 0 3 2 3 2
3 2 1 2 3 2 1 2 3
2 3 2 1 2 1 2 3 2
3 2 3 2 3 2 3 2 3
4 3 2 3 2 3 2 3 4

*/

/*

用範圍去抓?
角落的話不能用表解
一步的下一步?
=> 圖論的BFS?

unordered set?

root
level 1 => 
level 2 => 
level 3 => 

class nodes{
    nodes parent;
    int   level;
}

unoerdered_map<>


*/

class node
{
public:
    unordered_map<string, node> graph;
    node(string begin, string end){

    };

    getlevel(string crd){
        return graph[crd];
    }
};
