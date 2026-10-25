#include "types.h"

extern s32 func_8002D938(u8* a0, s32 a1, s32 a2);
extern void func_80017248(u8* obj);
extern void func_8002DF54(u8* a0);
extern s32 D_8009A420;

void func_80046258(u8* self) {
    if (func_8002D938(self, 0x20, 0x20) == 0) {
        func_80017248(self);
        func_8002DF54(self);
        if ((D_8009A420 & 3) == 0) {
            self[0x64]++;
        }
        return;
    }
    self[3] = 0;
    self[4] = 2;
    *(s32*)(self + 0x50) = 0;
}
