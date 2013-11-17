#include "stack.h"

void initQueue(moves_queue * queue){
    queue->index = -1;
    queue->count = 0;
}

element createElement(int16_t value,move_type type){
    element move;
    move.value = value;
    move.type = type;
    return move;
}

void switchToNextMove(moves_queue* queue){
   queue->index++; 
}

void addMove(moves_queue* queue,move_type type,int value){
    element move;
    move.type = type;
    move.value = value;
    queue->tab[queue->count] = move;
    queue->count++;
}

element getElement(moves_queue * queue){
    element elem;
    elem = queue->tab[queue->index]; 
    return elem;
}

uint8_t allMovesDone(moves_queue * queue){


    if ( queue -> index < queue->count)
        return 0;
    else    
        return 1;
}

