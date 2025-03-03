################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lvgl/lvgl/src/misc/lv_anim.c \
../lvgl/lvgl/src/misc/lv_anim_timeline.c \
../lvgl/lvgl/src/misc/lv_area.c \
../lvgl/lvgl/src/misc/lv_async.c \
../lvgl/lvgl/src/misc/lv_bidi.c \
../lvgl/lvgl/src/misc/lv_color.c \
../lvgl/lvgl/src/misc/lv_fs.c \
../lvgl/lvgl/src/misc/lv_gc.c \
../lvgl/lvgl/src/misc/lv_ll.c \
../lvgl/lvgl/src/misc/lv_log.c \
../lvgl/lvgl/src/misc/lv_lru.c \
../lvgl/lvgl/src/misc/lv_math.c \
../lvgl/lvgl/src/misc/lv_mem.c \
../lvgl/lvgl/src/misc/lv_printf.c \
../lvgl/lvgl/src/misc/lv_style.c \
../lvgl/lvgl/src/misc/lv_style_gen.c \
../lvgl/lvgl/src/misc/lv_templ.c \
../lvgl/lvgl/src/misc/lv_timer.c \
../lvgl/lvgl/src/misc/lv_tlsf.c \
../lvgl/lvgl/src/misc/lv_txt.c \
../lvgl/lvgl/src/misc/lv_txt_ap.c \
../lvgl/lvgl/src/misc/lv_utils.c 

C_DEPS += \
./lvgl/lvgl/src/misc/lv_anim.d \
./lvgl/lvgl/src/misc/lv_anim_timeline.d \
./lvgl/lvgl/src/misc/lv_area.d \
./lvgl/lvgl/src/misc/lv_async.d \
./lvgl/lvgl/src/misc/lv_bidi.d \
./lvgl/lvgl/src/misc/lv_color.d \
./lvgl/lvgl/src/misc/lv_fs.d \
./lvgl/lvgl/src/misc/lv_gc.d \
./lvgl/lvgl/src/misc/lv_ll.d \
./lvgl/lvgl/src/misc/lv_log.d \
./lvgl/lvgl/src/misc/lv_lru.d \
./lvgl/lvgl/src/misc/lv_math.d \
./lvgl/lvgl/src/misc/lv_mem.d \
./lvgl/lvgl/src/misc/lv_printf.d \
./lvgl/lvgl/src/misc/lv_style.d \
./lvgl/lvgl/src/misc/lv_style_gen.d \
./lvgl/lvgl/src/misc/lv_templ.d \
./lvgl/lvgl/src/misc/lv_timer.d \
./lvgl/lvgl/src/misc/lv_tlsf.d \
./lvgl/lvgl/src/misc/lv_txt.d \
./lvgl/lvgl/src/misc/lv_txt_ap.d \
./lvgl/lvgl/src/misc/lv_utils.d 

OBJS += \
./lvgl/lvgl/src/misc/lv_anim.o \
./lvgl/lvgl/src/misc/lv_anim_timeline.o \
./lvgl/lvgl/src/misc/lv_area.o \
./lvgl/lvgl/src/misc/lv_async.o \
./lvgl/lvgl/src/misc/lv_bidi.o \
./lvgl/lvgl/src/misc/lv_color.o \
./lvgl/lvgl/src/misc/lv_fs.o \
./lvgl/lvgl/src/misc/lv_gc.o \
./lvgl/lvgl/src/misc/lv_ll.o \
./lvgl/lvgl/src/misc/lv_log.o \
./lvgl/lvgl/src/misc/lv_lru.o \
./lvgl/lvgl/src/misc/lv_math.o \
./lvgl/lvgl/src/misc/lv_mem.o \
./lvgl/lvgl/src/misc/lv_printf.o \
./lvgl/lvgl/src/misc/lv_style.o \
./lvgl/lvgl/src/misc/lv_style_gen.o \
./lvgl/lvgl/src/misc/lv_templ.o \
./lvgl/lvgl/src/misc/lv_timer.o \
./lvgl/lvgl/src/misc/lv_tlsf.o \
./lvgl/lvgl/src/misc/lv_txt.o \
./lvgl/lvgl/src/misc/lv_txt_ap.o \
./lvgl/lvgl/src/misc/lv_utils.o 


