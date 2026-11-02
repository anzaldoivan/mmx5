#include "types.h"

extern s8 D_8009A424;
extern void func_800132F8(s8 arg);
extern void func_80021F10(u8* arg0);
extern void func_800183B4(void);
extern void func_80013288(s32);
extern void func_800272DC(void);

void func_80034D18(u8* o) {
    s32 t;

    t = *(s8*)(o + 6);
    switch (t) {
    case 0:
        func_800132F8(8);
        goto inc; // !FAKE: goto kept for the matching branch layout
    case 1:
        if (D_8009A424 == 0) {
            o[6]++;
        }
        goto call; // !FAKE: goto kept for the matching branch layout
    case 2:
        func_80021F10(o);
        break;
    case 3:
        func_800183B4();
        func_80013288(8);
    inc:
        t = o[6];
        t++;
        o[6] = t;
    call:
        func_800272DC();
        break;
    case 4:
        if (D_8009A424 == 0) {
            o[6] = 0;
            o[5] = o[0x30];
        } else {
            func_800272DC();
        }
        break;
    }
}
