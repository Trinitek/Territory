
#ifndef _RENDER_H_
#define _RENDER_H_

#define DEFAULT_WIN_WIDTH 800
#define DEFAULT_WIN_HEIGHT 600

void closeMainWindow(void);

#ifndef _RENDER_PROC_

extern volatile sfEvent event;
extern volatile sfBool eventAvailable;

void render_main(void* arg);

#else
#undef _RENDER_PROC_
#endif

#endif
