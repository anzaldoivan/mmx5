#include "types.h"

extern s32 D_800748D0;
extern s32 D_800748D4;

void func_8003CD08(Obj8003CD08* arg0) {
    if (arg0->unkD5 < 0) {
        arg0->unk68 = 0;
        return;
    }
    if (arg0->unkF8 == 0) {
        if (arg0->unk2 == 0) {
            arg0->unk68 = &D_800748D0;
        } else {
            arg0->unk68 = &D_800748D4;
        }
    }
}
