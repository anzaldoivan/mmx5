#include "types.h"
#include "addr.h"

extern void func_8002D89C(u8*);
extern u8 D_80070C54;
extern u8 D_800D1599;
extern u8 D_8006FADC;
extern u8 D_8006FADD;

void func_8004E660(u8* o) {
    *(s16*)(o + 0x40) = 0x1F00;
    *(u8**)(o + 0x3C) = D_801F3000 + *(s32*)D_801F3000;
    *(s8*)(o + 0x14) = -1;
    o[0x15] = 0;
    if (*(s16*)(o + 0xE) == 0x10) {
        *(s16*)(o + 0xE) = 0x18;
        *(s16*)(o + 0x42) = 0x7802;
    } else if (*(s8*)(o + 2) == 0x1C && D_80070C54 == 0xFF) {
        *(s16*)(o + 0x42) = 0x7804;
    } else {
        *(s16*)(o + 0x42) = 0x7800;
    }
    o[0x16] = 0x10;
    if (*(s8*)(o + 2) & 0x80) {
        *(u8**)(o + 0x3C) = D_801F3000 + *(s32*)(D_801F3000 + 8);
        if (o[2] & 0x40) {
            switch (o[2] & 0x3F) {
            case 0:
                o[0x54] = D_800D1599;
                if (D_800D1599) {
                    o[0x47] = 0xA;
                } else {
                    o[0x47] = 0xB;
                }
                o[4] += 2;
                break;
            case 1:
                o[0x47] = D_8006FADC + 6;
                o[4] += 4;
                break;
            case 2:
                if (D_8006FADD) {
                    o[0x47] = 9;
                } else {
                    o[0x47] = 7;
                }
                o[4] += 3;
                break;
            case 3:
            case 4:
                o[0x47] = 0xC;
                o[4] += 5;
                break;
            }
        } else {
            o[0x47] = o[2] & 0x3F;
            o[4]++;
        }
    } else {
        o[0x47] = o[2];
        o[4]++;
    }
    func_8002D89C(o);
}
