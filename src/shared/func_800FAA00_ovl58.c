#include "types.h"

extern D_8009A1F8_t D_8009A1F8;

void func_800FAA00_ovl58(UnkObj* arg0) {
    arg0->unk4++;
    if (arg0->unk4 == 4) {
        (&D_8009A1F8)->unkE = 0x200;
        arg0->unk6++;
    } else if (arg0->unk4 == 8) {
        (&D_8009A1F8)->unkE = 0;
        arg0->unk4 = 0;
        if (arg0->unk6 >= 9) {
            arg0->unk1++;
        }
    }
    (&D_8009A1F8)->pad49[3] = 1;
}
