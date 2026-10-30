#include "types.h"

extern s32 func_80044328(u8*);
extern s32 func_800306E0(u8*);
extern void func_8003B33C(u8*, s32);
extern void func_80016490(s32, s32, void*);
extern s32 func_8002DF78(void);
extern void func_8003CF74(u8*, s32);
extern void func_8003CE10(u8*);
extern s32 func_80043B88(u8* arg0);
extern void func_80017248(u8* obj);
extern void func_800443A8(u8*, s8);
extern void func_8003A874(u8*);

s32 func_80041774(u8* arg0) {
    if (func_80044328(arg0) == 0) {
        return 0;
    }
    func_8003B33C(arg0, 0x6A);
    func_80016490(1, 7, arg0);
    if (func_8002DF78() & 4) {
        func_8003CF74(arg0, 8);
    }
    func_8003CE10(arg0);
    arg0[5] = 0x3D;
    arg0[6] = 0;
    func_80043B88(arg0);
    if (*(s8*)(arg0 + 6) == 0) {
        arg0[6]++;
    } else {
        func_80017248(arg0);
        func_800443A8(arg0, (arg0[0x45] & 0x7F) + 0x26);
    }
    if (*(u16*)(arg0 + 0x80) & 2) {
        arg0[0x15] = 0;
    }
    if (*(u16*)(arg0 + 0x80) & 1) {
        arg0[0x15] = 0x40;
    }
    if (*(s8*)(arg0 + 0xD3) == 0) {
        arg0[0x8E] = 0;
        if (*(u16*)(arg0 + 0x80) & 0x80) {
            func_8003A874(arg0);
            return 1;
        }
        arg0[0x8E] = 1;
    }
    if (*(s8*)(arg0 + 0x46) == 0) {
        arg0[0x8E] = 0;
        if (func_800306E0(arg0) == 0x2E) {
            arg0[5] = 0x1B;
        } else {
            arg0[5] = 0x1C;
        }
        arg0[6] = 1;
    }
    return 1;
}
