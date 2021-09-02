# Linked Lists 

## Declaring a Linked List Node 
```
struct Node
{
	int data;
	struct Node* next;

	Node(int val)
	{
		data=val;
		next=NULL;
	}
};
```
## Deleting a Node in Linked List

### Deleting with position 
```
void delete_t_pos(Node* &head,int pos)
{
	if(pos==0)
	{
		Node* temp=head;
		head=head->next;
		delete temp;
	}
	else
	{int pre=pos-1;
		Node* temp=head;
		while(pre)
		{
			temp=temp->next;
			pre--;
		}
		Node* todel=temp->next;
		temp->next=temp->next->next;
		delete todel;}
}
```
### Deleting with value
```
void delete_t_value(Node* &head,int val)
{
	if(head->data==val)
	{
		Node* temp=head;
		head=head->next;
		delete temp;
	}
	else
	{Node* temp=head;
		while(temp->next->data!=val)
		{
			temp=temp->next;
		}
		Node* todelete=temp->next;
		temp->next=temp->next->next;
	
		delete todelete;}

}
```

## Reversing a Linked List 
```
Node* reverse(Node* &head)
{
	if( head==NULL || head->next==NULL)
	{
		return head;
	}
	Node* newhead=reverse(head->next);
	head->next->next=head;
	head->next=NULL;
	return newhead;
}
```

## Reverse K nodes in a Linked List 
```
{
		Node* prevptr=NULL;
		Node* currptr=head;
		Node* nextptr;

		int count=0;
		while(currptr!=NULL && count<k)
		{
				nextptr=currptr->next;
				currptr->next=prevptr;
				prevptr=currptr;
				currptr=nextptr;
				count++;
		}
		if(nextptr!=NULL)
		{
			head->next=reverse_k(nextptr,k);
		}

		return prevptr;
}
```
## Make a Cycle in a Linked List 
```
void makeCycle(Node* &head,int pos)
{
	Node* temp=head;
	Node* startNode;
	int count=1;
	while(temp->next!=NULL)
	{
		if(count==pos)
			startNode=temp;

		temp=temp->next;
		count++;
	}
	temp->next=startNode;
}

```

## Detect a Cycle in a Linked List (Hare and Tortoise Algorithm)
```
{
	Node* slow=head;
	Node* fast=head;
	while(fast!=NULL && fast->next!=NULL)
	{
		slow=slow->next;
		fast=fast->next->next;
		if(fast==slow)
		{
			return true;
		}
	}
	return false;
}
```

## Remove a Cycle in a Linked List 
```
void removecycle(Node* &head)
{
	Node* slow=head;
	Node* fast=head;

	do
	{
		slow=slow->next;
		fast=fast->next->next;
	}
	while(slow!=fast);
	fast=head;
	while(slow->next!=fast->next)
	{
		slow=slow->next;
		fast=fast->next;
	}
	slow->next=NULL;
}

```
