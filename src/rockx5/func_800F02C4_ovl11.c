#include "types.h"

extern void func_80017248(u8* obj);
extern void func_8002DF54(u8* a0);
extern s32 func_8002D800(u8* a0);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern int func_8002D6FC();

void func_800F02C4_ovl11(u8* obj) {
    func_80017248(obj);
    if (obj[0x47] >= 12) {
        func_8002DF54(obj);
    }
    if (func_8002D800(obj) == 0) {
        func_8002D9EC(obj, 0x20, 0x20);
    } else {
        func_8002D6FC(obj);
    }
}
