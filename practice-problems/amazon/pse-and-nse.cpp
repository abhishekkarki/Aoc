#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> previousSmallerElement(vector<int>& arr) {
    int n = arr.size();
    vector<int> result(n, -1);
    stack<int> st;

    for (int i = 0; i < n; ++i) {
        if (!st.empty() && arr[st.top()] >= arr[i]) {
            st.pop();
        }

        if (!st.empty()) {
            result[i] = arr[st.top()];
        }

        st.push(i);
    }
    return result;
}

vector<int> nextSmallestElement(vector<int>& arr) {
    int n = arr.size();
    vector<int> result(n, n);
    stack<int> st;

    for (int i = n - 1; i >= 0; --i) {
        while (!st.empty() && arr[st.top()] >= arr[i]) {
            st.pop();
        }
        
        if (!st.empty()) {
            result[i] = arr[st.top()];
        }

        st.push(i);
    }
    return result;
}

int main() {
    vector<int> arr = {4, 5, 2, 10, 8};
    vector<int> result = previousSmallerElement(arr);

    cout << "Previous Smaller Elements: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    vector<int> result1 = nextSmallestElement(arr);

    cout << "Previous Smaller Elements: ";
    for (int num : result1) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}