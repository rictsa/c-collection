#include <stdio.h>
#include <string.h>
#include "stack.h"
#include "queue.h"

#define OPERATOR_NUM 12
#define OPERATOR_STRING_SIZE 32

/*** STACK ***/
void UGpush(Stack *stack) {
	int num;
	scanf("%d", &num);
	push(createNode(num), stack);
}
void UGpop(Stack *stack) {
	pop(stack);
}
void UGtop(Stack *stack) {
	if(*stack == NULL) printf("top = NULL\n");
	else printf("top = %d\n", top(*stack) -> element);
}
void UGisStackEmpty(Stack *stack) {
	printf("isStackEmpty = %d\n", isStackEmpty(*stack));
}
void UGdeleteStack(Stack *stack) {
	deleteStack(stack);
}
void UGstackSize(Stack *stack) {
	printf("stackSize = %d\n", stackSize(*stack));
}
/*** QUEUE ***/
void UGenqueue(Queue *queue) {
	int num;
	scanf("%d", &num);
	enqueue(createNode(num), queue);
}
void UGdequeue(Queue *queue) {
	dequeue(queue);
}
void UGfirst(Queue *queue) {
	if(*queue == NULL) printf("first = NULL\n");
	else printf("first = %d\n", first(*queue) -> element);
}
void UGisQueueEmpty(Queue *queue) {
	printf("isQueueEmpty = %d\n", isQueueEmpty(*queue));
}
void UGdeleteQueue(Queue *queue) {
	deleteQueue(queue);
}
void UGqueueSize(Queue *queue) {
	printf("queueSize = %d\n", queueSize(*queue));
}
/*** MAIN ***/
void UGprintAll(NodePtr *ptr) {
	NodePtr p;
	for(p = *ptr; p != NULL; p = p -> next) {
		printf(" %d", p -> element);
	} printf("\n");
}
void (*op[OPERATOR_NUM + 1])(NodePtr *ptr) = {
	UGpush, UGpop, UGtop, UGisStackEmpty, UGdeleteStack, UGstackSize,
	UGenqueue, UGdequeue, UGfirst, UGisQueueEmpty, UGdeleteQueue, UGqueueSize,
	UGprintAll
};

const char operator_string[OPERATOR_NUM][OPERATOR_STRING_SIZE] = { 
	"push", "pop", "top", "isStackEmpty", "deleteStack", "stackSize",
	"enqueue", "dequeue", "first", "isQueueEmpty", "deleteQueue", "queueSize"
};

int getOperatorIndex(char *operator) {
	int i = 0;
	for(; i < OPERATOR_NUM; ++i) {
		if(strcmp(operator, operator_string[i]) == 0) {
			return i;
		}	
	}
	return OPERATOR_NUM;
}
int main(){
	Stack stack = NULL;
	Queue queue = NULL;
	int index;
	char operator[OPERATOR_STRING_SIZE];

	while(scanf("%s", operator) == 1) {
		index = getOperatorIndex(operator);	
		if(index < 6) {
			printf("====== STACK : %s ======\n", operator_string[index]);
			op[index](&stack);	
			printf("stack :"); op[OPERATOR_NUM](&stack);
		} else if(index < 12) {
			printf("====== QUEUE : %s ======\n", operator_string[index]);
			op[index](&queue);
			printf("queue :"); op[OPERATOR_NUM](&queue);
		} else {
			printf("====== WRONG INPUT ======\n");
		}
	}
	deleteStack(&stack);
	deleteQueue(&queue);
    return 0;
}

