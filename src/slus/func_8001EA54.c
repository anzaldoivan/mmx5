#include "types.h"

extern s8 D_8009A424;
extern s8 D_8009A0A0[];
extern void func_800132F8(s8 arg);
extern s32 func_80023728(void);
extern s32 func_8002DF78(void);
extern void func_800235DC(void);
extern void func_800272B4(void);

void func_8001EA54(u8* arg0) {
    if (D_8009A424 == 0) {
        arg0[0xD] = 0;
    }
    if (--*(s16*)(arg0 + 4) == 0 || D_8009A0A0[0] == 0 || D_8009A0A0[4] == 3) {
        func_800132F8(8);
        func_80023728();
        arg0[1]++;
    } else {
        func_8002DF78();
        func_800235DC();
    }
    func_800272B4();
}
