/* Adapted from mmx6 @c1c892d src/shared/SLUS_013.95/func_800131AC.c, AGPL-3.0 (THIRD_PARTY.md). */
#include "types.h"
#include "addr.h"
#define M2C_UNK s32

s32 OpenTh(s32, s32, s32);
s32 CloseTh(s32);
void ChangeTh(s32);
M2C_UNK func_8006C3B8();
M2C_UNK func_8006C3C8();
extern s32 D_8006FC2C;
extern s32 D_800D51E0;

#define SLOT_PTR D_801F8300

void func_80012C34(void) {
    u8* p;

    SLOT_PTR = D_801F8100;
    do {
        p = SLOT_PTR;
        switch (*(u16*)p) {
        case 1:
            if (--*(s16*)(p + 2) != 0) {
                break;
            }
        case 2:
        case 4:
        case 0x7F:
            *(u16*)SLOT_PTR = 0x7F;
            ChangeTh(*(s32*)(SLOT_PTR + 8));
            if (D_8006FC2C != 0) {
                D_8006FC2C = 0;
                func_8006C3B8();
                CloseTh(*(s32*)(SLOT_PTR + 8));
                *(s32*)(SLOT_PTR + 8) =
                    OpenTh(D_800D51E0, *(s32*)(SLOT_PTR + 0x10),
                           *(s32*)(SLOT_PTR + 0x44));
                func_8006C3C8();
            }
            break;
        }
        SLOT_PTR += 0x80;
    } while ((u32)SLOT_PTR < 0x801F8300U);
}
