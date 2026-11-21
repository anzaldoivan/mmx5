#include "types.h"
#include "mmx5/globals.h"

#define D_800EEBA0_ovl00 func_800F23F0_ovl04
#define func_8002D720 func_8002D760
#include "shared/D_800EEBA0_ovl00.c"
#undef D_800EEBA0_ovl00
#undef func_8002D720

extern int func_8002D7A0();

void func_800F2410_ovl04(u8* arg0) {
    u8* p;

    if (((s8*)arg0)[5] == 4) {
        p = g_Player;
        p[0xCA] = 0;
        if (p[0x5C] & 0x7F) {
            p[3] = 1;
        }
    }
    func_8002D7A0();
}

extern s32 func_800F2224_ovl04(u8* arg0);
extern void func_8004D4F4(s32 a0, void* a1, u8* a2);
extern u8 D_80101640_ovl04[];
extern void (*D_80101678_ovl04[])(u8*);

void func_800F2460_ovl04(u8* arg0) {
    if (func_800F2224_ovl04(arg0)) {
        g_Player[0xCA] = 0;
        if (g_Player[0x5C] & 0x7F) {
            g_Player[3] = 1;
        }
        arg0[3] = 0;
        *(s16*)(arg0 + 0x7C) = 0xF;
        *(s16*)(arg0 + 0x7E) = 5;
        func_8004D4F4(5, D_80101640_ovl04, arg0);
        arg0[4] = 6;
    } else {
        D_80101678_ovl04[((s8*)arg0)[5]](arg0);
        animate_object(arg0);
    }
}

extern void func_8004D4F4(s32 a0, void* a1, u8* a2);
extern u8 D_80101640_ovl04[];

void func_800F250C_ovl04(u8* arg0) {
    func_8004D4F4(5, D_80101640_ovl04, arg0);
    arg0[3] = 0;
    *(s16*)(arg0 + 0x7C) = 0xF;
    *(s16*)(arg0 + 0x7E) = 5;
    arg0[4] = 6;
}

void func_800F255C_ovl04(Obj800F2688* obj) {
    if (((s8*)obj)[5] == 4) {
        g_Player[0xCA] = 0;
        if (g_Player[0x5C] & 0x7F) {
            g_Player[3] = 1;
        }
    }
    if (--obj->unk7C == 0) {
        obj->unk7C = 2;
        obj->unk4 = 2;
    } else if (--obj->unk7E == 0) {
        ((s32(*)())func_8004FD90)(obj, 1, 0x20, 0x20);
        obj->unk7E = 5;
    }
}
