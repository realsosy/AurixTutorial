# -----------------------------------------------------------------------------
#
# Copyright (C) 2015-2017 Infineon Technologies AG. All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are met:
# - Redistributions of source code must retain the above copyright notice,
#   this list of conditions and the following disclaimer.
# - Redistributions in binary form must reproduce the above copyright notice,
#   this list of conditions and the following disclaimer in the documentation.
#   and/or other materials provided with the distribution.
# - Neither the name of the copyright holders nor the names of its
#   contributors may be used to endorse or promote products derived from this
#   software without specific prior written permission.
# 
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
# "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
# TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
# PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR
# CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
# EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
# PROCUREMENT OF SUBSTITUTE  GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
# OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
# WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
# OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
# ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
# 
# To improve the quality of the software, users are encouraged to share
# modifications, enhancements or bug fixes with Infineon Technologies AG
# (support@infineon.com).
# 
# -----------------------------------------------------------------------------
# Subdirectory make file for ../_LibSrc/iLLD_1_0_1_8_0__TC27D/Src/BaseSw/iLLD/TC27D/Tricore/_PinMap
# !! Generated make file, modifications could be overwritten !!
#------------------------------------------------------------------------------


# Make-Rules:
# Make-rules for architecture: Tricore

#Make-rule to build file: IfxAsclin_PinMap.c
B_GEN_DEP_FILES+= 2_Out/Tricore_Gnuc/Gnuc_Files/2_ExtSrc/BaseSw/iLLD/TC27D/Tricore/_PinMap/IfxAsclin_PinMap.d
B_GEN_OBJS_TRICORE_TC+= 2_Out/Tricore_Gnuc/Gnuc_Files/2_ExtSrc/BaseSw/iLLD/TC27D/Tricore/_PinMap/IfxAsclin_PinMap.o

2_Out/Tricore_Gnuc/Gnuc_Files/2_ExtSrc/BaseSw/iLLD/TC27D/Tricore/_PinMap/IfxAsclin_PinMap.o: ../_LibSrc/iLLD_1_0_1_8_0__TC27D/Src/BaseSw/iLLD/TC27D/Tricore/_PinMap/IfxAsclin_PinMap.c $(B_GEN_CONFIG_TRICORE_GNUC)
	@mkdir -p $(@D)
	@-rm -f $(B_GEN_ELF_TRICORE_TC) $(B_GEN_HEX_TRICORE_TC)
	@echo 'Building source file IfxAsclin_PinMap.c for Tricore'
	$(B_GEN_TRICORE_GNUC_CC) $(B_GNUC_TRICORE_CC_OPTIONS) -DBOARD=SHIELD_BUDDY @$(B_GEN_INC_LISTFILE_TRICORE) $(B_GEN_EXT_INCLUDE_PATHS) -c $< -o $@ -save-temps=obj -MMD

#Make-rule to build file: IfxCcu6_PinMap.c
B_GEN_DEP_FILES+= 2_Out/Tricore_Gnuc/Gnuc_Files/2_ExtSrc/BaseSw/iLLD/TC27D/Tricore/_PinMap/IfxCcu6_PinMap.d
B_GEN_OBJS_TRICORE_TC+= 2_Out/Tricore_Gnuc/Gnuc_Files/2_ExtSrc/BaseSw/iLLD/TC27D/Tricore/_PinMap/IfxCcu6_PinMap.o

2_Out/Tricore_Gnuc/Gnuc_Files/2_ExtSrc/BaseSw/iLLD/TC27D/Tricore/_PinMap/IfxCcu6_PinMap.o: ../_LibSrc/iLLD_1_0_1_8_0__TC27D/Src/BaseSw/iLLD/TC27D/Tricore/_PinMap/IfxCcu6_PinMap.c $(B_GEN_CONFIG_TRICORE_GNUC)
	@mkdir -p $(@D)
	@-rm -f $(B_GEN_ELF_TRICORE_TC) $(B_GEN_HEX_TRICORE_TC)
	@echo 'Building source file IfxCcu6_PinMap.c for Tricore'
	$(B_GEN_TRICORE_GNUC_CC) $(B_GNUC_TRICORE_CC_OPTIONS) -DBOARD=SHIELD_BUDDY @$(B_GEN_INC_LISTFILE_TRICORE) $(B_GEN_EXT_INCLUDE_PATHS) -c $< -o $@ -save-temps=obj -MMD

