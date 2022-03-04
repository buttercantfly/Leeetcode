#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int head = 0, end = nums.size() - 1;
        while (true) //用遞迴的方式呼叫 quicksort
        {
            int position =  quicksort(nums, head, end);
            if (position == k - 1) return nums[k-1];
            if (position <  k - 1) head = position + 1;
            else                   end  = position - 1;            
        }
    }

    int quicksort(vector<int>& nums, int head, int end) {
        int pivot = nums[head], l = head+1, r = end; //選頭的數當作pivot
        while(l <= r){
            if(nums[l] < pivot && nums[r] > pivot){
                swap(nums[l++], nums[r--]);
            }
            if(nums[l] >= pivot) l++;
            if(nums[r] <= pivot) r--;
        }
        swap(nums[head], nums[r]); //把pivot換到位置上 完成quick sort
        return r; //回傳pivot的位置(第r+1大的數字)
    }
};

int main(){
    vector<int> nums = {6,5,8,7,99,56};
    int k = 3;

    Solution sol;
    printf("%d",sol.findKthLargest(nums, k));
}