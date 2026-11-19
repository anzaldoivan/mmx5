#include "types.h"
#include "mmx5/globals.h"

void func_800FAB10_ovl53(Ovl45State* arg0) {
    if (arg0->unk4 == 0) {
        func_8002385C(0x53, 0xFF, 0);
        arg0->unk4 = 0;
        arg0->unk1++;
    }
}
