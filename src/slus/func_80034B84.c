#include "types.h"

extern void func_80016D54(s32, s32);
extern void func_800132F8(s8 arg);
extern s32 func_800272B4(void);

void func_80034B84(u8* arg0) {
    func_80016D54(0xFF, 0);
    func_800132F8(8);
    func_800272B4();
    arg0[5] = 1;
}
