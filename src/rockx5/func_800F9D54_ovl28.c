#include "types.h"

extern void func_80016490(s32, s32, void*);
extern void func_8001296C(s32);
extern u8* func_8002D1A4();
extern void func_8002A600(s32, s32, s32);
extern void func_800171E8(u8* obj, s32 state);

void func_800F9D54_ovl28(u8* obj) {
    u8* p;
    s32 i;

    if (*(s8*)(obj + 0x45) == 1) {
        func_80016490(2, 0x8E, obj);
        func_8001296C(3);
        obj[0x45] = 0;
        obj[7] = 0;
        for (i = 0; i < 8; i++) {
            p = func_8002D1A4();
            if (p != 0) {
                p[0] = 0x41;
                p[1] = 0x24;
                p[2] = 5;
                *(u8**)(p + 0x7C) = obj;
            }
        }
        func_8002A600(0x10, 6, 3);
    }
    if (*(s8*)(obj + 0x46) == 0) {
        func_800171E8(obj, 2);
        obj[5] = 3;
        obj[6] = 0;
    }
}
