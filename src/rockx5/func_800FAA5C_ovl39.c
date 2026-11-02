#include "types.h"

extern u8* func_8002D0E4(void);
extern u8* func_8002D1A4();
extern void func_800171E8(u8* obj, s32 state);
extern u8 D_8009A0B4;
extern u8 D_800FEC18_ovl39[];
extern u8 D_800FEC14_ovl39[];
extern u8 D_800750C0[];

void func_800FAA5C_ovl39(u8* obj) {
    u8* p;
    u8* q;
    u8 id;

    obj[0x16] = 3;
    id = D_8009A0B4;
    obj[0x60] = 8;
    obj[0x5C] = 0x20;
    *(u8**)(obj + 0x54) = D_800FEC18_ovl39;
    *(s32*)(obj + 0x50) = 0;
    *(u8**)(obj + 0x68) = D_800FEC14_ovl39;
    *(u8**)(obj + 0x58) = D_800750C0;
    obj[0x75] = 1;
    obj[0x76] = 0;
    obj[0x66] = 0;
    obj[0x4] = 1;
    obj[0x5] = 1;
    obj[0x6] = 0;
    obj[0x87] = 0;
    obj[0x88] = 0;
    obj[0x89] = 0;
    obj[0x8A] = 0;
    obj[0x14] = id;
    p = func_8002D0E4();
    if (p != 0) {
        p[0] = 0x61;
        p[1] = 0x15;
        p[2] = 1;
        *(u16*)(p + 0x40) = *(u16*)(obj + 0x40);
        *(s32*)(p + 0x30) = *(s32*)(obj + 0x30);
        *(s32*)(p + 0x3C) = *(s32*)(obj + 0x3C);
        *(u16*)(p + 0x42) = *(u16*)(obj + 0x42) & 0x7FFF;
        *(u8**)(p + 0x50) = obj;
    }
    q = func_8002D1A4();
    if (q != 0) {
        q[0] = 0x61;
        q[1] = 0x28;
        q[2] = 0xD;
        *(u16*)(q + 0x40) = *(u16*)(obj + 0x40);
        *(s32*)(q + 0x30) = *(s32*)(obj + 0x30);
        *(s32*)(q + 0x3C) = *(s32*)(obj + 0x3C);
        *(u16*)(q + 0x42) = *(u16*)(obj + 0x42) & 0x7FFF;
        q[0x15] = obj[0x15];
        if (((s8*)obj)[2] == 0) {
            *(u16*)(q + 0xA) = *(u16*)(obj + 0xA) - 0x38;
        } else {
            *(u16*)(q + 0xA) = *(u16*)(obj + 0xA) + 0x38;
        }
        *(u16*)(q + 0xE) = *(u16*)(obj + 0xE);
        *(u8**)(q + 0x7C) = obj;
    }
    if (((s8*)obj)[2] == 0) {
        *(s16*)(obj + 0x80) = 0;
    } else {
        *(s16*)(obj + 0x80) = 0x800;
    }
    func_800171E8(obj, 0);
}
