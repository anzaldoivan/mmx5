#include "types.h"

extern void func_80017248(u8* obj);
extern void func_8002DF54(u8* a0);
extern s32 func_800317B8(u8* a0);
extern s32 func_80031DD0(u8* a0);
extern s32 func_8004FC64(u8* a0);
extern s32 func_8002D938(u8* a0, s32 a1, s32 a2);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);

void func_800FFC00_ovl04(u8* a0) {
    func_80017248(a0);
    func_8002DF54(a0);
    func_800317B8(a0);
    if (func_80031DD0(a0) < 0) {
        func_8004FC64(a0);
        a0[4]++;
    } else if (func_8002D938(a0, 0x40, 0x40) == 0) {
        func_8002D9EC(a0, 0x10, 0x10);
    } else {
        a0[4]++;
    }
}
