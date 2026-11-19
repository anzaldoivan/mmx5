/* Shared body (DK-5), from the banked draft of func_800F0C80_ovl20 by tools/wave/gate.py rescan. */
#include "types.h"

extern void (*D_800F5354_ovl20[])(u8*);
extern void func_800223E4(void);
extern void func_8002272C(void);
extern void func_80022618(void);
extern void run_text_box(void);
extern void func_8002C2C0(void);
extern void func_8002BD8C(void);
extern void func_800272B4(void);

void DEDUP_NAME(u8* arg0) {
    D_800F5354_ovl20[*(signed char*)(arg0 + 1)](arg0);
    func_800223E4();
    func_8002272C();
    func_80022618();
    run_text_box();
    func_8002C2C0();
    func_8002BD8C();
    func_800272B4();
}
