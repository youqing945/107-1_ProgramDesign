#include<stdio.h>
#include<stdlib.h>
int i;

typedef struct node{
    int value;
    struct node *next;
} Node;

Node *SLL_build();
Node *SLL_qsort();
void *SLL_qsort2();
void SLL_print();
void SLL_delete();


int main(int argc, char *argv[]){
    srand(atoi(argv[3]));
    Node *llist = SLL_build(atoi(argv[1]), atoi(argv[2]));
    printf("Original SLL:");
    SLL_print(llist);
    llist = SLL_qsort(llist);
    printf("Sorted SLL:");
    SLL_print(llist);
    SLL_delete(llist);

    return 0;
}

Node *SLL_build(int n, int m){
    Node *node_head = malloc(sizeof(Node));
    Node *node_tag = node_head, *node_curr;
    for(i=0;i<n;i++){
        node_curr = malloc(sizeof(Node));
        node_tag->next = node_curr;
        node_curr->next = NULL;
        node_tag = node_curr;
    }
    Node *tmp = node_head;
    tmp->value = -1;
    tmp = tmp->next;
    while(tmp!=NULL) tmp->value = rand() % m, tmp = tmp->next;
    return node_head;
}

Node *SLL_qsort(Node *node_head){
    Node *node_last = node_head;
    while(node_last->next!=NULL)node_last = node_last->next;
    SLL_qsort2(node_head, node_last);
    return node_head;
}

void *SLL_qsort2(Node *head, Node *tag){
    if(head->next==tag){
        if((head->value)>(tag->value)){
            int a = head->value;
            head->value = tag->value;
            tag->value = a;
        }
    }
    else if(head==tag){}
    else{
        Node *last = tag, *cur = head, *tmp;
        while(cur->next!=tag){
            if((cur->next->value)>(tag->value)){
                tmp = cur->next;
                cur->next = cur->next->next;
                tmp->next = last->next;
                last->next = tmp;
                last = tmp;
            }
            else cur = cur->next;
        }
        SLL_qsort2(head, cur);
        SLL_qsort2(tag, last);
    }
}

void SLL_print(Node *head){
    Node *tmp = head->next;
    while(tmp!=NULL){
        printf(" %d", tmp->value);
        tmp = tmp->next;
    }
    printf("\n");
}

void SLL_delete(Node *head){
    Node *cur = head, *tmp;
    while(cur!=NULL){
        tmp = cur->next;
        free(cur);
        cur = tmp;
    }
}
