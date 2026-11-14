/* Dedup member (tools/dedup/propagate.py): cyclic rename, body inlined. */
#include "types.h"

#define DEDUP_NAME func_800FB204_ovl41

// dedup-inline ../shared/func_800F0C80_ovl20.c
// dedup-rename D_800F5354_ovl20 D_800FB838_ovl41
// dedup-rename func_80022618 func_8002272C
// dedup-rename func_8002272C func_80022618

/* Shared body (DK-5), from the banked draft of func_800F0C80_ovl20 by tools/wave/gate.py rescan. */
#include "types.h"

extern void (*D_800FB838_ovl41[])(u8*);
extern void func_800223E4(void);
extern void func_80022618(void);
extern void func_8002272C(void);
extern void func_80022E80(void);
extern void func_8002C2C0(void);
extern void func_8002BD8C(void);
extern void func_800272B4(void);

void DEDUP_NAME(u8* arg0) {
    D_800FB838_ovl41[*(signed char*)(arg0 + 1)](arg0);
    func_800223E4();
    func_80022618();
    func_8002272C();
    func_80022E80();
    func_8002C2C0();
    func_8002BD8C();
    func_800272B4();
}
