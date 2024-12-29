class Solution {
private:
    bool isFreqSame(int arr1[], int arr2[]) {
        for (int i = 0; i < 26; i++) {
            if (arr1[i] != arr2[i]) {
                return false;
            }
        }
        return true;
    }
public:
    bool checkInclusion(string s1, string s2) {
        // making a arry which contains the frequency of the characters of the s1
        int freq[26] = {0};
        for (int i = 0; i < s1.length(); i++) {
            freq[s1[i] - 'a']++;
        }

        int windSize = s1.length();
        // running a window of s1 in s2
        for (int i = 0; i < s2.length(); i++) {
            int winIdx = 0; 
            int idx = i;
            int windFreq[26] = {0};

            while (winIdx < windSize && idx < s2.length()) {
                windFreq[s2[idx] - 'a']++;
                winIdx++;
                idx++;    
            }
            if (isFreqSame(freq, windFreq)) { // found
                return true;
            }
        }
        return false;
    }
};