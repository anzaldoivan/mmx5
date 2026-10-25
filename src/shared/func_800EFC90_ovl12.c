/* Shared body (DK-5), from the banked draft of func_800EFC90_ovl12 by tools/wave/gate.py rescan. */
#include "types.h"

extern D_8009A1F8_t D_8009A1F8;
extern signed char D_800D1CA2;
extern u16 D_800F2100_ovl12;
extern s32 func_80044DE0();
extern void func_8002D9EC(EntFC90* obj, s32 a, s32 b);
extern s32 func_80016490(s32, s32, s32);
extern void func_8003D2C4(void);
extern void func_80017248(EntFC90*);
extern void func_8002DED4(EntFC90*);

void DEDUP_NAME(EntFC90* obj) {
    if (func_80044DE0()) {
        func_8002D9EC(obj, 0x40, 0x40);
        return;
    }
    D_8009A1F8.unk26 = obj->unk94;
    if (obj->unk5C < D_800D1CA2) {
        if (--obj->unk7C == 0) {
            func_80016490(0, 0xE, 0);
            obj->unk7C = 3;
        }
        obj->unk5C++;
        func_8002D9EC(obj, 0x40, 0x40);
        return;
    }
    D_8009A1F8.unk48 = 8;
    func_8003D2C4();
    func_80017248(obj);
    func_8002DED4(obj);
    func_8002D9EC(obj, 0x40, 0x40);
    D_800F2100_ovl12 = obj->unkE;
    obj->unk5 = 4;
    obj->unk6 = 0;
}
