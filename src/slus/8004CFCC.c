#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "addr.h"

extern u8 D_80077534[];

void func_8004CFCC(u8* obj) {
    s8 kind = obj[2];
    u8 raw = obj[2];

    if (kind < 0) {
        *(u8**)(obj + 0x30) = D_80077534;
        obj[0x16] = 0;
        *(s8*)(obj + 0x14) = -1;
        obj[0x15] = 0;
        if (kind == -1) {
            u8* p = D_8009A420;
            *(s16*)(obj + 0x40) = 0x1D00;
            *(s32*)(obj + 0x3C) = D_801F300C + (s32)D_801F3000;
            *(s16*)(obj + 0x42) = 0x780A;
            *(s16*)(obj + 0xE) = (*(u8**)(obj + 0x50))[p[7] * 2] + 8;
            obj[0x54] = p[7];
            set_animation(obj, 0);
        } else {
            *(s16*)(obj + 0x40) = 0x1E00;
            *(s32*)(obj + 0x3C) = *(s32*)(D_801F3000 + 0x14) + (s32)D_801F3000;
            *(s16*)(obj + 0x42) = 0x7848;
            *(s16*)(obj + 0xA) = 0xA0;
            *(s16*)(obj + 0xE) = 0xD8;
            obj[0x47] = 1;
        }
        obj[4] = 1;
    } else {
        *(s16*)(obj + 0x40) = 0x1F00;
        *(s32*)(obj + 0x3C) = *(s32*)(D_801F3000 + 0x10) + (s32)D_801F3000;
        *(s8*)(obj + 0x14) = -1;
        obj[0x15] = 0;
        *(s16*)(obj + 0xA) = 0xA0;
        obj[0x16] = 0;
        if (kind == 0x20) {
            *(s16*)(obj + 0x42) = 0x7802;
            obj[4] = 1;
        } else {
            *(s16*)(obj + 0x42) = 0x7800;
            if (kind < 7) {
                *(s16*)(obj + 0xA) = 0x38;
                obj[4] = 3;
            } else if (kind < 0x10) {
                *(s16*)(obj + 0xA) = 0x110;
                obj[2] = raw - 7;
                obj[4] = 4;
            } else {
                obj[4] = 2;
            }
        }
    }
    func_8002D89C(obj);
}

void func_8004D174(u8* obj) {
    u8* p;

    if (*(s8*)(obj + 2) == -1) {
        p = D_8009A420;
        if (obj[0x54] != p[7]) {
            *(s16*)(obj + 0xE) = (*(u8**)(obj + 0x50))[p[7] * 2] + 8;
            obj[0x54] = p[7];
        }
        animate_object(obj);
    }
    func_8002D89C(obj);
}

extern u8 D_8009A427;

void func_8004D1F4(u8* a0) {
    if (*(s8*)(a0 + 7) == D_8009A427) {
        *(s16*)(a0 + 0x42) = 0x7803;
    } else {
        *(s16*)(a0 + 0x42) = 0x7800;
    }
    func_8002D89C(a0);
}

extern u16 D_8006FAE4[];
extern u16 D_80073020[];
extern u16 D_80073030[];
extern u8 D_80077538[];

void func_8004D238(u8* obj) {
    u8 i;
    s32 idx;
    u16 v;

    for (i = 0; i < 16; i++) {
        if ((1 << i) == D_80073020[((s8*)obj)[2]]) {
            idx = i;
            break;
        }
    }
    v = D_8006FAE4[idx];
    for (i = 0; i < 8; i++) {
        if (v == D_80073030[i]) {
            obj[0x47] = D_80077538[i];
            break;
        }
    }
    func_8002D89C(obj);
}

extern u8 D_8006FADB;
extern u8 D_8007301C[];

void func_8004D344(u8* obj) {
    if (D_8006FADB & D_8007301C[((s8*)obj)[2]]) {
        obj[0x47] = 11;
    } else {
        obj[0x47] = 12;
    }
    func_8002D89C(obj);
}
