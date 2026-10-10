#include "types.h"

#define G (*(u8**)0x1F80004C)

typedef struct {
    /* 0x00 */ u8 pad0[2];
    /* 0x02 */ s8 unk2;
    /* 0x03 */ u8 pad3[2];
    /* 0x05 */ s8 unk5;
    /* 0x06 */ s8 unk6;
    /* 0x07 */ u8 pad7;
    /* 0x08 */ s32 x; /* 16.16, integer half at 0x0A */
    /* 0x0C */ s32 y; /* 16.16, integer half at 0x0E */
} ObjEEE84;

typedef struct {
    /* 0x00 */ u8 unk0;
    /* 0x01 */ u8 unk1;
    /* 0x02 */ u8 unk2;
    /* 0x03 */ u8 pad3[5];
    /* 0x08 */ s32 x; /* 16.16, integer half at 0x0A */
    /* 0x0C */ s32 y; /* 16.16, integer half at 0x0E */
    /* 0x10 */ u8 pad10[0x6C];
    /* 0x7C */ ObjEEE84* parent;
    /* 0x80 */ u8 pad80[4];
    /* 0x84 */ s32 unk84;
} SpawnEEE84;

extern u8 D_8009A0A0[];
extern s8 D_800F4EC0_ovl05[][32];
extern u8 D_800F4F40_ovl05[][32];
extern u8 D_800F4FC4_ovl05[];
extern u8 D_800D1C00[];
extern s8 func_8002E024(ObjEEE84*, u8*);
extern void func_800171E8(ObjEEE84*, s32);
extern SpawnEEE84* func_8002D1A4();
extern void func_800EF078_ovl05(ObjEEE84*);
extern void func_8002E058();

void func_800EEE84_ovl05(ObjEEE84* s) {
    SpawnEEE84* p;

    if (((s8*)G)[0x84] != 0) {
        ((s8*)G)[0x84]--;
        return;
    }
    G[0x86] = func_8002E024(s, D_8009A0A0);
    func_800171E8(s, D_800F4EC0_ovl05[s->unk2][(s8)G[0x86]]);
    G[0x86] = D_800F4F40_ovl05[s->unk2][(s8)G[0x86]];
    p = func_8002D1A4();
    if (p == 0) {
        return;
    }
    func_800EF078_ovl05(s);
    p->unk0 = 0x41;
    p->unk1 = 0;
    p->x = s->x;
    p->y = s->y;
    ((s16*)&p->x)[1] += *(s16*)(G + 0x80);
    ((s16*)&p->y)[1] += *(s16*)(G + 0x82);
    if (s->unk2 == 0) {
        ((s16*)&p->y)[1] += 2;
    }
    if (s->unk2 == 3) {
        ((s16*)&p->y)[1] -= 4;
    }
    p->unk2 = G[0x86];
    p->parent = s;
    p->unk84 = 0;
    func_8002E058(p, (s8)G[0x86] & 0xFE);
    G[0x84] = D_800F4FC4_ovl05[(s8)D_800D1C00[0x44]];
    G[0x85] = D_800F4FC4_ovl05[(s8)D_800D1C00[0x44]] >> 1;
    s->unk5 = 2;
    s->unk6 = 0;
}
