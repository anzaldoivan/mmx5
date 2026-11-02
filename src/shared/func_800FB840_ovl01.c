/* Shared body (DK-5), from the banked draft of func_800FB840_ovl01 by tools/wave/gate.py rescan. */
#include "types.h"

extern void func_80017248(u8* obj);
extern void func_8002DF54(u8* a0);
extern s32 func_800317B8(u8* a0);
extern s32 func_8002E274(u8* a0, u8* a1);
extern s32 func_80031DD0(u8* a0);
extern s32 func_8004FC64(u8* a0);
extern s32 func_8002F8FC(u8* a0);
extern s32 func_8002D938(u8* a0, s32 a1, s32 a2);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern u8 D_8009A0A0[];

void DEDUP_NAME(u8* obj) {
    func_80017248(obj);
    func_8002DF54(obj);
    func_800317B8(obj);
    if (func_8002E274(obj, D_8009A0A0) == 0) {
        if (*(s8*)(obj + 2) < 3 && (func_80031DD0(obj) < 0 || obj[0x70] != 0)) {
            func_8004FC64(obj);
            obj[4] = 2;
            return;
        }
        func_8002F8FC(obj);
        if (func_8002D938(obj, 0x60, 0x20) == 0) {
            func_8002D9EC(obj, 0x60, 0x20);
            return;
        }
    }
    obj[4] = 2;
}
