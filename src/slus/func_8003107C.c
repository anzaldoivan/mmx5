#include "types.h"

extern u8 D_800E9309;
extern u16 D_800E931C;

s32 func_8003107C(u8* arg0, u8 arg1) {
    switch (arg1) {
    case 0x38:
    case 0x39:
    case 0x3A:
    case 0x3C:
    case 0x3E:
    case 0x3F:
        D_800E9309 |= 4;
        D_800E931C = 0x10 - *(u16*)(arg0 + 0x6E);
        return -1;
    }
    return 0;
}
