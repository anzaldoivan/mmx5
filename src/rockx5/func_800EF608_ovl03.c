#include "types.h"

typedef struct ObjEF608 {
    /* 0x00 */ u8 pad0[6];
    /* 0x06 */ u8 unk6;
    /* 0x07 */ u8 pad7[0x20 - 0x7];
    /* 0x20 */ s32 unk20;
    /* 0x24 */ u8 pad24[0x50 - 0x24];
    /* 0x50 */ void* unk50;
    /* 0x54 */ void* unk54;
    /* 0x58 */ u8 pad58[0x80 - 0x58];
    /* 0x80 */ s32 unk80;
} ObjEF608;

extern s32 func_800171E8(ObjEF608*, s32);
extern u8 D_800F959C_ovl03[];

void func_800EF608_ovl03(ObjEF608* arg0) {
    func_800171E8(arg0, 1);
    arg0->unk80 = 5;
    arg0->unk20 = 0;
    arg0->unk54 = D_800F959C_ovl03;
    arg0->unk50 = D_800F959C_ovl03;
    arg0->unk6++;
}
