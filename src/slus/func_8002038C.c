/* Dedup member (tools/dedup/propagate.py): cyclic rename, body inlined. */
#include "types.h"

#define DEDUP_NAME func_8002038C

// dedup-inline ../shared/func_8001F314.c
// dedup-rename D_80070F2C D_80071074
// dedup-rename func_800223E4 func_80022618
// dedup-rename func_80022618 func_8002C2C0
// dedup-rename func_8002272C func_8002BD8C
// dedup-rename func_800272B4 func_800176DC
// dedup-rename func_8002BD8C func_800272B4

/* Shared body (DK-5), from the banked draft of func_8001F314 by tools/wave/gate.py rescan. */
#include "types.h"

extern void (*D_80071074[])(u8*);
extern void func_80022618(void);
extern void func_8002C2C0(void);
extern void func_8002BD8C(void);
extern void func_800272B4(void);
extern void func_800176DC(void);

void DEDUP_NAME(u8* arg0) {
    D_80071074[*(signed char*)(arg0 + 1)](arg0);
    func_80022618();
    func_8002C2C0();
    func_8002BD8C();
    func_800272B4();
    func_800176DC();
}
