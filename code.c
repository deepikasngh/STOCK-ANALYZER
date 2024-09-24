
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Structure for a stock item
struct StockItem
{
  int id;
  char name[20];
  int quantity;
  float cost;
};

//Linked List Node
struct node
{
  struct StockItem item;
  struct node *next;
};

struct node *head = NULL;

//Function to create a new node
struct node *createnode()
{
  struct node *p;
  p = (struct node *)malloc(sizeof(struct node));
  return p;
}

//Function to add a new item to the stock
void addItem()
{
  struct node *temp, *t;
  temp = createnode();
  printf("Enter item id: ");
  scanf("%d", &temp->item.id);
  printf("Enter item name: ");
  scanf("%s", temp->item.name);
  printf("Enter item quantity: ");
  scanf("%d", &temp->item.quantity);
  printf("Enter cost of item: ");
  scanf("%f", &temp->item.cost);
  temp->next = NULL;
  if(head == NULL){
    head = temp;
  }
  else{
    t = head;
    while(t->next!=NULL){
      t = t->next;
    }
    t->next = temp;
  }
  printf("Item added successfully!\n");
  printf("\n");
}

//Function to update the stock
void updateItem()
{
  int id, flag = 0;
  printf("Enter item id: ");
  scanf("%d", &id);
  struct node *t;
  t = head;
  while(t!=NULL){
    if(t->item.id == id){
      printf("Enter the updated quantity: ");
      scanf("%d", &t->item.quantity);
      flag = 1;
      printf("Item updated successfully!\n");
      printf("\n");
      break;
    }
    t = t->next;
  }
  if(flag == 0){
    printf("Item not found!\n");
    printf("\n");
  }
}

//Function to search item in the stock
void searchItem()
{
  int id, flag = 0;
  printf("Enter item id: ");
  scanf("%d", &id);
  struct node *t;
  t = head;
  while(t!=NULL){
    if(t->item.id == id){
      printf("Item Id: %d\n", t->item.id);
      printf("Item Name: %s\n", t->item.name);
      printf("Item Quantity: %d\n", t->item.quantity);
      printf("Item Cost: %f\n", t->item.cost);
      flag = 1;
      break;
    }
    t = t->next;
  }
  if(flag == 0){
    printf("Item not found!\n");
    printf("\n");
  }
}


//Function to delete item from the stock
void deleteItem()
{
  int id, flag = 0;
  printf("Enter item id: ");
  scanf("%d", &id);
  struct node *t, *prev;
  t = head;
  if(t->item.id == id){
    head = t->next;
    free(t);
    flag = 1;
    printf("Item deleted successfully!\n");
    printf("\n");
  }
  else{
    while(t!=NULL){
      if(t->item.id == id){
        prev->next = t->next;
        free(t);
        flag = 1;
        printf("Item deleted successfully!\n");
        printf("\n");
        break;
      }
      prev = t;
      t = t->next;
    }
  }
  if(flag == 0){
    printf("Item not found!\n");
    printf("\n");
  }
}

//Function to display all the items in the stock
void displayList()
{
  struct node *t;
  t = head;
  if(t == NULL){
    printf("No items in the stock!\n");
    printf("\n");
  }
  else{
    while(t!=NULL){
      printf("Item Id: %d\n", t->item.id);
      printf("Item Name: %s\n", t->item.name);
      printf("Item Quantity: %d\n", t->item.quantity);
      printf("Item Cost: %f\n", t->item.cost);
      printf("\n");
      t = t->next;
    }
  }
}

//Main Function
int main()
{
  int ch;
  while(1){
    printf("Stock Management System\n");
    printf("1. Add item\n");
    printf("2. Update item\n");
    printf("3. Search item\n");
    printf("4. Delete item\n");
    printf("5. Display list\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &ch);
    switch(ch){
      case 1:
        addItem();
        break;
      case 2:
        updateItem();
        break;
      case 3:
        searchItem();
        break;
      case 4:
        deleteItem();
        break;
      case 5:
        displayList();
        break;
      case 6:
        exit(0);
        break;
      default:
        printf("Invalid choice!\n");
        printf("\n");
        break;
    }
  }
  return 0;
}