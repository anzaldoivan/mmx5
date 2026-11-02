#include "types.h"

extern void func_800171E8(u8* obj, s32 state);
extern void func_80016490(s32, s32, void*);
extern u8* func_8002D0E4(void);
extern void func_80017248(u8* obj);
extern u8 D_8009A0A0[];
extern u8 D_800FDE84_ovl06[];
extern u8 D_800FDE8C_ovl06[];

void func_800EF2FC_ovl06(u8* obj) {
    u8* p;

    if (((s8*)obj)[6] == 0) {
        obj[6] = 1;
        obj[0x94] = 0;
        *(s16*)(obj + 0xA6) = 0;
        *(u8**)(obj + 0x68) = D_800FDE84_ovl06;
        func_800171E8(obj, 0x12);
        if (obj[0x8D] == 0) {
            D_8009A0A0[0xD8] = 0x39;
            D_8009A0A0[6] = 0;
        }
        func_80016490(5, 0xF, 0);
    }
    if (((s8*)obj)[0x46] == 0) {
        if (obj[0x8C] == 0) {
            obj[0x61] = 0;
        }
        obj[5] = 1;
        obj[0x94] = 0;
        *(s16*)(obj + 0xA6) = 0;
        obj[6] = 0;
        *(u8**)(obj + 0x54) = D_800FDE8C_ovl06;
        return;
    }
    if (obj[0x45] & 1) {
        p = func_8002D0E4();
        if (p != 0) {
            p[0] = obj[0];
            p[1] = 0xC;
            p[2] = 7;
            *(s32*)(p + 8) = *(s32*)(obj + 8);
            *(s32*)(p + 0xC) = *(s32*)(obj + 0xC);
            *(s32*)(p + 0x30) = *(s32*)(obj + 0x30);
            *(u16*)(p + 0x40) = *(u16*)(obj + 0x40);
            *(s32*)(p + 0x3C) = *(s32*)(obj + 0x3C);
            *(u16*)(p + 0x42) = *(u16*)(obj + 0x42) & 0x7FFF;
            p[0x16] = obj[0x16];
            p[0x15] = obj[0x15];
            *(u8**)(p + 0x50) = obj;
        }
        obj[0x45] = 0;
        return;
    }
    func_80017248(obj);
}
