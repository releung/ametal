/*******************************************************************************
*                                 AMetal
*                       ----------------------------
*                       innovating embedded platform
*
* Copyright (c) 2001-2018 Guangzhou ZHIYUAN Electronics Co., Ltd.
* All rights reserved.
*
* Contact information:
* web site:    http://www.zlg.cn/
*******************************************************************************/

/**
 * \file
 * \brief TIM14 定时器 CAP 例程，通过标准接口实现
 *
 * - 操作步骤：
 *   1. 使用杜邦线，将 PIOA_8 与 PIOB_8 连接。
 *
 * - 实验现象：
 *   1. TIM2 通过 PIOA_8 引脚输出 2KHz 的 PWM；
 *   2. TIM1 捕获输入通道 1 使用 PIOB_8 引脚捕获；
 *   3. 串口打印出利用捕获功能得到的 PWM 信号的周期和频率。
 *
 * \note
 *    1. 如需观察串口打印的调试信息，需要将 PIOA_9 引脚连接 PC 串口的 RXD；
 *    2. 由于 TIM4 默认初始化并作为系统滴答使用，使用本 Demo 之前必须在
 *       am_prj_config.h 内将 AM_CFG_KEY_GPIO_ENABLE、AM_CFG_SOFTIMER_ENABLE
 *       和 AM_CFG_SYSTEM_TICK_ENABLE 定义为 0。
 *
 * \par 源代码
 * \snippet demo_zmf159_core_std_tim4_cap.c src_zmf159_core_std_tim4_cap
 *
 * \internal
 * \par Modification history
 * - 1.00 16-04-22  nwt, first implementation
 * \endinternal
 */ 

/**
 * \addtogroup demo_if_zmf159_core_std_tim4_cap
 * \copydoc demo_zmf159_core_std_tim4_cap.c
 */

/** [src_zmf159_core_std_tim4_cap] */
#include <demo_zmf159_core_entries.h>
#include "ametal.h"
#include "am_pwm.h"
#include "am_vdebug.h"
#include "am_zmf159_inst_init.h"
#include "demo_std_entries.h"

/**
 * \brief 例程入口
 */
void demo_zmf159_core_std_tim4_cap_entry (void)
{
    am_pwm_handle_t pwm_handle = am_zmf159_tim1_pwm_inst_init();

    AM_DBG_INFO("demo zmf159_core std tim4 cap!\r\n");

    /* TIM2 输出频率为 2KHz 的 PWM */
    am_pwm_config(pwm_handle, 0, 500000 / 2, 500000);
    am_pwm_enable(pwm_handle, 0);

    demo_std_timer_cap_entry(am_zmf159_tim4_cap_inst_init(), 0);
}
/** [src_zmf159_core_std_tim4_cap] */

/* end of file */