#Make-rule to build file: IfxCif_PinMap.c
B_GEN_DEP_FILES+= 2_Out/Tricore_Gnuc/Gnuc_Files/2_ExtSrc/BaseSw/iLLD/TC27D/Tricore/_PinMap/IfxCif_PinMap.d
B_GEN_OBJS_TRICORE_TC+= 2_Out/Tricore_Gnuc/Gnuc_Files/2_ExtSrc/BaseSw/iLLD/TC27D/Tricore/_PinMap/IfxCif_PinMap.o

2_Out/Tricore_Gnuc/Gnuc_Files/2_ExtSrc/BaseSw/iLLD/TC27D/Tricore/_PinMap/IfxCif_PinMap.o: ../_LibSrc/iLLD_1_0_1_8_0__TC27D/Src/BaseSw/iLLD/TC27D/Tricore/_PinMap/IfxCif_PinMap.c $(B_GEN_CONFIG_TRICORE_GNUC)
	@mkdir -p $(@D)
	@-rm -f $(B_GEN_ELF_TRICORE_TC) $(B_GEN_HEX_TRICORE_TC)
	@echo 'Building source file IfxCif_PinMap.c for Tricore'
	$(B_GEN_TRICORE_GNUC_CC) $(B_GNUC_TRICORE_CC_OPTIONS) -DBOARD=SHIELD_BUDDY @$(B_GEN_INC_LISTFILE_TRICORE) $(B_GEN_EXT_INCLUDE_PATHS) -c $< -o $@ -save-temps=obj -MMD

#Make-rule to build file: IfxDsadc_PinMap.c
B_GEN_DEP_FILES+= 2_Out/Tricore_Gnuc/Gnuc_Files/2_ExtSrc/BaseSw/iLLD/TC27D/Tricore/_PinMap/IfxDsadc_PinMap.d
B_GEN_OBJS_TRICORE_TC+= 2_Out/Tricore_Gnuc/Gnuc_Files/2_ExtSrc/BaseSw/iLLD/TC27D/Tricore/_PinMap/IfxDsadc_PinMap.o

2_Out/Tricore_Gnuc/Gnuc_Files/2_ExtSrc/BaseSw/iLLD/TC27D/Tricore/_PinMap/IfxDsadc_PinMap.o: ../_LibSrc/iLLD_1_0_1_8_0__TC27D/Src/BaseSw/iLLD/TC27D/Tricore/_PinMap/IfxDsadc_PinMap.c $(B_GEN_CONFIG_TRICORE_GNUC)
	@mkdir -p $(@D)
	@-rm -f $(B_GEN_ELF_TRICORE_TC) $(B_GEN_HEX_TRICORE_TC)
	@echo 'Building source file IfxDsadc_PinMap.c for Tricore'
	$(B_GEN_TRICORE_GNUC_CC) $(B_GNUC_TRICORE_CC_OPTIONS) -DBOARD=SHIELD_BUDDY @$(B_GEN_INC_LISTFILE_TRICORE) $(B_GEN_EXT_INCLUDE_PATHS) -c $< -o $@ -save-temps=obj -MMD

#Make-rule to build file: IfxEray_PinMap.c
B_GEN_DEP_FILES+= 2_Out/Tricore_Gnuc/Gnuc_Files/2_ExtSrc/BaseSw/iLLD/TC27D/Tricore/_PinMap/IfxEray_PinMap.d
B_GEN_OBJS_TRICORE_TC+= 2_Out/Tricore_Gnuc/Gnuc_Files/2_ExtSrc/BaseSw/iLLD/TC27D/Tricore/_PinMap/IfxEray_PinMap.o

2_Out/Tricore_Gnuc/Gnuc_Files/2_ExtSrc/BaseSw/iLLD/TC27D/Tricore/_PinMap/IfxEray_PinMap.o: ../_LibSrc/iLLD_1_0_1_8_0__TC27D/Src/BaseSw/iLLD/TC27D/Tricore/_PinMap/IfxEray_PinMap.c $(B_GEN_CONFIG_TRICORE_GNUC)
	@mkdir -p $(@D)
	@-rm -f $(B_GEN_ELF_TRICORE_TC) $(B_GEN_HEX_TRICORE_TC)
	@echo 'Building source file IfxEray_PinMap.c for Tricore'
	$(B_GEN_TRICORE_GNUC_CC) $(B_GNUC_TRICORE_CC_OPTIONS) -DBOARD=SHIELD_BUDDY @$(B_GEN_INC_LISTFILE_TRICORE) $(B_GEN_EXT_INCLUDE_PATHS) -c $< -o $@ -save-temps=obj -MMD

