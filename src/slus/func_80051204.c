#include "types.h"

extern s16 D_8007B814[][6];
extern s16 D_8007B816;
extern s16 D_8007B822;

void func_80051204(u8* p) {
    switch (*(s8*)(p + 2)) {
    case 1:
        *(s16*)(p + 0x1A) -= 4;
        *(s16*)(p + 0x22) -= 4;
        *(s16*)(p + 0x2A) -= 4;
        *(s16*)(p + 0x32) -= 4;
        if (*(s16*)(p + 0x1A) <= D_8007B816 + *(s16*)(p + 0x48)) {
            p[5] = 5;
        }
        return;
    case 2:
        *(s16*)(p + 0x1A) += 4;
        *(s16*)(p + 0x22) += 4;
        *(s16*)(p + 0x2A) += 4;
        *(s16*)(p + 0x32) += 4;
        if (*(s16*)(p + 0x1A) < D_8007B822 + *(s16*)(p + 0x48)) {
            return;
        }
        p[5] = 5;
        break;
    case 3:
    case 4:
        *(s16*)(p + 0x1A) -= 4;
        *(s16*)(p + 0x22) -= 4;
        *(s16*)(p + 0x2A) += 4;
        *(s16*)(p + 0x32) += 4;
        if (D_8007B814[*(s8*)(p + 2) - 1][1] + *(s16*)(p + 0x48) <
            *(s16*)(p + 0x1A)) {
            return;
        }
        p[5] = 5;
        break;
    }
}
