#include "types.h"

extern void func_8002DED4(u8* obj);
extern s32 func_800394B0(u8* arg0);
extern s32 func_80039588(u8* arg0);
extern void func_8003A670(u8* arg0);
extern void func_8003B33C(u8*, s32);
extern void func_8003CE10(u8*);
extern void func_8003D200(u8* obj);

void func_80041628(u8* obj) {
    s32 mask;
    s32 done;
    s32 lim;
    u8 t;

    mask = 2;
    if (obj[0x15] != 0) {
        mask = 1;
    }
    if (obj[0x89] & mask) {
        done = 1;
    } else {
        func_8002DED4(obj);
        if (obj[0x15] != 0) {
            if (*(s32*)(obj + 0x20) < *(s32*)(obj + 0x118)) {
                *(s32*)(obj + 0x20) = *(s32*)(obj + 0x118);
            }
        } else {
            lim = -*(s32*)(obj + 0x118);
            if (lim < *(s32*)(obj + 0x20)) {
                *(s32*)(obj + 0x20) = lim;
            }
        }
        done = --((s8*)obj)[0x85] == 0;
    }
    if (done) {
        if (obj[0x89] & 8) {
            obj[0x67] = 0;
            func_8003CE10(obj);
            func_8003A670(obj);
            if (func_800394B0(obj) == 0) {
                func_80039588(obj);
            }
        } else {
            *(s32*)(obj + 0x20) = 0;
            *(s32*)(obj + 0x28) = 0;
            *(s32*)(obj + 0x24) = 0;
            ((s8*)obj)[0x67] = -1;
            obj[0x84] = 0;
            ((s8*)obj)[0x8C] = -1;
            *(s32*)(obj + 0x2C) = *(s32*)(obj + 0x110);
            func_8003B33C(obj, 0x13);
            obj[6] = 3;
        }
    } else {
        t = obj[0x45];
        if (t & 0x40) {
            obj[0x45] = t & 0x3F;
            func_8003D200(obj);
        }
    }
}
