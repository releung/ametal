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
 * \brief bootloader �̼��洢�Ľӿ�
 *
 * \internal
 * \par Modification history
 * - 1.00 18-11-16  yrh, first implementation
 * \endinternal
 */

#ifndef __AM_BOOT_FIRMWARE_H
#define __AM_BOOT_FIRMWARE_H

#include "ametal.h"

struct am_boot_firmware_drv_funcs {
    /**< \brief �̼��洢��ʼ��������*/
    int (*pfn_store_start)(void *p_drv, uint32_t firmware_size);

    /**< \brief �̼��洢��������*/
    int (*pfn_store_bytes)(void *p_drv, uint8_t *p_data, uint32_t firmware_size);

    /**< \brief �̼��洢������������*/
    int (*pfn_store_final)(void *p_drv);
};

typedef struct am_boot_firmware_serv {
    struct am_boot_firmware_drv_funcs *pfn_funcs;
    void                              *p_drv;
}am_boot_firmware_serv_t;

typedef am_boot_firmware_serv_t *am_boot_firmware_handle_t;

/**
 * \brief �̼��洢�Ŀ�ʼ����
 *
 * �����ʱ��֪���̼��ĳ��ȿ��Էֱ���0.���֪���̼��Ĵ�С��ֱ�Ӵ���̼��Ĵ�С
 *
 * \param[in] total_firmware_size : �̼����ܳ���
 *
 * \retval AM_ENOMEM   �̼������ڴ��С
 * \retval AM_EFAULT   �̼���ŵĵ�ַ����1.��ַ���󣬲��������Ĵ洢��Χ��2.�����������׵�ַ��
 * \retval AM_EINVAL   ����Ĳ������Ϸ�
 * \retval AM_OK       �ɹ�
 */
am_static_inline
int am_boot_firmware_store_start(am_boot_firmware_handle_t  handle,
                                 uint32_t                   total_firmware_size)
{
    return handle->pfn_funcs->pfn_store_start(handle->p_drv, total_firmware_size);
}

/**
 * \brief �̼����ݴ洢
 *
 * ���̼���ŵ�Ԥ���õĵ�ַ��ȥ�����һ��ʼ�����ʱ��֪���̼��Ĵ�С����ô����am_boot_firmware_store_startʱ��
 * �ڶ��������̼��Ĵ�С����0���������am_boot_firmware_store_bytesʱ����Ҫһ�߲���flash��һ�߽���flashд.
 * ����am_boot_firmware_store_bytes��������ִ����Ҫһ����ʱ�䣬����ʱע��̼������ʱ�䡣
 *
 * \param[in] p_data        : ����Ĺ̼����׵�ַ
 * \param[in] firmware_size : �̼����ȣ�Ҫ��4����������С����󲻹��Ĳ�0��
 *
 * \retval AM_EINVAL   ������Ч
 * \retval AM_ENOMEM   �ռ䣨�ڴ棩����
 * \retval AM_ERROR    ������д��ʧ��
 * \retval AM_OK       �ɹ�
 */
am_static_inline
int am_boot_firmware_store_bytes(am_boot_firmware_handle_t handle,
                                 uint8_t                  *p_data,
                                 uint32_t                  firmware_size)
{
    return handle->pfn_funcs->pfn_store_bytes(handle->p_drv, p_data, firmware_size);
}

/**
 * \brief �̼��洢�Ľ���
 *
 * \retval AM_ERROR ����
 * \retval AM_OK    �ɹ�
 */
am_static_inline
int am_boot_firmware_store_final(am_boot_firmware_handle_t handle)
{
    return handle->pfn_funcs->pfn_store_final(handle->p_drv);
}

#endif /* __AM_BOOT_FIRMWARE_H */

/* end of file */