#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "addr.h"

extern s32 ratan2(s32, s32);
extern s32 rcos(s32);
extern s32 rsin(s32);

void func_800F90B8_ovl27(u8* obj) {
    u8* p;
    s32 px;
    s32 pz;
    s32 ang;

    if (--*(s16*)(obj + 0x7C) == -1) {
        if (*(u16*)(obj + 0x7E) & 1) {
            set_animation(obj, 0xA);
            D_1F80004C.bytes[0x8A] = 0;
            *(u16*)(obj + 0x7C) = 0x3C;
        } else {
            set_animation(obj, 0xC);
            D_1F80004C.bytes[0x8A] = 1;
            *(u16*)(obj + 0x7C) = 0x19;
        }
        if (--*(s16*)(obj + 0x7E) != 0) {
            p = g_Player;
            px = *(s16*)(p + 0xA);
            pz = *(s16*)(p + 0xE);
            ang = ratan2(*(s16*)(obj + 0xE) - pz, px - *(s16*)(obj + 0xA));
            *(s32*)(obj + 0x28) = 0;
            *(s32*)(obj + 0x2C) = 0;
            *(s32*)(obj + 0x20) = rcos(ang) * 16;
            *(s32*)(obj + 0x24) = rsin(ang) * 16;
            if (*(s32*)(obj + 0x20) != 0) {
                *(s32*)(obj + 0x20) = *(s32*)(obj + 0x20) * 9 / 2;
            } else {
                *(s32*)(obj + 0x20) = 0;
            }
            if (*(s32*)(obj + 0x24) != 0) {
                *(s32*)(obj + 0x24) = *(s32*)(obj + 0x24) * 9 / 2;
            } else {
                *(s32*)(obj + 0x24) = 0;
            }
        } else {
            set_animation(obj, 0xA);
            D_1F80004C.bytes[0x8A] = 0;
            obj[6]++;
            return;
        }
    }
    if (*(u16*)(obj + 0x7E) & 1) {
        move_object(obj);
    }
}

extern s32 ratan2(s32, s32);
extern s32 rcos(s32);
extern s32 rsin(s32);
extern s16 D_800FDA58_ovl27[][2];

void func_800F9264_ovl27(u8* obj) {
    s32 a;
    s32 v;
    s32 x;
    s32 y;

    x = D_800FDA58_ovl27[D_1F80004C.bytes[0x89]][0];
    y = D_800FDA58_ovl27[D_1F80004C.bytes[0x89]][1];
    a = ratan2(*(s16*)(obj + 0xE) - y, x - *(s16*)(obj + 0xA));
    *(s32*)(obj + 0x28) = 0;
    *(s32*)(obj + 0x2C) = 0;
    *(s32*)(obj + 0x20) = rcos(a) << 4;
    *(s32*)(obj + 0x24) = rsin(a) << 4;
    v = *(s32*)(obj + 0x20);
    if (v != 0) {
        *(s32*)(obj + 0x20) = v * 3 / 2;
    } else {
        *(s32*)(obj + 0x20) = 0;
    }
    v = *(s32*)(obj + 0x24);
    if (v != 0) {
        *(s32*)(obj + 0x24) = v * 3 / 2;
    } else {
        *(s32*)(obj + 0x24) = 0;
    }
    move_object(obj);
    if (D_800FDA58_ovl27[D_1F80004C.bytes[0x89]][0] - 3 <= *(s16*)(obj + 0xA) &&
        D_800FDA58_ovl27[D_1F80004C.bytes[0x89]][0] + 3 >= *(s16*)(obj + 0xA) &&
        D_800FDA58_ovl27[D_1F80004C.bytes[0x89]][1] - 3 <= *(s16*)(obj + 0xE) &&
        D_800FDA58_ovl27[D_1F80004C.bytes[0x89]][1] + 3 >= *(s16*)(obj + 0xE)) {
        *(s16*)(obj + 0xA) = D_800FDA58_ovl27[D_1F80004C.bytes[0x89]][0];
        *(s16*)(obj + 0xE) = D_800FDA58_ovl27[D_1F80004C.bytes[0x89]][1];
        set_animation(obj, 0xB);
        obj[6]++;
    }
}
