#include "types.h"
#include "mmx5/object.h"
#include "mmx5/globals.h"

extern s32 func_8001D7E8(u8);
extern s32 func_8001D3A8(u8);
extern s32 memcard_list_files(s32, u8*, u8*);
extern s32 memcard_read_save_file(s32, s32, s32);
extern void func_8001DB78(s32);
extern s16 func_8001FF18(void*, s32);
extern void func_8001B984(void);
extern u8 D_800E81E8[];
extern u8 D_8009A427;
extern u8 D_80010090[];
extern u8 D_80070F98[];

static inline s32 func_8001B378_poll(u8* arg0) {
    s32 t;

    t = func_8001D7E8(D_800E81D8[6]);
    if (t != 0) {
        s32 one = 1;
        s32 two = 2;
        if (t == one) {
            arg0[1] = 5;
            D_800E81D8[8] = one;
        } else {
            arg0[1] = 5;
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

void func_8001B378(u8* arg0) {
    u8* p;
    u8* q;
    u8* m;
    u8* o;
    u32 r;

    p = D_800E81D8;
    if (p[0xA] != 0) {
        p[0xA]--;
        return;
    }
    if (func_8001B378_poll(arg0) != 0) {
        return;
    }
    q = D_800E81D8;
    r = func_8001D3A8(q[6]);
    switch (r) {
    case 1:
        arg0[1] = 5;
        q[8] = 0;
        arg0[3] = 1;
        return;
    case 2:
        arg0[1] = 5;
        q[8] = 1;
        arg0[3] = r;
        return;
    case 3:
        arg0[1] = 5;
        q[8] = 1;
        arg0[3] = 0x12;
        return;
    case 0:
        if (memcard_list_files(q[6], D_800E81E8, D_80010090) != 0) {
            return;
        }
        if (D_800E81E8[0x14A] != 0) {
            if (memcard_read_save_file(*(s32*)D_800E81D8, q[6], 0x2000) != 0) {
                return;
            }
            func_8001DB78(*(s32*)(q + 0xC));
            func_8002C50C();
            func_8001FF18(D_80070F98, 0);
            m = alloc_class6_slot();
            if (m != 0) {
                m[0] = 1;
                m[1] = 0xE;
                m[2] = 1;
            }
            o = func_8002D27C();
            if (o != 0) {
                o[0] = 1;
                o[1] = 0x3E;
                o[2] = 0x10;
            }
            o = func_8002D27C();
            if (o != 0) {
                o[0] = 1;
                o[1] = 0x3E;
                o[2] = 2;
            }
            arg0[3] = 3;
            D_8009A427 = 0;
            do {
                arg0[1]++;
            } while (
                0); // !FAKE: fence weights arg0 for the saved-register order
            func_8001B984();
        } else {
            arg0[3] = 2;
            q[8] = 0;
            arg0[1] = 5;
        }
        return;
    }
}
