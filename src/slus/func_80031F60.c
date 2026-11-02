#include "types.h"

extern u8 D_8009A16D;
extern s32 D_8009A19C;
extern u8 D_800D1C00[];

void func_800321EC(u8* a0, s32 a1);

s32 func_80031F60(u8* a0, u8* a1) {
    s8 idx;
    s8 dmg;
    u8* tbl;
    s16 t;
    u8* g;
    u8* g2;

    idx = ((s8*)a1)[1];
    if (((s8*)a1)[0x64] != 0) {
        if (((s8*)a1)[0x64] == ((s8*)a0)[0x65]) {
            return 0x7E;
        }
        a0[0x65] = a1[0x64];
    } else {
        a0[0x65] = 0;
    }
    tbl = *(u8**)(a0 + 0x58);
    a0[0x63] = tbl[idx * 2];
    if (((s8*)a0)[0x63] == 2) {
        return 0;
    }
    switch (idx) {
    case 26:
    case 27:
    case 28:
    case 30:
    case 31:
    case 32:
    case 35:
    case 36:
    case 61:
    case 62:
        if (((s8*)a0)[0x63] != 7) {
            D_8009A16D = 1;
        }
        break;
    }
    if (((s8*)a0)[0x63] == 8) {
        a1[0x98] = 1;
        return 0x7F;
    }
    if (((s8*)a0)[0x63] == -1) {
        func_800321EC(a1, -1);
        return 0x7F;
    }
    if (((s8*)a0)[0x63] == 7) {
        a1[0x70] |= 0xF;
        return 0x7F;
    }
    dmg = ((s8*)tbl)[idx * 2 + 1];
    if (dmg != 0) {
        if (D_8009A19C & 0x100) {
            switch (idx) {
            case 0:
            case 9:
            case 18:
            case 19:
            case 20:
            case 45:
            case 46:
            case 48:
            case 58:
                dmg++;
                break;
            }
        } else if (D_8009A19C & 0x4000) {
            switch (idx) {
            case 24:
            case 25:
            case 26:
            case 27:
            case 28:
            case 30:
            case 31:
            case 37:
            case 38:
            case 39:
            case 40:
            case 41:
                dmg++;
                break;
            }
        }
        g = D_800D1C00;
        if (g[0xA0] == 0) {
            t = dmg;
            t += dmg / 4;
            if (t > 0x7F) {
                t = 0x7F;
            }
            dmg = t;
        }
    }
    g2 = D_800D1C00;
    if (*(s16*)(g2 + 0xBC) < dmg) {
        *(s16*)(g2 + 0xBC) = dmg;
    }
    a0[0x5C] -= dmg;
    *(u16*)(a0 + 0x42) |= 0x8000;
    if (((s8*)a0)[0x5C] <= 0) {
        a0[0x5C] = 0;
        func_800321EC(a1, 1);
        return ~idx;
    }
    if (((s8*)a0)[0x63] != 0) {
        a0[5] = 0;
        a0[6] = 0;
    }
    func_800321EC(a1, 0);
    return (s8)(idx + 1);
}
