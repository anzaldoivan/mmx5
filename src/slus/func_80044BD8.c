#include "types.h"

extern FnTbl7 D_80010FE4;

void func_80044BD8(u8* a0) {
    FnTbl7 tbl = D_80010FE4;

    ((void (*)(u8*))tbl.fn[((s8*)a0)[0x63]])(a0);
}
