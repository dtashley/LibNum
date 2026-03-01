rem ---------------------------------------------------------------------------
rem Fully builds the document.  The commands below are run three times to
rem ensure that all references are resolved.
rem ---------------------------------------------------------------------------
latex libnum_user_manual
makeindex libnum_user_manual
latex libnum_user_manual
makeindex libnum_user_manual
latex libnum_user_manual
makeindex libnum_user_manual
dvips -T 8.5in,11in libnum_user_manual
rem ---------------------------------------------------------------------------
