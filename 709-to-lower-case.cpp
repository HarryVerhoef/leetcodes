class Solution {
public:
    string toLowerCase(string str) {
        for (int i = 0; i < str.length(); i++) {
            str[i] = str[i] | ' '; /* Bitwise OR */
        }
        return str;
    }
};