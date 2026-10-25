/* Shared body (DK-5), from the banked draft of func_800EECF4_ovl23 by tools/wave/gate.py rescan. */
#include "types.h"

extern void (*D_800EF298_ovl23[])(u8*);
extern void func_80022618(void);
extern void func_8002C2C0(void);
extern void func_8002BD8C(void);
extern void func_800272B4(void);

void DEDUP_NAME(u8* arg0) {
    D_800EF298_ovl23[*(signed char*)(arg0 + 1)](arg0);
    func_80022618();
    func_8002C2C0();
    func_8002BD8C();
    func_800272B4();
}
