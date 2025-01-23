class Solution {
private:
    //function to find the psee
    vector<int> psee(vector<int>& arr) {
        int n = arr.size();
        vector<int> result(n, -1);
        stack<int> st;

    for (int i = 0; i < n; ++i) {
        while (!st.empty() && arr[i] <  arr[st.top()]) {
            st.pop();
        }
        
        result[i] = !st.empty() ? st.top() : -1;

        st.push(i);
    }
    return result;
    }

    // function to find nse
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

public:
    int sumSubarrayMins(vector<int>& arr) {
        vector<int> pseeResult = psee(arr);
        vector<int> nseResult = nse(arr);
        long long count = 0;
        int mod = (int)1e9 + 7;

        for (int i = 0; i < arr.size(); ++i) {
            int left = i - pseeResult[i];
            int right = nseResult[i] - i;
            count = (count + ((long long)arr[i] * left % mod) * right % mod) % mod;
        }

        return count;
    }
};