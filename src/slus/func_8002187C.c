#include "types.h"

extern void func_8001E668(void);
extern void func_8002002C(s32);
extern void func_80013288(s32);
extern s16 func_8001FF18(void*, s32);
extern u8 D_8009A427;
extern u8 D_80070F68[];

void func_8002187C(Obj80021650* arg0) {
    func_8001E668();
    D_8009A427 = 0;
    arg0->unk1F = 0;
    arg0->unk24 = 0;
    func_8002002C(0);
    func_80013288(8);
    arg0->unk8 = func_8001FF18(D_80070F68, 1);
    arg0->unk1++;
}
