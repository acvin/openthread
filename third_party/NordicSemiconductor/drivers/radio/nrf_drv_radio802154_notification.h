/* Copyright (c) 2017, Nordic Semiconductor ASA
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *   1. Redistributions of source code must retain the above copyright notice, this
 *      list of conditions and the following disclaimer.
 *
 *   2. Redistributions in binary form must reproduce the above copyright notice,
 *      this list of conditions and the following disclaimer in the documentation
 *      and/or other materials provided with the distribution.
 *
 *   3. Neither the name of Nordic Semiconductor ASA nor the names of its
 *      contributors may be used to endorse or promote products derived from
 *      this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#ifndef NRF_DRIVER_RADIO802154_NOTIFICATION_H__
#define NRF_DRIVER_RADIO802154_NOTIFICATION_H__

#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @defgroup nrf_driver_radio802154_notification 802.15.4 driver notification
 * @{
 * @ingroup nrf_driver_radio802154
 * @brief Notifications to the next higher layer triggered from 802.15.4 radio driver.
 */

/**
 * @brief Initialize notification module.
 */
void nrf_drv_radio802154_notification_init(void);

/**
 * @brief Notify next higher layer that a frame was received.
 *
 * @param[in]  p_data  Array of bytes containing PSDU. First byte contains frame length, other contain the frame itself.
 * @param[in]  power   RSSI measured during the frame reception.
 * @param[in]  lqi     LQI indicating measured link quality during the frame reception.
 */
void nrf_drv_radio802154_notify_received(uint8_t * p_data, int8_t power, int8_t lqi);

/**
 * @brief Notify next higher layer that a frame was transmitted.
 *
 * @param[in]  p_ack  Pointer to buffer containing PSDU of ACK frame. NULL if ACK was not requested.
 * @param[in]  power  RSSI of received frame or 0 if ACK was not requested.
 * @param[in]  lqi    LQI of received frame of 0 if ACK was not requested.
 */
void nrf_drv_radio802154_notify_transmitted(uint8_t * p_ack, int8_t power, int8_t lqi);

/**
 * @brief Notify next higher layer that a frame was not transmitted.
 */
void nrf_drv_radio802154_notify_busy_channel(void);

/**
 * @brief Notify next higher layer that energy detection procedure ended.
 *
 * @param[in]  result  Detected energy level.
 */
void nrf_drv_radio802154_notify_energy_detected(uint8_t result);

/**
 * @brief Notify next higher layer that CCA procedure ended.
 *
 * @param[in]  is_free  If detected that channel is free.
 */
void nrf_drv_radio802154_notify_cca(bool is_free);

/**
 *@}
 **/

#ifdef __cplusplus
}
#endif

#endif // NRF_DRIVER_RADIO802154_NOTIFICATION_H__
