#include "types.h"

extern void func_80016490(s32, s32, void*);
extern void func_80022618(void);
extern void func_8002272C(void);
extern void func_80024698(void);
extern void func_800176DC(void);
extern signed char D_800D1C01;
extern u8 D_8009A420[];
extern void (*D_80070E84[])(u8*);
extern u16 D_800C9320;

void func_8001DAB8(u8* a0) {
    s32 old;

    if (D_800D1C01 != 0) {
        old = D_8009A420[7];
    } else {
        old = 0;
    }
    D_80070E84[((s8*)a0)[1]](a0);
    if (D_8009A420[7] != old && !(D_800C9320 & 0x50)) {
        func_80016490(0, 0xC, 0);
    }
    func_80022618();
    func_8002272C();
    func_80024698();
    func_800176DC();
}
