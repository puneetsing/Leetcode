/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode detectCycle(ListNode head) {
        ListNode slow = head;
        ListNode fast = head;
        boolean detect = false;
        while(fast!=null && fast.next != null){
            slow = slow.next;
            fast = fast.next.next;
            if(slow==fast){
                detect = true;
                break;
            }
        }
        if(fast ==null||fast.next==null||!detect){
            return null;
        }
        while(head != fast){
            head = head.next;
            fast = fast.next;
        }
        return head;
    }
}