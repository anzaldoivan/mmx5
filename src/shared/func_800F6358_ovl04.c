#include "types.h"
#include "mmx5/object.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"
#include "mmx5/ovl04.h"
#include "mmx5/system.h"

extern s32 func_8002D800(u8* a0);

void func_800F6358_ovl04(u8* o) {
    if (func_8002D800(o) == 0) {
        if (((s8*)o)[2] >= 6) {
            if (*(s32*)(o + 0x24) > 0x20000) {
                *(s32*)(o + 0x24) = 0x20000;
            }
            if (((s8*)*(u8**)(o + 0x50))[0x90] > 0) {
                *(s32*)(o + 0x20) = 0;
            } else {
                *(s32*)(o + 0x20) = 0xFFFF0000;
            }
            if (((s8*)o)[2] == 8) {
                *(s32*)(o + 0x20) = 0x10000;
            }
        }
        ((s32(*)())apply_object_motion)(o);
        if (((s8*)o)[2] == 0) {
            o[3] ^= 1;
        } else {
            if ((u8)(((s8*)o)[2] - 4) < 2) {
                *(s32*)(o + 0x20) = *(s32*)(*(u8**)(o + 0x50) + 0x98);
            }
            animate_object(o);
            if (o[0x47] == 0x34 || ((s8*)o)[0x45] == 0x10) {
                clear_object_slot(o);
                return;
            }
        }
        if (((s8*)o)[3] != 0) {
            func_8002D9EC(o, 0x30, 0x40);
        }
    } else {
        clear_object_slot(o);
    }
}

void func_800F5E5C_ovl04(Obj649C* o);

void func_800F649C_ovl04(Obj649C* o) {
    if (o->unk4 == 0) {
        func_800F5E5C_ovl04(o);
    } else if (o->unk7 == 0) {
        func_800F6358_ovl04(o);
    } else {
        o->unk7--;
    }
}

extern s32 D_80101C9C_ovl04[];
extern s32 D_80101CBC_ovl04[];

void func_800F64F8_ovl04(u8 n, u8* arg1, u8* src, s8 arg3) {
    u8* p;

    while (n != 0) {
        p = func_8002D27C();
        if (p != 0) {
            p[0] = 0x41;
            p[1] = 0x1A;
            p[0x15] = random_byte() & 0x40;
            p[2] = arg3;
            *(s32*)(p + 8) =
                *(s32*)(src + 8) + D_80101C9C_ovl04[random_byte() & 7];
            *(s32*)(p + 0xC) =
                *(s32*)(src + 0xC) + D_80101CBC_ovl04[random_byte() & 7];
            p[0x54] = arg1[n];
            *(s32*)(p + 0x30) = *(s32*)(src + 0x30);
            *(s32*)(p + 0x3C) = *(s32*)(src + 0x3C);
            *(u16*)(p + 0x40) = *(u16*)(src + 0x40);
            *(u16*)(p + 0x42) = *(u16*)(src + 0x42);
            p[0x14] = g_Player[0x14];
        }
        n--;
    }
}
