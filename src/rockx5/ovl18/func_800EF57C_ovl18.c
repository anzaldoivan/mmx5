#include "types.h"

s32 func_800EF57C_ovl18(Obj800EF57C* arg0, Obj800EF57C* arg1) {
    Hit800EF57C* h1;
    Hit800EF57C* h0;
    u16 x1;
    u8 w1;
    u8 w0;
    s16 y0;
    s16 y1;
    s16 d;
    s16 r;

    h1 = arg1->hit;
    if (h1 == 0) {
        return 0;
    }
    h0 = arg0->hit;
    w0 = h0->w;
    w1 = h1->w;
    x1 = arg1->x;
    r = arg0->x - (w0 - 0x10);
    if (r > (s16)(x1 - w1)) {
        return 0;
    }
    r = arg0->x + (w0 - 0x10);
    if (r < (s16)(x1 + w1)) {
        return 0;
    }
    y0 = arg0->y + h0->y;
    y1 = arg1->y + h1->y;
    d = (y0 - y1) < 0 ? (y1 - y0) : (y0 - y1);
    return ((volatile Obj800EF57C*)arg0)->hit->h + arg1->hit->h >=
           d; // !FAKE: volatile read keeps the target's reload
}
