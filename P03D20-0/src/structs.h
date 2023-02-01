#ifndef SRC_STRUCTS_H_
#define SRC_STRUCTS_H_




struct QNode {
    struct QNode *next;
    int op;
    double value;
};

struct QNode *create_queue(int op, double value);

typedef struct {
    struct QNode *first;
} Queue;

Queue *init_queue();
void push_queue(Queue *q, int op, double value);
int pop_queue(Queue *q, int *op, double *value);
void destroy_queue(Queue *q);
Queue *clone_queue(Queue *from);

typedef struct {
    struct QNode *last;
} Stack;

Stack *init_stack();
void push_stack(Stack *s, int op, double value);
int pop_stack(Stack *s, int *op, double *value);
void destroy_stack(Stack *s);

#endif  // SRC_STRUCTS_H_
