class Solution {
private:
    ListNode* reverse(ListNode* head)
    {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = curr->next;
        while(curr!=NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
ListNode* add(ListNode* first, ListNode* second)
{
    int digit = 0, sum = 0, carry = 0;
    ListNode* f = first;
    ListNode* s = second;
    ListNode* ans = new ListNode(0);
    ListNode* prev = ans;
    while(f!=NULL && s!=NULL)
    {
        sum = f->val+s->val+carry;
        digit = sum%10;
        ListNode* temp = new ListNode(digit);
        ans->next = temp;
        carry = sum/10;
        sum = 0;
        ans = temp;
        f = f->next;
        s = s->next;
    }
    if(s==NULL && f == NULL && carry!=0)
    {
        ListNode* temp = new ListNode(carry);
        ans->next = temp;
        ans = temp;
    }
    else if(f == NULL)
    {
        while(s!=NULL)
        {
            sum = s->val+carry;
            digit  = sum%10;
            ListNode* temp = new ListNode(digit);
            ans->next = temp;
            carry = sum/10;
            sum = 0;
            ans = temp;
            s = s->next;
        }
        if(carry!=0)
        {
            ListNode* temp = new ListNode(carry);
            ans->next= temp;
            ans = temp;
        }
    }
    else if(s == NULL)
    {
        while(f!=NULL)
        {
            sum = f->val+carry;
            digit  = sum%10;
            ListNode* temp = new ListNode(digit);
            ans->next = temp;
            carry = sum/10;
            sum = 0;
            ans = temp;
            f = f->next;
        }
        if(carry!=0)
        {
            ListNode* temp = new ListNode(carry);
            ans->next= temp;
            ans = temp;
        }
    }
    return prev->next;
}
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverse(l1);
        l2 = reverse(l2);
        ListNode* ans = add(l1, l2);
        ans = reverse(ans);
        return ans;
    }
};