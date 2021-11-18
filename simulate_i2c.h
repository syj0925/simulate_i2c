/**
 * @brief simulate IIC
 * @file simulate_i2c.h
 * @version 1.0
 * @author Su YouJiang
 * @date 2020-12-4 11:14:45
 * @par Copyright:
 * Copyright (c) LW-SDK 2000-2020. All rights reserved.
 *
 * @history
 * 1.Date        : 2020-12-4 11:14:45
 *   Author      : Su YouJiang
 *   Modification: Created file
 */

#ifndef __SIMULATE_I2C_H__
#define __SIMULATE_I2C_H__

#ifdef __cplusplus
extern "C"{
#endif  // __cplusplus

#include <stdint.h>

#define SIM_I2C_GPIO_H  1
#define SIM_I2C_GPIO_L  0
#define SIM_I2C_DIR_OUT 1
#define SIM_I2C_DIR_IN  0

typedef void (*i2c_delay_func_t)(void);
typedef void (*i2c_scl_out_func_t)(uint8_t value);
typedef void (*i2c_sda_dir_func_t)(uint8_t value);
typedef void (*i2c_sda_out_func_t)(uint8_t value);
typedef uint8_t (*i2c_sda_in_func_t)(void);

typedef struct {
    i2c_delay_func_t    delay;
    i2c_scl_out_func_t  scl_out;
    i2c_sda_dir_func_t  sda_dir;
    i2c_sda_out_func_t  sda_out;
    i2c_sda_in_func_t   sda_in;
} simulate_i2c_t;

void SimulateI2cInit(simulate_i2c_t *i2c);

int32_t SimulateI2cWrite(  simulate_i2c_t *i2c, uint8_t addr, uint8_t *data, uint32_t datalen);

int32_t SimulateI2cRead(  simulate_i2c_t *i2c, uint8_t addr, uint8_t *data, uint32_t datalen);

int32_t SimulateI2cWriteAndRead(simulate_i2c_t *i2c, uint8_t addr,
                                              uint8_t *wdata, uint32_t wdatalen,
                                              uint8_t *rdata, uint32_t rdatalen);

#ifdef __cplusplus
}
#endif  // __cplusplus

#endif  // __SIMULATE_I2C_H__

