#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"
#include "mmx5/sound.h"

extern s16 func_8001FF18(void*, s32);
extern u8 D_80070F7C[];

void func_800F3260_ovl24(u8* arg0) {
    u8* p;

    arg0[2]++;
    func_8002C50C();
    func_8001FF18(D_80070F7C, 0);
    p = alloc_class6_slot();
    if (p != 0) {
        p[0] = 1;
        p[1] = 0xE;
        p[2] = 0;
    }
    p = func_8002D27C();
    if (p != 0) {
        p[0] = 1;
        p[1] = 0x3E;
        p[2] = 0;
    }
    arg0[3] = 6;
}

extern s32 func_8001D7E8(u8);
extern u8 D_8009A427;
extern u16 D_800C9320;
extern u8* D_800F5F84_ovl24;

void func_800F32F4_ovl24(u8* arg0) {
    u8* obj = D_800E81D8;
    u8* p;
    s32 t;
    s32 ret;
    s32 one;
    s32 st;

    t = func_8001D7E8(obj[6]);
    if (t != 0) {
        if (t == 1) {
            arg0[1] = 10;
            obj[8] = 1;
            arg0[3] = 1;
        } else {
            arg0[1] = 10;
            st = 2;
            obj[8] = st;
            arg0[3] = 1;
        }
        D_8009A427 = 0;
        ret = 1;
    } else {
        ret = 0;
    }
    if (ret == 0 && (D_800C9320 & 0x40)) {
        play_sound(0, 0x22, 0);
        st = 7;
        arg0[3] = st;
        one = 1;
        p = func_8002D27C();
        if (p != 0) {
            p[0] = one;
            p[1] = 0x3E;
            p[2] = one;
        }
        D_800F5F84_ovl24 = p;
        *(s16*)(arg0 + 0xA) = one;
        arg0[2]++;
    }
}

extern s32 func_8001D7E8(u8);
extern u8 D_8009A427;
extern u16 D_800C9320;

void func_800F33DC_ovl24(u8* arg0) {
    u8* obj = D_800E81D8;
    s32 t;
    s32 ret;
    s32 st;

    t = func_8001D7E8(obj[6]);
    if (t != 0) {
        if (t == 1) {
            arg0[1] = 10;
            obj[8] = 1;
            arg0[3] = 1;
        } else {
            arg0[1] = 10;
            obj[8] = 2;
            arg0[3] = 1;
        }
        D_8009A427 = 0;
        ret = 1;
    } else {
        ret = 0;
    }
    if (ret == 0 && (D_800C9320 & 0x40)) {
        play_sound(0, 0x22, 0);
        arg0[2]++;
        st = 11;
        arg0[3] = st;
        D_800E81D8[0xA] = 3;
    }
}

extern s32 func_8001D7E8(u8);
extern void func_800F2970_ovl24(void);
extern void func_800F3884_ovl24(u8*);
extern u8 D_8009A427;

static inline s32 func_800F34AC_inl(u8* arg0) {
    u8* obj = D_800E81D8;
    s32 t;
    s32 ret;

    t = func_8001D7E8(obj[6]);
    if (t != 0) {
        if (t == 1) {
            arg0[1] = 10;
            obj[8] = 1;
            arg0[3] = 1;
        } else {
            arg0[1] = 10;
            obj[8] = 2;
            arg0[3] = 1;
        }
        D_8009A427 = 0;
        ret = 1;
    } else {
        ret = 0;
    }
    return ret;
}

void func_800F34AC_ovl24(u8* arg0) {
    u8* obj = D_800E81D8;

    if (obj[0xA] != 0) {
        obj[0xA]--;
        return;
    }
    if (func_800F34AC_inl(arg0) == 0) {
        func_800F2970_ovl24();
        func_800F3884_ovl24(D_800E81D8);
        if ((s8)arg0[1] != 10) {
            arg0[3] = 12;
            arg0[2]++;
        }
    }
}

extern s32 func_8001D7E8(u8);
extern u8 D_8009A427;
extern u16 D_800C9320;

static inline s32 func_800F3588_inl(u8* arg0) {
    u8* obj = D_800E81D8;
    s32 t;
    s32 ret;

    t = func_8001D7E8(obj[6]);
    if (t != 0) {
        if (t == 1) {
            arg0[1] = 10;
            obj[8] = 1;
            arg0[3] = 1;
        } else {
            arg0[1] = 10;
            obj[8] = 2;
            arg0[3] = 1;
        }
        D_8009A427 = 0;
        ret = 1;
    } else {
        ret = 0;
    }
    return ret;
}

void func_800F3588_ovl24(u8* arg0) {
    if (func_800F3588_inl(arg0) == 0 && (D_800C9320 & 0x40)) {
        play_sound(0, 0x22, 0);
        ((s32(*)())func_8002C50C)();
        D_8009A427 = 0;
        arg0[1] = 9;
        arg0[2] = 0;
    }
}
