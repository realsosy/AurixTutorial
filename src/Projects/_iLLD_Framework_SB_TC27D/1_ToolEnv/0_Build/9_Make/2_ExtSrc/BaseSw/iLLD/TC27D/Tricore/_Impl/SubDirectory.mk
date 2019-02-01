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
# Subdirectory make file for ../_LibSrc/iLLD_1_0_1_8_0__TC27D/Src/BaseSw/iLLD/TC27D/Tricore/_Impl
# !! Generated make file, modifications could be overwritten !!
#------------------------------------------------------------------------------


# Make-Rules:
# Make-rules for architecture: Tricore

#Make-rule to build file: IfxAsclin_cfg.c
B_GEN_DEP_FILES+= 2_Out/Tricore_Gnuc/Gnuc_Files/2_ExtSrc/BaseSw/iLLD/TC27D/Tricore/_Impl/IfxAsclin_cfg.d
B_GEN_OBJS_TRICORE_TC+= 2_Out/Tricore_Gnuc/Gnuc_Files/2_ExtSrc/BaseSw/iLLD/TC27D/Tricore/_Impl/IfxAsclin_cfg.o

2_Out/Tricore_Gnuc/Gnuc_Files/2_ExtSrc/BaseSw/iLLD/TC27D/Tricore/_Impl/IfxAsclin_cfg.o: ../_LibSrc/iLLD_1_0_1_8_0__TC27D/Src/BaseSw/iLLD/TC27D/Tricore/_Impl/IfxAsclin_cfg.c $(B_GEN_CONFIG_TRICORE_GNUC)
	@mkdir -p $(@D)
	@-rm -f $(B_GEN_ELF_TRICORE_TC) $(B_GEN_HEX_TRICORE_TC)
	@echo 'Building source file IfxAsclin_cfg.c for Tricore'
	$(B_GEN_TRICORE_GNUC_CC) $(B_GNUC_TRICORE_CC_OPTIONS) -DBOARD=SHIELD_BUDDY @$(B_GEN_INC_LISTFILE_TRICORE) $(B_GEN_EXT_INCLUDE_PATHS) -c $< -o $@ -save-temps=obj -MMD

#Make-rule to build file: IfxCcu6_cfg.c
B_GEN_DEP_FILES+= 2_Out/Tricore_Gnuc/Gnuc_Files/2_ExtSrc/BaseSw/iLLD/TC27D/Tricore/_Impl/IfxCcu6_cfg.d
B_GEN_OBJS_TRICORE_TC+= 2_Out/Tricore_Gnuc/Gnuc_Files/2_ExtSrc/BaseSw/iLLD/TC27D/Tricore/_Impl/IfxCcu6_cfg.o

2_Out/Tricore_Gnuc/Gnuc_Files/2_ExtSrc/BaseSw/iLLD/TC27D/Tricore/_Impl/IfxCcu6_cfg.o: ../_LibSrc/iLLD_1_0_1_8_0__TC27D/Src/BaseSw/iLLD/TC27D/Tricore/_Impl/IfxCcu6_cfg.c $(B_GEN_CONFIG_TRICORE_GNUC)
	@mkdir -p $(@D)
	@-rm -f $(B_GEN_ELF_TRICORE_TC) $(B_GEN_HEX_TRICORE_TC)
	@echo 'Building source file IfxCcu6_cfg.c for Tricore'
	$(B_GEN_TRICORE_GNUC_CC) $(B_GNUC_TRICORE_CC_OPTIONS) -DBOARD=SHIELD_BUDDY @$(B_GEN_INC_LISTFILE_TRICORE) $(B_GEN_EXT_INCLUDE_PATHS) -c $< -o $@ -save-temps=obj -MMD

#Make-rule to build file: IfxCif_cfg.c
B_GEN_DEP_FILES+= 2_Out/Tricore_Gnuc/Gnuc_Files/2_ExtSrc/BaseSw/iLLD/TC27D/Tricore/_Impl/IfxCif_cfg.d
B_GEN_OBJS_TRICORE_TC+= 2_Out/Tricore_Gnuc/Gnuc_Files/2_ExtSrc/BaseSw/iLLD/TC27D/Tricore/_Impl/IfxCif_cfg.o

