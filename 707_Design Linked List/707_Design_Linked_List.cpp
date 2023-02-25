#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

/*
note: 
    題目如果沒有先表示已經有寫node的struct/class的話
    要自己寫一個
    
improve:
    
*/

// Class Solution copy here
class MyLinkedList {
public:

    // 本題沒有node的struct
    struct LinkedNode {
        int val;
        LinkedNode* next;
        LinkedNode(int val):val(val), next(nullptr){}
    };

    // dummyhead 的好處是當 list 為空時也不會有nullpointer的問題
    // length主要方便at index相關邊界檢查
    LinkedNode* dummyhead;
    int length;

    MyLinkedList() { // initializer
        dummyhead = new LinkedNode(0);
    }
    
    int get(int index) { // get index value not found then return -1
        LinkedNode* tmp = dummyhead;
        int count = -1;
        while (tmp->next && count < index)
        {
            tmp = tmp->next;
            count++;
        }
        
        if (count == index)
        {
            return tmp->val;
        }
        else
        {
            return -1;
        }
    }
    
    void addAtHead(int val) { // add before head
        LinkedNode* newNode = new LinkedNode(val);

        if(dummyhead->next){ //需要做這個? 還是nullptr可以用=傳遞
            newNode->next = this->dummyhead->next;
            this->dummyhead->next = newNode;
        }
        else{
            this->dummyhead->next = newNode;
        }
    }
    
    void addAtTail(int val) { // add after last
        LinkedNode* tmp = this->dummyhead;
        while (tmp->next)
        {
            tmp = tmp->next;
        }
        LinkedNode* newNode = new LinkedNode(val);
        tmp->next = newNode;
    }
    
    void addAtIndex(int index, int val) { // add "before" index node //if index == length then add at last
        
        LinkedNode* tmp = dummyhead;
        int count = -1;
        while (tmp->next && count < (index-1))
        {
            tmp = tmp->next;
            count++;
        }
        LinkedNode* newNode = new LinkedNode(val);
        if(this->length != 0){
            newNode->next = tmp->next;
        }
        tmp->next = newNode;

        // (tmp) ---> (newNode) ---> (tmp->next)
    }
    
    void deleteAtIndex(int index) { // 
        LinkedNode* tmp = dummyhead;
        int count = 0;
        while (tmp->next && count < index-1)
        {
            tmp = tmp->next;
            count++;
        }
        tmp->next = tmp->next->next;
        delete tmp->next;
    }
};




// test function
int main(){

    // Your MyLinkedList object will be instantiated and called as such:
    MyLinkedList* obj = new MyLinkedList();
    int param_1 = obj->get(index);
    obj->addAtHead(val);
    obj->addAtTail(val);
    obj->addAtIndex(index,val);
    obj->deleteAtIndex(index);
    
    // given values
    vector<int> nums = {0};
    int target = 0;

    // call solution function
    Solution s;
    int ans = s.function("arguments");

    // print out answers 
    cout << ans;

    return 0;
}