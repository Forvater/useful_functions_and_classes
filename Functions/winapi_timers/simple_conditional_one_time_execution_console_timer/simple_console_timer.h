#ifndef SIMPLE_CONSOLE_TIMER_H
#define SIMPLE_CONSOLE_TIMER_H

struct TimerParams {
  unsigned int time_to_elapse;
  bool (*conditional_proc)();
  void (*callback_proc)();
};

// executes callback_proc after time_to_elapse if
// result of conditional_proc is true
void SetSimpleTimer(unsigned int time_to_elapse,
                    bool (*conditional_proc)(),
                    void (*callback_proc)());
#endif
