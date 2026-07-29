#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
    int x;
    struct Node *next;
} Node;

int main() {
    // Start timing
    clock_t start_time = clock();

    // Create head node
    Node *head = (Node *)malloc(sizeof(Node));
    head->x = 0;
    head->next = NULL;

    Node *last = head;

    // Loop to add 300 million nodes sequentially
    for (int i = 1; i < 100000000; i++) {
        Node *new_node = (Node *)malloc(sizeof(Node));
        new_node->x = i;
        new_node->next = NULL;

        last->next = new_node;
        last = new_node;
    }

    // End timing
    clock_t end_time = clock();
    double cpu_time_used = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    printf("100 million variables created in %.2f seconds\n", cpu_time_used);

    // Optional: Print a node to verify
    printf("Sample check (node value): %d\n", head->next->next->x);

    // Clean up memory (Note: freeing 300 million nodes sequentially can also take a moment)
    Node *current = head;
    while (current != NULL) {
        Node *temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
