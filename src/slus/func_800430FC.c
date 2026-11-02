#include "types.h"

extern s32 func_8003E6FC(void*, s8);
extern u8* func_8003D3A8(s32, s32, s32, u8*);
extern void func_8003A9AC(u8*);
extern void func_8003A94C(u8*);
extern s32 func_80039B50(u8*);
extern s32 func_80039BA8(u8*);
extern void func_80017248(u8*);
extern void func_800443A8(u8*, s8);
extern s32 func_80044328(u8*);
extern void func_8003B33C(u8*, s32);
extern void func_80016490(s32, s32, void*);
extern s32 func_8002DF78(void);
extern void func_8003CF74(u8*, s32);
extern void func_8002DF54(u8*);
extern void func_8003D344(void*);
extern void func_8003AEF0(u8*);

void func_800430FC(u8* o);

static inline s32 func_800430FC_sub(u8* o) {
    if (func_80044328(o) == 0) {
        return 0;
    }
    func_8003B33C(o, 0x5E);
    func_80016490(1, 7, o);
    if (func_8002DF78() & 4) {
        func_8003CF74(o, 8);
    }
    o[5] = 0x34;
    o[6] = 0;
    func_800430FC(o);
    return 1;
}

void func_800430FC(u8* o) {
    u8* p;
    u8 t;
    s32 v;

    if (((s8*)o)[2] != 0 && ((s8*)o)[0xD3] == 0 && ((s8*)o)[0x93] == 3 &&
        (*(u16*)(o + 0x80) & 0x20) && ((s8*)o)[0xA6] == 0 &&
        func_8003E6FC(o, 3) <= *(s16*)(o + 0xAE)) {
        p = func_8003D3A8(1, 0x2B, 0, o);
        if (p != 0) {
            *(s16*)(o + 0xAE) -= func_8003E6FC(o, 3);
            p[0x99] = 0;
        }
    }
    t = o[0x89];
    if (t & 8) {
        o[0x8E] = 0;
        func_8003A9AC(o);
        return;
    }
    v = ((s8*)o)[0xD3] != 0;
    if (!(t & 3)) {
        v = 1;
    }
    if (v) {
        o[0x8E] = 0;
        func_8003A94C(o);
        return;
    }
    if (func_80039B50(o)) {
        o[0x8E] = 0;
        return;
    }
    if (func_80039BA8(o)) {
        if (((s8*)o)[6] == 0) {
            o[6]++;
        } else {
            func_80017248(o);
        }
        func_800443A8(o, 0x1F);
        if (o[0x45] & 0x40) {
            o[0x8E] = 0;
            if (func_800430FC_sub(o)) {
                return;
            }
            o[0x8E] = 1;
        }
        func_8002DF54(o);
        func_8003D344(o);
        if (((s8*)o)[0x46] == 0) {
            o[0x8E] = 0;
            func_8003B33C(o, 0xF);
            o[5] = 0xB;
            o[6] = 0;
        }
    } else {
        o[0x8E] = 0;
        func_8003AEF0(o);
    }
}
