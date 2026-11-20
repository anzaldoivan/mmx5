#include "types.h"
#include "mmx5/object.h"

void func_800FDDE4_ovl39(EntFD048* arg0) {
    move_object(arg0);
    if ((arg0->unk2 == 0 && arg0->unkA >= 0x12F0) ||
        (arg0->unk2 == 1 && arg0->unkA < 0x1131)) {
        arg0->unk6++;
    }
}
