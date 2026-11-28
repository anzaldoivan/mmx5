#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

extern void func_8003D430(s32, s32, s32, void*);
extern s32 D_800771C8[];

void func_8004ACCC(u8* o) {
    s32 x;
    s16 n;
    s32 t;

    animate_object(o);
    move_object(o);
    x = *(s32*)(o + 0x20) + *(s32*)(o + 0x28);
    *(s32*)(o + 0x20) = x;
    *(s32*)(o + 0x24) = *(s32*)(o + 0x24) + *(s32*)(o + 0x2C);
    if (x > 0x60000) {
        *(s32*)(o + 0x20) = 0x60000;
    }
    if (*(s32*)(o + 0x20) < -0x60000) {
        *(s32*)(o + 0x20) = -0x60000;
    }
    if (*(s32*)(o + 0x24) > 0x60000) {
        *(s32*)(o + 0x24) = 0x60000;
    }
    func_8002D9EC(o, 0x40, 0xC0);
    if (*(s8*)(o + 3) == 0) {
        o[4] = 3;
        *(s32*)(o + 0x50) = 0;
        *(s32*)(o + 0x68) = 0;
        return;
    }
    t = *(u16*)(o + 0x8C) + 1;
    n = t;
    *(u16*)(o + 0x8C) = t;
    if (n < 0x47) {
        if ((s16)(n % 10) == 0) {
            func_8003D430(1, *(s8*)(o + 1), (s8)(n / 10), o);
            *(s32**)(o + 0x50) = &D_800771C8[(s16)(*(s16*)(o + 0x8C) / 10)];
        }
        if (*(s16*)(o + 0x8C) == 0x46) {
            *(s32*)(o + 0x2C) = 0;
            *(s32*)(o + 0x24) = 0;
        }
    }
}
