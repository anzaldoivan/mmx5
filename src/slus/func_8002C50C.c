#include "types.h"

extern u8 D_8009A0A0[];
extern u8 D_8009A2F8[];
extern u8 D_800942A8[][0x50];
extern u8 D_80093E10[];
extern Obj8002CC08 D_80098120[];
extern u8 D_80092090[];
extern u8 D_80096D98[][0x9C];
extern u8 D_80094398[];
extern u8 D_8009E7A0[];
extern u8 D_800C6A10[];
extern u8 D_800D1F40[];
extern u8 D_800994A0[];
extern u8 D_800C94A8[];
extern u8 D_8009F9A0[][0x60];
extern u8 D_800D1DC0[];
extern u8 D_800D4F40[];
extern s32 D_80093DD0[];
extern u16 D_80093E68;
extern u16 D_8009A42E;
extern u16 D_800D50DE;
extern u8 D_80093E66;
extern u8 D_8009A42C;
extern u8 D_800D50DC;
extern u8 D_80091C38[];

void func_8002C50C(void) {
    u8* p;
    s32 n;
    u32 i;
    u8 z = 0;
    u8 z0 = 0;
    u8 z1;
    u8 z2;
    u8* p0;
    s32 n0;
    u8* q;
    s32 m;
    u32 j;
    u32 k;

    p0 = D_8009A0A0;
    n0 = 0x158;
    while (n0--) {
        *p0++ = z0;
    }
    for (i = 0; i < 3; i++) {
        p = D_8009A2F8 + i * 0x60;
        n = 0x60;
        while (n--) {
            *p++ = z;
        }
    }
    for (i = 0; i < 3; i++) {
        p = D_800942A8[i];
        n = 0x50;
        while (n--) {
            *p++ = z;
        }
    }
    p = D_80093E10;
    n = 0x50;
    while (n--) {
        *p++ = z;
    }
    z1 = 0;
    for (j = 0; j < 32; j++) {
        q = (u8*)&D_80098120[j];
        m = 0x9C;
        while (m--) {
            *q++ = z1;
        }
    }
    z2 = 0;
    for (k = 0; k < 48; k++) {
        p = D_80092090 + k * 0x9C;
        n = 0x9C;
        while (n--) {
            *p++ = z2;
        }
    }
    for (k = 0; k < 32; k++) {
        q = D_80096D98[k];
        m = 0x9C;
        while (m--) {
            *q++ = z2;
        }
    }
    for (i = 0; i < 96; i++) {
        p = D_80094398 + i * 0x70;
        n = 0x70;
        while (n--) {
            *p++ = z;
        }
    }
    for (i = 0; i < 96; i++) {
        p = D_8009E7A0 + i * 0x30;
        n = 0x30;
        while (n--) {
            *p++ = z;
        }
    }
    for (i = 0; i < 64; i++) {
        p = D_800C6A10 + i * 0xA4;
        n = 0xA4;
        while (n--) {
            *p++ = z;
        }
    }
    for (i = 0; i < 128; i++) {
        p = D_800D1F40 + i * 0x60;
        n = 0x60;
        while (n--) {
            *p++ = z;
        }
    }
    for (i = 0; i < 32; i++) {
        p = D_800994A0 + i * 0x60;
        n = 0x60;
        while (n--) {
            *p++ = z;
        }
    }
    for (i = 0; i < 4; i++) {
        p = D_800C94A8 + i * 0x30;
        n = 0x30;
        while (n--) {
            *p++ = z;
        }
    }
    for (i = 0; i < 64; i++) {
        p = D_8009F9A0[i];
        n = 0x60;
        while (n--) {
            *p++ = z;
        }
    }
    p = D_800D1DC0;
    n = 0xB0;
    while (n--) {
        *p++ = z;
    }
    p = D_800D1DC0 + 0xB0;
    n = 0xB0;
    while (n--) {
        *p++ = z;
    }
    p = D_800D4F40;
    n = 0x3C;
    while (n--) {
        *p++ = z;
    }
    D_80093E68 = 0;
    D_8009A42E = 0;
    D_800D50DE = 0;
    D_80093E66 = 0;
    D_8009A42C = 0;
    D_800D50DC = 0;
    for (i = 0; i < 16; i++) {
        D_80093DD0[i] = 0;
    }
    p = D_80091C38;
    n = 0x14;
    while (n--) {
        *p++ = z;
    }
}
