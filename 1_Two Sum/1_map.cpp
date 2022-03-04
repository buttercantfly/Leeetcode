#include <vector>
#include <algorithm>
#include <unordered_map>

/*
    重點就是在於我們會有[一對]解答，所以解答會是[固定]的
    也就是說我們找到其中一個解答就能找出另一個，因此使用hash map就能有效率地找到對應的key
    **hash table的搜尋時間複雜度為O(1)**

    => 一個一個從vector上掃過 如果hash中沒有對應的key則將掃到的元素丟進hash當中
    => 若是找到對應的key則將此二元素的index回傳(key為元素值，value為index)
*/


class Solution {
public:
        
	std::vector<int> twoSum(std::vector<int> &numbers, int target)
    {
        //Key is the number and value is its index in the std::vector.
        std::unordered_map<int, int> hash;
        std::vector<int> result;
        for (int i = 0; i < numbers.size(); i++) {
            int numberToFind = target - numbers[i];

                //if numberToFind is found in map, return them
            if (hash.find(numberToFind) != hash.end()) {
                result.push_back(hash[numberToFind]);
                result.push_back(i);			
                return result;
            }

                //number was not found. Put it in the map.
            hash[numbers[i]] = i;
        }
        return result;
    }
};