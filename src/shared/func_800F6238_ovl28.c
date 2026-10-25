/* Shared body (DK-5), from the banked draft of func_800F6238_ovl28 by tools/wave/gate.py rescan. */
#include "types.h"
#include "addr.h"

extern void func_80017248(u8* obj);
extern void func_800F6A8C_ovl28(u8* obj);
extern u8 D_800FE198_ovl28[][3];

#define G D_1F80004C.bytes
void DEDUP_NAME(u8* obj) {
    func_80017248(obj);
    if ((s8)obj[0x45] == 1) {
        func_800F6A8C_ovl28(obj);
        obj[5] = D_800FE198_ovl28[0][++G[0x8A] + G[0x89] * 3];
        obj[6] = 0;
    }
}
