#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

struct node
{
	int data;
	struct node* next;
};

node* InsertAtHead(node* head,int x)
{
	node* temp = new node();
	temp->data =x;
	temp->next=head;
	head =temp;
	return head;
}

void print_list(node* head)
{
	while(head!=NULL)
	{
		cout<<head->data<<endl;
		head=head->next;
	}
	return;
}

void print_list_rec(node* head)
{
	if(head==NULL)
		return;
	else
	{
		cout<<head->data<<endl;
		print_list_rec(head->next);
	}
}

node* InsertAtEnd(node* head,int x)
{
	node* temp = new node();
	temp->data = x;
	temp->next=NULL;
	node* temp1 = head;
	while(temp1->next!=NULL)
		temp1 = temp1->next;
	temp1->next = temp;
	return head;
}

void print_list_reverse(node* head)
{
	if(head==NULL)
		return;
	else
	{
		print_list_reverse(head->next);
		cout<<head->data<<endl;
	}
	return;
}
int length_itr(struct node* head)
{
	int c=0;
	struct node* ptr=head;
	for(ptr=head;ptr!=NULL;ptr=ptr->next)
		c++;
	return c;
}

int length_rec(struct node* head)
{	
	if(head==NULL)
		return 0;
	return 1+length_rec(head->next);
}
int size_of_list(node* head)
{
	int c=0;
	while(head!=NULL)
	{
		c++;
		head= head->next;
	}
	return c;
}

int size_of_list_rec(node* head)
{
	if(head==NULL)
		return 0;
	return (size_of_list_rec(head->next)+1);
}

bool search_ele(node* head,int key)
{
	while(head!=NULL)
	{
		if(head->data == key)
			return true;
		head=head->next;
	}
	return false;
}

bool search_ele_rec(node* head,int key)
{
	if(head==NULL)
		return false;
	return ((head->data ==key)? true:search_ele_rec(head->next,key));
}

node* InsertAtPos(node* head,int x,int n)
{
	node* temp = new node();
	temp->data = x;
	temp->next=NULL;

	//if one has to insert at the front
	if(n==1)
	{
		temp->next = head;
		head=temp;
		return head;
	}
	//iterate to (n-1)th position
	node* temp1 = head;
	for(int i=1;i<(n-1);i++)
		temp1 = temp1->next;
	temp->next= temp1->next;
	temp1->next=temp;
	return head;
}

node* delete_at_pos(node* head,int n)
{
	node* temp = head;
	if(n==1)
	{
		
		head = temp->next;
		return head;
	}
	for(int i=1;i<(n-1);i++)
		temp = temp->next;
	node* del = temp->next;
	temp->next=del->next;
	delete del;
	return head;
}

node* delete_key(node* head,int key)
{
	node* temp = head;
	if(temp->data==key)
	{
		head = temp->next;
		delete temp;
		return head;
	}
	while(temp->next !=NULL && temp->next->data !=key)
		temp = temp->next;
	if(temp->next ==NULL)
	{
		cout<<"No such key"<<endl;
		return head;
	}
	node* del = temp->next;
	temp->next	= del->next;
	delete del;
	return head;
}

node* reverse_list(node* head)
{
	node* current,*prev,*next;
	current = head;
	prev = NULL;
	while(current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current=next;
	}
	head = prev;
	return head;
}

int get_nth(node* head,int n)
{
	int c=1;
	while(c!=n)
	{
		head = head->next;
		c++;
	}
	return head->data;
}

int print_middle(node* head)
{
	return get_nth(head,size_of_list(head)/2 +1);
}

void delete_list(node* head)
{
	node* cur = head,*next;
	while(cur!=NULL)
	{
		next = cur->next;
		delete cur;
		cur = next;
	}
	return;
}

struct node* reverse(struct node* head)
{	
	struct node* prev=NULL,*current=head,*nxt;
	while(current !=NULL)
	{
		nxt = current->next;
		current->next = prev;
		prev=current;
		current=nxt;
	}
	head=prev;
	return head;
}

struct node* insert(struct node* head,int x)
{	
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->data=x;
	if(head==NULL)
	{
		temp->next=NULL;
		head=temp;
		return head;
	}
	struct node* ptr=head;
	while(ptr->next!=NULL)
	{
		ptr=ptr->next;		
	}
	ptr->next = temp;
	temp->next=NULL;
	return head;
}

struct node* merge(struct node* head1,struct node* head2,struct node* head3)
{
	struct node* p1=head1,*p2=head2;
	while(p1!=NULL && p2!=NULL)
	{	
		if(p1->data<=p2->data)
		{
			head3 = insert(head3,p1->data);
			p1=p1->next;
		}
		else
		{
			head3 = insert(head3,p2->data);
			p2=p2->next;
		}
	}
	while(p1!=NULL)
	{
		head3 = insert(head3,p1->data);
			p1=p1->next;
	}
	while(p2!=NULL)
	{
		head3 = insert(head3,p2->data);
			p2=p2->next;
	}
	return head3;
}

struct node* remove_dup(struct node* head)
{	
	struct node* ptr=head;
	while(ptr->next!=NULL)
	{
		if(ptr->data ==ptr->next->data)
		{	
			struct node* temp = ptr->next;
			ptr->next = temp->next;
			free(temp);
		}
		else
			ptr=ptr->next;
	}	
	return head;
}

bool is_palin(struct node* head)
{
	bool palin;
	int len= length_itr(head),i;
	struct node* mid=head,*p=head,*head1=head,*head2,*temp1,*temp2;
	while(p!=NULL && p->next!=NULL)
	{
		mid=mid->next;
		p=p->next->next;
	}
	if(len %2==0)
		head2=mid;
	else
		head2 = mid->next;
	head2 = reverse(head2);
	temp1=head;
	temp2 = head2;
	for(i=0;i<(len/2);i++)
	{
		if(temp1->data != temp2->data)
		{	
			palin=false;
			break;
		}
		temp1=temp1->next;
		temp2 = temp2->next;
	}
	if(i==(len/2))
	palin = true;
head2 = reverse(head2);
	struct node* ptr= head;
	for(i=0;i<(len/2 -1);i++)
		ptr=ptr->next;
	if(len %2==1)
		ptr=ptr->next;
	ptr->next = head2;
	return palin;
}

struct node* del_altr(struct node* head)
{	
	struct node* ptr =head,*temp;
	while(ptr!=NULL && ptr->next!=NULL)
	{
		temp=ptr->next;
		ptr->next = temp->next;
		free(temp);
		ptr=ptr->next;
	} 
	return head;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    node* head = NULL;
    head = InsertAtHead(head,5);
    head = InsertAtHead(head,18);
    head = InsertAtHead(head,50);
    head = InsertAtHead(head,15);
    print_list_rec(head);
    cout<<endl;
    head = InsertAtEnd(head,20);
    head = InsertAtEnd(head,11);
    print_list(head);
    cout<<endl;
    //print_list_reverse(head);
    cout<<size_of_list(head)<<endl;
    //cout<<size_of_list_rec(head)<<endl;
    //cout<<search_ele_rec(head,500)<<endl;
    head = InsertAtPos(head,12,4);
    print_list(head);
    cout<<endl;
    head = delete_at_pos(head,7);
    print_list(head);
    cout<<endl;
    //head = delete_key(head,5);
    print_list(head);
    cout<<endl;
    head = reverse_list(head);
    print_list(head);
    cout<<endl;
    cout<<get_nth(head,5);
    cout<<endl;
    cout<<print_middle(head)<<endl;
    //delete_list(head);
    print_list(head);
    return 0;
}
