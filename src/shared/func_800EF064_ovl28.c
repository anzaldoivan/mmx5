#include "types.h"

extern u8 D_8009A197;
extern void (*D_800FD264_ovl28[])(Obj800EF064*);

void func_800EF064_ovl28(Obj800EF064* obj) {
    if (D_8009A197 == 0) {
        D_800FD264_ovl28[obj->state](obj);
        obj->timer++;
    }
}
