#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

node* create_node(int data) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    return new_node;
}

void remove_node(node **head, node **tail, int choice) {
    if (*head == NULL) {
        printf("Linked List is empty\n");
        return;
    }

    if (choice == 4) {  // Remove from start
        node *temp = *head;
        *head = (*head)->next;
        (*tail)->next = *head;
        printf("temp pointing at %d\n", temp->data);
        printf("Head pointing at: %d\n", (*head)->data);
        printf("Tail pointing at: %d\n", (*tail)->data);
        free(temp);
    } 
    else if (choice == 5) {  // Remove from end
        node *temp = *head;
        while (temp->next != *tail)
            temp = temp->next;
        temp->next = (*tail)->next;
        free(*tail);
        *tail = temp;
    } 
    else if (choice == 6) {  // Remove from given location
        int p, i = 1;
        printf("Enter the node number you want to remove: ");
        scanf("%d", &p);
        node *temp = *head, *temp2;

        if (p == 1) {
            *head = (*head)->next;
            (*tail)->next = *head;
            free(temp);
            return;
        }

        do {
            if (p - 1 == i) {
                if (temp->next == *tail) {
                    *tail = temp;
                }
                temp2 = temp->next;
                temp->next = temp2->next;
                free(temp2);
                return;
            }
            temp = temp->next;
            i++;
        } while (temp != *head);

        if (temp == *head) 
            printf("Invalid Input\n");
    }
}

void add(node **head, node **tail, int choice) {
    int data;
    printf("Enter the data you want to create node with: ");
    scanf("%d", &data);
    node *new_node = create_node(data);

    if (choice == 1) {  // Add at start
        if (*head == NULL) 
            *tail = new_node;
        new_node->next = *head;
        *head = new_node;
        (*tail)->next = *head;
    } 
    else if (choice == 2) {  // Add at end
        if (*head == NULL) {
            new_node->next = new_node;
            *head = new_node;
            *tail = new_node;
        } else {
            (*tail)->next = new_node;
            new_node->next = *head;
            *tail = new_node;
        }
    } 
    else if (choice == 3) {  // Add at given location
        if (*head == NULL) {
            printf("LL is empty\n");
            return;
        }

        int p, i = 1;
        printf("At which position you want to insert this node: ");
        scanf("%d", &p);

        if (p == 1) {
            new_node->next = *head;
            *head = new_node;
            (*tail)->next = new_node;
            printf("Added at start\n");
            return;
        }

        node *temp = *head;
        do {
            if (p - 1 == i) {
                if (temp == *tail) {
                    *tail = new_node;
                }
                new_node->next = temp->next;
                temp->next = new_node;
                printf("Node added\n");
                break;
            }
            temp = temp->next;
            i++;
        } while (temp != *head);

        if (temp == *head) {
            printf("Invalid input\n");
        }
    }
}

void display(node *head) {
    if (head == NULL) {
        printf("Linked List is empty\n");
        return;
    }
    node *temp = head;
    printf("Linked List is: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main() {
    node *head = NULL, *tail = NULL;
    int choice = 1;
    while (choice != 0) {
        printf("Enter your choice:\n1 : Add at start\n2 : Add at end\n3 : Add at given location\n4 : Delete at start\n5 : Delete at end\n6 : Delete at given location\n7 : Display\nYour choice: ");
        scanf("%d", &choice);
        if (choice >= 1 && choice <= 3) {
            add(&head, &tail, choice);
        } else if (choice >= 4 && choice <= 6) {
            remove_node(&head, &tail, choice);
        } else if (choice == 7) {
            display(head);
        }
    }
    return 0;
}
