#include "types.h"

extern u8* func_8002D144(void);
extern s32 func_8004FD24(u8* a0);
extern void func_8004D4F4(s32 a0, void* a1, u8* a2);
extern void func_800171E8(u8* obj, s32 state);
extern u8* func_8002D0E4(void);
extern void func_8001296C(s32);
extern u8 D_800F95F0_ovl11[];

void func_800EF308_ovl11(u8* obj) {
    u8* q;
    u8* p;

    q = func_8002D144();
    if (q != 0) {
        q[0] = 1;
        q[1] = 5;
    }
    func_8004FD24(obj);
    func_8004D4F4(2, D_800F95F0_ovl11, obj);
    func_800171E8(obj, 3);
    obj[4] = 2;
    *(s16*)(obj + 0x82) = 1;
    p = func_8002D0E4();
    if (p != 0) {
        p[0] = 0x41;
        p[1] = 8;
        p[2] = 0;
        p[0x15] = obj[0x15];
        *(u16*)(p + 0x40) = *(u16*)(obj + 0x40);
        *(u16*)(p + 0x42) = *(u16*)(obj + 0x42) & 0x7FFF;
        *(s32*)(p + 0x30) = *(s32*)(obj + 0x30);
        *(s32*)(p + 0x3C) = *(s32*)(obj + 0x3C);
        p[0x14] = obj[0x14];
        *(s32*)(p + 0x8) = *(s32*)(obj + 0x8);
        *(s32*)(p + 0xC) = *(s32*)(obj + 0xC);
    }
    func_8001296C(9);
}
