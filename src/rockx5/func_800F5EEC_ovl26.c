#include "types.h"

extern void func_80017248(u8* obj);
extern void func_8002DF54(u8* a0);
extern s32 func_8002D938(u8* a0, s32 a1, s32 a2);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);

void func_800F5EEC_ovl26(u8* obj) {
    func_80017248(obj);
    func_8002DF54(obj);
    if (func_8002D938(obj, 0x80, 0x80) == 0) {
        func_8002D9EC(obj, 0x60, 0x60);
    } else {
        obj[4] = 2;
    }
}
