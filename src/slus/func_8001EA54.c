#include "types.h"
#include "mmx5/system.h"
#include "mmx5/globals.h"
#define g_Player_as_s8 ((s8*)g_Player)

extern s8 D_8009A424;
extern void func_800132F8(s8 arg);
extern s32 func_80023728(void);
extern void func_800235DC(void);
extern void func_800272B4(void);

void func_8001EA54(u8* arg0) {
    if (D_8009A424 == 0) {
        arg0[0xD] = 0;
    }
    if (--*(s16*)(arg0 + 4) == 0 || g_Player_as_s8[0] == 0 ||
        g_Player_as_s8[4] == 3) {
        func_800132F8(8);
        func_80023728();
        arg0[1]++;
    } else {
        random_byte();
        func_800235DC();
    }
    func_800272B4();
}
