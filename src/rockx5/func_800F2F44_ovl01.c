#include "types.h"

s32 func_800F2F44_ovl01(Ent08D8* arg0) {
    if (!(arg0->unk70 & 8)) {
        arg0->unk5 = 7;
        arg0->unk6 = 0;
        arg0->unk2C = 0x4200;
        arg0->unk24 = 0;
        arg0->unk20 = 0;
        arg0->unk28 = 0;
        arg0->unk67 = 1;
        return 1;
    }
    return 0;
}
