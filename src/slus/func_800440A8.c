#include "types.h"
#include "mmx5/globals.h"

extern void func_8003A94C(void);
extern void (*D_80074D64[])(Obj440A8*);

void func_800440A8(Obj440A8* obj) {
    if (obj->unkD3 != 0) {
        func_8003A94C();
        return;
    }
    animate_object(obj);
    D_80074D64[obj->state](obj);
    if (obj->unk5 != 0x37 && obj->unk14B != -1) {
        obj->unk7A = 0;
    }
}