#Make-rule to build file: IfxEth_PinMap.c
B_GEN_DEP_FILES+= 2_Out/Tricore_Gnuc/Gnuc_Files/2_ExtSrc/BaseSw/iLLD/TC27D/Tricore/_PinMap/IfxEth_PinMap.d
B_GEN_OBJS_TRICORE_TC+= 2_Out/Tricore_Gnuc/Gnuc_Files/2_ExtSrc/BaseSw/iLLD/TC27D/Tricore/_PinMap/IfxEth_PinMap.o

2_Out/Tricore_Gnuc/Gnuc_Files/2_ExtSrc/BaseSw/iLLD/TC27D/Tricore/_PinMap/IfxEth_PinMap.o: ../_LibSrc/iLLD_1_0_1_8_0__TC27D/Src/BaseSw/iLLD/TC27D/Tricore/_PinMap/IfxEth_PinMap.c $(B_GEN_CONFIG_TRICORE_GNUC)
	@mkdir -p $(@D)
	@-rm -f $(B_GEN_ELF_TRICORE_TC) $(B_GEN_HEX_TRICORE_TC)
	@echo 'Building source file IfxEth_PinMap.c for Tricore'
	$(B_GEN_TRICORE_GNUC_CC) $(B_GNUC_TRICORE_CC_OPTIONS) -DBOARD=SHIELD_BUDDY @$(B_GEN_INC_LISTFILE_TRICORE) $(B_GEN_EXT_INCLUDE_PATHS) -c $< -o $@ -save-temps=obj -MMD

#Make-rule to build file: IfxGpt12_PinMap.c
B_GEN_DEP_FILES+= 2_Out/Tricore_Gnuc/Gnuc_Files/2_ExtSrc/BaseSw/iLLD/TC27D/Tricore/_PinMap/IfxGpt12_PinMap.d
B_GEN_OBJS_TRICORE_TC+= 2_Out/Tricore_Gnuc/Gnuc_Files/2_ExtSrc/BaseSw/iLLD/TC27D/Tricore/_PinMap/IfxGpt12_PinMap.o

2_Out/Tricore_Gnuc/Gnuc_Files/2_ExtSrc/BaseSw/iLLD/TC27D/Tricore/_PinMap/IfxGpt12_PinMap.o: ../_LibSrc/iLLD_1_0_1_8_0__TC27D/Src/BaseSw/iLLD/TC27D/Tricore/_PinMap/IfxGpt12_PinMap.c $(B_GEN_CONFIG_TRICORE_GNUC)
	@mkdir -p $(@D)
	@-rm -f $(B_GEN_ELF_TRICORE_TC) $(B_GEN_HEX_TRICORE_TC)
	@echo 'Building source file IfxGpt12_PinMap.c for Tricore'
	$(B_GEN_TRICORE_GNUC_CC) $(B_GNUC_TRICORE_CC_OPTIONS) -DBOARD=SHIELD_BUDDY @$(B_GEN_INC_LISTFILE_TRICORE) $(B_GEN_EXT_INCLUDE_PATHS) -c $< -o $@ -save-temps=obj -MMD

#Make-rule to build file: IfxGtm_PinMap.c
B_GEN_DEP_FILES+= 2_Out/Tricore_Gnuc/Gnuc_Files/2_ExtSrc/BaseSw/iLLD/TC27D/Tricore/_PinMap/IfxGtm_PinMap.d
B_GEN_OBJS_TRICORE_TC+= 2_Out/Tricore_Gnuc/Gnuc_Files/2_ExtSrc/BaseSw/iLLD/TC27D/Tricore/_PinMap/IfxGtm_PinMap.o