2_Out/Tricore_Gnuc/Gnuc_Files/2_ExtSrc/BaseSw/iLLD/TC27D/Tricore/_Impl/IfxCif_cfg.o: ../_LibSrc/iLLD_1_0_1_8_0__TC27D/Src/BaseSw/iLLD/TC27D/Tricore/_Impl/IfxCif_cfg.c $(B_GEN_CONFIG_TRICORE_GNUC)
	@mkdir -p $(@D)
	@-rm -f $(B_GEN_ELF_TRICORE_TC) $(B_GEN_HEX_TRICORE_TC)
	@echo 'Building source file IfxCif_cfg.c for Tricore'
	$(B_GEN_TRICORE_GNUC_CC) $(B_GNUC_TRICORE_CC_OPTIONS) -DBOARD=SHIELD_BUDDY @$(B_GEN_INC_LISTFILE_TRICORE) $(B_GEN_EXT_INCLUDE_PATHS) -c $< -o $@ -save-temps=obj -MMD

#Make-rule to build file: IfxCpu_cfg.c
B_GEN_DEP_FILES+= 2_Out/Tricore_Gnuc/Gnuc_Files/2_ExtSrc/BaseSw/iLLD/TC27D/Tricore/_Impl/IfxCpu_cfg.d
B_GEN_OBJS_TRICORE_TC+= 2_Out/Tricore_Gnuc/Gnuc_Files/2_ExtSrc/BaseSw/iLLD/TC27D/Tricore/_Impl/IfxCpu_cfg.o

2_Out/Tricore_Gnuc/Gnuc_Files/2_ExtSrc/BaseSw/iLLD/TC27D/Tricore/_Impl/IfxCpu_cfg.o: ../_LibSrc/iLLD_1_0_1_8_0__TC27D/Src/BaseSw/iLLD/TC27D/Tricore/_Impl/IfxCpu_cfg.c $(B_GEN_CONFIG_TRICORE_GNUC)
	@mkdir -p $(@D)
	@-rm -f $(B_GEN_ELF_TRICORE_TC) $(B_GEN_HEX_TRICORE_TC)
	@echo 'Building source file IfxCpu_cfg.c for Tricore'
	$(B_GEN_TRICORE_GNUC_CC) $(B_GNUC_TRICORE_CC_OPTIONS) -DBOARD=SHIELD_BUDDY @$(B_GEN_INC_LISTFILE_TRICORE) $(B_GEN_EXT_INCLUDE_PATHS) -c $< -o $@ -save-temps=obj -MMD

#Make-rule to build file: IfxDma_cfg.c
B_GEN_DEP_FILES+= 2_Out/Tricore_Gnuc/Gnuc_Files/2_ExtSrc/BaseSw/iLLD/TC27D/Tricore/_Impl/IfxDma_cfg.d
B_GEN_OBJS_TRICORE_TC+= 2_Out/Tricore_Gnuc/Gnuc_Files/2_ExtSrc/BaseSw/iLLD/TC27D/Tricore/_Impl/IfxDma_cfg.o

2_Out/Tricore_Gnuc/Gnuc_Files/2_ExtSrc/BaseSw/iLLD/TC27D/Tricore/_Impl/IfxDma_cfg.o: ../_LibSrc/iLLD_1_0_1_8_0__TC27D/Src/BaseSw/iLLD/TC27D/Tricore/_Impl/IfxDma_cfg.c $(B_GEN_CONFIG_TRICORE_GNUC)
	@mkdir -p $(@D)
	@-rm -f $(B_GEN_ELF_TRICORE_TC) $(B_GEN_HEX_TRICORE_TC)
	@echo 'Building source file IfxDma_cfg.c for Tricore'
	$(B_GEN_TRICORE_GNUC_CC) $(B_GNUC_TRICORE_CC_OPTIONS) -DBOARD=SHIELD_BUDDY @$(B_GEN_INC_LISTFILE_TRICORE) $(B_GEN_EXT_INCLUDE_PATHS) -c $< -o $@ -save-temps=obj -MMD

#Make-rule to build file: IfxEmem_cfg.c
B_GEN_DEP_FILES+= 2_Out/Tricore_Gnuc/Gnuc_Files/2_ExtSrc/BaseSw/iLLD/TC27D/Tricore/_Impl/IfxEmem_cfg.d
B_GEN_OBJS_TRICORE_TC+= 2_Out/Tricore_Gnuc/Gnuc_Files/2_ExtSrc/BaseSw/iLLD/TC27D/Tricore/_Impl/IfxEmem_cfg.o

2_Out/Tricore_Gnuc/Gnuc_Files/2_ExtSrc/BaseSw/iLLD/TC27D/Tricore/_Impl/IfxEmem_cfg.o: ../_LibSrc/iLLD_1_0_1_8_0__TC27D/Src/BaseSw/iLLD/TC27D/Tricore/_Impl/IfxEmem_cfg.c $(B_GEN_CONFIG_TRICORE_GNUC)
	@mkdir -p $(@D)
	@-rm -f $(B_GEN_ELF_TRICORE_TC) $(B_GEN_HEX_TRICORE_TC)
	@echo 'Building source file IfxEmem_cfg.c for Tricore'
	$(B_GEN_TRICORE_GNUC_CC) $(B_GNUC_TRICORE_CC_OPTIONS) -DBOARD=SHIELD_BUDDY @$(B_GEN_INC_LISTFILE_TRICORE) $(B_GEN_EXT_INCLUDE_PATHS) -c $< -o $@ -save-temps=obj -MMD

