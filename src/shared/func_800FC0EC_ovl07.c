/* Shared body (DK-5), from the banked draft of func_800FC0EC_ovl07 by tools/wave/gate.py rescan. */
#include "types.h"
#include "addr.h"

#define ABS(x) ((x) < 0 ? -(x) : (x))

extern void func_80017248(u8* obj);
extern void func_8002DED4(u8* obj);

void DEDUP_NAME(u8* obj) {
    func_80017248(obj);
    func_8002DED4(obj);
    if (ABS(*(s16*)(D_1F80004C.bytes + 0x84) - *(s16*)(obj + 0xE)) < 8) {
        obj[6] = 3;
    }
}
