#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"
#include "mmx5/sound.h"

extern void func_80013438(s32, s32);
extern void func_8001FF18(void*, s32);
extern void func_8002002C(s32);
extern u8 D_80070F74[];
extern u8 D_8009A427;

void func_800F2EDC_ovl24(u8* arg0) {
    u8* base;
    u8* p;
    s32 v;

    ((s32(*)())func_8002C50C)();
    v = D_800BE9A8.w;
    *(s32*)D_800E81D8 = v;
    base = D_800E81D8;
    ((s32*)base)[3] = v + 0x200;
    func_80013438(v, v + 0x1FFC);
    D_8009A427 = 0;
    func_8002002C(0);
    base[9] = 1;
    func_8001FF18(D_80070F74, 0);
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
    arg0[3] = 0;
    base[6] = 0;
    base[10] = 3;
    arg0[1]++;
}

#define D_800F5024_ovl24 D_800F51CC_ovl24

#define func_800EFFBC_ovl24 func_800F2FBC_ovl24
#include "shared/func_800EFFBC_ovl24.c"
#undef func_800EFFBC_ovl24
#undef D_800F5024_ovl24

extern s32 func_8001D7E8(u8);
extern void func_800F19F0_ovl24(void);
extern void func_800F2970_ovl24(void);
extern void func_800F3884_ovl24(u8*);
extern u8 D_8009A427;

static inline s32 func_800F2FF8_inner(u8* arg0) {
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

void func_800F2FF8_ovl24(u8* arg0) {
    u8* obj = D_800E81D8;

    if (obj[0xA] != 0) {
        obj[0xA]--;
        return;
    }
    if (func_800F2FF8_inner(arg0) == 0) {
        func_800F2970_ovl24();
        func_800F3884_ovl24(D_800E81D8);
        if ((s8)arg0[1] != 10) {
            arg0[1]++;
            arg0[3] = 12;
            func_800F19F0_ovl24();
        }
    }
}

extern u8 D_8009A427;

void func_800F30D8_ovl24(u8* arg0) {
    if (D_800C9320.h & 0x40) {
        play_sound(0, 0x22, 0);
        ((s32(*)())func_8002C50C)();
        D_8009A427 = 0;
        arg0[1] = 9;
        arg0[2] = 0;
    }
}

#define D_800EEC60_ovl00 func_800F3134_ovl24
#include "shared/D_800EEC60_ovl00.c"
#undef D_800EEC60_ovl00
