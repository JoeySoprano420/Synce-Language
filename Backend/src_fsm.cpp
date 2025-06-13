#include "fsm.h"

void transition(FSMNode* node, int new_state, FSMHandler handler) {
    node->state = new_state;
    node->handler = handler;
}
