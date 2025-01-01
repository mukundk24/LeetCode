class Solution {
private:
void InsertAtTail(Node*& head, Node*& tail, int data)
{
    Node* newnode = new Node(data);
    if(head == NULL)
    {
        head = newnode;
        tail = newnode;
        return;
    }
    tail->next = newnode;
    tail = newnode;
}
public:
    Node* copyRandomList(Node* head) {
        Node* clonehead = NULL;
        Node* clonetail = NULL;
        Node* temp = head;
        while(temp!=NULL)
        {
            InsertAtTail(clonehead, clonetail, temp->val);
            temp = temp->next;
        }
        unordered_map <Node*, Node*> otn;
        temp = head;
        Node* temp2 = clonehead;
        while(temp!=NULL)
        {
            otn[temp] = temp2;
            temp = temp->next;
            temp2 = temp2->next;
        }
        temp = head;
        temp2 = clonehead;
        Node* ptr = NULL;
        while(temp!=NULL)
        {
            temp2->random = otn[temp->random];
            temp = temp->next;
            temp2 = temp2->next;
        }
        return clonehead;
    }
};