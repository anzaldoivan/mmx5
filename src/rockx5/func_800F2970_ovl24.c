#include "types.h"

extern u16 D_8006FAE4[];
extern Blk158 D_80070C54;
extern u8 D_800D1599;
extern u8 D_800D1C00[];
extern u8 D_800E81D8[];

void func_800F2970_ovl24(void) {
    u8* p;
    u8* e;
    u8* s;
    s32 i;
    s32 i1;
    u16 sum;
    u8* g1;
    u8* g2;
    u8* g3;
    u8* g4;
    u8* g5;
    u8* q1;
    u8* q2;

    q1 = D_800E81D8;
    p = *(u8**)(q1 + 0xC);
    g1 = D_800D1C00;
    p[0] = 0;
    p[1] = g1[0x79];
    p[2] = g1[0xA0];
    p[3] = D_800D1599;
    *(s32*)(p + 4) = *(s32*)(g1 + 0x84);
    for (i1 = 0; i1 < 6; i1++) {
        ((s32*)(p + 8))[i1] = ((s32*)(D_800D1C00 + 0x88))[i1];
        ((Rec2970*)p)->u4B[i1] = D_800D1C00[0x4D + i1];
        ((Rec2970*)p)->u52[i1] = D_800D1C00[0xA3 + i1];
    }
    g2 = D_800D1C00;
    *(s32*)(p + 0x20) = *(s32*)(g2 + 0x80);
    *(u16*)(p + 0x24) = *(u16*)(g2 + 0x7E);
    for (i = 0; i < 16; i++) {
        ((Rec2970*)p)->a26[i] = D_8006FAE4[i];
    }
    g3 = D_800D1C00;
    p[0x48] = g3[0x53];
    p[0x49] = g3[0x54];
    p[0x46] = g3[0x47];
    p[0x47] = g3[0x48];
    p[0x4A] = g3[0x4C];
    p[0x51] = g3[0x4B];
    p[0x58] = g3[0x4A];
    p[0x59] = g3[0xA1];
    p[0x5A] = g3[0xA9];
    p[0x5B] = g3[0xAA];
    p[0x5C] = g3[0xAB];
    *(s32*)(p + 0xE0) = *(s32*)(g3 + 0xAC);
    *(s32*)(p + 0xE4) = *(s32*)(g3 + 0x1B4);
    for (i = 0; i < 4; i++) {
        ((Rec2970*)p)->uE8[i] = D_800D1C00[0xC2 + i];
        ((Rec2970*)p)->uEC[i] = D_800D1C00[0xC6 + i];
    }
    g4 = D_800D1C00;
    p[0xF0] = g4[0xCA];
    p[0xF1] = g4[0xCB];
    p[0x5D] = g4[0x10F];
    p[0x5E] = g4[0x110];
    p[0x5F] = g4[0x1BA];
    for (i = 0; i < 32; i++) {
        ((Rec2970*)p)->a60[i] = ((s32*)(D_800D1C00 + 0x114))[i];
        ((Rec2970*)p)->u132[i] = D_800D1C00[0x194 + i];
        ((Rec2970*)p)->uF2[i] = D_800D1C00[0xCD + i];
        ((Rec2970*)p)->u112[i] = D_800D1C00[0xED + i];
    }
    g5 = D_800D1C00;
    p[0x152] = g5[0x1B8];
    p[0x153] = g5[0x1B9];
    sum = 0;
    e = p - 0x154;
    s = p;
    for (i = 0; i < p - e; i++) {
        sum += *s++;
    }
    *(s16*)(p + 0x154) = sum + 0x55;
    q2 = D_800E81D8;
    D_80070C54 = **(Blk158**)(q2 + 0xC);
}
