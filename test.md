User manual:

Important: before proceeding with this manual be sure to properly set up
remote keyboard emulator, according to “Remote keyboard. User Manual”.

1\. Installation:

1.  Build From Source:

    Be sure to properly set-up boost libraries:
    <http://www.boost.org/doc/libs/1_64_0/more/getting_started/windows.html>

Download Source Code:

<https://github.com/extramask93/VK>

Build with c++14 compiler.

1.  Download Pre-compiled windows binary from:

    <https://github.com/extramask93/VK>

2\. Version:

This manual covers version 1.0 of VirtualKeyboard desktop application.
To check Locally installed version please type virtualkeyboard.exe
--version in Your windows console.

3\. Available Functions:

Note: All of the listed options could be supplied from a file, named:
“config.ini” or directly as command line arguments. To list all
available options run virtualkeyboard.exe with \[-h\] parameter.
Additionally to stop application while in *record* or *free* mode user
should click F12 key.

![](Pictures/10000000000001BC000000E6B86551534DF12F82.png){width="444"
height="229"}

--verbose option is available mainly for debugging purposes, it lists
every send packet structure in real time. User should avoid this option,
it significantly impacts the performance.

--macro option with text file argument lets the user run predefined
macro script. It’s syntax is described in Appendix 1.

-- setip lets user specify network card settings of a remote keyboard.
Argumets should be given as follows: 1/0,ip
adddress,port,Netmask,GateWay

Where: 1 – dhcp

0 – static settings

When specifying dhcp, all the rest should be filled with zeros.

-- record records and puts user actons into specified macro file. Not
available in version 1.0

-- free lets user to send keystrokes in real time from host computer to
the remote keyboard. To actually capture anything, should be used with
--keyboard and --mouse switches.

-- keyboard switch used in combination with --free and --record option.
Hooks into keyboard procedure.

-- mouse switch used in combination with --free and --record option.
Hooks into mouse procedure.

-- dual switch specifies that every keystroke will be executed on host
and remote machine.

-- singular switch specifies that every keystroke will be executed only
on remote machine.

-- ip specifies ip or a remote keyboard,

-- port specifies port of a remote keyboard,

Appendix 1

Macro structure.

To ease usage macro could be written in 2 modes, that is: short and
long. Both modes could be contained in single file, given that they
would be separated by line with \[SHORT\] or \[LONG\] specifier
depending what mode starting point it marks.

Short mode:

This mode is somewhat crippled, but lets user prototype faster. It’s
main disadvantage is that it allows to only write to keyboard and only
click or move the mouse. No prolonged push here, that is it does not
hold a button.

**Syntax:**

For printable characters – they can be specified as is, separated by a
white-character. Example:

\[SHORT\]

H e l l o w o r l d

For non-printable characters – they should be consulted with Table 1 to
determine their identificator.

Example:

\[SHORT\]

H e l l o KEY\_RETURN w o r l d

For mouse actions there are only two:

MMx,y,wheel – where x,y, determine incremental mouse cursor position
change in range \[-127;127\]

and wheel determines wheel rotation in range \[-127;127\]

MCbutton – where button could be LPM or PPM indicating left and right
mouse click accordingly.

Example:

MM100,100,0 MM100,-20,0

MCLPM MCLPM

Table 1:

  -------------------
  KEY\_UP\_ARROW
  KEY\_DOWN\_ARROW
  KEY\_LEFT\_ARROW
  KEY\_RIGHT\_ARROW
  KEY\_BACKSPACE
  KEY\_TAB
  KEY\_RETURN
  KEY\_ESC
  KEY\_INSERT
  KEY\_DELETE
  KEY\_PAGE\_UP
  KEY\_HOME
  KEY\_END
  KEY\_CAPS\_LOCK
  KEY\_F1
  KEY\_F...
  KEY\_F12
  KEY\_SPACE
  -------------------

Long mode:

This mode while being heavy typing oriented offers: button combinations,
delays and single nested loops.

Syntax:

Main syntax rule is that every command should be in separate line and
there should be space between command and it’s parameters.

Available commands:

  -------------------- --------------------------------------------------- ----------------------------------------------------------------------------------------------
  Command name         Parameters                                          Description
  delayS               Non-negative integer                                Delays given amount of seconds.
  delayMS              Non-negative integer                                Delays given amount of miliseconds.
  keyboardPush         Printable character or identificator from Table 1   Pushes specified key on the keyboard
  keyboardWrite        Printable character or identificator from Table 1   Pushes and relases specified key on the keyboard
  keyboardRelease      Printable character or identificator from Table 1   Releases specified key on the keyboard
  keyboardReleaseAll   No parameter                                        Releases all keys currently pressed on the keyboard
  mouseMove            X,Y,Wheel in range\[-127;127\]                      Moves mouse by specified amount
  mouseReleaseAll      No parameter                                        Releases all keys currently pressed on the mouse
  mouseRelease         LPM or PPM                                          Releases specified key on the mouse
  mousePush            LPM or PPM                                          Presses specified key on the mouse
  mouseClick           LPM or PPM                                          Clicks specified key on the mouse
  DO                   Non negative number of iterations                   Repeats commands specified between this command and corresponding END given amount of times.
  END                  No paramters                                        Ends corresponding DO loops
  -------------------- --------------------------------------------------- ----------------------------------------------------------------------------------------------

Example:

\[LONG\]

DO 5

keyboardPush KEY\_SHIFT

keyboardPush KEY\_DELETE

keyboardReleaseAll

END

NOTE:

Application facilities only basic error checking for macro files.
Generally it’s behavior under such an error is undefined.