#Make-rule to build file: IfxEray_cfg.c
B_GEN_DEP_FILES+= 2_Out/Tricore_Gnuc/Gnuc_Files/2_ExtSrc/BaseSw/iLLD/TC27D/Tricore/_Impl/IfxEray_cfg.d
B_GEN_OBJS_TRICORE_TC+= 2_Out/Tricore_Gnuc/Gnuc_Files/2_ExtSrc/BaseSw/iLLD/TC27D/Tricore/_Impl/IfxEray_cfg.o

2_Out/Tricore_Gnuc/Gnuc_Files/2_ExtSrc/BaseSw/iLLD/TC27D/Tricore/_Impl/IfxEray_cfg.o: ../_LibSrc/iLLD_1_0_1_8_0__TC27D/Src/BaseSw/iLLD/TC27D/Tricore/_Impl/IfxEray_cfg.c $(B_GEN_CONFIG_TRICORE_GNUC)
	@mkdir -p $(@D)
	@-rm -f $(B_GEN_ELF_TRICORE_TC) $(B_GEN_HEX_TRICORE_TC)
	@echo 'Building source file IfxEray_cfg.c for Tricore'
	$(B_GEN_TRICORE_GNUC_CC) $(B_GNUC_TRICORE_CC_OPTIONS) -DBOARD=SHIELD_BUDDY @$(B_GEN_INC_LISTFILE_TRICORE) $(B_GEN_EXT_INCLUDE_PATHS) -c $< -o $@ -save-temps=obj -MMD

#Make-rule to build file: IfxFlash_cfg.c
B_GEN_DEP_FILES+= 2_Out/Tricore_Gnuc/Gnuc_Files/2_ExtSrc/BaseSw/iLLD/TC27D/Tricore/_Impl/IfxFlash_cfg.d
B_GEN_OBJS_TRICORE_TC+= 2_Out/Tricore_Gnuc/Gnuc_Files/2_ExtSrc/BaseSw/iLLD/TC27D/Tricore/_Impl/IfxFlash_cfg.o

2_Out/Tricore_Gnuc/Gnuc_Files/2_ExtSrc/BaseSw/iLLD/TC27D/Tricore/_Impl/IfxFlash_cfg.o: ../_LibSrc/iLLD_1_0_1_8_0__TC27D/Src/BaseSw/iLLD/TC27D/Tricore/_Impl/IfxFlash_cfg.c $(B_GEN_CONFIG_TRICORE_GNUC)
	@mkdir -p $(@D)
	@-rm -f $(B_GEN_ELF_TRICORE_TC) $(B_GEN_HEX_TRICORE_TC)
	@echo 'Building source file IfxFlash_cfg.c for Tricore'
	$(B_GEN_TRICORE_GNUC_CC) $(B_GNUC_TRICORE_CC_OPTIONS) -DBOARD=SHIELD_BUDDY @$(B_GEN_INC_LISTFILE_TRICORE) $(B_GEN_EXT_INCLUDE_PATHS) -c $< -o $@ -save-temps=obj -MMD

#Make-rule to build file: IfxGtm_cfg.c
B_GEN_DEP_FILES+= 2_Out/Tricore_Gnuc/Gnuc_Files/2_ExtSrc/BaseSw/iLLD/TC27D/Tricore/_Impl/IfxGtm_cfg.d
B_GEN_OBJS_TRICORE_TC+= 2_Out/Tricore_Gnuc/Gnuc_Files/2_ExtSrc/BaseSw/iLLD/TC27D/Tricore/_Impl/IfxGtm_cfg.o

2_Out/Tricore_Gnuc/Gnuc_Files/2_ExtSrc/BaseSw/iLLD/TC27D/Tricore/_Impl/IfxGtm_cfg.o: ../_LibSrc/iLLD_1_0_1_8_0__TC27D/Src/BaseSw/iLLD/TC27D/Tricore/_Impl/IfxGtm_cfg.c $(B_GEN_CONFIG_TRICORE_GNUC)
	@mkdir -p $(@D)
	@-rm -f $(B_GEN_ELF_TRICORE_TC) $(B_GEN_HEX_TRICORE_TC)
	@echo 'Building source file IfxGtm_cfg.c for Tricore'
	$(B_GEN_TRICORE_GNUC_CC) $(B_GNUC_TRICORE_CC_OPTIONS) -DBOARD=SHIELD_BUDDY @$(B_GEN_INC_LISTFILE_TRICORE) $(B_GEN_EXT_INCLUDE_PATHS) -c $< -o $@ -save-temps=obj -MMD

