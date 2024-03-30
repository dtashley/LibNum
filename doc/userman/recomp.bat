rem ---------------------------------------------------------------------------
rem Fully builds the document.  The commands below are run three times to
rem ensure that all references are resolved.
rem ---------------------------------------------------------------------------
latex libnum_userman
makeindex libnum_userman
latex libnum_userman
makeindex libnum_userman
latex libnum_userman
makeindex libnum_userman
dvips -T 8.5in,11in libnum_userman
rem ---------------------------------------------------------------------------
