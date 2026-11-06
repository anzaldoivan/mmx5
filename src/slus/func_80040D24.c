#include "types.h"

extern s32 func_80040E98(u8* obj);
extern void func_8003AA4C(u8* arg0);
extern u8* func_8003D3A8(s32, s32, s32, u8*);
extern void func_8003CEDC(u8* arg0, s32 arg1);
extern s32 func_80016490(s32, s32, void*);
extern s8 D_800D1C1C;

void func_80040D24(u8* obj) {
    if (func_80040E98(obj) != 0 && (obj[0x45] & 0x40)) {
        if (*(s8*)(obj + 0xD3) == 0) {
            obj[0x7A] = 0;
        }
        obj[0xF3] = 0;
        D_800D1C1C = 0;
        func_8003AA4C(obj);
        return;
    }
    if (obj[0x45] & 0x20) {
        obj[0x45] = 0;
        func_8003D3A8(1, 0x16, 0, 0);
        func_8003CEDC(obj, 0x49);
        func_80016490(1, 5, obj);
        func_80016490(0, 0x20, obj);
        if (obj[0x15] != 0) {
            *(s32*)(obj + 0x20) = 0x80000;
        } else {
            *(s32*)(obj + 0x20) = 0xFFF80000;
        }
        *(s32*)(obj + 0x28) = 0;
        *(s32*)(obj + 0x24) = 0;
        *(s32*)(obj + 0x2C) = 0;
        obj[6]++;
    }
}
