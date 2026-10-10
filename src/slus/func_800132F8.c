/* T4 probe: signed-char guard then a call (slus game_80011DC8). */
#include "types.h"

extern Ctl D_8009A420;
extern void func_80012E0C(s32, void (*)(void));
extern void func_8001303C(void);

void func_800132F8(s8 arg) {
    if (D_8009A420.busy == 0) {
        D_8009A420.busy = -1;
        D_8009A420.arg = arg;
        func_80012E0C(2, func_8001303C);
    }
}
