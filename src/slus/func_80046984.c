#include "types.h"

extern s32 func_8002D938(u8* a0, s32 a1, s32 a2);
extern void func_80046A40(u8* a0);
extern void func_80017248(u8* obj);
extern void func_8002DF54(u8* a0);
extern s32 func_8002F8FC(u8* a0);
extern void func_80044F78(void* arg0);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);

void func_80046984(u8* a0) {
    if (func_8002D938(a0, 0x20, 0x20) == 0) {
        if (*(s8*)(a0 + 0x98) != 0) {
            func_80046A40(a0);
        } else {
            func_80017248(a0);
            func_8002DF54(a0);
            if (a0[0x70] == 0) {
                func_8002F8FC(a0);
            }
            if (a0[0x70] != 0) {
                func_80044F78(a0);
                func_80046A40(a0);
            }
            func_8002D9EC(a0, 0x20, 0x20);
        }
    } else {
        func_80046A40(a0);
    }
}
