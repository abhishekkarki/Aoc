#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Previous Smaller or Equal Element
vector<int> psee(vector<int>& arr) {
    int n = arr.size();
    vector<int> result(n, -1);
    stack<int> st;

    for (int i = 0; i < n; ++i) {
        while (!st.empty() && arr[i] < arr[st.top()]) {
            st.pop();
        }
        result[i] = !st.empty() ? st.top() : -1;
        st.push(i);
    }
    return result;
}

// Next Smaller Element
vector<int> nse(vector<int>& arr) {
    int n = arr.size();
    vector<int> result(n, n);
    stack<int> st;

    for (int i = n - 1; i >= 0; --i) {
        while (!st.empty() && arr[i] <= arr[st.top()]) {
            st.pop();
        }
        result[i] = !st.empty() ? st.top() : n;
        st.push(i);
    }
    return result;
}

// Previous Greater or Equal Element
vector<int> pgee(vector<int>& arr) {
    int n = arr.size();
    vector<int> result(n, -1);
    stack<int> st;

    for (int i = 0; i < n; ++i) {
        while (!st.empty() && arr[i] > arr[st.top()]) {
            st.pop();
        }
        result[i] = !st.empty() ? st.top() : -1;
        st.push(i);
    }
    return result;
}

// Next Greater Element
vector<int> nge(vector<int>& arr) {
    int n = arr.size();
    vector<int> result(n, n);
    stack<int> st;

    for (int i = n - 1; i >= 0; --i) {
        while (!st.empty() && arr[i] >= arr[st.top()]) {
            st.pop();
        }
        result[i] = !st.empty() ? st.top() : n;
        st.push(i);
    }
    return result;
}

// Function to calculate the sum of subarray ranges
long long sumOfSubarrayRanges(vector<int>& arr) {
    // Compute indices for minimums
    vector<int> pseeResult = psee(arr);
    vector<int> nseResult = nse(arr);

    // Compute indices for maximums
    vector<int> pgeeResult = pgee(arr);
    vector<int> ngeResult = nge(arr);

    long long sumMax = 0, sumMin = 0;

    for (int i = 0; i < arr.size(); ++i) {
        // Contribution as a maximum
        long long leftMax = i - pgeeResult[i];
        long long rightMax = ngeResult[i] - i;
        sumMax += (long long)arr[i] * leftMax * rightMax;

        // Contribution as a minimum
        long long leftMin = i - pseeResult[i];
        long long rightMin = nseResult[i] - i;
        sumMin += (long long)arr[i] * leftMin * rightMin;
    }

    return sumMax - sumMin;
}

int main() {
    vector<int> list = {-31372, 86677, 70463, 37727, -91683, -41347, -90576, -82174, -84198, -5148, -12591, -34156, 49770, 9666, -77075, -57678, -31101, -47531, -86306, -91337, -89507, -24917, -87692, -39171, 98075, 17787, -42549, 34352, -70752, 71832, 70055, -1026, 3784, 2190, -36669, 959, 50619, 97129, 77088, 54049, 51707, 72052, 59230, -96834, -14048, -9619, 84853, 99362, 69885, 74086, -28737, 23060, -63323, 13156, -72998, 94336, -75409, 58266, -86800, -54564, 80773, 40687, -47207, 43609, -56556, 21192, -48024, -58907, 1629, -65561, -68397, 31862, -2201, -34966, 43542, -59201, -3637, -21936, -93559, 49435, 23249, -54299, 70508, -90795, -3620, -33894, 43927, 10208, -7390, 86931, 48175, 81859, 95058, -16614, 38066, -99361, 63621, -99285, -47111, 29933, 73901, 60455, 46586, -84117, 35256, -89853, 33383, -91662, 82979, -48835, -93877, -80929, -98904, -47773, 69451, 85183, -14449, -51496, 75765, 35062, 12456, 35254, -16363, 80792, -3414, 9244, 62961, -52057, 56344, -50277, -26870, -63323, 54993, 75596, -93637, -78526, -3058, -30560, 82233, -50795, -5290, -641, -83040, 13524, 86725, 23735, 29280, 43938, -43995, -8992, -83717, -62090, 74538, 58682, -56550, -8638, 61528, -87974};

    cout << "The sum of subarray ranges is: " << sumOfSubarrayRanges(list) << endl;
    return 0;
}