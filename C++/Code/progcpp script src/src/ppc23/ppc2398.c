#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <assert.h>

typedef struct {
    uint64_t a;
    uint16_t b;
    uint8_t c;
} 
//__attribute__((packed)) 
testStruct_ts ;

typedef struct listNode {
    uint8_t data;
    struct listNode* next;
} node;

void initList(node** list, uint8_t data_u8);
void printList(const node* list);
void addNode(node* const list, uint8_t const data);
void freeList(node** list);

static testStruct_ts testStruct_s;

int main(){
    testStruct_s.a = 2;
    testStruct_s.b = 0;
    
    printf("%p %p %p \n", &testStruct_s, &testStruct_s.a, &testStruct_s.b);
    
    printf("size: %ld %ld\n", sizeof(testStruct_ts), sizeof(testStruct_s));
    
    
    node* list = NULL;
    initList(&list, 1);
    addNode(list, 2);
    addNode(list, 3);
    printList(list);
    freeList(&list);
}

node* allocNode(uint8_t const data) {
    node* const n = malloc(sizeof(node));
    assert(n);
    n->data= data;
    n->next = NULL;
    return n;
}

void addNode(node* const list, uint8_t const data) {
    node* n = list;
    while(n->next) {
        n = n->next;
    }
    assert(!n->next);
    n->next = allocNode(data);
}

void initList(node** const list, uint8_t const data) {
    if (*list) return;
    assert(!*list);
    *list = allocNode(data);
    assert(*list);
}

void freeList(node** const list) {
    assert(list);
    node* n = *list;
    while(n) {
        node* const nn = n->next;
        free(n);
        n = nn;
    }
}

void printList(const node* const list) {
    for(const node* n = list; n; n = n->next) {
        printf("address: %p\tvalue: %i\n", n, n->data);
    }
}
