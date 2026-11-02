#include "types.h"

extern s32 func_80031DD0(u8* a0);
extern void func_8004FD90(u8*, s32, s32, s32);
extern s32 func_800317B8(u8* a0);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern s32 func_8004FD24(u8* a0);
extern u8 D_800D1C00[];

void func_800FA09C_ovl04(u8* obj) {
    u8* parent;
    s32 r;

    parent = *(u8**)(obj + 0x80);
    r = func_80031DD0(obj);
    if (r < 0) {
        D_800D1C00[0x2A] |= obj[0x92];
        func_8004FD90(obj, 1, 0x1F, 0x1F);
        func_8004FD90(obj, 1, 0x1F, 0x1F);
        func_8004FD90(obj, 1, 0x1F, 0x1F);
        func_8004FD90(obj, 1, 0x1F, 0x1F);
        func_8004FD24(obj);
        obj[5]++;
        return;
    }
    if (r > 0) {
        D_800D1C00[0x27] |= 1;
    } else if (*(u16*)(parent + 0x42) & 0x8000) {
        *(u16*)(obj + 0x42) |= 0x8000;
    }
    func_800317B8(obj);
    func_8002D9EC(obj, 0x40, 0x20);
    if (D_800D1C00[0x2A] & 4) {
        D_800D1C00[0x2A] |= obj[0x92];
        func_8004FD24(obj);
        obj[5]++;
    }
}
