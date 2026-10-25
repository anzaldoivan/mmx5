#include "types.h"
s32 func_80039C80(u8* arg0);
s32 func_80039588(u8* arg0);
s32 func_800395E8(u8* arg0);
void func_8003A7E4(u8* arg0);

s32 func_8004445C(u8* arg0) {
    if (func_80039C80(arg0) != 0) {
        return 1;
    }
    if (func_80039588(arg0) != 0) {
        return 1;
    }
    if (func_800395E8(arg0) == 0) {
        return 0;
    }
    func_8003A7E4(arg0);
    return 1;
}
