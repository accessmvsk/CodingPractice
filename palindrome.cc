class Solution {
public:
    bool isPalindrome(string s) {
        //take two pointers, one from beginning one from ending of the string.
        //move them as long they match, return false if not.
        //make sure we skip "any" number of spaces till we hit a alphanumberic
        //also make sure we compare each character at lowe case
        for (int left=0, right=(s.length() -1 ); left < right; left++, right--)
        {
            //avoid non-alphanumberic characters on left
            while (left < right && !std::isalnum(s[left])) { left++; }
            while (left < right && !std::isalnum(s[right])) { right--; }
            if (tolower(s[left]) != tolower(s[right])) {
                return false;
            }
            
        }
        return true;
    }
};
//https://leetcode.com/submissions/detail/146291885/
