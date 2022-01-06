#include <iostream>
using namespace std;


// ITERATION 1
// had a 0ms run time on leetcode, 100th percentile
// I realized halway through that I am stupid and can just do a lookup table.
// Look to iteration 2
/*
string intToRoman(int num) {

    string roman = "";

    while(num > 0){

        if(num - 1000 >= 0){
            roman += "M";
            num -= 1000;
            continue;
        }
        if(num - 900 >= 0){
            roman += "CM";
            num -= 900;
            continue;
        }
        if(num - 500 >= 0){
            roman += "D";
            num -= 500;
            continue;
        }
        if(num - 400 >= 0){
            roman += "CD";
            num -= 400;
            continue;
        }
        if(num - 100 >= 0){
            roman += "C";
            num -= 100;
            continue;
        }
        if(num - 90 >= 0){
            roman += "XC";
            num -= 90;
            continue;
        }
        if(num - 50 >= 0){
            roman += "L";
            num -= 50;
            continue;
        }
        if(num - 40 >= 0){
            roman += "XL";
            num -= 40;
            continue;
        }
        if(num - 10 >= 0){
            roman += "X";
            num -= 10;
            continue;
        }
        if(num - 9 >= 0){
            roman += "IX";
            num -= 9;
            continue;
        }
        if(num - 5 >= 0){
            roman += "V";
            num -= 5;
            continue;
        }
        if(num - 4 >= 0){
            roman += "IV";
            num -= 4;
            continue;
        }
        if(num - 1 >= 0){
            roman += "I";
            num -= 1;
            continue;
        }
    }
    return roman;
}
*/

//ITERATION 2
//runs slower than iteration 1 but far far better code.
string intToRoman(int num) {
    string letters[13] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    int nums[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

    string roman = "";

    for(int i = 0; i < size(nums); i++){
        while(num >= nums[i]){
            roman += letters[i];
            num -= nums[i];
        }
    }

    return roman;
}

int main(){

    cout << intToRoman(58) << endl;

    return 0;
}