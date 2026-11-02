#include "types.h"

extern s32 func_800317B8(u8* a0);
extern s32 func_80031DD0(u8* a0);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern u8 D_80074EE0[];
extern u8 D_80076560[];
extern u8 D_8009A0A0[];
extern u8 D_8009A11A;
extern u8 D_800FE37C_ovl28[];
extern u8 D_800FE380_ovl28[];
extern u8 D_800FE384_ovl28[];
extern u8 D_800FE388_ovl28[];
extern u8 D_800FE38C_ovl28[];
extern u8 D_800FE390_ovl28[];
extern void* D_800FE6A0_ovl28[];

void func_800F77A8_ovl28(u8* o) {
    s32 v;
    u8* base;
    u8* base2;
    s32 r;
    s32 t;
    s32 c;
    u8 n;

    v = o[0x47];
    if (v < 0x1F) {
        *(u8**)(o + 0x50) = D_800FE37C_ovl28;
        *(u8**)(o + 0x54) = D_800FE380_ovl28;
    } else if (v < 0x28) {
        *(u8**)(o + 0x50) = D_800FE384_ovl28;
        *(u8**)(o + 0x54) = D_800FE388_ovl28;
    } else if (v < 0x6E) {
        if (v < 0x65) {
            *(u8**)(o + 0x50) = D_800FE37C_ovl28;
            *(u8**)(o + 0x54) = D_800FE380_ovl28;
        } else {
            *(u8**)(o + 0x50) = D_800FE38C_ovl28;
            *(u8**)(o + 0x54) = D_800FE390_ovl28;
        }
    } else {
        *(u8**)(o + 0x50) = D_800FE37C_ovl28;
        *(u8**)(o + 0x54) = D_800FE380_ovl28;
    }
    func_800317B8(o);
    if (*(s8*)(o + 5) == 7) {
        *(u8**)(o + 0x58) = D_80074EE0;
    }
    r = func_80031DD0(o);
    if (r < 0) {
        o[4] = 2;
        o[5] = 0;
        o[6] = 0;
        *(u16*)(o + 0x42) &= 0x7FFF;
        D_8009A11A = 1;
        func_8002D9EC(o, 0x30, 0x30);
        return;
    }
    if (r > 0 && r != 0x7F) {
        o[0x84] = ((u32)(r - 0x19) < 2) ? 2 : 0x1E;
        *(u8**)(o + 0x58) = D_80074EE0;
    }
    n = o[0x84];
    if (n != 0) {
        o[0x84] = n + 0xFF;
        if (n & 2) {
            *(u16*)(o + 0x42) |= 0x8000;
        } else {
            *(u16*)(o + 0x42) &= 0x7FFF;
        }
        if (o[0x84] == 0) {
            *(u8**)(o + 0x58) = D_80076560;
            *(u16*)(o + 0x42) &= 0x7FFF;
        }
        if (*(s8*)(o + 5) < 3) {
            goto end; // !FAKE: duplicated test, cross-jumped, keeps the state-byte reload
        }
        goto state; // !FAKE: duplicated test, cross-jumped
    }
    if (*(s8*)(o + 5) < 3) {
        goto end; // !FAKE: duplicated test, cross-jumped
    }
state: {
    if (*(s8*)(o + 2) == 1) {
        t = *(s32*)(o + 0x88);
        if (t < 0) {
            goto end; // !FAKE: goto kept for the matching branch layout
        }
        t++;
        *(s32*)(o + 0x88) = t;
        if (t >= 0x1C20 && *(s8*)(o + 5) == 3) {
            *(s32*)(o + 0x88) = -1;
            o[5] = 7;
            o[6] = 0;
        }
    }
    base = D_8009A0A0;
    if (((*(s16*)(base + 0xA) - *(s16*)(o + 0xA)) < 0
             ? (*(s16*)(o + 0xA) - *(s16*)(base + 0xA))
             : (*(s16*)(base + 0xA) - *(s16*)(o + 0xA))) < 0x41) {
        if (*(s8*)(o + 5) == 3) {
            o[5] = 6;
            o[6] = 0;
            *(s32*)(o + 0x8C) = 0;
        }
    } else if ((base2 = D_8009A0A0,
                ((*(s16*)(base2 + 0xE) - *(s16*)(o + 0xE)) < 0
                     ? (*(s16*)(o + 0xE) - *(s16*)(base2 + 0xE))
                     : (*(s16*)(base2 + 0xE) - *(s16*)(o + 0xE))) >= 0x30) ||
               (c = *(s32*)(o + 0x8C)) == 2) {
        if (*(s8*)(o + 5) == 3) {
            o[5] = 5;
            o[6] = 0;
            *(s32*)(o + 0x8C) = 0;
        }
    } else if ((*(s32*)(o + 4) & 0xFFFF00) == 0x20300) {
        o[5] = 4;
        o[6] = 0;
        *(s32*)(o + 0x8C) = c + 1;
    }
}
end:
    o[0x9A] = 0;
    if (*(s8*)(o + 5) == 5) {
        o[0x9A] = 1;
    }
    ((void (*)(u8*))D_800FE6A0_ovl28[*(s8*)(o + 5)])(o);
}
