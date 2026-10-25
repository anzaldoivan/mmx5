#include "types.h"
#include "addr.h"

extern s32 func_8006C3B8();
extern s32 CloseTh(s32);
extern s32 func_8006C3C8();
extern void ChangeTh(s32);

void func_80012EAC(void) {
    *(s16*)D_801F8300 = 0;
    func_8006C3B8();
    CloseTh(*(s32*)(D_801F8300 + 8));
    func_8006C3C8();
    ChangeTh(0xFF000000);
}
