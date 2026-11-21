#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "mmx5/sound.h"
#include "addr.h"

void func_800F986C_ovl06(u8* obj) {
    animate_object(obj);
    if (*(s8*)(obj + 0x45) == 1) {
        set_animation(obj, 2);
        obj[6]++;
    }
}

extern s32 func_8002DC14(void);
extern u8 D_800D1C00[];

void func_800F98B8_ovl06(u8* obj) {
    u8* p;

    animate_object(obj);
    p = D_800D1C00;
    if (*(s8*)(p + 0xC) != 12) {
        if (func_8002DC14() == 0) {
            func_8002385C(0x69, 0xFF, p[0x2E]);
        } else if (func_8002DC14() == 1) {
            func_8002385C(0x2D, 0xFF, p[0x2E]);
        } else {
            func_8002385C(0x5F, 0xFF, p[0x2E]);
        }
        D_800D1C00[0x2E] = 1;
    }
    obj[6]++;
    animate_object(obj);
}

extern u8 D_80091C44;
extern void func_80044DD0(s32 a0);

void func_800F9970_ovl06(u8* obj) {
    animate_object(obj);
    if (D_80091C44 == 0) {
        func_80044DD0(0);
        *(s16*)(obj + 0x7C) = 2;
        obj[6]++;
    }
}

extern s32 func_80044DE0();
extern u8 D_8009A1F8[];

void func_800F99C4_ovl06(u8* o) {
    u8* p;

    animate_object(o);
    if (func_80044DE0() != 0) {
        return;
    }
    if (--*(s16*)(o + 0x7C) == 0) {
        play_sound(0, 0xE, 0);
        *(s16*)(o + 0x7C) = 2;
    }
    p = D_8009A1F8;
    *(s16*)(p + 0x26) = *(s16*)(o + 0x8C);
    if ((s8)++o[0x5C] == D_1F80004C.bytes[0x86]) {
        p[0x48] = o[0x90];
        *(s32*)(o + 0x8C) = 0;
        *(s32*)(o + 0x90) = 0;
        D_1F80004C.bytes[0x85] = 1;
        ((s32(*)())func_8003D2C4)();
        o[5] = 3;
        o[6] = 0;
    }
}
