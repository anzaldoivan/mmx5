#include "types.h"

extern void (*D_8007115C[])(u8*);
extern void func_800231B4(void);
extern void func_80027120(void);
extern void func_800176DC(void);

void func_80021F10(u8* arg0) {
    D_8007115C[*(signed char*)(arg0 + 7)](arg0);
    func_800231B4();
    func_80027120();
    func_800176DC();
}