#Make-rule to build file: IfxHssl_cfg.c
B_GEN_DEP_FILES+= 2_Out/Tricore_Gnuc/Gnuc_Files/2_ExtSrc/BaseSw/iLLD/TC27D/Tricore/_Impl/IfxHssl_cfg.d
B_GEN_OBJS_TRICORE_TC+= 2_Out/Tricore_Gnuc/Gnuc_Files/2_ExtSrc/BaseSw/iLLD/TC27D/Tricore/_Impl/IfxHssl_cfg.o

2_Out/Tricore_Gnuc/Gnuc_Files/2_ExtSrc/BaseSw/iLLD/TC27D/Tricore/_Impl/IfxHssl_cfg.o: ../_LibSrc/iLLD_1_0_1_8_0__TC27D/Src/BaseSw/iLLD/TC27D/Tricore/_Impl/IfxHssl_cfg.c $(B_GEN_CONFIG_TRICORE_GNUC)
	@mkdir -p $(@D)
	@-rm -f $(B_GEN_ELF_TRICORE_TC) $(B_GEN_HEX_TRICORE_TC)
	@echo 'Building source file IfxHssl_cfg.c for Tricore'
	$(B_GEN_TRICORE_GNUC_CC) $(B_GNUC_TRICORE_CC_OPTIONS) -DBOARD=SHIELD_BUDDY @$(B_GEN_INC_LISTFILE_TRICORE) $(B_GEN_EXT_INCLUDE_PATHS) -c $< -o $@ -save-temps=obj -MMD

#Make-rule to build file: IfxI2c_cfg.c
B_GEN_DEP_FILES+= 2_Out/Tricore_Gnuc/Gnuc_Files/2_ExtSrc/BaseSw/iLLD/TC27D/Tricore/_Impl/IfxI2c_cfg.d
B_GEN_OBJS_TRICORE_TC+= 2_Out/Tricore_Gnuc/Gnuc_Files/2_ExtSrc/BaseSw/iLLD/TC27D/Tricore/_Impl/IfxI2c_cfg.o

2_Out/Tricore_Gnuc/Gnuc_Files/2_ExtSrc/BaseSw/iLLD/TC27D/Tricore/_Impl/IfxI2c_cfg.o: ../_LibSrc/iLLD_1_0_1_8_0__TC27D/Src/BaseSw/iLLD/TC27D/Tricore/_Impl/IfxI2c_cfg.c $(B_GEN_CONFIG_TRICORE_GNUC)
	@mkdir -p $(@D)
	@-rm -f $(B_GEN_ELF_TRICORE_TC) $(B_GEN_HEX_TRICORE_TC)
	@echo 'Building source file IfxI2c_cfg.c for Tricore'
	$(B_GEN_TRICORE_GNUC_CC) $(B_GNUC_TRICORE_CC_OPTIONS) -DBOARD=SHIELD_BUDDY @$(B_GEN_INC_LISTFILE_TRICORE) $(B_GEN_EXT_INCLUDE_PATHS) -c $< -o $@ -save-temps=obj -MMD

#Make-rule to build file: IfxMsc_cfg.c
B_GEN_DEP_FILES+= 2_Out/Tricore_Gnuc/Gnuc_Files/2_ExtSrc/BaseSw/iLLD/TC27D/Tricore/_Impl/IfxMsc_cfg.d
B_GEN_OBJS_TRICORE_TC+= 2_Out/Tricore_Gnuc/Gnuc_Files/2_ExtSrc/BaseSw/iLLD/TC27D/Tricore/_Impl/IfxMsc_cfg.o

2_Out/Tricore_Gnuc/Gnuc_Files/2_ExtSrc/BaseSw/iLLD/TC27D/Tricore/_Impl/IfxMsc_cfg.o: ../_LibSrc/iLLD_1_0_1_8_0__TC27D/Src/BaseSw/iLLD/TC27D/Tricore/_Impl/IfxMsc_cfg.c $(B_GEN_CONFIG_TRICORE_GNUC)
	@mkdir -p $(@D)
	@-rm -f $(B_GEN_ELF_TRICORE_TC) $(B_GEN_HEX_TRICORE_TC)
	@echo 'Building source file IfxMsc_cfg.c for Tricore'
	$(B_GEN_TRICORE_GNUC_CC) $(B_GNUC_TRICORE_CC_OPTIONS) -DBOARD=SHIELD_BUDDY @$(B_GEN_INC_LISTFILE_TRICORE) $(B_GEN_EXT_INCLUDE_PATHS) -c $< -o $@ -save-temps=obj -MMD

