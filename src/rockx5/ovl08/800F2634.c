#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/title.h"

extern void func_8004D4F4(s32 a0, void* a1, u8* a2);
extern u8 D_800F3F2C_ovl08[];

void func_800F2634_ovl08(u8* arg0) {
    u32 t;

    t = *(u32*)(arg0 + 0x7C);
    t++;
    *(u32*)(arg0 + 0x7C) = t;
    arg0[3] = arg0[0x7C] & 4;
    if (t >= 0x1F) {
        *(u16*)(arg0 + 0xA) += 8;
        *(u16*)(arg0 + 0xE) += 8;
        func_8004D4F4(5, D_800F3F2C_ovl08, arg0);
        t = 3;
        arg0[4] = t;
        arg0[3] = 0;
        *(u16*)(arg0 + 0xA) -= 8;
        *(u16*)(arg0 + 0xE) -= 8;
    }
}

extern s8 D_800D1C0F;

void func_800F26C8_ovl08(u8* arg0) {
    if (D_8009A0AA >= 0xEB1) {
        D_800D1C0F = 0x40;
        func_8002D720(arg0);
    }
}

extern void func_800F28E8_ovl08(u8* a0);

void func_800F2700_ovl08(u8* a0) {
    s8 r;

    animate_object(a0);
    r = func_80031DD0(a0);
    if (r == 5 || r == 14 || r == 36 || r < 0) {
        a0[3] = 1;
        *(u16*)(a0 + 0x42) &= 0x7FFF;
        func_800F28E8_ovl08(a0);
        func_800F28E8_ovl08(a0);
        func_800F28E8_ovl08(a0);
        func_800F28E8_ovl08(a0);
        *(s16*)(a0 + 0x7C) = 0x78;
        *(s16*)(a0 + 0x7E) = 8;
        a0[4] = 5;
    } else if (is_off_screen(a0, 0xA0, 0x60) == 1) {
        a0[4] = 7;
    }
}

extern void func_800F28E8_ovl08(u8* a0);
extern void func_8004D4F4(s32 a0, void* a1, u8* a2);
extern u8 D_8009A244;
extern u8 D_800F3F34_ovl08[];
extern u8 D_800F3F44_ovl08[];

void func_800F27C0_ovl08(u8* obj) {
    obj[3] = 0;
    if (!(*(u16*)(obj + 0x7C) & 3)) {
        obj[3] = 1;
    }
    if (--*(s16*)(obj + 0x7E) == 0) {
        func_800F28E8_ovl08(obj);
        *(s16*)(obj + 0x7E) = 8;
    }
    if (--*(s16*)(obj + 0x7C) == 0) {
        obj[3] = 0;
        func_800F28E8_ovl08(obj);
        func_800F28E8_ovl08(obj);
        func_800F28E8_ovl08(obj);
        func_800F28E8_ovl08(obj);
        *(s32*)(obj + 0x20) = 0;
        func_8004D4F4(3, D_800F3F34_ovl08, obj);
        func_80028B18(0, 0x660, 0x110, D_800F3F44_ovl08);
        D_8009A244 = 1;
        obj[4] = 6;
    }
}

#define D_800EEBA0_ovl00 func_800F28A8_ovl08
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00

extern void func_8002D7A0();
#define D_800EEBA0_ovl00 func_800F28C8_ovl08
#define func_8002D720 func_8002D7A0
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720
