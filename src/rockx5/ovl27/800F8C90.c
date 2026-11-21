#include "types.h"
#include "mmx5/system.h"
#include "mmx5/sound.h"
#include "addr.h"
#include "mmx5/object.h"

extern u8 D_8009A1F8[];
extern u8 D_800FD6EC_ovl27[];
extern u8 D_800FD6E8_ovl27[];

void func_800F8C90_ovl27(u8* arg0) {
    s8 state;
    u8* p;

    if ((s8)arg0[0x45] == 2) {
        play_sound(2, 0x6B, arg0);
    }
    state = arg0[0x45];
    if (state == 1) {
        *(s32*)(arg0 + 0x68) = 0;
        *(void**)(arg0 + 0x50) = D_800FD6EC_ovl27;
        *(void**)(arg0 + 0x54) = D_800FD6E8_ovl27;
        if (random_byte() & 1) {
            u8* d = D_8009A1F8;
            *(s16*)(D_1F80004C.bytes + 0x86) = *(u16*)(d + 0xA) + 0x50;
            D_1F80004C.bytes[0x8B] = 0;
        } else {
            u8* d = D_8009A1F8;
            *(s16*)(D_1F80004C.bytes + 0x86) = *(u16*)(d + 0xA) + 0xF0;
            D_1F80004C.bytes[0x8B] = state;
        }
        p = D_1F80004C.bytes;
        if ((*(u8**)(p + 0x80))[0x8A] == 2) {
            u8* d = D_8009A1F8;
            *(s16*)(p + 0x86) = *(u16*)(d + 0xA) + 0xA0;
            if (random_byte() & 1) {
                D_1F80004C.bytes[0x8B] = 0;
            } else {
                D_1F80004C.bytes[0x8B] = 1;
            }
        }
        arg0[6]++;
    }
}

extern s32 ratan2(s32, s32);
extern s32 rcos(s32);
extern s32 rsin(s32);
extern u8 D_8009A1F8[];

void func_800F8DD0_ovl27(u8* obj) {
    u8* p;
    u8* q;
    s32 ang;
    s32 e;
    s32 dx;
    s32 y;
    s32 x;

    p = D_8009A1F8;
    e = *(s16*)(obj + 0xE) - 0x78;
    dx = *(s16*)(D_1F80004C.bytes + 0x86) - *(s16*)(obj + 0xA);
    ang = ratan2(e - *(s16*)(p + 0xE), dx);
    *(s32*)(obj + 0x28) = 0;
    *(s32*)(obj + 0x2C) = 0;
    *(s32*)(obj + 0x20) = rcos(ang) * 16;
    *(s32*)(obj + 0x24) = rsin(ang) * 16;
    if (*(s32*)(obj + 0x20) != 0) {
        *(s32*)(obj + 0x20) = *(s32*)(obj + 0x20) * 3 / 2;
    } else {
        *(s32*)(obj + 0x20) = 0;
    }
    if (*(s32*)(obj + 0x24) != 0) {
        *(s32*)(obj + 0x24) = *(s32*)(obj + 0x24) * 3 / 2;
    } else {
        *(s32*)(obj + 0x24) = 0;
    }
    move_object(obj);
    x = *(s16*)(D_1F80004C.bytes + 0x86);
    if (*(s16*)(obj + 0xA) >= x - 3 && *(s16*)(obj + 0xA) <= x + 3) {
        q = D_8009A1F8;
        y = *(s16*)(q + 0xE);
        if (*(s16*)(obj + 0xE) >= y + 0x75 && *(s16*)(obj + 0xE) <= y + 0x7B) {
            *(s16*)(obj + 0x7C) = 0x28;
            obj[6]++;
        }
    }
}