2_Out/Tricore_Gnuc/Gnuc_Files/2_ExtSrc/BaseSw/iLLD/TC27D/Tricore/_PinMap/IfxGtm_PinMap.o: ../_LibSrc/iLLD_1_0_1_8_0__TC27D/Src/BaseSw/iLLD/TC27D/Tricore/_PinMap/IfxGtm_PinMap.c $(B_GEN_CONFIG_TRICORE_GNUC)
	@mkdir -p $(@D)
	@-rm -f $(B_GEN_ELF_TRICORE_TC) $(B_GEN_HEX_TRICORE_TC)
	@echo 'Building source file IfxGtm_PinMap.c for Tricore'
	$(B_GEN_TRICORE_GNUC_CC) $(B_GNUC_TRICORE_CC_OPTIONS) -DBOARD=SHIELD_BUDDY @$(B_GEN_INC_LISTFILE_TRICORE) $(B_GEN_EXT_INCLUDE_PATHS) -c $< -o $@ -save-temps=obj -MMD

#Make-rule to build file: IfxI2c_PinMap.c
B_GEN_DEP_FILES+= 2_Out/Tricore_Gnuc/Gnuc_Files/2_ExtSrc/BaseSw/iLLD/TC27D/Tricore/_PinMap/IfxI2c_PinMap.d
B_GEN_OBJS_TRICORE_TC+= 2_Out/Tricore_Gnuc/Gnuc_Files/2_ExtSrc/BaseSw/iLLD/TC27D/Tricore/_PinMap/IfxI2c_PinMap.o

2_Out/Tricore_Gnuc/Gnuc_Files/2_ExtSrc/BaseSw/iLLD/TC27D/Tricore/_PinMap/IfxI2c_PinMap.o: ../_LibSrc/iLLD_1_0_1_8_0__TC27D/Src/BaseSw/iLLD/TC27D/Tricore/_PinMap/IfxI2c_PinMap.c $(B_GEN_CONFIG_TRICORE_GNUC)
	@mkdir -p $(@D)
	@-rm -f $(B_GEN_ELF_TRICORE_TC) $(B_GEN_HEX_TRICORE_TC)
	@echo 'Building source file IfxI2c_PinMap.c for Tricore'
	$(B_GEN_TRICORE_GNUC_CC) $(B_GNUC_TRICORE_CC_OPTIONS) -DBOARD=SHIELD_BUDDY @$(B_GEN_INC_LISTFILE_TRICORE) $(B_GEN_EXT_INCLUDE_PATHS) -c $< -o $@ -save-temps=obj -MMD

#Make-rule to build file: IfxMsc_PinMap.c
B_GEN_DEP_FILES+= 2_Out/Tricore_Gnuc/Gnuc_Files/2_ExtSrc/BaseSw/iLLD/TC27D/Tricore/_PinMap/IfxMsc_PinMap.d
B_GEN_OBJS_TRICORE_TC+= 2_Out/Tricore_Gnuc/Gnuc_Files/2_ExtSrc/BaseSw/iLLD/TC27D/Tricore/_PinMap/IfxMsc_PinMap.o

2_Out/Tricore_Gnuc/Gnuc_Files/2_ExtSrc/BaseSw/iLLD/TC27D/Tricore/_PinMap/IfxMsc_PinMap.o: ../_LibSrc/iLLD_1_0_1_8_0__TC27D/Src/BaseSw/iLLD/TC27D/Tricore/_PinMap/IfxMsc_PinMap.c $(B_GEN_CONFIG_TRICORE_GNUC)
	@mkdir -p $(@D)
	@-rm -f $(B_GEN_ELF_TRICORE_TC) $(B_GEN_HEX_TRICORE_TC)
	@echo 'Building source file IfxMsc_PinMap.c for Tricore'
	$(B_GEN_TRICORE_GNUC_CC) $(B_GNUC_TRICORE_CC_OPTIONS) -DBOARD=SHIELD_BUDDY @$(B_GEN_INC_LISTFILE_TRICORE) $(B_GEN_EXT_INCLUDE_PATHS) -c $< -o $@ -save-temps=obj -MMD

#Make-rule to build file: IfxMultican_PinMap.c
B_GEN_DEP_FILES+= 2_Out/Tricore_Gnuc/Gnuc_Files/2_ExtSrc/BaseSw/iLLD/TC27D/Tricore/_PinMap/IfxMultican_PinMap.d
B_GEN_OBJS_TRICORE_TC+= 2_Out/Tricore_Gnuc/Gnuc_Files/2_ExtSrc/BaseSw/iLLD/TC27D/Tricore/_PinMap/IfxMultican_PinMap.o

