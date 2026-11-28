#include "types.h"
#include "mmx5/globals.h"

extern void task_yield(s32);
extern void* g_playthrough_state_handlers[];

void func_80020904(void) {
    s32 state;

    while (1) {
        state = g_playthrough_state.s[0];
        ((void (*)(s8*))g_playthrough_state_handlers[state])(
            g_playthrough_state.s);
        task_yield(1);
    }
}
