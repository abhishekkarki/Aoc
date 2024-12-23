/*
* combination sum problem, given a vector and a target find all the 
* combition of elements whose sum is equal to the target 
*/

#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
//--------------------------------------------------------------------------------------------

void sum(std::vector<int>& list, std::vector<int>& combi, int index, int target, std::vector<std::vector<int>>& result, std::set<std::vector<int>>& s) {

    if (index == list.size() || target < 0) {
        return;
    }

    if (target == 0) {
        if (s.find(combi) == s.end()) {
            result.push_back(combi);
            s.insert(combi);
        }
        return;
    }
    combi.push_back(list[index]);
    // include and increment
    sum(list, combi, index + 1, target - list[index], result, s);
    // include but do not increment
    sum(list, combi, index, target - list[index], result, s); 
    // backtrack
    combi.pop_back();
    // exclude and just increment the index
    sum(list, combi, index + 1, target, result, s);
}
//--------------------------------------------------------------------------------------------
int main() {
    std::vector<int> list = {2, 3, 5};
    std::vector<std::vector<int>> result;
    std::vector<int> combi;
    std::set<std::vector<int>> s;


    for (const auto& i : list) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    int index = 0;
    int target = 8;

    sum(list, combi, index, target, result, s);


    for (const auto& i : result) {
        std::cout << "[";
        for (const auto& j : i) {
            std::cout << j << " ";  
        }
        std::cout << "]" << std::endl;
    }
   
    
    
}