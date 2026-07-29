#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
    int x;
    struct Node *next;
} Node;

int main() {
    clock_t start_time = clock();

    Node *head = (Node *)malloc(sizeof(Node));
    head->x = 0;
    head->next = NULL;

    Node *last = head;

    for (int i = 1; i < 100000000; i++) {
        Node *new_node = (Node *)malloc(sizeof(Node));
        new_node->x = i;
        new_node->next = NULL;

        last->next = new_node;
        last = new_node;
    }

    clock_t end_time = clock();
    double cpu_time_used = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    printf("100,000,000 million variables created in %.2f seconds\n", cpu_time_used);
    printf("Sample check (node value): %d\n", head->next->next->x);

    Node *current = head;
    while (current != NULL) {
        Node *temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}


// ```[cite: 1]

// ---

// ### How to Compile and Run in Termux

// ```bash
// # Compile with maximum speed optimization
// gcc -O3 datachains.c -o datachains

// # Run the executable
// ./datachains
