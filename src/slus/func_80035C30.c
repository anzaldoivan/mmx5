#include "types.h"

extern s32 func_80043B88(u8* arg0);
extern s32 func_8003E0C0(u8* arg0);
extern s32 func_8003A084(u8* arg0);
extern s32 func_800418DC(u8* arg0);
extern void func_80017248(u8* obj);
extern s32 func_800306E0(u8* arg0);
extern s32 func_8003A134(u8* arg0, s32 arg1);
extern void func_8003B4CC(u8* obj, s32 arg1, s32 arg2);
extern void func_80038748(u8* arg0);
extern void func_80038488(u8* arg0);
extern void func_80016490(s32, s32, void*);

void func_80035C30(u8* arg0) {
    s8 saved;

    func_80043B88(arg0);
    if (*(u16*)(arg0 + 0x7C) & 2) {
        arg0[0x15] = 0;
    }
    if (*(u16*)(arg0 + 0x7C) & 1) {
        arg0[0x15] = 0x40;
    }
    if (func_8003E0C0(arg0) != 0) {
        return;
    }
    if (func_8003A084(arg0) != 0) {
        return;
    }
    if (func_800418DC(arg0) != 0) {
        return;
    }
    if (*(s8*)(arg0 + 0x6) == 0) {
        func_80017248(arg0);
        if (*(s8*)(arg0 + 0x8F) != 0 && *(s8*)(arg0 + 0x2) == 0) {
            saved = *(s8*)(arg0 + 0x44);
            func_8003B4CC(
                arg0, func_8003A134(arg0, func_800306E0(arg0) & 0xFF) + 0x94,
                arg0[0x45] & 0x3F);
            *(s8*)(arg0 + 0x44) = saved;
        }
        if (*(s8*)(arg0 + 0x46) == 0) {
            arg0[0x6] = 1;
        }
    } else {
        func_80038748(arg0);
        func_80038488(arg0);
        if (*(s32*)(arg0 + 0x18) != *(s32*)(arg0 + 0x8)) {
            if (*(s8*)(arg0 + 0x157) == 0) {
                func_80016490(0, 0x27, arg0);
            }
            if (++*(s8*)(arg0 + 0x157) < 21) {
                return;
            }
        }
        arg0[0x157] = 0;
    }
}
