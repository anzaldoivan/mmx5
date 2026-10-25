#include "types.h"

extern void func_80014684(s32, s32, s32);
extern void func_800157D4(void);
extern void func_80015A88(s32, s32);

void func_80013B8C(void) {
    func_80014684(0x4D, 0, 0);
    func_800157D4();
    func_80015A88(0x4E, 0x801F3000);
    func_800157D4();
}