# Each subdirectory must supply rules for building sources it contributes
lvgl/lvgl/src/misc/%.o: ../lvgl/lvgl/src/misc/%.c lvgl/lvgl/src/misc/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -std=gnu99 -DCPU_MCXN947VDF -DCPU_MCXN947VDF_cm33 -DCPU_MCXN947VDF_cm33_core0 -DLV_CONF_INCLUDE_SIMPLE=1 -DMCUXPRESSO_SDK -DSDK_I2C_BASED_COMPONENT_USED=1 -DSD_ENABLED -DSDK_DEBUGCONSOLE=1 -DCR_INTEGER_PRINTF -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -D__NEWLIB__ -I"D:\MCUXpresso-Project\frdmmcxn947_lvgl_canfd_lin_log\source" -I"D:\MCUXpresso-Project\frdmmcxn947_lvgl_canfd_lin_log\drivers" -I"D:\MCUXpresso-Project\frdmmcxn947_lvgl_canfd_lin_log\lcdc" -I"D:\MCUXpresso-Project\frdmmcxn947_lvgl_canfd_lin_log\sdmmc\host" -I"D:\MCUXpresso-Project\frdmmcxn947_lvgl_canfd_lin_log\sdmmc\inc" -I"D:\MCUXpresso-Project\frdmmcxn947_lvgl_canfd_lin_log\component\gpio" -I"D:\MCUXpresso-Project\frdmmcxn947_lvgl_canfd_lin_log\fatfs\source\fsl_sd_disk" -I"D:\MCUXpresso-Project\frdmmcxn947_lvgl_canfd_lin_log\fatfs\source" -I"D:\MCUXpresso-Project\frdmmcxn947_lvgl_canfd_lin_log\video" -I"D:\MCUXpresso-Project\frdmmcxn947_lvgl_canfd_lin_log\touchpanel" -I"D:\MCUXpresso-Project\frdmmcxn947_lvgl_canfd_lin_log\utilities" -I"D:\MCUXpresso-Project\frdmmcxn947_lvgl_canfd_lin_log\lvgl\lvgl" -I"D:\MCUXpresso-Project\frdmmcxn947_lvgl_canfd_lin_log\lvgl\lvgl\src" -I"D:\MCUXpresso-Project\frdmmcxn947_lvgl_canfd_lin_log\lvgl" -I"D:\MCUXpresso-Project\frdmmcxn947_lvgl_canfd_lin_log\device" -I"D:\MCUXpresso-Project\frdmmcxn947_lvgl_canfd_lin_log\startup" -I"D:\MCUXpresso-Project\frdmmcxn947_lvgl_canfd_lin_log\component\uart" -I"D:\MCUXpresso-Project\frdmmcxn947_lvgl_canfd_lin_log\component\lists" -I"D:\MCUXpresso-Project\frdmmcxn947_lvgl_canfd_lin_log\sdmmc\osa" -I"D:\MCUXpresso-Project\frdmmcxn947_lvgl_canfd_lin_log\component\osa" -I"D:\MCUXpresso-Project\frdmmcxn947_lvgl_canfd_lin_log\sdmmc\template\usdhc" -I"D:\MCUXpresso-Project\frdmmcxn947_lvgl_canfd_lin_log\CMSIS" -I"D:\MCUXpresso-Project\frdmmcxn947_lvgl_canfd_lin_log\board" -I"D:\MCUXpresso-Project\frdmmcxn947_lvgl_canfd_lin_log\generated" -I"D:\MCUXpresso-Project\frdmmcxn947_lvgl_canfd_lin_log\custom" -I"D:\MCUXpresso-Project\frdmmcxn947_lvgl_canfd_lin_log\generated\guider_customer_fonts" -I"D:\MCUXpresso-Project\frdmmcxn947_lvgl_canfd_lin_log\generated\guider_fonts" -I"D:\MCUXpresso-Project\frdmmcxn947_lvgl_canfd_lin_log\lvgl\template" -O0 -fno-common -g3 -gdwarf-4 -Wall -mcpu=cortex-m33 -c -ffunction-sections -fdata-sections -fno-builtin -Wno-format -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m33 -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -D__NEWLIB__ -fstack-usage -specs=nano.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-lvgl-2f-lvgl-2f-src-2f-misc

clean-lvgl-2f-lvgl-2f-src-2f-misc:
	-$(RM) ./lvgl/lvgl/src/misc/lv_anim.d ./lvgl/lvgl/src/misc/lv_anim.o ./lvgl/lvgl/src/misc/lv_anim_timeline.d ./lvgl/lvgl/src/misc/lv_anim_timeline.o ./lvgl/lvgl/src/misc/lv_area.d ./lvgl/lvgl/src/misc/lv_area.o ./lvgl/lvgl/src/misc/lv_async.d ./lvgl/lvgl/src/misc/lv_async.o ./lvgl/lvgl/src/misc/lv_bidi.d ./lvgl/lvgl/src/misc/lv_bidi.o ./lvgl/lvgl/src/misc/lv_color.d ./lvgl/lvgl/src/misc/lv_color.o ./lvgl/lvgl/src/misc/lv_fs.d ./lvgl/lvgl/src/misc/lv_fs.o ./lvgl/lvgl/src/misc/lv_gc.d ./lvgl/lvgl/src/misc/lv_gc.o ./lvgl/lvgl/src/misc/lv_ll.d ./lvgl/lvgl/src/misc/lv_ll.o ./lvgl/lvgl/src/misc/lv_log.d ./lvgl/lvgl/src/misc/lv_log.o ./lvgl/lvgl/src/misc/lv_lru.d ./lvgl/lvgl/src/misc/lv_lru.o ./lvgl/lvgl/src/misc/lv_math.d ./lvgl/lvgl/src/misc/lv_math.o ./lvgl/lvgl/src/misc/lv_mem.d ./lvgl/lvgl/src/misc/lv_mem.o ./lvgl/lvgl/src/misc/lv_printf.d ./lvgl/lvgl/src/misc/lv_printf.o ./lvgl/lvgl/src/misc/lv_style.d ./lvgl/lvgl/src/misc/lv_style.o ./lvgl/lvgl/src/misc/lv_style_gen.d ./lvgl/lvgl/src/misc/lv_style_gen.o ./lvgl/lvgl/src/misc/lv_templ.d ./lvgl/lvgl/src/misc/lv_templ.o ./lvgl/lvgl/src/misc/lv_timer.d ./lvgl/lvgl/src/misc/lv_timer.o ./lvgl/lvgl/src/misc/lv_tlsf.d ./lvgl/lvgl/src/misc/lv_tlsf.o ./lvgl/lvgl/src/misc/lv_txt.d ./lvgl/lvgl/src/misc/lv_txt.o ./lvgl/lvgl/src/misc/lv_txt_ap.d ./lvgl/lvgl/src/misc/lv_txt_ap.o ./lvgl/lvgl/src/misc/lv_utils.d ./lvgl/lvgl/src/misc/lv_utils.o

.PHONY: clean-lvgl-2f-lvgl-2f-src-2f-misc

