#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

/*
string multiply(string num1, string num2) {


    //multiply the numbers individually and then get the addends
    vector<vector<int>> multNums;
    for(int i = num2.size() - 1; i >= 0; i--){
        vector<int> temp;
        for(int x = 0; x < )
        for(int j = num1.size(); j >= 0; j--){
            temp.push_back(int(num2[i]) * int(num1[j]));
        }
        multNums.push_back(temp);
    }

    //add the addens up and get the numbers in each "number space"
    vector<int> soln;
    for(auto &vec : multNums){
        for(int i = 0; i < vec.size(); i++){
            if(i >= soln.size()){
                soln.push_back(vec[i]);
            }
            else{
                soln[i] += vec[i];
            }
        }
    }

    //move them into the correct char locations




    
    
    
    return "";
} 
*/

string multiply(string num1, string num2){

    if(num1 == "0" || num2 == "0"){
        return "0";
    }

    vector<vector<char>> table;

    for(int i = 0; i < (num1.size() + num2.size()); i++){
        vector<char> temp;
        table.push_back(temp);
    }


    for(int i = 0; i < num1.size(); i++){
        for(int j = 0; j < num2.size(); j++){
            string sum = to_string((int(num1[i]) - 48) * (int(num2[j]) - 48));
            if(sum.size() < 2){
                sum = "0" + sum;
            }
            table[j + i].push_back(sum[0]);
            table[j + i + 1].push_back(sum[1]);
        }
    }

    vector<int> soln;

    for(int i = 0; i < table.size(); i++){
        int temp = 0;
        for(int j = 0; j < table[i].size(); j++){
            temp += int(table[i][j]) - 48;
        }   
        soln.push_back(temp);
    }


    for(int i = soln.size() - 1; i > 0; i--){
        while(soln[i] >= 10){
                soln[i - 1] += 1;
                soln[i] -= 10;   
        }
    }

    string solution = "";
    for(int num : soln){
        solution.push_back('0' + num);
    }
    if(solution[0] == '0'){
        solution.erase(0,1);
    }


    return solution;

}









int main(){

    cout << multiply("999", "999")<< endl;

    return 0;
}