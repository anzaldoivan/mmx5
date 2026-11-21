#include "types.h"
#include "addr.h"

extern u8 D_800FA78C_ovl00[];

void func_800EFDFC_ovl00(u8* arg0) {
    D_1F80004C.bytes[0x91] = 1;
    arg0[6]++;
    *(s32*)(arg0 + 0x20) = 0;
    *(s32*)(arg0 + 0x24) = 0;
    *(s32*)(arg0 + 0x28) = 0;
    *(s32*)(arg0 + 0x2C) = 0;
    if (*(s8*)(arg0 + 2) == 0 && D_1F80004C.bytes[0x85] == 1) {
        *(u8**)(arg0 + 0x54) = D_800FA78C_ovl00;
    }
}

extern u8 D_800FA758_ovl00[];

void func_800EFE60_ovl00(Ent85* e) {
    if (--D_1F80004C.scr->unk86 == 0xFF) {
        D_1F80004C.scr->unk91 = 0;
        switch (e->unk2) {
        case 0:
            e->unk54 = D_800FA758_ovl00;
            e->unk5 = 5;
            e->unk6 = 0;
            break;
        case 1:
        case 2:
        case 3:
            e->unk5 = 6;
            e->unk6 = 0;
            break;
        case 16:
            e->unk5 = 2;
            e->unk6 = 0;
            break;
        }
    }
}
