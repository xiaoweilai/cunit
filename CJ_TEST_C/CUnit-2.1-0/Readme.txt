
			CUnit : A Unit Testing Framework
			  http://cunit.sourceforge.net

CUnit is a Unit testing framework for C.

The basic framework is platform/version independent and should be
portable to all platforms.  CUnit provides various interfaces to
the framework, some of which are platform dependent (e.g. curses on
*nix).  Building other interfaces should be straightforward with
the facilities provided in the framework.

CUnit is built as either a static or shared library which provides 
framework support when linked into user testing code.  The framework 
complies with the conventional structure of test cases bundled into 
suites which are registered with the framework for running.  See the
documentation for more about the structure and use of the framework.

Note - the windows-specific gui interface is not yet written.  It is
still necessary to use either the automated, basic, or console
interfaces to CUnit on Windows at this time.

-----------------------------------------------------------------------
     Important Note - Changes to CUnit Structure & Interface
-----------------------------------------------------------------------

As of version 2.0, the interface functions used to interact with the
CUnit framework have changed.  The original interface did not attempt
to protect user code from name clashes with public CUnit functions and
variables.  To minimize such name clashes, all CUnit public functions
are now prefixed with 'CU_'.

The old public names are deprecated as of Version 2.0, but continue
to be supported with conversion macros.  In order to compile older code
using the original interface, it is now necessary to compile with the
macro -USE_DEPRECATED_CUNIT_NAMES defined.  If there are any problems
compiling older code, please file a bug report.

In addition, the DTD and XSL files for output from the automated test
interface have been updated to support both old and new file structure.
That is, a List or Run file generated using the version 1.1 library
should be (1) valid under the version 2 DTD's and (2) formatted
correctly by the version 2 XSL's.  Note, however, that this has not
been extended to the Memory-Dump DTD and XSL files.  That is, memory
dumps created using version 1.1 are ill-formed and incorrectly
formatted using the version 2 DTD and XSL files.

Another exception to backward compatibility occurs if the user has
directly manipulated the global variables in version 1.1.  The
original CUnit structure included global variables error_number and
g_pTestRegistry which have been removed from the global namespace as
of Version 2.0.  Any user code which directly accessed these variables
will break.  The variables must be retrieved using the accessor
functions CU__get_error() and CU_get_registry().

Similarly, user code retrieving the active test registry and directly
manipulating the uiNumberOfFailures or pResult members will break.
These members have been moved to the TestRun.c part of the framework
and are no longer available in the test registry as of version 2.0.

Another change in Version 2.0 is the update of the framework terminology.
What were termed 'test groups' in the original structure are now called
"suites", and "test cases" are now just "tests".  This change was made to
bring CUnit in conformance with standard testing terminology, and results
in a change in the name of some functions (e.g. run_group_tests() is
now CU_run_suite().

-----------------------------------------------------------------------

The binary distribution of CUnit was built using gcc/MinGW and ftjam.
The dll should be usable by other compilers that can generate an
import library.  A module definition file (libcunit_dll.def) is
included.  Visual C++ projects are available for building CUnit
in the source distriburtion.

What's installed:

  .       Readme.txt
          ChangeLog.txt
          libcunit_dll.def
 
  bin     libcunit.dll - dll version of the CUnit library

  doc     CUnit manual (index.html)

  include CUnit header files - needed to compile code using the framework.

  lib     libcunit.a      Static CUnit library for gcc/MinGW
          libcunit_dll.a  Import library (gcc/MinGW) for libcunit.dll

  man     CUnit man page

  share   dtd and xsl files for xml output files 
          (automated interface and memtrace memory tracer)

-----------------------------------------------------------------------

 