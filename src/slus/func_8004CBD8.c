#include "types.h"

extern void (*D_800774D8[])(u8*);
extern void func_8002FB58(u8*);
extern void func_80017348(u8* a0, s32 a1, s32 a2);

void func_8004CBD8(u8* arg0) {
    D_800774D8[(signed char)arg0[5]](arg0);
    func_8002FB58(arg0);
    func_80017348(arg0, 0x140, 0x40);
}
