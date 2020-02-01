#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node *next;
};
node *head, *tail;
node *create_node(int x)
{
    node *temp = new node;
    temp->data = x;
    temp->next = NULL;
    return temp;
}
void insert_last(node *temp)
{
    if (head == NULL)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        tail->next = temp;
        tail = temp;
    }
}
void insert_middle(node *temp, int p)
{
    if (p == 1) // INSERTION IN BEGINNING
    {
        temp->next = head;
        head = temp;
    }
    else
    {
        node *tt = head;
        int cnt = 2;
        while (cnt < p)
        {
            tt = tt->next;
            cnt++;
        }
        temp->next = tt->next;
        tt->next = temp;
    }
}
void print_list()
{
    node *tt = head;
    while (tt->next != NULL)
    {
        cout<<tt->data<<"->";
        tt = tt->next;
    }
    cout<<tt->data;
}
int main()
{
    int n, x, p;
    cin >> n;
    while (n--)
    {
        cin >> x;
        node *temp = create_node(x);
        insert_last(temp);
    }
    // INSERTION IN MIDDLE at p
    cin >> p;
    cin >> x;
    node *temp = create_node(x);
    insert_middle(temp, p);
    print_list();
}