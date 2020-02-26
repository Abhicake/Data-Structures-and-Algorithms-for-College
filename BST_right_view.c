// BST - Binary search tree
//	Give binary search tree elements as input and get the right side view elements

#include<stdio.h>
#include<stdlib.h>

// node of BST
typedef struct node
{
  int data;
  struct node *left, *right;
}node;

node  *head=NULL; // head of BST

// queue(array) which will hold BST nodes
node * que[100];
int front=0,back=0;


// function to create and return node
node * create(int data){
    node *temp=(node *)malloc(sizeof(node));
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}

// function to add node to BST
void add(int data){
    node *temp = create(data);
    node *p=head; // variable to traverse the BST and add node
    
	if( !head ) head = temp;
    
	else
        while(1){
            if(data > p->data)
                if(p->right) p=p->right;
                else {
                    p->right=temp;
                    return ;
                }
            
            else if(data == p->data) return; // no duplicate values in BST
            
			else
                if(p->left) p=p->left;
                else {
                    p->left=temp;
                    return ;
                }
        }
    
}



void print_right_view ()
{
    int prev_back=-1;
    
    que[back++]=head;
    
	while(prev_back!=back){
        int i, n=back ; // 'n' is some variable to store back 
        
		for(i =front ; i < n ; ++i){
            if(que[i]->left) que[back++]=que[i]->left;
            if(que[i]->right) que[back++]=que[i]->right;
            ++front;
        }
        printf("%d ",que[n-1]->data );
        prev_back=n;
    }
    
}

int main ()
{
  int n;
  printf("Enter number of elements: ");
  scanf ("%d", &n);
  printf("Enter %d elements: \n",n);
  while (n--)
    {
      int d;
      scanf ("%d", &d);
      add (d); // adding elements to BST
    }
  printf ("The right view:\n");
  print_right_view ();
}

/*

Enter number of elements: 11
Enter 11 elements:
20
10
25
8
15
23
28
14
18
12
11
The right view:
20 25 28 18 12 11
*/
