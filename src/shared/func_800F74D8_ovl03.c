/* Shared body (DK-5), from the banked draft of func_800F74D8_ovl03 by tools/wave/gate.py rescan. */
#include "types.h"

extern void (*D_800FA0EC_ovl03[])(u8*);
extern void func_800F866C_ovl03(u8* obj);
extern s32 func_8002FB58(u8* obj);

void DEDUP_NAME(u8* arg0) {
    if (((signed char*)arg0)[2] != 0) {
        func_800F866C_ovl03(arg0);
        return;
    }
    *(s32*)(arg0 + 0x18) = *(s32*)(arg0 + 0x8);
    *(s32*)(arg0 + 0x1C) = *(s32*)(arg0 + 0xC);
    arg0[3] = 0;
    D_800FA0EC_ovl03[((signed char*)arg0)[4]](arg0);
    func_8002FB58(arg0);
}
