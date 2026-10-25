#include "types.h"

extern void func_8003763C(u8* arg0);
extern void func_8003CEDC(u8* arg0, s32 arg1);
extern void func_8003C5D8(u8* obj);
extern void func_8003AA4C(u8* arg0);
extern void func_8003CFA8(u8* arg0);

void func_80037330(u8* arg0) {
    func_8003763C(arg0);
    if (((s8*)arg0)[2] == 0) {
        if (arg0[0x47] == 0xEC) {
            func_8003CEDC(arg0, 0x52);
        } else {
            func_8003C5D8(arg0);
        }
    }
    if (((s8*)arg0)[0x61] == 0x3C) {
        func_8003AA4C(arg0);
        if (((s8*)arg0)[0xD3] != 0) {
            arg0[0xA4] = 0;
            arg0[0x61] = 0;
        } else {
            func_8003CFA8(arg0);
            ((s8*)arg0)[0xA4] = -1;
        }
    }
}
