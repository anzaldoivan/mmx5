#include "types.h"

extern void func_800231B4(void);
extern void func_80027120(void);
extern void func_800176DC(void);
extern void (*D_800730A0[])(s32);
extern u8 D_800E9300;

void func_8002BD34(s32 arg0) {
    D_800730A0[D_800E9300](arg0);
    func_800231B4();
    func_80027120();
    func_800176DC();
}
