#include "types.h"

extern u8 D_80078C80[];
extern u8 D_8007A0E4[];
extern u8 D_80077E48[];
extern u8 D_80078048[];
extern u8 D_80077F48[];
extern s32 D_80078148[];
extern u8 D_8007903C[];
extern u8 D_8007913C[];
extern u8 D_8007923C[];
extern s32 D_8007933C[];

void func_8003C3A8(u8* o, s32 n) {
    u8 k;

    if (((s8*)o)[2] == 0) {
        if (((s8*)o)[0xF0] != 0) {
            *(s32**)(o + 0x54) = 0;
            return;
        }
        if (D_80078C80[o[0x17]] == 0) {
            n = D_80077E48[o[0x47]];
        } else if (o[0xFA] == 2) {
            n = D_80078048[o[0x47]];
        } else {
            n = D_80077F48[o[0x47]];
        }
        if (n == 0) {
            *(s32**)(o + 0x54) = 0;
            return;
        }
        *(s32**)(o + 0x54) = &D_80078148[n];
        return;
    }
    k = D_8007A0E4[o[0x17]];
    if (k == 0) {
        n = D_8007903C[o[0x47]];
    } else if (k == 1) {
        n = D_8007913C[o[0x47]];
    } else if (k == 2) {
        n = D_8007923C[o[0x47]];
    }
    if (n == 0) {
        *(s32**)(o + 0x54) = 0;
        return;
    }
    *(s32**)(o + 0x54) = &D_8007933C[n];
}
