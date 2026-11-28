#include "types.h"

extern void func_8001A30C(void);
extern void SetDispMask(s32);
extern void DrawSyncCallback(void (*)(void));
extern void func_80012BB4(void);

void func_8001E0D0(void) {
    func_8001A30C();
    SetDispMask(0);
    DrawSyncCallback(func_80012BB4);
}
