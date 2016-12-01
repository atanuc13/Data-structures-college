/*Program in c to implement creation,insertion,deletion,inorder traversal,preorder traversal,postorder travarsal and height of a B.S.T*/

#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int info;
    struct node *left,*right;
}nd;

void create();
void insert(nd *);
void del(int);
nd *search(int);
nd *p_search(int);
int inorder_succesor(nd *);
void inorder(nd *);
void preorder(nd *);
void postorder(nd *);
int height(nd *);
nd *root=NULL;
nd *g=NULL;

int main()
{
    nd *ptr;
    int i,j;
    while(1)
    {
        printf("\n1.create\n2.insert\n3.delete\n4.traverse\n5.height\n6.exit\n");
        scanf("%d",&i);
        switch(i)
        {
           case 1:
             create();
             break;
           case 2:
             g=root;
             ptr=(nd *)malloc(sizeof(nd));
             printf("enter a number: ");
             scanf("%d",&ptr->info);
             ptr->left=ptr->right=NULL;
             insert(ptr);
             printf("\ninserted successfully..");
             break;
           case 3:
               printf("enter a number : ");
               scanf("%d",&j);
               del(j);
               break;
           case 4:
               printf("1.inorder\n2.preorder\n3.postorder\n");
               scanf("%d",&j);
               switch(j)
               {
               case 1:
                  inorder(root);
                  break;
               case 2:
                preorder(root);
                break;
               case 3:
                 postorder(root);
                 break;
               default:
                printf("wrong input\n");
               }
               break;
               case 5:
                printf("the height of the given tree is %d",height(root));
                break;
               case 6:
                exit(0);
               default:
                printf("wrong input\n");

        }
    }
}

/* Function to create new node */
void create()
{
    char ch;
    nd *ptr=(nd *)malloc(sizeof(nd));
    printf("enter a number: ");
    scanf("%d",&ptr->info);
    ptr->left=ptr->right=NULL;
    root=ptr;
    printf("Do you want to continue?(y/n): ");
    fflush(stdin);
    scanf("%c",&ch);
    while(ch=='Y'||ch=='y')
    {
       g=root;
       ptr=(nd *)malloc(sizeof(nd));
       printf("enter a number: ");
       scanf("%d",&ptr->info);
       ptr->left=NULL;
       ptr->right=NULL;
       insert(ptr);
       printf("Do you want to continue?(y/n): ");
       fflush(stdin);
       scanf("%c",&ch);
    }
}

/* Function to insert a  new node to a appropriate position*/
void insert(nd *ptr)
{
    if(g)
    {
        if(ptr->info<g->info)
        {
            if(g->left==NULL)
                g->left=ptr;
            else
            {
                g=g->left;
                insert(ptr);
            }
        }
        else if(ptr->info>g->info)
        {
            if(g->right==NULL)
                g->right=ptr;
            else
            {
                g=g->right;
                insert(ptr);
            }
        }
    }
    else
        printf("\ninsertion not possible because tree is empty..");
}

/* recursive function to perform inorder traversal of tree */
void inorder(nd *ptr)
{
    if(ptr)
    {
        inorder(ptr->left);
        printf("%d\t",ptr->info);
        inorder(ptr->right);
    }
}

/* recursive function to perform preorder traversal of tree */
void preorder(nd *ptr)
{
    if(ptr)
    {
        printf("%d\t",ptr->info);
        preorder(ptr->left);
        preorder(ptr->right);
    }
}

/* recursive function to perform postorder traversal of tree */
void postorder(nd *ptr)
{
    if(ptr)
    {
        postorder(ptr->left);
        postorder(ptr->right);
        printf("%d\t",ptr->info);
    }
}

/* Function to search the appropriate node  */
nd *search(int x)
{
    nd *ptr=root;
    while(ptr)
    {
        if(x==ptr->info)
            return ptr;
        else if (x<ptr->info)
            ptr=ptr->left;
        else
            ptr=ptr->right;
    }
    return NULL;
}

/* Function to search the appropriate parent node of the given node*/
nd *p_search(int x)
{
    nd *ptr=root;
    while(ptr->left||ptr->right)
    {
        if(ptr->left->info==x||ptr->right->info==x)
            return ptr;
        else if (x<ptr->info)
            ptr=ptr->left;
        else if(x>ptr->info)
            ptr=ptr->right;
    }
    return NULL;
}

/* Function to find inorder succesor of a given node*/
int inorder_succesor(nd *ptr)
{
    ptr=ptr->right;
    while(ptr->left)
        ptr=ptr->left;
    return ptr->info;
}

/* Function to perform deletion operation of the given node */
void del(int x)
{
    int a;
    nd *ptr=search(x);
    nd *p=p_search(x);
    if(ptr)
    {
        if(ptr->left==NULL&&ptr->right==NULL)
        {
            if(p->left==ptr)
                p->left=NULL;
            else
                p->right=NULL;
        }
        else if(ptr->left!=NULL&&ptr->right==NULL)
        {
            if(p->left==ptr)
                p->left=ptr->left;
            else
                p->right=ptr->left;
        }
        else if(ptr->left==NULL&&ptr->right!=NULL)
        {
            if(p->left==ptr)
                p->left=ptr->right;
            else
                p->right=ptr->right;
        }
        else if(ptr->left!=NULL&&ptr->right!=NULL)
        {
            a=inorder_succesor(ptr);
            del(a);
            ptr->info=a;
        }
        printf("\ndeleted successfully..");
    }
    else
        printf("item not present in the B.S.T");
}

/* Function to find the height of the B.S.T. */
int height(nd *ptr)
{
    int l,r;
    if(ptr==NULL)
        return (0);
    l=height(ptr->left);
    r=height(ptr->right);
    if(l>r)
        return (l+1);
    else
        return (r+1);
}

