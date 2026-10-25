#include "types.h"

extern Obj8002CC08 D_80098120[];
extern s32 func_8002E804(u8*, u8*);
extern void func_80031C38(u8*, Obj8002CC08*, u8*, u8*);
extern s32 func_80031F60(u8*, Obj8002CC08*);

s32 func_80032F70(u8* arg0) {
    Obj8002CC08* p;
    s32 v;

    for (p = D_80098120; p < D_80098120 + 32; p++) {
        if (p->active != 0 && func_8002E804((u8*)p, arg0) != 0) {
            func_80031C38(arg0, p, (u8*)p + 0x80, (u8*)p + 0x82);
            v = func_80031F60(arg0, p);
            if (v == 0x7E) {
                return 0;
            }
            if (v != 0) {
                return v;
            }
        }
    }
    arg0[0x65] = 0;
    return 0;
}
