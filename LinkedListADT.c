#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode{
  char data;
  struct ListNode *next;
}ListNode;

ListNode *head;    //create
ListNode *current;


void addTail(char data);
void printList();
void get_data();
void traverse_front(ListNode *list);
void delete_node(ListNode *list);
void add(ListNode *list, char data);
void traverse_rear(ListNode *list);
void replace(ListNode *list, char data);
void data_count(ListNode *list);
void is_member(char data);
void is_empty(ListNode *list);
int count(char cmd[]);
void init();
void freeList();


int main(void) {
  char cmd[3];
  init();

  switch (cmd[0]){
    case '+':
      addTail(cmd[1]);
      break;
    case 'L':
      printList();
      break;
    case 'G':
      get_data();
      break;
    case '<':
      traverse_front();
      break;
    case '-':
      delete_node();
      break;
    case '>':
      traverse_rear();
      break;
    case '=':
      replace();
      break;
    case '#':
      data_count();
      break;
    case '?':
      is_member();
      break;
    case 'E':
      is_empty();
      break;
    default:
      printf("다른 문자를 입력해주세요.")
  }
  return 0;
}

void addTail(char data){
  ListNode* ptr;
  ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
  newNode->data = data;
  newNode->next = NULL;

  if(head==NULL){
    head = newNode;
  }
  else{
    
  }
}
void printList(){
 ListNode* ptr;
  for(ptr=head; ptr->next; ptr=ptr->next)
    printf("%c\t", ptr->data);
  printf("%c",ptr->data);
  for(ptr=head; ptr->next; ptr=ptr->next){
    if(current==ptr)
      printf("-\t");
  }
}
void get_data(){
  printf("%c\n", current->data);
}
void traverse_front(ListNode *list){
  current=head;
  
}
void delete_node(ListNode *list){
  
};
void add(ListNode *list);
void traverse_rear(ListNode *list);
void replace(ListNode *list);
void data_count(ListNode *list);
void is_member(ListNode *list);
void is_empty(ListNode *list,);
void init(){
  head=NULL;
}
int count(char cm[]){
  int add=0;
  
  for(int i=1;i<3;i++){
    if(cm[i]=='N')
      add=add+1;
    else if(cm[i]=='P')
      add=add-1;
  }

  return add;
}
void freeList(){
  
}