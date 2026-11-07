#include "types.h"

extern void func_8002C1C8(void);

extern Spawn800FB000* func_8002D53C(void);
extern s32 func_80016490(s32, s32, void*);
extern u8 D_80093E66;
extern u8 D_8009A42C;
extern u8 D_800D50DC;
extern u8 D_8009A1F8[];

void func_800FB000_ovl49(u8* arg0) {
    u8* p;
    Spawn800FB000* o;
    s32 t;

    t = *(u16*)(arg0 + 4) + 1;
    *(u16*)(arg0 + 4) = t;
    if ((s16)t >= 0x1F) {
        D_80093E66 = 0;
        D_8009A42C = 0;
        D_800D50DC = 0;
        func_8002C1C8();
        p = D_8009A1F8;
        p[3] = 0;
        *(s32*)(p + 0x5C) = 0x02000000;
        *(s32*)(p + 0x60) = 0x02000000;
        p[0xA0] = 1;
        p[0x57] = 1;
        p[0xAB] = 0;
        *(u16*)(arg0 + 4) = 0;
        o = func_8002D53C();
        if (o != 0) {
            o->unk1 = 9;
            o->unk36 = 0x11;
            o->unk0 = 1;
            o->unk34 = 0x7FFF;
            o->unk2 = 2;
            o->unk38 = 0x1E;
        }
        func_80016490(2, 0x4D, 0);
        *(u16*)(arg0 + 4) = 1;
        arg0[1]++;
    }
}
