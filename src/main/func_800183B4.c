#include "types.h"
#include "addr.h"

extern void func_8002002C(s32);
extern void LoadImage(void*, void*);
extern u8 D_800708D8;

void func_800183B4(void) {
    func_8002002C(0);
    LoadImage(&D_800708D8, D_1F800038);
}
