/*
* Merge Sort
* Time: O(nlog(n))
*/

#include <iostream>
#include <vector>

void merge(std::vector<int>& list, int start, int mid, int end) { //O(n)
    std::vector<int> temp;
    int i = start, j = mid + 1;

    while (i <= mid && j <= end) {
        if (list[i] <= list[j]) {
            temp.push_back(list[i]);
            i++;
        } else {
            temp.push_back(list[j]);
            j++;
        }
    }

    while (i <= mid) {
        temp.push_back(list[i]);
        i++;
    }
    while (j <= end) {
        temp.push_back(list[j]);
        j++;
    }

    for (int index = 0; index < temp.size(); index++) {
        list[index + start] = temp[index];
    }
}

void mergeSort(std::vector<int>& list, int start, int end) { // (log(n))
    if (start < end) {
        int mid = start + (end - start) / 2;
    mergeSort(list, start, mid); // left part
    mergeSort(list, mid + 1, end); // right part

    merge(list, start, mid, end);
    } 
    
}

int main() {
    std::vector<int> list = {12, 2, 6, 1, 77};
    int start = 0;
    int end = list.size() - 1;
    
    mergeSort(list, start, end);

    for (const auto& i : list) {
        std::cout << i << " ";
    }


}