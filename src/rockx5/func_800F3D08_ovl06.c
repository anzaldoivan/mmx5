#include "types.h"

extern u8 D_8009A0A0[];

#define OY (*(s16*)(o + 0xE))
#define PY(p) (*(s16*)((p) + 0xE))

void func_800F3D08_ovl06(u8* o) {
    u8* p = D_8009A0A0;

    if ((OY - PY(p)) >= 0 ? (OY - PY(p)) >= 9 : (PY(p) - OY) >= 9) {
        {
            u8* q = D_8009A0A0;
            if (OY > PY(q)) {
                OY--;
            } else if (OY < PY(q)) {
                OY++;
            }
        }
        {
            u8* r = D_8009A0A0;
            if ((OY - PY(r)) >= 0 ? (OY - PY(r)) < 9 : (PY(r) - OY) < 9) {
                *(s32*)(o + 0xC) = *(s32*)(o + 0x1C);
            }
        }
    }
    if (--*(s16*)(o + 0x7C) == 0) {
        o[6]++;
    }
}
