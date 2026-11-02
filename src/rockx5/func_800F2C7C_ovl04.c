#include "types.h"
#include "addr.h"

extern void func_80017248(u8* obj);
extern void func_8002D89C(u8* obj);
extern void func_8002DF54(u8* a0);
extern u8 D_8009A197;
extern u16 D_801016A0_ovl04[][2];
extern u16 D_801016B8_ovl04[][2];

void func_800F2C7C_ovl04(u8* o) {
    u8* p;
    s8 st;
    QByte f; // !FAKE: one-byte struct keeps the andi 0xFF zero test
    u8* q;

    p = *(u8**)(o + 0x50);
    st = p[4];
    if (st != 1 || p[0x84] == 0) {
        o[3] = 0;
        o[4] = 2;
        return;
    }
    {
        if (D_8009A197 == 0) {
            *(s32*)(o + 0x18) = *(s32*)(o + 0x8);
            *(s32*)(o + 0x1C) = *(s32*)(o + 0xC);
            f.b = p[0x15];
            o[0x15] = f.b;
            if (((u8*)D_1F800064)[0x54] == st) {
                if (f.b == 0) {
                    *(u16*)(o + 0xA) = *(u16*)(p + 0xA) -
                                       D_801016A0_ovl04[*(s8*)(o + 0x45)][0];
                } else {
                    *(u16*)(o + 0xA) = *(u16*)(p + 0xA) +
                                       D_801016A0_ovl04[*(s8*)(o + 0x45)][0];
                }
                *(u16*)(o + 0xE) = *(u16*)(*(u8**)(o + 0x50) + 0xE) -
                                   D_801016A0_ovl04[*(s8*)(o + 0x45)][1];
            } else {
                if (f.b == 0) {
                    *(u16*)(o + 0xA) = *(u16*)(p + 0xA) -
                                       D_801016B8_ovl04[*(s8*)(o + 0x45)][0];
                } else {
                    *(u16*)(o + 0xA) = *(u16*)(p + 0xA) +
                                       D_801016B8_ovl04[*(s8*)(o + 0x45)][0];
                }
                *(u16*)(o + 0xE) = *(u16*)(*(u8**)(o + 0x50) + 0xE) +
                                   D_801016B8_ovl04[*(s8*)(o + 0x45)][1];
            }
            func_8002DF54(o);
            if (*(s8*)(o + 0x45) == 5) {
                q = (u8*)D_1F800064;
                q[0x54] ^= 1;
            }
            func_80017248(o);
        }
        func_8002D89C(o);
    }
}
