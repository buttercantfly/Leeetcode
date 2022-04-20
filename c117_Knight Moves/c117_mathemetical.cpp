#include <iostream> // STL與iostream都包含在此行中
#include <vector>
#include <array>


// bfs 盡量不要用recursive 因為很容易有記憶體錯誤產生?
int bfs(int step, std::vector<char> begin, std::vector<char> end){
    std::vector<std::vector<char>> neighbor;
    step++;

    for(int i = -2;i <= 2;i++){
        for(int j = -2;j <=2;j++){
            if(i!=0&&j!=0){
                std::vector<char> mid;
                if(begin[0] + i < 105 && begin[0] + i > 96) mid.push_back(begin[0] + i);
                else break;
                if(begin[0] + i < 105 && begin[0] + i > 96) mid.push_back(begin[0] + i);
                else break;
                if(mid[0] == end[0] && mid[1] == end[0]) return step;
                else neighbor.push_back(mid);
            }
        }
    }

    for(std::vector<char> node:neighbor) return bfs(step, node, end);
}

struct {

    std::string bffer;
    std::stringstream ss;

    void F() {


    }

    void operator()(){
        //

        this->F();

    }

} read_input;


struct {
    std::vector<Node*> stack;

    void clear() {
        //    
    }


    void operator()(const std::vector<Node*>& nodes) {
        //

        this->dtack.clear;

        this->stack.push_back(begin);

        for(int i{0}; i< this->stack.size(); ++i) {

            Node* node{this->stack[i]};



            // push all children of node into this->stack back



        }


    }

} bfs;

int main()
{
    std::ios_base::sync_with_stdio(false);
		// 解決synchronization的效率問題
    std::cin.tie(NULL);
		// 確保cout flush before cin 接收input
		// 常用在需要對話的program
    std::vector<char> begin;
    std::vector<char> end;

    read_input();

    bfs();

    while (true)
    {
        begin.push_back(std::cin.get());
        begin.push_back(std::cin.get());
        std::cin.get();
        end.push_back(std::cin.get());
        end.push_back(std::cin.get());
        std::cin.get();

        int steps = bfs(0, begin, end);

        std::cout << "To get from ";
        for(char i:begin) std::cout <<i;
        std::cout << " to ";
        for(char j:begin) std::cout <<j;
        std::cout <<" takes "<< steps <<" knight moves.\n";

        begin.clear();
        end.clear();
    }
    
    return 0;
}

