#ifndef EVENTLOOP_EVENT_H
#define EVENTLOOP_EVENT_H

#define EVENT_CALLBACK(name) int name(void *context, int param1, void *param2)
typedef EVENT_CALLBACK(event_callback);

static EVENT_CALLBACK(EVENT_HANDLER_APPLICATION_LAUNCHED);
static EVENT_CALLBACK(EVENT_HANDLER_APPLICATION_TERMINATED);
static EVENT_CALLBACK(EVENT_HANDLER_APPLICATION_FRONT_SWITCHED);
static EVENT_CALLBACK(EVENT_HANDLER_APPLICATION_ACTIVATED);
static EVENT_CALLBACK(EVENT_HANDLER_APPLICATION_DEACTIVATED);
static EVENT_CALLBACK(EVENT_HANDLER_APPLICATION_VISIBLE);
static EVENT_CALLBACK(EVENT_HANDLER_APPLICATION_HIDDEN);
static EVENT_CALLBACK(EVENT_HANDLER_WINDOW_CREATED);
static EVENT_CALLBACK(EVENT_HANDLER_WINDOW_DESTROYED);
static EVENT_CALLBACK(EVENT_HANDLER_WINDOW_FOCUSED);
static EVENT_CALLBACK(EVENT_HANDLER_WINDOW_MOVED);
static EVENT_CALLBACK(EVENT_HANDLER_WINDOW_RESIZED);
static EVENT_CALLBACK(EVENT_HANDLER_WINDOW_MINIMIZED);
static EVENT_CALLBACK(EVENT_HANDLER_WINDOW_DEMINIMIZED);
static EVENT_CALLBACK(EVENT_HANDLER_WINDOW_TITLE_CHANGED);
static EVENT_CALLBACK(EVENT_HANDLER_SPACE_CHANGED);
static EVENT_CALLBACK(EVENT_HANDLER_DISPLAY_ADDED);
static EVENT_CALLBACK(EVENT_HANDLER_DISPLAY_REMOVED);
static EVENT_CALLBACK(EVENT_HANDLER_DISPLAY_MOVED);
static EVENT_CALLBACK(EVENT_HANDLER_DISPLAY_RESIZED);
static EVENT_CALLBACK(EVENT_HANDLER_DISPLAY_CHANGED);
static EVENT_CALLBACK(EVENT_HANDLER_MOUSE_DOWN);
static EVENT_CALLBACK(EVENT_HANDLER_MOUSE_UP);
static EVENT_CALLBACK(EVENT_HANDLER_MOUSE_DRAGGED);
static EVENT_CALLBACK(EVENT_HANDLER_MOUSE_MOVED);
static EVENT_CALLBACK(EVENT_HANDLER_MISSION_CONTROL_ENTER);
static EVENT_CALLBACK(EVENT_HANDLER_MISSION_CONTROL_CHECK_FOR_EXIT);
static EVENT_CALLBACK(EVENT_HANDLER_MISSION_CONTROL_EXIT);
static EVENT_CALLBACK(EVENT_HANDLER_DOCK_DID_RESTART);
static EVENT_CALLBACK(EVENT_HANDLER_MENU_OPENED);
static EVENT_CALLBACK(EVENT_HANDLER_MENU_BAR_HIDDEN_CHANGED);
static EVENT_CALLBACK(EVENT_HANDLER_SYSTEM_WOKE);
static EVENT_CALLBACK(EVENT_HANDLER_DAEMON_MESSAGE);

#define EVENT_IGNORED   -1
#define EVENT_QUEUED     0
#define EVENT_PROCESSED  1

#define EVENT_SUCCESS      0
#define EVENT_MOUSE_IGNORE 1

struct event
{
    event_callback *handler;
    void *context;
    int param1;
    void *param2;
    volatile int *status;
    volatile int *result;
};

#define event_create(e, t, d)\
    do {\
        e = malloc(sizeof(struct event));\
        e->context = d;\
        e->handler = &EVENT_HANDLER_##t;\
        e->param1 = 0;\
        e->param2 = 0;\
        e->status = 0;\
        e->result = 0;\
    } while (0)

#define event_create_p2(e, t, d, p1, p2)\
    do {\
        e = malloc(sizeof(struct event));\
        e->context = d;\
        e->handler = &EVENT_HANDLER_##t;\
        e->param1 = p1;\
        e->param2 = p2;\
        e->status = 0;\
        e->result = 0;\
    } while (0)

#endif