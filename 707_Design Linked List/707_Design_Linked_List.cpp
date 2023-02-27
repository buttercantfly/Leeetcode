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

    本題慢慢寫就一次過
    以後記得就是想清楚再開始
    每步都搞清楚自己在幹嘛就會很順
    
improve:
    length存在的必要?
    => 應該是必要的，通過amortize(每次insert/delete多O(1))，減少out of range的損失(可能是O(N))
    
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
        length = 0;
    }
    
    int get(int index) { // get index value not found then return -1
        LinkedNode* tmp = dummyhead;
        int count = -1;

        while (tmp->next && count < index)
        {
            tmp = tmp->next;
            count++;
        }
        
        if (count == index) return tmp->val;
        else return -1;
    }
    
    void addAtHead(int val) { // add before head
        LinkedNode* newNode = new LinkedNode(val);

        // nullptr be assigned?
        newNode->next = this->dummyhead->next;
        this->dummyhead->next = newNode;
        this->length++;

        /*
        if(dummyhead->next){ //需要做這個? 還是nullptr可以用=傳遞
            newNode->next = this->dummyhead->next;
            this->dummyhead->next = newNode;
        }
        else{
            this->dummyhead->next = newNode;
        }
        */
    }
    
    void addAtTail(int val) { // add after last
        LinkedNode* tmp = this->dummyhead;
        while (tmp->next)
        {
            tmp = tmp->next;
        }
        LinkedNode* newNode = new LinkedNode(val);
        tmp->next = newNode;
        this->length++;
    }
    
    void addAtIndex(int index, int val) { // add "before" index node //if index == length then add at last
        if (index > this->length) return; // out of range
        
        LinkedNode* tmp = dummyhead; // 這邊可能出錯 care
        int count = 0;
        while (tmp->next && count < index)
        {
            tmp = tmp->next;
            count++;
        }

        LinkedNode* newNode = new LinkedNode(val);
        newNode->next = tmp->next;
        tmp->next = newNode;
        // (tmp) ---> (newNode) ---> (tmp->next)
        
        this->length++;
    }
    
    void deleteAtIndex(int index) { 
        if (index >= this->length) return; // out of range

        LinkedNode* tmp = dummyhead;
        int count = 0;
        while (tmp->next && count < index)
        {
            tmp = tmp->next;
            count++;
        }
        LinkedNode* del = tmp->next;
        tmp->next = tmp->next->next;
        delete del;
        this->length--;
    }
};

// test function
int main(){

    int index = 1;
    int val = 10;

    // Your MyLinkedList object will be instantiated and called as such:
    MyLinkedList* obj = new MyLinkedList();
    int param_1 = obj->get(index);
    obj->addAtHead(val);
    obj->addAtTail(val);
    obj->addAtIndex(index,val);
    obj->deleteAtIndex(index);

    return 0;
}