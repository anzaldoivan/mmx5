#include "types.h"
#include "mmx5/globals.h"

void func_800FEAC8_ovl07(EntFEAC8* a0) {
    a0->unk3 = 0;
    if ((s8)a0->unk7 == 0) {
        a0->unk15 = a0->unk7C->unk15;
        a0->unk7++;
    }
    if ((s8)a0->unk7C->unk6 == 6 || (s8)a0->unk7C->unk5 != 9) {
        a0->unk4 = 2;
    } else {
        func_800317B8(a0);
    }
}

extern u8 D_80101DF0_ovl07[][4];
extern u8 D_80101DF8_ovl07[];

s32 func_800FEB48_ovl07(Ent800FE04C* o, u8 i) {
    func_8002FB58(o);
    if (o->unk70 & D_80101DF0_ovl07[o->pad71[0x1B]][i]) {
        return ((o->unk70 & D_80101DF8_ovl07[i]) != 0) * 2;
    }
    return 1;
}

void func_800FEBCC_ovl07(u8* self, s16 x, s16 y, u8 sub) {
    u8* p;

    p = func_8002D1A4();
    if (p != 0) {
        p[0] = 0x41;
        p[1] = 0xC;
        *(u8**)(p + 0x7C) = self;
        p[2] = sub;
        *(s16*)(p + 0xA) = x;
        *(s16*)(p + 0xE) = y;
        *(u16*)(p + 0x42) = *(u16*)(self + 0x42) & 0x7FFF;
        *(s32*)(p + 0x30) = *(s32*)(self + 0x30);
        *(s32*)(p + 0x3C) = *(s32*)(self + 0x3C);
        *(u16*)(p + 0x40) = *(u16*)(self + 0x40);
        p[0x14] = self[0x14];
    }
}

extern s16 D_80101DFC_ovl07[][4];

s32 func_800FEC84_ovl07(u8* arg0, u8 idx, s16 x, s16 y) {
    s16* pos = *(s16**)(arg0 + 0x84);

    if (D_80101DFC_ovl07[idx][0] + pos[0] - 4 < x &&
        x < D_80101DFC_ovl07[idx][1] + pos[0] + 4 &&
        D_80101DFC_ovl07[idx][2] + pos[1] - 4 < y &&
        y < D_80101DFC_ovl07[idx][3] + pos[1] + 4) {
        return 0;
    }
    return 1;
}
