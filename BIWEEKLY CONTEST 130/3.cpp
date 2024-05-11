// Minimum Substring Partition of Equal Character Frequency
#include <string>
#include <cstring>
#include <algorithm>

class Solution {
public:
    int dpArray[1002];
    int findSubstrings(int newIndex, std::string &newStr) {
        if (newIndex < 0) return 0;
        if (dpArray[newIndex] != -1) return dpArray[newIndex];
        
        int freq[26] = {0};
        int minSubstrings = 5005;
        
        for (int j = newIndex; j >=0; j--) {
            freq[newStr[j]-'a'] += 1;
            int maxFreq = -1, minFreq = 5005;
            for(int k = 0 ; k < 26; k++) {
                if (freq[k]) {
                    minFreq = std::min(minFreq,freq[k]);
                    maxFreq = std::max(maxFreq,freq[k]);
                }
            }
            if (minFreq == maxFreq)
                minSubstrings = std::min(minSubstrings, 1 + findSubstrings(j-1, newStr));
        }
        return dpArray[newIndex] = minSubstrings;
    }
    int minimumSubstringsInPartition(std::string newString) {
        memset(dpArray, -1, sizeof dpArray);
        return findSubstrings(newString.size()-1,newString);
    }
};

