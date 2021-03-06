// Source : https://leetcode.com/problems/rotate-array/
// Author : Zhonghuan Gao
// Date   : 2019-10-16

/********************************************************************************** 
*
Given an array, rotate the array to the right by k steps, where k is non-negative.

Example 1:

Input: [1,2,3,4,5,6,7] and k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
Example 2:

Input: [-1,-100,3,99] and k = 2
Output: [3,99,-1,-100]
Explanation: 
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]
Note:

Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
Could you do it in-place with O(1) extra space?
*               
***********************************************************************************/

class Solution {
public:
    /**
     * 解法一:
     * 时间复杂度：O(n)
     * 空间复杂度：O(1)
     */
    void rotate(vector<int>& nums, int k) {
        for (int n = nums.size(), i = n; i > n - k; i--) {
            int tmp = nums.back();
            nums.pop_back();
            nums.insert(nums.begin(), tmp);
        }
    }

    /**
     * 解法二：
     */
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        reverse(nums.begin(), nums.begin() + n - k);
        reverse(nums.begin() + n - k, nums.end());
        reverse(nums.begin(), nums.end());
    }
};
