#include "types.h"

extern Obj8002CD14 D_800C6A10[];

Obj8002CD14* func_8002D210(void) {
    Obj8002CD14* p;
    u8* q;
    s32 i;

    for (p = D_800C6A10; p < D_800C6A10 + 64; p++) {
        if (p->active == 0) {
            q = (u8*)p;
            for (i = sizeof(Obj8002CD14) - 1; i != -1; i--) {
                *q++ = 0;
            }
            p->unk50 = 0;
            p->unk54 = 0;
            p->unk68 = 0;
            return p;
        }
    }
    return 0;
}
