#include "types.h"

extern void func_800132F8(s8 arg);
extern s32 func_800272DC(void);

void func_80034E0C(u8* arg0) {
    func_800132F8(8);
    func_800272DC();
    arg0[5] = 1;
}
