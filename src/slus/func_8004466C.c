#include "types.h"

s32 func_800392E4(void);
void func_8003A008(u8* p);

void func_8004466C(u8* p) {
    if (func_800392E4() == 0) {
        func_8003A008(p);
    }
}
