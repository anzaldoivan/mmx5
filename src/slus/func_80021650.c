#include "types.h"

extern void func_8001E668(void);
extern void func_80013288(s32);
extern s16 func_8001FF18(void*, s32);
extern u8 D_8009A427;
extern u8 D_80070F5C[];

void func_80021650(Obj80021650* arg0) {
    func_8001E668();
    D_8009A427 = 1;
    arg0->unk1F = 0;
    arg0->unk24 = 0;
    func_80013288(8);
    arg0->unk8 = func_8001FF18(D_80070F5C, 1);
    arg0->unk1++;
}
