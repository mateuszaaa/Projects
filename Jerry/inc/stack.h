#ifndef STACK_H
#define STACK_H
#include "defines.h"
#include <stdio.h> 
typedef enum{
FORWARD,
ROTATE
}move_type;

typedef struct s_element{
    int value;
    move_type type;
}element;

typedef struct s_queue{
    element tab[10];
    int index;
    int count;

}moves_queue;

volatile moves_queue robot_queue;

void initQueue(moves_queue * queue);
void addMove(moves_queue* queue,move_type type,int value);
void switchToNextMove(moves_queue* );
void setNodeValue(moves_queue* ,element );
element getElement(moves_queue *);
uint8_t allMovesDone(moves_queue * );

#endif
