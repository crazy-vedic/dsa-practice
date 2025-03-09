/*
 * 234. Palindrome Linked List
 * Difficulty: Easy
 * 
 * Given the head of a singly linked list, return true if it is a palindrome or false otherwise.

**Example 1:**

**Example 1:**
Input: head = [1,2,2,1]
Output: true

**Example 2:**

**Example 2:**
Input: head = [1,2]
Output: false

**Constraints:**

**Constraints:**
The number of nodes in the list is in the range [1, 105].
0 <= Node.val <= 9
Follow up:
Follow up: Could you do it in O(n) time and O(1) space?
 */

ListNode* LLReverse(ListNode* head){
    ListNode* prev = nullptr;
    ListNode* curr = head;
    while (curr!=nullptr){
        ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

class Solution {
    public:
        bool isPalindrome(ListNode* head) {
            ListNode *slow = head, *fast = head;
            if (head->next==nullptr){return true;}