class Solution {
private:
    bool isAlphaNum(char c) {
        if ((c >= '0' && c <= '9') || (tolower(c) >= 'a' && tolower(c) <= 'z')) {
            return true;
        }
        return false;
    }
public:
    bool isPalindrome(string s) {
        int start = 0;
        int end = s.length() - 1;
        while (start <= end) {
            if (!isAlphaNum(s[start])) {
                start++;
                continue;
            } 
            if (!isAlphaNum(s[end])) {
                end--;
                continue;
            }
            if (tolower(s[start]) != tolower(s[end])) {
                return false;
            }
            start++; end--;
        }
        return true;
    }
};