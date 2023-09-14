
/*
 * < CONFIG BOOT OPTION
 */
#undef  CONFIG_XIP_FLASH

/*
 * < CONFIG SOC PS
 */
#define CONFIG_SOC_PS_EN 1
#define CONFIG_SOC_PS_MODULE 1

/*
 * < CONFIG BT
 */
#undef  CONFIG_BT_MENU
#define  CONFIG_BT 1
#define  CONFIG_BT_AP 1
#undef  CONFIG_BT_NP
#undef  CONFIG_BT_SINGLE_CORE

/*
 * < CONFIG WIFI
 */
#define CONFIG_WLAN_MENU 1
#define CONFIG_AS_INIC_KM4_NP_CA32_AP 1
#undef  CONFIG_SINGLE_CORE_WIFI_KM4
#define CONFIG_WLAN 1
#define CONFIG_AS_INIC_AP 1
#define CONFIG_LWIP_LAYER 1
#if defined(CONFIG_PLATFORM_TIZENRT_OS)
#define  CONFIG_HIGH_TP_TEST 1
#else
#undef CONFIG_HIGH_TP_TEST
#endif


/*
 * < MENUCONFIG FOR AP CONFIG
 */

/*
 * < CONFIG CHIP
 */
#define CONFIG_AMEBAD2 1
#define ARM_CORE_CA32 1
#define CONFIG_FPGA 1
#define CONFIG_RL6678_A_CUT 1

/*
 * < CONFIG TEST MODE
 */
#undef  CONFIG_MP
#undef  CONFIG_CP
#undef  CONFIG_FT
#undef  CONFIG_EQC
#undef  CONFIG_OLT

/*
 * < CONFIG OS
 */
#define CONFIG_KERNEL 1
#define PLATFORM_FREERTOS 1
#define TASK_SCHEDULER_DISABLED (0)

/*
 * < CONFIG USB
 */
#undef  CONFIG_USB_OTG_EN

/*
 * < MBED_API
 */
#define CONFIG_MBED_API_EN 1

/*
 * < CONFIG FUNCTION TEST
 */
#undef  CONFIG_PER_TEST

/*
 * < CONFIG 802154
 */
#undef  CONFIG_802154_PHY_EN
#undef  CONFIG_802154_RADIO_COEX_PTA_EN

/*
 * < SSL Config
 */
#define CONFIG_MBED_TLS_ENABLED 1

/*
 * < Audio Config
 */
#undef  CONFIG_AUDIO_FWK
#undef  CONFIG_MEDIA_PLAYER
#undef  CONFIG_MEDIA_LITE_PLAYER

/*
 * < IPC Message Queue Config
 */
#undef  CONFIG_IMQ

/*
 * < CLINTWOOD Config
 */
#undef  CONFIG_CLINTWOOD

/*
 * < GUI Config
 */
#undef  CONFIG_GUI_EN

/*
 * To set debug msg flag
 */
#define CONFIG_DEBUG_LOG 1

/*
 * < Build Option
 */
#define CONFIG_TOOLCHAIN_ASDK 1
#undef  CONFIG_TOOLCHAIN_ARM_GCC
#define CONFIG_LINK_ROM_LIB 1
#undef  CONFIG_LINK_ROM_SYMB

/*
 * < CONFIG IAR PROJECT
 */
#if defined(CONFIG_INIC_IPC_DISABLE) && (CONFIG_INIC_IPC_DISABLE == 1)
#ifdef CONFIG_WLAN
#undef CONFIG_WLAN
#endif
#ifdef CONFIG_HIGH_TP_TEST
#undef CONFIG_HIGH_TP_TEST
#endif
#ifdef CONFIG_AS_INIC_AP
#undef CONFIG_AS_INIC_AP
#endif
#ifdef CONFIG_LWIP_LAYER
#undef CONFIG_LWIP_LAYER
#endif
#endif
#undef  CONFIG_AUDIO_MIXER
#undef  CONFIG_AUDIO_PASSTHROUGH
#undef  CONFIG_MEDIA_PLAYER
#undef  CONFIG_MEDIA_DEMUX_WAV
#undef  CONFIG_MEDIA_DEMUX_MP3
#undef  CONFIG_MEDIA_DEMUX_AAC
#undef  CONFIG_MEDIA_DEMUX_MP4
#undef  CONFIG_MEDIA_DEMUX_FLAC
#undef  CONFIG_MEDIA_DEMUX_OGG
#undef  CONFIG_MEDIA_CODEC_PCM
#undef  CONFIG_MEDIA_CODEC_MP3
#undef  CONFIG_MEDIA_CODEC_HAAC
#undef  CONFIG_MEDIA_CODEC_VORBIS
#undef  CONFIG_MEDIA_CODEC_OPUS