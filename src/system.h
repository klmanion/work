/** system.h: defines for system-dependent headers */

#ifndef _SYSTEM_H_
#define _SYSTEM_H_

#ifdef HAVE_CONFIG_H
# include "config.h"
#else /* !HAVE_CONFIG_H */
# error "Autotools generatd config.h is missing"
#endif /* HAVE_CONFIG_H */

#if defined HAVE_NCURSESW_CURSES_H
# define NCURSES_INCL <ncursesw/curses.h>

#elif defined HAVE_NCURSESW_H
# define NCURSES_INCL <ncursesw.h>

#elif defined HAVE_NCURSES_CURSES_H
# define NCURSES_INCL <ncurses/curses.h>

#elif defined HAVE_NCURSES_H
# define NCURSES_INCL <ncurses.h>

#elif defined HAVE_CURSES_H
# define NCURSES_INCL <curses.h>

#else
# error "SysV or X/Open-compatible Curses header file required"
#endif

#endif /* !_SYSTEM_H_ */

/* vi: set ts=8 sw=8 noexpandtab tw=79: */
