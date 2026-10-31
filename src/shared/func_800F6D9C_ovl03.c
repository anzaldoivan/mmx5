/* Shared body (DK-5), from the banked draft of func_800F6D9C_ovl03 by tools/wave/gate.py rescan. */
#include "types.h"

extern s32 func_8002DF78(void);
extern void func_80017214(u8* a0, s32 a1, s32 a2);
extern s32 func_80016490(s32, s32, void*);

extern u8 D_8009A0B4;
extern u8 D_800F9E70_ovl03[];
extern u8 D_800F9E74_ovl03[];
extern u8 D_800750C0[];

void DEDUP_NAME(u8* obj) {
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
    func_80017214(obj, 0xD, func_8002DF78() % 10);
    func_80016490(2, 0xE, obj);
    obj[0x5] = 0;
    obj[0x4]++;
}
