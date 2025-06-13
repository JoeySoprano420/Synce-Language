#pragma once

typedef void (*FSMHandler)(void*);

struct FSMNode {
    int state;
    FSMHandler handler;
};

void transition(FSMNode* node, int new_state, FSMHandler handler);
