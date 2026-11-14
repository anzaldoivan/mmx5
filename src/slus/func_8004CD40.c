/* slus func_8004CD40: twin of func_800462D4 (dup1200), counter at +0xA6. */
#include "types.h"

extern int func_8002D6FC();
extern u8 D_8009A0A0[];

void func_8004CD40(s8* e) {
    D_8009A0A0[0xA6]--;
    func_8002D6FC(e);
}
