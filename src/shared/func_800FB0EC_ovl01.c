/* Shared body (DK-5), from the banked draft of func_800FB0EC_ovl01 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_80017248(u8* obj);
extern void func_8002DED4(u8* obj);
extern void func_8001296C(s32);
extern void func_80016490(s32, s32, void*);
extern void func_8002A600(s32, s32, s32);

void DEDUP_NAME(u8* obj) {
    func_80017248(obj);
    func_8002DED4(obj);
    if ((obj[0x70] & 8) && *(s32*)(obj + 0x24) < 0) {
        func_8001296C(5);
        func_80016490(2, 7, obj);
        func_8002A600(0x14, 3, 2);
        *(s32*)(obj + 0x24) = 0x10000;
        *(s32*)(obj + 0x2C) = 0x2000;
        obj[6] = 3;
        *(u16*)(obj + 0xE) -= 4;
    }
}