#Make-rule to build file: IfxMtu_cfg.c
B_GEN_DEP_FILES+= 2_Out/Tricore_Gnuc/Gnuc_Files/2_ExtSrc/BaseSw/iLLD/TC27D/Tricore/_Impl/IfxMtu_cfg.d
B_GEN_OBJS_TRICORE_TC+= 2_Out/Tricore_Gnuc/Gnuc_Files/2_ExtSrc/BaseSw/iLLD/TC27D/Tricore/_Impl/IfxMtu_cfg.o

2_Out/Tricore_Gnuc/Gnuc_Files/2_ExtSrc/BaseSw/iLLD/TC27D/Tricore/_Impl/IfxMtu_cfg.o: ../_LibSrc/iLLD_1_0_1_8_0__TC27D/Src/BaseSw/iLLD/TC27D/Tricore/_Impl/IfxMtu_cfg.c $(B_GEN_CONFIG_TRICORE_GNUC)
	@mkdir -p $(@D)
	@-rm -f $(B_GEN_ELF_TRICORE_TC) $(B_GEN_HEX_TRICORE_TC)
	@echo 'Building source file IfxMtu_cfg.c for Tricore'
	$(B_GEN_TRICORE_GNUC_CC) $(B_GNUC_TRICORE_CC_OPTIONS) -DBOARD=SHIELD_BUDDY @$(B_GEN_INC_LISTFILE_TRICORE) $(B_GEN_EXT_INCLUDE_PATHS) -c $< -o $@ -save-temps=obj -MMD

#Make-rule to build file: IfxMultican_cfg.c
B_GEN_DEP_FILES+= 2_Out/Tricore_Gnuc/Gnuc_Files/2_ExtSrc/BaseSw/iLLD/TC27D/Tricore/_Impl/IfxMultican_cfg.d
B_GEN_OBJS_TRICORE_TC+= 2_Out/Tricore_Gnuc/Gnuc_Files/2_ExtSrc/BaseSw/iLLD/TC27D/Tricore/_Impl/IfxMultican_cfg.o

2_Out/Tricore_Gnuc/Gnuc_Files/2_ExtSrc/BaseSw/iLLD/TC27D/Tricore/_Impl/IfxMultican_cfg.o: ../_LibSrc/iLLD_1_0_1_8_0__TC27D/Src/BaseSw/iLLD/TC27D/Tricore/_Impl/IfxMultican_cfg.c $(B_GEN_CONFIG_TRICORE_GNUC)
	@mkdir -p $(@D)
	@-rm -f $(B_GEN_ELF_TRICORE_TC) $(B_GEN_HEX_TRICORE_TC)
	@echo 'Building source file IfxMultican_cfg.c for Tricore'
	$(B_GEN_TRICORE_GNUC_CC) $(B_GNUC_TRICORE_CC_OPTIONS) -DBOARD=SHIELD_BUDDY @$(B_GEN_INC_LISTFILE_TRICORE) $(B_GEN_EXT_INCLUDE_PATHS) -c $< -o $@ -save-temps=obj -MMD

#Make-rule to build file: IfxPort_cfg.c
B_GEN_DEP_FILES+= 2_Out/Tricore_Gnuc/Gnuc_Files/2_ExtSrc/BaseSw/iLLD/TC27D/Tricore/_Impl/IfxPort_cfg.d
B_GEN_OBJS_TRICORE_TC+= 2_Out/Tricore_Gnuc/Gnuc_Files/2_ExtSrc/BaseSw/iLLD/TC27D/Tricore/_Impl/IfxPort_cfg.o

2_Out/Tricore_Gnuc/Gnuc_Files/2_ExtSrc/BaseSw/iLLD/TC27D/Tricore/_Impl/IfxPort_cfg.o: ../_LibSrc/iLLD_1_0_1_8_0__TC27D/Src/BaseSw/iLLD/TC27D/Tricore/_Impl/IfxPort_cfg.c $(B_GEN_CONFIG_TRICORE_GNUC)
	@mkdir -p $(@D)
	@-rm -f $(B_GEN_ELF_TRICORE_TC) $(B_GEN_HEX_TRICORE_TC)
	@echo 'Building source file IfxPort_cfg.c for Tricore'
	$(B_GEN_TRICORE_GNUC_CC) $(B_GNUC_TRICORE_CC_OPTIONS) -DBOARD=SHIELD_BUDDY @$(B_GEN_INC_LISTFILE_TRICORE) $(B_GEN_EXT_INCLUDE_PATHS) -c $< -o $@ -save-temps=obj -MMD

