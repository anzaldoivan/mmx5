#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/object.h"

extern signed char D_8009A424;
extern u8* D_800FB59C_ovl53;

void func_800FA528_ovl53(Ovl45State* s) {
    u8* p;
    u8* q;

    if (D_8009A424 == 0) {
        D_800FB59C_ovl53[4] = 2;
        p = alloc_class6_slot();
        if (p != 0) {
            p[0] = 1;
            p[1] = 9;
            p[0x36] = 0x11;
            *(s16*)(p + 0x34) = 0x7FFF;
            p[2] = 0;
            *(s32*)(p + 0x38) = 0x1E;
        }
        q = D_8009A1F8.u;
        *(s16*)(q + 0xB2) = 0;
        *(s16*)(q + 0xB6) = 0;
        q[0xAB] = 1;
        q[0xF4] = 1;
        s->unk4 = 1;
        s->unk1++;
    }
}
