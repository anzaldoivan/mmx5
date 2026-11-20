#include "types.h"
#include "mmx5/globals.h"

extern void func_8003A94C(void);
extern void (*D_80074D10[])(Obj440A8*);

void func_80040350(Obj440A8* obj) {
    if (obj->unkD3 != 0) {
        func_8003A94C();
        return;
    }
    animate_object(obj);
    D_80074D10[obj->state](obj);
    if (obj->unk5 != 0x23) {
        obj->unk7A = 0;
    }
}
