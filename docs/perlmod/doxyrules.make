DOXY_EXEC_PATH = /media/SQ004224P01/estudos/wx/vtiger/vtigui/docs
DOXYFILE = /media/SQ004224P01/estudos/wx/vtiger/vtigui/docs/-
DOXYDOCS_PM = /media/SQ004224P01/estudos/wx/vtiger/vtigui/docs/perlmod/DoxyDocs.pm
DOXYSTRUCTURE_PM = /media/SQ004224P01/estudos/wx/vtiger/vtigui/docs/perlmod/DoxyStructure.pm
DOXYRULES = /media/SQ004224P01/estudos/wx/vtiger/vtigui/docs/perlmod/doxyrules.make

.PHONY: clean-perlmod
clean-perlmod::
	rm -f $(DOXYSTRUCTURE_PM) \
	$(DOXYDOCS_PM)

$(DOXYRULES) \
$(DOXYMAKEFILE) \
$(DOXYSTRUCTURE_PM) \
$(DOXYDOCS_PM): \
	$(DOXYFILE)
	cd $(DOXY_EXEC_PATH) ; doxygen "$<"
