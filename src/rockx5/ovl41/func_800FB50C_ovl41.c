#include "types.h"
#include "mmx5/globals.h"

void func_800FB50C_ovl41(UnkObj* e) {
    u8* p;
    u8* q;

    if (--e->unk6 == 0) {
        q = D_8009A1F8.u;
        *(s16*)(q + 0xB6) += 0x100;
        if (*(s16*)(q + 0xB6) >= 0x300) {
            *(s16*)(q + 0xB6) = 0;
        }
        e->unk6 = 0x3C;
    }
    p = D_8009A1F8.u;
    p[0xF4] = 1;
    e->unk4 = 0;
    e->unk1++;
}
