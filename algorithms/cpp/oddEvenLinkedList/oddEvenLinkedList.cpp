// Source : https://leetcode.com/problems/odd-even-linked-list/
// Author : Zhonghuan Gao
// Date   : 2019-06-27

/********************************************************************************** 
*
Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes.

You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.

Example 1:

Input: 1->2->3->4->5->NULL
Output: 1->3->5->2->4->NULL
Example 2:

Input: 2->1->3->5->6->4->7->NULL
Output: 2->3->6->7->1->5->4->NULL

Note:
The relative order inside both the even and odd groups should remain as it was in the input.
The first node is considered odd, the second node even and so on ...
*               
***********************************************************************************/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    /**
     * 将一个链表的奇偶节点分离开，奇节点在前，偶节点在后。
     * 解法一：
     * 使用两个指针来解决，pre指向奇节点，cur指向偶节点，然后把偶节点cur后面的那个奇节点提前到pre的后面，
     * 然后pre和cur各自前进一步，此时cur又指向偶节点，pre指向当前奇节点的末尾，以此类推直到所有奇节点移到前面。
     */
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *pre = head, *cur = head->next;

        while (cur && cur->next) {
            ListNode *tmp = pre->next;
            pre->next = cur->next;
            cur->next = cur->next->next;
            pre->next->next = tmp;
            pre = pre->next;
            cur = cur->next;
        }

        return head;
    }
};
