rem ---------------------------------------------------------------------------
rem Fully builds the document.  The commands below are run three times to
rem ensure that all references and index entries are resolved and correct.
rem ---------------------------------------------------------------------------
latex libnum_user_manual
makeindex libnum_user_manual
latex libnum_user_manual
makeindex libnum_user_manual
latex libnum_user_manual
makeindex libnum_user_manual
rem ---------------------------------------------------------------------------
rem Create Postscript output.
rem ---------------------------------------------------------------------------
dvips -T 8.5in,11in libnum_user_manual
rem ---------------------------------------------------------------------------
rem Creation of a .PDF will be done manually.
rem ---------------------------------------------------------------------------
