// daily temperature problem using the monotoic stack
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<int> dailyTemperatures(vector<int>& temperatures) {
    int n = temperatures.size();
    stack<int> st;
    vector<int> results(n, 0);

    for (int i = 0; i < n; ++i) {
        while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
            int index = st.top();
            st.pop();
            results[index] = i - index;
        }
        st.push(i);
    }
    return results;
}

int main () {
    vector<int> list = {73,74,75,71,69,72,76,73};
    vector<int> result = dailyTemperatures(list);

    cout << "Days to wait for a warmer temperature: ";
    for (int days : result) {
        cout << days << " ";
    }
    cout << endl;

}
