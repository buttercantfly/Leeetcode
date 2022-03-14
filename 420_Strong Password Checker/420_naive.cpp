#include<vector>
#include<string>
#include<iostream>

/*
    A password is considered strong if the below conditions are all met:

    * It has at least 6 characters and at most 20 characters.
    * It contains at least one lowercase letter, at least one uppercase letter, and at least one digit.
    * It does not contain three repeating characters in a row (i.e., "...aaa..." is weak, but "...aa...a..." is strong, assuming other conditions are met).
    
    Given a string password, return the minimum number of steps required to make password strong. if password is already strong, return 0.

    In one step, you can:

    Insert one character to password,
    Delete one character from password, or
    Replace one character of password with another character.
*/

class Solution {
public:
    int strongPasswordChecker(string password) {

        int lowercase = 1;
        int uppercase = 1;
        int digit     = 1;
        int toDel;
        int toAdd;
        
        int  repeat    = 0;
        vector<int> repeat_len;

        int  cur_rep   = 1;
        char pre_char  = ' ';

        vector<std::string::iterator> constraints;

        for(std::string::iterator it = password.begin(); it != password.end(); ++it) {
            // repeat check
            char c = (char)*it;
            if(pre_char == ' ') pre_char = c;
            else if(pre_char == c){
                cur_rep++;
                if(it == password.end()-1){
                    repeat += cur_rep/3;
                    repeat_len.push_back(cur_rep%3);
                }
            }
            else{ // != c
                if(cur_rep >= 3){
                    repeat += cur_rep/3;
                    repeat_len.push_back(cur_rep%3);
                }
                cur_rep  = 1;
                pre_char = c;
            }

            // lower/upper/digit check
            if(std::isupper(c)) uppercase = 0;
            if(std::islower(c)) lowercase = 0;
            if(std::isdigit(c)) digit = 0;
        }

        // require為需要"增加"或"替換"的
        int require = uppercase + lowercase + digit;
        // repeat為需要"刪除"或"替換"的
        // extend為需要"增加"或"刪除"的
        int length = password.length();

        if(length <= 6 && length > 0){
            int extend = 6 - length; // 需要增加多少
            return std::max(extend, std::max(require, repeat)); //找出最大的就好(每個都是增加or替換)
        }
        else if(length <= 20 && length > 0){
            return std::max(require, repeat); // 都是替換即可
        }
        else if(length > 20){
            // 問題點: 如果repeat極長則不能用"刪除"元素處理，短如長度3則可以
            // solve: 將repeat使用先做刪除(vector[i]-2)再替換(vector[i]/3)去做處理
            int del  = length - 20; // 需要刪除多少元素
            int del_ = del;

            std::sort(repeat_len.begin(), repeat_len.end());

            // 怎樣刪除元素最有效率? => 用最少delete減少repeat的數量
            // 
            for(int i = 0; i < repeat_len.size();i++){
                if(del >= repeat_len[i]+1){
                    del -= repeat_len[i]+1;
                    repeat--;
                }
                else{
                    break;
                }
            }

            while(del >= 3 && repeat > 0){
                del -= 3;
                repeat--;
            }

            return std::max(repeat, require) + del_;
        }
        else return -1;
    }
};

/*

23 5 2

*/