#include "types.h"

extern s32 func_80039C80(u8* arg0);
extern s32 func_8003EF28(u8* arg0);
extern s32 func_800437FC(u8* arg0);
extern s32 func_800394B0(u8* arg0);
extern s32 func_8004387C(u8* arg0);
extern s32 func_80041A54(u8* arg0);
extern void func_80016490(s32, s32, void*);
extern void func_8002DED4(u8* obj);
extern void func_8003A670(u8* arg0);
extern void func_8003F2D8(u8* arg0, s32 arg1);

void func_800356F4(u8* obj) {
    s32 mask;

    if (func_80039C80(obj) != 0) {
        return;
    }
    if (func_8003EF28(obj) != 0) {
        return;
    }
    if (func_800437FC(obj) != 0) {
        return;
    }
    if (func_800394B0(obj) != 0) {
        return;
    }
    if (func_8004387C(obj) != 0) {
        return;
    }
    if (func_80041A54(obj) != 0) {
        return;
    }
    if (*(s8*)(obj + 0x45) & 0x80) {
        obj[0x45] &= 0x7F;
        func_80016490(1, 6, obj);
    }
    if ((obj[0x45] & 0x40) && *(s8*)(obj + 0x85) == 0) {
        mask = 2;
        if (obj[0x15] != 0) {
            mask = 1;
        }
        if (obj[0x89] & mask) {
            *(s32*)(obj + 0x20) = 0;
        }
        if (*(s32*)(obj + 0x20) != 0) {
            func_8002DED4(obj);
            if (obj[0x15] != 0) {
                if (*(s32*)(obj + 0x20) < 0) {
                    *(s32*)(obj + 0x20) = 0;
                }
            } else {
                if (*(s32*)(obj + 0x20) > 0) {
                    *(s32*)(obj + 0x20) = 0;
                }
            }
        }
    }
    if (*(s8*)(obj + 0x46) < 0) {
        func_8003A670(obj);
    } else {
        func_8003F2D8(obj, 0x11);
    }
}
