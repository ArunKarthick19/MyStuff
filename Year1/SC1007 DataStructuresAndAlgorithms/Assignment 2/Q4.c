/////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <limits.h> // Include limits.h for INT_MIN

#define SIZE 1000 // The limit of expression length

////////////////////////////////////////////////////

typedef struct _listnode {
    double item;
    struct _listnode *next;
} ListNode;

typedef struct _linkedlist {
    int size;
    ListNode *head;
} LinkedList;

////////////////////////////////// stack    /////////

typedef struct stack {
    LinkedList ll;
} Stack;

//////////////////////// function prototypes //////////////

// You should not change the prototypes of these functions

double postfixEvaluation(char* postfix);

////////////////////////////////////////////////////////////

void push(Stack *s, double item);
double pop(Stack *s); // Change return type to double
double peek(Stack *s); // Change return type to double
int isEmptyStack(Stack *s);

//////////////////////////////////////////////////////////////
void printList(LinkedList *ll);
ListNode *findNode(LinkedList *ll, int index);
int insertNode(LinkedList *ll, int index, double item);
int removeNode(LinkedList *ll, int index);
void removeAllItems(LinkedList *ll);

//////////////////////////////////////////////////////////////

int main() {
    char postfix[SIZE];

    printf("Enter a postfix expression:\n");
    scanf("%[^\n]%*c", postfix);

    printf("The answer is %.2lf\n", postfixEvaluation(postfix)); // Correct function name

    return 0;
}

double postfixEvaluation(char* postfix)
{
    Stack f;
    f.ll.head = NULL;
    f.ll.size = 0;
    double k;

    while (*postfix)
    {
        char c = *postfix;

        if (c >= '0' && c <= '9')
            push(&f, c - '0');
        if (c == '+' || c == '-' || c == '*' || c == '/')
        {

            double p1 = pop(&f);
            double p2 = pop(&f);
            if (c == '+')
                k = p2 + p1;
            else if (c == '-')
                k = p2 - p1;
            else if (c == '*')
                k = p2 * p1;
            else if (c == '/')
                k = p2 / p1;

            push(&f, k);
        }
        postfix++;
    }

    return peek(&f);
}




//////////////////////////////////////////////////////////////////////

void push(Stack *s, double item) {
    insertNode(&(s->ll), 0, item);
}

double pop(Stack *s) { // Change return type to double
    double item;
    if (!isEmptyStack(s)) {
        item = ((s->ll).head)->item;
        removeNode(&(s->ll), 0);
        return item;
    }
    return INT_MIN;
}

double peek(Stack *s) { // Change return type to double
    return ((s->ll).head)->item;
}

int isEmptyStack(Stack *s) {
    if ((s->ll).size == 0)
        return 1;
    return 0;
}

/////////////////////////////////////////////////////////////

void printList(LinkedList *ll) {

    ListNode *cur;
    if (ll == NULL)
        return;
    cur = ll->head;

    if (cur == NULL)
        printf("Empty");
    while (cur != NULL) {
        printf("%.2lf ", cur->item);
        cur = cur->next;
    }
    printf("\n");
}

ListNode *findNode(LinkedList *ll, int index) {

    ListNode *temp;

    if (ll == NULL || index < 0 || index >= ll->size)
        return NULL;

    temp = ll->head;

    if (temp == NULL || index < 0)
        return NULL;

    while (index > 0) {
        temp = temp->next;
        if (temp == NULL)
            return NULL;
        index--;
    }

    return temp;
}

int insertNode(LinkedList *ll, int index, double value) {

    ListNode *pre, *cur;

    if (ll == NULL || index < 0 || index > ll->size + 1)
        return -1;

    // If empty list or inserting first node, need to update head pointer
    if (ll->head == NULL || index == 0) {
        cur = ll->head;
        ll->head = malloc(sizeof(ListNode));
        ll->head->item = value;
        ll->head->next = cur;
        ll->size++;
        return 0;
    }


    // Find the nodes before and at the target position
    // Create a new node and reconnect the links
    if ((pre = findNode(ll, index - 1)) != NULL) {
        cur = pre->next;
        pre->next = malloc(sizeof(ListNode));
        pre->next->item = value;
        pre->next->next = cur;
        ll->size++;
        return 0;
    }

    return -1;
}

int removeNode(LinkedList *ll, int index){

	ListNode *pre, *cur;

	// Highest index we can remove is size-1
	if (ll == NULL || index < 0 || index >= ll->size)
		return -1;

	// If removing first node, need to update head pointer
	if (index == 0){
		cur = ll->head->next;
		free(ll->head);
		ll->head = cur;
		ll->size--;

		return 0;
	}

	// Find the nodes before and after the target position
	// Free the target node and reconnect the links
	if ((pre = findNode(ll, index - 1)) != NULL){

		if (pre->next == NULL)
			return -1;

		cur = pre->next;
		pre->next = cur->next;
		free(cur);
		ll->size--;
		return 0;
	}

	return -1;
}
