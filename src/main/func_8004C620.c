#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "addr.h"

#define FX(p, type, off) (*(type*)((u8*)(p) + (off)))

extern void func_80017348(u8* a0, s32 a1, s32 a2);
extern u8 D_8007B3D8[];

void func_8004C620(u8* arg0) {
    u8* s;
    u8* t;
    s32 n;

    if (FX(arg0, s8, 0x4) == 0) {
        FX(arg0, u8, 0x3) = 1;
        s = D_1F80001C.bytes;
        FX(arg0, u8*, 0x3C) = s + FX(s, s32, 0x24);
        t = D_1F800014;
        n = FX(t, s32, 0x10);
        FX(arg0, u8*, 0x30) = D_8007B3D8;
        FX(arg0, s16, 0x40) = 0x540;
        FX(arg0, s16, 0x42) = 0x7804;
        FX(arg0, u8, 0x16) = 2;
        FX(arg0, u8*, 0x38) = t + n;
        set_animation(arg0, 2);
        FX(arg0, u8, 0x48) = 0xFF;
        FX(arg0, u8, 0x49) = 0;
        func_80017348(arg0, 0x140, 0x40);
        FX(arg0, u8, 0x4)++;
    } else {
        FX(arg0, u8, 0x4)++;
        if ((FX(arg0, u8, 0x4) & 7) == 0) {
            func_8004FD90(arg0, 1, 0x10, 0x10);
        }
        animate_object(arg0);
        if (FX(arg0, s8, 0x4) >= 0x29) {
            clear_object_slot(arg0);
            return;
        }
    }
    func_8002D9EC(arg0, 0x40, 0x40);
}
