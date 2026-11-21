#include "types.h"
#include "mmx5/object.h"

#define func_800FD504_ovl39 func_800FDD90_ovl39
#include "shared/func_800FD504_ovl39.c"
#undef func_800FD504_ovl39

void func_800FDDE4_ovl39(EntFD048* arg0) {
    move_object(arg0);
    if ((arg0->unk2 == 0 && arg0->unkA >= 0x12F0) ||
        (arg0->unk2 == 1 && arg0->unkA < 0x1131)) {
        arg0->unk6++;
    }
}

void func_800FDE58_ovl39(u8* arg0) {
    arg0[0x84] = 0;
    arg0[4] = 2;
}
