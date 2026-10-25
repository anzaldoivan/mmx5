/* Shared body (DK-5), from the banked draft of func_800EF064_ovl28 by tools/wave/gate.py rescan. */
#include "types.h"

extern u8 D_8009A197;
extern void (*D_800FD264_ovl28[])(Obj800EF064*);

void DEDUP_NAME(Obj800EF064* obj) {
    if (D_8009A197 == 0) {
        D_800FD264_ovl28[obj->state](obj);
        obj->timer++;
    }
}
