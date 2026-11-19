#include "types.h"
#include "mmx5/object.h"

void func_800FCF70_ovl39(EntFD048* arg0) {
    move_object(arg0);
    if ((arg0->unk2 == 0 && arg0->unkA < 0x1291) ||
        (arg0->unk2 == 1 && arg0->unkA >= 0x1190)) {
        arg0->unk6++;
    }
}
