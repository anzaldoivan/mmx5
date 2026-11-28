#include "types.h"
#include "mmx5/object.h"

Obj8002CC08* func_8002D078(void) {
    Obj8002CC08* p;
    u8* q;
    s32 i;

    for (p = D_80098120.cc08; p < &D_80098120.cc08[32]; p++) {
        if (p->active == 0) {
            q = (u8*)p;
            for (i = sizeof(Obj8002CC08) - 1; i != -1; i--) {
                *q++ = 0;
            }
            p->unk50 = 0;
            p->unk54.w = 0;
            p->unk68 = 0;
            return p;
        }
    }
    return 0;
}
