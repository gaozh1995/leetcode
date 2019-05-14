// Source : https://leetcode.com/problems/find-the-difference/
// Author : Zhonghuan Gao
// Date   : 2019-04-30

/********************************************************************************** 
**
Given two strings s and t which consist of only lowercase letters.

String t is generated by random shuffling string s and then add one more letter at a random position.

Find the letter that was added in t.

Example:

Input:
s = "abcd"
t = "abcde"

Output:
e

Explanation:
'e' is the letter that was added.
** 
***********************************************************************************/

class Solution {
public:
    /**
     * 解法一：
     * 先将较长字符串中字符出现的次数记录到哈希表中，然后在将较短字符串在哈希表中出现的次数减一，
     * 最后哈希表中字符次数为一的字符即为多余的字符
     */
    char findTheDifference(string s, string t) {
        map<char, int> m;
        for (auto c : t) {
            m[c]++;
        }
        for (auto c : s) {
            m[c]--;
        }
        for (auto c : t) {
            if (m[c] == 1) return c;
        }
        return t[0];
    }

    /**
     * 解法一优化
     */
    char findTheDifference(string s, string t) {
        unordered_map<char, int> m;
        for (char c : s) ++m[c];
        for (char c : t) {
            if (--m[c] < 0) return c;
        }
        return 0;
    }

    /**
     * 解法二：位操作
     * 异或，相同位返回0
     */
    char findTheDifference(string s, string t) {
        char res = 0;
        for (char c : s) res ^= c;
        for (char c : t) res ^= c;
        return res;
    }

    /**
     * 解法三：
     * 加减操作
     */
    char findTheDifference(string s, string t) {
        char res = 0;
        for (char c : s) res -= c;
        for (char c : t) res += c;
        return res;
    }
};