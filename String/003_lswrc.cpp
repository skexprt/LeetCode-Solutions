#include <unordered_set>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;
        int left = 0;
        int maxLen = 0;

        for (int right = 0; right < s.length(); right++) {
            
            // If duplicate found, shrink window from left
            while (st.count(s[right])) {
                st.erase(s[left]);
                left++;
            }

            // Insert current character
            st.insert(s[right]);

            // Update maximum length
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};
