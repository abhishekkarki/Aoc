#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        // Custom comparator to sort logs
        auto comparator = [](const string& log1, const string& log2) {
            // Split the log into identifier and content
            int space1 = log1.find(' ');
            int space2 = log2.find(' ');

            string id1 = log1.substr(0, space1);
            string content1 = log1.substr(space1 + 1);

            string id2 = log2.substr(0, space2);
            string content2 = log2.substr(space2 + 1);

            // Determine if the logs are digit-logs or letter-logs
            bool isDigit1 = isdigit(content1[0]);
            bool isDigit2 = isdigit(content2[0]);

            // Rule 1: Letter-logs come before digit-logs
            if (!isDigit1 && isDigit2) return true;  // Letter-log before digit-log
            if (isDigit1 && !isDigit2) return false; // Digit-log after letter-log

            // Rule 2: Sort letter-logs lexicographically by content, then identifier
            if (!isDigit1 && !isDigit2) {
                if (content1 != content2) {
                    return content1 < content2; // Sort by content
                }
                return id1 < id2; // If content is the same, sort by identifier
            }

            // Rule 3: Digit-logs maintain their original order (no swapping)
            return false;
        };

        // Use stable_sort to ensure digit-logs retain their original order
        stable_sort(logs.begin(), logs.end(), comparator);

        return logs;
    }
};

int main() {
    Solution solution;

    vector<string> logs = {
        "dig1 8 1 5 1",
        "let1 art can",
        "dig2 3 6",
        "let2 own kit dig",
        "let3 art zero"
    };

    vector<string> result = solution.reorderLogFiles(logs);

    cout << "Reordered logs:" << endl;
    for (const string& log : result) {
        cout << log << endl;
    }

    return 0;
}