#include <iostream>
#include <vector>
#include <set>
using namespace std;


/*
Explanation:

The problem here is given a vector, you need to return the power set,
which is all subsets. 

To do this we use depth first search, because to get every possible set,
we create a tree where you either add the next number to the set or you 
add a blank element to the set. 

*/




void recursive(vector<vector<int>>& v, vector<int>& nums, vector<int> currentSubset, int i){

    if(i >= nums.size()){
        v.push_back(currentSubset);
        return;
    }
    
    //choosing the path where you add the number
    currentSubset.push_back(nums[i]);
    recursive(v, nums, currentSubset, i+1);

    //choosing the path where you add the blank
    currentSubset.pop_back();
    recursive(v, nums, currentSubset, i+1);

}



vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> vec;
    vector<int> cSub;
    recursive(vec, nums, cSub, 0);
    return vec;
}




int main(){
    vector<int> v = {1,2,3};
    vector<vector<int>> vec = subsets(v);

    for(auto i : vec){
        cout << "["; 
        for(int j : i){
            cout << j << ",";
        }
        cout << "]" << endl;
    }

    return 0;
}