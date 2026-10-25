#include "types.h"

extern int func_8002D6FC();
extern signed char D_8009A0A5;
extern void (*D_800774E4[])(signed char*);

void func_8004C73C(signed char* arg0) {
    if (D_8009A0A5 != 0x3B && D_8009A0A5 != 0x11) {
        func_8002D6FC();
    } else {
        D_800774E4[arg0[4]](arg0);
    }
}
