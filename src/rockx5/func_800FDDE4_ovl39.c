#include "types.h"

extern void func_8002DF54(EntFD048*);

void func_800FDDE4_ovl39(EntFD048* arg0) {
    func_8002DF54(arg0);
    if ((arg0->unk2 == 0 && arg0->unkA >= 0x12F0) ||
        (arg0->unk2 == 1 && arg0->unkA < 0x1131)) {
        arg0->unk6++;
    }
}
