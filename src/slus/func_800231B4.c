#include "types.h"
#include "addr.h"

extern s8 D_800994A0[];
extern void (*D_800712A8[])(s8*);

void func_800231B4(void) {
    s8* p;

    for (D_1F800064 = D_800994A0; D_1F800064 < D_800994A0 + 0xC00;
         D_1F800064 += 0x60) {
        p = D_1F800064;
        if (p[0] != 0) {
            D_800712A8[p[1]](p);
        }
    }
}
