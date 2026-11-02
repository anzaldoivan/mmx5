#include "types.h"

extern void func_80017248(u8* obj);
extern s32 func_800317B8(u8* a0);
extern void func_8002DED4(u8* obj);
extern void func_80016490(s32, s32, void*);
extern void func_8001296C(s32);
extern s32 func_8002A5C4(s32, s32, s32);
extern s32 func_8002A600(s32, s32, s32);
extern void func_800FBAF8_ovl39(u8* obj);
extern void func_800171E8(u8* obj, s32 state);

void func_800FBCBC_ovl39(u8* obj) {
    u16 t;

    func_80017248(obj);
    func_800317B8(obj);
    t = *(u16*)(obj + 0x8C);
    if (t != 0) {
        *(u16*)(obj + 0x8C) = t - 1;
        return;
    }
    if (*(s32*)(obj + 0x24) > 0x7FFFF) {
        *(s32*)(obj + 0x24) = 0x80000;
    } else if (*(s32*)(obj + 0x24) <= -0x80000) {
        *(s32*)(obj + 0x24) = -0x80000;
    }
    if (*(s32*)(obj + 0x20) > 0x7FFFF) {
        *(s32*)(obj + 0x20) = 0x80000;
    } else if (*(s32*)(obj + 0x20) <= -0x80000) {
        *(s32*)(obj + 0x20) = -0x80000;
    }
    func_8002DED4(obj);
    if (*(s32*)(obj + 0x20) > 0) {
        if (*(s16*)(obj + 0xA) >= 0x1268) {
            func_80016490(2, 0xAA, obj);
            func_8001296C(5);
            func_8002A5C4(0x20, 4, 1);
            *(s16*)(obj + 0xA) = 0x1268;
            func_800FBAF8_ovl39(obj);
        }
    } else if (*(s32*)(obj + 0x20) < 0) {
        if (*(s16*)(obj + 0xA) < 0x11B9) {
            func_80016490(2, 0xAA, obj);
            func_8001296C(5);
            func_8002A5C4(0x20, 4, 1);
            *(s16*)(obj + 0xA) = 0x11B8;
            func_800FBAF8_ovl39(obj);
        }
    } else if (*(s32*)(obj + 0x24) < 0) {
        if (*(s16*)(obj + 0xE) >= 0x808) {
            func_80016490(2, 0xAA, obj);
            func_8001296C(5);
            func_8002A600(0x20, 4, 1);
            *(s16*)(obj + 0xE) = 0x808;
            func_800FBAF8_ovl39(obj);
        }
    } else if (*(s16*)(obj + 0xE) < 0x7B9) {
        func_80016490(2, 0xAA, obj);
        func_8001296C(5);
        func_8002A600(0x20, 4, 1);
        *(s16*)(obj + 0xE) = 0x7B8;
        func_800FBAF8_ovl39(obj);
    }
    if (obj[0x8E] == 4) {
        func_800171E8(obj, 0x19);
        obj[5]++;
    }
}
