/* Shared body (DK-5), from the banked draft of func_80021828 by tools/wave/gate.py rescan. */
#include "types.h"

extern void (*D_8007110C[])(u8*);
extern void func_80022618(void);
extern void func_80024698(void);
extern void func_800176DC(void);

void DEDUP_NAME(u8* arg0) {
    D_8007110C[*(signed char*)(arg0 + 1)](arg0);
    func_80022618();
    func_80024698();
    func_800176DC();
}
