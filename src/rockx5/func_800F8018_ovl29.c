#include "types.h"

extern s32 func_800171E8(ObjEF680*, s32);
extern u8 D_800FA618_ovl29[];

void func_800F8018_ovl29(ObjEF680* s) {
    ObjEF680* p = s->unk50;

    s->unk3 = 1;
    s->unk20 = 0;
    s->unk28 = 0;
    s->unk24 = 0;
    s->unk2C = 0;
    s->unk16 = 0;
    s->unk40 = p->unk40;
    s->unk42 = p->unk42 & 0x7FFF;
    s->unk30 = p->unk30;
    s->unk3C = p->unk3C;
    s->unk15 = p->unk15;
    s->unk14 = p->unk14;
    func_800171E8(s, 7);

    switch (s->unk2 & 0xFE) {
    case 2:
    case 4:
    case 6:
        s->unkA += (s8)D_800FA618_ovl29[6];
        s->unkE += (s8)D_800FA618_ovl29[7];
        break;
    case 10:
    case 12:
    case 14:
        s->unkA += (s8)D_800FA618_ovl29[4];
        s->unkE += (s8)D_800FA618_ovl29[5];
        break;
    case 8:
        s->unkA += (s8)D_800FA618_ovl29[8];
        s->unkE += (s8)D_800FA618_ovl29[9];
        break;
    case 18:
    case 20:
    case 22:
        s->unkA += (s8)D_800FA618_ovl29[12];
        s->unkE += (s8)D_800FA618_ovl29[13];
        break;
    case 26:
    case 28:
    case 30:
        s->unkA += (s8)D_800FA618_ovl29[14];
        s->unkE += (s8)D_800FA618_ovl29[15];
        break;
    case 24:
        s->unkA += (s8)D_800FA618_ovl29[10];
        s->unkE += (s8)D_800FA618_ovl29[11];
        break;
    default:
        if (s->unk15 & 0x40) {
            s->unkA += (s8)D_800FA618_ovl29[2];
            s->unkE += (s8)D_800FA618_ovl29[3];
        } else {
            s->unkA += (s8)D_800FA618_ovl29[0];
            s->unkE += (s8)D_800FA618_ovl29[1];
        }
        break;
    }
    s->unk4++;
}
