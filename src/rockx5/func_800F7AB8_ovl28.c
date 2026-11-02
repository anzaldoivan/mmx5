#include "types.h"

extern s8 D_800D1C0F;
extern u8 D_8009A1F8[];
extern void func_8003D29C(s32, s32);
extern s32 func_80016490(s32, s32, void*);
extern void func_800171E8(u8* obj, s32 state);
extern u8* func_8002D1A4();

void func_800F7AB8_ovl28(u8* obj) {
    u8* p;
    u8* child;

    if (D_800D1C0F != 0) {
        return;
    }
    if (*(s16*)(obj + 0x7C) == 0x28) {
        p = D_8009A1F8;
        *(s32*)(obj + 0x94) = *(s16*)(p + 0x26);
        *(s16*)(p + 0x26) = *(s16*)(p + 0x24) - 0x10;
    }
    if (--*(s16*)(obj + 0x7C) == 0) {
        func_8003D29C(0x14, 0x40);
    }
    if (**(s8**)(obj + 0x80) != 0) {
        return;
    }
    if (*(s8*)(obj + 2) == 0) {
        func_80016490(2, 0x8C, obj);
        func_800171E8(obj, 0);
        *(s32*)(obj + 0x24) = 0xFFF80000;
        obj[6] = 2;
    } else {
        child = func_8002D1A4();
        if (child != 0) {
            child[0] = 0x41;
            child[1] = 0x24;
            child[2] = 0;
            *(u8**)(child + 0x7C) = obj;
        }
        func_800171E8(obj, 1);
        func_80016490(2, 0x90, obj);
        *(s32*)(obj + 0x24) = 0xFFFF4000;
        obj[6] = 5;
    }
}
