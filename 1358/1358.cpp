class Solution {
    public:
        int numberOfSubstrings(string s) {
            int left = 0, right = 0, cnt = 0, localCnt = 0;
            vector<int> curABC = {0,0,0};
            int isValid = 0; // == 3 is valid, else invalid
    
            for(;right < s.size();right++) {
                if(curABC[s[right] - 'a'] == 0) isValid++; 
                curABC[s[right] - 'a']++;
    
                // "kernel" found -> calculate how many substring can make by this kernel (left)
                while(isValid == 3) {
                    // cnt++;
                    curABC[s[left] - 'a']--;
                    if(curABC[s[left] - 'a'] == 0) isValid--; 
                    left++;
    
                    if(isValid == 2) cnt += left;
                }
            }
    
            return cnt;
        }
    };