#include "types.h"

extern void (*D_8007BC60[])(X4_Obj*);

void func_80052B34(X4_Obj* arg0) {
    D_8007BC60[arg0->unk2](arg0);
    arg0->on_screen = 1;
}
