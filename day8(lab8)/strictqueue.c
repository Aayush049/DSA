#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int dq[MAX], f = -1, r = -1;

int isFull() { return (f == 0 && r == MAX - 1) || (f == r + 1); }
int isEmpty() { return f == -1; }

void insertLeft(int x) {
    if (isFull()) { printf("Deque full\n"); return; }
    if (f == -1) f = r = 0;
    else if (f == 0) f = MAX - 1;
    else f--;
    dq[f] = x;
}

void insertRight(int x) {
    if (isFull()) { printf("Deque full\n"); return; }
    if (f == -1) f = r = 0;
    else if (r == MAX - 1) r = 0;
    else r++;
    dq[r] = x;
}

void deleteLeft() {
    if (isEmpty()) { printf("Deque empty\n"); return; }
    printf("%d deleted\n", dq[f]);
    if (f == r) f = r = -1;
    else if (f == MAX - 1) f = 0;
    else f++;
}

void deleteRight() {
    if (isEmpty()) { printf("Deque empty\n"); return; }
    printf("%d deleted\n", dq[r]);
    if (f == r) f = r = -1;
    else if (r == 0) r = MAX - 1;
    else r--;
}

void display() {
    if (isEmpty()) { printf("Deque empty\n"); return; }
    printf("Deque: ");
    for (int i = f;; i = (i + 1) % MAX) {
        printf("%d ", dq[i]);
        if (i == r) break;
    }
    printf("\n");
}

int main() {
    int ch, t, x;
    printf("1. Input restricted\n2. Output restricted\nEnter type: ");
    scanf("%d", &t);

    while (1) {
        if (t == 1)
            printf("\n1.Insert right 2.Delete left 3.Delete right 4.Display 5.Quit\n");
        else
            printf("\n1.Insert right 2.Insert left 3.Delete left 4.Display 5.Quit\n");

        printf("Enter choice: ");
        scanf("%d", &ch);

        if (t == 1) {
            switch (ch) {
                case 1: printf("Enter element: "); scanf("%d", &x); insertRight(x); break;
                case 2: deleteLeft(); break;
                case 3: deleteRight(); break;
                case 4: display(); break;
                case 5: exit(0);
                default: printf("Invalid\n");
            }
        } else {
            switch (ch) {
                case 1: printf("Enter element: "); scanf("%d", &x); insertRight(x); break;
                case 2: printf("Enter element: "); scanf("%d", &x); insertLeft(x); break;
                case 3: deleteLeft(); break;
                case 4: display(); break;
                case 5: exit(0);
                default: printf("Invalid\n");
            }
        }
    }
}