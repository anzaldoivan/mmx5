#include "types.h"

extern s32 func_8002D938(u8* a0, s32 a1, s32 a2);
extern void func_80017248(u8* obj);
extern void func_8002DF54(u8* a0);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern s32 func_8002F8FC(u8* a0);
extern void func_80044F78(void* arg0);

void func_8004607C(u8* a0) {
    if (func_8002D938(a0, 0x20, 0x14) == 0 && *(s8*)(a0 + 0x98) == 0) {
        func_80017248(a0);
        func_8002DF54(a0);
        func_8002D9EC(a0, 0x20, 0x14);
        if (a0[0x70] == 0) {
            func_8002F8FC(a0);
            if (a0[0x70] == 0) {
                return;
            }
        }
        func_80044F78(a0);
    }
    a0[3] = 0;
    a0[4] = 3;
    *(s32*)(a0 + 0x50) = 0;
    *(s32*)(a0 + 0x68) = 0;
}
