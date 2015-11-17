
#ifndef _EVENT_H_
#define _EVENT_H_

#ifndef _EVENT_PROC_

void event_main(void* arg);

#else
#undef _EVENT_PROC_
#endif

#endif
