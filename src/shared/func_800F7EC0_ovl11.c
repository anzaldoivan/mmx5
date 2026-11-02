/* Shared body (DK-5), from the banked draft of func_800F7EC0_ovl11 by tools/wave/gate.py rescan. */
#include "types.h"
#include "addr.h"

extern void func_80017248(u8* obj);
extern void func_800F81F4_ovl11(u8* obj);
extern s16 D_800FA056_ovl11;
extern s16 D_800FA058_ovl11;
extern u8 D_800F9D0C_ovl11[];
extern u8 D_800F9EEC_ovl11[][5];

#define G D_1F80004C.bytes
void DEDUP_NAME(u8* obj) {
    u8 v;

    func_80017248(obj);
    if (*(s16*)(obj + 0xA) < D_800FA056_ovl11 - 0x50) {
        *(s16*)(obj + 0xA) += 4;
    } else if (D_800FA058_ovl11 + 0x50 < *(s16*)(obj + 0xA)) {
        *(s16*)(obj + 0xA) -= 4;
    } else {
        *(u8**)(obj + 0x68) = D_800F9D0C_ovl11;
        func_800F81F4_ovl11(obj);
        *(s32*)(obj + 0x20) = 0;
        *(s32*)(obj + 0x24) = 0;
        v = D_800F9EEC_ovl11[0][++G[0x8F] + G[0x8E] * 5];
        obj[6] = 1;
        *(s16*)(obj + 0x7C) = 1;
        obj[5] = v;
    }
}
