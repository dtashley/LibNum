rem ---------------------------------------------------------------------------
rem Fully builds the document.  The commands below are run three times to
rem ensure that all references are resolved.
rem ---------------------------------------------------------------------------
latex ucu_userman
makeindex ucu_userman
latex ucu_userman
makeindex ucu_userman
latex ucu_userman
makeindex ucu_userman
dvips -T 8.5in,11in ucu_userman
rem ---------------------------------------------------------------------------
