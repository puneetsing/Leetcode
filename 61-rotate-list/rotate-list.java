/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode rotateRight(ListNode head, int k) {
        if(head == null|| head.next == null||k==0){
            return head;
        }
        ListNode curr = head;
        ListNode prev = null;

        while(curr.next != null){
            prev = curr;
            curr = curr.next;
        }
        ListNode count = head;
        int n = 0;
        while(count != null){
            n++;
            count = count.next;
        }
        k = k % n;
        curr.next=head;
        ListNode newtail = head;
        for(int i = 0;i<n-k-1;i++){
            newtail = newtail.next;
        }
        ListNode newhead = newtail.next;
        newtail.next = null;
        return newhead;
    }
}