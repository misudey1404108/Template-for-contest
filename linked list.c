#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
}*root;
int a[200010];
void traverse(struct node* head)
{
    struct node* curr= head;
    while(curr!=NULL)
    {
        printf("%d ", curr->data);
        curr=curr->next;
    }
}
struct node* insert_beg(struct node *head, int val)
{
    struct  node* tmp=(struct node*)malloc(sizeof(struct node));
    tmp->data=val;
    tmp->next=head;
    head=tmp;
    return head;
}
struct node* insert_end(struct node* head, int val)
{
    struct  node* tmp=(struct node*)malloc(sizeof(struct node));
    struct  node* curr=head;
    struct  node* prev;
    tmp->data=val;
    tmp->next=NULL;
    if(head==NULL) head=tmp;
    else
    {
        while(curr!=NULL)
        {
            prev=curr;
            curr=curr->next;
        }
        prev->next=tmp;
    }
    return head;
}
struct node* insert_spec(struct node* head, int val, int search)
{
    struct node* curr=head;
    struct node* tmp=(struct node*)malloc(sizeof(struct node));
    tmp->data=val; tmp->next=NULL;
    struct node* tt;
    while(curr!=NULL)
    {
        if(curr->data==search)
        {
            tt=curr->next;
            curr->next=tmp;
            tmp->next=tt;
            break;


        }
        curr=curr->next;
    }
    return head;
};
struct node* del(struct node* head, int pos)
{
    struct node* curr=head;
    struct node* prev=(struct node*)malloc(sizeof(struct node));
    int ck=0;
    while(curr!=NULL)
    {
        if(ck==pos)
        {
            if(ck==0) head=curr->next;
            else prev->next=curr->next;
        }
        prev=curr;
        curr=curr->next;
        ck++;
    }
    return head;
};
struct node* reverse(struct node* head)
{
    struct node* curr=head;
    struct node* prev=NULL;
    struct node* next=(struct node*)malloc(sizeof(struct node));
    while(curr!=NULL)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    head=prev;
    return head;
};
int main()
{
    root= (struct node*)malloc(sizeof(struct node));
    root=NULL;
    int n; scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        root=insert_end(root,i);
    }
    root=insert_spec(root, 6, 5);
    traverse(root); printf("\n");
    root=del(root,6);
    traverse(root); printf("\n");
    root=reverse(root);
    traverse(root); printf("\n");

    return 0;

}
