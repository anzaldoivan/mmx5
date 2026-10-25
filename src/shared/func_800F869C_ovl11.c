/* Shared body (DK-5), from the banked draft of func_800F869C_ovl11 by tools/wave/gate.py rescan. */
#include "types.h"

extern u8 D_8009A197;
extern void (*D_800FA02C_ovl11[])(u8*);
extern s32 func_80031DD0(u8* a0);
extern void func_800317B8(u8* a0);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);

void DEDUP_NAME(u8* obj) {
    if (*(signed char*)(obj + 2) == 0) {
        func_80031DD0(obj);
    }
    func_800317B8(obj);
    if (D_8009A197 == 0) {
        D_800FA02C_ovl11[*(signed char*)(obj + 5)](obj);
    }
    func_8002D9EC(obj, 0x60, 0x60);
}
