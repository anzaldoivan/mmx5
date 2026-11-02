#include "types.h"

extern u16 D_8006FAE4[];
extern u8 D_80070C54;
extern u8 D_800D1599;
extern u8 D_800D1C00[];

void func_8001CF5C(void) {
    u8* d;
    u8* s;
    u8 i;
    s32 j;
    s32 k;
    s32 m;
    u8* wd;
    u8* ws;
    u8* ad;
    u8* as;
    u8* bd;
    u8* bs;
    u8* cd;
    u8* cs;
    u8* hd;
    u16* hs;
    u8* ed;
    u8* es;
    u8* fd;
    u8* fs;
    u8* gd;
    u8* gs;
    u8* hd2;
    u8* hs2;
    u8* xd;
    u8* xs;

    i = 0;
    d = &D_80070C54;
    s = D_800D1C00;
    d[0] = 1;
    d[1] = s[0x79];
    d[2] = s[0xA0];
    d[3] = D_800D1599;
    *(s32*)(d + 4) = *(s32*)(s + 0x84);
    for (; i < 6; i++) {
        wd = d + 8;
        ws = s + 0x88;
        ad = d + 0x4B;
        as = s + 0x4D;
        bd = d + 0x52;
        bs = s + 0xA3;
        j = i * 4;
        *(s32*)(wd + j) = *(s32*)(ws + j);
        ad[i] = as[i];
        bd[i] = bs[i];
    }
    i = 0;
    *(s32*)(d + 0x20) = *(s32*)(s + 0x80);
    *(u16*)(d + 0x24) = *(u16*)(s + 0x7E);
    for (; i < 16; i++) {
        hd = d + 0x26;
        hs = D_8006FAE4;
        k = i * 2;
        *(u16*)(hd + k) = hs[i];
    }
    i = 0;
    d[0x48] = s[0x53];
    d[0x49] = s[0x54];
    d[0x46] = s[0x47];
    d[0x47] = s[0x48];
    d[0x4A] = s[0x4C];
    d[0x51] = s[0x4B];
    d[0x58] = s[0x4A];
    d[0x59] = s[0xA1];
    d[0x5A] = s[0xA9];
    d[0x5B] = s[0xAA];
    d[0x5C] = s[0xAB];
    *(s32*)(d + 0xE0) = *(s32*)(s + 0xAC);
    *(s32*)(d + 0xE4) = *(s32*)(s + 0x1B4);
    for (; i < 4; i++) {
        cd = d + 0xE8;
        cs = s + 0xC2;
        ed = d + 0xEC;
        es = s + 0xC6;
        cd[i] = cs[i];
        ed[i] = es[i];
    }
    i = 0;
    d[0xF0] = s[0xCA];
    d[0xF1] = s[0xCB];
    d[0x5D] = s[0x10F];
    d[0x5E] = s[0x110];
    d[0x5F] = s[0x1BA];
    for (; i < 32; i++) {
        xd = d + 0x60;
        xs = s + 0x114;
        fd = d + 0x132;
        fs = s + 0x194;
        gd = d + 0xF2;
        gs = s + 0xCD;
        hd2 = d + 0x112;
        hs2 = s + 0xED;
        m = i * 4;
        *(s32*)(xd + m) = *(s32*)(xs + m);
        fd[i] = fs[i];
        gd[i] = gs[i];
        hd2[i] = hs2[i];
    }
    d[0x152] = s[0x1B8];
    d[0x153] = s[0x1B9];
}
