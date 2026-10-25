/* Shared body (DK-5), from the banked draft of func_800FC718_ovl07 by tools/wave/gate.py rescan. */
#include "types.h"
#include "addr.h"

extern void func_800171E8(u8* obj, s32 state);
extern void func_80017248(u8* obj);

void DEDUP_NAME(u8* obj) {
    if (--*(s16*)(obj + 0x7C) == -1) {
        switch (D_1F80004C.bytes[0x90]) {
        case 0:
            func_800171E8(obj, 0x15);
            break;
        case 1:
            func_800171E8(obj, 0x15);
            break;
        case 2:
            func_800171E8(obj, 0x13);
            break;
        }
        obj[6]++;
    } else {
        func_80017248(obj);
    }
}
