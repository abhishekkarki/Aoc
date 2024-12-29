class Solution {
public:
    string reverseWords(string s) {
        // step 1: reverse the string
        int n = s.length();
        string ans;
        reverse(s.begin(), s.end());

        // step 2: now reverse the words in the string and remove extra space
        for (int i = 0; i < n; i++) {
            string word = "";
            while (s[i] != ' ' && i < n) {
                word += s[i];
                i++;
            }
            reverse(word.begin(), word.end());
            if (word.length() > 0) {
                ans += " " + word;
            }
        }
        return ans.substr(1);
    }
};