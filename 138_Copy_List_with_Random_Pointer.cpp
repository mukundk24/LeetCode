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

// Another Approach without using map
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
        Node *temp = head;
        while(temp!=NULL)
        {
            InsertAtTail(clonehead, clonetail, temp->val);
            temp = temp->next;
        }
        Node* orgnode = head;
        Node* clnode = clonehead;
        while(orgnode!=NULL && clnode!=NULL)
        {
            Node* nnext = orgnode->next;
            orgnode->next = clnode;
            orgnode = nnext;

            Node* cnnext = clnode->next;
            clnode->next = orgnode;
            clnode = cnnext;
        }

        temp = head;
        while(temp!=NULL)
        {
            if(temp->next!=NULL)
            {
                if(temp->random != NULL)
                {
                temp->next->random = temp->random->next;
                }
                else
                {
                    temp->next->random = temp->random;
                }
            }
            temp = temp->next->next;
        }
        orgnode = head;
        clnode = clonehead;
        while(orgnode!=NULL && clnode!=NULL)
        {
            orgnode->next = clnode->next;
            orgnode = orgnode->next;
            if(orgnode!=NULL)
            {
            clnode->next = orgnode->next;
            }
            clnode = clnode->next;
        }
        return clonehead;
    }
};