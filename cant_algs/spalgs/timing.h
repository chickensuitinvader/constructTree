#ifndef TIMING_H
#define TIMING_H
//#include <sys/ctime>
#include <sys/time.h>
#include <time.h>
/* Timing Library (for measuring algorithm running time)
 * ----------------------------------------------------------------------------
 * Author:  Shane Saunders
 */
 
/* This file provides a timing object and related functions which can be
 * used when timing multiple algorithms.  These functions keep the code tidy
 * and make modification easier.  The main use is for summing up, dividing,
 * then reporting the average for each time measurement.  A single timer
 * is also provided for simple time measurements.
 */ 

/*--- Settings --------------------------------------------------------------*/

/* This file allows the user to specify the clock function that clockval()
 * points to:
 *     (default)      clock()         - ANSI C clock() function.
 *     USE_PTIME      gethrvtime()    - High resolution time in nanoseconds
 *                                      when ptime utility is used.  (Solaris)
 *     USE_REALTIME   realclock()     - Wrapper for the gettimeofday()
 *                                      function.  Returns a high resolution
 *                                      value for real time in microseconds.
 */
/* Use a 1 to select a platform specific clock function.  The standard
 * ANSI clock() function will be used if no specialised clock is selected.
 */
#if defined (__SVR4) && defined (__sun)

/* Solaris */
#define USE_PTIME 1
#define USE_USERTIME 0
#define USE_REALTIME 0

#else  /* All other operating systems. */

#define USE_PTIME 0  // (= 0) Available under Solaris only (see above)
#define USE_USERTIME 1
#define USE_REALTIME 0
#endif

/*--- Type definitions ------------------------------------------------------*/

/* Define the type for ClockValue depending on which clock function is
 * selected.
 */
#if USE_PTIME
typedef hrtime_t ClockValue;
#elif USE_USERTIME
typedef clock_t ClockValue;
#elif USE_REALTIME
typedef long ClockValue;
#else
typedef clock_t ClockValue;
#endif

/*--- Global constants (defined in timing.c) --------------------------------*/

/* --- readclock() ---
 * This returns the current clock time as a ClockValue type.
 */
extern ClockValue (*readclock)(void);

/* --- CLOCK_SECOND ---
 * Number of ClockValue clock ticks per second.
 */
extern const ClockValue CLOCK_SECOND;

/*--- Classes ---------------------------------------------------------------*/

/* --- Timer ---
 * Class for timer objects.  A timer object has the following methods.
 * reset() - Reset the total accumulated time on the timer to zero.
 * start() - Start the timer.
 * stop()  - Stop the timer.  This does not reset the total accumulated time on
 *           the timer.  The elapsed time is taken as the time since the last
 *           call to either start() or stop() and is added to the total
 *           accumulated time whenever timer_stop() is called.  The elapsed
 *           time is returned in ClockValue units.
 * total() - Return the total accumulated time on the timer in ClockValue
 *           units.
 * print() - Print the total accumulated time divided by div in milliseconds.
 *           The divisor div allows the user to print out an average or scale
 *           the measurement to some other units.  The value is printed
 *           according to the printf() format specifier in the string pointed
 *           to by fmt.
 */
class Timer {
  public:
    void reset();
    void start();
    ClockValue stop();
    ClockValue total() const;
    void print(char *fmt, int div) const;
  private:
    ClockValue startTime, totalTime;
};

/* --- Timings ---
 * Class for recording multiple time measurements.  A timings object is is used
 * for storing n independent time measurements.  The time measurement that a
 * method acts upon is identified using an index i, which ranges between 0
 * and n-1.  The user is responsible for passing valid indexes to methods since
 * no bounds checking is performed.
 * reset()
 * - Reset all measurements to zero.
 * restetSingle()
 * - Reset measurement i to zero.
 * start()
 * - Start the timer.
 * stop()
 * - Stop the timer and add the elapsed time to the total accumulated time on
 *   measurement i.  The elapsed time is taken as the time since the last call
 *   to start() or stop() and is added to the total accumulated time whenever
 *   stop() is called.  Additionally, the elapsed time is returned in
 *   ClockValue units.
 * total()
 * - Return the total accumulated time on measurement i.
 * print()
 * - Print all measurements.  This prints the total accumulated time divided
 *   by div in milliseconds.  The divisor div allows the user to print out an
 *   average or scale the measurement to some other units. The time values are
 *   printed in index order according to the printf() format specifier in the
 *   string pointed to by fmt.  The format specifier supplied must be
 *   appropriate for a floating point value, and is allowed to include
 *   separator characters.  For example "\t%.2f" will print values to two
 *   decimal places, with each separated by a tab character.
 * printSingle()
 * - For measurement i in the timing structure pointed to by t, print the total
 *   accumulated time divided by div in milliseconds.  The divisor div allows
 *   the user to print out an average or scale the measurement to some other
 *   units.  The time value is printed according to the printf() format
 *   specifier in the string pointed to by fmt.  The format specifier supplied
 *   must be appropriate for a floating point value.
 * sub()
 * - Specialised function used for subtracting a fixed amount from all time
 *   measurements in the timing structure pointed to by t.  This subtracts the
 *   elapsed time from the total accumulated time for each measurement.  The
 *   elapsed time is taken as the last call to either start(), stop(),
 *   or sub().
 *
 *   This can be used for discarding overhead from time from measurements.
 *   After calling start(), a dummy calculation involving only overhead can be
 *   run and then sub() called.
 *
 */
class Timings {
  public:
    Timings(int n);
    ~Timings();
    void reset();
    void resetSingle(int i);
    void start();
    ClockValue stop(int i);
    ClockValue total(int i) const;
    double average(int i) const;
    void print(char *fmt, int div) const;
    void printSingle(int i, char *fmt, int div) const; 
    ClockValue sub();
    
  private:
    int nItems;  /* Number of separate time measurements held. */
    ClockValue *totals;  /* Array for holding each time measurement. */
    int *samples;  /* Array holding number of samples used for each time
                    * measurement
                    */
    ClockValue startTime;
};

/*---------------------------------------------------------------------------*/
#endif /* TIMING_H */