2_Out/Tricore_Gnuc/Gnuc_Files/2_ExtSrc/BaseSw/iLLD/TC27D/Tricore/_PinMap/IfxMultican_PinMap.o: ../_LibSrc/iLLD_1_0_1_8_0__TC27D/Src/BaseSw/iLLD/TC27D/Tricore/_PinMap/IfxMultican_PinMap.c $(B_GEN_CONFIG_TRICORE_GNUC)
	@mkdir -p $(@D)
	@-rm -f $(B_GEN_ELF_TRICORE_TC) $(B_GEN_HEX_TRICORE_TC)
	@echo 'Building source file IfxMultican_PinMap.c for Tricore'
	$(B_GEN_TRICORE_GNUC_CC) $(B_GNUC_TRICORE_CC_OPTIONS) -DBOARD=SHIELD_BUDDY @$(B_GEN_INC_LISTFILE_TRICORE) $(B_GEN_EXT_INCLUDE_PATHS) -c $< -o $@ -save-temps=obj -MMD

#Make-rule to build file: IfxPort_PinMap.c
B_GEN_DEP_FILES+= 2_Out/Tricore_Gnuc/Gnuc_Files/2_ExtSrc/BaseSw/iLLD/TC27D/Tricore/_PinMap/IfxPort_PinMap.d
B_GEN_OBJS_TRICORE_TC+= 2_Out/Tricore_Gnuc/Gnuc_Files/2_ExtSrc/BaseSw/iLLD/TC27D/Tricore/_PinMap/IfxPort_PinMap.o

2_Out/Tricore_Gnuc/Gnuc_Files/2_ExtSrc/BaseSw/iLLD/TC27D/Tricore/_PinMap/IfxPort_PinMap.o: ../_LibSrc/iLLD_1_0_1_8_0__TC27D/Src/BaseSw/iLLD/TC27D/Tricore/_PinMap/IfxPort_PinMap.c $(B_GEN_CONFIG_TRICORE_GNUC)
	@mkdir -p $(@D)
	@-rm -f $(B_GEN_ELF_TRICORE_TC) $(B_GEN_HEX_TRICORE_TC)
	@echo 'Building source file IfxPort_PinMap.c for Tricore'
	$(B_GEN_TRICORE_GNUC_CC) $(B_GNUC_TRICORE_CC_OPTIONS) -DBOARD=SHIELD_BUDDY @$(B_GEN_INC_LISTFILE_TRICORE) $(B_GEN_EXT_INCLUDE_PATHS) -c $< -o $@ -save-temps=obj -MMD

#Make-rule to build file: IfxPsi5s_PinMap.c
B_GEN_DEP_FILES+= 2_Out/Tricore_Gnuc/Gnuc_Files/2_ExtSrc/BaseSw/iLLD/TC27D/Tricore/_PinMap/IfxPsi5s_PinMap.d
B_GEN_OBJS_TRICORE_TC+= 2_Out/Tricore_Gnuc/Gnuc_Files/2_ExtSrc/BaseSw/iLLD/TC27D/Tricore/_PinMap/IfxPsi5s_PinMap.o

2_Out/Tricore_Gnuc/Gnuc_Files/2_ExtSrc/BaseSw/iLLD/TC27D/Tricore/_PinMap/IfxPsi5s_PinMap.o: ../_LibSrc/iLLD_1_0_1_8_0__TC27D/Src/BaseSw/iLLD/TC27D/Tricore/_PinMap/IfxPsi5s_PinMap.c $(B_GEN_CONFIG_TRICORE_GNUC)
	@mkdir -p $(@D)
	@-rm -f $(B_GEN_ELF_TRICORE_TC) $(B_GEN_HEX_TRICORE_TC)
	@echo 'Building source file IfxPsi5s_PinMap.c for Tricore'
	$(B_GEN_TRICORE_GNUC_CC) $(B_GNUC_TRICORE_CC_OPTIONS) -DBOARD=SHIELD_BUDDY @$(B_GEN_INC_LISTFILE_TRICORE) $(B_GEN_EXT_INCLUDE_PATHS) -c $< -o $@ -save-temps=obj -MMD

#Make-rule to build file: IfxPsi5_PinMap.c
B_GEN_DEP_FILES+= 2_Out/Tricore_Gnuc/Gnuc_Files/2_ExtSrc/BaseSw/iLLD/TC27D/Tricore/_PinMap/IfxPsi5_PinMap.d
B_GEN_OBJS_TRICORE_TC+= 2_Out/Tricore_Gnuc/Gnuc_Files/2_ExtSrc/BaseSw/iLLD/TC27D/Tricore/_PinMap/IfxPsi5_PinMap.o