#Make-rule to build file: IfxPsi5s_cfg.c
B_GEN_DEP_FILES+= 2_Out/Tricore_Gnuc/Gnuc_Files/2_ExtSrc/BaseSw/iLLD/TC27D/Tricore/_Impl/IfxPsi5s_cfg.d
B_GEN_OBJS_TRICORE_TC+= 2_Out/Tricore_Gnuc/Gnuc_Files/2_ExtSrc/BaseSw/iLLD/TC27D/Tricore/_Impl/IfxPsi5s_cfg.o

2_Out/Tricore_Gnuc/Gnuc_Files/2_ExtSrc/BaseSw/iLLD/TC27D/Tricore/_Impl/IfxPsi5s_cfg.o: ../_LibSrc/iLLD_1_0_1_8_0__TC27D/Src/BaseSw/iLLD/TC27D/Tricore/_Impl/IfxPsi5s_cfg.c $(B_GEN_CONFIG_TRICORE_GNUC)
	@mkdir -p $(@D)
	@-rm -f $(B_GEN_ELF_TRICORE_TC) $(B_GEN_HEX_TRICORE_TC)
	@echo 'Building source file IfxPsi5s_cfg.c for Tricore'
	$(B_GEN_TRICORE_GNUC_CC) $(B_GNUC_TRICORE_CC_OPTIONS) -DBOARD=SHIELD_BUDDY @$(B_GEN_INC_LISTFILE_TRICORE) $(B_GEN_EXT_INCLUDE_PATHS) -c $< -o $@ -save-temps=obj -MMD

#Make-rule to build file: IfxPsi5_cfg.c
B_GEN_DEP_FILES+= 2_Out/Tricore_Gnuc/Gnuc_Files/2_ExtSrc/BaseSw/iLLD/TC27D/Tricore/_Impl/IfxPsi5_cfg.d
B_GEN_OBJS_TRICORE_TC+= 2_Out/Tricore_Gnuc/Gnuc_Files/2_ExtSrc/BaseSw/iLLD/TC27D/Tricore/_Impl/IfxPsi5_cfg.o

2_Out/Tricore_Gnuc/Gnuc_Files/2_ExtSrc/BaseSw/iLLD/TC27D/Tricore/_Impl/IfxPsi5_cfg.o: ../_LibSrc/iLLD_1_0_1_8_0__TC27D/Src/BaseSw/iLLD/TC27D/Tricore/_Impl/IfxPsi5_cfg.c $(B_GEN_CONFIG_TRICORE_GNUC)
	@mkdir -p $(@D)
	@-rm -f $(B_GEN_ELF_TRICORE_TC) $(B_GEN_HEX_TRICORE_TC)
	@echo 'Building source file IfxPsi5_cfg.c for Tricore'
	$(B_GEN_TRICORE_GNUC_CC) $(B_GNUC_TRICORE_CC_OPTIONS) -DBOARD=SHIELD_BUDDY @$(B_GEN_INC_LISTFILE_TRICORE) $(B_GEN_EXT_INCLUDE_PATHS) -c $< -o $@ -save-temps=obj -MMD

#Make-rule to build file: IfxQspi_cfg.c
B_GEN_DEP_FILES+= 2_Out/Tricore_Gnuc/Gnuc_Files/2_ExtSrc/BaseSw/iLLD/TC27D/Tricore/_Impl/IfxQspi_cfg.d
B_GEN_OBJS_TRICORE_TC+= 2_Out/Tricore_Gnuc/Gnuc_Files/2_ExtSrc/BaseSw/iLLD/TC27D/Tricore/_Impl/IfxQspi_cfg.o

2_Out/Tricore_Gnuc/Gnuc_Files/2_ExtSrc/BaseSw/iLLD/TC27D/Tricore/_Impl/IfxQspi_cfg.o: ../_LibSrc/iLLD_1_0_1_8_0__TC27D/Src/BaseSw/iLLD/TC27D/Tricore/_Impl/IfxQspi_cfg.c $(B_GEN_CONFIG_TRICORE_GNUC)
	@mkdir -p $(@D)
	@-rm -f $(B_GEN_ELF_TRICORE_TC) $(B_GEN_HEX_TRICORE_TC)
	@echo 'Building source file IfxQspi_cfg.c for Tricore'
	$(B_GEN_TRICORE_GNUC_CC) $(B_GNUC_TRICORE_CC_OPTIONS) -DBOARD=SHIELD_BUDDY @$(B_GEN_INC_LISTFILE_TRICORE) $(B_GEN_EXT_INCLUDE_PATHS) -c $< -o $@ -save-temps=obj -MMD

