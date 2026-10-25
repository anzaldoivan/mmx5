/* Shared body (DK-5), from the banked draft of func_800FAC04_ovl58 by tools/wave/gate.py rescan. */
#include "types.h"

extern D_8009A1F8_t D_8009A1F8;
extern void func_8002C1C8(void);
extern u8* func_8002D53C(void);

void DEDUP_NAME(UnkObj* arg0) {
    u8* s;
    D_8009A1F8_t* p;

    arg0->unk4++;
    if (arg0->unk4 >= 0x3D) {
        func_8002C1C8();
        s = func_8002D53C();
        if (s != 0) {
            s[0] = 1;
            s[1] = 9;
            s[0x36] = 0x11;
            *(s16*)(s + 0x34) = 0x7FFF;
            s[2] = 3;
            *(s32*)(s + 0x38) = 0x1E;
        }
        p = &D_8009A1F8;
        *(s16*)&p->padA1[0xB2 - 0xA1] = 0;
        p->unkB6 = 0x200;
        p->unkF4 = 1;
        arg0->unk4 = 1;
        arg0->unk6 = 0;
        arg0->unk1++;
    }
}