2_Out/Tricore_Gnuc/Gnuc_Files/2_ExtSrc/BaseSw/iLLD/TC27D/Tricore/_PinMap/IfxPsi5_PinMap.o: ../_LibSrc/iLLD_1_0_1_8_0__TC27D/Src/BaseSw/iLLD/TC27D/Tricore/_PinMap/IfxPsi5_PinMap.c $(B_GEN_CONFIG_TRICORE_GNUC)
	@mkdir -p $(@D)
	@-rm -f $(B_GEN_ELF_TRICORE_TC) $(B_GEN_HEX_TRICORE_TC)
	@echo 'Building source file IfxPsi5_PinMap.c for Tricore'
	$(B_GEN_TRICORE_GNUC_CC) $(B_GNUC_TRICORE_CC_OPTIONS) -DBOARD=SHIELD_BUDDY @$(B_GEN_INC_LISTFILE_TRICORE) $(B_GEN_EXT_INCLUDE_PATHS) -c $< -o $@ -save-temps=obj -MMD

#Make-rule to build file: IfxQspi_PinMap.c
B_GEN_DEP_FILES+= 2_Out/Tricore_Gnuc/Gnuc_Files/2_ExtSrc/BaseSw/iLLD/TC27D/Tricore/_PinMap/IfxQspi_PinMap.d
B_GEN_OBJS_TRICORE_TC+= 2_Out/Tricore_Gnuc/Gnuc_Files/2_ExtSrc/BaseSw/iLLD/TC27D/Tricore/_PinMap/IfxQspi_PinMap.o

2_Out/Tricore_Gnuc/Gnuc_Files/2_ExtSrc/BaseSw/iLLD/TC27D/Tricore/_PinMap/IfxQspi_PinMap.o: ../_LibSrc/iLLD_1_0_1_8_0__TC27D/Src/BaseSw/iLLD/TC27D/Tricore/_PinMap/IfxQspi_PinMap.c $(B_GEN_CONFIG_TRICORE_GNUC)
	@mkdir -p $(@D)
	@-rm -f $(B_GEN_ELF_TRICORE_TC) $(B_GEN_HEX_TRICORE_TC)
	@echo 'Building source file IfxQspi_PinMap.c for Tricore'
	$(B_GEN_TRICORE_GNUC_CC) $(B_GNUC_TRICORE_CC_OPTIONS) -DBOARD=SHIELD_BUDDY @$(B_GEN_INC_LISTFILE_TRICORE) $(B_GEN_EXT_INCLUDE_PATHS) -c $< -o $@ -save-temps=obj -MMD

#Make-rule to build file: IfxScu_PinMap.c
B_GEN_DEP_FILES+= 2_Out/Tricore_Gnuc/Gnuc_Files/2_ExtSrc/BaseSw/iLLD/TC27D/Tricore/_PinMap/IfxScu_PinMap.d
B_GEN_OBJS_TRICORE_TC+= 2_Out/Tricore_Gnuc/Gnuc_Files/2_ExtSrc/BaseSw/iLLD/TC27D/Tricore/_PinMap/IfxScu_PinMap.o

2_Out/Tricore_Gnuc/Gnuc_Files/2_ExtSrc/BaseSw/iLLD/TC27D/Tricore/_PinMap/IfxScu_PinMap.o: ../_LibSrc/iLLD_1_0_1_8_0__TC27D/Src/BaseSw/iLLD/TC27D/Tricore/_PinMap/IfxScu_PinMap.c $(B_GEN_CONFIG_TRICORE_GNUC)
	@mkdir -p $(@D)
	@-rm -f $(B_GEN_ELF_TRICORE_TC) $(B_GEN_HEX_TRICORE_TC)
	@echo 'Building source file IfxScu_PinMap.c for Tricore'
	$(B_GEN_TRICORE_GNUC_CC) $(B_GNUC_TRICORE_CC_OPTIONS) -DBOARD=SHIELD_BUDDY @$(B_GEN_INC_LISTFILE_TRICORE) $(B_GEN_EXT_INCLUDE_PATHS) -c $< -o $@ -save-temps=obj -MMD

