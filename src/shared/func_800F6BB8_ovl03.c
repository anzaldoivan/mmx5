#include "types.h"
#include "mmx5/movement.h"
#include "mmx5/globals.h"
#include "mmx5/system.h"
#include "mmx5/sound.h"

extern s32 ratan2(s32, s32);
extern s32 rcos(s32);
extern s32 rsin(s32);

void func_800F6BB8_ovl03(u8* arg0) {
    s16 angle;
    u8* base;
    u8* base2;

    func_800317B8(arg0);
    *(u16*)(arg0 + 0x42) &= 0x7FFF;
    if (func_80031DD0(arg0) < 0) {
        func_8004FD24(arg0);
        arg0[4]++;
        func_8002D9EC(arg0, 0x16, 0x16);
        return;
    }
    switch (*(s8*)(arg0 + 5)) {
    case 0:
        if (!(*(u16*)(arg0 + 0x7C) & 3)) {
            *(s32*)(arg0 + 0x24) = -*(s32*)(arg0 + 0x24);
        }
        if (++*(s16*)(arg0 + 0x7C) == 0x14) {
            base = g_Player;
            if (*(s16*)(base + 0xA) > *(s16*)(arg0 + 0xA)) {
                arg0[0x15] = 0x40;
            } else {
                arg0[0x15] = 0;
            }
            base2 = g_Player;
            angle = ratan2(*(s16*)(base2 + 0xE) - *(s16*)(arg0 + 0xE),
                           *(s16*)(base2 + 0xA) - *(s16*)(arg0 + 0xA));
            *(s32*)(arg0 + 0x20) = rcos(angle) << 5;
            *(s32*)(arg0 + 0x24) = -rsin(angle) << 5;
            *(s16*)(arg0 + 0x7C) = 0;
            arg0[5]++;
        }
        break;
    case 1:
        if (++*(s16*)(arg0 + 0x7C) == 0xC8) {
            arg0[4] = 2;
        }
        break;
    }
    if (*(s8*)(*(u8**)(arg0 + 0x80) + 4) == 2) {
        func_8004FD24(arg0);
        arg0[4] = 2;
    }
    if (*(s8*)(*(u8**)(arg0 + 0x80) + 5) == 0xA) {
        arg0[4] = 2;
    }
    func_8002D9EC(arg0, 0x10, 0x10);
    animate_object(arg0);
    apply_object_motion(arg0);
}

extern void set_animation_frame(u8* a0, s32 a1, s32 a2);

extern u8 D_8009A0B4;
extern u8 D_800F9E70_ovl03[];
extern u8 D_800F9E74_ovl03[];
extern u8 D_800750C0[];

void func_800F6D9C_ovl03(u8* obj) {
    u8* par;
    u8 dir;
    u16 x;
    Ent6B44* e = (Ent6B44*)obj;

    par = *(u8**)(obj + 0x80);
    e->unk40 = *(u16*)(par + 0x40);
    e->unk42 = *(u16*)(par + 0x42) & 0x7FFF;
    e->unk30 = *(void**)(par + 0x30);
    e->unk3C = *(s32*)(par + 0x3C);
    e->unk14 = D_8009A0B4;
    e->unk16 = 4;
    dir = par[0x15];
    e->unk67 = 0;
    e->unk3 = 0;
    e->unk68 = 0;
    e->unk50 = (s32)D_800F9E70_ovl03;
    e->unk54 = (s32)D_800F9E74_ovl03;
    e->unk58 = (s32)D_800750C0;
    obj[0x62] = 0;
    obj[0x61] = 0;
    obj[0x15] = dir;
    *(s16*)(obj + 0xA) = *(u16*)(par + 0xA);
    x = *(u16*)(par + 0xE);
    *(s32*)(obj + 0x24) = 0x8000;
    *(s32*)(obj + 0x20) = 0;
    *(s32*)(obj + 0x28) = 0;
    *(s32*)(obj + 0x2C) = 0;
    obj[0x5C] = 3;
    obj[0x60] = 3;
    obj[0x90] = 0;
    *(s16*)(obj + 0xE) = x;
    *(s16*)(obj + 0x7C) = 0;
    *(s16*)(obj + 0x7E) = 0;
    set_animation_frame(obj, 0xD, random_byte() % 10);
    play_sound(2, 0xE, obj);
    obj[0x5] = 0;
    obj[0x4]++;
}

#define g_Player_as_Obj66A0 (*(Obj66A0*)&g_Player)

void func_800F6EE4_ovl03(Obj66A0* o) {
    s32 vx;
    s32 r;
    s32 vy;
    s32 d;

    vx = 0x14000;
    vy = 0x8000;
    r = func_800317B8(o);
    o->unk42 &= 0x7FFF;
    if (func_80031DD0(o) < 0) {
        func_8004FD24(o);
        o->unk4++;
        func_8002D9EC(o, 0x16, 0x16);
        return;
    }
    switch (o->unk5) {
    case 0:
        if (!(o->unk7C & 3)) {
            o->unk24 = -o->unk24;
        }
        if (++o->unk7C == 0x3C) {
            if (g_Player_as_Obj66A0.unkA > o->unkA) {
                o->unk15 = 0x40;
            } else {
                o->unk15 = 0;
            }
            if (o->unkA > g_Player_as_Obj66A0.unkA) {
                o->unk20 = -vx;
            } else {
                o->unk20 = 0;
            }
            if (o->unkA == g_Player_as_Obj66A0.unkA) {
                o->unk20 = 0;
            }
            if (g_Player_as_Obj66A0.unkE < o->unkE) {
                o->unk24 = vy;
            } else {
                o->unk24 = -vy;
            }
            o->unk7C = 0;
            o->unk5++;
        }
        break;
    case 1:
        if (++o->unk7C == 0xD2 || r != 0) {
            o->unk24 = 0x20000;
            o->unk20 = 0;
            o->unk7C = 0;
            o->unk5++;
            break;
        }
        if (!(o->unk7C & 3)) {
            if (g_Player_as_Obj66A0.unkA > o->unkA) {
                o->unk15 = 0x40;
            } else {
                o->unk15 = 0;
            }
            if (o->unkA > g_Player_as_Obj66A0.unkA) {
                o->unk20 = -vx;
            } else {
                o->unk20 = vx;
            }
            if (g_Player_as_Obj66A0.unkE < o->unkE) {
                o->unk24 = vy;
            } else {
                o->unk24 = -vy;
            }
        }
        d = o->unkA - g_Player_as_Obj66A0.unkA;
        if ((d >= 0) ? (d < 2) : (g_Player_as_Obj66A0.unkA - o->unkA < 2)) {
            o->unk20 = 0;
        }
        if (o->unkE == g_Player_as_Obj66A0.unkE) {
            o->unk24 = 0;
        }
        break;
    case 2:
        if (++o->unk7C == 0x78) {
            o->unk4 = 2;
        }
        break;
    }
    if (o->unk80->busy == 2) {
        func_8004FD24(o);
        o->unk4 = 2;
    }
    if (o->unk80->arg == 10) {
        o->unk4 = 2;
    }
    func_8002D9EC(o, 0x10, 0x10);
    animate_object(o);
    apply_object_motion(o);
}
