$(BUILD_DIR)/main.o: CXXFLAGS+=$(shell aocl compile-config) \
    -isystem /var/scratch/package/altera_pro/18.1.0.222/hld/host/include

$(EXE_DIR)/host-template: LDFLAGS+=$(shell aocl link-config) -lpthread $(shell pkg-config --libs fftw3f)
$(EXE_DIR)/host-template: $(BUILD_DIR)/main.o $(LIB_DIR)/libfft.a $(LIB_DIR)/libcl.a
	$(PRINTF) " LD\t$(@F)\n"
	$(AT)$(LD) $^ $(LDFLAGS) -o $@

$(TARGET): $(EXE_DIR)/host-template
