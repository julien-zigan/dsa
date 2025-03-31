#ifndef __DIJKSTRA_H__
#define __DIJKSTRA_H__

#define IDBUF 16

struct node_t;

typedef enum status_t {
    PERMANENT,
    TENTATIVE,
    UNDEFINED
} STATUS_T;

typedef struct label_t {
    unsigned int sum_weight;
    struct node_t *next_hop;
    STATUS_T status;
} LABEL_T;


typedef struct edge_t {
    struct edge_t *next;
    unsigned int weight;
    struct node_t *node;

} EDGE_T;

typedef struct node_t {
    char id[IDBUF];
    EDGE_T *edges;
    LABEL_T label;

} NODE_T;

#endif
