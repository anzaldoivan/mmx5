#include "types.h"
#include "addr.h"

extern void func_80017248(u8* obj);
extern s32 func_8002D800(u8* a0);
extern void func_8002D89C(u8* a0);
extern s32 func_8002FB58(u8* obj);
extern s32 func_800317B8(u8* a0);
extern s32 func_80031DD0(u8* a0);
extern s32 func_8004D4F4(s32 a0, void* a1, u8* a2);
extern s32 func_8004FD24(u8* a0);
extern u8 D_8009A197;
extern u8 D_800FB69C_ovl10[];
extern void* D_800FB718_ovl10[];

void func_800F1544_ovl10(u8* obj) {
    u8 flags;
    s32 dir;

    if (D_8009A197 == 0) {
        *(s32*)(obj + 0x18) = *(s32*)(obj + 0x8);
        *(s32*)(obj + 0x1C) = *(s32*)(obj + 0xC);
        ((void (*)(u8*))D_800FB718_ovl10[*(s8*)(obj + 5)])(obj);
        func_80017248(obj);
        if (--*(s16*)(D_1F80004C.bytes + 0x88) == -1) {
            func_8004FD24(obj);
            func_8004D4F4(3, D_800FB69C_ovl10, obj);
            obj[4] = 2;
            return;
        }
    }
    func_800317B8(obj);
    if (func_80031DD0(obj) < 0) {
        func_8004FD24(obj);
        func_8004D4F4(3, D_800FB69C_ovl10, obj);
        obj[4] = 2;
        return;
    }
    if (func_8002D800(obj) != 0) {
        obj[4] = 3;
        return;
    }
    func_8002D89C(obj);
    flags = obj[0x70];
    if ((flags & 0xC) == 0xC || (flags & 3) == 3) {
        func_8004FD24(obj);
        *(s32*)(obj + 0x20) = 0;
        func_8004D4F4(3, D_800FB69C_ovl10, obj);
        obj[4] = 2;
        return;
    }
    if (flags & 8) {
        obj[0x67] = 0;
    } else {
        dir = *(s32*)(obj + 0x24);
        if (dir < 0) {
            dir = -1;
        } else {
            dir = 1;
        }
        obj[0x67] = dir;
    }
    func_8002FB58(obj);
}
