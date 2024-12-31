class Solution {
private:
    ListNode* getMid(ListNode* head)
    {
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast!=NULL && fast->next!=NULL)
        {
            fast = fast->next;
            if(fast != NULL)
                fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
    ListNode* reverse(ListNode* head)
    {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;
        while(curr!=NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
public:
    bool isPalindrome(ListNode* head) {
        if(head->next == NULL)
            return true;
        ListNode* mid = getMid(head);
        ListNode* temp = mid;
        mid->next = reverse(temp->next);
        ListNode* curr = head;
        temp = mid->next;
        while(temp!=NULL)
        {
            if(curr->val != temp->val)
                return false;
            curr = curr->next;
            temp = temp->next;
        }
        return true;
    }
};