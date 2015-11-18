
#ifndef _EVENT_H_
#define _EVENT_H_

#ifndef _EVENT_PROC_

    void event_main(void* arg);

#endif

#ifdef _EVENT_PROC_
#undef _RENDER_PROC_
#endif

#endif
