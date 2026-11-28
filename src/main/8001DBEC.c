#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"
#include "mmx5/sound.h"

extern void func_80013438(u8*, u8*);
extern void func_8002002C(s32);
extern s16 func_8001FF18(void*, s32);
extern u8 D_8009A427;
extern u8 D_80070F74[];

void func_8001DBEC(u8* a0) {
    u8* p;
    u8* v;

    ((s32(*)())func_8002C50C)();
    v = D_800BE9A8.p;
    *(u8**)D_800E81D8 = v;
    *(u8**)(D_800E81D8 + 0xC) = v + 0x200;
    func_80013438(v, v + 0x1FFC);
    D_8009A427 = 0;
    func_8002002C(0);
    D_800E81D8[9] = 0;
    D_800E81D8[6] = 0;
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
    a0[3] = 0;
    D_800E81D8[0xA] = 3;
    a0[1]++;
}

extern s8 D_8009A424;
extern void func_8002002C(s32);
extern void create_task(s32, void (*)(void));
extern void func_80012EAC(void);
extern void func_80020904(void);

void func_8001DCC8(u8* a0) {
    if (D_8009A424 == 0) {
        func_8002C50C();
        func_8002002C(1);
        if (a0[0x194] == 0xFF) {
            g_playthrough_state.u[0] = 3;
            g_playthrough_state.u[1] = 0;
            g_playthrough_state.u[2] = 0;
            g_playthrough_state.u[3] = 0;
        } else {
            u8* p = g_playthrough_state.u;
            u8 v = p[0x194];
            p[0] = 0x13;
            p[1] = 0;
            p[2] = 0;
            p[3] = 0;
            p[0x1D] = v;
        }
        create_task(1, func_80020904);
        func_80012EAC();
    }
}

#define func_800F3178_ovl24 func_8001DD6C
#include "shared/func_800F3178_ovl24.c"
#undef func_800F3178_ovl24

extern u8 D_800D1F28[];

void func_8001DDF4(void) {
    if (D_800C9320.h & 0x40) {
        play_sound(0, 0x22, 0);
        ((s32(*)())func_8002C50C)();
        D_800D1F28[0] = 7;
        D_800D1F28[1] = 5;
    }
}
