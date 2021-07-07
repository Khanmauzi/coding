#include<bits/stdc++.h>
using namespace std;
#define null NULL

struct node {
	int data;
	node *next;
};
void printLinkedList(struct node *root){
	while(root!=null){
		cout<<root->data<<" ";
		root=root->next;
	}
	cout<<endl;
}
addBegin(struct node** root, int data){
	struct node* temp;
	temp = new node();
	temp->data = data;
	temp->next = *root;
	*root = temp;
}
void addEnd(struct node **root, int data){
	struct node *temp,*it;
	it=*root;
	while(it->next!=null){
		it=it->next;
	}
	temp = new node();
	temp->data=data;
	temp->next=null;
	it->next=temp;
}
void addAfterElement(struct node **root, int data, int element){
	struct node *temp,*it;
	it=*root;
	temp = new node();
	temp->data = data;
	while(it->data != element){
		it = it->next;
	}
	temp->next=it->next;
	it->next=temp;
}
void deleteFirst(struct node **root){
	struct node *temp = *root;
	*root = (*root)->next;
	delete(temp);
}
void deleteLast(struct node **root){
	struct node *it = *root;
	while(it->next->next != null){
		it = it->next;
	}
	struct node *temp = it->next;
	it->next = null;
	delete(temp);
}
void deleteNode(struct node **root, int data){
	struct node *it;
	it=*root;
	if(it==null){
		cout<<"empty list"<<endl;
		return;
	}
	if(it->data == data){
		deleteFirst(&(*root));
	} else {
		while(it->next->data != data){
			it=it->next;
			if(it->next == null){
				break;
			}
		}
		if(it->next == null){
			cout<<"no element present with given data"<<endl;
		} else {
			struct node *temp;
			temp = it->next;
			it->next=temp->next;
			delete(temp);
		}
		
	}
}
int recursiveLength(struct node *root){
	if(root == null)
	return 0;
	else return 1+recursiveLength(root->next);
}
int main(){
	struct node *root;
	root = null;
	ifstream fin;
	fin.open("data.txt");
	struct node *temp;
	int x;
	while(!fin.eof()){
		fin>>x;
		struct node *t;
		t=new node();
		t->data=x;
		t->next=null;
		if(root == null){
			root = t;
			temp=root;
		} else {
			temp->next = t;
			temp = temp->next;
			
		}
	}
	cout<<"*******************Linked List******************"<<endl;
	printLinkedList(root);
	
	cout<<"Adding 126 at the end"<<endl;
	addEnd(&root, 126);
	cout<<"****************After adding****************"<<endl;
	printLinkedList(root);
	cout<<"Adding 62 at the beginning"<<endl;
	addBegin(&root,62);
	cout<<"****************After adding****************"<<endl;
	printLinkedList(root);
	cout<<"adding 99 after 55"<<endl;
	addAfterElement(&root, 99, 55);
	cout<<"****************After adding****************"<<endl;
	printLinkedList(root);
	cout<<"deleting first element"<<endl;
	deleteFirst(&root);
	printLinkedList(root);
	cout<<"deleting last element"<<endl;
	deleteLast(&root);
	printLinkedList(root);
	while(1){
		cout<<"enter element to be deleted (-1 to break): ";
		cin>>x;
		if(x = -1)
		break;
		deleteNode(&root,  x);
		printLinkedList(root);
	}
	int length = recursiveLength(root);
	cout<<"length of list is: "<<length<<endl;
	return 0;
}
