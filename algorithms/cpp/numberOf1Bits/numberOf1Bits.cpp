// Source : https://leetcode.com/problems/number-of-1-bits/
// Author : Zhonghuan Gao
// Date   : 2019-12-19

/********************************************************************************** 
*
Write a function that takes an unsigned integer and return the number of '1' bits it has (also known as the Hamming weight).

Example 1:
Input: 00000000000000000000000000001011
Output: 3
Explanation: The input binary string 00000000000000000000000000001011 has a total of three '1' bits.

Example 2:
Input: 00000000000000000000000010000000
Output: 1
Explanation: The input binary string 00000000000000000000000010000000 has a total of one '1' bit.

Example 3:
Input: 11111111111111111111111111111101
Output: 31
Explanation: The input binary string 11111111111111111111111111111101 has a total of thirty one '1' bits.

Note:
Note that in some languages such as Java, there is no unsigned integer type. In this case, the input will be given as signed integer type and should not affect your implementation, as the internal binary representation of the integer is the same whether it is signed or unsigned.
In Java, the compiler represents the signed integers using 2's complement notation. Therefore, in Example 3 above the input represents the signed integer -3.
 
Follow up:
If this function is called many times, how would you optimize it?
*               
***********************************************************************************/

/**
 * 题意：输入是一个无符号整数，返回其二进制表达式中数字位数为 ‘1’ 的个数
 */
class Solution {
public:
    /**
     * 解法一：
     */
    int hammingWeight(uint32_t n) {
        int res = 0;
        for (int i = 0; i < 32; i++) {
            if (n & 1 == 1) res++; // res += (n & 1);
            n = n >> 1;
        }
        return res;
    }
};
