#include "types.h"

extern s32 func_8003E6FC(void*, s8);
extern u8* func_8003D3A8(s32, s32, s32, u8*);
extern s32 func_80039E7C(u8*);
extern void func_80017248(u8* obj);
extern void func_800443A8(u8*, s8);
extern s32 func_80044328(u8*);
extern void func_8003B33C(u8*, s32);
extern void func_80016490(s32, s32, void*);
extern s32 func_8002DF78(void);
extern void func_8003CF74(u8*, s32);
extern void func_8003B4CC(u8* obj, s32 arg1, s32 arg2);
extern void func_8003B0EC(u8* obj);
void func_80042F00(u8* p);

static inline s32 func_80042F00_land(u8* p) {
    if (func_80044328(p) == 0) {
        return 0;
    }
    func_8003B33C(p, 0x5D);
    func_80016490(1, 7, p);
    if (func_8002DF78() & 4) {
        func_8003CF74(p, 8);
    }
    p[0x84] = 0;
    p[0x86] = 0;
    p[0x5] = 0x33;
    p[0x6] = 0;
    func_80042F00(p);
    return 1;
}

void func_80042F00(u8* p) {
    u8* q;

    if (*(s8*)(p + 0x2) != 0 && *(s8*)(p + 0xD3) == 0 &&
        *(s8*)(p + 0x93) == 3 && (*(u16*)(p + 0x80) & 0x20) &&
        *(s8*)(p + 0xA6) == 0 && func_8003E6FC(p, 3) <= *(s16*)(p + 0xAE)) {
        q = func_8003D3A8(1, 0x2B, 0, p);
        if (q != 0) {
            *(s16*)(p + 0xAE) -= func_8003E6FC(p, 3);
            q[0x99] = 0;
        }
    }
    if (func_80039E7C(p) != 0) {
        p[0x8E] = 0;
        return;
    }
    if (*(s8*)(p + 0x6) == 0) {
        p[0x6] = p[0x6] + 1;
    } else {
        func_80017248(p);
    }
    func_800443A8(p, 0x1E);
    if (p[0x45] & 0x40) {
        p[0x8E] = 0;
        if (func_80042F00_land(p) != 0) {
            return;
        }
        p[0x8E] = 1;
    }
    if (*(u16*)(p + 0x80) & 2) {
        p[0x15] = 0;
    }
    if (*(u16*)(p + 0x80) & 1) {
        p[0x15] = 0x40;
    }
    if (*(s8*)(p + 0x46) == 0) {
        p[0x8E] = 0;
        func_8003B4CC(p, 0x1F, 2);
        func_8003B0EC(p);
    }
}
