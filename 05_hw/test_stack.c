#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// ���� ��� ������� ���������� ��������� � ����
void test_push() {
    Stack stack;
    initStack(&stack);

    push(&stack, 15);
    push(&stack, 25);
    push(&stack, 35);

    // ��������� ������������ �������� ��������
    const Node* top = getTop(&stack);
    assert(top != NULL && top->data == 35);

    destroyStack(&stack);
    printf("test_push: PASSED\n");
}

// ���� ��� ������� �������� ��������� �� �����
void test_pop() {
    Stack stack;
    initStack(&stack);

    push(&stack, 15);
    push(&stack, 25);
    push(&stack, 35);

    pop(&stack);
    assert(getTop(&stack)->data == 25);

    pop(&stack);
    assert(getTop(&stack)->data == 15);

    pop(&stack);
    assert(isEmpty(&stack));

    destroyStack(&stack);
    printf("test_pop: PASSED\n");
}

// ���� ��� �������� ������� �����
void test_isEmpty() {
    Stack stack;
    initStack(&stack);

    assert(isEmpty(&stack)); // ���� ���� ��� �������������

    push(&stack, 42);
    assert(!isEmpty(&stack)); // ���� ������ �� ����

    pop(&stack);
    assert(isEmpty(&stack)); // ����� �������� ���� ����� ����

    destroyStack(&stack);
    printf("test_isEmpty: PASSED\n");
}

// ���� ��� ������ �� ��������
void test_searchByValue() {
    Stack stack;
    initStack(&stack);

    push(&stack, 5);
    push(&stack, 15);
    push(&stack, 25);

    const Node* found = searchByValue(&stack, 15);
    assert(found != NULL && found->data == 15);

    found = searchByValue(&stack, 99);
    assert(found == NULL);

    destroyStack(&stack);
    printf("test_searchByValue: PASSED\n");
}

// ���� ��� ������ �� �������
void test_searchByIndex() {
    Stack stack;
    initStack(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    const Node* result = searchByIndex(&stack, 1);
    assert(result != NULL && result->data == 20);

    result = searchByIndex(&stack, 5);
    assert(result == NULL);

    destroyStack(&stack);
    printf("test_searchByIndex: PASSED\n");
}

// ���� ��� ������� ��������� �������� ��������
void test_getTop() {
    Stack stack;
    initStack(&stack);

    push(&stack, 8);
    push(&stack, 18);

    const Node* top = getTop(&stack);
    assert(top != NULL && top->data == 18);

    pop(&stack);
    assert(getTop(&stack)->data == 8);

    destroyStack(&stack);
    printf("test_getTop: PASSED\n");
}

// ���� ��� ����������� ������������ ������
void test_destroyStack() {
    Stack stack;
    initStack(&stack);

    push(&stack, 1);
    push(&stack, 2);

    destroyStack(&stack);
    assert(getTop(&stack) == NULL);

    printf("test_destroyStack: PASSED\n");
}

// ���� ��� �������� ����
void test_createNode() {
    Node* node = createNode(100);
    assert(node != NULL && node->data == 100 && node->next == NULL);

    free(node);
    printf("test_createNode: PASSED\n");
}

// ���� ��� ������������� �����
void test_initStack() {
    Stack stack;
    initStack(&stack);
    assert(stack.top == NULL);

    printf("test_initStack: PASSED\n");
}

// ���� ��� ����������� ����������� �����
void test_traverseStack() {
    Stack stack;
    initStack(&stack);

    push(&stack, 3);
    push(&stack, 6);
    push(&stack, 9);

    printf("Expected output: 9 6 3\n");
    printf("Actual output:   ");
    traverseStack(&stack);

    destroyStack(&stack);
    printf("test_traverseStack: PASSED\n");
}

// ������� ������� ��� ������� ���� ������
int main() {
    printf("Starting test suite...\n");

    test_createNode();
    test_initStack();
    test_destroyStack();
    test_push();
    test_pop();
    test_isEmpty();
    test_searchByValue();
    test_searchByIndex();
    test_getTop();
    test_traverseStack();

    printf("All tests completed successfully.\n");
    return 0;
}
