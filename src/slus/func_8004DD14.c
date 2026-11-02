#include "types.h"
#include "addr.h"

extern void func_800171E8(u8* obj, s32 state);
extern s8 D_800D1C44;
extern u8 D_8007B4FC[];
extern u8 D_8007B524[];
extern u16 D_8007B52C[];
extern u16 D_8007B538[];
extern u8 D_8007B544[];
extern u16 D_800E9568[];
extern u8 D_800C9310;

void func_8004DD14(u8* obj) {
    s8 kind;
    u8 t;
    u16* dst;
    u16* src;
    u32 i;

    if (D_800D1C44 == 0) {
        *(u8**)(obj + 0x3C) = D_1F80001C.bytes + D_1F80001C.s32s[9];
    } else {
        *(u8**)(obj + 0x3C) = D_1F80001C.bytes + D_1F80001C.s32s[4];
    }
    if (*(s8*)(obj + 2) == 2) {
        *(s32*)(obj + 0x3C) = *(s32*)(D_801F3000 + 0x14) + (s32)D_801F3000;
    }
    *(s16*)(obj + 0x40) = 0x1E00;
    *(u8**)(obj + 0x30) = D_8007B4FC;
    kind = *(s8*)(obj + 2);
    *(u8*)(obj + 4) = 1;
    *(s8*)(obj + 0x14) = -1;
    t = D_8007B524[kind];
    *(s16*)(obj + 0x42) = (t & 0xF) | (((t >> 4) + 0x1E0) << 6);
    *(u16*)(obj + 0xA) = D_8007B52C[kind];
    *(s16*)(obj + 0xE) = D_8007B538[kind];
    *(u8*)(obj + 0x16) = D_8007B544[kind];
    *(u8*)(obj + 0x15) = 0;
    *(s32*)(obj + 0x20) = 0;
    *(s32*)(obj + 0x28) = 0;
    *(s32*)(obj + 0x24) = 0;
    *(s32*)(obj + 0x2C) = 0;
    *(s16*)(obj + 0x54) = 0;
    *(s16*)(obj + 0x56) = 0;
    *(s16*)(obj + 0x58) = 0;
    *(s16*)(obj + 0x5A) = 0;
    *(s16*)(obj + 0x5C) = 0;
    if (kind < 2) {
        if (kind != 0) {
            dst = D_800E9568;
            src = (u16*)(D_1F800028 + 0x200);
            for (i = 0; i < 16; i++) {
                *dst++ = *src;
                if (i != 0) {
                    *src = 0x8000;
                } else {
                    *src = 0;
                }
                src++;
            }
            D_800C9310 |= 1;
        }
        func_800171E8(obj, 0);
    } else {
        func_800171E8(obj, kind - 1);
    }
}
