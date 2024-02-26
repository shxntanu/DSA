package recursion;
class ListNode {
         int val;
         ListNode next;
         ListNode() {}
         ListNode(int val) { this.val = val; }
         ListNode(int val, ListNode next) { this.val = val; this.next = next; }
     }
public class remove_linked_list_element {
    public ListNode removeElements(ListNode head, int val) {
        ListNode current = new ListNode();
        ListNode previous = new ListNode();
        current = head;
        previous = null;
        while(current != null){
            if(current.val == val){
                if (previous == null) {
                    head = current.next;
                } else {
                    previous.next = current.next;
                }
            }
            else{
                previous = current; 
            }
            current = current.next;
        }
    return head;
        }
        public ListNode removeElements2(ListNode head, int val) {
            if (head == null) {
                return null;
            }
            head.next = removeElements(head.next, val);
    
            if (head.val == val) {
                return head.next;
            } else {
                return head;
            }  
        }  
}
