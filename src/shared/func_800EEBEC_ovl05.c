#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/graphics.h"
#include "addr.h"

#define G D_1F80004C.bytes
extern u8 D_800F4DE8_ovl05[];
extern u8 D_800F4E38_ovl05[];
extern u8 D_800750C0[];
extern u8 D_800F4E7C_ovl05[][16];
extern u8 D_800F4E3C_ovl05[][16];
extern s8 D_800F4EC0_ovl05[][32];
extern s8 func_8002E024(ObjEEBEC*, u8*);

void func_800EEBEC_ovl05(ObjEEBEC* s) {
    u8 t = g_Player[0x14];

    s->unk30 = D_800F4DE8_ovl05;
    s->unk16 = 3;
    s->unk68 = D_800F4E38_ovl05;
    s->unk58 = D_800750C0;
    s->unk5C = 4;
    s->unk15 = 0;
    s->unk14 = t;
    s->unk50 = D_800F4E7C_ovl05[s->unk2];
    s->unk54 = D_800F4E3C_ovl05[s->unk2];
    s->unk61 = 0;
    s->unk60 = 3;
    G[0x84] = 0;
    G[0x85] = 0;
    if (s->unk2 >= 5) {
        s->unk2 = 0;
    }
    if (s->unk2 == 2) {
        s->unk15 = 0x40;
    } else {
        s->unk15 = 0;
    }
    G[0x86] = func_8002E024(s, g_Player);
    set_animation(s, D_800F4EC0_ovl05[s->unk2][(s8)G[0x86]]);
    s->unk4 = 1;
    s->unk5 = 2;
    s->unk6 = 0;
}

extern u8 D_8009A197;
extern u8 D_800F4EBC_ovl05[];
extern void (*D_800F4FD8_ovl05[])(u8*);
extern void func_80054440(u8* a0, s32 a1);
extern void func_8004D4F4(s32 a0, void* a1, u8* a2);
extern void func_800EF390_ovl05(u8* a0);
extern s32 func_8002D800(u8* a0);
extern int func_8002D7A0();

void func_800EED34_ovl05(u8* obj) {
    signed char kind;

    animate_object(obj);
    if (func_80031DD0(obj) < 0) {
        func_80054440(obj, 0x12);
        goto die;
    }
    kind = *(signed char*)(obj + 2);
    if ((kind == 0 && (obj[0x70] & 7)) || (kind == 1 && (obj[0x70] & 0xE)) ||
        (kind == 2 && (obj[0x70] & 0xD)) || (kind == 3 && (obj[0x70] & 0xB))) {
    die:
        func_8004FD24(obj);
        func_8004D4F4(4, D_800F4EBC_ovl05, obj);
        obj[4] = 2;
        return;
    }
    if (D_8009A197 == 0) {
        func_800EF390_ovl05(obj);
        D_800F4FD8_ovl05[*(signed char*)(obj + 5)](obj);
    }
    func_800317B8(obj);
    if (func_8002D800(obj) == 0) {
        func_8002D89C(obj);
        return;
    }
    func_8002D7A0(obj);
}
