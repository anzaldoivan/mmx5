#include "types.h"
#include "mmx5/globals.h"

extern void (*D_800FA220_ovl03[])(u8*);

void func_800F87D4_ovl03(u8* a0) {
    signed char state;

    if (*(s32*)(a0 + 0x84) == 0 && a0[0x70] == 0) {
        func_8002F8FC(a0);
    }
    state = *(signed char*)(a0 + 2);
    a0[3] = 0;
    if (state < 8) {
        if (state >= 0) {
            D_800FA220_ovl03[*(signed char*)(a0 + 4)](a0);
        }
    }
}
