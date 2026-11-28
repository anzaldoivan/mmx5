#include "types.h"
#include "addr.h"

void func_8004EC30(u8* o) {
    s8 s;

    s = o[2];
    o[0] = 1;
    o[3] = 1;
    o[0x15] = 0;
    *(s8*)(o + 0x14) = -1;
    switch (s) {
    case 0:
        o[0x16] = 2;
        *(s32*)(o + 0x3C) = D_801F300C + 0x801F3000;
        *(s16*)(o + 0x40) = 0x1D00;
        *(s16*)(o + 0x42) = ((*(s8*)(o + 0x56) + 8) % 16) |
                            (((*(s8*)(o + 0x56) + 8) / 16 + 0x1E0) << 6);
        break;
    case 1:
        o[0x16] = 2;
        *(s32*)(o + 0x3C) = *(s32*)D_801F3000 + 0x801F3000;
        *(s16*)(o + 0x40) = 0x1F00;
        *(s16*)(o + 0x42) =
            (*(s8*)(o + 0x56) % 16) | ((*(s8*)(o + 0x56) / 16 + 0x1E0) << 6);
        break;
    case 2:
        goto three; // !FAKE: goto kept for the matching branch layout
    case 3:
    three:
        o[0x16] = s;
        *(s32*)(o + 0x3C) = *(s32*)(D_801F3000 + 0x14) + 0x801F3000;
        *(s16*)(o + 0x40) = 0x1E00;
        *(s16*)(o + 0x42) = ((*(s8*)(o + 0x56) + 0x18) % 16) |
                            (((*(s8*)(o + 0x56) + 0x18) / 16 + 0x1E0) << 6);
        break;
    }
    o[4] = 1;
    o[6] = 0;
}
