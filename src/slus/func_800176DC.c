#include "types.h"
#include "addr.h"

extern s8 D_8009A0A2;
extern u8 D_800B4958[];
extern void func_80016E78(s32, s32, s32, s32, u8*);

void func_800176DC(void) {
    u8* p;
    s32 n;

    p = D_800B4958 + D_1F800000 * 0xA000;
    n = 8;
    if (D_8009A0A2 == 1) {
        n = 0x11;
    }
    func_80016E78(0, 0x80, 0x78, n, p);
    func_80016E78(0, 0x120, 0x78, n, p);
}
