#include "types.h"

extern s32 func_8003E6FC(void*, s8);
extern u8* func_8003D3A8(s32, s32, s32, u8*);
extern s32 func_800390A4(u8* p);
extern void func_800443A8(u8*, s8);
extern void func_80017248(u8* obj);
extern s32 func_80044328(u8*);
extern void func_8003B33C(u8*, s32);
extern s32 func_80016490(s32, s32, void*);
extern void* func_8003D4C0(s8 arg0, s8 arg1, s8 arg2, s32 arg3);
extern s32 func_80039D2C(u8* obj);
extern s32 func_80039AE0(void* self);
extern s32 func_80038850(u8* self);
extern void func_8003D120(u8*);
extern void func_8003D344(void* arg0);
extern void func_8003B4CC(u8* obj, s32 arg1, s32 arg2);

void func_80042770(u8* o);

static inline s32 func_80042770_a(u8* o) {
    if (func_80044328(o)) {
        if (o[0xC9] & 1) {
            func_8003B33C(o, 0x60);
            func_80016490(1, 7, o);
            func_8003D4C0(1, 0x11, 0, (s32)o);
            o[5] = 0x35;
        } else {
            func_8003B33C(o, 0x5B);
            func_80016490(1, 8, o);
            o[5] = 0x31;
        }
        o[6] = 0;
        func_80042770(o);
        return 1;
    }
    return 0;
}

void func_80042770(u8* o) {
    u8* p;
    s8 saved;
    s32 t;

    if (((s8*)o)[2] != 0 && ((s8*)o)[0xD3] == 0 && ((s8*)o)[0x93] == 3 &&
        (*(u16*)(o + 0x80) & 0x20) && ((s8*)o)[0xA6] == 0) {
        t = func_8003E6FC(o, 3);
        if (*(s16*)(o + 0xAE) >= t) {
            p = func_8003D3A8(1, 0x2B, 0, o);
            if (p != 0) {
                *(s16*)(o + 0xAE) -= func_8003E6FC(o, 3);
                p[0x99] = 0;
            }
        }
    }
    if (func_800390A4(o)) {
        return;
    }
    if (((s8*)o)[6] == 0) {
        if (((s8*)o)[5] == 0x31) {
            func_800443A8(o, 0x1B);
        }
        o[6]++;
    } else {
        func_80017248(o);
        if (((s8*)o)[5] == 0x35) {
            func_800443A8(o, 0x20);
        }
    }
    if (((s8*)o)[0xD3] != 0) {
        *(s32*)(o + 0x24) = 0;
    }
    if (o[0x89] & 4) {
        *(s32*)(o + 0x24) = 0;
    }
    if (!(*(u16*)(o + 0x7C) & 0x80)) {
        *(s32*)(o + 0x24) = 0;
    }
    if (((s8*)o)[0x8E] != 0 && ((s8*)o)[0x46] == 0) {
        o[0x8E] = 0;
    }
    if (func_80042770_a(o)) {
        return;
    }
    saved = ((s8*)o)[0x8E];
    o[0x8E] = 0;
    if (o[0x45] & 0x40) {
        if (func_80042770_a(o)) {
            return;
        }
    }
    if (((s8*)o)[0x8B] == 0) {
        if (func_80039D2C(o)) {
            return;
        }
        if (func_80039AE0(o)) {
            return;
        }
        if (func_80038850(o)) {
            return;
        }
    } else {
        o[0x8B]--;
    }
    o[0x8E] = saved;
    func_8003D120(o);
    func_8003D344(o);
    if (*(s32*)(o + 0x24) > 0) {
        return;
    }
    if (((s8*)o)[0x8E] != 0) {
        if (((s8*)o)[5] == 0x31) {
            o[5] = 0x32;
        } else {
            o[5] = 0x36;
        }
        o[6] = 1;
    } else {
        func_8003B4CC(o, 0xB, 5);
        o[0x8A] = 0;
        o[5] = 7;
        o[6] = 0;
    }
    ((s8*)o)[0x67] = -1;
}
