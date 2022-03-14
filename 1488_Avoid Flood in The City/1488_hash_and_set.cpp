#include <vector>
#include <iostream>
#include <unordered_map>

/*

rains[]: 為各天的降雨情形，value是指會下雨到哪個湖
         ，而當該天不下雨則可以dry一個lake
return 一個array去決定當rains[i] = 0 時要讓哪個湖dry才不會有flood產生

*/

class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        // 儲存各個湖的降雨天是那些(用來找什麼時候dry) key: which lake, value: rains' index
        // 此處利用hash的讀取優勢(O(1))來降低複雜度
        unordered_map<int, int> rainy_lakes;
        // 儲存晴天是那些(怎麼放) index
        // 為什麼用set? 因為其讀取跟放置皆為logN 能將時間複雜度降低(vector的話在處理中間元素會是O(N))
        set<int> sunny_days;
        // 答案vector
        vector<int> ans(n,-1);

        for(int i = 0;i < n;i++){
            int lake = rains[i];

            if(lake == 0){
                sunny_days.insert(i);
            }
            else{

                if(!rainy_lakes.insert(std::pair<int, int>(lake, i)).second){
                    int  index = rainy_lakes[lake];
                    bool ispos = false;
                    for(std::set<int>::iterator it = sunny_days.begin(); it != sunny_days.end(); ++it){
                        if(*it > index && *it < i){
                            ans[*it] = lake;
                            sunny_days.erase(it);
                            rainy_lakes[lake] = i;
                            ispos = true;
                            break;
                        }else if(*it > i) break;
                    }
                    if(!ispos){
                        return {};
                    }
                }
            }
        }

        if (!sunny_days.empty())
        {
            for(int i:sunny_days){
                ans[i] = 1;
            }
        }
        

        return ans;
    }
};