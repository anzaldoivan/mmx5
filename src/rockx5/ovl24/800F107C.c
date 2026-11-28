#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"
#include "mmx5/sound.h"

extern s32 func_8001D7E8(u8);
extern s16 func_8001FF18(void*, s32);
extern u8 D_80070F84[];
extern u8 D_8009A427;
#define D_800D1C00_as_X4_EngineObj (*(X4_EngineObj*)&g_playthrough_state)
extern u8* D_800F5F84_ovl24;

static inline s32 func_800F107C_ovl24_poll(u8* arg0) {
    s32 t;

    t = func_8001D7E8(D_800E81D8[6]);
    if (t != 0) {
        s32 one = 1;
        s32 two = 2;
        if (t == one) {
            arg0[1] = 0xA;
            D_800E81D8[8] = one;
        } else {
            arg0[1] = 0xA;
            D_800E81D8[8] = two;
        }
        arg0[3] = one;
        do {
            D_8009A427 = 0;
        } while (0); // !FAKE: do-while(0) for the register choice
        return 1;
    }
    return 0;
}

void func_800F107C_ovl24(u8* arg0) {
    u8* p;
    s32 n;
    u8* q;

    if (func_800F107C_ovl24_poll(arg0) != 0) {
        return;
    }
    if (g_pad1_buttons[2] & 0xA000) {
        play_sound(0, 0xC, 0);
        D_800D1C00_as_X4_EngineObj.unkA ^= 1;
    }
    if (g_pad1_buttons[2] & 0x40) {
        play_sound(0, 0x22, 0);
        p = D_800F5F84_ovl24;
        n = 0x5F;
        do {
            *p++ = 0;
        } while (n--);
        if (D_800D1C00_as_X4_EngineObj.unkA == 0) {
            ((s32(*)())func_8002C50C)();
            func_8001FF18(D_80070F84, 0);
            q = alloc_class6_slot();
            if (q != 0) {
                q[0] = 1;
                q[1] = 0xE;
                q[2] = 0;
            }
            q = func_8002D27C();
            if (q != 0) {
                q[0] = 1;
                q[1] = 0x3E;
                q[2] = 0;
            }
            arg0[3] = 0xE;
            D_800E81D8[0xA] = 3;
            arg0[2]++;
            return;
        }
        ((s32(*)())func_8002C50C)();
        arg0[0] = 0xE;
        arg0[1] = 3;
        arg0[2] = 0;
        arg0[3] = 0;
    }
}

extern s32 func_8001D3A8(u8);
extern s32 func_8001D7E8(u8);
extern s32 memcard_format(u8);
extern u8 D_8009A427;
extern u8 D_800E8332;

static inline s32 func_800F1248_ovl24_poll(u8* arg0) {
    s32 t;

    t = func_8001D7E8(D_800E81D8[6]);
    if (t != 0) {
        s32 one = 1;
        s32 two = 2;
        if (t == one) {
            arg0[1] = 0xA;
            D_800E81D8[8] = one;
        } else {
            arg0[1] = 0xA;
            D_800E81D8[8] = two;
        }
        arg0[3] = one;
        do {
            D_8009A427 = 0;
        } while (0); // !FAKE: do-while(0) for the register choice
        return 1;
    }
    return 0;
}

void func_800F1248_ovl24(u8* arg0) {
    u8* p;
    u8* q;
    u8* b;
    s32 r;

    p = D_800E81D8;
    if (p[0xA] != 0) {
        p[0xA]--;
        return;
    }
    if (func_800F1248_ovl24_poll(arg0) != 0) {
        return;
    }
    q = D_800E81D8;
    r = func_8001D3A8(q[6]) & 0xFF;
    if (r != 0 && r != 2) {
        ((s32(*)())func_8002C50C)();
        D_8009A427 = 0;
        arg0[1] = 0xA;
        arg0[2] = 0;
        if (r == 1) {
            q[8] = 0;
            arg0[3] = 1;
            return;
        }
        q[8] = 4;
        arg0[3] = 1;
        return;
    }
    b = D_800E81D8;
    if (memcard_format(b[6]) == 0) {
        arg0[2]++;
        (*(u8**)(b + 0xC))[0] = 0xFF;
        (*(u8**)(b + 0xC))[0x158] = 0xFF;
        (*(u8**)(b + 0xC))[0x2B0] = 0xFF;
        (*(u8**)(b + 0xC))[0x408] = 0xFF;
        (*(u8**)(b + 0xC))[0x560] = 0xFF;
        (*(u8**)(b + 0xC))[0x6B8] = 0xFF;
        (*(u8**)(b + 0xC))[0x810] = 0xFF;
        (*(u8**)(b + 0xC))[0x968] = 0xFF;
        D_800E8332 = 0;
        arg0[3] = 0xF;
    } else {
        ((s32(*)())func_8002C50C)();
        b[8] = 4;
        arg0[1] = 0xA;
        arg0[2] = 0;
        arg0[3] = 0x10;
    }
}
