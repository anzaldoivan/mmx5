/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_8004CD3C.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_8002DF78();
void func_80052BA0(struct X4_QuadObj* arg0);
extern u16 D_8007BC20[];
extern u8 D_8007BC6C[];

void func_80052868(struct X4_QuadObj* arg0) {
    u16* p;
    s32 n;
    u8* t;

    switch (M2C_FIELD(arg0, s8*, 0x5)) {
    case 0:
        t = D_8007BC6C;
        M2C_FIELD(arg0, s8*, 0x5) = 1;
        p = &D_8007BC20[t[func_8002DF78() & 0xF] * 8];
        arg0->vertices[0].x.h.hi = *p++;
        arg0->vertices[0].y.h.hi = *p++;
        arg0->vertices[1].x.h.hi = *p++;
        arg0->vertices[1].y.h.hi = *p++;
        arg0->vertices[2].x.h.hi = *p++;
        arg0->vertices[2].y.h.hi = *p++;
        arg0->vertices[3].x.h.hi = *p++;
        arg0->vertices[3].y.h.hi = *p++;
        n = 1;
        if (func_8002DF78() & 1) {
            n = 2;
        }
        if (func_8002DF78() & 1) {
            M2C_FIELD(arg0, s16*, 0xA) = -0xB0;
            M2C_FIELD(arg0, s32*, 0x38) = n * 0x180000;
            M2C_FIELD(arg0, s32*, 0x3C) = 0;
            M2C_FIELD(arg0, s32*, 0x40) = 0;
            M2C_FIELD(arg0, s32*, 0x44) = 0;
            M2C_FIELD(arg0, u8*, 0x48) = 0;
        } else {
            M2C_FIELD(arg0, s16*, 0xA) = 0x1F0;
            M2C_FIELD(arg0, s32*, 0x38) = -(n * 0x180000);
            M2C_FIELD(arg0, s32*, 0x3C) = 0;
            M2C_FIELD(arg0, s32*, 0x40) = 0;
            M2C_FIELD(arg0, s32*, 0x44) = 0;
            M2C_FIELD(arg0, u8*, 0x48) = 1;
        }
        M2C_FIELD(arg0, s16*, 0xE) = (func_8002DF78() & 7) * 4 + 0x68;
        M2C_FIELD(arg0, s16*, 0x52) = M2C_FIELD(arg0, s8*, 0x7) << 3;
        break;
    case 1:
        if (*(u16*)&M2C_FIELD(arg0, s16*, 0x52) != 0) {
            (*(u16*)&M2C_FIELD(arg0, s16*, 0x52))--;
            break;
        }
        if (M2C_FIELD(arg0, u8*, 0x48) == 0) {
            if (M2C_FIELD(arg0, s16*, 0xA) >= 0x140) {
                goto set2; // !FAKE: control flow kept from the mmx6 twin
            }
            goto call; // !FAKE: control flow kept from the mmx6 twin
        }
        if (M2C_FIELD(arg0, s16*, 0xA) < -0xB0) {
        set2:
            M2C_FIELD(arg0, s8*, 0x5) = 2;
            break;
        }
    call:
        func_80052BA0(arg0);
        break;
    case 2:
        ((u8*)M2C_FIELD(arg0, void**, 0x58))[0x14]--;
        arg0->state = 2;
        M2C_FIELD(arg0, s8*, 0x5) = 0;
        break;
    }
}