#Make-rule to build file: IfxScu_cfg.c
B_GEN_DEP_FILES+= 2_Out/Tricore_Gnuc/Gnuc_Files/2_ExtSrc/BaseSw/iLLD/TC27D/Tricore/_Impl/IfxScu_cfg.d
B_GEN_OBJS_TRICORE_TC+= 2_Out/Tricore_Gnuc/Gnuc_Files/2_ExtSrc/BaseSw/iLLD/TC27D/Tricore/_Impl/IfxScu_cfg.o

2_Out/Tricore_Gnuc/Gnuc_Files/2_ExtSrc/BaseSw/iLLD/TC27D/Tricore/_Impl/IfxScu_cfg.o: ../_LibSrc/iLLD_1_0_1_8_0__TC27D/Src/BaseSw/iLLD/TC27D/Tricore/_Impl/IfxScu_cfg.c $(B_GEN_CONFIG_TRICORE_GNUC)
	@mkdir -p $(@D)
	@-rm -f $(B_GEN_ELF_TRICORE_TC) $(B_GEN_HEX_TRICORE_TC)
	@echo 'Building source file IfxScu_cfg.c for Tricore'
	$(B_GEN_TRICORE_GNUC_CC) $(B_GNUC_TRICORE_CC_OPTIONS) -DBOARD=SHIELD_BUDDY @$(B_GEN_INC_LISTFILE_TRICORE) $(B_GEN_EXT_INCLUDE_PATHS) -c $< -o $@ -save-temps=obj -MMD

#Make-rule to build file: IfxSent_cfg.c
B_GEN_DEP_FILES+= 2_Out/Tricore_Gnuc/Gnuc_Files/2_ExtSrc/BaseSw/iLLD/TC27D/Tricore/_Impl/IfxSent_cfg.d
B_GEN_OBJS_TRICORE_TC+= 2_Out/Tricore_Gnuc/Gnuc_Files/2_ExtSrc/BaseSw/iLLD/TC27D/Tricore/_Impl/IfxSent_cfg.o

2_Out/Tricore_Gnuc/Gnuc_Files/2_ExtSrc/BaseSw/iLLD/TC27D/Tricore/_Impl/IfxSent_cfg.o: ../_LibSrc/iLLD_1_0_1_8_0__TC27D/Src/BaseSw/iLLD/TC27D/Tricore/_Impl/IfxSent_cfg.c $(B_GEN_CONFIG_TRICORE_GNUC)
	@mkdir -p $(@D)
	@-rm -f $(B_GEN_ELF_TRICORE_TC) $(B_GEN_HEX_TRICORE_TC)
	@echo 'Building source file IfxSent_cfg.c for Tricore'
	$(B_GEN_TRICORE_GNUC_CC) $(B_GNUC_TRICORE_CC_OPTIONS) -DBOARD=SHIELD_BUDDY @$(B_GEN_INC_LISTFILE_TRICORE) $(B_GEN_EXT_INCLUDE_PATHS) -c $< -o $@ -save-temps=obj -MMD

#Make-rule to build file: IfxSmu_cfg.c
B_GEN_DEP_FILES+= 2_Out/Tricore_Gnuc/Gnuc_Files/2_ExtSrc/BaseSw/iLLD/TC27D/Tricore/_Impl/IfxSmu_cfg.d
B_GEN_OBJS_TRICORE_TC+= 2_Out/Tricore_Gnuc/Gnuc_Files/2_ExtSrc/BaseSw/iLLD/TC27D/Tricore/_Impl/IfxSmu_cfg.o

2_Out/Tricore_Gnuc/Gnuc_Files/2_ExtSrc/BaseSw/iLLD/TC27D/Tricore/_Impl/IfxSmu_cfg.o: ../_LibSrc/iLLD_1_0_1_8_0__TC27D/Src/BaseSw/iLLD/TC27D/Tricore/_Impl/IfxSmu_cfg.c $(B_GEN_CONFIG_TRICORE_GNUC)
	@mkdir -p $(@D)
	@-rm -f $(B_GEN_ELF_TRICORE_TC) $(B_GEN_HEX_TRICORE_TC)
	@echo 'Building source file IfxSmu_cfg.c for Tricore'
	$(B_GEN_TRICORE_GNUC_CC) $(B_GNUC_TRICORE_CC_OPTIONS) -DBOARD=SHIELD_BUDDY @$(B_GEN_INC_LISTFILE_TRICORE) $(B_GEN_EXT_INCLUDE_PATHS) -c $< -o $@ -save-temps=obj -MMD

