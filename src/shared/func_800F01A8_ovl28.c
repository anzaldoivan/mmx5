#include "types.h"
#include "mmx5/system.h"
#include "mmx5/graphics.h"
#include "addr.h"
#include "mmx5/globals.h"

extern u8 D_8009A0B4;
extern u8 D_800FD98C_ovl28[];
extern u8 D_800FD9C8_ovl28[];
extern u8 D_800FD9C0_ovl28[];
extern u8 D_800750C0[];

void func_800F01A8_ovl28(Ent01A8* e) {
    s32 t = D_8009A0B4;
    s32 r;

    e->unk30 = D_800FD98C_ovl28;
    e->unk16 = 4;
    e->unk20 = 0;
    e->unk24 = 0;
    e->unk28 = 0;
    e->unk2C = 0;
    e->unk67 = 0;
    e->unk68 = 0;
    e->unk50 = D_800FD9C8_ovl28;
    e->unk54 = D_800FD9C0_ovl28;
    e->unk58 = D_800750C0;
    e->unk61 = 0;
    e->unk5C = 5;
    e->unk60 = 3;
    e->unk4 = 1;
    e->unk6 = 0;
    e->unk14 = t;
    r = random_byte() & 3;
    t = (s32)D_1F80004C.scr01a8;
    ((Scr01A8*)t)->unk81 = r;
    D_1F80004C.scr01a8->unk89 = 0;
    if (e->unk2 & 0x80) {
        set_animation(e, 0);
        e->unk5 = 2;
        e->unk67 = 1;
    } else {
        e->unk15 = 0;
        set_animation(e, 0);
        e->unk67 = 0;
        e->unk5 = 3;
    }
    if ((e->unk2 & 0xF) == 1) {
        e->unk4 = 3;
    }
    if (e->unk2 == 3) {
        set_animation(e, 1);
        D_1F80004C.scr01a8->unk8A = e->unk6;
        D_1F80004C.scr01a8->unk8B = e->unk7C;
        D_1F80004C.scr01a8->unk8E = e->unkE;
        D_1F80004C.scr01a8->unk90 = e->unk24;
        D_1F80004C.scr01a8->unk94 = e->unk2C;
        e->unk5 = 7;
    }
}

#define SCR4C D_1F80004C.bytes
extern u8 D_800FD9D4_ovl28[];
extern void (*D_800FDA10_ovl28[])(u8*);
extern void func_80054440(u8* a0, s32 a1);
extern void func_8004D4F4(s32 a0, void* a1, u8* a2);
extern void func_800F092C_ovl28(u8* a0);
extern s32 func_8002D800(u8* a0);

void func_800F0344_ovl28(u8* obj) {
    u8 state;
    u8* p;

    *(s32*)(obj + 0x18) = *(s32*)(obj + 0x8);
    *(s32*)(obj + 0x1C) = *(s32*)(obj + 0xC);
    if (func_80031DD0(obj) < 0) {
        func_8004FD24(obj);
        func_80054440(obj, 0x12);
        func_8004D4F4(5, D_800FD9D4_ovl28, obj);
        state = 2;
    } else {
        p = g_Player;
        if (p[0xF7] == 0) {
            if (*(signed char*)(obj + 2) == 3) {
                if (*(s32*)(obj + 8) > *(s32*)(p + 8)) {
                    obj[0x15] = 0;
                } else {
                    obj[0x15] = 0x40;
                }
            }
            func_800F092C_ovl28(obj);
            if (SCR4C[0x89] < 0x3C) {
                D_800FDA10_ovl28[*(signed char*)(obj + 5)](obj);
            } else {
                animate_object(obj);
            }
        }
        func_800317B8(obj);
        if (func_8002D800(obj) == 0) {
            func_8002D89C(obj);
            return;
        }
        state = 4;
    }
    obj[4] = state;
}
