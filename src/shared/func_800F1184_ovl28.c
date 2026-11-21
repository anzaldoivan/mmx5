#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "addr.h"

#define g_Player_as_Obj4FE0 (*(Obj4FE0*)&g_Player)

#define G D_1F80004C.bytes
extern s8 func_8002E024(Obj4FE0*, Obj4FE0*);
extern void func_800F09F0_ovl28(Obj4FE0*);

void func_800F1184_ovl28(Obj4FE0* s) {
    s->unk6++;
    s->unk20 = 0;
    s->unk28 = 0;
    s->unk24 = 0;
    s->unk2C = 0;
    set_animation(s, 1);
    G[0x80] = 20;
    G[0x82] = 0;
    if (g_Player_as_Obj4FE0.unkA - s->unkA > 0) {
        s->unk15 = 0x40;
    }
    G[0x85] = func_8002E024(s, &g_Player_as_Obj4FE0);
    func_800F09F0_ovl28(s);
}

extern void set_velocity_from_angle();

#define G D_1F80004C.bytes
void func_800F1224_ovl28(u8* arg0) {
    u8* p;

    if (*(s8*)(arg0 + 0x45) != 0) {
        p = func_8002D1A4();
        if (p != 0) {
            p[0] = 0x41;
            p[1] = 0x1A;
            *(s32*)(p + 8) = *(s32*)(arg0 + 8);
            *(s32*)(p + 0xC) = *(s32*)(arg0 + 0xC);
            p[2] = G[0x85];
            *(u8**)(p + 0x7C) = arg0;
            *(s32*)(p + 0x84) = 0;
            set_velocity_from_angle(p, *(s8*)(G + 0x85) & 0xFE);
            G[0x80] = 8;
            arg0[6]++;
            G[0x82]++;
        }
        p = func_8002D27C();
        if (p != 0) {
            p[0] = 0x41;
            p[1] = 0x19;
            *(s32*)(p + 8) = *(s32*)(arg0 + 8);
            *(s32*)(p + 0xC) = *(s32*)(arg0 + 0xC);
            p[2] = G[0x85];
            *(u8**)(p + 0x50) = arg0;
        }
    }
}

void func_800F0B70_ovl28();

void func_800F1344_ovl28(Obj* arg0) {
    if (D_1F80004C.scr1344->unk82 < 9) {
        func_800F0B70_ovl28();
        arg0->step -= 2;
    } else {
        arg0->step++;
    }
}
