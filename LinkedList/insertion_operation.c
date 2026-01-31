//CREATION AND DIFFERENT INSERTION OPERATIONS ON A LINKED LIST

struct Node {
    int data;            
    struct Node* link;   
};
void insert_at_end(struct Node *temp,struct Node *head){
	struct Node *newnode1 = (struct Node*)malloc(sizeof(struct Node));
	printf("Enter data: ");
	scanf("%d",&newnode1->data);
	newnode1->link = NULL;
	temp = head;
	while(temp -> link != NULL){
		temp = temp -> link;
	}
	temp -> link = newnode1;
	temp = head;
	printf("The updated linked list is: ");
	while(temp!=NULL){
		printf("%d ",temp->data);
		temp = temp->link;
	}
	printf("\n");
}
void insert_at_beginning(struct Node *temp,struct Node *head){
	struct Node *temp1;
	struct Node *newnode2 = (struct Node*)malloc(sizeof(struct Node));
	printf("Enter data: ");
	scanf("%d",&newnode2->data);
	temp1 = head;
	head = newnode2;
	temp = newnode2;
	temp -> link = temp1;
	temp = head;
	printf("The updated linked list is: ");
	while(temp!=NULL){
		printf("%d ",temp->data);
		temp = temp->link;
	}
	printf("\n");
}
void insert_at_position(struct Node *temp,struct Node *head){
	int pos;
	struct Node *temp2;
	struct Node *temp3;
	printf("Enter position on which data is to be entered: ");
	scanf("%d",&pos);
	if(pos<1){
		printf("Invalid position!");
	}
	struct Node *newnode3 = (struct Node*)malloc(sizeof(struct Node));
	printf("Enter data: ");
	scanf("%d",&newnode3->data);
	if(pos == 1){
		temp2 = head;
		head = newnode3;
		temp = newnode3;
		temp -> link = temp2;
	}
	else if(pos>1){
		temp = head;
		for (int i = 1; temp != NULL && i < pos - 1; i++) {
	        temp = temp->link;
	    }
	    newnode3->link = temp->link;
	    temp -> link = newnode3;
	}
	else{
		printf("Invalid position");
	}
	printf("The updated linked list is: ");
	while(temp!=NULL){
		printf("%d ",temp->data);
		temp = temp->link;
	}
	printf("\n");
}
int main(){
	int n;
	struct Node *head = NULL;
	struct Node *temp, *newnode;
	int choice=1;
	while(choice==1){
		newnode = (struct Node*)malloc(sizeof(struct Node));
		printf("Enter data: ");
		scanf("%d",&newnode->data);
		newnode->link = NULL;
		if(head==NULL){
			temp = newnode;
			head = newnode;
		}
		else{
			temp->link = newnode;
			temp = newnode;
		}
		printf("Want to enter more data(0,1): ");
		scanf("%d",&choice);
	}
	printf("1 - Insertion at end\n");
	printf("2 - Insertion at beginning\n");
	printf("3 - Insertion at position\n");
	printf("Enter your choice: ");
	scanf("%d",&n);
	switch(n){
		case 1:
			insert_at_end(temp,head);
			break;
		case 2:
			insert_at_beginning(temp,head);
			break;
		case 3:
			insert_at_position(temp,head);
			break;
		}
	return 0;
}
