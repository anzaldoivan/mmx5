#include "types.h"

extern void func_8003CD08(u8* obj);
extern s32 func_80043B88(u8* arg0);
extern s32 func_80039ECC(u8* arg0);
extern s32 func_8003F414(u8* arg0);
extern s32 func_8003952C(u8* arg0);
extern s32 func_80043C64(u8* arg0);
extern s32 func_80041A54(u8* arg0);
extern s32 func_800395E8(u8* arg0);
extern void func_8003A7E4(u8* arg0);
extern void func_80017248(u8* obj);
extern void func_8003B4CC(u8* obj, s32 arg1, s32 arg2);
extern void func_8003CD60(u8* obj);
extern void func_8003B33C(u8* obj, s32 arg1);
extern void func_8003A670(u8* arg0);

void func_80035864(u8* obj) {
    s8 state;
    s8 kind;
    s8 save;

    func_8003CD08(obj);
    func_80043B88(obj);
    if (*(u16*)(obj + 0x80) & 2) {
        obj[0x15] = 0;
    }
    if (*(u16*)(obj + 0x80) & 1) {
        obj[0x15] = 0x40;
    }
    if (func_80039ECC(obj) != 0) {
        return;
    }
    if (func_8003F414(obj) != 0) {
        return;
    }
    if (func_8003952C(obj) != 0) {
        return;
    }
    if (func_80043C64(obj) != 0) {
        return;
    }
    if (func_80041A54(obj) != 0) {
        return;
    }
    if (!(*(u16*)(obj + 0x7C) & 8) && func_800395E8(obj) != 0) {
        func_8003A7E4(obj);
        return;
    }
    func_80017248(obj);
    state = *(s8*)(obj + 0x6);
    if (state == 0) {
        if (*(s8*)(obj + 0x8F) != 0 && *(s8*)(obj + 0x2) == 0) {
            save = *(s8*)(obj + 0x44);
            func_8003B4CC(obj, 0x6D, obj[0x45] & 0x3F);
            *(s8*)(obj + 0x44) = save;
        }
        if (*(s8*)(obj + 0x46) == 0) {
            obj[0x6]++;
        }
    } else if (state == 1) {
        func_8003CD60(obj);
        if (*(s8*)(obj + 0x8F) != 0 && *(s8*)(obj + 0x2) == 0) {
            kind = *(s8*)(obj + 0x96);
            if (kind == 0x12 || kind == 0x14 || kind == 0x2E) {
                func_8003B33C(obj, 0x8B);
            } else {
                func_8003B33C(obj, 0x6C);
            }
        } else if (*(s8*)(obj + 0x8E) == 0 && *(s8*)(obj + 0x2) == 0) {
            func_8003B4CC(obj, 0x51, 2);
        }
        if (!(*(u16*)(obj + 0x7C) & 8)) {
            if ((*(u32*)(obj + 0x8C) & 0xFFFF0000) && *(s8*)(obj + 0x2) == 0) {
                func_8003B33C(obj, 0x6E);
            } else {
                func_8003B33C(obj, 0x52);
            }
            obj[0x6] = 2;
        }
    } else if (*(s8*)(obj + 0x46) == 0) {
        func_8003A670(obj);
    }
}
