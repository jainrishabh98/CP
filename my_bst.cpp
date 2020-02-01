#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node *left,*right;
};
node *root = NULL;
void find(node *curr,node **loc, node **par,int item)
{
    if(root ->data == item)
    {
        *loc = root;
        return ;
    }
    else if(curr->data < item && curr->right!=NULL)
    {
        if((curr->right)->data==item)
        {
            *loc = curr->right;
            *par = curr;
            return ;
        }
        else
        {
            find(curr->right,loc,par,item);
        }
        
    }
    else if(curr->data > item && curr->left!=NULL)
    {
        if((curr->left)->data==item)
        {
            *loc = curr->left;
            *par = curr;
            return ;
        }
        else
        {
            find(curr->left,loc,par,item);
        }
    }

}
void case_a(node *par, node*loc)
{
    if(loc == root)
    {
        root = NULL;
        return ;
    }
    else if(par->right == loc)
    {
        par->right = NULL;
    }
    else
    {
        par->left = NULL;
    }
    
}
void case_b(node *par, node*loc)
{
    node *child;
    if(loc->left != NULL)
    {
        child = loc->left;
    }
    else
    {
        child = loc->right;
    }
    if(loc == root)
    {
        root = child;
    }
    else if(par->left == loc)
    {
        par->left = child;
    }
    else
    {
        par->right = child;
    }
}
void case_c(node *par, node*loc)
{
    node *ptr, *ptrsave, *suc, *parsuc;
    ptrsave = loc;
    ptr = loc->right;
    while (ptr->left != NULL)
    {
        ptrsave = ptr;
        ptr = ptr->left;
    }
    suc = ptr;
    parsuc = ptrsave;
    if (suc->left == NULL && suc->right == NULL)
        case_a(parsuc, suc);
    else
        case_b(parsuc, suc);
    if (par == NULL)
    {
        root = suc;
    }
    else
    {
        if (loc == par->left)
            par->left = suc;
        else
            par->right = suc;
    }
    suc->left = loc->left;
    suc->right = loc->right;
}
void del(int item)
{
    node *parent = NULL,*location = NULL;
    if(root == NULL)
    {
        cout<<"Empty\n";
        return ;
    }
    find(root,&parent,&location,item);
    if(location == NULL)
    {
        cout<<"Element not found\n";
        return ;
    }
    if(location->left == NULL && location->right == NULL)
    {
        case_a(parent,location);
    }
    else if(location->left != NULL && location->right!= NULL)
    {
        case_c(parent,location);
    }
    else
    {
        case_b(parent,location);
    }
    
}
void insert(node *curr,node *temp)
{
    if(root == NULL)
    {
        root = temp;
        return ;
    }
    if(curr->data == temp->data)
    {
        cout<<"Already present\n";
    }
    else if(curr->data < temp->data)
    {
        if(curr->right == NULL)
        {
            curr->right = temp;
        }
        else
        {
            insert(curr->right,temp);
        }
        
    }
    else
    {
        if(curr->left == NULL)
        {
            curr->left = temp;
        }
        else
        {
            insert(curr->left,temp);
        }
        
    }
    
}
void preorder(node *curr)
{
    if(root == NULL)
    {
        cout<<"Empty\n";

    }
    else if(curr!=NULL)
    {
        cout<<curr->data<<"\t";
        preorder(curr->left);
        preorder(curr->right);
    }
    
}
void inorder(node *curr)
{
    if(root == NULL)
    {
        cout<<"Empty\n";

    }
    else if(curr!=NULL)
    {
        inorder(curr->left);
        cout<<curr->data<<"\t";
        inorder(curr->right);
    }
    
}
void postorder(node *curr)
{
    if(root == NULL)
    {
        cout<<"Empty\n";

    }
    else if(curr!=NULL)
    {
        postorder(curr->left);
        postorder(curr->right);
        cout<<curr->data<<"\t";
    }
    
}
int main ()
{
    int choice;
    while (1)
    {
        cout<<"-----------------"<<endl;
        cout<<"Operations on BST"<<endl;
        cout<<"-----------------"<<endl;
        cout<<"1.Insert Element "<<endl;
        cout<<"2.Delete Element "<<endl;
        cout<<"3.Inorder Traversal"<<endl;
        cout<<"4.Preorder Traversal"<<endl;
        cout<<"5.Postorder Traversal"<<endl;
        cout<<"6.Display"<<endl;
        cout<<"7.Quit"<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            node *temp = new node;
            cout<<"Enter the number to be inserted : ";
	    cin>>temp->data;
        temp->left = NULL;temp->right = NULL;
            insert(root, temp);
        case 2:
            if (root == NULL)
            {
                cout<<"Tree is empty, nothing to delete"<<endl;
                continue;
            }
            int num;
            cout<<"Enter the number to be deleted : ";
            cin>>num;
            // del(num);
            break;
        case 3:
            cout<<"Inorder Traversal of BST:"<<endl;
            inorder(root);
            cout<<endl;
            break;
	case 4:
            cout<<"Preorder Traversal of BST:"<<endl;
            preorder(root);
            cout<<endl;
            break;
        case 5:
            cout<<"Postorder Traversal of BST:"<<endl;
            postorder(root);
            cout<<endl;
            break;
        case 6:
            cout<<"Display BST:"<<endl;
            //display(root,1);
            cout<<endl;
            break;
        case 7:
            exit(1);
        default:
            cout<<"Wrong choice"<<endl;
        }
    }
}