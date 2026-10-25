#include "types.h"
#include "addr.h"

void func_80017248(u8* obj);
s32 func_80044DE0();
void func_8002C338(s32, void*, s32);
void func_800171E8(u8* obj, s32 state);

void func_800F564C_ovl28(u8* self) {
    func_80017248(self);
    if (*(s16*)(self + 0x7E) != 0) {
        if (func_80044DE0() != 0) {
            return;
        }
        *(s16*)(self + 0x7E) = 0;
    }
    func_8002C338(0x13C, D_1F800030 + 0x60, 1);
    func_8002C338(0x13D, D_1F800030 + 0x80, 1);
    *(s16*)(self + 0x42) = 0x7CCC;
    if (*(s8*)(self + 0x45) == 1) {
        func_800171E8(self, 1);
        *(s16*)(self + 0x7C) = 2;
        self[6]++;
    }
}
