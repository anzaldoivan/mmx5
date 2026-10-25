#include "types.h"

extern int func_8002D6FC();
extern s16 D_8009A0AA;
extern s8 D_800D1C26;
extern void (*D_800FB148_ovl09[])(signed char*);

void func_800F72C0_ovl09(signed char* arg0) {
    if (D_8009A0AA >= 0x8C0) {
        func_8002D6FC();
    } else if (D_800D1C26 == 0) {
        D_800FB148_ovl09[arg0[4]](arg0);
    }
}
