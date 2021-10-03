class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans=new ListNode();
        ListNode* current=ans;
        int carry=0,val,add;
        
        while (l1 && l2 )
        {   
            add=l1->val+l2->val+carry;
            val=add%10;
            carry=add/10;
            l1->val=val;
            current->next=l1;
            current=current->next;
            l1=l1->next;
            l2=l2->next;
        }
        current->next=l1?l1: l2;
        while (carry>0)
        {
            if (current->next)
            {
                current=current->next;
                add=current->val+carry;
                val=add%10;
                carry=add/10;
                current->val=val;
            }
            else
            {
             current->next=new ListNode(carry);
                carry=0;
            }
            
        }
    return ans->next;
    }
};