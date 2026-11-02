#include "types.h"
#include "addr.h"

extern s32 func_8002B5B4(s32);
extern void func_800171E8(u8* obj, s32 state);
extern void func_800F83B8_ovl01(u8* obj);
extern u32* D_80098118;
extern u8 D_80074EE0[];
extern u8 D_8009A0B4;
extern u8 D_800FD430_ovl01;
extern u8 D_800FD434_ovl01;
extern u8 D_800FD4DC_ovl01;

void func_800F7CA0_ovl01(u8* p) {
    s32 r0;
    s32 r1;
    u8 t;

    p[0x5C] = 0;
    p[0x60] = 0x7F;
    *(u8**)(p + 0x68) = &D_800FD430_ovl01;
    if (((s8*)p)[2] & 0xF0) {
        *(u16*)(p + 0x40) = D_80098118[func_8002B5B4(((s8*)p)[1])] >> 7;
        r0 = func_8002B5B4(((s8*)p)[1]);
        r1 = func_8002B5B4(((s8*)p)[1]);
        *(u16*)(p + 0x42) =
            ((r0 * 4 + 0x18) % 16) | (((r1 + 6) / 4 + 0x1E0) << 6);
        *(s32*)(p + 0x3C) =
            (s32)D_1F800020.s32s + D_1F800020.s32s[func_8002B5B4(((s8*)p)[1])];
        if ((((s8*)p)[2] & 0xF0) == 0x20) {
            *(u8**)(p + 0x68) = &D_800FD434_ovl01;
        }
    }
    p[0x61] = 0;
    *(u8**)(p + 0x58) = D_80074EE0;
    p[0x14] = D_8009A0B4;
    *(s32*)(p + 0x20) = 0;
    *(s32*)(p + 0x24) = 0;
    *(s32*)(p + 0x28) = 0;
    *(s32*)(p + 0x2C) = 0;
    p[0x67] = 0;
    *(s32*)(p + 0x18) = *(s32*)(p + 0x8);
    *(s32*)(p + 0x1C) = *(s32*)(p + 0xC);
    *(u8**)(p + 0x30) = &D_800FD4DC_ovl01;
    p[0x16] = 1;
    func_800171E8(p, 0);
    D_1F80004C.s8s[0x84] = -8;
    D_1F80004C.s8s[0x85] = -8;
    D_1F80004C.bytes[0x86] = 0x10;
    D_1F80004C.bytes[0x87] = 0x10;
    *(u8**)(p + 0x54) = D_1F80004C.bytes + 0x84;
    *(u8**)(p + 0x50) = D_1F80004C.bytes + 0x84;
    t = p[2] & 0xF;
    if (t == 0) {
        p[0x15] = 0;
    } else if (t == 1) {
        p[0x15] = 0x40;
    }
    func_800F83B8_ovl01(p);
    p[5] = 2;
    p[6] = 0;
    p[0x75] = 1;
    p[0x76] = 0;
    p[4]++;
}