#Make-rule to build file: IfxSent_PinMap.c
B_GEN_DEP_FILES+= 2_Out/Tricore_Gnuc/Gnuc_Files/2_ExtSrc/BaseSw/iLLD/TC27D/Tricore/_PinMap/IfxSent_PinMap.d
B_GEN_OBJS_TRICORE_TC+= 2_Out/Tricore_Gnuc/Gnuc_Files/2_ExtSrc/BaseSw/iLLD/TC27D/Tricore/_PinMap/IfxSent_PinMap.o

2_Out/Tricore_Gnuc/Gnuc_Files/2_ExtSrc/BaseSw/iLLD/TC27D/Tricore/_PinMap/IfxSent_PinMap.o: ../_LibSrc/iLLD_1_0_1_8_0__TC27D/Src/BaseSw/iLLD/TC27D/Tricore/_PinMap/IfxSent_PinMap.c $(B_GEN_CONFIG_TRICORE_GNUC)
	@mkdir -p $(@D)
	@-rm -f $(B_GEN_ELF_TRICORE_TC) $(B_GEN_HEX_TRICORE_TC)
	@echo 'Building source file IfxSent_PinMap.c for Tricore'
	$(B_GEN_TRICORE_GNUC_CC) $(B_GNUC_TRICORE_CC_OPTIONS) -DBOARD=SHIELD_BUDDY @$(B_GEN_INC_LISTFILE_TRICORE) $(B_GEN_EXT_INCLUDE_PATHS) -c $< -o $@ -save-temps=obj -MMD

#Make-rule to build file: IfxSmu_PinMap.c
B_GEN_DEP_FILES+= 2_Out/Tricore_Gnuc/Gnuc_Files/2_ExtSrc/BaseSw/iLLD/TC27D/Tricore/_PinMap/IfxSmu_PinMap.d
B_GEN_OBJS_TRICORE_TC+= 2_Out/Tricore_Gnuc/Gnuc_Files/2_ExtSrc/BaseSw/iLLD/TC27D/Tricore/_PinMap/IfxSmu_PinMap.o

2_Out/Tricore_Gnuc/Gnuc_Files/2_ExtSrc/BaseSw/iLLD/TC27D/Tricore/_PinMap/IfxSmu_PinMap.o: ../_LibSrc/iLLD_1_0_1_8_0__TC27D/Src/BaseSw/iLLD/TC27D/Tricore/_PinMap/IfxSmu_PinMap.c $(B_GEN_CONFIG_TRICORE_GNUC)
	@mkdir -p $(@D)
	@-rm -f $(B_GEN_ELF_TRICORE_TC) $(B_GEN_HEX_TRICORE_TC)
	@echo 'Building source file IfxSmu_PinMap.c for Tricore'
	$(B_GEN_TRICORE_GNUC_CC) $(B_GNUC_TRICORE_CC_OPTIONS) -DBOARD=SHIELD_BUDDY @$(B_GEN_INC_LISTFILE_TRICORE) $(B_GEN_EXT_INCLUDE_PATHS) -c $< -o $@ -save-temps=obj -MMD

#Make-rule to build file: IfxVadc_PinMap.c
B_GEN_DEP_FILES+= 2_Out/Tricore_Gnuc/Gnuc_Files/2_ExtSrc/BaseSw/iLLD/TC27D/Tricore/_PinMap/IfxVadc_PinMap.d
B_GEN_OBJS_TRICORE_TC+= 2_Out/Tricore_Gnuc/Gnuc_Files/2_ExtSrc/BaseSw/iLLD/TC27D/Tricore/_PinMap/IfxVadc_PinMap.o

2_Out/Tricore_Gnuc/Gnuc_Files/2_ExtSrc/BaseSw/iLLD/TC27D/Tricore/_PinMap/IfxVadc_PinMap.o: ../_LibSrc/iLLD_1_0_1_8_0__TC27D/Src/BaseSw/iLLD/TC27D/Tricore/_PinMap/IfxVadc_PinMap.c $(B_GEN_CONFIG_TRICORE_GNUC)
	@mkdir -p $(@D)
	@-rm -f $(B_GEN_ELF_TRICORE_TC) $(B_GEN_HEX_TRICORE_TC)
	@echo 'Building source file IfxVadc_PinMap.c for Tricore'
	$(B_GEN_TRICORE_GNUC_CC) $(B_GNUC_TRICORE_CC_OPTIONS) -DBOARD=SHIELD_BUDDY @$(B_GEN_INC_LISTFILE_TRICORE) $(B_GEN_EXT_INCLUDE_PATHS) -c $< -o $@ -save-temps=obj -MMD
