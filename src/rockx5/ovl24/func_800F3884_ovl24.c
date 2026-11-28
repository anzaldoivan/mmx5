#include "types.h"
#include "mmx5/globals.h"

extern s32 func_8001D7E8(u8);
extern s32 func_800F3968_ovl24(u8*, u8, s32);
extern void func_800F3988_ovl24(u8*);
extern u8 D_8009A427;
extern Rgb800F3884 D_800EE988_ovl24;

void func_800F3884_ovl24(u8* obj) {
    u8 id;
    u8* buf;
    u8* p;
    s32 i;

    buf = *(u8**)obj;
    id = obj[6];
    p = buf;
    for (i = 0; i < 0x200; i++) {
        *p++ = 0;
    }
    *(Rgb800F3884*)*(u8**)obj = D_800EE988_ovl24;
    (*(u8**)obj)[2] = 0x13;
    obj[8] = func_8001D7E8(id);
    if (obj[8] == 0) {
        func_800F3988_ovl24(obj);
        obj[8] = func_800F3968_ovl24(buf, id, 0x2000);
        if (obj[8] == 0) {
            return;
        }
    }
    g_playthrough_state.u[1] = 0xA;
    ((s32(*)())func_8002C50C)();
    D_8009A427 = 0;
    g_playthrough_state.u[3] = 0xD;
}
