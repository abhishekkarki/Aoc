#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int maxProduct(vector<int>& list) {
    int pre = 0, suf = 0;
    int n = list.size();
    int result = INT_MIN;

    for (int i = 0; i < n; ++i) {
        if (pre == 0) pre = 1;
        if (suf == 0) suf = 1;
    
        pre = pre * list[i];
        suf = suf * list[n - i -1];

        result = max(result, max(pre, suf));
    }
    return result;
}

int main() {
    vector<int> list = {2, 3, -2, 4};
    maxProduct(list);
}