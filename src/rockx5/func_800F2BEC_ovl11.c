#include "types.h"

extern void func_80017248(Ob5*);

void func_800F2BEC_ovl11(Ob5* o) {
    func_80017248(o);
    if (o->b45 != 0) {
        o->b6++;
    }
}
