#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
// all positions are 1-based indexing
struct node
{
	int data;
	struct node* next;
};

struct node* head;

//function to insert a node at the front
void insert_front(int x)
{
	node* temp = new node();
	temp->data =x;
	temp->next = head;
	head = temp;
}

//fuction to print the elements of linked-list
void print_itr()
{
	node* temp = head;
	while(temp !=NULL)
	{
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<endl;
}

void print_rec(node* p)
{
	if(p==NULL)
		return;
	cout<<p->data<<" ";
	print_rec(p->next);
}

//fuction to print the reverse linked list

void print_rev(node* p)
{
	if(p==NULL)
		return;
	print_rev(p->next);
	cout<<p->data<<" ";
}

//function to insert at the end of the linked list
void insert_end(int x)
{
	node* temp1=new node();
	temp1->data = x;
	temp1->next = NULL;
	if(head==NULL)
	{
		head = temp1;
		return;
	}
	node* temp = head;
	while(temp->next !=NULL)
		temp=temp->next;
	temp->next=temp1;
}

//function to insert a node at a specific location in a linked list
void insert_at(int x,int n)
{
	node* temp1=new node();
	temp1->data = x;
	temp1->next = NULL;

	node*temp2 = head;
	if(n==1)
	{
		temp1->next =head;
		head = temp1;
		return ;
	}
	for(int i=0;i<(n-2);i++)
		temp2 = temp2->next;
	temp1->next = temp2->next;
	temp2->next =temp1;
}

//function to delete a node at a given position
void delete_at(int n)
{
	node* temp = head;
	if(n==1)
	{
		head = temp->next;
		free(temp);
		return;
	}
	for(int i=0;i<(n-2);i++)
		temp = temp->next;             //(n-1)th node
	node* temp1 = temp->next;			//(n)th node which has to be deleted
	temp->next = temp1->next;
	free(temp1);
}

//function to reverse a linked list in iterative manner

void reverse_itr()
{
	node* prev , *current,*nxt;
	current = head;
	prev = NULL;
	while(current != NULL)
	{
		nxt= current->next;
		current->next = prev;
		prev = current;
		current = nxt;
	}
	head = prev;
}

//function to determine the size of a linked list

int size()
{
	int c=0;
	node* temp = head;
	while(temp!=NULL)
	{
		c++;
		temp = temp->next;
	}
	return c;
}

int size_rec(node* p)
{
	if(p==NULL)
		return 0;
	else
		return size_rec(p->next) + 1;
}

//function to delete the first occurence of the given key

void delete_key(int key)
{
	node* temp = head;
	if(temp->data == key)
	{
		head = temp->next ;
		free(temp);
		return;
	}
	while( temp->next !=NULL &&  temp->next->data!=key)
		temp = temp->next;
	// now temp will be the node behind the target node

	node* temp1 = temp->next;
	if(temp1==NULL)
	{
		cout<<"No such key exists"<<endl;
		return;
	}
	temp->next = temp1->next ;
	free(temp1);
}

//function to search for an element in a linked list

bool search(int key)
{
	node* temp = head;
	while(temp != NULL)
	{
		if(temp->data == key)
			return true;
		temp=temp->next;
	}
	return false;
}

//function to get the value of nth node from the end

int GetNode(node *head,int positionFromTail)
{
    int n=0;
    node* temp = head;
    while(temp!=NULL)
    {
        n++;
        temp= temp->next;
    }
    int pos = n-positionFromTail-1;
    node* temp1 = head;
    for(int i=0;i<(pos);i++)
        temp1=temp1->next;
    return temp1->data;
   
}

//function to reverse a linked list using recursion

void rev_rec(node* p)
{
	if(p->next ==NULL)
	{
		head = p;
		return;
	}
	rev_rec(p->next);
	node* q = p->next;
	q->next =p;
	p->next =NULL;
}

//Driver program to test the above functions
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    head = NULL;
    insert_end(9);
    print_itr();
    cout<<"Size of LL is "<<size()<<endl;
    insert_end(0);
    print_itr();
    cout<<"Size of LL is "<<size()<<endl;
    insert_front(4);
    print_itr();
    cout<<"Size of LL is "<<size()<<endl;
    insert_front(5);
    print_itr();
    cout<<"Size of LL is "<<size()<<endl;
    insert_front(8);
    print_itr();
    cout<<"Size of LL is "<<size()<<endl;
    insert_at(3,2);
    print_itr();
    cout<<"Size of LL is "<<size()<<endl;
    insert_at(1,1);
    print_itr();
    cout<<"Size of LL is "<<size()<<endl;
    insert_at(7,8);
    print_itr();
    cout<<"Size of LL is "<<size()<<endl;
    delete_at(5);
    print_itr();
    cout<<"Size of LL is "<<size()<<endl;
    delete_at(1);
    print_itr();
    cout<<"Size of LL is "<<size()<<endl;
    delete_at(6);
    print_itr();
    reverse_itr();
    cout<<"Size of LL is "<<size()<<endl;
    print_itr();
    cout<<size_rec(head)<<endl;
    if(search(5))
    	cout<<"YES"<<endl;
    else
    	cout<<"NO"<<endl;
    rev_rec(head);
    print_itr();
    return 0;
}
