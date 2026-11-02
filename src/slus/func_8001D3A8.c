#include "types.h"

extern s32 TestEvent(s32);
extern int VSync(int mode);
extern s32 _card_load(s32);
extern s32 func_8001DA18(void);
extern void func_8001DE4C(s32);
extern s32 D_800E81B8;
extern s32 D_800E81BC;
extern s32 D_800E81C0;
extern s32 D_800E81C4;

static inline s32 func_8001D3A8_try(s32 chan) {
    s32 i;
    s32 r;

    i = 3;
    TestEvent(D_800E81B8);
    TestEvent(D_800E81BC);
    TestEvent(D_800E81C0);
    TestEvent(D_800E81C4);
    for (; i != 0; i--) {
        if (_card_load(chan << 4) != 0) {
            r = func_8001DA18();
            if (r == 0) {
                return 0;
            }
        }
    }
    return r;
}

s32 func_8001D3A8(s32 arg0) {
    s32 r;

    r = func_8001D3A8_try(arg0);
    if (r != 2) {
        return r;
    }
    func_8001DE4C(arg0);
    VSync(300);
    r = func_8001D3A8_try(arg0);
    if (r == 2) {
        func_8001DE4C(arg0);
        VSync(300);
        r = func_8001D3A8_try(arg0);
    }
    return r;
}
