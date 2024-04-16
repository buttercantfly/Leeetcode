#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// |x-a|+|x-b|/2

int main() {
    int n,m,tmp,dis,house;
    vector<int> vec;
    cin>>n;
    while (n--) // how many test data
    {
        cin>>m;
        dis = 0;
        vec.clear();
        while (m--) // how many relatives
        {
            cin >> tmp;
            vec.push_back(tmp);
        }
        sort(vec.begin(), vec.end());

        // 這邊其實不用管奇偶(偶數那個就可以代替了)
        if(vec.size()%2) { // 奇數
            house = vec[vec.size()/2];
        }
        else { // 偶數
            house = (vec[vec.size()/2] + vec[vec.size()/2-1])/2;
        }

        for(int i:vec)
        {
            dis += abs(house - i);
        }

        cout << dis << endl;
    }

    return 0;
}