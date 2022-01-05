#include <iostream>
using namespace std;

// ITERATION 1
//Time complexity O(n/2) ~ O(n)
//Used a loop here because it felt intuitive albeit slow
/*
bool isPalindrome(int x) {
        string xstr = to_string(x);
        int size = xstr.size();
        for(int i = 0; i < size / 2; i++){
            if(xstr[i] != xstr[size - i - 1]){
                return false;
            }
         }
        return true;
    }
*/

//ITERATION 2
//time complexity: O(n) because reverse takes O(n)
//In this one I used substrings and then reversed the second one and checked for equality

bool isPalindrome(int x) {
    string xstr = to_string(x);
    int size = xstr.size();
    string firstHalf = xstr.substr(0, size / 2);
    string secondHalf = xstr.substr(size % 2 == 0 ? size / 2 : size / 2 + 1, size - 1);
    
    reverse(secondHalf.begin(), secondHalf.end());

    if(firstHalf == secondHalf){
        return true;
    }
    return false;
}



int main(){

    cout << isPalindrome(123321);

    return 0;
}