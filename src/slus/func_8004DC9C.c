#include "types.h"

extern s32 func_8002D938(u8* a0, s32 a1, s32 a2);
extern int func_8002D6FC();
extern void func_80017248(u8* obj);
extern void func_8002DF54(u8* a0);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);

void func_8004DC9C(u8* a0) {
    if ((((s8*)a0)[2] & 0x80) && func_8002D938(a0, 0x80000, 0x80000) == 1) {
        func_8002D6FC(a0);
        return;
    }
    func_80017248(a0);
    func_8002DF54(a0);
    func_8002D9EC(a0, 0x80000, 0x80000);
}
