TEST_DIR:=$(SRCDIR)
test_cc_files = $(SRCDIR)/gtest/src/gtest-all.cc $(SRCDIR)/gmock/src/gmock-all.cc $(SRCDIR)/gtest/src/gtest_main.cc
test_cc_files += $(wildcard $(SRCDIR)/*.cc)
test_obj_files = $(test_cc_files:$(SRCDIR)/%.cc=$(BUILD_DIR)/%.o)

$(test_obj_files): CXXFLAGS+=-iquote $(TEST_DIR)/gtest/ -iquote $(TEST_DIR)/gmock/
$(test_obj_files): | $(BUILD_DIR)/gtest/src/ $(BUILD_DIR)/gmock/src/

$(BUILD_DIR)/gtest/src/ $(BUILD_DIR)/gmock/src/: ; $(make-dir)

$(EXE_DIR)/run-tests: LDFLAGS+=-lpthread
$(EXE_DIR)/run-tests: $(test_obj_files)
	$(PRINTF) " LD\t$(@F)\n"
	$(AT)$(LD) $^ $(LDFLAGS) -o $@

all: $(EXE_DIR)/run-tests
