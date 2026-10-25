#include "types.h"

extern void func_8001E668(void);
extern void func_8002002C(s32);
extern void func_80013288(s32);
extern s16 func_8001FF18(void*, s32);
extern u8 D_8009A427;
extern u8 D_80070F40[];
extern u8 D_80070F4C[];

void func_80021280(Obj80021650* arg0) {
    func_8001E668();
    D_8009A427 = 0;
    arg0->unk1F = 0;
    arg0->unk24 = 0;
    func_8002002C(0);
    *(s16*)((u8*)arg0 + 4) = 0x78;
    func_80013288(8);
    if (*(s8*)((u8*)arg0 + 0xC) == 0) {
        arg0->unk8 = func_8001FF18(D_80070F40, 1);
        arg0->unk1 += 3;
    } else {
        arg0->unk8 = func_8001FF18(D_80070F4C, 1);
        arg0->unk1 += 1;
    }
}