#Make-rule to build file: IfxSrc_cfg.c
B_GEN_DEP_FILES+= 2_Out/Tricore_Gnuc/Gnuc_Files/2_ExtSrc/BaseSw/iLLD/TC27D/Tricore/_Impl/IfxSrc_cfg.d
B_GEN_OBJS_TRICORE_TC+= 2_Out/Tricore_Gnuc/Gnuc_Files/2_ExtSrc/BaseSw/iLLD/TC27D/Tricore/_Impl/IfxSrc_cfg.o

2_Out/Tricore_Gnuc/Gnuc_Files/2_ExtSrc/BaseSw/iLLD/TC27D/Tricore/_Impl/IfxSrc_cfg.o: ../_LibSrc/iLLD_1_0_1_8_0__TC27D/Src/BaseSw/iLLD/TC27D/Tricore/_Impl/IfxSrc_cfg.c $(B_GEN_CONFIG_TRICORE_GNUC)
	@mkdir -p $(@D)
	@-rm -f $(B_GEN_ELF_TRICORE_TC) $(B_GEN_HEX_TRICORE_TC)
	@echo 'Building source file IfxSrc_cfg.c for Tricore'
	$(B_GEN_TRICORE_GNUC_CC) $(B_GNUC_TRICORE_CC_OPTIONS) -DBOARD=SHIELD_BUDDY @$(B_GEN_INC_LISTFILE_TRICORE) $(B_GEN_EXT_INCLUDE_PATHS) -c $< -o $@ -save-temps=obj -MMD

#Make-rule to build file: IfxStm_cfg.c
B_GEN_DEP_FILES+= 2_Out/Tricore_Gnuc/Gnuc_Files/2_ExtSrc/BaseSw/iLLD/TC27D/Tricore/_Impl/IfxStm_cfg.d
B_GEN_OBJS_TRICORE_TC+= 2_Out/Tricore_Gnuc/Gnuc_Files/2_ExtSrc/BaseSw/iLLD/TC27D/Tricore/_Impl/IfxStm_cfg.o

2_Out/Tricore_Gnuc/Gnuc_Files/2_ExtSrc/BaseSw/iLLD/TC27D/Tricore/_Impl/IfxStm_cfg.o: ../_LibSrc/iLLD_1_0_1_8_0__TC27D/Src/BaseSw/iLLD/TC27D/Tricore/_Impl/IfxStm_cfg.c $(B_GEN_CONFIG_TRICORE_GNUC)
	@mkdir -p $(@D)
	@-rm -f $(B_GEN_ELF_TRICORE_TC) $(B_GEN_HEX_TRICORE_TC)
	@echo 'Building source file IfxStm_cfg.c for Tricore'
	$(B_GEN_TRICORE_GNUC_CC) $(B_GNUC_TRICORE_CC_OPTIONS) -DBOARD=SHIELD_BUDDY @$(B_GEN_INC_LISTFILE_TRICORE) $(B_GEN_EXT_INCLUDE_PATHS) -c $< -o $@ -save-temps=obj -MMD

#Make-rule to build file: IfxVadc_cfg.c
B_GEN_DEP_FILES+= 2_Out/Tricore_Gnuc/Gnuc_Files/2_ExtSrc/BaseSw/iLLD/TC27D/Tricore/_Impl/IfxVadc_cfg.d
B_GEN_OBJS_TRICORE_TC+= 2_Out/Tricore_Gnuc/Gnuc_Files/2_ExtSrc/BaseSw/iLLD/TC27D/Tricore/_Impl/IfxVadc_cfg.o

2_Out/Tricore_Gnuc/Gnuc_Files/2_ExtSrc/BaseSw/iLLD/TC27D/Tricore/_Impl/IfxVadc_cfg.o: ../_LibSrc/iLLD_1_0_1_8_0__TC27D/Src/BaseSw/iLLD/TC27D/Tricore/_Impl/IfxVadc_cfg.c $(B_GEN_CONFIG_TRICORE_GNUC)
	@mkdir -p $(@D)
	@-rm -f $(B_GEN_ELF_TRICORE_TC) $(B_GEN_HEX_TRICORE_TC)
	@echo 'Building source file IfxVadc_cfg.c for Tricore'
	$(B_GEN_TRICORE_GNUC_CC) $(B_GNUC_TRICORE_CC_OPTIONS) -DBOARD=SHIELD_BUDDY @$(B_GEN_INC_LISTFILE_TRICORE) $(B_GEN_EXT_INCLUDE_PATHS) -c $< -o $@ -save-temps=obj -MMD
