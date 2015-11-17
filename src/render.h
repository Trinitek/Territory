
#ifndef _RENDER_H_
#define _RENDER_H_

#define DEFAULT_WIN_WIDTH 800
#define DEFAULT_WIN_HEIGHT 600

#ifndef _RENDER_PROC_

void render_main(void* arg);

#else
#undef _RENDER_PROC_
#endif

#endif
