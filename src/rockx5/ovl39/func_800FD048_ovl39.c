#include "types.h"
#include "mmx5/object.h"

void func_800FD048_ovl39(EntFD048* arg0) {
    move_object(arg0);
    if (arg0->unk2 == 0 && arg0->unkA >= 0x1290) {
        arg0->unk6++;
    } else if (arg0->unk2 == 1 && arg0->unkA < 0x1191) {
        arg0->unk6++;
    }
}
