#include "types.h"
#include "addr.h"

void func_800F0B70_ovl28(void) {
    switch ((s8)D_1F80004C.scr82->flags82) {
    case 1:
    case 5:
        D_1F80004C.scr1090->unk85 = D_1F80004C.scr1090->unk86;
        break;
    case 3:
    case 7:
        D_1F80004C.scr1090->unk85 = D_1F80004C.scr1090->unk87;
        break;
    case 2:
    case 4:
    case 6:
    case 8:
        D_1F80004C.scr1090->unk85 = D_1F80004C.scr1090->unk88;
        break;
    }
}
