#include "types.h"

extern void func_8002C1C8(void);
extern Spawn800FB000* func_8002D53C(void);
extern u8 D_80091C44;
extern u8 D_8009A1F8[];
extern u8* D_800FAC30_ovl46;

void func_800FA368_ovl46(u8* arg0) {
    u8* b;
    Spawn800FB000* p;

    if (D_80091C44 == 0) {
        b = D_8009A1F8;
        *(s16*)(b + 0xB2) = 0;
        *(s16*)(b + 0xB6) = 0x100;
        b[0xF4] = 1;
        func_8002C1C8();
        p = func_8002D53C();
        if (p != 0) {
            p->unk0 = 1;
            p->unk1 = 0xA;
            p->unk36 = 0x31;
            p->unk2 = 0;
            D_800FAC30_ovl46 = (u8*)p;
        }
        p = func_8002D53C();
        if (p != 0) {
            p->unk1 = 9;
            p->unk36 = 0x20;
            p->unk0 = 1;
            p->unk34 = 0x7FFF;
            p->unk2 = 2;
            p->unk38 = 0x1E;
        }
        *(s16*)(arg0 + 4) = 1;
        arg0[1]++;
    }
}
