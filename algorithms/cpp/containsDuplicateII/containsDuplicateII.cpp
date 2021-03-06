// Source : https://leetcode.com/problems/contains-duplicate-ii/
// Author : Zhonghuan Gao
// Date   : 2019-10-17

/********************************************************************************** 
*
Given an array of integers and an integer k, find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j] and the absolute difference between i and j is at most k.

Example 1:
Input: nums = [1,2,3,1], k = 3
Output: true

Example 2:
Input: nums = [1,0,1,1], k = 1
Output: true

Example 3:
Input: nums = [1,2,3,1,2,3], k = 2
Output: false
*               
***********************************************************************************/

/**
 * 题意：给你一个整数数组，判断其中是否有重复的数并且两个数的索引差不大于k
 */
class Solution {
public:
    /**
     * 解法一：
     * 使用哈希表存每个数字的索引，如果该数字在哈希表中已存在，则求差并更新索引
     */
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            if (m.find(nums[i]) != m.end() && i - m[nums[i]] <= k)
                return true;
            m[nums[i]] = i;
        }
        return false;
    }
};
