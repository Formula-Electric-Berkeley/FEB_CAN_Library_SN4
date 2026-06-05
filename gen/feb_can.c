#include <string.h>

#include "feb_can.h"

static inline uint8_t pack_left_shift_u8(
    uint8_t value,
    uint8_t shift,
    uint8_t mask)
{
    return (uint8_t)((uint8_t)(value << shift) & mask);
}

static inline uint8_t pack_left_shift_u16(
    uint16_t value,
    uint8_t shift,
    uint8_t mask)
{
    return (uint8_t)((uint8_t)(value << shift) & mask);
}

static inline uint8_t pack_left_shift_u32(
    uint32_t value,
    uint8_t shift,
    uint8_t mask)
{
    return (uint8_t)((uint8_t)(value << shift) & mask);
}

static inline uint8_t pack_right_shift_u16(
    uint16_t value,
    uint8_t shift,
    uint8_t mask)
{
    return (uint8_t)((uint8_t)(value >> shift) & mask);
}

static inline uint8_t pack_right_shift_u32(
    uint32_t value,
    uint8_t shift,
    uint8_t mask)
{
    return (uint8_t)((uint8_t)(value >> shift) & mask);
}

static inline uint16_t unpack_left_shift_u16(
    uint8_t value,
    uint8_t shift,
    uint8_t mask)
{
    return (uint16_t)((uint16_t)(value & mask) << shift);
}

static inline uint32_t unpack_left_shift_u32(
    uint8_t value,
    uint8_t shift,
    uint8_t mask)
{
    return (uint32_t)((uint32_t)(value & mask) << shift);
}

static inline uint8_t unpack_right_shift_u8(
    uint8_t value,
    uint8_t shift,
    uint8_t mask)
{
    return (uint8_t)((uint8_t)(value & mask) >> shift);
}

static inline uint16_t unpack_right_shift_u16(
    uint8_t value,
    uint8_t shift,
    uint8_t mask)
{
    return (uint16_t)((uint16_t)(value & mask) >> shift);
}

static inline uint32_t unpack_right_shift_u32(
    uint8_t value,
    uint8_t shift,
    uint8_t mask)
{
    return (uint32_t)((uint32_t)(value & mask) >> shift);
}

int feb_can_bms_cell_data_pack(
    uint8_t *dst_p,
    const struct feb_can_bms_cell_data_t *src_p,
    size_t size)
{
    uint16_t bms_temperature;

    if (size < 8u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 8);

    dst_p[0] |= pack_left_shift_u8(src_p->bms_flags, 0u, 0x0fu);
    dst_p[1] |= pack_left_shift_u8(src_p->bms_cell, 0u, 0x0fu);
    dst_p[1] |= pack_left_shift_u8(src_p->bms_bank, 4u, 0xf0u);
    dst_p[2] |= pack_left_shift_u16(src_p->bms_voltage, 0u, 0xffu);
    dst_p[3] |= pack_right_shift_u16(src_p->bms_voltage, 8u, 0xffu);
    bms_temperature = (uint16_t)src_p->bms_temperature;
    dst_p[4] |= pack_left_shift_u16(bms_temperature, 0u, 0xffu);
    dst_p[5] |= pack_right_shift_u16(bms_temperature, 8u, 0xffu);
    dst_p[6] |= pack_left_shift_u16(src_p->bms_send_time, 0u, 0xffu);
    dst_p[7] |= pack_right_shift_u16(src_p->bms_send_time, 8u, 0xffu);

    return (8);
}

int feb_can_bms_cell_data_unpack(
    struct feb_can_bms_cell_data_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    uint16_t bms_temperature;

    if (size < 8u) {
        return (-EINVAL);
    }

    dst_p->bms_flags = unpack_right_shift_u8(src_p[0], 0u, 0x0fu);
    dst_p->bms_cell = unpack_right_shift_u8(src_p[1], 0u, 0x0fu);
    dst_p->bms_bank = unpack_right_shift_u8(src_p[1], 4u, 0xf0u);
    dst_p->bms_voltage = unpack_right_shift_u16(src_p[2], 0u, 0xffu);
    dst_p->bms_voltage |= unpack_left_shift_u16(src_p[3], 8u, 0xffu);
    bms_temperature = unpack_right_shift_u16(src_p[4], 0u, 0xffu);
    bms_temperature |= unpack_left_shift_u16(src_p[5], 8u, 0xffu);
    dst_p->bms_temperature = (int16_t)bms_temperature;
    dst_p->bms_send_time = unpack_right_shift_u16(src_p[6], 0u, 0xffu);
    dst_p->bms_send_time |= unpack_left_shift_u16(src_p[7], 8u, 0xffu);

    return (0);
}

int feb_can_bms_cell_data_init(struct feb_can_bms_cell_data_t *msg_p)
{
    if (msg_p == NULL) return -1;

    memset(msg_p, 0, sizeof(struct feb_can_bms_cell_data_t));

    return 0;
}

uint8_t feb_can_bms_cell_data_bms_flags_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_bms_cell_data_bms_flags_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_bms_cell_data_bms_flags_is_in_range(uint8_t value)
{
    return (value <= 15u);
}

uint8_t feb_can_bms_cell_data_bms_cell_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_bms_cell_data_bms_cell_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_bms_cell_data_bms_cell_is_in_range(uint8_t value)
{
    return (value <= 15u);
}

uint8_t feb_can_bms_cell_data_bms_bank_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_bms_cell_data_bms_bank_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_bms_cell_data_bms_bank_is_in_range(uint8_t value)
{
    return (value <= 15u);
}

uint16_t feb_can_bms_cell_data_bms_voltage_encode(double value)
{
    return (uint16_t)(value);
}

double feb_can_bms_cell_data_bms_voltage_decode(uint16_t value)
{
    return ((double)value);
}

bool feb_can_bms_cell_data_bms_voltage_is_in_range(uint16_t value)
{
    (void)value;

    return (true);
}

int16_t feb_can_bms_cell_data_bms_temperature_encode(double value)
{
    return (int16_t)(value);
}

double feb_can_bms_cell_data_bms_temperature_decode(int16_t value)
{
    return ((double)value);
}

bool feb_can_bms_cell_data_bms_temperature_is_in_range(int16_t value)
{
    (void)value;

    return (true);
}

uint16_t feb_can_bms_cell_data_bms_send_time_encode(double value)
{
    return (uint16_t)(value);
}

double feb_can_bms_cell_data_bms_send_time_decode(uint16_t value)
{
    return ((double)value);
}

bool feb_can_bms_cell_data_bms_send_time_is_in_range(uint16_t value)
{
    (void)value;

    return (true);
}

int feb_can_bms_accumulator_voltage_pack(
    uint8_t *dst_p,
    const struct feb_can_bms_accumulator_voltage_t *src_p,
    size_t size)
{
    if (size < 8u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 8);

    dst_p[0] |= pack_left_shift_u16(src_p->total_pack_voltage, 0u, 0xffu);
    dst_p[1] |= pack_right_shift_u16(src_p->total_pack_voltage, 8u, 0xffu);
    dst_p[2] |= pack_left_shift_u16(src_p->min_cell_voltage, 0u, 0xffu);
    dst_p[3] |= pack_right_shift_u16(src_p->min_cell_voltage, 8u, 0xffu);
    dst_p[4] |= pack_left_shift_u16(src_p->max_cell_voltage, 0u, 0xffu);
    dst_p[5] |= pack_right_shift_u16(src_p->max_cell_voltage, 8u, 0xffu);
    dst_p[6] |= pack_left_shift_u16(src_p->send_time, 0u, 0xffu);
    dst_p[7] |= pack_right_shift_u16(src_p->send_time, 8u, 0xffu);

    return (8);
}

int feb_can_bms_accumulator_voltage_unpack(
    struct feb_can_bms_accumulator_voltage_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    if (size < 8u) {
        return (-EINVAL);
    }

    dst_p->total_pack_voltage = unpack_right_shift_u16(src_p[0], 0u, 0xffu);
    dst_p->total_pack_voltage |= unpack_left_shift_u16(src_p[1], 8u, 0xffu);
    dst_p->min_cell_voltage = unpack_right_shift_u16(src_p[2], 0u, 0xffu);
    dst_p->min_cell_voltage |= unpack_left_shift_u16(src_p[3], 8u, 0xffu);
    dst_p->max_cell_voltage = unpack_right_shift_u16(src_p[4], 0u, 0xffu);
    dst_p->max_cell_voltage |= unpack_left_shift_u16(src_p[5], 8u, 0xffu);
    dst_p->send_time = unpack_right_shift_u16(src_p[6], 0u, 0xffu);
    dst_p->send_time |= unpack_left_shift_u16(src_p[7], 8u, 0xffu);

    return (0);
}

int feb_can_bms_accumulator_voltage_init(struct feb_can_bms_accumulator_voltage_t *msg_p)
{
    if (msg_p == NULL) return -1;

    memset(msg_p, 0, sizeof(struct feb_can_bms_accumulator_voltage_t));

    return 0;
}

uint16_t feb_can_bms_accumulator_voltage_total_pack_voltage_encode(double value)
{
    return (uint16_t)(value);
}

double feb_can_bms_accumulator_voltage_total_pack_voltage_decode(uint16_t value)
{
    return ((double)value);
}

bool feb_can_bms_accumulator_voltage_total_pack_voltage_is_in_range(uint16_t value)
{
    (void)value;

    return (true);
}

uint16_t feb_can_bms_accumulator_voltage_min_cell_voltage_encode(double value)
{
    return (uint16_t)(value);
}

double feb_can_bms_accumulator_voltage_min_cell_voltage_decode(uint16_t value)
{
    return ((double)value);
}

bool feb_can_bms_accumulator_voltage_min_cell_voltage_is_in_range(uint16_t value)
{
    (void)value;

    return (true);
}

uint16_t feb_can_bms_accumulator_voltage_max_cell_voltage_encode(double value)
{
    return (uint16_t)(value);
}

double feb_can_bms_accumulator_voltage_max_cell_voltage_decode(uint16_t value)
{
    return ((double)value);
}

bool feb_can_bms_accumulator_voltage_max_cell_voltage_is_in_range(uint16_t value)
{
    (void)value;

    return (true);
}

uint16_t feb_can_bms_accumulator_voltage_send_time_encode(double value)
{
    return (uint16_t)(value);
}

double feb_can_bms_accumulator_voltage_send_time_decode(uint16_t value)
{
    return ((double)value);
}

bool feb_can_bms_accumulator_voltage_send_time_is_in_range(uint16_t value)
{
    (void)value;

    return (true);
}

int feb_can_bms_accumulator_temperature_pack(
    uint8_t *dst_p,
    const struct feb_can_bms_accumulator_temperature_t *src_p,
    size_t size)
{
    uint16_t average_pack_temperature;
    uint16_t max_cell_temperature;
    uint16_t min_cell_temperature;

    if (size < 8u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 8);

    average_pack_temperature = (uint16_t)src_p->average_pack_temperature;
    dst_p[0] |= pack_left_shift_u16(average_pack_temperature, 0u, 0xffu);
    dst_p[1] |= pack_right_shift_u16(average_pack_temperature, 8u, 0xffu);
    min_cell_temperature = (uint16_t)src_p->min_cell_temperature;
    dst_p[2] |= pack_left_shift_u16(min_cell_temperature, 0u, 0xffu);
    dst_p[3] |= pack_right_shift_u16(min_cell_temperature, 8u, 0xffu);
    max_cell_temperature = (uint16_t)src_p->max_cell_temperature;
    dst_p[4] |= pack_left_shift_u16(max_cell_temperature, 0u, 0xffu);
    dst_p[5] |= pack_right_shift_u16(max_cell_temperature, 8u, 0xffu);
    dst_p[6] |= pack_left_shift_u16(src_p->send_time, 0u, 0xffu);
    dst_p[7] |= pack_right_shift_u16(src_p->send_time, 8u, 0xffu);

    return (8);
}

int feb_can_bms_accumulator_temperature_unpack(
    struct feb_can_bms_accumulator_temperature_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    uint16_t average_pack_temperature;
    uint16_t max_cell_temperature;
    uint16_t min_cell_temperature;

    if (size < 8u) {
        return (-EINVAL);
    }

    average_pack_temperature = unpack_right_shift_u16(src_p[0], 0u, 0xffu);
    average_pack_temperature |= unpack_left_shift_u16(src_p[1], 8u, 0xffu);
    dst_p->average_pack_temperature = (int16_t)average_pack_temperature;
    min_cell_temperature = unpack_right_shift_u16(src_p[2], 0u, 0xffu);
    min_cell_temperature |= unpack_left_shift_u16(src_p[3], 8u, 0xffu);
    dst_p->min_cell_temperature = (int16_t)min_cell_temperature;
    max_cell_temperature = unpack_right_shift_u16(src_p[4], 0u, 0xffu);
    max_cell_temperature |= unpack_left_shift_u16(src_p[5], 8u, 0xffu);
    dst_p->max_cell_temperature = (int16_t)max_cell_temperature;
    dst_p->send_time = unpack_right_shift_u16(src_p[6], 0u, 0xffu);
    dst_p->send_time |= unpack_left_shift_u16(src_p[7], 8u, 0xffu);

    return (0);
}

int feb_can_bms_accumulator_temperature_init(struct feb_can_bms_accumulator_temperature_t *msg_p)
{
    if (msg_p == NULL) return -1;

    memset(msg_p, 0, sizeof(struct feb_can_bms_accumulator_temperature_t));

    return 0;
}

int16_t feb_can_bms_accumulator_temperature_average_pack_temperature_encode(double value)
{
    return (int16_t)(value);
}

double feb_can_bms_accumulator_temperature_average_pack_temperature_decode(int16_t value)
{
    return ((double)value);
}

bool feb_can_bms_accumulator_temperature_average_pack_temperature_is_in_range(int16_t value)
{
    (void)value;

    return (true);
}

int16_t feb_can_bms_accumulator_temperature_min_cell_temperature_encode(double value)
{
    return (int16_t)(value);
}

double feb_can_bms_accumulator_temperature_min_cell_temperature_decode(int16_t value)
{
    return ((double)value);
}

bool feb_can_bms_accumulator_temperature_min_cell_temperature_is_in_range(int16_t value)
{
    (void)value;

    return (true);
}

int16_t feb_can_bms_accumulator_temperature_max_cell_temperature_encode(double value)
{
    return (int16_t)(value);
}

double feb_can_bms_accumulator_temperature_max_cell_temperature_decode(int16_t value)
{
    return ((double)value);
}

bool feb_can_bms_accumulator_temperature_max_cell_temperature_is_in_range(int16_t value)
{
    (void)value;

    return (true);
}

uint16_t feb_can_bms_accumulator_temperature_send_time_encode(double value)
{
    return (uint16_t)(value);
}

double feb_can_bms_accumulator_temperature_send_time_decode(uint16_t value)
{
    return ((double)value);
}

bool feb_can_bms_accumulator_temperature_send_time_is_in_range(uint16_t value)
{
    (void)value;

    return (true);
}

int feb_can_accumulator_faults_pack(
    uint8_t *dst_p,
    const struct feb_can_accumulator_faults_t *src_p,
    size_t size)
{
    if (size < 1u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 1);

    dst_p[0] |= pack_left_shift_u8(src_p->bms_fault, 0u, 0x01u);
    dst_p[0] |= pack_left_shift_u8(src_p->imd_fault, 1u, 0x02u);

    return (1);
}

int feb_can_accumulator_faults_unpack(
    struct feb_can_accumulator_faults_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    if (size < 1u) {
        return (-EINVAL);
    }

    dst_p->bms_fault = unpack_right_shift_u8(src_p[0], 0u, 0x01u);
    dst_p->imd_fault = unpack_right_shift_u8(src_p[0], 1u, 0x02u);

    return (0);
}

int feb_can_accumulator_faults_init(struct feb_can_accumulator_faults_t *msg_p)
{
    if (msg_p == NULL) return -1;

    memset(msg_p, 0, sizeof(struct feb_can_accumulator_faults_t));

    return 0;
}

uint8_t feb_can_accumulator_faults_bms_fault_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_accumulator_faults_bms_fault_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_accumulator_faults_bms_fault_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_accumulator_faults_imd_fault_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_accumulator_faults_imd_fault_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_accumulator_faults_imd_fault_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

int feb_can_bms_state_pack(
    uint8_t *dst_p,
    const struct feb_can_bms_state_t *src_p,
    size_t size)
{
    if (size < 2u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 2);

    dst_p[0] |= pack_left_shift_u8(src_p->bms_state, 0u, 0x1fu);
    dst_p[0] |= pack_left_shift_u8(src_p->ping_lv_nodes, 5u, 0xe0u);
    dst_p[1] |= pack_left_shift_u8(src_p->relay_state, 0u, 0x07u);
    dst_p[1] |= pack_left_shift_u8(src_p->gpio_sense, 3u, 0xf8u);

    return (2);
}

int feb_can_bms_state_unpack(
    struct feb_can_bms_state_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    if (size < 2u) {
        return (-EINVAL);
    }

    dst_p->bms_state = unpack_right_shift_u8(src_p[0], 0u, 0x1fu);
    dst_p->ping_lv_nodes = unpack_right_shift_u8(src_p[0], 5u, 0xe0u);
    dst_p->relay_state = unpack_right_shift_u8(src_p[1], 0u, 0x07u);
    dst_p->gpio_sense = unpack_right_shift_u8(src_p[1], 3u, 0xf8u);

    return (0);
}

int feb_can_bms_state_init(struct feb_can_bms_state_t *msg_p)
{
    if (msg_p == NULL) return -1;

    memset(msg_p, 0, sizeof(struct feb_can_bms_state_t));

    return 0;
}

uint8_t feb_can_bms_state_bms_state_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_bms_state_bms_state_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_bms_state_bms_state_is_in_range(uint8_t value)
{
    return (value <= 31u);
}

uint8_t feb_can_bms_state_ping_lv_nodes_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_bms_state_ping_lv_nodes_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_bms_state_ping_lv_nodes_is_in_range(uint8_t value)
{
    return (value <= 7u);
}

uint8_t feb_can_bms_state_relay_state_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_bms_state_relay_state_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_bms_state_relay_state_is_in_range(uint8_t value)
{
    return (value <= 7u);
}

uint8_t feb_can_bms_state_gpio_sense_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_bms_state_gpio_sense_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_bms_state_gpio_sense_is_in_range(uint8_t value)
{
    return (value <= 31u);
}

int feb_can_brake_pack(
    uint8_t *dst_p,
    const struct feb_can_brake_t *src_p,
    size_t size)
{
    if (size < 8u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 8);

    dst_p[0] |= pack_right_shift_u16(src_p->brake_position, 8u, 0xffu);
    dst_p[1] |= pack_left_shift_u16(src_p->brake_position, 0u, 0xffu);
    dst_p[2] |= pack_right_shift_u16(src_p->brake1_pct, 8u, 0xffu);
    dst_p[3] |= pack_left_shift_u16(src_p->brake1_pct, 0u, 0xffu);
    dst_p[4] |= pack_right_shift_u16(src_p->brake2_pct, 8u, 0xffu);
    dst_p[5] |= pack_left_shift_u16(src_p->brake2_pct, 0u, 0xffu);
    dst_p[6] |= pack_left_shift_u8(src_p->plausible, 0u, 0x01u);
    dst_p[6] |= pack_left_shift_u8(src_p->brake_pressed, 1u, 0x02u);
    dst_p[6] |= pack_left_shift_u8(src_p->bots_active, 2u, 0x04u);
    dst_p[7] |= pack_left_shift_u8(src_p->brake_switch, 1u, 0x02u);

    return (8);
}

int feb_can_brake_unpack(
    struct feb_can_brake_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    if (size < 8u) {
        return (-EINVAL);
    }

    dst_p->brake_position = unpack_left_shift_u16(src_p[0], 8u, 0xffu);
    dst_p->brake_position |= unpack_right_shift_u16(src_p[1], 0u, 0xffu);
    dst_p->brake1_pct = unpack_left_shift_u16(src_p[2], 8u, 0xffu);
    dst_p->brake1_pct |= unpack_right_shift_u16(src_p[3], 0u, 0xffu);
    dst_p->brake2_pct = unpack_left_shift_u16(src_p[4], 8u, 0xffu);
    dst_p->brake2_pct |= unpack_right_shift_u16(src_p[5], 0u, 0xffu);
    dst_p->plausible = unpack_right_shift_u8(src_p[6], 0u, 0x01u);
    dst_p->brake_pressed = unpack_right_shift_u8(src_p[6], 1u, 0x02u);
    dst_p->bots_active = unpack_right_shift_u8(src_p[6], 2u, 0x04u);
    dst_p->brake_switch = unpack_right_shift_u8(src_p[7], 1u, 0x02u);

    return (0);
}

int feb_can_brake_init(struct feb_can_brake_t *msg_p)
{
    if (msg_p == NULL) return -1;

    memset(msg_p, 0, sizeof(struct feb_can_brake_t));

    return 0;
}

uint16_t feb_can_brake_brake_position_encode(double value)
{
    return (uint16_t)(value);
}

double feb_can_brake_brake_position_decode(uint16_t value)
{
    return ((double)value);
}

bool feb_can_brake_brake_position_is_in_range(uint16_t value)
{
    (void)value;

    return (true);
}

uint16_t feb_can_brake_brake1_pct_encode(double value)
{
    return (uint16_t)(value);
}

double feb_can_brake_brake1_pct_decode(uint16_t value)
{
    return ((double)value);
}

bool feb_can_brake_brake1_pct_is_in_range(uint16_t value)
{
    (void)value;

    return (true);
}

uint16_t feb_can_brake_brake2_pct_encode(double value)
{
    return (uint16_t)(value);
}

double feb_can_brake_brake2_pct_decode(uint16_t value)
{
    return ((double)value);
}

bool feb_can_brake_brake2_pct_is_in_range(uint16_t value)
{
    (void)value;

    return (true);
}

uint8_t feb_can_brake_plausible_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_brake_plausible_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_brake_plausible_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_brake_brake_pressed_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_brake_brake_pressed_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_brake_brake_pressed_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_brake_bots_active_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_brake_bots_active_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_brake_bots_active_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_brake_brake_switch_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_brake_brake_switch_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_brake_brake_switch_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

int feb_can_bspd_state_pack(
    uint8_t *dst_p,
    const struct feb_can_bspd_state_t *src_p,
    size_t size)
{
    if (size < 1u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 1);

    dst_p[0] |= pack_left_shift_u8(src_p->bspd_state, 0u, 0xffu);

    return (1);
}

int feb_can_bspd_state_unpack(
    struct feb_can_bspd_state_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    if (size < 1u) {
        return (-EINVAL);
    }

    dst_p->bspd_state = unpack_right_shift_u8(src_p[0], 0u, 0xffu);

    return (0);
}

int feb_can_bspd_state_init(struct feb_can_bspd_state_t *msg_p)
{
    if (msg_p == NULL) return -1;

    memset(msg_p, 0, sizeof(struct feb_can_bspd_state_t));

    return 0;
}

uint8_t feb_can_bspd_state_bspd_state_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_bspd_state_bspd_state_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_bspd_state_bspd_state_is_in_range(uint8_t value)
{
    (void)value;

    return (true);
}

int feb_can_res_state_pack(
    uint8_t *dst_p,
    const struct feb_can_res_state_t *src_p,
    size_t size)
{
    if (size < 2u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 2);

    dst_p[0] |= pack_left_shift_u8(src_p->res_state, 0u, 0xffu);

    return (2);
}

int feb_can_res_state_unpack(
    struct feb_can_res_state_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    if (size < 2u) {
        return (-EINVAL);
    }

    dst_p->res_state = unpack_right_shift_u8(src_p[0], 0u, 0xffu);

    return (0);
}

int feb_can_res_state_init(struct feb_can_res_state_t *msg_p)
{
    if (msg_p == NULL) return -1;

    memset(msg_p, 0, sizeof(struct feb_can_res_state_t));

    return 0;
}

uint8_t feb_can_res_state_res_state_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_res_state_res_state_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_res_state_res_state_is_in_range(uint8_t value)
{
    (void)value;

    return (true);
}

int feb_can_dash_state_pack(
    uint8_t *dst_p,
    const struct feb_can_dash_state_t *src_p,
    size_t size)
{
    if (size < 2u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 2);

    dst_p[0] |= pack_left_shift_u8(src_p->button1, 0u, 0x01u);
    dst_p[0] |= pack_left_shift_u8(src_p->button2, 1u, 0x02u);
    dst_p[0] |= pack_left_shift_u8(src_p->button3, 2u, 0x04u);
    dst_p[0] |= pack_left_shift_u8(src_p->button4, 3u, 0x08u);
    dst_p[0] |= pack_left_shift_u8(src_p->switch1, 4u, 0x10u);
    dst_p[0] |= pack_left_shift_u8(src_p->switch2, 5u, 0x20u);
    dst_p[0] |= pack_left_shift_u8(src_p->switch3, 6u, 0x40u);
    dst_p[0] |= pack_left_shift_u8(src_p->switch4, 7u, 0x80u);
    dst_p[1] |= pack_left_shift_u8(src_p->buzzer, 0u, 0x01u);
    dst_p[1] |= pack_left_shift_u8(src_p->ready_to_drive, 1u, 0x02u);

    return (2);
}

int feb_can_dash_state_unpack(
    struct feb_can_dash_state_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    if (size < 2u) {
        return (-EINVAL);
    }

    dst_p->button1 = unpack_right_shift_u8(src_p[0], 0u, 0x01u);
    dst_p->button2 = unpack_right_shift_u8(src_p[0], 1u, 0x02u);
    dst_p->button3 = unpack_right_shift_u8(src_p[0], 2u, 0x04u);
    dst_p->button4 = unpack_right_shift_u8(src_p[0], 3u, 0x08u);
    dst_p->switch1 = unpack_right_shift_u8(src_p[0], 4u, 0x10u);
    dst_p->switch2 = unpack_right_shift_u8(src_p[0], 5u, 0x20u);
    dst_p->switch3 = unpack_right_shift_u8(src_p[0], 6u, 0x40u);
    dst_p->switch4 = unpack_right_shift_u8(src_p[0], 7u, 0x80u);
    dst_p->buzzer = unpack_right_shift_u8(src_p[1], 0u, 0x01u);
    dst_p->ready_to_drive = unpack_right_shift_u8(src_p[1], 1u, 0x02u);

    return (0);
}

int feb_can_dash_state_init(struct feb_can_dash_state_t *msg_p)
{
    if (msg_p == NULL) return -1;

    memset(msg_p, 0, sizeof(struct feb_can_dash_state_t));

    return 0;
}

uint8_t feb_can_dash_state_button1_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_dash_state_button1_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_dash_state_button1_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_dash_state_button2_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_dash_state_button2_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_dash_state_button2_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_dash_state_button3_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_dash_state_button3_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_dash_state_button3_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_dash_state_button4_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_dash_state_button4_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_dash_state_button4_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_dash_state_switch1_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_dash_state_switch1_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_dash_state_switch1_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_dash_state_switch2_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_dash_state_switch2_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_dash_state_switch2_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_dash_state_switch3_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_dash_state_switch3_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_dash_state_switch3_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_dash_state_switch4_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_dash_state_switch4_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_dash_state_switch4_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_dash_state_buzzer_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_dash_state_buzzer_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_dash_state_buzzer_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_dash_state_ready_to_drive_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_dash_state_ready_to_drive_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_dash_state_ready_to_drive_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

int feb_can_lvpdb_lv_24v_bus_and_12v_bus_voltages_pack(
    uint8_t *dst_p,
    const struct feb_can_lvpdb_lv_24v_bus_and_12v_bus_voltages_t *src_p,
    size_t size)
{
    if (size < 4u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 4);

    dst_p[0] |= pack_left_shift_u16(src_p->lv_24v_voltage, 0u, 0xffu);
    dst_p[1] |= pack_right_shift_u16(src_p->lv_24v_voltage, 8u, 0xffu);
    dst_p[2] |= pack_left_shift_u16(src_p->lv_12v_voltage, 0u, 0xffu);
    dst_p[3] |= pack_right_shift_u16(src_p->lv_12v_voltage, 8u, 0xffu);

    return (4);
}

int feb_can_lvpdb_lv_24v_bus_and_12v_bus_voltages_unpack(
    struct feb_can_lvpdb_lv_24v_bus_and_12v_bus_voltages_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    if (size < 4u) {
        return (-EINVAL);
    }

    dst_p->lv_24v_voltage = unpack_right_shift_u16(src_p[0], 0u, 0xffu);
    dst_p->lv_24v_voltage |= unpack_left_shift_u16(src_p[1], 8u, 0xffu);
    dst_p->lv_12v_voltage = unpack_right_shift_u16(src_p[2], 0u, 0xffu);
    dst_p->lv_12v_voltage |= unpack_left_shift_u16(src_p[3], 8u, 0xffu);

    return (0);
}

int feb_can_lvpdb_lv_24v_bus_and_12v_bus_voltages_init(struct feb_can_lvpdb_lv_24v_bus_and_12v_bus_voltages_t *msg_p)
{
    if (msg_p == NULL) return -1;

    memset(msg_p, 0, sizeof(struct feb_can_lvpdb_lv_24v_bus_and_12v_bus_voltages_t));

    return 0;
}

uint16_t feb_can_lvpdb_lv_24v_bus_and_12v_bus_voltages_lv_24v_voltage_encode(double value)
{
    return (uint16_t)(value);
}

double feb_can_lvpdb_lv_24v_bus_and_12v_bus_voltages_lv_24v_voltage_decode(uint16_t value)
{
    return ((double)value);
}

bool feb_can_lvpdb_lv_24v_bus_and_12v_bus_voltages_lv_24v_voltage_is_in_range(uint16_t value)
{
    (void)value;

    return (true);
}

uint16_t feb_can_lvpdb_lv_24v_bus_and_12v_bus_voltages_lv_12v_voltage_encode(double value)
{
    return (uint16_t)(value);
}

double feb_can_lvpdb_lv_24v_bus_and_12v_bus_voltages_lv_12v_voltage_decode(uint16_t value)
{
    return ((double)value);
}

bool feb_can_lvpdb_lv_24v_bus_and_12v_bus_voltages_lv_12v_voltage_is_in_range(uint16_t value)
{
    (void)value;

    return (true);
}

int feb_can_lvpdb_lv_sh_lt_bm_l_currents_pack(
    uint8_t *dst_p,
    const struct feb_can_lvpdb_lv_sh_lt_bm_l_currents_t *src_p,
    size_t size)
{
    if (size < 8u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 8);

    dst_p[0] |= pack_left_shift_u16(src_p->lv_current, 0u, 0xffu);
    dst_p[1] |= pack_right_shift_u16(src_p->lv_current, 8u, 0xffu);
    dst_p[2] |= pack_left_shift_u16(src_p->sh_current, 0u, 0xffu);
    dst_p[3] |= pack_right_shift_u16(src_p->sh_current, 8u, 0xffu);
    dst_p[4] |= pack_left_shift_u16(src_p->lt_current, 0u, 0xffu);
    dst_p[5] |= pack_right_shift_u16(src_p->lt_current, 8u, 0xffu);
    dst_p[6] |= pack_left_shift_u16(src_p->bm_l_current, 0u, 0xffu);
    dst_p[7] |= pack_right_shift_u16(src_p->bm_l_current, 8u, 0xffu);

    return (8);
}

int feb_can_lvpdb_lv_sh_lt_bm_l_currents_unpack(
    struct feb_can_lvpdb_lv_sh_lt_bm_l_currents_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    if (size < 8u) {
        return (-EINVAL);
    }

    dst_p->lv_current = unpack_right_shift_u16(src_p[0], 0u, 0xffu);
    dst_p->lv_current |= unpack_left_shift_u16(src_p[1], 8u, 0xffu);
    dst_p->sh_current = unpack_right_shift_u16(src_p[2], 0u, 0xffu);
    dst_p->sh_current |= unpack_left_shift_u16(src_p[3], 8u, 0xffu);
    dst_p->lt_current = unpack_right_shift_u16(src_p[4], 0u, 0xffu);
    dst_p->lt_current |= unpack_left_shift_u16(src_p[5], 8u, 0xffu);
    dst_p->bm_l_current = unpack_right_shift_u16(src_p[6], 0u, 0xffu);
    dst_p->bm_l_current |= unpack_left_shift_u16(src_p[7], 8u, 0xffu);

    return (0);
}

int feb_can_lvpdb_lv_sh_lt_bm_l_currents_init(struct feb_can_lvpdb_lv_sh_lt_bm_l_currents_t *msg_p)
{
    if (msg_p == NULL) return -1;

    memset(msg_p, 0, sizeof(struct feb_can_lvpdb_lv_sh_lt_bm_l_currents_t));

    return 0;
}

uint16_t feb_can_lvpdb_lv_sh_lt_bm_l_currents_lv_current_encode(double value)
{
    return (uint16_t)(value);
}

double feb_can_lvpdb_lv_sh_lt_bm_l_currents_lv_current_decode(uint16_t value)
{
    return ((double)value);
}

bool feb_can_lvpdb_lv_sh_lt_bm_l_currents_lv_current_is_in_range(uint16_t value)
{
    (void)value;

    return (true);
}

uint16_t feb_can_lvpdb_lv_sh_lt_bm_l_currents_sh_current_encode(double value)
{
    return (uint16_t)(value);
}

double feb_can_lvpdb_lv_sh_lt_bm_l_currents_sh_current_decode(uint16_t value)
{
    return ((double)value);
}

bool feb_can_lvpdb_lv_sh_lt_bm_l_currents_sh_current_is_in_range(uint16_t value)
{
    (void)value;

    return (true);
}

uint16_t feb_can_lvpdb_lv_sh_lt_bm_l_currents_lt_current_encode(double value)
{
    return (uint16_t)(value);
}

double feb_can_lvpdb_lv_sh_lt_bm_l_currents_lt_current_decode(uint16_t value)
{
    return ((double)value);
}

bool feb_can_lvpdb_lv_sh_lt_bm_l_currents_lt_current_is_in_range(uint16_t value)
{
    (void)value;

    return (true);
}

uint16_t feb_can_lvpdb_lv_sh_lt_bm_l_currents_bm_l_current_encode(double value)
{
    return (uint16_t)(value);
}

double feb_can_lvpdb_lv_sh_lt_bm_l_currents_bm_l_current_decode(uint16_t value)
{
    return ((double)value);
}

bool feb_can_lvpdb_lv_sh_lt_bm_l_currents_bm_l_current_is_in_range(uint16_t value)
{
    (void)value;

    return (true);
}

int feb_can_lvpdb_sm_af1_af2_cp_rf_currents_pack(
    uint8_t *dst_p,
    const struct feb_can_lvpdb_sm_af1_af2_cp_rf_currents_t *src_p,
    size_t size)
{
    if (size < 8u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 8);

    dst_p[0] |= pack_left_shift_u16(src_p->sm_current, 0u, 0xffu);
    dst_p[1] |= pack_right_shift_u16(src_p->sm_current, 8u, 0xffu);
    dst_p[2] |= pack_left_shift_u16(src_p->af1_af2_current, 0u, 0xffu);
    dst_p[3] |= pack_right_shift_u16(src_p->af1_af2_current, 8u, 0xffu);
    dst_p[4] |= pack_left_shift_u16(src_p->cp_rf_current, 0u, 0xffu);
    dst_p[5] |= pack_right_shift_u16(src_p->cp_rf_current, 8u, 0xffu);

    return (8);
}

int feb_can_lvpdb_sm_af1_af2_cp_rf_currents_unpack(
    struct feb_can_lvpdb_sm_af1_af2_cp_rf_currents_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    if (size < 8u) {
        return (-EINVAL);
    }

    dst_p->sm_current = unpack_right_shift_u16(src_p[0], 0u, 0xffu);
    dst_p->sm_current |= unpack_left_shift_u16(src_p[1], 8u, 0xffu);
    dst_p->af1_af2_current = unpack_right_shift_u16(src_p[2], 0u, 0xffu);
    dst_p->af1_af2_current |= unpack_left_shift_u16(src_p[3], 8u, 0xffu);
    dst_p->cp_rf_current = unpack_right_shift_u16(src_p[4], 0u, 0xffu);
    dst_p->cp_rf_current |= unpack_left_shift_u16(src_p[5], 8u, 0xffu);

    return (0);
}

int feb_can_lvpdb_sm_af1_af2_cp_rf_currents_init(struct feb_can_lvpdb_sm_af1_af2_cp_rf_currents_t *msg_p)
{
    if (msg_p == NULL) return -1;

    memset(msg_p, 0, sizeof(struct feb_can_lvpdb_sm_af1_af2_cp_rf_currents_t));

    return 0;
}

uint16_t feb_can_lvpdb_sm_af1_af2_cp_rf_currents_sm_current_encode(double value)
{
    return (uint16_t)(value);
}

double feb_can_lvpdb_sm_af1_af2_cp_rf_currents_sm_current_decode(uint16_t value)
{
    return ((double)value);
}

bool feb_can_lvpdb_sm_af1_af2_cp_rf_currents_sm_current_is_in_range(uint16_t value)
{
    (void)value;

    return (true);
}

uint16_t feb_can_lvpdb_sm_af1_af2_cp_rf_currents_af1_af2_current_encode(double value)
{
    return (uint16_t)(value);
}

double feb_can_lvpdb_sm_af1_af2_cp_rf_currents_af1_af2_current_decode(uint16_t value)
{
    return ((double)value);
}

bool feb_can_lvpdb_sm_af1_af2_cp_rf_currents_af1_af2_current_is_in_range(uint16_t value)
{
    (void)value;

    return (true);
}

uint16_t feb_can_lvpdb_sm_af1_af2_cp_rf_currents_cp_rf_current_encode(double value)
{
    return (uint16_t)(value);
}

double feb_can_lvpdb_sm_af1_af2_cp_rf_currents_cp_rf_current_decode(uint16_t value)
{
    return ((double)value);
}

bool feb_can_lvpdb_sm_af1_af2_cp_rf_currents_cp_rf_current_is_in_range(uint16_t value)
{
    (void)value;

    return (true);
}

int feb_can_linear_potentiometer_front_pack(
    uint8_t *dst_p,
    const struct feb_can_linear_potentiometer_front_t *src_p,
    size_t size)
{
    if (size < 4u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 4);

    dst_p[0] |= pack_left_shift_u16(src_p->linear_potentiometer_1_front, 0u, 0xffu);
    dst_p[1] |= pack_right_shift_u16(src_p->linear_potentiometer_1_front, 8u, 0xffu);
    dst_p[2] |= pack_left_shift_u16(src_p->linear_potentiometer_2_front, 0u, 0xffu);
    dst_p[3] |= pack_right_shift_u16(src_p->linear_potentiometer_2_front, 8u, 0xffu);

    return (4);
}

int feb_can_linear_potentiometer_front_unpack(
    struct feb_can_linear_potentiometer_front_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    if (size < 4u) {
        return (-EINVAL);
    }

    dst_p->linear_potentiometer_1_front = unpack_right_shift_u16(src_p[0], 0u, 0xffu);
    dst_p->linear_potentiometer_1_front |= unpack_left_shift_u16(src_p[1], 8u, 0xffu);
    dst_p->linear_potentiometer_2_front = unpack_right_shift_u16(src_p[2], 0u, 0xffu);
    dst_p->linear_potentiometer_2_front |= unpack_left_shift_u16(src_p[3], 8u, 0xffu);

    return (0);
}

int feb_can_linear_potentiometer_front_init(struct feb_can_linear_potentiometer_front_t *msg_p)
{
    if (msg_p == NULL) return -1;

    memset(msg_p, 0, sizeof(struct feb_can_linear_potentiometer_front_t));

    return 0;
}

uint16_t feb_can_linear_potentiometer_front_linear_potentiometer_1_front_encode(double value)
{
    return (uint16_t)(value);
}

double feb_can_linear_potentiometer_front_linear_potentiometer_1_front_decode(uint16_t value)
{
    return ((double)value);
}

bool feb_can_linear_potentiometer_front_linear_potentiometer_1_front_is_in_range(uint16_t value)
{
    (void)value;

    return (true);
}

uint16_t feb_can_linear_potentiometer_front_linear_potentiometer_2_front_encode(double value)
{
    return (uint16_t)(value);
}

double feb_can_linear_potentiometer_front_linear_potentiometer_2_front_decode(uint16_t value)
{
    return ((double)value);
}

bool feb_can_linear_potentiometer_front_linear_potentiometer_2_front_is_in_range(uint16_t value)
{
    (void)value;

    return (true);
}

int feb_can_linear_potentiometer_rear_pack(
    uint8_t *dst_p,
    const struct feb_can_linear_potentiometer_rear_t *src_p,
    size_t size)
{
    if (size < 4u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 4);

    dst_p[0] |= pack_left_shift_u16(src_p->linear_potentiometer_1_rear, 0u, 0xffu);
    dst_p[1] |= pack_right_shift_u16(src_p->linear_potentiometer_1_rear, 8u, 0xffu);
    dst_p[2] |= pack_left_shift_u16(src_p->linear_potentiometer_2_rear, 0u, 0xffu);
    dst_p[3] |= pack_right_shift_u16(src_p->linear_potentiometer_2_rear, 8u, 0xffu);

    return (4);
}

int feb_can_linear_potentiometer_rear_unpack(
    struct feb_can_linear_potentiometer_rear_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    if (size < 4u) {
        return (-EINVAL);
    }

    dst_p->linear_potentiometer_1_rear = unpack_right_shift_u16(src_p[0], 0u, 0xffu);
    dst_p->linear_potentiometer_1_rear |= unpack_left_shift_u16(src_p[1], 8u, 0xffu);
    dst_p->linear_potentiometer_2_rear = unpack_right_shift_u16(src_p[2], 0u, 0xffu);
    dst_p->linear_potentiometer_2_rear |= unpack_left_shift_u16(src_p[3], 8u, 0xffu);

    return (0);
}

int feb_can_linear_potentiometer_rear_init(struct feb_can_linear_potentiometer_rear_t *msg_p)
{
    if (msg_p == NULL) return -1;

    memset(msg_p, 0, sizeof(struct feb_can_linear_potentiometer_rear_t));

    return 0;
}

uint16_t feb_can_linear_potentiometer_rear_linear_potentiometer_1_rear_encode(double value)
{
    return (uint16_t)(value);
}

double feb_can_linear_potentiometer_rear_linear_potentiometer_1_rear_decode(uint16_t value)
{
    return ((double)value);
}

bool feb_can_linear_potentiometer_rear_linear_potentiometer_1_rear_is_in_range(uint16_t value)
{
    (void)value;

    return (true);
}

uint16_t feb_can_linear_potentiometer_rear_linear_potentiometer_2_rear_encode(double value)
{
    return (uint16_t)(value);
}

double feb_can_linear_potentiometer_rear_linear_potentiometer_2_rear_decode(uint16_t value)
{
    return ((double)value);
}

bool feb_can_linear_potentiometer_rear_linear_potentiometer_2_rear_is_in_range(uint16_t value)
{
    (void)value;

    return (true);
}

int feb_can_front_left_tire_temp_pack(
    uint8_t *dst_p,
    const struct feb_can_front_left_tire_temp_t *src_p,
    size_t size)
{
    if (size < 8u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 8);

    dst_p[0] |= pack_left_shift_u16(src_p->leftmost_temp_fl, 0u, 0xffu);
    dst_p[1] |= pack_right_shift_u16(src_p->leftmost_temp_fl, 8u, 0xffu);
    dst_p[2] |= pack_left_shift_u16(src_p->center_left_temp_fl, 0u, 0xffu);
    dst_p[3] |= pack_right_shift_u16(src_p->center_left_temp_fl, 8u, 0xffu);
    dst_p[4] |= pack_left_shift_u16(src_p->center_right_temp_fl, 0u, 0xffu);
    dst_p[5] |= pack_right_shift_u16(src_p->center_right_temp_fl, 8u, 0xffu);
    dst_p[6] |= pack_left_shift_u16(src_p->rightmost_temp_fl, 0u, 0xffu);
    dst_p[7] |= pack_right_shift_u16(src_p->rightmost_temp_fl, 8u, 0xffu);

    return (8);
}

int feb_can_front_left_tire_temp_unpack(
    struct feb_can_front_left_tire_temp_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    if (size < 8u) {
        return (-EINVAL);
    }

    dst_p->leftmost_temp_fl = unpack_right_shift_u16(src_p[0], 0u, 0xffu);
    dst_p->leftmost_temp_fl |= unpack_left_shift_u16(src_p[1], 8u, 0xffu);
    dst_p->center_left_temp_fl = unpack_right_shift_u16(src_p[2], 0u, 0xffu);
    dst_p->center_left_temp_fl |= unpack_left_shift_u16(src_p[3], 8u, 0xffu);
    dst_p->center_right_temp_fl = unpack_right_shift_u16(src_p[4], 0u, 0xffu);
    dst_p->center_right_temp_fl |= unpack_left_shift_u16(src_p[5], 8u, 0xffu);
    dst_p->rightmost_temp_fl = unpack_right_shift_u16(src_p[6], 0u, 0xffu);
    dst_p->rightmost_temp_fl |= unpack_left_shift_u16(src_p[7], 8u, 0xffu);

    return (0);
}

int feb_can_front_left_tire_temp_init(struct feb_can_front_left_tire_temp_t *msg_p)
{
    if (msg_p == NULL) return -1;

    memset(msg_p, 0, sizeof(struct feb_can_front_left_tire_temp_t));

    return 0;
}

uint16_t feb_can_front_left_tire_temp_leftmost_temp_fl_encode(double value)
{
    return (uint16_t)(value);
}

double feb_can_front_left_tire_temp_leftmost_temp_fl_decode(uint16_t value)
{
    return ((double)value);
}

bool feb_can_front_left_tire_temp_leftmost_temp_fl_is_in_range(uint16_t value)
{
    (void)value;

    return (true);
}

uint16_t feb_can_front_left_tire_temp_center_left_temp_fl_encode(double value)
{
    return (uint16_t)(value);
}

double feb_can_front_left_tire_temp_center_left_temp_fl_decode(uint16_t value)
{
    return ((double)value);
}

bool feb_can_front_left_tire_temp_center_left_temp_fl_is_in_range(uint16_t value)
{
    (void)value;

    return (true);
}

uint16_t feb_can_front_left_tire_temp_center_right_temp_fl_encode(double value)
{
    return (uint16_t)(value);
}

double feb_can_front_left_tire_temp_center_right_temp_fl_decode(uint16_t value)
{
    return ((double)value);
}

bool feb_can_front_left_tire_temp_center_right_temp_fl_is_in_range(uint16_t value)
{
    (void)value;

    return (true);
}

uint16_t feb_can_front_left_tire_temp_rightmost_temp_fl_encode(double value)
{
    return (uint16_t)(value);
}

double feb_can_front_left_tire_temp_rightmost_temp_fl_decode(uint16_t value)
{
    return ((double)value);
}

bool feb_can_front_left_tire_temp_rightmost_temp_fl_is_in_range(uint16_t value)
{
    (void)value;

    return (true);
}

int feb_can_front_right_tire_temp_pack(
    uint8_t *dst_p,
    const struct feb_can_front_right_tire_temp_t *src_p,
    size_t size)
{
    if (size < 8u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 8);

    dst_p[0] |= pack_left_shift_u16(src_p->leftmost_temp_fr, 0u, 0xffu);
    dst_p[1] |= pack_right_shift_u16(src_p->leftmost_temp_fr, 8u, 0xffu);
    dst_p[2] |= pack_left_shift_u16(src_p->center_left_temp_fr, 0u, 0xffu);
    dst_p[3] |= pack_right_shift_u16(src_p->center_left_temp_fr, 8u, 0xffu);
    dst_p[4] |= pack_left_shift_u16(src_p->center_right_temp_fr, 0u, 0xffu);
    dst_p[5] |= pack_right_shift_u16(src_p->center_right_temp_fr, 8u, 0xffu);
    dst_p[6] |= pack_left_shift_u16(src_p->rightmost_temp_fr, 0u, 0xffu);
    dst_p[7] |= pack_right_shift_u16(src_p->rightmost_temp_fr, 8u, 0xffu);

    return (8);
}

int feb_can_front_right_tire_temp_unpack(
    struct feb_can_front_right_tire_temp_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    if (size < 8u) {
        return (-EINVAL);
    }

    dst_p->leftmost_temp_fr = unpack_right_shift_u16(src_p[0], 0u, 0xffu);
    dst_p->leftmost_temp_fr |= unpack_left_shift_u16(src_p[1], 8u, 0xffu);
    dst_p->center_left_temp_fr = unpack_right_shift_u16(src_p[2], 0u, 0xffu);
    dst_p->center_left_temp_fr |= unpack_left_shift_u16(src_p[3], 8u, 0xffu);
    dst_p->center_right_temp_fr = unpack_right_shift_u16(src_p[4], 0u, 0xffu);
    dst_p->center_right_temp_fr |= unpack_left_shift_u16(src_p[5], 8u, 0xffu);
    dst_p->rightmost_temp_fr = unpack_right_shift_u16(src_p[6], 0u, 0xffu);
    dst_p->rightmost_temp_fr |= unpack_left_shift_u16(src_p[7], 8u, 0xffu);

    return (0);
}

int feb_can_front_right_tire_temp_init(struct feb_can_front_right_tire_temp_t *msg_p)
{
    if (msg_p == NULL) return -1;

    memset(msg_p, 0, sizeof(struct feb_can_front_right_tire_temp_t));

    return 0;
}

uint16_t feb_can_front_right_tire_temp_leftmost_temp_fr_encode(double value)
{
    return (uint16_t)(value);
}

double feb_can_front_right_tire_temp_leftmost_temp_fr_decode(uint16_t value)
{
    return ((double)value);
}

bool feb_can_front_right_tire_temp_leftmost_temp_fr_is_in_range(uint16_t value)
{
    (void)value;

    return (true);
}

uint16_t feb_can_front_right_tire_temp_center_left_temp_fr_encode(double value)
{
    return (uint16_t)(value);
}

double feb_can_front_right_tire_temp_center_left_temp_fr_decode(uint16_t value)
{
    return ((double)value);
}

bool feb_can_front_right_tire_temp_center_left_temp_fr_is_in_range(uint16_t value)
{
    (void)value;

    return (true);
}

uint16_t feb_can_front_right_tire_temp_center_right_temp_fr_encode(double value)
{
    return (uint16_t)(value);
}

double feb_can_front_right_tire_temp_center_right_temp_fr_decode(uint16_t value)
{
    return ((double)value);
}

bool feb_can_front_right_tire_temp_center_right_temp_fr_is_in_range(uint16_t value)
{
    (void)value;

    return (true);
}

uint16_t feb_can_front_right_tire_temp_rightmost_temp_fr_encode(double value)
{
    return (uint16_t)(value);
}

double feb_can_front_right_tire_temp_rightmost_temp_fr_decode(uint16_t value)
{
    return ((double)value);
}

bool feb_can_front_right_tire_temp_rightmost_temp_fr_is_in_range(uint16_t value)
{
    (void)value;

    return (true);
}

int feb_can_rear_left_tire_temp_pack(
    uint8_t *dst_p,
    const struct feb_can_rear_left_tire_temp_t *src_p,
    size_t size)
{
    if (size < 8u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 8);

    dst_p[0] |= pack_left_shift_u16(src_p->leftmost_temp_rl, 0u, 0xffu);
    dst_p[1] |= pack_right_shift_u16(src_p->leftmost_temp_rl, 8u, 0xffu);
    dst_p[2] |= pack_left_shift_u16(src_p->center_left_temp_rl, 0u, 0xffu);
    dst_p[3] |= pack_right_shift_u16(src_p->center_left_temp_rl, 8u, 0xffu);
    dst_p[4] |= pack_left_shift_u16(src_p->center_right_temp_rl, 0u, 0xffu);
    dst_p[5] |= pack_right_shift_u16(src_p->center_right_temp_rl, 8u, 0xffu);
    dst_p[6] |= pack_left_shift_u16(src_p->rightmost_temp_rl, 0u, 0xffu);
    dst_p[7] |= pack_right_shift_u16(src_p->rightmost_temp_rl, 8u, 0xffu);

    return (8);
}

int feb_can_rear_left_tire_temp_unpack(
    struct feb_can_rear_left_tire_temp_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    if (size < 8u) {
        return (-EINVAL);
    }

    dst_p->leftmost_temp_rl = unpack_right_shift_u16(src_p[0], 0u, 0xffu);
    dst_p->leftmost_temp_rl |= unpack_left_shift_u16(src_p[1], 8u, 0xffu);
    dst_p->center_left_temp_rl = unpack_right_shift_u16(src_p[2], 0u, 0xffu);
    dst_p->center_left_temp_rl |= unpack_left_shift_u16(src_p[3], 8u, 0xffu);
    dst_p->center_right_temp_rl = unpack_right_shift_u16(src_p[4], 0u, 0xffu);
    dst_p->center_right_temp_rl |= unpack_left_shift_u16(src_p[5], 8u, 0xffu);
    dst_p->rightmost_temp_rl = unpack_right_shift_u16(src_p[6], 0u, 0xffu);
    dst_p->rightmost_temp_rl |= unpack_left_shift_u16(src_p[7], 8u, 0xffu);

    return (0);
}

int feb_can_rear_left_tire_temp_init(struct feb_can_rear_left_tire_temp_t *msg_p)
{
    if (msg_p == NULL) return -1;

    memset(msg_p, 0, sizeof(struct feb_can_rear_left_tire_temp_t));

    return 0;
}

uint16_t feb_can_rear_left_tire_temp_leftmost_temp_rl_encode(double value)
{
    return (uint16_t)(value);
}

double feb_can_rear_left_tire_temp_leftmost_temp_rl_decode(uint16_t value)
{
    return ((double)value);
}

bool feb_can_rear_left_tire_temp_leftmost_temp_rl_is_in_range(uint16_t value)
{
    (void)value;

    return (true);
}

uint16_t feb_can_rear_left_tire_temp_center_left_temp_rl_encode(double value)
{
    return (uint16_t)(value);
}

double feb_can_rear_left_tire_temp_center_left_temp_rl_decode(uint16_t value)
{
    return ((double)value);
}

bool feb_can_rear_left_tire_temp_center_left_temp_rl_is_in_range(uint16_t value)
{
    (void)value;

    return (true);
}

uint16_t feb_can_rear_left_tire_temp_center_right_temp_rl_encode(double value)
{
    return (uint16_t)(value);
}

double feb_can_rear_left_tire_temp_center_right_temp_rl_decode(uint16_t value)
{
    return ((double)value);
}

bool feb_can_rear_left_tire_temp_center_right_temp_rl_is_in_range(uint16_t value)
{
    (void)value;

    return (true);
}

uint16_t feb_can_rear_left_tire_temp_rightmost_temp_rl_encode(double value)
{
    return (uint16_t)(value);
}

double feb_can_rear_left_tire_temp_rightmost_temp_rl_decode(uint16_t value)
{
    return ((double)value);
}

bool feb_can_rear_left_tire_temp_rightmost_temp_rl_is_in_range(uint16_t value)
{
    (void)value;

    return (true);
}

int feb_can_rear_right_tire_temp_pack(
    uint8_t *dst_p,
    const struct feb_can_rear_right_tire_temp_t *src_p,
    size_t size)
{
    if (size < 8u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 8);

    dst_p[0] |= pack_left_shift_u16(src_p->leftmost_temp_rr, 0u, 0xffu);
    dst_p[1] |= pack_right_shift_u16(src_p->leftmost_temp_rr, 8u, 0xffu);
    dst_p[2] |= pack_left_shift_u16(src_p->center_left_temp_rr, 0u, 0xffu);
    dst_p[3] |= pack_right_shift_u16(src_p->center_left_temp_rr, 8u, 0xffu);
    dst_p[4] |= pack_left_shift_u16(src_p->center_right_temp_rr, 0u, 0xffu);
    dst_p[5] |= pack_right_shift_u16(src_p->center_right_temp_rr, 8u, 0xffu);
    dst_p[6] |= pack_left_shift_u16(src_p->rightmost_temp_rr, 0u, 0xffu);
    dst_p[7] |= pack_right_shift_u16(src_p->rightmost_temp_rr, 8u, 0xffu);

    return (8);
}

int feb_can_rear_right_tire_temp_unpack(
    struct feb_can_rear_right_tire_temp_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    if (size < 8u) {
        return (-EINVAL);
    }

    dst_p->leftmost_temp_rr = unpack_right_shift_u16(src_p[0], 0u, 0xffu);
    dst_p->leftmost_temp_rr |= unpack_left_shift_u16(src_p[1], 8u, 0xffu);
    dst_p->center_left_temp_rr = unpack_right_shift_u16(src_p[2], 0u, 0xffu);
    dst_p->center_left_temp_rr |= unpack_left_shift_u16(src_p[3], 8u, 0xffu);
    dst_p->center_right_temp_rr = unpack_right_shift_u16(src_p[4], 0u, 0xffu);
    dst_p->center_right_temp_rr |= unpack_left_shift_u16(src_p[5], 8u, 0xffu);
    dst_p->rightmost_temp_rr = unpack_right_shift_u16(src_p[6], 0u, 0xffu);
    dst_p->rightmost_temp_rr |= unpack_left_shift_u16(src_p[7], 8u, 0xffu);

    return (0);
}

int feb_can_rear_right_tire_temp_init(struct feb_can_rear_right_tire_temp_t *msg_p)
{
    if (msg_p == NULL) return -1;

    memset(msg_p, 0, sizeof(struct feb_can_rear_right_tire_temp_t));

    return 0;
}

uint16_t feb_can_rear_right_tire_temp_leftmost_temp_rr_encode(double value)
{
    return (uint16_t)(value);
}

double feb_can_rear_right_tire_temp_leftmost_temp_rr_decode(uint16_t value)
{
    return ((double)value);
}

bool feb_can_rear_right_tire_temp_leftmost_temp_rr_is_in_range(uint16_t value)
{
    (void)value;

    return (true);
}

uint16_t feb_can_rear_right_tire_temp_center_left_temp_rr_encode(double value)
{
    return (uint16_t)(value);
}

double feb_can_rear_right_tire_temp_center_left_temp_rr_decode(uint16_t value)
{
    return ((double)value);
}

bool feb_can_rear_right_tire_temp_center_left_temp_rr_is_in_range(uint16_t value)
{
    (void)value;

    return (true);
}

uint16_t feb_can_rear_right_tire_temp_center_right_temp_rr_encode(double value)
{
    return (uint16_t)(value);
}

double feb_can_rear_right_tire_temp_center_right_temp_rr_decode(uint16_t value)
{
    return ((double)value);
}

bool feb_can_rear_right_tire_temp_center_right_temp_rr_is_in_range(uint16_t value)
{
    (void)value;

    return (true);
}

uint16_t feb_can_rear_right_tire_temp_rightmost_temp_rr_encode(double value)
{
    return (uint16_t)(value);
}

double feb_can_rear_right_tire_temp_rightmost_temp_rr_decode(uint16_t value)
{
    return ((double)value);
}

bool feb_can_rear_right_tire_temp_rightmost_temp_rr_is_in_range(uint16_t value)
{
    (void)value;

    return (true);
}

int feb_can_wss_front_data_pack(
    uint8_t *dst_p,
    const struct feb_can_wss_front_data_t *src_p,
    size_t size)
{
    if (size < 8u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 8);

    dst_p[0] |= pack_left_shift_u16(src_p->wss_left_front, 0u, 0xffu);
    dst_p[1] |= pack_right_shift_u16(src_p->wss_left_front, 8u, 0xffu);
    dst_p[2] |= pack_left_shift_u16(src_p->wss_right_front, 0u, 0xffu);
    dst_p[3] |= pack_right_shift_u16(src_p->wss_right_front, 8u, 0xffu);
    dst_p[4] |= pack_left_shift_u8(src_p->wss_dir_flags, 0u, 0xffu);

    return (8);
}

int feb_can_wss_front_data_unpack(
    struct feb_can_wss_front_data_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    if (size < 8u) {
        return (-EINVAL);
    }

    dst_p->wss_left_front = unpack_right_shift_u16(src_p[0], 0u, 0xffu);
    dst_p->wss_left_front |= unpack_left_shift_u16(src_p[1], 8u, 0xffu);
    dst_p->wss_right_front = unpack_right_shift_u16(src_p[2], 0u, 0xffu);
    dst_p->wss_right_front |= unpack_left_shift_u16(src_p[3], 8u, 0xffu);
    dst_p->wss_dir_flags = unpack_right_shift_u8(src_p[4], 0u, 0xffu);

    return (0);
}

int feb_can_wss_front_data_init(struct feb_can_wss_front_data_t *msg_p)
{
    if (msg_p == NULL) return -1;

    memset(msg_p, 0, sizeof(struct feb_can_wss_front_data_t));

    return 0;
}

uint16_t feb_can_wss_front_data_wss_left_front_encode(double value)
{
    return (uint16_t)(value / 0.1);
}

double feb_can_wss_front_data_wss_left_front_decode(uint16_t value)
{
    return ((double)value * 0.1);
}

bool feb_can_wss_front_data_wss_left_front_is_in_range(uint16_t value)
{
    (void)value;

    return (true);
}

uint16_t feb_can_wss_front_data_wss_right_front_encode(double value)
{
    return (uint16_t)(value / 0.1);
}

double feb_can_wss_front_data_wss_right_front_decode(uint16_t value)
{
    return ((double)value * 0.1);
}

bool feb_can_wss_front_data_wss_right_front_is_in_range(uint16_t value)
{
    (void)value;

    return (true);
}

uint8_t feb_can_wss_front_data_wss_dir_flags_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_wss_front_data_wss_dir_flags_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_wss_front_data_wss_dir_flags_is_in_range(uint8_t value)
{
    (void)value;

    return (true);
}

int feb_can_wss_rear_data_pack(
    uint8_t *dst_p,
    const struct feb_can_wss_rear_data_t *src_p,
    size_t size)
{
    if (size < 8u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 8);

    dst_p[0] |= pack_left_shift_u32(src_p->wss_right_rear, 0u, 0xffu);
    dst_p[1] |= pack_right_shift_u32(src_p->wss_right_rear, 8u, 0xffu);
    dst_p[2] |= pack_right_shift_u32(src_p->wss_right_rear, 16u, 0xffu);
    dst_p[3] |= pack_right_shift_u32(src_p->wss_right_rear, 24u, 0xffu);
    dst_p[4] |= pack_left_shift_u32(src_p->wss_left_rear, 0u, 0xffu);
    dst_p[5] |= pack_right_shift_u32(src_p->wss_left_rear, 8u, 0xffu);
    dst_p[6] |= pack_right_shift_u32(src_p->wss_left_rear, 16u, 0xffu);
    dst_p[7] |= pack_right_shift_u32(src_p->wss_left_rear, 24u, 0xffu);

    return (8);
}

int feb_can_wss_rear_data_unpack(
    struct feb_can_wss_rear_data_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    if (size < 8u) {
        return (-EINVAL);
    }

    dst_p->wss_right_rear = unpack_right_shift_u32(src_p[0], 0u, 0xffu);
    dst_p->wss_right_rear |= unpack_left_shift_u32(src_p[1], 8u, 0xffu);
    dst_p->wss_right_rear |= unpack_left_shift_u32(src_p[2], 16u, 0xffu);
    dst_p->wss_right_rear |= unpack_left_shift_u32(src_p[3], 24u, 0xffu);
    dst_p->wss_left_rear = unpack_right_shift_u32(src_p[4], 0u, 0xffu);
    dst_p->wss_left_rear |= unpack_left_shift_u32(src_p[5], 8u, 0xffu);
    dst_p->wss_left_rear |= unpack_left_shift_u32(src_p[6], 16u, 0xffu);
    dst_p->wss_left_rear |= unpack_left_shift_u32(src_p[7], 24u, 0xffu);

    return (0);
}

int feb_can_wss_rear_data_init(struct feb_can_wss_rear_data_t *msg_p)
{
    if (msg_p == NULL) return -1;

    memset(msg_p, 0, sizeof(struct feb_can_wss_rear_data_t));

    return 0;
}

uint32_t feb_can_wss_rear_data_wss_right_rear_encode(double value)
{
    return (uint32_t)(value);
}

double feb_can_wss_rear_data_wss_right_rear_decode(uint32_t value)
{
    return ((double)value);
}

bool feb_can_wss_rear_data_wss_right_rear_is_in_range(uint32_t value)
{
    (void)value;

    return (true);
}

uint32_t feb_can_wss_rear_data_wss_left_rear_encode(double value)
{
    return (uint32_t)(value);
}

double feb_can_wss_rear_data_wss_left_rear_decode(uint32_t value)
{
    return ((double)value);
}

bool feb_can_wss_rear_data_wss_left_rear_is_in_range(uint32_t value)
{
    (void)value;

    return (true);
}

int feb_can_imu_acceleration_data_pack(
    uint8_t *dst_p,
    const struct feb_can_imu_acceleration_data_t *src_p,
    size_t size)
{
    uint16_t acceleration_x;
    uint16_t acceleration_y;
    uint16_t acceleration_z;

    if (size < 6u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 6);

    acceleration_x = (uint16_t)src_p->acceleration_x;
    dst_p[0] |= pack_left_shift_u16(acceleration_x, 0u, 0xffu);
    dst_p[1] |= pack_right_shift_u16(acceleration_x, 8u, 0xffu);
    acceleration_y = (uint16_t)src_p->acceleration_y;
    dst_p[2] |= pack_left_shift_u16(acceleration_y, 0u, 0xffu);
    dst_p[3] |= pack_right_shift_u16(acceleration_y, 8u, 0xffu);
    acceleration_z = (uint16_t)src_p->acceleration_z;
    dst_p[4] |= pack_left_shift_u16(acceleration_z, 0u, 0xffu);
    dst_p[5] |= pack_right_shift_u16(acceleration_z, 8u, 0xffu);

    return (6);
}

int feb_can_imu_acceleration_data_unpack(
    struct feb_can_imu_acceleration_data_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    uint16_t acceleration_x;
    uint16_t acceleration_y;
    uint16_t acceleration_z;

    if (size < 6u) {
        return (-EINVAL);
    }

    acceleration_x = unpack_right_shift_u16(src_p[0], 0u, 0xffu);
    acceleration_x |= unpack_left_shift_u16(src_p[1], 8u, 0xffu);
    dst_p->acceleration_x = (int16_t)acceleration_x;
    acceleration_y = unpack_right_shift_u16(src_p[2], 0u, 0xffu);
    acceleration_y |= unpack_left_shift_u16(src_p[3], 8u, 0xffu);
    dst_p->acceleration_y = (int16_t)acceleration_y;
    acceleration_z = unpack_right_shift_u16(src_p[4], 0u, 0xffu);
    acceleration_z |= unpack_left_shift_u16(src_p[5], 8u, 0xffu);
    dst_p->acceleration_z = (int16_t)acceleration_z;

    return (0);
}

int feb_can_imu_acceleration_data_init(struct feb_can_imu_acceleration_data_t *msg_p)
{
    if (msg_p == NULL) return -1;

    memset(msg_p, 0, sizeof(struct feb_can_imu_acceleration_data_t));

    return 0;
}

int16_t feb_can_imu_acceleration_data_acceleration_x_encode(double value)
{
    return (int16_t)(value / 0.061);
}

double feb_can_imu_acceleration_data_acceleration_x_decode(int16_t value)
{
    return ((double)value * 0.061);
}

bool feb_can_imu_acceleration_data_acceleration_x_is_in_range(int16_t value)
{
    (void)value;

    return (true);
}

int16_t feb_can_imu_acceleration_data_acceleration_y_encode(double value)
{
    return (int16_t)(value / 0.061);
}

double feb_can_imu_acceleration_data_acceleration_y_decode(int16_t value)
{
    return ((double)value * 0.061);
}

bool feb_can_imu_acceleration_data_acceleration_y_is_in_range(int16_t value)
{
    (void)value;

    return (true);
}

int16_t feb_can_imu_acceleration_data_acceleration_z_encode(double value)
{
    return (int16_t)(value / 0.061);
}

double feb_can_imu_acceleration_data_acceleration_z_decode(int16_t value)
{
    return ((double)value * 0.061);
}

bool feb_can_imu_acceleration_data_acceleration_z_is_in_range(int16_t value)
{
    (void)value;

    return (true);
}

int feb_can_imu_acceleration_data_rear_pack(
    uint8_t *dst_p,
    const struct feb_can_imu_acceleration_data_rear_t *src_p,
    size_t size)
{
    uint16_t acceleration_x;
    uint16_t acceleration_y;
    uint16_t acceleration_z;

    if (size < 6u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 6);

    acceleration_x = (uint16_t)src_p->acceleration_x;
    dst_p[0] |= pack_left_shift_u16(acceleration_x, 0u, 0xffu);
    dst_p[1] |= pack_right_shift_u16(acceleration_x, 8u, 0xffu);
    acceleration_y = (uint16_t)src_p->acceleration_y;
    dst_p[2] |= pack_left_shift_u16(acceleration_y, 0u, 0xffu);
    dst_p[3] |= pack_right_shift_u16(acceleration_y, 8u, 0xffu);
    acceleration_z = (uint16_t)src_p->acceleration_z;
    dst_p[4] |= pack_left_shift_u16(acceleration_z, 0u, 0xffu);
    dst_p[5] |= pack_right_shift_u16(acceleration_z, 8u, 0xffu);

    return (6);
}

int feb_can_imu_acceleration_data_rear_unpack(
    struct feb_can_imu_acceleration_data_rear_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    uint16_t acceleration_x;
    uint16_t acceleration_y;
    uint16_t acceleration_z;

    if (size < 6u) {
        return (-EINVAL);
    }

    acceleration_x = unpack_right_shift_u16(src_p[0], 0u, 0xffu);
    acceleration_x |= unpack_left_shift_u16(src_p[1], 8u, 0xffu);
    dst_p->acceleration_x = (int16_t)acceleration_x;
    acceleration_y = unpack_right_shift_u16(src_p[2], 0u, 0xffu);
    acceleration_y |= unpack_left_shift_u16(src_p[3], 8u, 0xffu);
    dst_p->acceleration_y = (int16_t)acceleration_y;
    acceleration_z = unpack_right_shift_u16(src_p[4], 0u, 0xffu);
    acceleration_z |= unpack_left_shift_u16(src_p[5], 8u, 0xffu);
    dst_p->acceleration_z = (int16_t)acceleration_z;

    return (0);
}

int feb_can_imu_acceleration_data_rear_init(struct feb_can_imu_acceleration_data_rear_t *msg_p)
{
    if (msg_p == NULL) return -1;

    memset(msg_p, 0, sizeof(struct feb_can_imu_acceleration_data_rear_t));

    return 0;
}

int16_t feb_can_imu_acceleration_data_rear_acceleration_x_encode(double value)
{
    return (int16_t)(value / 0.061);
}

double feb_can_imu_acceleration_data_rear_acceleration_x_decode(int16_t value)
{
    return ((double)value * 0.061);
}

bool feb_can_imu_acceleration_data_rear_acceleration_x_is_in_range(int16_t value)
{
    (void)value;

    return (true);
}

int16_t feb_can_imu_acceleration_data_rear_acceleration_y_encode(double value)
{
    return (int16_t)(value / 0.061);
}

double feb_can_imu_acceleration_data_rear_acceleration_y_decode(int16_t value)
{
    return ((double)value * 0.061);
}

bool feb_can_imu_acceleration_data_rear_acceleration_y_is_in_range(int16_t value)
{
    (void)value;

    return (true);
}

int16_t feb_can_imu_acceleration_data_rear_acceleration_z_encode(double value)
{
    return (int16_t)(value / 0.061);
}

double feb_can_imu_acceleration_data_rear_acceleration_z_decode(int16_t value)
{
    return ((double)value * 0.061);
}

bool feb_can_imu_acceleration_data_rear_acceleration_z_is_in_range(int16_t value)
{
    (void)value;

    return (true);
}

int feb_can_imu_gyro_data_pack(
    uint8_t *dst_p,
    const struct feb_can_imu_gyro_data_t *src_p,
    size_t size)
{
    uint16_t gyro_x;
    uint16_t gyro_y;
    uint16_t gyro_z;

    if (size < 6u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 6);

    gyro_x = (uint16_t)src_p->gyro_x;
    dst_p[0] |= pack_left_shift_u16(gyro_x, 0u, 0xffu);
    dst_p[1] |= pack_right_shift_u16(gyro_x, 8u, 0xffu);
    gyro_y = (uint16_t)src_p->gyro_y;
    dst_p[2] |= pack_left_shift_u16(gyro_y, 0u, 0xffu);
    dst_p[3] |= pack_right_shift_u16(gyro_y, 8u, 0xffu);
    gyro_z = (uint16_t)src_p->gyro_z;
    dst_p[4] |= pack_left_shift_u16(gyro_z, 0u, 0xffu);
    dst_p[5] |= pack_right_shift_u16(gyro_z, 8u, 0xffu);

    return (6);
}

int feb_can_imu_gyro_data_unpack(
    struct feb_can_imu_gyro_data_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    uint16_t gyro_x;
    uint16_t gyro_y;
    uint16_t gyro_z;

    if (size < 6u) {
        return (-EINVAL);
    }

    gyro_x = unpack_right_shift_u16(src_p[0], 0u, 0xffu);
    gyro_x |= unpack_left_shift_u16(src_p[1], 8u, 0xffu);
    dst_p->gyro_x = (int16_t)gyro_x;
    gyro_y = unpack_right_shift_u16(src_p[2], 0u, 0xffu);
    gyro_y |= unpack_left_shift_u16(src_p[3], 8u, 0xffu);
    dst_p->gyro_y = (int16_t)gyro_y;
    gyro_z = unpack_right_shift_u16(src_p[4], 0u, 0xffu);
    gyro_z |= unpack_left_shift_u16(src_p[5], 8u, 0xffu);
    dst_p->gyro_z = (int16_t)gyro_z;

    return (0);
}

int feb_can_imu_gyro_data_init(struct feb_can_imu_gyro_data_t *msg_p)
{
    if (msg_p == NULL) return -1;

    memset(msg_p, 0, sizeof(struct feb_can_imu_gyro_data_t));

    return 0;
}

int16_t feb_can_imu_gyro_data_gyro_x_encode(double value)
{
    return (int16_t)(value / 70.0);
}

double feb_can_imu_gyro_data_gyro_x_decode(int16_t value)
{
    return ((double)value * 70.0);
}

bool feb_can_imu_gyro_data_gyro_x_is_in_range(int16_t value)
{
    (void)value;

    return (true);
}

int16_t feb_can_imu_gyro_data_gyro_y_encode(double value)
{
    return (int16_t)(value / 70.0);
}

double feb_can_imu_gyro_data_gyro_y_decode(int16_t value)
{
    return ((double)value * 70.0);
}

bool feb_can_imu_gyro_data_gyro_y_is_in_range(int16_t value)
{
    (void)value;

    return (true);
}

int16_t feb_can_imu_gyro_data_gyro_z_encode(double value)
{
    return (int16_t)(value / 70.0);
}

double feb_can_imu_gyro_data_gyro_z_decode(int16_t value)
{
    return ((double)value * 70.0);
}

bool feb_can_imu_gyro_data_gyro_z_is_in_range(int16_t value)
{
    (void)value;

    return (true);
}

int feb_can_imu_gyro_data_rear_pack(
    uint8_t *dst_p,
    const struct feb_can_imu_gyro_data_rear_t *src_p,
    size_t size)
{
    uint16_t gyro_x;
    uint16_t gyro_y;
    uint16_t gyro_z;

    if (size < 6u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 6);

    gyro_x = (uint16_t)src_p->gyro_x;
    dst_p[0] |= pack_left_shift_u16(gyro_x, 0u, 0xffu);
    dst_p[1] |= pack_right_shift_u16(gyro_x, 8u, 0xffu);
    gyro_y = (uint16_t)src_p->gyro_y;
    dst_p[2] |= pack_left_shift_u16(gyro_y, 0u, 0xffu);
    dst_p[3] |= pack_right_shift_u16(gyro_y, 8u, 0xffu);
    gyro_z = (uint16_t)src_p->gyro_z;
    dst_p[4] |= pack_left_shift_u16(gyro_z, 0u, 0xffu);
    dst_p[5] |= pack_right_shift_u16(gyro_z, 8u, 0xffu);

    return (6);
}

int feb_can_imu_gyro_data_rear_unpack(
    struct feb_can_imu_gyro_data_rear_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    uint16_t gyro_x;
    uint16_t gyro_y;
    uint16_t gyro_z;

    if (size < 6u) {
        return (-EINVAL);
    }

    gyro_x = unpack_right_shift_u16(src_p[0], 0u, 0xffu);
    gyro_x |= unpack_left_shift_u16(src_p[1], 8u, 0xffu);
    dst_p->gyro_x = (int16_t)gyro_x;
    gyro_y = unpack_right_shift_u16(src_p[2], 0u, 0xffu);
    gyro_y |= unpack_left_shift_u16(src_p[3], 8u, 0xffu);
    dst_p->gyro_y = (int16_t)gyro_y;
    gyro_z = unpack_right_shift_u16(src_p[4], 0u, 0xffu);
    gyro_z |= unpack_left_shift_u16(src_p[5], 8u, 0xffu);
    dst_p->gyro_z = (int16_t)gyro_z;

    return (0);
}

int feb_can_imu_gyro_data_rear_init(struct feb_can_imu_gyro_data_rear_t *msg_p)
{
    if (msg_p == NULL) return -1;

    memset(msg_p, 0, sizeof(struct feb_can_imu_gyro_data_rear_t));

    return 0;
}

int16_t feb_can_imu_gyro_data_rear_gyro_x_encode(double value)
{
    return (int16_t)(value / 70.0);
}

double feb_can_imu_gyro_data_rear_gyro_x_decode(int16_t value)
{
    return ((double)value * 70.0);
}

bool feb_can_imu_gyro_data_rear_gyro_x_is_in_range(int16_t value)
{
    (void)value;

    return (true);
}

int16_t feb_can_imu_gyro_data_rear_gyro_y_encode(double value)
{
    return (int16_t)(value / 70.0);
}

double feb_can_imu_gyro_data_rear_gyro_y_decode(int16_t value)
{
    return ((double)value * 70.0);
}

bool feb_can_imu_gyro_data_rear_gyro_y_is_in_range(int16_t value)
{
    (void)value;

    return (true);
}

int16_t feb_can_imu_gyro_data_rear_gyro_z_encode(double value)
{
    return (int16_t)(value / 70.0);
}

double feb_can_imu_gyro_data_rear_gyro_z_decode(int16_t value)
{
    return ((double)value * 70.0);
}

bool feb_can_imu_gyro_data_rear_gyro_z_is_in_range(int16_t value)
{
    (void)value;

    return (true);
}

int feb_can_magnetometer_data_pack(
    uint8_t *dst_p,
    const struct feb_can_magnetometer_data_t *src_p,
    size_t size)
{
    uint16_t magnetometer_x;
    uint16_t magnetometer_y;
    uint16_t magnetometer_z;

    if (size < 6u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 6);

    magnetometer_x = (uint16_t)src_p->magnetometer_x;
    dst_p[0] |= pack_left_shift_u16(magnetometer_x, 0u, 0xffu);
    dst_p[1] |= pack_right_shift_u16(magnetometer_x, 8u, 0xffu);
    magnetometer_y = (uint16_t)src_p->magnetometer_y;
    dst_p[2] |= pack_left_shift_u16(magnetometer_y, 0u, 0xffu);
    dst_p[3] |= pack_right_shift_u16(magnetometer_y, 8u, 0xffu);
    magnetometer_z = (uint16_t)src_p->magnetometer_z;
    dst_p[4] |= pack_left_shift_u16(magnetometer_z, 0u, 0xffu);
    dst_p[5] |= pack_right_shift_u16(magnetometer_z, 8u, 0xffu);

    return (6);
}

int feb_can_magnetometer_data_unpack(
    struct feb_can_magnetometer_data_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    uint16_t magnetometer_x;
    uint16_t magnetometer_y;
    uint16_t magnetometer_z;

    if (size < 6u) {
        return (-EINVAL);
    }

    magnetometer_x = unpack_right_shift_u16(src_p[0], 0u, 0xffu);
    magnetometer_x |= unpack_left_shift_u16(src_p[1], 8u, 0xffu);
    dst_p->magnetometer_x = (int16_t)magnetometer_x;
    magnetometer_y = unpack_right_shift_u16(src_p[2], 0u, 0xffu);
    magnetometer_y |= unpack_left_shift_u16(src_p[3], 8u, 0xffu);
    dst_p->magnetometer_y = (int16_t)magnetometer_y;
    magnetometer_z = unpack_right_shift_u16(src_p[4], 0u, 0xffu);
    magnetometer_z |= unpack_left_shift_u16(src_p[5], 8u, 0xffu);
    dst_p->magnetometer_z = (int16_t)magnetometer_z;

    return (0);
}

int feb_can_magnetometer_data_init(struct feb_can_magnetometer_data_t *msg_p)
{
    if (msg_p == NULL) return -1;

    memset(msg_p, 0, sizeof(struct feb_can_magnetometer_data_t));

    return 0;
}

int16_t feb_can_magnetometer_data_magnetometer_x_encode(double value)
{
    return (int16_t)(value / 0.5844);
}

double feb_can_magnetometer_data_magnetometer_x_decode(int16_t value)
{
    return ((double)value * 0.5844);
}

bool feb_can_magnetometer_data_magnetometer_x_is_in_range(int16_t value)
{
    (void)value;

    return (true);
}

int16_t feb_can_magnetometer_data_magnetometer_y_encode(double value)
{
    return (int16_t)(value / 0.5844);
}

double feb_can_magnetometer_data_magnetometer_y_decode(int16_t value)
{
    return ((double)value * 0.5844);
}

bool feb_can_magnetometer_data_magnetometer_y_is_in_range(int16_t value)
{
    (void)value;

    return (true);
}

int16_t feb_can_magnetometer_data_magnetometer_z_encode(double value)
{
    return (int16_t)(value / 0.5844);
}

double feb_can_magnetometer_data_magnetometer_z_decode(int16_t value)
{
    return ((double)value * 0.5844);
}

bool feb_can_magnetometer_data_magnetometer_z_is_in_range(int16_t value)
{
    (void)value;

    return (true);
}

int feb_can_magnetometer_data_rear_pack(
    uint8_t *dst_p,
    const struct feb_can_magnetometer_data_rear_t *src_p,
    size_t size)
{
    uint16_t magnetometer_x;
    uint16_t magnetometer_y;
    uint16_t magnetometer_z;

    if (size < 6u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 6);

    magnetometer_x = (uint16_t)src_p->magnetometer_x;
    dst_p[0] |= pack_left_shift_u16(magnetometer_x, 0u, 0xffu);
    dst_p[1] |= pack_right_shift_u16(magnetometer_x, 8u, 0xffu);
    magnetometer_y = (uint16_t)src_p->magnetometer_y;
    dst_p[2] |= pack_left_shift_u16(magnetometer_y, 0u, 0xffu);
    dst_p[3] |= pack_right_shift_u16(magnetometer_y, 8u, 0xffu);
    magnetometer_z = (uint16_t)src_p->magnetometer_z;
    dst_p[4] |= pack_left_shift_u16(magnetometer_z, 0u, 0xffu);
    dst_p[5] |= pack_right_shift_u16(magnetometer_z, 8u, 0xffu);

    return (6);
}

int feb_can_magnetometer_data_rear_unpack(
    struct feb_can_magnetometer_data_rear_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    uint16_t magnetometer_x;
    uint16_t magnetometer_y;
    uint16_t magnetometer_z;

    if (size < 6u) {
        return (-EINVAL);
    }

    magnetometer_x = unpack_right_shift_u16(src_p[0], 0u, 0xffu);
    magnetometer_x |= unpack_left_shift_u16(src_p[1], 8u, 0xffu);
    dst_p->magnetometer_x = (int16_t)magnetometer_x;
    magnetometer_y = unpack_right_shift_u16(src_p[2], 0u, 0xffu);
    magnetometer_y |= unpack_left_shift_u16(src_p[3], 8u, 0xffu);
    dst_p->magnetometer_y = (int16_t)magnetometer_y;
    magnetometer_z = unpack_right_shift_u16(src_p[4], 0u, 0xffu);
    magnetometer_z |= unpack_left_shift_u16(src_p[5], 8u, 0xffu);
    dst_p->magnetometer_z = (int16_t)magnetometer_z;

    return (0);
}

int feb_can_magnetometer_data_rear_init(struct feb_can_magnetometer_data_rear_t *msg_p)
{
    if (msg_p == NULL) return -1;

    memset(msg_p, 0, sizeof(struct feb_can_magnetometer_data_rear_t));

    return 0;
}

int16_t feb_can_magnetometer_data_rear_magnetometer_x_encode(double value)
{
    return (int16_t)(value / 0.5844);
}

double feb_can_magnetometer_data_rear_magnetometer_x_decode(int16_t value)
{
    return ((double)value * 0.5844);
}

bool feb_can_magnetometer_data_rear_magnetometer_x_is_in_range(int16_t value)
{
    (void)value;

    return (true);
}

int16_t feb_can_magnetometer_data_rear_magnetometer_y_encode(double value)
{
    return (int16_t)(value / 0.5844);
}

double feb_can_magnetometer_data_rear_magnetometer_y_decode(int16_t value)
{
    return ((double)value * 0.5844);
}

bool feb_can_magnetometer_data_rear_magnetometer_y_is_in_range(int16_t value)
{
    (void)value;

    return (true);
}

int16_t feb_can_magnetometer_data_rear_magnetometer_z_encode(double value)
{
    return (int16_t)(value / 0.5844);
}

double feb_can_magnetometer_data_rear_magnetometer_z_decode(int16_t value)
{
    return ((double)value * 0.5844);
}

bool feb_can_magnetometer_data_rear_magnetometer_z_is_in_range(int16_t value)
{
    (void)value;

    return (true);
}

int feb_can_dart_tach_measurements_1234_pack(
    uint8_t *dst_p,
    const struct feb_can_dart_tach_measurements_1234_t *src_p,
    size_t size)
{
    if (size < 8u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 8);

    dst_p[0] |= pack_left_shift_u16(src_p->fan1_speed, 0u, 0xffu);
    dst_p[1] |= pack_right_shift_u16(src_p->fan1_speed, 8u, 0xffu);
    dst_p[2] |= pack_left_shift_u16(src_p->fan2_speed, 0u, 0xffu);
    dst_p[3] |= pack_right_shift_u16(src_p->fan2_speed, 8u, 0xffu);
    dst_p[4] |= pack_left_shift_u16(src_p->fan3_speed, 0u, 0xffu);
    dst_p[5] |= pack_right_shift_u16(src_p->fan3_speed, 8u, 0xffu);
    dst_p[6] |= pack_left_shift_u16(src_p->fan4_speed, 0u, 0xffu);
    dst_p[7] |= pack_right_shift_u16(src_p->fan4_speed, 8u, 0xffu);

    return (8);
}

int feb_can_dart_tach_measurements_1234_unpack(
    struct feb_can_dart_tach_measurements_1234_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    if (size < 8u) {
        return (-EINVAL);
    }

    dst_p->fan1_speed = unpack_right_shift_u16(src_p[0], 0u, 0xffu);
    dst_p->fan1_speed |= unpack_left_shift_u16(src_p[1], 8u, 0xffu);
    dst_p->fan2_speed = unpack_right_shift_u16(src_p[2], 0u, 0xffu);
    dst_p->fan2_speed |= unpack_left_shift_u16(src_p[3], 8u, 0xffu);
    dst_p->fan3_speed = unpack_right_shift_u16(src_p[4], 0u, 0xffu);
    dst_p->fan3_speed |= unpack_left_shift_u16(src_p[5], 8u, 0xffu);
    dst_p->fan4_speed = unpack_right_shift_u16(src_p[6], 0u, 0xffu);
    dst_p->fan4_speed |= unpack_left_shift_u16(src_p[7], 8u, 0xffu);

    return (0);
}

int feb_can_dart_tach_measurements_1234_init(struct feb_can_dart_tach_measurements_1234_t *msg_p)
{
    if (msg_p == NULL) return -1;

    memset(msg_p, 0, sizeof(struct feb_can_dart_tach_measurements_1234_t));

    return 0;
}

uint16_t feb_can_dart_tach_measurements_1234_fan1_speed_encode(double value)
{
    return (uint16_t)(value);
}

double feb_can_dart_tach_measurements_1234_fan1_speed_decode(uint16_t value)
{
    return ((double)value);
}

bool feb_can_dart_tach_measurements_1234_fan1_speed_is_in_range(uint16_t value)
{
    (void)value;

    return (true);
}

uint16_t feb_can_dart_tach_measurements_1234_fan2_speed_encode(double value)
{
    return (uint16_t)(value);
}

double feb_can_dart_tach_measurements_1234_fan2_speed_decode(uint16_t value)
{
    return ((double)value);
}

bool feb_can_dart_tach_measurements_1234_fan2_speed_is_in_range(uint16_t value)
{
    (void)value;

    return (true);
}

uint16_t feb_can_dart_tach_measurements_1234_fan3_speed_encode(double value)
{
    return (uint16_t)(value);
}

double feb_can_dart_tach_measurements_1234_fan3_speed_decode(uint16_t value)
{
    return ((double)value);
}

bool feb_can_dart_tach_measurements_1234_fan3_speed_is_in_range(uint16_t value)
{
    (void)value;

    return (true);
}

uint16_t feb_can_dart_tach_measurements_1234_fan4_speed_encode(double value)
{
    return (uint16_t)(value);
}

double feb_can_dart_tach_measurements_1234_fan4_speed_decode(uint16_t value)
{
    return ((double)value);
}

bool feb_can_dart_tach_measurements_1234_fan4_speed_is_in_range(uint16_t value)
{
    (void)value;

    return (true);
}

int feb_can_dart_tach_measurements_5_pack(
    uint8_t *dst_p,
    const struct feb_can_dart_tach_measurements_5_t *src_p,
    size_t size)
{
    if (size < 2u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 2);

    dst_p[0] |= pack_left_shift_u16(src_p->fan5_speed, 0u, 0xffu);
    dst_p[1] |= pack_right_shift_u16(src_p->fan5_speed, 8u, 0xffu);

    return (2);
}

int feb_can_dart_tach_measurements_5_unpack(
    struct feb_can_dart_tach_measurements_5_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    if (size < 2u) {
        return (-EINVAL);
    }

    dst_p->fan5_speed = unpack_right_shift_u16(src_p[0], 0u, 0xffu);
    dst_p->fan5_speed |= unpack_left_shift_u16(src_p[1], 8u, 0xffu);

    return (0);
}

int feb_can_dart_tach_measurements_5_init(struct feb_can_dart_tach_measurements_5_t *msg_p)
{
    if (msg_p == NULL) return -1;

    memset(msg_p, 0, sizeof(struct feb_can_dart_tach_measurements_5_t));

    return 0;
}

uint16_t feb_can_dart_tach_measurements_5_fan5_speed_encode(double value)
{
    return (uint16_t)(value);
}

double feb_can_dart_tach_measurements_5_fan5_speed_decode(uint16_t value)
{
    return ((double)value);
}

bool feb_can_dart_tach_measurements_5_fan5_speed_is_in_range(uint16_t value)
{
    (void)value;

    return (true);
}

int feb_can_bbb_tps_pack(
    uint8_t *dst_p,
    const struct feb_can_bbb_tps_t *src_p,
    size_t size)
{
    if (size < 4u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 4);

    dst_p[0] |= pack_left_shift_u16(src_p->voltage, 0u, 0xffu);
    dst_p[1] |= pack_right_shift_u16(src_p->voltage, 8u, 0xffu);
    dst_p[2] |= pack_left_shift_u16(src_p->current, 0u, 0xffu);
    dst_p[3] |= pack_right_shift_u16(src_p->current, 8u, 0xffu);

    return (4);
}

int feb_can_bbb_tps_unpack(
    struct feb_can_bbb_tps_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    if (size < 4u) {
        return (-EINVAL);
    }

    dst_p->voltage = unpack_right_shift_u16(src_p[0], 0u, 0xffu);
    dst_p->voltage |= unpack_left_shift_u16(src_p[1], 8u, 0xffu);
    dst_p->current = unpack_right_shift_u16(src_p[2], 0u, 0xffu);
    dst_p->current |= unpack_left_shift_u16(src_p[3], 8u, 0xffu);

    return (0);
}

int feb_can_bbb_tps_init(struct feb_can_bbb_tps_t *msg_p)
{
    if (msg_p == NULL) return -1;

    memset(msg_p, 0, sizeof(struct feb_can_bbb_tps_t));

    return 0;
}

uint16_t feb_can_bbb_tps_voltage_encode(double value)
{
    return (uint16_t)(value);
}

double feb_can_bbb_tps_voltage_decode(uint16_t value)
{
    return ((double)value);
}

bool feb_can_bbb_tps_voltage_is_in_range(uint16_t value)
{
    (void)value;

    return (true);
}

uint16_t feb_can_bbb_tps_current_encode(double value)
{
    return (uint16_t)(value);
}

double feb_can_bbb_tps_current_decode(uint16_t value)
{
    return ((double)value);
}

bool feb_can_bbb_tps_current_is_in_range(uint16_t value)
{
    (void)value;

    return (true);
}

int feb_can_pcu_tps_pack(
    uint8_t *dst_p,
    const struct feb_can_pcu_tps_t *src_p,
    size_t size)
{
    if (size < 4u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 4);

    dst_p[0] |= pack_left_shift_u16(src_p->voltage, 0u, 0xffu);
    dst_p[1] |= pack_right_shift_u16(src_p->voltage, 8u, 0xffu);
    dst_p[2] |= pack_left_shift_u16(src_p->current, 0u, 0xffu);
    dst_p[3] |= pack_right_shift_u16(src_p->current, 8u, 0xffu);

    return (4);
}

int feb_can_pcu_tps_unpack(
    struct feb_can_pcu_tps_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    if (size < 4u) {
        return (-EINVAL);
    }

    dst_p->voltage = unpack_right_shift_u16(src_p[0], 0u, 0xffu);
    dst_p->voltage |= unpack_left_shift_u16(src_p[1], 8u, 0xffu);
    dst_p->current = unpack_right_shift_u16(src_p[2], 0u, 0xffu);
    dst_p->current |= unpack_left_shift_u16(src_p[3], 8u, 0xffu);

    return (0);
}

int feb_can_pcu_tps_init(struct feb_can_pcu_tps_t *msg_p)
{
    if (msg_p == NULL) return -1;

    memset(msg_p, 0, sizeof(struct feb_can_pcu_tps_t));

    return 0;
}

uint16_t feb_can_pcu_tps_voltage_encode(double value)
{
    return (uint16_t)(value);
}

double feb_can_pcu_tps_voltage_decode(uint16_t value)
{
    return ((double)value);
}

bool feb_can_pcu_tps_voltage_is_in_range(uint16_t value)
{
    (void)value;

    return (true);
}

uint16_t feb_can_pcu_tps_current_encode(double value)
{
    return (uint16_t)(value);
}

double feb_can_pcu_tps_current_decode(uint16_t value)
{
    return ((double)value);
}

bool feb_can_pcu_tps_current_is_in_range(uint16_t value)
{
    (void)value;

    return (true);
}

int feb_can_dash_tps_pack(
    uint8_t *dst_p,
    const struct feb_can_dash_tps_t *src_p,
    size_t size)
{
    if (size < 4u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 4);

    dst_p[0] |= pack_left_shift_u16(src_p->voltage, 0u, 0xffu);
    dst_p[1] |= pack_right_shift_u16(src_p->voltage, 8u, 0xffu);
    dst_p[2] |= pack_left_shift_u16(src_p->current, 0u, 0xffu);
    dst_p[3] |= pack_right_shift_u16(src_p->current, 8u, 0xffu);

    return (4);
}

int feb_can_dash_tps_unpack(
    struct feb_can_dash_tps_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    if (size < 4u) {
        return (-EINVAL);
    }

    dst_p->voltage = unpack_right_shift_u16(src_p[0], 0u, 0xffu);
    dst_p->voltage |= unpack_left_shift_u16(src_p[1], 8u, 0xffu);
    dst_p->current = unpack_right_shift_u16(src_p[2], 0u, 0xffu);
    dst_p->current |= unpack_left_shift_u16(src_p[3], 8u, 0xffu);

    return (0);
}

int feb_can_dash_tps_init(struct feb_can_dash_tps_t *msg_p)
{
    if (msg_p == NULL) return -1;

    memset(msg_p, 0, sizeof(struct feb_can_dash_tps_t));

    return 0;
}

uint16_t feb_can_dash_tps_voltage_encode(double value)
{
    return (uint16_t)(value);
}

double feb_can_dash_tps_voltage_decode(uint16_t value)
{
    return ((double)value);
}

bool feb_can_dash_tps_voltage_is_in_range(uint16_t value)
{
    (void)value;

    return (true);
}

uint16_t feb_can_dash_tps_current_encode(double value)
{
    return (uint16_t)(value);
}

double feb_can_dash_tps_current_decode(uint16_t value)
{
    return ((double)value);
}

bool feb_can_dash_tps_current_is_in_range(uint16_t value)
{
    (void)value;

    return (true);
}

int feb_can_dcu_tps_pack(
    uint8_t *dst_p,
    const struct feb_can_dcu_tps_t *src_p,
    size_t size)
{
    if (size < 4u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 4);

    dst_p[0] |= pack_left_shift_u16(src_p->voltage, 0u, 0xffu);
    dst_p[1] |= pack_right_shift_u16(src_p->voltage, 8u, 0xffu);
    dst_p[2] |= pack_left_shift_u16(src_p->current, 0u, 0xffu);
    dst_p[3] |= pack_right_shift_u16(src_p->current, 8u, 0xffu);

    return (4);
}

int feb_can_dcu_tps_unpack(
    struct feb_can_dcu_tps_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    if (size < 4u) {
        return (-EINVAL);
    }

    dst_p->voltage = unpack_right_shift_u16(src_p[0], 0u, 0xffu);
    dst_p->voltage |= unpack_left_shift_u16(src_p[1], 8u, 0xffu);
    dst_p->current = unpack_right_shift_u16(src_p[2], 0u, 0xffu);
    dst_p->current |= unpack_left_shift_u16(src_p[3], 8u, 0xffu);

    return (0);
}

int feb_can_dcu_tps_init(struct feb_can_dcu_tps_t *msg_p)
{
    if (msg_p == NULL) return -1;

    memset(msg_p, 0, sizeof(struct feb_can_dcu_tps_t));

    return 0;
}

uint16_t feb_can_dcu_tps_voltage_encode(double value)
{
    return (uint16_t)(value);
}

double feb_can_dcu_tps_voltage_decode(uint16_t value)
{
    return ((double)value);
}

bool feb_can_dcu_tps_voltage_is_in_range(uint16_t value)
{
    (void)value;

    return (true);
}

uint16_t feb_can_dcu_tps_current_encode(double value)
{
    return (uint16_t)(value);
}

double feb_can_dcu_tps_current_decode(uint16_t value)
{
    return ((double)value);
}

bool feb_can_dcu_tps_current_is_in_range(uint16_t value)
{
    (void)value;

    return (true);
}

int feb_can_pcu_raw_acc_pack(
    uint8_t *dst_p,
    const struct feb_can_pcu_raw_acc_t *src_p,
    size_t size)
{
    if (size < 8u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 8);

    dst_p[0] |= pack_right_shift_u16(src_p->acc0, 8u, 0xffu);
    dst_p[1] |= pack_left_shift_u16(src_p->acc0, 0u, 0xffu);
    dst_p[2] |= pack_right_shift_u16(src_p->acc1, 8u, 0xffu);
    dst_p[3] |= pack_left_shift_u16(src_p->acc1, 0u, 0xffu);
    dst_p[4] |= pack_right_shift_u16(src_p->accel, 8u, 0xffu);
    dst_p[5] |= pack_left_shift_u16(src_p->accel, 0u, 0xffu);
    dst_p[6] |= pack_left_shift_u8(src_p->plausible, 0u, 0x01u);
    dst_p[6] |= pack_left_shift_u8(src_p->short_circuit, 1u, 0x02u);
    dst_p[6] |= pack_left_shift_u8(src_p->open_circuit, 2u, 0x04u);

    return (8);
}

int feb_can_pcu_raw_acc_unpack(
    struct feb_can_pcu_raw_acc_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    if (size < 8u) {
        return (-EINVAL);
    }

    dst_p->acc0 = unpack_left_shift_u16(src_p[0], 8u, 0xffu);
    dst_p->acc0 |= unpack_right_shift_u16(src_p[1], 0u, 0xffu);
    dst_p->acc1 = unpack_left_shift_u16(src_p[2], 8u, 0xffu);
    dst_p->acc1 |= unpack_right_shift_u16(src_p[3], 0u, 0xffu);
    dst_p->accel = unpack_left_shift_u16(src_p[4], 8u, 0xffu);
    dst_p->accel |= unpack_right_shift_u16(src_p[5], 0u, 0xffu);
    dst_p->plausible = unpack_right_shift_u8(src_p[6], 0u, 0x01u);
    dst_p->short_circuit = unpack_right_shift_u8(src_p[6], 1u, 0x02u);
    dst_p->open_circuit = unpack_right_shift_u8(src_p[6], 2u, 0x04u);

    return (0);
}

int feb_can_pcu_raw_acc_init(struct feb_can_pcu_raw_acc_t *msg_p)
{
    if (msg_p == NULL) return -1;

    memset(msg_p, 0, sizeof(struct feb_can_pcu_raw_acc_t));

    return 0;
}

uint16_t feb_can_pcu_raw_acc_acc0_encode(double value)
{
    return (uint16_t)(value);
}

double feb_can_pcu_raw_acc_acc0_decode(uint16_t value)
{
    return ((double)value);
}

bool feb_can_pcu_raw_acc_acc0_is_in_range(uint16_t value)
{
    (void)value;

    return (true);
}

uint16_t feb_can_pcu_raw_acc_acc1_encode(double value)
{
    return (uint16_t)(value);
}

double feb_can_pcu_raw_acc_acc1_decode(uint16_t value)
{
    return ((double)value);
}

bool feb_can_pcu_raw_acc_acc1_is_in_range(uint16_t value)
{
    (void)value;

    return (true);
}

uint16_t feb_can_pcu_raw_acc_accel_encode(double value)
{
    return (uint16_t)(value);
}

double feb_can_pcu_raw_acc_accel_decode(uint16_t value)
{
    return ((double)value);
}

bool feb_can_pcu_raw_acc_accel_is_in_range(uint16_t value)
{
    (void)value;

    return (true);
}

uint8_t feb_can_pcu_raw_acc_plausible_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_pcu_raw_acc_plausible_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_pcu_raw_acc_plausible_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_pcu_raw_acc_short_circuit_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_pcu_raw_acc_short_circuit_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_pcu_raw_acc_short_circuit_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_pcu_raw_acc_open_circuit_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_pcu_raw_acc_open_circuit_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_pcu_raw_acc_open_circuit_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

int feb_can_gps_pos_data_pack(
    uint8_t *dst_p,
    const struct feb_can_gps_pos_data_t *src_p,
    size_t size)
{
    uint32_t latitude;
    uint32_t longitude;

    if (size < 8u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 8);

    latitude = (uint32_t)src_p->latitude;
    dst_p[0] |= pack_left_shift_u32(latitude, 0u, 0xffu);
    dst_p[1] |= pack_right_shift_u32(latitude, 8u, 0xffu);
    dst_p[2] |= pack_right_shift_u32(latitude, 16u, 0xffu);
    dst_p[3] |= pack_right_shift_u32(latitude, 24u, 0xffu);
    longitude = (uint32_t)src_p->longitude;
    dst_p[4] |= pack_left_shift_u32(longitude, 0u, 0xffu);
    dst_p[5] |= pack_right_shift_u32(longitude, 8u, 0xffu);
    dst_p[6] |= pack_right_shift_u32(longitude, 16u, 0xffu);
    dst_p[7] |= pack_right_shift_u32(longitude, 24u, 0xffu);

    return (8);
}

int feb_can_gps_pos_data_unpack(
    struct feb_can_gps_pos_data_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    uint32_t latitude;
    uint32_t longitude;

    if (size < 8u) {
        return (-EINVAL);
    }

    latitude = unpack_right_shift_u32(src_p[0], 0u, 0xffu);
    latitude |= unpack_left_shift_u32(src_p[1], 8u, 0xffu);
    latitude |= unpack_left_shift_u32(src_p[2], 16u, 0xffu);
    latitude |= unpack_left_shift_u32(src_p[3], 24u, 0xffu);
    dst_p->latitude = (int32_t)latitude;
    longitude = unpack_right_shift_u32(src_p[4], 0u, 0xffu);
    longitude |= unpack_left_shift_u32(src_p[5], 8u, 0xffu);
    longitude |= unpack_left_shift_u32(src_p[6], 16u, 0xffu);
    longitude |= unpack_left_shift_u32(src_p[7], 24u, 0xffu);
    dst_p->longitude = (int32_t)longitude;

    return (0);
}

int feb_can_gps_pos_data_init(struct feb_can_gps_pos_data_t *msg_p)
{
    if (msg_p == NULL) return -1;

    memset(msg_p, 0, sizeof(struct feb_can_gps_pos_data_t));

    return 0;
}

int32_t feb_can_gps_pos_data_latitude_encode(double value)
{
    return (int32_t)(value / 1e-07);
}

double feb_can_gps_pos_data_latitude_decode(int32_t value)
{
    return ((double)value * 1e-07);
}

bool feb_can_gps_pos_data_latitude_is_in_range(int32_t value)
{
    (void)value;

    return (true);
}

int32_t feb_can_gps_pos_data_longitude_encode(double value)
{
    return (int32_t)(value / 1e-07);
}

double feb_can_gps_pos_data_longitude_decode(int32_t value)
{
    return ((double)value * 1e-07);
}

bool feb_can_gps_pos_data_longitude_is_in_range(int32_t value)
{
    (void)value;

    return (true);
}

int feb_can_gps_altitude_data_pack(
    uint8_t *dst_p,
    const struct feb_can_gps_altitude_data_t *src_p,
    size_t size)
{
    uint32_t altitude;

    if (size < 8u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 8);

    altitude = (uint32_t)src_p->altitude;
    dst_p[0] |= pack_left_shift_u32(altitude, 0u, 0xffu);
    dst_p[1] |= pack_right_shift_u32(altitude, 8u, 0xffu);
    dst_p[2] |= pack_right_shift_u32(altitude, 16u, 0xffu);
    dst_p[3] |= pack_right_shift_u32(altitude, 24u, 0xffu);
    dst_p[4] |= pack_left_shift_u16(src_p->hdop, 0u, 0xffu);
    dst_p[5] |= pack_right_shift_u16(src_p->hdop, 8u, 0xffu);
    dst_p[6] |= pack_left_shift_u16(src_p->vdop, 0u, 0xffu);
    dst_p[7] |= pack_right_shift_u16(src_p->vdop, 8u, 0xffu);

    return (8);
}

int feb_can_gps_altitude_data_unpack(
    struct feb_can_gps_altitude_data_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    uint32_t altitude;

    if (size < 8u) {
        return (-EINVAL);
    }

    altitude = unpack_right_shift_u32(src_p[0], 0u, 0xffu);
    altitude |= unpack_left_shift_u32(src_p[1], 8u, 0xffu);
    altitude |= unpack_left_shift_u32(src_p[2], 16u, 0xffu);
    altitude |= unpack_left_shift_u32(src_p[3], 24u, 0xffu);
    dst_p->altitude = (int32_t)altitude;
    dst_p->hdop = unpack_right_shift_u16(src_p[4], 0u, 0xffu);
    dst_p->hdop |= unpack_left_shift_u16(src_p[5], 8u, 0xffu);
    dst_p->vdop = unpack_right_shift_u16(src_p[6], 0u, 0xffu);
    dst_p->vdop |= unpack_left_shift_u16(src_p[7], 8u, 0xffu);

    return (0);
}

int feb_can_gps_altitude_data_init(struct feb_can_gps_altitude_data_t *msg_p)
{
    if (msg_p == NULL) return -1;

    memset(msg_p, 0, sizeof(struct feb_can_gps_altitude_data_t));

    return 0;
}

int32_t feb_can_gps_altitude_data_altitude_encode(double value)
{
    return (int32_t)(value / 0.01);
}

double feb_can_gps_altitude_data_altitude_decode(int32_t value)
{
    return ((double)value * 0.01);
}

bool feb_can_gps_altitude_data_altitude_is_in_range(int32_t value)
{
    (void)value;

    return (true);
}

uint16_t feb_can_gps_altitude_data_hdop_encode(double value)
{
    return (uint16_t)(value / 0.01);
}

double feb_can_gps_altitude_data_hdop_decode(uint16_t value)
{
    return ((double)value * 0.01);
}

bool feb_can_gps_altitude_data_hdop_is_in_range(uint16_t value)
{
    (void)value;

    return (true);
}

uint16_t feb_can_gps_altitude_data_vdop_encode(double value)
{
    return (uint16_t)(value / 0.01);
}

double feb_can_gps_altitude_data_vdop_decode(uint16_t value)
{
    return ((double)value * 0.01);
}

bool feb_can_gps_altitude_data_vdop_is_in_range(uint16_t value)
{
    (void)value;

    return (true);
}

int feb_can_gps_motion_data_pack(
    uint8_t *dst_p,
    const struct feb_can_gps_motion_data_t *src_p,
    size_t size)
{
    if (size < 4u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 4);

    dst_p[0] |= pack_left_shift_u16(src_p->speed, 0u, 0xffu);
    dst_p[1] |= pack_right_shift_u16(src_p->speed, 8u, 0xffu);
    dst_p[2] |= pack_left_shift_u16(src_p->course, 0u, 0xffu);
    dst_p[3] |= pack_right_shift_u16(src_p->course, 8u, 0xffu);

    return (4);
}

int feb_can_gps_motion_data_unpack(
    struct feb_can_gps_motion_data_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    if (size < 4u) {
        return (-EINVAL);
    }

    dst_p->speed = unpack_right_shift_u16(src_p[0], 0u, 0xffu);
    dst_p->speed |= unpack_left_shift_u16(src_p[1], 8u, 0xffu);
    dst_p->course = unpack_right_shift_u16(src_p[2], 0u, 0xffu);
    dst_p->course |= unpack_left_shift_u16(src_p[3], 8u, 0xffu);

    return (0);
}

int feb_can_gps_motion_data_init(struct feb_can_gps_motion_data_t *msg_p)
{
    if (msg_p == NULL) return -1;

    memset(msg_p, 0, sizeof(struct feb_can_gps_motion_data_t));

    return 0;
}

uint16_t feb_can_gps_motion_data_speed_encode(double value)
{
    return (uint16_t)(value / 0.01);
}

double feb_can_gps_motion_data_speed_decode(uint16_t value)
{
    return ((double)value * 0.01);
}

bool feb_can_gps_motion_data_speed_is_in_range(uint16_t value)
{
    (void)value;

    return (true);
}

uint16_t feb_can_gps_motion_data_course_encode(double value)
{
    return (uint16_t)(value / 0.01);
}

double feb_can_gps_motion_data_course_decode(uint16_t value)
{
    return ((double)value * 0.01);
}

bool feb_can_gps_motion_data_course_is_in_range(uint16_t value)
{
    (void)value;

    return (true);
}

int feb_can_gps_time_data_pack(
    uint8_t *dst_p,
    const struct feb_can_gps_time_data_t *src_p,
    size_t size)
{
    uint8_t hours;
    uint8_t minutes;
    uint8_t seconds;

    if (size < 3u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 3);

    hours = (uint8_t)src_p->hours;
    dst_p[0] |= pack_left_shift_u8(hours, 0u, 0xffu);
    minutes = (uint8_t)src_p->minutes;
    dst_p[1] |= pack_left_shift_u8(minutes, 0u, 0xffu);
    seconds = (uint8_t)src_p->seconds;
    dst_p[2] |= pack_left_shift_u8(seconds, 0u, 0xffu);

    return (3);
}

int feb_can_gps_time_data_unpack(
    struct feb_can_gps_time_data_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    uint8_t hours;
    uint8_t minutes;
    uint8_t seconds;

    if (size < 3u) {
        return (-EINVAL);
    }

    hours = unpack_right_shift_u8(src_p[0], 0u, 0xffu);
    dst_p->hours = (int8_t)hours;
    minutes = unpack_right_shift_u8(src_p[1], 0u, 0xffu);
    dst_p->minutes = (int8_t)minutes;
    seconds = unpack_right_shift_u8(src_p[2], 0u, 0xffu);
    dst_p->seconds = (int8_t)seconds;

    return (0);
}

int feb_can_gps_time_data_init(struct feb_can_gps_time_data_t *msg_p)
{
    if (msg_p == NULL) return -1;

    memset(msg_p, 0, sizeof(struct feb_can_gps_time_data_t));

    return 0;
}

int8_t feb_can_gps_time_data_hours_encode(double value)
{
    return (int8_t)(value);
}

double feb_can_gps_time_data_hours_decode(int8_t value)
{
    return ((double)value);
}

bool feb_can_gps_time_data_hours_is_in_range(int8_t value)
{
    (void)value;

    return (true);
}

int8_t feb_can_gps_time_data_minutes_encode(double value)
{
    return (int8_t)(value);
}

double feb_can_gps_time_data_minutes_decode(int8_t value)
{
    return ((double)value);
}

bool feb_can_gps_time_data_minutes_is_in_range(int8_t value)
{
    (void)value;

    return (true);
}

int8_t feb_can_gps_time_data_seconds_encode(double value)
{
    return (int8_t)(value);
}

double feb_can_gps_time_data_seconds_decode(int8_t value)
{
    return ((double)value);
}

bool feb_can_gps_time_data_seconds_is_in_range(int8_t value)
{
    (void)value;

    return (true);
}

int feb_can_gps_date_data_pack(
    uint8_t *dst_p,
    const struct feb_can_gps_date_data_t *src_p,
    size_t size)
{
    uint8_t day;
    uint8_t month;
    uint8_t year;

    if (size < 3u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 3);

    day = (uint8_t)src_p->day;
    dst_p[0] |= pack_left_shift_u8(day, 0u, 0xffu);
    month = (uint8_t)src_p->month;
    dst_p[1] |= pack_left_shift_u8(month, 0u, 0xffu);
    year = (uint8_t)src_p->year;
    dst_p[2] |= pack_left_shift_u8(year, 0u, 0xffu);

    return (3);
}

int feb_can_gps_date_data_unpack(
    struct feb_can_gps_date_data_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    uint8_t day;
    uint8_t month;
    uint8_t year;

    if (size < 3u) {
        return (-EINVAL);
    }

    day = unpack_right_shift_u8(src_p[0], 0u, 0xffu);
    dst_p->day = (int8_t)day;
    month = unpack_right_shift_u8(src_p[1], 0u, 0xffu);
    dst_p->month = (int8_t)month;
    year = unpack_right_shift_u8(src_p[2], 0u, 0xffu);
    dst_p->year = (int8_t)year;

    return (0);
}

int feb_can_gps_date_data_init(struct feb_can_gps_date_data_t *msg_p)
{
    if (msg_p == NULL) return -1;

    memset(msg_p, 0, sizeof(struct feb_can_gps_date_data_t));

    return 0;
}

int8_t feb_can_gps_date_data_day_encode(double value)
{
    return (int8_t)(value);
}

double feb_can_gps_date_data_day_decode(int8_t value)
{
    return ((double)value);
}

bool feb_can_gps_date_data_day_is_in_range(int8_t value)
{
    (void)value;

    return (true);
}

int8_t feb_can_gps_date_data_month_encode(double value)
{
    return (int8_t)(value);
}

double feb_can_gps_date_data_month_decode(int8_t value)
{
    return ((double)value);
}

bool feb_can_gps_date_data_month_is_in_range(int8_t value)
{
    (void)value;

    return (true);
}

int8_t feb_can_gps_date_data_year_encode(double value)
{
    return (int8_t)(value);
}

double feb_can_gps_date_data_year_decode(int8_t value)
{
    return ((double)value);
}

bool feb_can_gps_date_data_year_is_in_range(int8_t value)
{
    (void)value;

    return (true);
}

int feb_can_gps_status_data_pack(
    uint8_t *dst_p,
    const struct feb_can_gps_status_data_t *src_p,
    size_t size)
{
    if (size < 8u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 8);

    dst_p[0] |= pack_left_shift_u8(src_p->fix_type, 0u, 0xffu);
    dst_p[1] |= pack_left_shift_u8(src_p->fix_mode, 0u, 0xffu);
    dst_p[2] |= pack_left_shift_u8(src_p->sats_in_use, 0u, 0xffu);
    dst_p[3] |= pack_left_shift_u8(src_p->sats_in_view, 0u, 0xffu);
    dst_p[4] |= pack_left_shift_u8(src_p->valid, 0u, 0xffu);
    dst_p[5] |= pack_left_shift_u8(src_p->has_fix, 0u, 0xffu);
    dst_p[6] |= pack_left_shift_u16(src_p->pdop, 0u, 0xffu);
    dst_p[7] |= pack_right_shift_u16(src_p->pdop, 8u, 0xffu);

    return (8);
}

int feb_can_gps_status_data_unpack(
    struct feb_can_gps_status_data_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    if (size < 8u) {
        return (-EINVAL);
    }

    dst_p->fix_type = unpack_right_shift_u8(src_p[0], 0u, 0xffu);
    dst_p->fix_mode = unpack_right_shift_u8(src_p[1], 0u, 0xffu);
    dst_p->sats_in_use = unpack_right_shift_u8(src_p[2], 0u, 0xffu);
    dst_p->sats_in_view = unpack_right_shift_u8(src_p[3], 0u, 0xffu);
    dst_p->valid = unpack_right_shift_u8(src_p[4], 0u, 0xffu);
    dst_p->has_fix = unpack_right_shift_u8(src_p[5], 0u, 0xffu);
    dst_p->pdop = unpack_right_shift_u16(src_p[6], 0u, 0xffu);
    dst_p->pdop |= unpack_left_shift_u16(src_p[7], 8u, 0xffu);

    return (0);
}

int feb_can_gps_status_data_init(struct feb_can_gps_status_data_t *msg_p)
{
    if (msg_p == NULL) return -1;

    memset(msg_p, 0, sizeof(struct feb_can_gps_status_data_t));

    return 0;
}

uint8_t feb_can_gps_status_data_fix_type_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_gps_status_data_fix_type_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_gps_status_data_fix_type_is_in_range(uint8_t value)
{
    (void)value;

    return (true);
}

uint8_t feb_can_gps_status_data_fix_mode_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_gps_status_data_fix_mode_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_gps_status_data_fix_mode_is_in_range(uint8_t value)
{
    (void)value;

    return (true);
}

uint8_t feb_can_gps_status_data_sats_in_use_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_gps_status_data_sats_in_use_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_gps_status_data_sats_in_use_is_in_range(uint8_t value)
{
    (void)value;

    return (true);
}

uint8_t feb_can_gps_status_data_sats_in_view_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_gps_status_data_sats_in_view_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_gps_status_data_sats_in_view_is_in_range(uint8_t value)
{
    (void)value;

    return (true);
}

uint8_t feb_can_gps_status_data_valid_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_gps_status_data_valid_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_gps_status_data_valid_is_in_range(uint8_t value)
{
    (void)value;

    return (true);
}

uint8_t feb_can_gps_status_data_has_fix_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_gps_status_data_has_fix_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_gps_status_data_has_fix_is_in_range(uint8_t value)
{
    (void)value;

    return (true);
}

uint16_t feb_can_gps_status_data_pdop_encode(double value)
{
    return (uint16_t)(value / 0.01);
}

double feb_can_gps_status_data_pdop_decode(uint16_t value)
{
    return ((double)value * 0.01);
}

bool feb_can_gps_status_data_pdop_is_in_range(uint16_t value)
{
    (void)value;

    return (true);
}

int feb_can_fusion_quaternion_data_pack(
    uint8_t *dst_p,
    const struct feb_can_fusion_quaternion_data_t *src_p,
    size_t size)
{
    uint16_t q_w;
    uint16_t q_x;
    uint16_t q_y;
    uint16_t q_z;

    if (size < 8u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 8);

    q_w = (uint16_t)src_p->q_w;
    dst_p[0] |= pack_left_shift_u16(q_w, 0u, 0xffu);
    dst_p[1] |= pack_right_shift_u16(q_w, 8u, 0xffu);
    q_x = (uint16_t)src_p->q_x;
    dst_p[2] |= pack_left_shift_u16(q_x, 0u, 0xffu);
    dst_p[3] |= pack_right_shift_u16(q_x, 8u, 0xffu);
    q_y = (uint16_t)src_p->q_y;
    dst_p[4] |= pack_left_shift_u16(q_y, 0u, 0xffu);
    dst_p[5] |= pack_right_shift_u16(q_y, 8u, 0xffu);
    q_z = (uint16_t)src_p->q_z;
    dst_p[6] |= pack_left_shift_u16(q_z, 0u, 0xffu);
    dst_p[7] |= pack_right_shift_u16(q_z, 8u, 0xffu);

    return (8);
}

int feb_can_fusion_quaternion_data_unpack(
    struct feb_can_fusion_quaternion_data_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    uint16_t q_w;
    uint16_t q_x;
    uint16_t q_y;
    uint16_t q_z;

    if (size < 8u) {
        return (-EINVAL);
    }

    q_w = unpack_right_shift_u16(src_p[0], 0u, 0xffu);
    q_w |= unpack_left_shift_u16(src_p[1], 8u, 0xffu);
    dst_p->q_w = (int16_t)q_w;
    q_x = unpack_right_shift_u16(src_p[2], 0u, 0xffu);
    q_x |= unpack_left_shift_u16(src_p[3], 8u, 0xffu);
    dst_p->q_x = (int16_t)q_x;
    q_y = unpack_right_shift_u16(src_p[4], 0u, 0xffu);
    q_y |= unpack_left_shift_u16(src_p[5], 8u, 0xffu);
    dst_p->q_y = (int16_t)q_y;
    q_z = unpack_right_shift_u16(src_p[6], 0u, 0xffu);
    q_z |= unpack_left_shift_u16(src_p[7], 8u, 0xffu);
    dst_p->q_z = (int16_t)q_z;

    return (0);
}

int feb_can_fusion_quaternion_data_init(struct feb_can_fusion_quaternion_data_t *msg_p)
{
    if (msg_p == NULL) return -1;

    memset(msg_p, 0, sizeof(struct feb_can_fusion_quaternion_data_t));

    return 0;
}

int16_t feb_can_fusion_quaternion_data_q_w_encode(double value)
{
    return (int16_t)(value / 3.051850947599719e-05);
}

double feb_can_fusion_quaternion_data_q_w_decode(int16_t value)
{
    return ((double)value * 3.051850947599719e-05);
}

bool feb_can_fusion_quaternion_data_q_w_is_in_range(int16_t value)
{
    (void)value;

    return (true);
}

int16_t feb_can_fusion_quaternion_data_q_x_encode(double value)
{
    return (int16_t)(value / 3.051850947599719e-05);
}

double feb_can_fusion_quaternion_data_q_x_decode(int16_t value)
{
    return ((double)value * 3.051850947599719e-05);
}

bool feb_can_fusion_quaternion_data_q_x_is_in_range(int16_t value)
{
    (void)value;

    return (true);
}

int16_t feb_can_fusion_quaternion_data_q_y_encode(double value)
{
    return (int16_t)(value / 3.051850947599719e-05);
}

double feb_can_fusion_quaternion_data_q_y_decode(int16_t value)
{
    return ((double)value * 3.051850947599719e-05);
}

bool feb_can_fusion_quaternion_data_q_y_is_in_range(int16_t value)
{
    (void)value;

    return (true);
}

int16_t feb_can_fusion_quaternion_data_q_z_encode(double value)
{
    return (int16_t)(value / 3.051850947599719e-05);
}

double feb_can_fusion_quaternion_data_q_z_decode(int16_t value)
{
    return ((double)value * 3.051850947599719e-05);
}

bool feb_can_fusion_quaternion_data_q_z_is_in_range(int16_t value)
{
    (void)value;

    return (true);
}

int feb_can_fusion_euler_data_pack(
    uint8_t *dst_p,
    const struct feb_can_fusion_euler_data_t *src_p,
    size_t size)
{
    uint16_t pitch;
    uint16_t roll;
    uint16_t yaw;

    if (size < 6u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 6);

    roll = (uint16_t)src_p->roll;
    dst_p[0] |= pack_left_shift_u16(roll, 0u, 0xffu);
    dst_p[1] |= pack_right_shift_u16(roll, 8u, 0xffu);
    pitch = (uint16_t)src_p->pitch;
    dst_p[2] |= pack_left_shift_u16(pitch, 0u, 0xffu);
    dst_p[3] |= pack_right_shift_u16(pitch, 8u, 0xffu);
    yaw = (uint16_t)src_p->yaw;
    dst_p[4] |= pack_left_shift_u16(yaw, 0u, 0xffu);
    dst_p[5] |= pack_right_shift_u16(yaw, 8u, 0xffu);

    return (6);
}

int feb_can_fusion_euler_data_unpack(
    struct feb_can_fusion_euler_data_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    uint16_t pitch;
    uint16_t roll;
    uint16_t yaw;

    if (size < 6u) {
        return (-EINVAL);
    }

    roll = unpack_right_shift_u16(src_p[0], 0u, 0xffu);
    roll |= unpack_left_shift_u16(src_p[1], 8u, 0xffu);
    dst_p->roll = (int16_t)roll;
    pitch = unpack_right_shift_u16(src_p[2], 0u, 0xffu);
    pitch |= unpack_left_shift_u16(src_p[3], 8u, 0xffu);
    dst_p->pitch = (int16_t)pitch;
    yaw = unpack_right_shift_u16(src_p[4], 0u, 0xffu);
    yaw |= unpack_left_shift_u16(src_p[5], 8u, 0xffu);
    dst_p->yaw = (int16_t)yaw;

    return (0);
}

int feb_can_fusion_euler_data_init(struct feb_can_fusion_euler_data_t *msg_p)
{
    if (msg_p == NULL) return -1;

    memset(msg_p, 0, sizeof(struct feb_can_fusion_euler_data_t));

    return 0;
}

int16_t feb_can_fusion_euler_data_roll_encode(double value)
{
    return (int16_t)(value / 0.01);
}

double feb_can_fusion_euler_data_roll_decode(int16_t value)
{
    return ((double)value * 0.01);
}

bool feb_can_fusion_euler_data_roll_is_in_range(int16_t value)
{
    (void)value;

    return (true);
}

int16_t feb_can_fusion_euler_data_pitch_encode(double value)
{
    return (int16_t)(value / 0.01);
}

double feb_can_fusion_euler_data_pitch_decode(int16_t value)
{
    return ((double)value * 0.01);
}

bool feb_can_fusion_euler_data_pitch_is_in_range(int16_t value)
{
    (void)value;

    return (true);
}

int16_t feb_can_fusion_euler_data_yaw_encode(double value)
{
    return (int16_t)(value / 0.01);
}

double feb_can_fusion_euler_data_yaw_decode(int16_t value)
{
    return ((double)value * 0.01);
}

bool feb_can_fusion_euler_data_yaw_is_in_range(int16_t value)
{
    (void)value;

    return (true);
}

int feb_can_fusion_linear_accel_data_pack(
    uint8_t *dst_p,
    const struct feb_can_fusion_linear_accel_data_t *src_p,
    size_t size)
{
    uint16_t lin_accel_x;
    uint16_t lin_accel_y;
    uint16_t lin_accel_z;

    if (size < 6u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 6);

    lin_accel_x = (uint16_t)src_p->lin_accel_x;
    dst_p[0] |= pack_left_shift_u16(lin_accel_x, 0u, 0xffu);
    dst_p[1] |= pack_right_shift_u16(lin_accel_x, 8u, 0xffu);
    lin_accel_y = (uint16_t)src_p->lin_accel_y;
    dst_p[2] |= pack_left_shift_u16(lin_accel_y, 0u, 0xffu);
    dst_p[3] |= pack_right_shift_u16(lin_accel_y, 8u, 0xffu);
    lin_accel_z = (uint16_t)src_p->lin_accel_z;
    dst_p[4] |= pack_left_shift_u16(lin_accel_z, 0u, 0xffu);
    dst_p[5] |= pack_right_shift_u16(lin_accel_z, 8u, 0xffu);

    return (6);
}

int feb_can_fusion_linear_accel_data_unpack(
    struct feb_can_fusion_linear_accel_data_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    uint16_t lin_accel_x;
    uint16_t lin_accel_y;
    uint16_t lin_accel_z;

    if (size < 6u) {
        return (-EINVAL);
    }

    lin_accel_x = unpack_right_shift_u16(src_p[0], 0u, 0xffu);
    lin_accel_x |= unpack_left_shift_u16(src_p[1], 8u, 0xffu);
    dst_p->lin_accel_x = (int16_t)lin_accel_x;
    lin_accel_y = unpack_right_shift_u16(src_p[2], 0u, 0xffu);
    lin_accel_y |= unpack_left_shift_u16(src_p[3], 8u, 0xffu);
    dst_p->lin_accel_y = (int16_t)lin_accel_y;
    lin_accel_z = unpack_right_shift_u16(src_p[4], 0u, 0xffu);
    lin_accel_z |= unpack_left_shift_u16(src_p[5], 8u, 0xffu);
    dst_p->lin_accel_z = (int16_t)lin_accel_z;

    return (0);
}

int feb_can_fusion_linear_accel_data_init(struct feb_can_fusion_linear_accel_data_t *msg_p)
{
    if (msg_p == NULL) return -1;

    memset(msg_p, 0, sizeof(struct feb_can_fusion_linear_accel_data_t));

    return 0;
}

int16_t feb_can_fusion_linear_accel_data_lin_accel_x_encode(double value)
{
    return (int16_t)(value);
}

double feb_can_fusion_linear_accel_data_lin_accel_x_decode(int16_t value)
{
    return ((double)value);
}

bool feb_can_fusion_linear_accel_data_lin_accel_x_is_in_range(int16_t value)
{
    (void)value;

    return (true);
}

int16_t feb_can_fusion_linear_accel_data_lin_accel_y_encode(double value)
{
    return (int16_t)(value);
}

double feb_can_fusion_linear_accel_data_lin_accel_y_decode(int16_t value)
{
    return ((double)value);
}

bool feb_can_fusion_linear_accel_data_lin_accel_y_is_in_range(int16_t value)
{
    (void)value;

    return (true);
}

int16_t feb_can_fusion_linear_accel_data_lin_accel_z_encode(double value)
{
    return (int16_t)(value);
}

double feb_can_fusion_linear_accel_data_lin_accel_z_decode(int16_t value)
{
    return ((double)value);
}

bool feb_can_fusion_linear_accel_data_lin_accel_z_is_in_range(int16_t value)
{
    (void)value;

    return (true);
}

int feb_can_fusion_earth_accel_data_pack(
    uint8_t *dst_p,
    const struct feb_can_fusion_earth_accel_data_t *src_p,
    size_t size)
{
    uint16_t earth_accel_x;
    uint16_t earth_accel_y;
    uint16_t earth_accel_z;

    if (size < 6u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 6);

    earth_accel_x = (uint16_t)src_p->earth_accel_x;
    dst_p[0] |= pack_left_shift_u16(earth_accel_x, 0u, 0xffu);
    dst_p[1] |= pack_right_shift_u16(earth_accel_x, 8u, 0xffu);
    earth_accel_y = (uint16_t)src_p->earth_accel_y;
    dst_p[2] |= pack_left_shift_u16(earth_accel_y, 0u, 0xffu);
    dst_p[3] |= pack_right_shift_u16(earth_accel_y, 8u, 0xffu);
    earth_accel_z = (uint16_t)src_p->earth_accel_z;
    dst_p[4] |= pack_left_shift_u16(earth_accel_z, 0u, 0xffu);
    dst_p[5] |= pack_right_shift_u16(earth_accel_z, 8u, 0xffu);

    return (6);
}

int feb_can_fusion_earth_accel_data_unpack(
    struct feb_can_fusion_earth_accel_data_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    uint16_t earth_accel_x;
    uint16_t earth_accel_y;
    uint16_t earth_accel_z;

    if (size < 6u) {
        return (-EINVAL);
    }

    earth_accel_x = unpack_right_shift_u16(src_p[0], 0u, 0xffu);
    earth_accel_x |= unpack_left_shift_u16(src_p[1], 8u, 0xffu);
    dst_p->earth_accel_x = (int16_t)earth_accel_x;
    earth_accel_y = unpack_right_shift_u16(src_p[2], 0u, 0xffu);
    earth_accel_y |= unpack_left_shift_u16(src_p[3], 8u, 0xffu);
    dst_p->earth_accel_y = (int16_t)earth_accel_y;
    earth_accel_z = unpack_right_shift_u16(src_p[4], 0u, 0xffu);
    earth_accel_z |= unpack_left_shift_u16(src_p[5], 8u, 0xffu);
    dst_p->earth_accel_z = (int16_t)earth_accel_z;

    return (0);
}

int feb_can_fusion_earth_accel_data_init(struct feb_can_fusion_earth_accel_data_t *msg_p)
{
    if (msg_p == NULL) return -1;

    memset(msg_p, 0, sizeof(struct feb_can_fusion_earth_accel_data_t));

    return 0;
}

int16_t feb_can_fusion_earth_accel_data_earth_accel_x_encode(double value)
{
    return (int16_t)(value);
}

double feb_can_fusion_earth_accel_data_earth_accel_x_decode(int16_t value)
{
    return ((double)value);
}

bool feb_can_fusion_earth_accel_data_earth_accel_x_is_in_range(int16_t value)
{
    (void)value;

    return (true);
}

int16_t feb_can_fusion_earth_accel_data_earth_accel_y_encode(double value)
{
    return (int16_t)(value);
}

double feb_can_fusion_earth_accel_data_earth_accel_y_decode(int16_t value)
{
    return ((double)value);
}

bool feb_can_fusion_earth_accel_data_earth_accel_y_is_in_range(int16_t value)
{
    (void)value;

    return (true);
}

int16_t feb_can_fusion_earth_accel_data_earth_accel_z_encode(double value)
{
    return (int16_t)(value);
}

double feb_can_fusion_earth_accel_data_earth_accel_z_decode(int16_t value)
{
    return ((double)value);
}

bool feb_can_fusion_earth_accel_data_earth_accel_z_is_in_range(int16_t value)
{
    (void)value;

    return (true);
}

int feb_can_fusion_status_data_pack(
    uint8_t *dst_p,
    const struct feb_can_fusion_status_data_t *src_p,
    size_t size)
{
    if (size < 3u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 3);

    dst_p[0] |= pack_left_shift_u8(src_p->flags, 0u, 0xffu);
    dst_p[1] |= pack_left_shift_u8(src_p->accel_error, 0u, 0xffu);
    dst_p[2] |= pack_left_shift_u8(src_p->mag_error, 0u, 0xffu);

    return (3);
}

int feb_can_fusion_status_data_unpack(
    struct feb_can_fusion_status_data_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    if (size < 3u) {
        return (-EINVAL);
    }

    dst_p->flags = unpack_right_shift_u8(src_p[0], 0u, 0xffu);
    dst_p->accel_error = unpack_right_shift_u8(src_p[1], 0u, 0xffu);
    dst_p->mag_error = unpack_right_shift_u8(src_p[2], 0u, 0xffu);

    return (0);
}

int feb_can_fusion_status_data_init(struct feb_can_fusion_status_data_t *msg_p)
{
    if (msg_p == NULL) return -1;

    memset(msg_p, 0, sizeof(struct feb_can_fusion_status_data_t));

    return 0;
}

uint8_t feb_can_fusion_status_data_flags_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_fusion_status_data_flags_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_fusion_status_data_flags_is_in_range(uint8_t value)
{
    (void)value;

    return (true);
}

uint8_t feb_can_fusion_status_data_accel_error_encode(double value)
{
    return (uint8_t)(value / 0.1);
}

double feb_can_fusion_status_data_accel_error_decode(uint8_t value)
{
    return ((double)value * 0.1);
}

bool feb_can_fusion_status_data_accel_error_is_in_range(uint8_t value)
{
    (void)value;

    return (true);
}

uint8_t feb_can_fusion_status_data_mag_error_encode(double value)
{
    return (uint8_t)(value / 0.1);
}

double feb_can_fusion_status_data_mag_error_decode(uint8_t value)
{
    return ((double)value * 0.1);
}

bool feb_can_fusion_status_data_mag_error_is_in_range(uint8_t value)
{
    (void)value;

    return (true);
}

int feb_can_sensor_temps_data_pack(
    uint8_t *dst_p,
    const struct feb_can_sensor_temps_data_t *src_p,
    size_t size)
{
    uint16_t imu_temp;
    uint16_t mag_temp;

    if (size < 4u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 4);

    imu_temp = (uint16_t)src_p->imu_temp;
    dst_p[0] |= pack_left_shift_u16(imu_temp, 0u, 0xffu);
    dst_p[1] |= pack_right_shift_u16(imu_temp, 8u, 0xffu);
    mag_temp = (uint16_t)src_p->mag_temp;
    dst_p[2] |= pack_left_shift_u16(mag_temp, 0u, 0xffu);
    dst_p[3] |= pack_right_shift_u16(mag_temp, 8u, 0xffu);

    return (4);
}

int feb_can_sensor_temps_data_unpack(
    struct feb_can_sensor_temps_data_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    uint16_t imu_temp;
    uint16_t mag_temp;

    if (size < 4u) {
        return (-EINVAL);
    }

    imu_temp = unpack_right_shift_u16(src_p[0], 0u, 0xffu);
    imu_temp |= unpack_left_shift_u16(src_p[1], 8u, 0xffu);
    dst_p->imu_temp = (int16_t)imu_temp;
    mag_temp = unpack_right_shift_u16(src_p[2], 0u, 0xffu);
    mag_temp |= unpack_left_shift_u16(src_p[3], 8u, 0xffu);
    dst_p->mag_temp = (int16_t)mag_temp;

    return (0);
}

int feb_can_sensor_temps_data_init(struct feb_can_sensor_temps_data_t *msg_p)
{
    if (msg_p == NULL) return -1;

    memset(msg_p, 0, sizeof(struct feb_can_sensor_temps_data_t));

    return 0;
}

int16_t feb_can_sensor_temps_data_imu_temp_encode(double value)
{
    return (int16_t)(value / 0.01);
}

double feb_can_sensor_temps_data_imu_temp_decode(int16_t value)
{
    return ((double)value * 0.01);
}

bool feb_can_sensor_temps_data_imu_temp_is_in_range(int16_t value)
{
    (void)value;

    return (true);
}

int16_t feb_can_sensor_temps_data_mag_temp_encode(double value)
{
    return (int16_t)(value / 0.01);
}

double feb_can_sensor_temps_data_mag_temp_decode(int16_t value)
{
    return ((double)value * 0.01);
}

bool feb_can_sensor_temps_data_mag_temp_is_in_range(int16_t value)
{
    (void)value;

    return (true);
}

int feb_can_sensor_temps_data_rear_pack(
    uint8_t *dst_p,
    const struct feb_can_sensor_temps_data_rear_t *src_p,
    size_t size)
{
    uint16_t imu_temp;
    uint16_t mag_temp;

    if (size < 4u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 4);

    imu_temp = (uint16_t)src_p->imu_temp;
    dst_p[0] |= pack_left_shift_u16(imu_temp, 0u, 0xffu);
    dst_p[1] |= pack_right_shift_u16(imu_temp, 8u, 0xffu);
    mag_temp = (uint16_t)src_p->mag_temp;
    dst_p[2] |= pack_left_shift_u16(mag_temp, 0u, 0xffu);
    dst_p[3] |= pack_right_shift_u16(mag_temp, 8u, 0xffu);

    return (4);
}

int feb_can_sensor_temps_data_rear_unpack(
    struct feb_can_sensor_temps_data_rear_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    uint16_t imu_temp;
    uint16_t mag_temp;

    if (size < 4u) {
        return (-EINVAL);
    }

    imu_temp = unpack_right_shift_u16(src_p[0], 0u, 0xffu);
    imu_temp |= unpack_left_shift_u16(src_p[1], 8u, 0xffu);
    dst_p->imu_temp = (int16_t)imu_temp;
    mag_temp = unpack_right_shift_u16(src_p[2], 0u, 0xffu);
    mag_temp |= unpack_left_shift_u16(src_p[3], 8u, 0xffu);
    dst_p->mag_temp = (int16_t)mag_temp;

    return (0);
}

int feb_can_sensor_temps_data_rear_init(struct feb_can_sensor_temps_data_rear_t *msg_p)
{
    if (msg_p == NULL) return -1;

    memset(msg_p, 0, sizeof(struct feb_can_sensor_temps_data_rear_t));

    return 0;
}

int16_t feb_can_sensor_temps_data_rear_imu_temp_encode(double value)
{
    return (int16_t)(value / 0.01);
}

double feb_can_sensor_temps_data_rear_imu_temp_decode(int16_t value)
{
    return ((double)value * 0.01);
}

bool feb_can_sensor_temps_data_rear_imu_temp_is_in_range(int16_t value)
{
    (void)value;

    return (true);
}

int16_t feb_can_sensor_temps_data_rear_mag_temp_encode(double value)
{
    return (int16_t)(value / 0.01);
}

double feb_can_sensor_temps_data_rear_mag_temp_decode(int16_t value)
{
    return ((double)value * 0.01);
}

bool feb_can_sensor_temps_data_rear_mag_temp_is_in_range(int16_t value)
{
    (void)value;

    return (true);
}

int feb_can_steer_angle_data_pack(
    uint8_t *dst_p,
    const struct feb_can_steer_angle_data_t *src_p,
    size_t size)
{
    if (size < 5u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 5);

    dst_p[0] |= pack_left_shift_u16(src_p->angle, 0u, 0xffu);
    dst_p[1] |= pack_right_shift_u16(src_p->angle, 8u, 0xffu);
    dst_p[2] |= pack_left_shift_u16(src_p->raw_angle, 0u, 0xffu);
    dst_p[3] |= pack_right_shift_u16(src_p->raw_angle, 8u, 0xffu);
    dst_p[4] |= pack_left_shift_u8(src_p->agc, 0u, 0xffu);

    return (5);
}

int feb_can_steer_angle_data_unpack(
    struct feb_can_steer_angle_data_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    if (size < 5u) {
        return (-EINVAL);
    }

    dst_p->angle = unpack_right_shift_u16(src_p[0], 0u, 0xffu);
    dst_p->angle |= unpack_left_shift_u16(src_p[1], 8u, 0xffu);
    dst_p->raw_angle = unpack_right_shift_u16(src_p[2], 0u, 0xffu);
    dst_p->raw_angle |= unpack_left_shift_u16(src_p[3], 8u, 0xffu);
    dst_p->agc = unpack_right_shift_u8(src_p[4], 0u, 0xffu);

    return (0);
}

int feb_can_steer_angle_data_init(struct feb_can_steer_angle_data_t *msg_p)
{
    if (msg_p == NULL) return -1;

    memset(msg_p, 0, sizeof(struct feb_can_steer_angle_data_t));

    return 0;
}

uint16_t feb_can_steer_angle_data_angle_encode(double value)
{
    return (uint16_t)(value);
}

double feb_can_steer_angle_data_angle_decode(uint16_t value)
{
    return ((double)value);
}

bool feb_can_steer_angle_data_angle_is_in_range(uint16_t value)
{
    (void)value;

    return (true);
}

uint16_t feb_can_steer_angle_data_raw_angle_encode(double value)
{
    return (uint16_t)(value);
}

double feb_can_steer_angle_data_raw_angle_decode(uint16_t value)
{
    return ((double)value);
}

bool feb_can_steer_angle_data_raw_angle_is_in_range(uint16_t value)
{
    (void)value;

    return (true);
}

uint8_t feb_can_steer_angle_data_agc_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_steer_angle_data_agc_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_steer_angle_data_agc_is_in_range(uint8_t value)
{
    (void)value;

    return (true);
}

int feb_can_steer_status_data_pack(
    uint8_t *dst_p,
    const struct feb_can_steer_status_data_t *src_p,
    size_t size)
{
    if (size < 3u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 3);

    dst_p[0] |= pack_left_shift_u8(src_p->status, 0u, 0xffu);
    dst_p[1] |= pack_left_shift_u16(src_p->magnitude, 0u, 0xffu);
    dst_p[2] |= pack_right_shift_u16(src_p->magnitude, 8u, 0xffu);

    return (3);
}

int feb_can_steer_status_data_unpack(
    struct feb_can_steer_status_data_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    if (size < 3u) {
        return (-EINVAL);
    }

    dst_p->status = unpack_right_shift_u8(src_p[0], 0u, 0xffu);
    dst_p->magnitude = unpack_right_shift_u16(src_p[1], 0u, 0xffu);
    dst_p->magnitude |= unpack_left_shift_u16(src_p[2], 8u, 0xffu);

    return (0);
}

int feb_can_steer_status_data_init(struct feb_can_steer_status_data_t *msg_p)
{
    if (msg_p == NULL) return -1;

    memset(msg_p, 0, sizeof(struct feb_can_steer_status_data_t));

    return 0;
}

uint8_t feb_can_steer_status_data_status_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_steer_status_data_status_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_steer_status_data_status_is_in_range(uint8_t value)
{
    (void)value;

    return (true);
}

uint16_t feb_can_steer_status_data_magnitude_encode(double value)
{
    return (uint16_t)(value);
}

double feb_can_steer_status_data_magnitude_decode(uint16_t value)
{
    return ((double)value);
}

bool feb_can_steer_status_data_magnitude_is_in_range(uint16_t value)
{
    (void)value;

    return (true);
}

int feb_can_gps_pos_data_rear_pack(
    uint8_t *dst_p,
    const struct feb_can_gps_pos_data_rear_t *src_p,
    size_t size)
{
    uint32_t latitude;
    uint32_t longitude;

    if (size < 8u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 8);

    latitude = (uint32_t)src_p->latitude;
    dst_p[0] |= pack_left_shift_u32(latitude, 0u, 0xffu);
    dst_p[1] |= pack_right_shift_u32(latitude, 8u, 0xffu);
    dst_p[2] |= pack_right_shift_u32(latitude, 16u, 0xffu);
    dst_p[3] |= pack_right_shift_u32(latitude, 24u, 0xffu);
    longitude = (uint32_t)src_p->longitude;
    dst_p[4] |= pack_left_shift_u32(longitude, 0u, 0xffu);
    dst_p[5] |= pack_right_shift_u32(longitude, 8u, 0xffu);
    dst_p[6] |= pack_right_shift_u32(longitude, 16u, 0xffu);
    dst_p[7] |= pack_right_shift_u32(longitude, 24u, 0xffu);

    return (8);
}

int feb_can_gps_pos_data_rear_unpack(
    struct feb_can_gps_pos_data_rear_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    uint32_t latitude;
    uint32_t longitude;

    if (size < 8u) {
        return (-EINVAL);
    }

    latitude = unpack_right_shift_u32(src_p[0], 0u, 0xffu);
    latitude |= unpack_left_shift_u32(src_p[1], 8u, 0xffu);
    latitude |= unpack_left_shift_u32(src_p[2], 16u, 0xffu);
    latitude |= unpack_left_shift_u32(src_p[3], 24u, 0xffu);
    dst_p->latitude = (int32_t)latitude;
    longitude = unpack_right_shift_u32(src_p[4], 0u, 0xffu);
    longitude |= unpack_left_shift_u32(src_p[5], 8u, 0xffu);
    longitude |= unpack_left_shift_u32(src_p[6], 16u, 0xffu);
    longitude |= unpack_left_shift_u32(src_p[7], 24u, 0xffu);
    dst_p->longitude = (int32_t)longitude;

    return (0);
}

int feb_can_gps_pos_data_rear_init(struct feb_can_gps_pos_data_rear_t *msg_p)
{
    if (msg_p == NULL) return -1;

    memset(msg_p, 0, sizeof(struct feb_can_gps_pos_data_rear_t));

    return 0;
}

int32_t feb_can_gps_pos_data_rear_latitude_encode(double value)
{
    return (int32_t)(value / 1e-07);
}

double feb_can_gps_pos_data_rear_latitude_decode(int32_t value)
{
    return ((double)value * 1e-07);
}

bool feb_can_gps_pos_data_rear_latitude_is_in_range(int32_t value)
{
    (void)value;

    return (true);
}

int32_t feb_can_gps_pos_data_rear_longitude_encode(double value)
{
    return (int32_t)(value / 1e-07);
}

double feb_can_gps_pos_data_rear_longitude_decode(int32_t value)
{
    return ((double)value * 1e-07);
}

bool feb_can_gps_pos_data_rear_longitude_is_in_range(int32_t value)
{
    (void)value;

    return (true);
}

int feb_can_gps_altitude_data_rear_pack(
    uint8_t *dst_p,
    const struct feb_can_gps_altitude_data_rear_t *src_p,
    size_t size)
{
    uint32_t altitude;

    if (size < 8u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 8);

    altitude = (uint32_t)src_p->altitude;
    dst_p[0] |= pack_left_shift_u32(altitude, 0u, 0xffu);
    dst_p[1] |= pack_right_shift_u32(altitude, 8u, 0xffu);
    dst_p[2] |= pack_right_shift_u32(altitude, 16u, 0xffu);
    dst_p[3] |= pack_right_shift_u32(altitude, 24u, 0xffu);
    dst_p[4] |= pack_left_shift_u16(src_p->hdop, 0u, 0xffu);
    dst_p[5] |= pack_right_shift_u16(src_p->hdop, 8u, 0xffu);
    dst_p[6] |= pack_left_shift_u16(src_p->vdop, 0u, 0xffu);
    dst_p[7] |= pack_right_shift_u16(src_p->vdop, 8u, 0xffu);

    return (8);
}

int feb_can_gps_altitude_data_rear_unpack(
    struct feb_can_gps_altitude_data_rear_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    uint32_t altitude;

    if (size < 8u) {
        return (-EINVAL);
    }

    altitude = unpack_right_shift_u32(src_p[0], 0u, 0xffu);
    altitude |= unpack_left_shift_u32(src_p[1], 8u, 0xffu);
    altitude |= unpack_left_shift_u32(src_p[2], 16u, 0xffu);
    altitude |= unpack_left_shift_u32(src_p[3], 24u, 0xffu);
    dst_p->altitude = (int32_t)altitude;
    dst_p->hdop = unpack_right_shift_u16(src_p[4], 0u, 0xffu);
    dst_p->hdop |= unpack_left_shift_u16(src_p[5], 8u, 0xffu);
    dst_p->vdop = unpack_right_shift_u16(src_p[6], 0u, 0xffu);
    dst_p->vdop |= unpack_left_shift_u16(src_p[7], 8u, 0xffu);

    return (0);
}

int feb_can_gps_altitude_data_rear_init(struct feb_can_gps_altitude_data_rear_t *msg_p)
{
    if (msg_p == NULL) return -1;

    memset(msg_p, 0, sizeof(struct feb_can_gps_altitude_data_rear_t));

    return 0;
}

int32_t feb_can_gps_altitude_data_rear_altitude_encode(double value)
{
    return (int32_t)(value / 0.01);
}

double feb_can_gps_altitude_data_rear_altitude_decode(int32_t value)
{
    return ((double)value * 0.01);
}

bool feb_can_gps_altitude_data_rear_altitude_is_in_range(int32_t value)
{
    (void)value;

    return (true);
}

uint16_t feb_can_gps_altitude_data_rear_hdop_encode(double value)
{
    return (uint16_t)(value / 0.01);
}

double feb_can_gps_altitude_data_rear_hdop_decode(uint16_t value)
{
    return ((double)value * 0.01);
}

bool feb_can_gps_altitude_data_rear_hdop_is_in_range(uint16_t value)
{
    (void)value;

    return (true);
}

uint16_t feb_can_gps_altitude_data_rear_vdop_encode(double value)
{
    return (uint16_t)(value / 0.01);
}

double feb_can_gps_altitude_data_rear_vdop_decode(uint16_t value)
{
    return ((double)value * 0.01);
}

bool feb_can_gps_altitude_data_rear_vdop_is_in_range(uint16_t value)
{
    (void)value;

    return (true);
}

int feb_can_gps_motion_data_rear_pack(
    uint8_t *dst_p,
    const struct feb_can_gps_motion_data_rear_t *src_p,
    size_t size)
{
    if (size < 4u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 4);

    dst_p[0] |= pack_left_shift_u16(src_p->speed, 0u, 0xffu);
    dst_p[1] |= pack_right_shift_u16(src_p->speed, 8u, 0xffu);
    dst_p[2] |= pack_left_shift_u16(src_p->course, 0u, 0xffu);
    dst_p[3] |= pack_right_shift_u16(src_p->course, 8u, 0xffu);

    return (4);
}

int feb_can_gps_motion_data_rear_unpack(
    struct feb_can_gps_motion_data_rear_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    if (size < 4u) {
        return (-EINVAL);
    }

    dst_p->speed = unpack_right_shift_u16(src_p[0], 0u, 0xffu);
    dst_p->speed |= unpack_left_shift_u16(src_p[1], 8u, 0xffu);
    dst_p->course = unpack_right_shift_u16(src_p[2], 0u, 0xffu);
    dst_p->course |= unpack_left_shift_u16(src_p[3], 8u, 0xffu);

    return (0);
}

int feb_can_gps_motion_data_rear_init(struct feb_can_gps_motion_data_rear_t *msg_p)
{
    if (msg_p == NULL) return -1;

    memset(msg_p, 0, sizeof(struct feb_can_gps_motion_data_rear_t));

    return 0;
}

uint16_t feb_can_gps_motion_data_rear_speed_encode(double value)
{
    return (uint16_t)(value / 0.01);
}

double feb_can_gps_motion_data_rear_speed_decode(uint16_t value)
{
    return ((double)value * 0.01);
}

bool feb_can_gps_motion_data_rear_speed_is_in_range(uint16_t value)
{
    (void)value;

    return (true);
}

uint16_t feb_can_gps_motion_data_rear_course_encode(double value)
{
    return (uint16_t)(value / 0.01);
}

double feb_can_gps_motion_data_rear_course_decode(uint16_t value)
{
    return ((double)value * 0.01);
}

bool feb_can_gps_motion_data_rear_course_is_in_range(uint16_t value)
{
    (void)value;

    return (true);
}

int feb_can_gps_time_data_rear_pack(
    uint8_t *dst_p,
    const struct feb_can_gps_time_data_rear_t *src_p,
    size_t size)
{
    uint8_t hours;
    uint8_t minutes;
    uint8_t seconds;

    if (size < 3u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 3);

    hours = (uint8_t)src_p->hours;
    dst_p[0] |= pack_left_shift_u8(hours, 0u, 0xffu);
    minutes = (uint8_t)src_p->minutes;
    dst_p[1] |= pack_left_shift_u8(minutes, 0u, 0xffu);
    seconds = (uint8_t)src_p->seconds;
    dst_p[2] |= pack_left_shift_u8(seconds, 0u, 0xffu);

    return (3);
}

int feb_can_gps_time_data_rear_unpack(
    struct feb_can_gps_time_data_rear_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    uint8_t hours;
    uint8_t minutes;
    uint8_t seconds;

    if (size < 3u) {
        return (-EINVAL);
    }

    hours = unpack_right_shift_u8(src_p[0], 0u, 0xffu);
    dst_p->hours = (int8_t)hours;
    minutes = unpack_right_shift_u8(src_p[1], 0u, 0xffu);
    dst_p->minutes = (int8_t)minutes;
    seconds = unpack_right_shift_u8(src_p[2], 0u, 0xffu);
    dst_p->seconds = (int8_t)seconds;

    return (0);
}

int feb_can_gps_time_data_rear_init(struct feb_can_gps_time_data_rear_t *msg_p)
{
    if (msg_p == NULL) return -1;

    memset(msg_p, 0, sizeof(struct feb_can_gps_time_data_rear_t));

    return 0;
}

int8_t feb_can_gps_time_data_rear_hours_encode(double value)
{
    return (int8_t)(value);
}

double feb_can_gps_time_data_rear_hours_decode(int8_t value)
{
    return ((double)value);
}

bool feb_can_gps_time_data_rear_hours_is_in_range(int8_t value)
{
    (void)value;

    return (true);
}

int8_t feb_can_gps_time_data_rear_minutes_encode(double value)
{
    return (int8_t)(value);
}

double feb_can_gps_time_data_rear_minutes_decode(int8_t value)
{
    return ((double)value);
}

bool feb_can_gps_time_data_rear_minutes_is_in_range(int8_t value)
{
    (void)value;

    return (true);
}

int8_t feb_can_gps_time_data_rear_seconds_encode(double value)
{
    return (int8_t)(value);
}

double feb_can_gps_time_data_rear_seconds_decode(int8_t value)
{
    return ((double)value);
}

bool feb_can_gps_time_data_rear_seconds_is_in_range(int8_t value)
{
    (void)value;

    return (true);
}

int feb_can_gps_date_data_rear_pack(
    uint8_t *dst_p,
    const struct feb_can_gps_date_data_rear_t *src_p,
    size_t size)
{
    uint8_t day;
    uint8_t month;
    uint8_t year;

    if (size < 3u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 3);

    day = (uint8_t)src_p->day;
    dst_p[0] |= pack_left_shift_u8(day, 0u, 0xffu);
    month = (uint8_t)src_p->month;
    dst_p[1] |= pack_left_shift_u8(month, 0u, 0xffu);
    year = (uint8_t)src_p->year;
    dst_p[2] |= pack_left_shift_u8(year, 0u, 0xffu);

    return (3);
}

int feb_can_gps_date_data_rear_unpack(
    struct feb_can_gps_date_data_rear_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    uint8_t day;
    uint8_t month;
    uint8_t year;

    if (size < 3u) {
        return (-EINVAL);
    }

    day = unpack_right_shift_u8(src_p[0], 0u, 0xffu);
    dst_p->day = (int8_t)day;
    month = unpack_right_shift_u8(src_p[1], 0u, 0xffu);
    dst_p->month = (int8_t)month;
    year = unpack_right_shift_u8(src_p[2], 0u, 0xffu);
    dst_p->year = (int8_t)year;

    return (0);
}

int feb_can_gps_date_data_rear_init(struct feb_can_gps_date_data_rear_t *msg_p)
{
    if (msg_p == NULL) return -1;

    memset(msg_p, 0, sizeof(struct feb_can_gps_date_data_rear_t));

    return 0;
}

int8_t feb_can_gps_date_data_rear_day_encode(double value)
{
    return (int8_t)(value);
}

double feb_can_gps_date_data_rear_day_decode(int8_t value)
{
    return ((double)value);
}

bool feb_can_gps_date_data_rear_day_is_in_range(int8_t value)
{
    (void)value;

    return (true);
}

int8_t feb_can_gps_date_data_rear_month_encode(double value)
{
    return (int8_t)(value);
}

double feb_can_gps_date_data_rear_month_decode(int8_t value)
{
    return ((double)value);
}

bool feb_can_gps_date_data_rear_month_is_in_range(int8_t value)
{
    (void)value;

    return (true);
}

int8_t feb_can_gps_date_data_rear_year_encode(double value)
{
    return (int8_t)(value);
}

double feb_can_gps_date_data_rear_year_decode(int8_t value)
{
    return ((double)value);
}

bool feb_can_gps_date_data_rear_year_is_in_range(int8_t value)
{
    (void)value;

    return (true);
}

int feb_can_gps_status_data_rear_pack(
    uint8_t *dst_p,
    const struct feb_can_gps_status_data_rear_t *src_p,
    size_t size)
{
    if (size < 8u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 8);

    dst_p[0] |= pack_left_shift_u8(src_p->fix_type, 0u, 0xffu);
    dst_p[1] |= pack_left_shift_u8(src_p->fix_mode, 0u, 0xffu);
    dst_p[2] |= pack_left_shift_u8(src_p->sats_in_use, 0u, 0xffu);
    dst_p[3] |= pack_left_shift_u8(src_p->sats_in_view, 0u, 0xffu);
    dst_p[4] |= pack_left_shift_u8(src_p->valid, 0u, 0xffu);
    dst_p[5] |= pack_left_shift_u8(src_p->has_fix, 0u, 0xffu);
    dst_p[6] |= pack_left_shift_u16(src_p->pdop, 0u, 0xffu);
    dst_p[7] |= pack_right_shift_u16(src_p->pdop, 8u, 0xffu);

    return (8);
}

int feb_can_gps_status_data_rear_unpack(
    struct feb_can_gps_status_data_rear_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    if (size < 8u) {
        return (-EINVAL);
    }

    dst_p->fix_type = unpack_right_shift_u8(src_p[0], 0u, 0xffu);
    dst_p->fix_mode = unpack_right_shift_u8(src_p[1], 0u, 0xffu);
    dst_p->sats_in_use = unpack_right_shift_u8(src_p[2], 0u, 0xffu);
    dst_p->sats_in_view = unpack_right_shift_u8(src_p[3], 0u, 0xffu);
    dst_p->valid = unpack_right_shift_u8(src_p[4], 0u, 0xffu);
    dst_p->has_fix = unpack_right_shift_u8(src_p[5], 0u, 0xffu);
    dst_p->pdop = unpack_right_shift_u16(src_p[6], 0u, 0xffu);
    dst_p->pdop |= unpack_left_shift_u16(src_p[7], 8u, 0xffu);

    return (0);
}

int feb_can_gps_status_data_rear_init(struct feb_can_gps_status_data_rear_t *msg_p)
{
    if (msg_p == NULL) return -1;

    memset(msg_p, 0, sizeof(struct feb_can_gps_status_data_rear_t));

    return 0;
}

uint8_t feb_can_gps_status_data_rear_fix_type_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_gps_status_data_rear_fix_type_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_gps_status_data_rear_fix_type_is_in_range(uint8_t value)
{
    (void)value;

    return (true);
}

uint8_t feb_can_gps_status_data_rear_fix_mode_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_gps_status_data_rear_fix_mode_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_gps_status_data_rear_fix_mode_is_in_range(uint8_t value)
{
    (void)value;

    return (true);
}

uint8_t feb_can_gps_status_data_rear_sats_in_use_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_gps_status_data_rear_sats_in_use_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_gps_status_data_rear_sats_in_use_is_in_range(uint8_t value)
{
    (void)value;

    return (true);
}

uint8_t feb_can_gps_status_data_rear_sats_in_view_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_gps_status_data_rear_sats_in_view_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_gps_status_data_rear_sats_in_view_is_in_range(uint8_t value)
{
    (void)value;

    return (true);
}

uint8_t feb_can_gps_status_data_rear_valid_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_gps_status_data_rear_valid_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_gps_status_data_rear_valid_is_in_range(uint8_t value)
{
    (void)value;

    return (true);
}

uint8_t feb_can_gps_status_data_rear_has_fix_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_gps_status_data_rear_has_fix_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_gps_status_data_rear_has_fix_is_in_range(uint8_t value)
{
    (void)value;

    return (true);
}

uint16_t feb_can_gps_status_data_rear_pdop_encode(double value)
{
    return (uint16_t)(value / 0.01);
}

double feb_can_gps_status_data_rear_pdop_decode(uint16_t value)
{
    return ((double)value * 0.01);
}

bool feb_can_gps_status_data_rear_pdop_is_in_range(uint16_t value)
{
    (void)value;

    return (true);
}

int feb_can_fusion_quaternion_data_rear_pack(
    uint8_t *dst_p,
    const struct feb_can_fusion_quaternion_data_rear_t *src_p,
    size_t size)
{
    uint16_t q_w;
    uint16_t q_x;
    uint16_t q_y;
    uint16_t q_z;

    if (size < 8u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 8);

    q_w = (uint16_t)src_p->q_w;
    dst_p[0] |= pack_left_shift_u16(q_w, 0u, 0xffu);
    dst_p[1] |= pack_right_shift_u16(q_w, 8u, 0xffu);
    q_x = (uint16_t)src_p->q_x;
    dst_p[2] |= pack_left_shift_u16(q_x, 0u, 0xffu);
    dst_p[3] |= pack_right_shift_u16(q_x, 8u, 0xffu);
    q_y = (uint16_t)src_p->q_y;
    dst_p[4] |= pack_left_shift_u16(q_y, 0u, 0xffu);
    dst_p[5] |= pack_right_shift_u16(q_y, 8u, 0xffu);
    q_z = (uint16_t)src_p->q_z;
    dst_p[6] |= pack_left_shift_u16(q_z, 0u, 0xffu);
    dst_p[7] |= pack_right_shift_u16(q_z, 8u, 0xffu);

    return (8);
}

int feb_can_fusion_quaternion_data_rear_unpack(
    struct feb_can_fusion_quaternion_data_rear_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    uint16_t q_w;
    uint16_t q_x;
    uint16_t q_y;
    uint16_t q_z;

    if (size < 8u) {
        return (-EINVAL);
    }

    q_w = unpack_right_shift_u16(src_p[0], 0u, 0xffu);
    q_w |= unpack_left_shift_u16(src_p[1], 8u, 0xffu);
    dst_p->q_w = (int16_t)q_w;
    q_x = unpack_right_shift_u16(src_p[2], 0u, 0xffu);
    q_x |= unpack_left_shift_u16(src_p[3], 8u, 0xffu);
    dst_p->q_x = (int16_t)q_x;
    q_y = unpack_right_shift_u16(src_p[4], 0u, 0xffu);
    q_y |= unpack_left_shift_u16(src_p[5], 8u, 0xffu);
    dst_p->q_y = (int16_t)q_y;
    q_z = unpack_right_shift_u16(src_p[6], 0u, 0xffu);
    q_z |= unpack_left_shift_u16(src_p[7], 8u, 0xffu);
    dst_p->q_z = (int16_t)q_z;

    return (0);
}

int feb_can_fusion_quaternion_data_rear_init(struct feb_can_fusion_quaternion_data_rear_t *msg_p)
{
    if (msg_p == NULL) return -1;

    memset(msg_p, 0, sizeof(struct feb_can_fusion_quaternion_data_rear_t));

    return 0;
}

int16_t feb_can_fusion_quaternion_data_rear_q_w_encode(double value)
{
    return (int16_t)(value / 3.051850947599719e-05);
}

double feb_can_fusion_quaternion_data_rear_q_w_decode(int16_t value)
{
    return ((double)value * 3.051850947599719e-05);
}

bool feb_can_fusion_quaternion_data_rear_q_w_is_in_range(int16_t value)
{
    (void)value;

    return (true);
}

int16_t feb_can_fusion_quaternion_data_rear_q_x_encode(double value)
{
    return (int16_t)(value / 3.051850947599719e-05);
}

double feb_can_fusion_quaternion_data_rear_q_x_decode(int16_t value)
{
    return ((double)value * 3.051850947599719e-05);
}

bool feb_can_fusion_quaternion_data_rear_q_x_is_in_range(int16_t value)
{
    (void)value;

    return (true);
}

int16_t feb_can_fusion_quaternion_data_rear_q_y_encode(double value)
{
    return (int16_t)(value / 3.051850947599719e-05);
}

double feb_can_fusion_quaternion_data_rear_q_y_decode(int16_t value)
{
    return ((double)value * 3.051850947599719e-05);
}

bool feb_can_fusion_quaternion_data_rear_q_y_is_in_range(int16_t value)
{
    (void)value;

    return (true);
}

int16_t feb_can_fusion_quaternion_data_rear_q_z_encode(double value)
{
    return (int16_t)(value / 3.051850947599719e-05);
}

double feb_can_fusion_quaternion_data_rear_q_z_decode(int16_t value)
{
    return ((double)value * 3.051850947599719e-05);
}

bool feb_can_fusion_quaternion_data_rear_q_z_is_in_range(int16_t value)
{
    (void)value;

    return (true);
}

int feb_can_fusion_euler_data_rear_pack(
    uint8_t *dst_p,
    const struct feb_can_fusion_euler_data_rear_t *src_p,
    size_t size)
{
    uint16_t pitch;
    uint16_t roll;
    uint16_t yaw;

    if (size < 6u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 6);

    roll = (uint16_t)src_p->roll;
    dst_p[0] |= pack_left_shift_u16(roll, 0u, 0xffu);
    dst_p[1] |= pack_right_shift_u16(roll, 8u, 0xffu);
    pitch = (uint16_t)src_p->pitch;
    dst_p[2] |= pack_left_shift_u16(pitch, 0u, 0xffu);
    dst_p[3] |= pack_right_shift_u16(pitch, 8u, 0xffu);
    yaw = (uint16_t)src_p->yaw;
    dst_p[4] |= pack_left_shift_u16(yaw, 0u, 0xffu);
    dst_p[5] |= pack_right_shift_u16(yaw, 8u, 0xffu);

    return (6);
}

int feb_can_fusion_euler_data_rear_unpack(
    struct feb_can_fusion_euler_data_rear_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    uint16_t pitch;
    uint16_t roll;
    uint16_t yaw;

    if (size < 6u) {
        return (-EINVAL);
    }

    roll = unpack_right_shift_u16(src_p[0], 0u, 0xffu);
    roll |= unpack_left_shift_u16(src_p[1], 8u, 0xffu);
    dst_p->roll = (int16_t)roll;
    pitch = unpack_right_shift_u16(src_p[2], 0u, 0xffu);
    pitch |= unpack_left_shift_u16(src_p[3], 8u, 0xffu);
    dst_p->pitch = (int16_t)pitch;
    yaw = unpack_right_shift_u16(src_p[4], 0u, 0xffu);
    yaw |= unpack_left_shift_u16(src_p[5], 8u, 0xffu);
    dst_p->yaw = (int16_t)yaw;

    return (0);
}

int feb_can_fusion_euler_data_rear_init(struct feb_can_fusion_euler_data_rear_t *msg_p)
{
    if (msg_p == NULL) return -1;

    memset(msg_p, 0, sizeof(struct feb_can_fusion_euler_data_rear_t));

    return 0;
}

int16_t feb_can_fusion_euler_data_rear_roll_encode(double value)
{
    return (int16_t)(value / 0.01);
}

double feb_can_fusion_euler_data_rear_roll_decode(int16_t value)
{
    return ((double)value * 0.01);
}

bool feb_can_fusion_euler_data_rear_roll_is_in_range(int16_t value)
{
    (void)value;

    return (true);
}

int16_t feb_can_fusion_euler_data_rear_pitch_encode(double value)
{
    return (int16_t)(value / 0.01);
}

double feb_can_fusion_euler_data_rear_pitch_decode(int16_t value)
{
    return ((double)value * 0.01);
}

bool feb_can_fusion_euler_data_rear_pitch_is_in_range(int16_t value)
{
    (void)value;

    return (true);
}

int16_t feb_can_fusion_euler_data_rear_yaw_encode(double value)
{
    return (int16_t)(value / 0.01);
}

double feb_can_fusion_euler_data_rear_yaw_decode(int16_t value)
{
    return ((double)value * 0.01);
}

bool feb_can_fusion_euler_data_rear_yaw_is_in_range(int16_t value)
{
    (void)value;

    return (true);
}

int feb_can_fusion_linear_accel_data_rear_pack(
    uint8_t *dst_p,
    const struct feb_can_fusion_linear_accel_data_rear_t *src_p,
    size_t size)
{
    uint16_t lin_accel_x;
    uint16_t lin_accel_y;
    uint16_t lin_accel_z;

    if (size < 6u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 6);

    lin_accel_x = (uint16_t)src_p->lin_accel_x;
    dst_p[0] |= pack_left_shift_u16(lin_accel_x, 0u, 0xffu);
    dst_p[1] |= pack_right_shift_u16(lin_accel_x, 8u, 0xffu);
    lin_accel_y = (uint16_t)src_p->lin_accel_y;
    dst_p[2] |= pack_left_shift_u16(lin_accel_y, 0u, 0xffu);
    dst_p[3] |= pack_right_shift_u16(lin_accel_y, 8u, 0xffu);
    lin_accel_z = (uint16_t)src_p->lin_accel_z;
    dst_p[4] |= pack_left_shift_u16(lin_accel_z, 0u, 0xffu);
    dst_p[5] |= pack_right_shift_u16(lin_accel_z, 8u, 0xffu);

    return (6);
}

int feb_can_fusion_linear_accel_data_rear_unpack(
    struct feb_can_fusion_linear_accel_data_rear_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    uint16_t lin_accel_x;
    uint16_t lin_accel_y;
    uint16_t lin_accel_z;

    if (size < 6u) {
        return (-EINVAL);
    }

    lin_accel_x = unpack_right_shift_u16(src_p[0], 0u, 0xffu);
    lin_accel_x |= unpack_left_shift_u16(src_p[1], 8u, 0xffu);
    dst_p->lin_accel_x = (int16_t)lin_accel_x;
    lin_accel_y = unpack_right_shift_u16(src_p[2], 0u, 0xffu);
    lin_accel_y |= unpack_left_shift_u16(src_p[3], 8u, 0xffu);
    dst_p->lin_accel_y = (int16_t)lin_accel_y;
    lin_accel_z = unpack_right_shift_u16(src_p[4], 0u, 0xffu);
    lin_accel_z |= unpack_left_shift_u16(src_p[5], 8u, 0xffu);
    dst_p->lin_accel_z = (int16_t)lin_accel_z;

    return (0);
}

int feb_can_fusion_linear_accel_data_rear_init(struct feb_can_fusion_linear_accel_data_rear_t *msg_p)
{
    if (msg_p == NULL) return -1;

    memset(msg_p, 0, sizeof(struct feb_can_fusion_linear_accel_data_rear_t));

    return 0;
}

int16_t feb_can_fusion_linear_accel_data_rear_lin_accel_x_encode(double value)
{
    return (int16_t)(value);
}

double feb_can_fusion_linear_accel_data_rear_lin_accel_x_decode(int16_t value)
{
    return ((double)value);
}

bool feb_can_fusion_linear_accel_data_rear_lin_accel_x_is_in_range(int16_t value)
{
    (void)value;

    return (true);
}

int16_t feb_can_fusion_linear_accel_data_rear_lin_accel_y_encode(double value)
{
    return (int16_t)(value);
}

double feb_can_fusion_linear_accel_data_rear_lin_accel_y_decode(int16_t value)
{
    return ((double)value);
}

bool feb_can_fusion_linear_accel_data_rear_lin_accel_y_is_in_range(int16_t value)
{
    (void)value;

    return (true);
}

int16_t feb_can_fusion_linear_accel_data_rear_lin_accel_z_encode(double value)
{
    return (int16_t)(value);
}

double feb_can_fusion_linear_accel_data_rear_lin_accel_z_decode(int16_t value)
{
    return ((double)value);
}

bool feb_can_fusion_linear_accel_data_rear_lin_accel_z_is_in_range(int16_t value)
{
    (void)value;

    return (true);
}

int feb_can_fusion_earth_accel_data_rear_pack(
    uint8_t *dst_p,
    const struct feb_can_fusion_earth_accel_data_rear_t *src_p,
    size_t size)
{
    uint16_t earth_accel_x;
    uint16_t earth_accel_y;
    uint16_t earth_accel_z;

    if (size < 6u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 6);

    earth_accel_x = (uint16_t)src_p->earth_accel_x;
    dst_p[0] |= pack_left_shift_u16(earth_accel_x, 0u, 0xffu);
    dst_p[1] |= pack_right_shift_u16(earth_accel_x, 8u, 0xffu);
    earth_accel_y = (uint16_t)src_p->earth_accel_y;
    dst_p[2] |= pack_left_shift_u16(earth_accel_y, 0u, 0xffu);
    dst_p[3] |= pack_right_shift_u16(earth_accel_y, 8u, 0xffu);
    earth_accel_z = (uint16_t)src_p->earth_accel_z;
    dst_p[4] |= pack_left_shift_u16(earth_accel_z, 0u, 0xffu);
    dst_p[5] |= pack_right_shift_u16(earth_accel_z, 8u, 0xffu);

    return (6);
}

int feb_can_fusion_earth_accel_data_rear_unpack(
    struct feb_can_fusion_earth_accel_data_rear_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    uint16_t earth_accel_x;
    uint16_t earth_accel_y;
    uint16_t earth_accel_z;

    if (size < 6u) {
        return (-EINVAL);
    }

    earth_accel_x = unpack_right_shift_u16(src_p[0], 0u, 0xffu);
    earth_accel_x |= unpack_left_shift_u16(src_p[1], 8u, 0xffu);
    dst_p->earth_accel_x = (int16_t)earth_accel_x;
    earth_accel_y = unpack_right_shift_u16(src_p[2], 0u, 0xffu);
    earth_accel_y |= unpack_left_shift_u16(src_p[3], 8u, 0xffu);
    dst_p->earth_accel_y = (int16_t)earth_accel_y;
    earth_accel_z = unpack_right_shift_u16(src_p[4], 0u, 0xffu);
    earth_accel_z |= unpack_left_shift_u16(src_p[5], 8u, 0xffu);
    dst_p->earth_accel_z = (int16_t)earth_accel_z;

    return (0);
}

int feb_can_fusion_earth_accel_data_rear_init(struct feb_can_fusion_earth_accel_data_rear_t *msg_p)
{
    if (msg_p == NULL) return -1;

    memset(msg_p, 0, sizeof(struct feb_can_fusion_earth_accel_data_rear_t));

    return 0;
}

int16_t feb_can_fusion_earth_accel_data_rear_earth_accel_x_encode(double value)
{
    return (int16_t)(value);
}

double feb_can_fusion_earth_accel_data_rear_earth_accel_x_decode(int16_t value)
{
    return ((double)value);
}

bool feb_can_fusion_earth_accel_data_rear_earth_accel_x_is_in_range(int16_t value)
{
    (void)value;

    return (true);
}

int16_t feb_can_fusion_earth_accel_data_rear_earth_accel_y_encode(double value)
{
    return (int16_t)(value);
}

double feb_can_fusion_earth_accel_data_rear_earth_accel_y_decode(int16_t value)
{
    return ((double)value);
}

bool feb_can_fusion_earth_accel_data_rear_earth_accel_y_is_in_range(int16_t value)
{
    (void)value;

    return (true);
}

int16_t feb_can_fusion_earth_accel_data_rear_earth_accel_z_encode(double value)
{
    return (int16_t)(value);
}

double feb_can_fusion_earth_accel_data_rear_earth_accel_z_decode(int16_t value)
{
    return ((double)value);
}

bool feb_can_fusion_earth_accel_data_rear_earth_accel_z_is_in_range(int16_t value)
{
    (void)value;

    return (true);
}

int feb_can_fusion_status_data_rear_pack(
    uint8_t *dst_p,
    const struct feb_can_fusion_status_data_rear_t *src_p,
    size_t size)
{
    if (size < 3u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 3);

    dst_p[0] |= pack_left_shift_u8(src_p->flags, 0u, 0xffu);
    dst_p[1] |= pack_left_shift_u8(src_p->accel_error, 0u, 0xffu);
    dst_p[2] |= pack_left_shift_u8(src_p->mag_error, 0u, 0xffu);

    return (3);
}

int feb_can_fusion_status_data_rear_unpack(
    struct feb_can_fusion_status_data_rear_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    if (size < 3u) {
        return (-EINVAL);
    }

    dst_p->flags = unpack_right_shift_u8(src_p[0], 0u, 0xffu);
    dst_p->accel_error = unpack_right_shift_u8(src_p[1], 0u, 0xffu);
    dst_p->mag_error = unpack_right_shift_u8(src_p[2], 0u, 0xffu);

    return (0);
}

int feb_can_fusion_status_data_rear_init(struct feb_can_fusion_status_data_rear_t *msg_p)
{
    if (msg_p == NULL) return -1;

    memset(msg_p, 0, sizeof(struct feb_can_fusion_status_data_rear_t));

    return 0;
}

uint8_t feb_can_fusion_status_data_rear_flags_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_fusion_status_data_rear_flags_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_fusion_status_data_rear_flags_is_in_range(uint8_t value)
{
    (void)value;

    return (true);
}

uint8_t feb_can_fusion_status_data_rear_accel_error_encode(double value)
{
    return (uint8_t)(value / 0.1);
}

double feb_can_fusion_status_data_rear_accel_error_decode(uint8_t value)
{
    return ((double)value * 0.1);
}

bool feb_can_fusion_status_data_rear_accel_error_is_in_range(uint8_t value)
{
    (void)value;

    return (true);
}

uint8_t feb_can_fusion_status_data_rear_mag_error_encode(double value)
{
    return (uint8_t)(value / 0.1);
}

double feb_can_fusion_status_data_rear_mag_error_decode(uint8_t value)
{
    return ((double)value * 0.1);
}

bool feb_can_fusion_status_data_rear_mag_error_is_in_range(uint8_t value)
{
    (void)value;

    return (true);
}

int feb_can_m160_temperature_set_1_pack(
    uint8_t *dst_p,
    const struct feb_can_m160_temperature_set_1_t *src_p,
    size_t size)
{
    uint16_t inv_gate_driver_board;
    uint16_t inv_module_a;
    uint16_t inv_module_b;
    uint16_t inv_module_c;

    if (size < 8u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 8);

    inv_module_a = (uint16_t)src_p->inv_module_a;
    dst_p[0] |= pack_left_shift_u16(inv_module_a, 0u, 0xffu);
    dst_p[1] |= pack_right_shift_u16(inv_module_a, 8u, 0xffu);
    inv_module_b = (uint16_t)src_p->inv_module_b;
    dst_p[2] |= pack_left_shift_u16(inv_module_b, 0u, 0xffu);
    dst_p[3] |= pack_right_shift_u16(inv_module_b, 8u, 0xffu);
    inv_module_c = (uint16_t)src_p->inv_module_c;
    dst_p[4] |= pack_left_shift_u16(inv_module_c, 0u, 0xffu);
    dst_p[5] |= pack_right_shift_u16(inv_module_c, 8u, 0xffu);
    inv_gate_driver_board = (uint16_t)src_p->inv_gate_driver_board;
    dst_p[6] |= pack_left_shift_u16(inv_gate_driver_board, 0u, 0xffu);
    dst_p[7] |= pack_right_shift_u16(inv_gate_driver_board, 8u, 0xffu);

    return (8);
}

int feb_can_m160_temperature_set_1_unpack(
    struct feb_can_m160_temperature_set_1_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    uint16_t inv_gate_driver_board;
    uint16_t inv_module_a;
    uint16_t inv_module_b;
    uint16_t inv_module_c;

    if (size < 8u) {
        return (-EINVAL);
    }

    inv_module_a = unpack_right_shift_u16(src_p[0], 0u, 0xffu);
    inv_module_a |= unpack_left_shift_u16(src_p[1], 8u, 0xffu);
    dst_p->inv_module_a = (int16_t)inv_module_a;
    inv_module_b = unpack_right_shift_u16(src_p[2], 0u, 0xffu);
    inv_module_b |= unpack_left_shift_u16(src_p[3], 8u, 0xffu);
    dst_p->inv_module_b = (int16_t)inv_module_b;
    inv_module_c = unpack_right_shift_u16(src_p[4], 0u, 0xffu);
    inv_module_c |= unpack_left_shift_u16(src_p[5], 8u, 0xffu);
    dst_p->inv_module_c = (int16_t)inv_module_c;
    inv_gate_driver_board = unpack_right_shift_u16(src_p[6], 0u, 0xffu);
    inv_gate_driver_board |= unpack_left_shift_u16(src_p[7], 8u, 0xffu);
    dst_p->inv_gate_driver_board = (int16_t)inv_gate_driver_board;

    return (0);
}

int feb_can_m160_temperature_set_1_init(struct feb_can_m160_temperature_set_1_t *msg_p)
{
    if (msg_p == NULL) return -1;

    memset(msg_p, 0, sizeof(struct feb_can_m160_temperature_set_1_t));

    return 0;
}

int16_t feb_can_m160_temperature_set_1_inv_module_a_encode(double value)
{
    return (int16_t)(value / 0.1);
}

double feb_can_m160_temperature_set_1_inv_module_a_decode(int16_t value)
{
    return ((double)value * 0.1);
}

bool feb_can_m160_temperature_set_1_inv_module_a_is_in_range(int16_t value)
{
    (void)value;

    return (true);
}

int16_t feb_can_m160_temperature_set_1_inv_module_b_encode(double value)
{
    return (int16_t)(value / 0.1);
}

double feb_can_m160_temperature_set_1_inv_module_b_decode(int16_t value)
{
    return ((double)value * 0.1);
}

bool feb_can_m160_temperature_set_1_inv_module_b_is_in_range(int16_t value)
{
    (void)value;

    return (true);
}

int16_t feb_can_m160_temperature_set_1_inv_module_c_encode(double value)
{
    return (int16_t)(value / 0.1);
}

double feb_can_m160_temperature_set_1_inv_module_c_decode(int16_t value)
{
    return ((double)value * 0.1);
}

bool feb_can_m160_temperature_set_1_inv_module_c_is_in_range(int16_t value)
{
    (void)value;

    return (true);
}

int16_t feb_can_m160_temperature_set_1_inv_gate_driver_board_encode(double value)
{
    return (int16_t)(value / 0.1);
}

double feb_can_m160_temperature_set_1_inv_gate_driver_board_decode(int16_t value)
{
    return ((double)value * 0.1);
}

bool feb_can_m160_temperature_set_1_inv_gate_driver_board_is_in_range(int16_t value)
{
    (void)value;

    return (true);
}

int feb_can_m161_temperature_set_2_pack(
    uint8_t *dst_p,
    const struct feb_can_m161_temperature_set_2_t *src_p,
    size_t size)
{
    uint16_t inv_control_board_temperature;
    uint16_t inv_rtd1_temperature;
    uint16_t inv_rtd2_temperature;
    uint16_t inv_rtd3_temperature;

    if (size < 8u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 8);

    inv_control_board_temperature = (uint16_t)src_p->inv_control_board_temperature;
    dst_p[0] |= pack_left_shift_u16(inv_control_board_temperature, 0u, 0xffu);
    dst_p[1] |= pack_right_shift_u16(inv_control_board_temperature, 8u, 0xffu);
    inv_rtd1_temperature = (uint16_t)src_p->inv_rtd1_temperature;
    dst_p[2] |= pack_left_shift_u16(inv_rtd1_temperature, 0u, 0xffu);
    dst_p[3] |= pack_right_shift_u16(inv_rtd1_temperature, 8u, 0xffu);
    inv_rtd2_temperature = (uint16_t)src_p->inv_rtd2_temperature;
    dst_p[4] |= pack_left_shift_u16(inv_rtd2_temperature, 0u, 0xffu);
    dst_p[5] |= pack_right_shift_u16(inv_rtd2_temperature, 8u, 0xffu);
    inv_rtd3_temperature = (uint16_t)src_p->inv_rtd3_temperature;
    dst_p[6] |= pack_left_shift_u16(inv_rtd3_temperature, 0u, 0xffu);
    dst_p[7] |= pack_right_shift_u16(inv_rtd3_temperature, 8u, 0xffu);

    return (8);
}

int feb_can_m161_temperature_set_2_unpack(
    struct feb_can_m161_temperature_set_2_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    uint16_t inv_control_board_temperature;
    uint16_t inv_rtd1_temperature;
    uint16_t inv_rtd2_temperature;
    uint16_t inv_rtd3_temperature;

    if (size < 8u) {
        return (-EINVAL);
    }

    inv_control_board_temperature = unpack_right_shift_u16(src_p[0], 0u, 0xffu);
    inv_control_board_temperature |= unpack_left_shift_u16(src_p[1], 8u, 0xffu);
    dst_p->inv_control_board_temperature = (int16_t)inv_control_board_temperature;
    inv_rtd1_temperature = unpack_right_shift_u16(src_p[2], 0u, 0xffu);
    inv_rtd1_temperature |= unpack_left_shift_u16(src_p[3], 8u, 0xffu);
    dst_p->inv_rtd1_temperature = (int16_t)inv_rtd1_temperature;
    inv_rtd2_temperature = unpack_right_shift_u16(src_p[4], 0u, 0xffu);
    inv_rtd2_temperature |= unpack_left_shift_u16(src_p[5], 8u, 0xffu);
    dst_p->inv_rtd2_temperature = (int16_t)inv_rtd2_temperature;
    inv_rtd3_temperature = unpack_right_shift_u16(src_p[6], 0u, 0xffu);
    inv_rtd3_temperature |= unpack_left_shift_u16(src_p[7], 8u, 0xffu);
    dst_p->inv_rtd3_temperature = (int16_t)inv_rtd3_temperature;

    return (0);
}

int feb_can_m161_temperature_set_2_init(struct feb_can_m161_temperature_set_2_t *msg_p)
{
    if (msg_p == NULL) return -1;

    memset(msg_p, 0, sizeof(struct feb_can_m161_temperature_set_2_t));

    return 0;
}

int16_t feb_can_m161_temperature_set_2_inv_control_board_temperature_encode(double value)
{
    return (int16_t)(value / 0.1);
}

double feb_can_m161_temperature_set_2_inv_control_board_temperature_decode(int16_t value)
{
    return ((double)value * 0.1);
}

bool feb_can_m161_temperature_set_2_inv_control_board_temperature_is_in_range(int16_t value)
{
    (void)value;

    return (true);
}

int16_t feb_can_m161_temperature_set_2_inv_rtd1_temperature_encode(double value)
{
    return (int16_t)(value / 0.1);
}

double feb_can_m161_temperature_set_2_inv_rtd1_temperature_decode(int16_t value)
{
    return ((double)value * 0.1);
}

bool feb_can_m161_temperature_set_2_inv_rtd1_temperature_is_in_range(int16_t value)
{
    (void)value;

    return (true);
}

int16_t feb_can_m161_temperature_set_2_inv_rtd2_temperature_encode(double value)
{
    return (int16_t)(value / 0.1);
}

double feb_can_m161_temperature_set_2_inv_rtd2_temperature_decode(int16_t value)
{
    return ((double)value * 0.1);
}

bool feb_can_m161_temperature_set_2_inv_rtd2_temperature_is_in_range(int16_t value)
{
    (void)value;

    return (true);
}

int16_t feb_can_m161_temperature_set_2_inv_rtd3_temperature_encode(double value)
{
    return (int16_t)(value / 0.1);
}

double feb_can_m161_temperature_set_2_inv_rtd3_temperature_decode(int16_t value)
{
    return ((double)value * 0.1);
}

bool feb_can_m161_temperature_set_2_inv_rtd3_temperature_is_in_range(int16_t value)
{
    (void)value;

    return (true);
}

int feb_can_m162_temperature_set_3_pack(
    uint8_t *dst_p,
    const struct feb_can_m162_temperature_set_3_t *src_p,
    size_t size)
{
    uint16_t inv_motor_temperature;
    uint16_t inv_rtd4_temperature;
    uint16_t inv_rtd5_temperature;
    uint16_t inv_torque_shudder;

    if (size < 8u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 8);

    inv_rtd4_temperature = (uint16_t)src_p->inv_rtd4_temperature;
    dst_p[0] |= pack_left_shift_u16(inv_rtd4_temperature, 0u, 0xffu);
    dst_p[1] |= pack_right_shift_u16(inv_rtd4_temperature, 8u, 0xffu);
    inv_rtd5_temperature = (uint16_t)src_p->inv_rtd5_temperature;
    dst_p[2] |= pack_left_shift_u16(inv_rtd5_temperature, 0u, 0xffu);
    dst_p[3] |= pack_right_shift_u16(inv_rtd5_temperature, 8u, 0xffu);
    inv_motor_temperature = (uint16_t)src_p->inv_motor_temperature;
    dst_p[4] |= pack_left_shift_u16(inv_motor_temperature, 0u, 0xffu);
    dst_p[5] |= pack_right_shift_u16(inv_motor_temperature, 8u, 0xffu);
    inv_torque_shudder = (uint16_t)src_p->inv_torque_shudder;
    dst_p[6] |= pack_left_shift_u16(inv_torque_shudder, 0u, 0xffu);
    dst_p[7] |= pack_right_shift_u16(inv_torque_shudder, 8u, 0xffu);

    return (8);
}

int feb_can_m162_temperature_set_3_unpack(
    struct feb_can_m162_temperature_set_3_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    uint16_t inv_motor_temperature;
    uint16_t inv_rtd4_temperature;
    uint16_t inv_rtd5_temperature;
    uint16_t inv_torque_shudder;

    if (size < 8u) {
        return (-EINVAL);
    }

    inv_rtd4_temperature = unpack_right_shift_u16(src_p[0], 0u, 0xffu);
    inv_rtd4_temperature |= unpack_left_shift_u16(src_p[1], 8u, 0xffu);
    dst_p->inv_rtd4_temperature = (int16_t)inv_rtd4_temperature;
    inv_rtd5_temperature = unpack_right_shift_u16(src_p[2], 0u, 0xffu);
    inv_rtd5_temperature |= unpack_left_shift_u16(src_p[3], 8u, 0xffu);
    dst_p->inv_rtd5_temperature = (int16_t)inv_rtd5_temperature;
    inv_motor_temperature = unpack_right_shift_u16(src_p[4], 0u, 0xffu);
    inv_motor_temperature |= unpack_left_shift_u16(src_p[5], 8u, 0xffu);
    dst_p->inv_motor_temperature = (int16_t)inv_motor_temperature;
    inv_torque_shudder = unpack_right_shift_u16(src_p[6], 0u, 0xffu);
    inv_torque_shudder |= unpack_left_shift_u16(src_p[7], 8u, 0xffu);
    dst_p->inv_torque_shudder = (int16_t)inv_torque_shudder;

    return (0);
}

int feb_can_m162_temperature_set_3_init(struct feb_can_m162_temperature_set_3_t *msg_p)
{
    if (msg_p == NULL) return -1;

    memset(msg_p, 0, sizeof(struct feb_can_m162_temperature_set_3_t));

    return 0;
}

int16_t feb_can_m162_temperature_set_3_inv_rtd4_temperature_encode(double value)
{
    return (int16_t)(value / 0.1);
}

double feb_can_m162_temperature_set_3_inv_rtd4_temperature_decode(int16_t value)
{
    return ((double)value * 0.1);
}

bool feb_can_m162_temperature_set_3_inv_rtd4_temperature_is_in_range(int16_t value)
{
    (void)value;

    return (true);
}

int16_t feb_can_m162_temperature_set_3_inv_rtd5_temperature_encode(double value)
{
    return (int16_t)(value / 0.1);
}

double feb_can_m162_temperature_set_3_inv_rtd5_temperature_decode(int16_t value)
{
    return ((double)value * 0.1);
}

bool feb_can_m162_temperature_set_3_inv_rtd5_temperature_is_in_range(int16_t value)
{
    (void)value;

    return (true);
}

int16_t feb_can_m162_temperature_set_3_inv_motor_temperature_encode(double value)
{
    return (int16_t)(value / 0.1);
}

double feb_can_m162_temperature_set_3_inv_motor_temperature_decode(int16_t value)
{
    return ((double)value * 0.1);
}

bool feb_can_m162_temperature_set_3_inv_motor_temperature_is_in_range(int16_t value)
{
    (void)value;

    return (true);
}

int16_t feb_can_m162_temperature_set_3_inv_torque_shudder_encode(double value)
{
    return (int16_t)(value / 0.1);
}

double feb_can_m162_temperature_set_3_inv_torque_shudder_decode(int16_t value)
{
    return ((double)value * 0.1);
}

bool feb_can_m162_temperature_set_3_inv_torque_shudder_is_in_range(int16_t value)
{
    (void)value;

    return (true);
}

int feb_can_m163_analog_input_voltages_pack(
    uint8_t *dst_p,
    const struct feb_can_m163_analog_input_voltages_t *src_p,
    size_t size)
{
    if (size < 8u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 8);

    dst_p[0] |= pack_left_shift_u16(src_p->inv_analog_input_1, 0u, 0xffu);
    dst_p[1] |= pack_right_shift_u16(src_p->inv_analog_input_1, 8u, 0x03u);
    dst_p[1] |= pack_left_shift_u16(src_p->inv_analog_input_2, 2u, 0xfcu);
    dst_p[2] |= pack_right_shift_u16(src_p->inv_analog_input_2, 6u, 0x0fu);
    dst_p[2] |= pack_left_shift_u16(src_p->inv_analog_input_3, 4u, 0xf0u);
    dst_p[3] |= pack_right_shift_u16(src_p->inv_analog_input_3, 4u, 0x3fu);
    dst_p[4] |= pack_left_shift_u16(src_p->inv_analog_input_4, 0u, 0xffu);
    dst_p[5] |= pack_right_shift_u16(src_p->inv_analog_input_4, 8u, 0x03u);
    dst_p[5] |= pack_left_shift_u16(src_p->inv_analog_input_5, 2u, 0xfcu);
    dst_p[6] |= pack_right_shift_u16(src_p->inv_analog_input_5, 6u, 0x0fu);
    dst_p[6] |= pack_left_shift_u16(src_p->inv_analog_input_6, 4u, 0xf0u);
    dst_p[7] |= pack_right_shift_u16(src_p->inv_analog_input_6, 4u, 0x3fu);

    return (8);
}

int feb_can_m163_analog_input_voltages_unpack(
    struct feb_can_m163_analog_input_voltages_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    if (size < 8u) {
        return (-EINVAL);
    }

    dst_p->inv_analog_input_1 = unpack_right_shift_u16(src_p[0], 0u, 0xffu);
    dst_p->inv_analog_input_1 |= unpack_left_shift_u16(src_p[1], 8u, 0x03u);
    dst_p->inv_analog_input_2 = unpack_right_shift_u16(src_p[1], 2u, 0xfcu);
    dst_p->inv_analog_input_2 |= unpack_left_shift_u16(src_p[2], 6u, 0x0fu);
    dst_p->inv_analog_input_3 = unpack_right_shift_u16(src_p[2], 4u, 0xf0u);
    dst_p->inv_analog_input_3 |= unpack_left_shift_u16(src_p[3], 4u, 0x3fu);
    dst_p->inv_analog_input_4 = unpack_right_shift_u16(src_p[4], 0u, 0xffu);
    dst_p->inv_analog_input_4 |= unpack_left_shift_u16(src_p[5], 8u, 0x03u);
    dst_p->inv_analog_input_5 = unpack_right_shift_u16(src_p[5], 2u, 0xfcu);
    dst_p->inv_analog_input_5 |= unpack_left_shift_u16(src_p[6], 6u, 0x0fu);
    dst_p->inv_analog_input_6 = unpack_right_shift_u16(src_p[6], 4u, 0xf0u);
    dst_p->inv_analog_input_6 |= unpack_left_shift_u16(src_p[7], 4u, 0x3fu);

    return (0);
}

int feb_can_m163_analog_input_voltages_init(struct feb_can_m163_analog_input_voltages_t *msg_p)
{
    if (msg_p == NULL) return -1;

    memset(msg_p, 0, sizeof(struct feb_can_m163_analog_input_voltages_t));

    return 0;
}

uint16_t feb_can_m163_analog_input_voltages_inv_analog_input_1_encode(double value)
{
    return (uint16_t)(value / 0.01);
}

double feb_can_m163_analog_input_voltages_inv_analog_input_1_decode(uint16_t value)
{
    return ((double)value * 0.01);
}

bool feb_can_m163_analog_input_voltages_inv_analog_input_1_is_in_range(uint16_t value)
{
    return (value <= 1023u);
}

uint16_t feb_can_m163_analog_input_voltages_inv_analog_input_2_encode(double value)
{
    return (uint16_t)(value / 0.01);
}

double feb_can_m163_analog_input_voltages_inv_analog_input_2_decode(uint16_t value)
{
    return ((double)value * 0.01);
}

bool feb_can_m163_analog_input_voltages_inv_analog_input_2_is_in_range(uint16_t value)
{
    return (value <= 1023u);
}

uint16_t feb_can_m163_analog_input_voltages_inv_analog_input_3_encode(double value)
{
    return (uint16_t)(value / 0.01);
}

double feb_can_m163_analog_input_voltages_inv_analog_input_3_decode(uint16_t value)
{
    return ((double)value * 0.01);
}

bool feb_can_m163_analog_input_voltages_inv_analog_input_3_is_in_range(uint16_t value)
{
    return (value <= 1023u);
}

uint16_t feb_can_m163_analog_input_voltages_inv_analog_input_4_encode(double value)
{
    return (uint16_t)(value / 0.01);
}

double feb_can_m163_analog_input_voltages_inv_analog_input_4_decode(uint16_t value)
{
    return ((double)value * 0.01);
}

bool feb_can_m163_analog_input_voltages_inv_analog_input_4_is_in_range(uint16_t value)
{
    return (value <= 1023u);
}

uint16_t feb_can_m163_analog_input_voltages_inv_analog_input_5_encode(double value)
{
    return (uint16_t)(value / 0.01);
}

double feb_can_m163_analog_input_voltages_inv_analog_input_5_decode(uint16_t value)
{
    return ((double)value * 0.01);
}

bool feb_can_m163_analog_input_voltages_inv_analog_input_5_is_in_range(uint16_t value)
{
    return (value <= 1023u);
}

uint16_t feb_can_m163_analog_input_voltages_inv_analog_input_6_encode(double value)
{
    return (uint16_t)(value / 0.01);
}

double feb_can_m163_analog_input_voltages_inv_analog_input_6_decode(uint16_t value)
{
    return ((double)value * 0.01);
}

bool feb_can_m163_analog_input_voltages_inv_analog_input_6_is_in_range(uint16_t value)
{
    return (value <= 1023u);
}

int feb_can_m164_digital_input_status_pack(
    uint8_t *dst_p,
    const struct feb_can_m164_digital_input_status_t *src_p,
    size_t size)
{
    if (size < 8u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 8);

    dst_p[0] |= pack_left_shift_u8(src_p->inv_digital_input_1, 0u, 0x01u);
    dst_p[1] |= pack_left_shift_u8(src_p->inv_digital_input_2, 0u, 0x01u);
    dst_p[2] |= pack_left_shift_u8(src_p->inv_digital_input_3, 0u, 0x01u);
    dst_p[3] |= pack_left_shift_u8(src_p->inv_digital_input_4, 0u, 0x01u);
    dst_p[4] |= pack_left_shift_u8(src_p->inv_digital_input_5, 0u, 0x01u);
    dst_p[5] |= pack_left_shift_u8(src_p->inv_digital_input_6, 0u, 0x01u);
    dst_p[6] |= pack_left_shift_u8(src_p->inv_digital_input_7, 0u, 0x01u);
    dst_p[7] |= pack_left_shift_u8(src_p->inv_digital_input_8, 0u, 0x01u);

    return (8);
}

int feb_can_m164_digital_input_status_unpack(
    struct feb_can_m164_digital_input_status_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    if (size < 8u) {
        return (-EINVAL);
    }

    dst_p->inv_digital_input_1 = unpack_right_shift_u8(src_p[0], 0u, 0x01u);
    dst_p->inv_digital_input_2 = unpack_right_shift_u8(src_p[1], 0u, 0x01u);
    dst_p->inv_digital_input_3 = unpack_right_shift_u8(src_p[2], 0u, 0x01u);
    dst_p->inv_digital_input_4 = unpack_right_shift_u8(src_p[3], 0u, 0x01u);
    dst_p->inv_digital_input_5 = unpack_right_shift_u8(src_p[4], 0u, 0x01u);
    dst_p->inv_digital_input_6 = unpack_right_shift_u8(src_p[5], 0u, 0x01u);
    dst_p->inv_digital_input_7 = unpack_right_shift_u8(src_p[6], 0u, 0x01u);
    dst_p->inv_digital_input_8 = unpack_right_shift_u8(src_p[7], 0u, 0x01u);

    return (0);
}

int feb_can_m164_digital_input_status_init(struct feb_can_m164_digital_input_status_t *msg_p)
{
    if (msg_p == NULL) return -1;

    memset(msg_p, 0, sizeof(struct feb_can_m164_digital_input_status_t));

    return 0;
}

uint8_t feb_can_m164_digital_input_status_inv_digital_input_1_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_m164_digital_input_status_inv_digital_input_1_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_m164_digital_input_status_inv_digital_input_1_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_m164_digital_input_status_inv_digital_input_2_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_m164_digital_input_status_inv_digital_input_2_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_m164_digital_input_status_inv_digital_input_2_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_m164_digital_input_status_inv_digital_input_3_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_m164_digital_input_status_inv_digital_input_3_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_m164_digital_input_status_inv_digital_input_3_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_m164_digital_input_status_inv_digital_input_4_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_m164_digital_input_status_inv_digital_input_4_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_m164_digital_input_status_inv_digital_input_4_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_m164_digital_input_status_inv_digital_input_5_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_m164_digital_input_status_inv_digital_input_5_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_m164_digital_input_status_inv_digital_input_5_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_m164_digital_input_status_inv_digital_input_6_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_m164_digital_input_status_inv_digital_input_6_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_m164_digital_input_status_inv_digital_input_6_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_m164_digital_input_status_inv_digital_input_7_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_m164_digital_input_status_inv_digital_input_7_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_m164_digital_input_status_inv_digital_input_7_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_m164_digital_input_status_inv_digital_input_8_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_m164_digital_input_status_inv_digital_input_8_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_m164_digital_input_status_inv_digital_input_8_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

int feb_can_m165_motor_position_info_pack(
    uint8_t *dst_p,
    const struct feb_can_m165_motor_position_info_t *src_p,
    size_t size)
{
    uint16_t inv_delta_resolver_filtered;
    uint16_t inv_electrical_output_frequency;
    uint16_t inv_motor_speed;

    if (size < 8u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 8);

    dst_p[0] |= pack_left_shift_u16(src_p->inv_motor_angle_electrical, 0u, 0xffu);
    dst_p[1] |= pack_right_shift_u16(src_p->inv_motor_angle_electrical, 8u, 0xffu);
    inv_motor_speed = (uint16_t)src_p->inv_motor_speed;
    dst_p[2] |= pack_left_shift_u16(inv_motor_speed, 0u, 0xffu);
    dst_p[3] |= pack_right_shift_u16(inv_motor_speed, 8u, 0xffu);
    inv_electrical_output_frequency = (uint16_t)src_p->inv_electrical_output_frequency;
    dst_p[4] |= pack_left_shift_u16(inv_electrical_output_frequency, 0u, 0xffu);
    dst_p[5] |= pack_right_shift_u16(inv_electrical_output_frequency, 8u, 0xffu);
    inv_delta_resolver_filtered = (uint16_t)src_p->inv_delta_resolver_filtered;
    dst_p[6] |= pack_left_shift_u16(inv_delta_resolver_filtered, 0u, 0xffu);
    dst_p[7] |= pack_right_shift_u16(inv_delta_resolver_filtered, 8u, 0xffu);

    return (8);
}

int feb_can_m165_motor_position_info_unpack(
    struct feb_can_m165_motor_position_info_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    uint16_t inv_delta_resolver_filtered;
    uint16_t inv_electrical_output_frequency;
    uint16_t inv_motor_speed;

    if (size < 8u) {
        return (-EINVAL);
    }

    dst_p->inv_motor_angle_electrical = unpack_right_shift_u16(src_p[0], 0u, 0xffu);
    dst_p->inv_motor_angle_electrical |= unpack_left_shift_u16(src_p[1], 8u, 0xffu);
    inv_motor_speed = unpack_right_shift_u16(src_p[2], 0u, 0xffu);
    inv_motor_speed |= unpack_left_shift_u16(src_p[3], 8u, 0xffu);
    dst_p->inv_motor_speed = (int16_t)inv_motor_speed;
    inv_electrical_output_frequency = unpack_right_shift_u16(src_p[4], 0u, 0xffu);
    inv_electrical_output_frequency |= unpack_left_shift_u16(src_p[5], 8u, 0xffu);
    dst_p->inv_electrical_output_frequency = (int16_t)inv_electrical_output_frequency;
    inv_delta_resolver_filtered = unpack_right_shift_u16(src_p[6], 0u, 0xffu);
    inv_delta_resolver_filtered |= unpack_left_shift_u16(src_p[7], 8u, 0xffu);
    dst_p->inv_delta_resolver_filtered = (int16_t)inv_delta_resolver_filtered;

    return (0);
}

int feb_can_m165_motor_position_info_init(struct feb_can_m165_motor_position_info_t *msg_p)
{
    if (msg_p == NULL) return -1;

    memset(msg_p, 0, sizeof(struct feb_can_m165_motor_position_info_t));

    return 0;
}

uint16_t feb_can_m165_motor_position_info_inv_motor_angle_electrical_encode(double value)
{
    return (uint16_t)(value / 0.1);
}

double feb_can_m165_motor_position_info_inv_motor_angle_electrical_decode(uint16_t value)
{
    return ((double)value * 0.1);
}

bool feb_can_m165_motor_position_info_inv_motor_angle_electrical_is_in_range(uint16_t value)
{
    (void)value;

    return (true);
}

int16_t feb_can_m165_motor_position_info_inv_motor_speed_encode(double value)
{
    return (int16_t)(value);
}

double feb_can_m165_motor_position_info_inv_motor_speed_decode(int16_t value)
{
    return ((double)value);
}

bool feb_can_m165_motor_position_info_inv_motor_speed_is_in_range(int16_t value)
{
    (void)value;

    return (true);
}

int16_t feb_can_m165_motor_position_info_inv_electrical_output_frequency_encode(double value)
{
    return (int16_t)(value / 0.1);
}

double feb_can_m165_motor_position_info_inv_electrical_output_frequency_decode(int16_t value)
{
    return ((double)value * 0.1);
}

bool feb_can_m165_motor_position_info_inv_electrical_output_frequency_is_in_range(int16_t value)
{
    (void)value;

    return (true);
}

int16_t feb_can_m165_motor_position_info_inv_delta_resolver_filtered_encode(double value)
{
    return (int16_t)(value / 0.1);
}

double feb_can_m165_motor_position_info_inv_delta_resolver_filtered_decode(int16_t value)
{
    return ((double)value * 0.1);
}

bool feb_can_m165_motor_position_info_inv_delta_resolver_filtered_is_in_range(int16_t value)
{
    (void)value;

    return (true);
}

int feb_can_m166_current_info_pack(
    uint8_t *dst_p,
    const struct feb_can_m166_current_info_t *src_p,
    size_t size)
{
    uint16_t inv_dc_bus_current;
    uint16_t inv_phase_a_current;
    uint16_t inv_phase_b_current;
    uint16_t inv_phase_c_current;

    if (size < 8u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 8);

    inv_phase_a_current = (uint16_t)src_p->inv_phase_a_current;
    dst_p[0] |= pack_left_shift_u16(inv_phase_a_current, 0u, 0xffu);
    dst_p[1] |= pack_right_shift_u16(inv_phase_a_current, 8u, 0xffu);
    inv_phase_b_current = (uint16_t)src_p->inv_phase_b_current;
    dst_p[2] |= pack_left_shift_u16(inv_phase_b_current, 0u, 0xffu);
    dst_p[3] |= pack_right_shift_u16(inv_phase_b_current, 8u, 0xffu);
    inv_phase_c_current = (uint16_t)src_p->inv_phase_c_current;
    dst_p[4] |= pack_left_shift_u16(inv_phase_c_current, 0u, 0xffu);
    dst_p[5] |= pack_right_shift_u16(inv_phase_c_current, 8u, 0xffu);
    inv_dc_bus_current = (uint16_t)src_p->inv_dc_bus_current;
    dst_p[6] |= pack_left_shift_u16(inv_dc_bus_current, 0u, 0xffu);
    dst_p[7] |= pack_right_shift_u16(inv_dc_bus_current, 8u, 0xffu);

    return (8);
}

int feb_can_m166_current_info_unpack(
    struct feb_can_m166_current_info_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    uint16_t inv_dc_bus_current;
    uint16_t inv_phase_a_current;
    uint16_t inv_phase_b_current;
    uint16_t inv_phase_c_current;

    if (size < 8u) {
        return (-EINVAL);
    }

    inv_phase_a_current = unpack_right_shift_u16(src_p[0], 0u, 0xffu);
    inv_phase_a_current |= unpack_left_shift_u16(src_p[1], 8u, 0xffu);
    dst_p->inv_phase_a_current = (int16_t)inv_phase_a_current;
    inv_phase_b_current = unpack_right_shift_u16(src_p[2], 0u, 0xffu);
    inv_phase_b_current |= unpack_left_shift_u16(src_p[3], 8u, 0xffu);
    dst_p->inv_phase_b_current = (int16_t)inv_phase_b_current;
    inv_phase_c_current = unpack_right_shift_u16(src_p[4], 0u, 0xffu);
    inv_phase_c_current |= unpack_left_shift_u16(src_p[5], 8u, 0xffu);
    dst_p->inv_phase_c_current = (int16_t)inv_phase_c_current;
    inv_dc_bus_current = unpack_right_shift_u16(src_p[6], 0u, 0xffu);
    inv_dc_bus_current |= unpack_left_shift_u16(src_p[7], 8u, 0xffu);
    dst_p->inv_dc_bus_current = (int16_t)inv_dc_bus_current;

    return (0);
}

int feb_can_m166_current_info_init(struct feb_can_m166_current_info_t *msg_p)
{
    if (msg_p == NULL) return -1;

    memset(msg_p, 0, sizeof(struct feb_can_m166_current_info_t));

    return 0;
}

int16_t feb_can_m166_current_info_inv_phase_a_current_encode(double value)
{
    return (int16_t)(value / 0.1);
}

double feb_can_m166_current_info_inv_phase_a_current_decode(int16_t value)
{
    return ((double)value * 0.1);
}

bool feb_can_m166_current_info_inv_phase_a_current_is_in_range(int16_t value)
{
    (void)value;

    return (true);
}

int16_t feb_can_m166_current_info_inv_phase_b_current_encode(double value)
{
    return (int16_t)(value / 0.1);
}

double feb_can_m166_current_info_inv_phase_b_current_decode(int16_t value)
{
    return ((double)value * 0.1);
}

bool feb_can_m166_current_info_inv_phase_b_current_is_in_range(int16_t value)
{
    (void)value;

    return (true);
}

int16_t feb_can_m166_current_info_inv_phase_c_current_encode(double value)
{
    return (int16_t)(value / 0.1);
}

double feb_can_m166_current_info_inv_phase_c_current_decode(int16_t value)
{
    return ((double)value * 0.1);
}

bool feb_can_m166_current_info_inv_phase_c_current_is_in_range(int16_t value)
{
    (void)value;

    return (true);
}

int16_t feb_can_m166_current_info_inv_dc_bus_current_encode(double value)
{
    return (int16_t)(value / 0.1);
}

double feb_can_m166_current_info_inv_dc_bus_current_decode(int16_t value)
{
    return ((double)value * 0.1);
}

bool feb_can_m166_current_info_inv_dc_bus_current_is_in_range(int16_t value)
{
    (void)value;

    return (true);
}

int feb_can_m167_voltage_info_pack(
    uint8_t *dst_p,
    const struct feb_can_m167_voltage_info_t *src_p,
    size_t size)
{
    uint16_t inv_dc_bus_voltage;
    uint16_t inv_output_voltage;
    uint16_t inv_vab_vd_voltage;
    uint16_t inv_vbc_vq_voltage;

    if (size < 8u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 8);

    inv_dc_bus_voltage = (uint16_t)src_p->inv_dc_bus_voltage;
    dst_p[0] |= pack_left_shift_u16(inv_dc_bus_voltage, 0u, 0xffu);
    dst_p[1] |= pack_right_shift_u16(inv_dc_bus_voltage, 8u, 0xffu);
    inv_output_voltage = (uint16_t)src_p->inv_output_voltage;
    dst_p[2] |= pack_left_shift_u16(inv_output_voltage, 0u, 0xffu);
    dst_p[3] |= pack_right_shift_u16(inv_output_voltage, 8u, 0xffu);
    inv_vab_vd_voltage = (uint16_t)src_p->inv_vab_vd_voltage;
    dst_p[4] |= pack_left_shift_u16(inv_vab_vd_voltage, 0u, 0xffu);
    dst_p[5] |= pack_right_shift_u16(inv_vab_vd_voltage, 8u, 0xffu);
    inv_vbc_vq_voltage = (uint16_t)src_p->inv_vbc_vq_voltage;
    dst_p[6] |= pack_left_shift_u16(inv_vbc_vq_voltage, 0u, 0xffu);
    dst_p[7] |= pack_right_shift_u16(inv_vbc_vq_voltage, 8u, 0xffu);

    return (8);
}

int feb_can_m167_voltage_info_unpack(
    struct feb_can_m167_voltage_info_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    uint16_t inv_dc_bus_voltage;
    uint16_t inv_output_voltage;
    uint16_t inv_vab_vd_voltage;
    uint16_t inv_vbc_vq_voltage;

    if (size < 8u) {
        return (-EINVAL);
    }

    inv_dc_bus_voltage = unpack_right_shift_u16(src_p[0], 0u, 0xffu);
    inv_dc_bus_voltage |= unpack_left_shift_u16(src_p[1], 8u, 0xffu);
    dst_p->inv_dc_bus_voltage = (int16_t)inv_dc_bus_voltage;
    inv_output_voltage = unpack_right_shift_u16(src_p[2], 0u, 0xffu);
    inv_output_voltage |= unpack_left_shift_u16(src_p[3], 8u, 0xffu);
    dst_p->inv_output_voltage = (int16_t)inv_output_voltage;
    inv_vab_vd_voltage = unpack_right_shift_u16(src_p[4], 0u, 0xffu);
    inv_vab_vd_voltage |= unpack_left_shift_u16(src_p[5], 8u, 0xffu);
    dst_p->inv_vab_vd_voltage = (int16_t)inv_vab_vd_voltage;
    inv_vbc_vq_voltage = unpack_right_shift_u16(src_p[6], 0u, 0xffu);
    inv_vbc_vq_voltage |= unpack_left_shift_u16(src_p[7], 8u, 0xffu);
    dst_p->inv_vbc_vq_voltage = (int16_t)inv_vbc_vq_voltage;

    return (0);
}

int feb_can_m167_voltage_info_init(struct feb_can_m167_voltage_info_t *msg_p)
{
    if (msg_p == NULL) return -1;

    memset(msg_p, 0, sizeof(struct feb_can_m167_voltage_info_t));

    return 0;
}

int16_t feb_can_m167_voltage_info_inv_dc_bus_voltage_encode(double value)
{
    return (int16_t)(value / 0.1);
}

double feb_can_m167_voltage_info_inv_dc_bus_voltage_decode(int16_t value)
{
    return ((double)value * 0.1);
}

bool feb_can_m167_voltage_info_inv_dc_bus_voltage_is_in_range(int16_t value)
{
    (void)value;

    return (true);
}

int16_t feb_can_m167_voltage_info_inv_output_voltage_encode(double value)
{
    return (int16_t)(value / 0.1);
}

double feb_can_m167_voltage_info_inv_output_voltage_decode(int16_t value)
{
    return ((double)value * 0.1);
}

bool feb_can_m167_voltage_info_inv_output_voltage_is_in_range(int16_t value)
{
    (void)value;

    return (true);
}

int16_t feb_can_m167_voltage_info_inv_vab_vd_voltage_encode(double value)
{
    return (int16_t)(value / 0.1);
}

double feb_can_m167_voltage_info_inv_vab_vd_voltage_decode(int16_t value)
{
    return ((double)value * 0.1);
}

bool feb_can_m167_voltage_info_inv_vab_vd_voltage_is_in_range(int16_t value)
{
    (void)value;

    return (true);
}

int16_t feb_can_m167_voltage_info_inv_vbc_vq_voltage_encode(double value)
{
    return (int16_t)(value / 0.1);
}

double feb_can_m167_voltage_info_inv_vbc_vq_voltage_decode(int16_t value)
{
    return ((double)value * 0.1);
}

bool feb_can_m167_voltage_info_inv_vbc_vq_voltage_is_in_range(int16_t value)
{
    (void)value;

    return (true);
}

int feb_can_m168_flux_id_iq_info_pack(
    uint8_t *dst_p,
    const struct feb_can_m168_flux_id_iq_info_t *src_p,
    size_t size)
{
    uint16_t inv_flux_command;
    uint16_t inv_flux_feedback;
    uint16_t inv_id;
    uint16_t inv_iq;

    if (size < 8u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 8);

    inv_flux_command = (uint16_t)src_p->inv_flux_command;
    dst_p[0] |= pack_left_shift_u16(inv_flux_command, 0u, 0xffu);
    dst_p[1] |= pack_right_shift_u16(inv_flux_command, 8u, 0xffu);
    inv_flux_feedback = (uint16_t)src_p->inv_flux_feedback;
    dst_p[2] |= pack_left_shift_u16(inv_flux_feedback, 0u, 0xffu);
    dst_p[3] |= pack_right_shift_u16(inv_flux_feedback, 8u, 0xffu);
    inv_id = (uint16_t)src_p->inv_id;
    dst_p[4] |= pack_left_shift_u16(inv_id, 0u, 0xffu);
    dst_p[5] |= pack_right_shift_u16(inv_id, 8u, 0xffu);
    inv_iq = (uint16_t)src_p->inv_iq;
    dst_p[6] |= pack_left_shift_u16(inv_iq, 0u, 0xffu);
    dst_p[7] |= pack_right_shift_u16(inv_iq, 8u, 0xffu);

    return (8);
}

int feb_can_m168_flux_id_iq_info_unpack(
    struct feb_can_m168_flux_id_iq_info_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    uint16_t inv_flux_command;
    uint16_t inv_flux_feedback;
    uint16_t inv_id;
    uint16_t inv_iq;

    if (size < 8u) {
        return (-EINVAL);
    }

    inv_flux_command = unpack_right_shift_u16(src_p[0], 0u, 0xffu);
    inv_flux_command |= unpack_left_shift_u16(src_p[1], 8u, 0xffu);
    dst_p->inv_flux_command = (int16_t)inv_flux_command;
    inv_flux_feedback = unpack_right_shift_u16(src_p[2], 0u, 0xffu);
    inv_flux_feedback |= unpack_left_shift_u16(src_p[3], 8u, 0xffu);
    dst_p->inv_flux_feedback = (int16_t)inv_flux_feedback;
    inv_id = unpack_right_shift_u16(src_p[4], 0u, 0xffu);
    inv_id |= unpack_left_shift_u16(src_p[5], 8u, 0xffu);
    dst_p->inv_id = (int16_t)inv_id;
    inv_iq = unpack_right_shift_u16(src_p[6], 0u, 0xffu);
    inv_iq |= unpack_left_shift_u16(src_p[7], 8u, 0xffu);
    dst_p->inv_iq = (int16_t)inv_iq;

    return (0);
}

int feb_can_m168_flux_id_iq_info_init(struct feb_can_m168_flux_id_iq_info_t *msg_p)
{
    if (msg_p == NULL) return -1;

    memset(msg_p, 0, sizeof(struct feb_can_m168_flux_id_iq_info_t));

    return 0;
}

int16_t feb_can_m168_flux_id_iq_info_inv_flux_command_encode(double value)
{
    return (int16_t)(value / 0.001);
}

double feb_can_m168_flux_id_iq_info_inv_flux_command_decode(int16_t value)
{
    return ((double)value * 0.001);
}

bool feb_can_m168_flux_id_iq_info_inv_flux_command_is_in_range(int16_t value)
{
    (void)value;

    return (true);
}

int16_t feb_can_m168_flux_id_iq_info_inv_flux_feedback_encode(double value)
{
    return (int16_t)(value / 0.001);
}

double feb_can_m168_flux_id_iq_info_inv_flux_feedback_decode(int16_t value)
{
    return ((double)value * 0.001);
}

bool feb_can_m168_flux_id_iq_info_inv_flux_feedback_is_in_range(int16_t value)
{
    (void)value;

    return (true);
}

int16_t feb_can_m168_flux_id_iq_info_inv_id_encode(double value)
{
    return (int16_t)(value / 0.1);
}

double feb_can_m168_flux_id_iq_info_inv_id_decode(int16_t value)
{
    return ((double)value * 0.1);
}

bool feb_can_m168_flux_id_iq_info_inv_id_is_in_range(int16_t value)
{
    (void)value;

    return (true);
}

int16_t feb_can_m168_flux_id_iq_info_inv_iq_encode(double value)
{
    return (int16_t)(value / 0.1);
}

double feb_can_m168_flux_id_iq_info_inv_iq_decode(int16_t value)
{
    return ((double)value * 0.1);
}

bool feb_can_m168_flux_id_iq_info_inv_iq_is_in_range(int16_t value)
{
    (void)value;

    return (true);
}

int feb_can_m169_internal_voltages_pack(
    uint8_t *dst_p,
    const struct feb_can_m169_internal_voltages_t *src_p,
    size_t size)
{
    uint16_t inv_reference_voltage_12_0;
    uint16_t inv_reference_voltage_1_5;
    uint16_t inv_reference_voltage_2_5;
    uint16_t inv_reference_voltage_5_0;

    if (size < 8u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 8);

    inv_reference_voltage_1_5 = (uint16_t)src_p->inv_reference_voltage_1_5;
    dst_p[0] |= pack_left_shift_u16(inv_reference_voltage_1_5, 0u, 0xffu);
    dst_p[1] |= pack_right_shift_u16(inv_reference_voltage_1_5, 8u, 0xffu);
    inv_reference_voltage_2_5 = (uint16_t)src_p->inv_reference_voltage_2_5;
    dst_p[2] |= pack_left_shift_u16(inv_reference_voltage_2_5, 0u, 0xffu);
    dst_p[3] |= pack_right_shift_u16(inv_reference_voltage_2_5, 8u, 0xffu);
    inv_reference_voltage_5_0 = (uint16_t)src_p->inv_reference_voltage_5_0;
    dst_p[4] |= pack_left_shift_u16(inv_reference_voltage_5_0, 0u, 0xffu);
    dst_p[5] |= pack_right_shift_u16(inv_reference_voltage_5_0, 8u, 0xffu);
    inv_reference_voltage_12_0 = (uint16_t)src_p->inv_reference_voltage_12_0;
    dst_p[6] |= pack_left_shift_u16(inv_reference_voltage_12_0, 0u, 0xffu);
    dst_p[7] |= pack_right_shift_u16(inv_reference_voltage_12_0, 8u, 0xffu);

    return (8);
}

int feb_can_m169_internal_voltages_unpack(
    struct feb_can_m169_internal_voltages_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    uint16_t inv_reference_voltage_12_0;
    uint16_t inv_reference_voltage_1_5;
    uint16_t inv_reference_voltage_2_5;
    uint16_t inv_reference_voltage_5_0;

    if (size < 8u) {
        return (-EINVAL);
    }

    inv_reference_voltage_1_5 = unpack_right_shift_u16(src_p[0], 0u, 0xffu);
    inv_reference_voltage_1_5 |= unpack_left_shift_u16(src_p[1], 8u, 0xffu);
    dst_p->inv_reference_voltage_1_5 = (int16_t)inv_reference_voltage_1_5;
    inv_reference_voltage_2_5 = unpack_right_shift_u16(src_p[2], 0u, 0xffu);
    inv_reference_voltage_2_5 |= unpack_left_shift_u16(src_p[3], 8u, 0xffu);
    dst_p->inv_reference_voltage_2_5 = (int16_t)inv_reference_voltage_2_5;
    inv_reference_voltage_5_0 = unpack_right_shift_u16(src_p[4], 0u, 0xffu);
    inv_reference_voltage_5_0 |= unpack_left_shift_u16(src_p[5], 8u, 0xffu);
    dst_p->inv_reference_voltage_5_0 = (int16_t)inv_reference_voltage_5_0;
    inv_reference_voltage_12_0 = unpack_right_shift_u16(src_p[6], 0u, 0xffu);
    inv_reference_voltage_12_0 |= unpack_left_shift_u16(src_p[7], 8u, 0xffu);
    dst_p->inv_reference_voltage_12_0 = (int16_t)inv_reference_voltage_12_0;

    return (0);
}

int feb_can_m169_internal_voltages_init(struct feb_can_m169_internal_voltages_t *msg_p)
{
    if (msg_p == NULL) return -1;

    memset(msg_p, 0, sizeof(struct feb_can_m169_internal_voltages_t));

    return 0;
}

int16_t feb_can_m169_internal_voltages_inv_reference_voltage_1_5_encode(double value)
{
    return (int16_t)(value / 0.01);
}

double feb_can_m169_internal_voltages_inv_reference_voltage_1_5_decode(int16_t value)
{
    return ((double)value * 0.01);
}

bool feb_can_m169_internal_voltages_inv_reference_voltage_1_5_is_in_range(int16_t value)
{
    (void)value;

    return (true);
}

int16_t feb_can_m169_internal_voltages_inv_reference_voltage_2_5_encode(double value)
{
    return (int16_t)(value / 0.01);
}

double feb_can_m169_internal_voltages_inv_reference_voltage_2_5_decode(int16_t value)
{
    return ((double)value * 0.01);
}

bool feb_can_m169_internal_voltages_inv_reference_voltage_2_5_is_in_range(int16_t value)
{
    (void)value;

    return (true);
}

int16_t feb_can_m169_internal_voltages_inv_reference_voltage_5_0_encode(double value)
{
    return (int16_t)(value / 0.01);
}

double feb_can_m169_internal_voltages_inv_reference_voltage_5_0_decode(int16_t value)
{
    return ((double)value * 0.01);
}

bool feb_can_m169_internal_voltages_inv_reference_voltage_5_0_is_in_range(int16_t value)
{
    (void)value;

    return (true);
}

int16_t feb_can_m169_internal_voltages_inv_reference_voltage_12_0_encode(double value)
{
    return (int16_t)(value / 0.01);
}

double feb_can_m169_internal_voltages_inv_reference_voltage_12_0_decode(int16_t value)
{
    return ((double)value * 0.01);
}

bool feb_can_m169_internal_voltages_inv_reference_voltage_12_0_is_in_range(int16_t value)
{
    (void)value;

    return (true);
}

int feb_can_m170_internal_states_pack(
    uint8_t *dst_p,
    const struct feb_can_m170_internal_states_t *src_p,
    size_t size)
{
    if (size < 8u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 8);

    dst_p[0] |= pack_left_shift_u8(src_p->inv_vsm_state, 0u, 0xffu);
    dst_p[1] |= pack_left_shift_u8(src_p->inv_pwm_frequency, 0u, 0xffu);
    dst_p[2] |= pack_left_shift_u8(src_p->inv_inverter_state, 0u, 0xffu);
    dst_p[3] |= pack_left_shift_u8(src_p->inv_relay_1_status, 0u, 0x01u);
    dst_p[3] |= pack_left_shift_u8(src_p->inv_relay_2_status, 1u, 0x02u);
    dst_p[3] |= pack_left_shift_u8(src_p->inv_relay_3_status, 2u, 0x04u);
    dst_p[3] |= pack_left_shift_u8(src_p->inv_relay_4_status, 3u, 0x08u);
    dst_p[3] |= pack_left_shift_u8(src_p->inv_relay_5_status, 4u, 0x10u);
    dst_p[3] |= pack_left_shift_u8(src_p->inv_relay_6_status, 5u, 0x20u);
    dst_p[4] |= pack_left_shift_u8(src_p->inv_inverter_run_mode, 0u, 0x01u);
    dst_p[4] |= pack_left_shift_u8(src_p->inv_inverter_discharge_state, 5u, 0xe0u);
    dst_p[5] |= pack_left_shift_u8(src_p->inv_inverter_command_mode, 0u, 0x01u);
    dst_p[5] |= pack_left_shift_u8(src_p->inv_rolling_counter, 4u, 0xf0u);
    dst_p[6] |= pack_left_shift_u8(src_p->inv_inverter_enable_state, 0u, 0x01u);
    dst_p[6] |= pack_left_shift_u8(src_p->inv_start_mode_active, 6u, 0x40u);
    dst_p[6] |= pack_left_shift_u8(src_p->inv_inverter_enable_lockout, 7u, 0x80u);
    dst_p[7] |= pack_left_shift_u8(src_p->inv_direction_command, 0u, 0x01u);
    dst_p[7] |= pack_left_shift_u8(src_p->inv_bms_active, 1u, 0x02u);
    dst_p[7] |= pack_left_shift_u8(src_p->inv_bms_torque_limiting, 2u, 0x04u);
    dst_p[7] |= pack_left_shift_u8(src_p->inv_max_speed_limiting, 3u, 0x08u);
    dst_p[7] |= pack_left_shift_u8(src_p->inv_low_speed_limiting, 5u, 0x20u);

    return (8);
}

int feb_can_m170_internal_states_unpack(
    struct feb_can_m170_internal_states_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    if (size < 8u) {
        return (-EINVAL);
    }

    dst_p->inv_vsm_state = unpack_right_shift_u8(src_p[0], 0u, 0xffu);
    dst_p->inv_pwm_frequency = unpack_right_shift_u8(src_p[1], 0u, 0xffu);
    dst_p->inv_inverter_state = unpack_right_shift_u8(src_p[2], 0u, 0xffu);
    dst_p->inv_relay_1_status = unpack_right_shift_u8(src_p[3], 0u, 0x01u);
    dst_p->inv_relay_2_status = unpack_right_shift_u8(src_p[3], 1u, 0x02u);
    dst_p->inv_relay_3_status = unpack_right_shift_u8(src_p[3], 2u, 0x04u);
    dst_p->inv_relay_4_status = unpack_right_shift_u8(src_p[3], 3u, 0x08u);
    dst_p->inv_relay_5_status = unpack_right_shift_u8(src_p[3], 4u, 0x10u);
    dst_p->inv_relay_6_status = unpack_right_shift_u8(src_p[3], 5u, 0x20u);
    dst_p->inv_inverter_run_mode = unpack_right_shift_u8(src_p[4], 0u, 0x01u);
    dst_p->inv_inverter_discharge_state = unpack_right_shift_u8(src_p[4], 5u, 0xe0u);
    dst_p->inv_inverter_command_mode = unpack_right_shift_u8(src_p[5], 0u, 0x01u);
    dst_p->inv_rolling_counter = unpack_right_shift_u8(src_p[5], 4u, 0xf0u);
    dst_p->inv_inverter_enable_state = unpack_right_shift_u8(src_p[6], 0u, 0x01u);
    dst_p->inv_start_mode_active = unpack_right_shift_u8(src_p[6], 6u, 0x40u);
    dst_p->inv_inverter_enable_lockout = unpack_right_shift_u8(src_p[6], 7u, 0x80u);
    dst_p->inv_direction_command = unpack_right_shift_u8(src_p[7], 0u, 0x01u);
    dst_p->inv_bms_active = unpack_right_shift_u8(src_p[7], 1u, 0x02u);
    dst_p->inv_bms_torque_limiting = unpack_right_shift_u8(src_p[7], 2u, 0x04u);
    dst_p->inv_max_speed_limiting = unpack_right_shift_u8(src_p[7], 3u, 0x08u);
    dst_p->inv_low_speed_limiting = unpack_right_shift_u8(src_p[7], 5u, 0x20u);

    return (0);
}

int feb_can_m170_internal_states_init(struct feb_can_m170_internal_states_t *msg_p)
{
    if (msg_p == NULL) return -1;

    memset(msg_p, 0, sizeof(struct feb_can_m170_internal_states_t));

    return 0;
}

uint8_t feb_can_m170_internal_states_inv_vsm_state_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_m170_internal_states_inv_vsm_state_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_m170_internal_states_inv_vsm_state_is_in_range(uint8_t value)
{
    return (value <= 15u);
}

uint8_t feb_can_m170_internal_states_inv_pwm_frequency_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_m170_internal_states_inv_pwm_frequency_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_m170_internal_states_inv_pwm_frequency_is_in_range(uint8_t value)
{
    (void)value;

    return (true);
}

uint8_t feb_can_m170_internal_states_inv_inverter_state_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_m170_internal_states_inv_inverter_state_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_m170_internal_states_inv_inverter_state_is_in_range(uint8_t value)
{
    (void)value;

    return (true);
}

uint8_t feb_can_m170_internal_states_inv_relay_1_status_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_m170_internal_states_inv_relay_1_status_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_m170_internal_states_inv_relay_1_status_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_m170_internal_states_inv_relay_2_status_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_m170_internal_states_inv_relay_2_status_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_m170_internal_states_inv_relay_2_status_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_m170_internal_states_inv_relay_3_status_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_m170_internal_states_inv_relay_3_status_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_m170_internal_states_inv_relay_3_status_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_m170_internal_states_inv_relay_4_status_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_m170_internal_states_inv_relay_4_status_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_m170_internal_states_inv_relay_4_status_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_m170_internal_states_inv_relay_5_status_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_m170_internal_states_inv_relay_5_status_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_m170_internal_states_inv_relay_5_status_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_m170_internal_states_inv_relay_6_status_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_m170_internal_states_inv_relay_6_status_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_m170_internal_states_inv_relay_6_status_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_m170_internal_states_inv_inverter_run_mode_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_m170_internal_states_inv_inverter_run_mode_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_m170_internal_states_inv_inverter_run_mode_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_m170_internal_states_inv_inverter_discharge_state_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_m170_internal_states_inv_inverter_discharge_state_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_m170_internal_states_inv_inverter_discharge_state_is_in_range(uint8_t value)
{
    return (value <= 7u);
}

uint8_t feb_can_m170_internal_states_inv_inverter_command_mode_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_m170_internal_states_inv_inverter_command_mode_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_m170_internal_states_inv_inverter_command_mode_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_m170_internal_states_inv_rolling_counter_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_m170_internal_states_inv_rolling_counter_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_m170_internal_states_inv_rolling_counter_is_in_range(uint8_t value)
{
    return (value <= 15u);
}

uint8_t feb_can_m170_internal_states_inv_inverter_enable_state_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_m170_internal_states_inv_inverter_enable_state_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_m170_internal_states_inv_inverter_enable_state_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_m170_internal_states_inv_start_mode_active_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_m170_internal_states_inv_start_mode_active_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_m170_internal_states_inv_start_mode_active_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_m170_internal_states_inv_inverter_enable_lockout_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_m170_internal_states_inv_inverter_enable_lockout_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_m170_internal_states_inv_inverter_enable_lockout_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_m170_internal_states_inv_direction_command_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_m170_internal_states_inv_direction_command_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_m170_internal_states_inv_direction_command_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_m170_internal_states_inv_bms_active_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_m170_internal_states_inv_bms_active_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_m170_internal_states_inv_bms_active_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_m170_internal_states_inv_bms_torque_limiting_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_m170_internal_states_inv_bms_torque_limiting_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_m170_internal_states_inv_bms_torque_limiting_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_m170_internal_states_inv_max_speed_limiting_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_m170_internal_states_inv_max_speed_limiting_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_m170_internal_states_inv_max_speed_limiting_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_m170_internal_states_inv_low_speed_limiting_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_m170_internal_states_inv_low_speed_limiting_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_m170_internal_states_inv_low_speed_limiting_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

int feb_can_m171_fault_codes_pack(
    uint8_t *dst_p,
    const struct feb_can_m171_fault_codes_t *src_p,
    size_t size)
{
    if (size < 8u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 8);

    dst_p[0] |= pack_left_shift_u16(src_p->inv_post_fault_lo, 0u, 0xffu);
    dst_p[1] |= pack_right_shift_u16(src_p->inv_post_fault_lo, 8u, 0xffu);
    dst_p[2] |= pack_left_shift_u16(src_p->inv_post_fault_hi, 0u, 0xffu);
    dst_p[3] |= pack_right_shift_u16(src_p->inv_post_fault_hi, 8u, 0xffu);
    dst_p[4] |= pack_left_shift_u16(src_p->inv_run_fault_lo, 0u, 0xffu);
    dst_p[5] |= pack_right_shift_u16(src_p->inv_run_fault_lo, 8u, 0xffu);
    dst_p[6] |= pack_left_shift_u16(src_p->inv_run_fault_hi, 0u, 0xffu);
    dst_p[7] |= pack_right_shift_u16(src_p->inv_run_fault_hi, 8u, 0xffu);

    return (8);
}

int feb_can_m171_fault_codes_unpack(
    struct feb_can_m171_fault_codes_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    if (size < 8u) {
        return (-EINVAL);
    }

    dst_p->inv_post_fault_lo = unpack_right_shift_u16(src_p[0], 0u, 0xffu);
    dst_p->inv_post_fault_lo |= unpack_left_shift_u16(src_p[1], 8u, 0xffu);
    dst_p->inv_post_fault_hi = unpack_right_shift_u16(src_p[2], 0u, 0xffu);
    dst_p->inv_post_fault_hi |= unpack_left_shift_u16(src_p[3], 8u, 0xffu);
    dst_p->inv_run_fault_lo = unpack_right_shift_u16(src_p[4], 0u, 0xffu);
    dst_p->inv_run_fault_lo |= unpack_left_shift_u16(src_p[5], 8u, 0xffu);
    dst_p->inv_run_fault_hi = unpack_right_shift_u16(src_p[6], 0u, 0xffu);
    dst_p->inv_run_fault_hi |= unpack_left_shift_u16(src_p[7], 8u, 0xffu);

    return (0);
}

int feb_can_m171_fault_codes_init(struct feb_can_m171_fault_codes_t *msg_p)
{
    if (msg_p == NULL) return -1;

    memset(msg_p, 0, sizeof(struct feb_can_m171_fault_codes_t));

    return 0;
}

uint16_t feb_can_m171_fault_codes_inv_post_fault_lo_encode(double value)
{
    return (uint16_t)(value);
}

double feb_can_m171_fault_codes_inv_post_fault_lo_decode(uint16_t value)
{
    return ((double)value);
}

bool feb_can_m171_fault_codes_inv_post_fault_lo_is_in_range(uint16_t value)
{
    (void)value;

    return (true);
}

uint16_t feb_can_m171_fault_codes_inv_post_fault_hi_encode(double value)
{
    return (uint16_t)(value);
}

double feb_can_m171_fault_codes_inv_post_fault_hi_decode(uint16_t value)
{
    return ((double)value);
}

bool feb_can_m171_fault_codes_inv_post_fault_hi_is_in_range(uint16_t value)
{
    (void)value;

    return (true);
}

uint16_t feb_can_m171_fault_codes_inv_run_fault_lo_encode(double value)
{
    return (uint16_t)(value);
}

double feb_can_m171_fault_codes_inv_run_fault_lo_decode(uint16_t value)
{
    return ((double)value);
}

bool feb_can_m171_fault_codes_inv_run_fault_lo_is_in_range(uint16_t value)
{
    (void)value;

    return (true);
}

uint16_t feb_can_m171_fault_codes_inv_run_fault_hi_encode(double value)
{
    return (uint16_t)(value);
}

double feb_can_m171_fault_codes_inv_run_fault_hi_decode(uint16_t value)
{
    return ((double)value);
}

bool feb_can_m171_fault_codes_inv_run_fault_hi_is_in_range(uint16_t value)
{
    (void)value;

    return (true);
}

int feb_can_m172_torque_and_timer_info_pack(
    uint8_t *dst_p,
    const struct feb_can_m172_torque_and_timer_info_t *src_p,
    size_t size)
{
    uint16_t inv_commanded_torque;
    uint16_t inv_torque_feedback;

    if (size < 8u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 8);

    inv_commanded_torque = (uint16_t)src_p->inv_commanded_torque;
    dst_p[0] |= pack_left_shift_u16(inv_commanded_torque, 0u, 0xffu);
    dst_p[1] |= pack_right_shift_u16(inv_commanded_torque, 8u, 0xffu);
    inv_torque_feedback = (uint16_t)src_p->inv_torque_feedback;
    dst_p[2] |= pack_left_shift_u16(inv_torque_feedback, 0u, 0xffu);
    dst_p[3] |= pack_right_shift_u16(inv_torque_feedback, 8u, 0xffu);
    dst_p[4] |= pack_left_shift_u32(src_p->inv_power_on_timer, 0u, 0xffu);
    dst_p[5] |= pack_right_shift_u32(src_p->inv_power_on_timer, 8u, 0xffu);
    dst_p[6] |= pack_right_shift_u32(src_p->inv_power_on_timer, 16u, 0xffu);
    dst_p[7] |= pack_right_shift_u32(src_p->inv_power_on_timer, 24u, 0xffu);

    return (8);
}

int feb_can_m172_torque_and_timer_info_unpack(
    struct feb_can_m172_torque_and_timer_info_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    uint16_t inv_commanded_torque;
    uint16_t inv_torque_feedback;

    if (size < 8u) {
        return (-EINVAL);
    }

    inv_commanded_torque = unpack_right_shift_u16(src_p[0], 0u, 0xffu);
    inv_commanded_torque |= unpack_left_shift_u16(src_p[1], 8u, 0xffu);
    dst_p->inv_commanded_torque = (int16_t)inv_commanded_torque;
    inv_torque_feedback = unpack_right_shift_u16(src_p[2], 0u, 0xffu);
    inv_torque_feedback |= unpack_left_shift_u16(src_p[3], 8u, 0xffu);
    dst_p->inv_torque_feedback = (int16_t)inv_torque_feedback;
    dst_p->inv_power_on_timer = unpack_right_shift_u32(src_p[4], 0u, 0xffu);
    dst_p->inv_power_on_timer |= unpack_left_shift_u32(src_p[5], 8u, 0xffu);
    dst_p->inv_power_on_timer |= unpack_left_shift_u32(src_p[6], 16u, 0xffu);
    dst_p->inv_power_on_timer |= unpack_left_shift_u32(src_p[7], 24u, 0xffu);

    return (0);
}

int feb_can_m172_torque_and_timer_info_init(struct feb_can_m172_torque_and_timer_info_t *msg_p)
{
    if (msg_p == NULL) return -1;

    memset(msg_p, 0, sizeof(struct feb_can_m172_torque_and_timer_info_t));

    return 0;
}

int16_t feb_can_m172_torque_and_timer_info_inv_commanded_torque_encode(double value)
{
    return (int16_t)(value / 0.1);
}

double feb_can_m172_torque_and_timer_info_inv_commanded_torque_decode(int16_t value)
{
    return ((double)value * 0.1);
}

bool feb_can_m172_torque_and_timer_info_inv_commanded_torque_is_in_range(int16_t value)
{
    (void)value;

    return (true);
}

int16_t feb_can_m172_torque_and_timer_info_inv_torque_feedback_encode(double value)
{
    return (int16_t)(value / 0.1);
}

double feb_can_m172_torque_and_timer_info_inv_torque_feedback_decode(int16_t value)
{
    return ((double)value * 0.1);
}

bool feb_can_m172_torque_and_timer_info_inv_torque_feedback_is_in_range(int16_t value)
{
    (void)value;

    return (true);
}

uint32_t feb_can_m172_torque_and_timer_info_inv_power_on_timer_encode(double value)
{
    return (uint32_t)(value / 0.003);
}

double feb_can_m172_torque_and_timer_info_inv_power_on_timer_decode(uint32_t value)
{
    return ((double)value * 0.003);
}

bool feb_can_m172_torque_and_timer_info_inv_power_on_timer_is_in_range(uint32_t value)
{
    return (value <= 4294933333u);
}

int feb_can_m173_modulation_and_flux_info_pack(
    uint8_t *dst_p,
    const struct feb_can_m173_modulation_and_flux_info_t *src_p,
    size_t size)
{
    uint16_t inv_flux_weakening_output;
    uint16_t inv_id_command;
    uint16_t inv_iq_command;
    uint16_t inv_modulation_index;

    if (size < 8u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 8);

    inv_modulation_index = (uint16_t)src_p->inv_modulation_index;
    dst_p[0] |= pack_left_shift_u16(inv_modulation_index, 0u, 0xffu);
    dst_p[1] |= pack_right_shift_u16(inv_modulation_index, 8u, 0xffu);
    inv_flux_weakening_output = (uint16_t)src_p->inv_flux_weakening_output;
    dst_p[2] |= pack_left_shift_u16(inv_flux_weakening_output, 0u, 0xffu);
    dst_p[3] |= pack_right_shift_u16(inv_flux_weakening_output, 8u, 0xffu);
    inv_id_command = (uint16_t)src_p->inv_id_command;
    dst_p[4] |= pack_left_shift_u16(inv_id_command, 0u, 0xffu);
    dst_p[5] |= pack_right_shift_u16(inv_id_command, 8u, 0xffu);
    inv_iq_command = (uint16_t)src_p->inv_iq_command;
    dst_p[6] |= pack_left_shift_u16(inv_iq_command, 0u, 0xffu);
    dst_p[7] |= pack_right_shift_u16(inv_iq_command, 8u, 0xffu);

    return (8);
}

int feb_can_m173_modulation_and_flux_info_unpack(
    struct feb_can_m173_modulation_and_flux_info_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    uint16_t inv_flux_weakening_output;
    uint16_t inv_id_command;
    uint16_t inv_iq_command;
    uint16_t inv_modulation_index;

    if (size < 8u) {
        return (-EINVAL);
    }

    inv_modulation_index = unpack_right_shift_u16(src_p[0], 0u, 0xffu);
    inv_modulation_index |= unpack_left_shift_u16(src_p[1], 8u, 0xffu);
    dst_p->inv_modulation_index = (int16_t)inv_modulation_index;
    inv_flux_weakening_output = unpack_right_shift_u16(src_p[2], 0u, 0xffu);
    inv_flux_weakening_output |= unpack_left_shift_u16(src_p[3], 8u, 0xffu);
    dst_p->inv_flux_weakening_output = (int16_t)inv_flux_weakening_output;
    inv_id_command = unpack_right_shift_u16(src_p[4], 0u, 0xffu);
    inv_id_command |= unpack_left_shift_u16(src_p[5], 8u, 0xffu);
    dst_p->inv_id_command = (int16_t)inv_id_command;
    inv_iq_command = unpack_right_shift_u16(src_p[6], 0u, 0xffu);
    inv_iq_command |= unpack_left_shift_u16(src_p[7], 8u, 0xffu);
    dst_p->inv_iq_command = (int16_t)inv_iq_command;

    return (0);
}

int feb_can_m173_modulation_and_flux_info_init(struct feb_can_m173_modulation_and_flux_info_t *msg_p)
{
    if (msg_p == NULL) return -1;

    memset(msg_p, 0, sizeof(struct feb_can_m173_modulation_and_flux_info_t));

    return 0;
}

int16_t feb_can_m173_modulation_and_flux_info_inv_modulation_index_encode(double value)
{
    return (int16_t)(value / 0.0001);
}

double feb_can_m173_modulation_and_flux_info_inv_modulation_index_decode(int16_t value)
{
    return ((double)value * 0.0001);
}

bool feb_can_m173_modulation_and_flux_info_inv_modulation_index_is_in_range(int16_t value)
{
    return (value >= 0);
}

int16_t feb_can_m173_modulation_and_flux_info_inv_flux_weakening_output_encode(double value)
{
    return (int16_t)(value / 0.1);
}

double feb_can_m173_modulation_and_flux_info_inv_flux_weakening_output_decode(int16_t value)
{
    return ((double)value * 0.1);
}

bool feb_can_m173_modulation_and_flux_info_inv_flux_weakening_output_is_in_range(int16_t value)
{
    (void)value;

    return (true);
}

int16_t feb_can_m173_modulation_and_flux_info_inv_id_command_encode(double value)
{
    return (int16_t)(value / 0.1);
}

double feb_can_m173_modulation_and_flux_info_inv_id_command_decode(int16_t value)
{
    return ((double)value * 0.1);
}

bool feb_can_m173_modulation_and_flux_info_inv_id_command_is_in_range(int16_t value)
{
    (void)value;

    return (true);
}

int16_t feb_can_m173_modulation_and_flux_info_inv_iq_command_encode(double value)
{
    return (int16_t)(value / 0.1);
}

double feb_can_m173_modulation_and_flux_info_inv_iq_command_decode(int16_t value)
{
    return ((double)value * 0.1);
}

bool feb_can_m173_modulation_and_flux_info_inv_iq_command_is_in_range(int16_t value)
{
    (void)value;

    return (true);
}

int feb_can_m174_firmware_info_pack(
    uint8_t *dst_p,
    const struct feb_can_m174_firmware_info_t *src_p,
    size_t size)
{
    if (size < 8u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 8);

    dst_p[0] |= pack_left_shift_u16(src_p->inv_project_code_eep_ver, 0u, 0xffu);
    dst_p[1] |= pack_right_shift_u16(src_p->inv_project_code_eep_ver, 8u, 0xffu);
    dst_p[2] |= pack_left_shift_u16(src_p->inv_sw_version, 0u, 0xffu);
    dst_p[3] |= pack_right_shift_u16(src_p->inv_sw_version, 8u, 0xffu);
    dst_p[4] |= pack_left_shift_u16(src_p->inv_date_code_mmdd, 0u, 0xffu);
    dst_p[5] |= pack_right_shift_u16(src_p->inv_date_code_mmdd, 8u, 0xffu);
    dst_p[6] |= pack_left_shift_u16(src_p->inv_date_code_yyyy, 0u, 0xffu);
    dst_p[7] |= pack_right_shift_u16(src_p->inv_date_code_yyyy, 8u, 0xffu);

    return (8);
}

int feb_can_m174_firmware_info_unpack(
    struct feb_can_m174_firmware_info_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    if (size < 8u) {
        return (-EINVAL);
    }

    dst_p->inv_project_code_eep_ver = unpack_right_shift_u16(src_p[0], 0u, 0xffu);
    dst_p->inv_project_code_eep_ver |= unpack_left_shift_u16(src_p[1], 8u, 0xffu);
    dst_p->inv_sw_version = unpack_right_shift_u16(src_p[2], 0u, 0xffu);
    dst_p->inv_sw_version |= unpack_left_shift_u16(src_p[3], 8u, 0xffu);
    dst_p->inv_date_code_mmdd = unpack_right_shift_u16(src_p[4], 0u, 0xffu);
    dst_p->inv_date_code_mmdd |= unpack_left_shift_u16(src_p[5], 8u, 0xffu);
    dst_p->inv_date_code_yyyy = unpack_right_shift_u16(src_p[6], 0u, 0xffu);
    dst_p->inv_date_code_yyyy |= unpack_left_shift_u16(src_p[7], 8u, 0xffu);

    return (0);
}

int feb_can_m174_firmware_info_init(struct feb_can_m174_firmware_info_t *msg_p)
{
    if (msg_p == NULL) return -1;

    memset(msg_p, 0, sizeof(struct feb_can_m174_firmware_info_t));

    return 0;
}

uint16_t feb_can_m174_firmware_info_inv_project_code_eep_ver_encode(double value)
{
    return (uint16_t)(value);
}

double feb_can_m174_firmware_info_inv_project_code_eep_ver_decode(uint16_t value)
{
    return ((double)value);
}

bool feb_can_m174_firmware_info_inv_project_code_eep_ver_is_in_range(uint16_t value)
{
    (void)value;

    return (true);
}

uint16_t feb_can_m174_firmware_info_inv_sw_version_encode(double value)
{
    return (uint16_t)(value);
}

double feb_can_m174_firmware_info_inv_sw_version_decode(uint16_t value)
{
    return ((double)value);
}

bool feb_can_m174_firmware_info_inv_sw_version_is_in_range(uint16_t value)
{
    (void)value;

    return (true);
}

uint16_t feb_can_m174_firmware_info_inv_date_code_mmdd_encode(double value)
{
    return (uint16_t)(value);
}

double feb_can_m174_firmware_info_inv_date_code_mmdd_decode(uint16_t value)
{
    return ((double)value);
}

bool feb_can_m174_firmware_info_inv_date_code_mmdd_is_in_range(uint16_t value)
{
    (void)value;

    return (true);
}

uint16_t feb_can_m174_firmware_info_inv_date_code_yyyy_encode(double value)
{
    return (uint16_t)(value);
}

double feb_can_m174_firmware_info_inv_date_code_yyyy_decode(uint16_t value)
{
    return ((double)value);
}

bool feb_can_m174_firmware_info_inv_date_code_yyyy_is_in_range(uint16_t value)
{
    (void)value;

    return (true);
}

int feb_can_m175_diag_data_message_pack(
    uint8_t *dst_p,
    const struct feb_can_m175_diag_data_message_t *src_p,
    size_t size)
{
    uint16_t inv_diag_cos;
    uint16_t inv_diag_fw_output;
    uint16_t inv_diag_gamma_observer;
    uint16_t inv_diag_gamma_resolver;
    uint16_t inv_diag_ia;
    uint16_t inv_diag_ib;
    uint16_t inv_diag_ic;
    uint16_t inv_diag_id_cmd;
    uint16_t inv_diag_iq_cmd;
    uint16_t inv_diag_mod_index;
    uint16_t inv_diag_sin;
    uint16_t inv_diag_vd_cmd;
    uint16_t inv_diag_vdc;
    uint16_t inv_diag_vq_cmd;
    uint16_t inv_diag_vqs_cmd;

    if (size < 8u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 8);

    dst_p[0] |= pack_left_shift_u8(src_p->inv_diag_record, 0u, 0xffu);
    dst_p[1] |= pack_left_shift_u8(src_p->inv_diag_segment, 0u, 0xffu);

    switch (src_p->inv_diag_segment) {

    case 0:
        inv_diag_gamma_resolver = (uint16_t)src_p->inv_diag_gamma_resolver;
        dst_p[2] |= pack_left_shift_u16(inv_diag_gamma_resolver, 0u, 0xffu);
        dst_p[3] |= pack_right_shift_u16(inv_diag_gamma_resolver, 8u, 0xffu);
        inv_diag_gamma_observer = (uint16_t)src_p->inv_diag_gamma_observer;
        dst_p[4] |= pack_left_shift_u16(inv_diag_gamma_observer, 0u, 0xffu);
        dst_p[5] |= pack_right_shift_u16(inv_diag_gamma_observer, 8u, 0xffu);
        inv_diag_sin = (uint16_t)src_p->inv_diag_sin;
        dst_p[6] |= pack_left_shift_u16(inv_diag_sin, 0u, 0xffu);
        dst_p[7] |= pack_right_shift_u16(inv_diag_sin, 8u, 0xffu);
        break;

    case 1:
        inv_diag_cos = (uint16_t)src_p->inv_diag_cos;
        dst_p[2] |= pack_left_shift_u16(inv_diag_cos, 0u, 0xffu);
        dst_p[3] |= pack_right_shift_u16(inv_diag_cos, 8u, 0xffu);
        inv_diag_ia = (uint16_t)src_p->inv_diag_ia;
        dst_p[4] |= pack_left_shift_u16(inv_diag_ia, 0u, 0xffu);
        dst_p[5] |= pack_right_shift_u16(inv_diag_ia, 8u, 0xffu);
        inv_diag_ib = (uint16_t)src_p->inv_diag_ib;
        dst_p[6] |= pack_left_shift_u16(inv_diag_ib, 0u, 0xffu);
        dst_p[7] |= pack_right_shift_u16(inv_diag_ib, 8u, 0xffu);
        break;

    case 2:
        inv_diag_ic = (uint16_t)src_p->inv_diag_ic;
        dst_p[2] |= pack_left_shift_u16(inv_diag_ic, 0u, 0xffu);
        dst_p[3] |= pack_right_shift_u16(inv_diag_ic, 8u, 0xffu);
        inv_diag_vdc = (uint16_t)src_p->inv_diag_vdc;
        dst_p[4] |= pack_left_shift_u16(inv_diag_vdc, 0u, 0xffu);
        dst_p[5] |= pack_right_shift_u16(inv_diag_vdc, 8u, 0xffu);
        inv_diag_iq_cmd = (uint16_t)src_p->inv_diag_iq_cmd;
        dst_p[6] |= pack_left_shift_u16(inv_diag_iq_cmd, 0u, 0xffu);
        dst_p[7] |= pack_right_shift_u16(inv_diag_iq_cmd, 8u, 0xffu);
        break;

    case 3:
        inv_diag_id_cmd = (uint16_t)src_p->inv_diag_id_cmd;
        dst_p[2] |= pack_left_shift_u16(inv_diag_id_cmd, 0u, 0xffu);
        dst_p[3] |= pack_right_shift_u16(inv_diag_id_cmd, 8u, 0xffu);
        inv_diag_mod_index = (uint16_t)src_p->inv_diag_mod_index;
        dst_p[4] |= pack_left_shift_u16(inv_diag_mod_index, 0u, 0xffu);
        dst_p[5] |= pack_right_shift_u16(inv_diag_mod_index, 8u, 0xffu);
        inv_diag_fw_output = (uint16_t)src_p->inv_diag_fw_output;
        dst_p[6] |= pack_left_shift_u16(inv_diag_fw_output, 0u, 0xffu);
        dst_p[7] |= pack_right_shift_u16(inv_diag_fw_output, 8u, 0xffu);
        break;

    case 4:
        inv_diag_vq_cmd = (uint16_t)src_p->inv_diag_vq_cmd;
        dst_p[2] |= pack_left_shift_u16(inv_diag_vq_cmd, 0u, 0xffu);
        dst_p[3] |= pack_right_shift_u16(inv_diag_vq_cmd, 8u, 0xffu);
        inv_diag_vd_cmd = (uint16_t)src_p->inv_diag_vd_cmd;
        dst_p[4] |= pack_left_shift_u16(inv_diag_vd_cmd, 0u, 0xffu);
        dst_p[5] |= pack_right_shift_u16(inv_diag_vd_cmd, 8u, 0xffu);
        inv_diag_vqs_cmd = (uint16_t)src_p->inv_diag_vqs_cmd;
        dst_p[6] |= pack_left_shift_u16(inv_diag_vqs_cmd, 0u, 0xffu);
        dst_p[7] |= pack_right_shift_u16(inv_diag_vqs_cmd, 8u, 0xffu);
        break;

    case 5:
        dst_p[2] |= pack_left_shift_u16(src_p->inv_diag_12_v, 0u, 0xffu);
        dst_p[3] |= pack_right_shift_u16(src_p->inv_diag_12_v, 8u, 0xffu);
        dst_p[4] |= pack_left_shift_u16(src_p->inv_diag_run_faults_lo, 0u, 0xffu);
        dst_p[5] |= pack_right_shift_u16(src_p->inv_diag_run_faults_lo, 8u, 0xffu);
        dst_p[6] |= pack_left_shift_u16(src_p->inv_diag_run_faults_hi, 0u, 0xffu);
        dst_p[7] |= pack_right_shift_u16(src_p->inv_diag_run_faults_hi, 8u, 0xffu);
        break;

    default:
        break;
    }

    return (8);
}

int feb_can_m175_diag_data_message_unpack(
    struct feb_can_m175_diag_data_message_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    uint16_t inv_diag_cos;
    uint16_t inv_diag_fw_output;
    uint16_t inv_diag_gamma_observer;
    uint16_t inv_diag_gamma_resolver;
    uint16_t inv_diag_ia;
    uint16_t inv_diag_ib;
    uint16_t inv_diag_ic;
    uint16_t inv_diag_id_cmd;
    uint16_t inv_diag_iq_cmd;
    uint16_t inv_diag_mod_index;
    uint16_t inv_diag_sin;
    uint16_t inv_diag_vd_cmd;
    uint16_t inv_diag_vdc;
    uint16_t inv_diag_vq_cmd;
    uint16_t inv_diag_vqs_cmd;

    if (size < 8u) {
        return (-EINVAL);
    }

    dst_p->inv_diag_record = unpack_right_shift_u8(src_p[0], 0u, 0xffu);
    dst_p->inv_diag_segment = unpack_right_shift_u8(src_p[1], 0u, 0xffu);

    switch (dst_p->inv_diag_segment) {

    case 0:
        inv_diag_gamma_resolver = unpack_right_shift_u16(src_p[2], 0u, 0xffu);
        inv_diag_gamma_resolver |= unpack_left_shift_u16(src_p[3], 8u, 0xffu);
        dst_p->inv_diag_gamma_resolver = (int16_t)inv_diag_gamma_resolver;
        inv_diag_gamma_observer = unpack_right_shift_u16(src_p[4], 0u, 0xffu);
        inv_diag_gamma_observer |= unpack_left_shift_u16(src_p[5], 8u, 0xffu);
        dst_p->inv_diag_gamma_observer = (int16_t)inv_diag_gamma_observer;
        inv_diag_sin = unpack_right_shift_u16(src_p[6], 0u, 0xffu);
        inv_diag_sin |= unpack_left_shift_u16(src_p[7], 8u, 0xffu);
        dst_p->inv_diag_sin = (int16_t)inv_diag_sin;
        break;

    case 1:
        inv_diag_cos = unpack_right_shift_u16(src_p[2], 0u, 0xffu);
        inv_diag_cos |= unpack_left_shift_u16(src_p[3], 8u, 0xffu);
        dst_p->inv_diag_cos = (int16_t)inv_diag_cos;
        inv_diag_ia = unpack_right_shift_u16(src_p[4], 0u, 0xffu);
        inv_diag_ia |= unpack_left_shift_u16(src_p[5], 8u, 0xffu);
        dst_p->inv_diag_ia = (int16_t)inv_diag_ia;
        inv_diag_ib = unpack_right_shift_u16(src_p[6], 0u, 0xffu);
        inv_diag_ib |= unpack_left_shift_u16(src_p[7], 8u, 0xffu);
        dst_p->inv_diag_ib = (int16_t)inv_diag_ib;
        break;

    case 2:
        inv_diag_ic = unpack_right_shift_u16(src_p[2], 0u, 0xffu);
        inv_diag_ic |= unpack_left_shift_u16(src_p[3], 8u, 0xffu);
        dst_p->inv_diag_ic = (int16_t)inv_diag_ic;
        inv_diag_vdc = unpack_right_shift_u16(src_p[4], 0u, 0xffu);
        inv_diag_vdc |= unpack_left_shift_u16(src_p[5], 8u, 0xffu);
        dst_p->inv_diag_vdc = (int16_t)inv_diag_vdc;
        inv_diag_iq_cmd = unpack_right_shift_u16(src_p[6], 0u, 0xffu);
        inv_diag_iq_cmd |= unpack_left_shift_u16(src_p[7], 8u, 0xffu);
        dst_p->inv_diag_iq_cmd = (int16_t)inv_diag_iq_cmd;
        break;

    case 3:
        inv_diag_id_cmd = unpack_right_shift_u16(src_p[2], 0u, 0xffu);
        inv_diag_id_cmd |= unpack_left_shift_u16(src_p[3], 8u, 0xffu);
        dst_p->inv_diag_id_cmd = (int16_t)inv_diag_id_cmd;
        inv_diag_mod_index = unpack_right_shift_u16(src_p[4], 0u, 0xffu);
        inv_diag_mod_index |= unpack_left_shift_u16(src_p[5], 8u, 0xffu);
        dst_p->inv_diag_mod_index = (int16_t)inv_diag_mod_index;
        inv_diag_fw_output = unpack_right_shift_u16(src_p[6], 0u, 0xffu);
        inv_diag_fw_output |= unpack_left_shift_u16(src_p[7], 8u, 0xffu);
        dst_p->inv_diag_fw_output = (int16_t)inv_diag_fw_output;
        break;

    case 4:
        inv_diag_vq_cmd = unpack_right_shift_u16(src_p[2], 0u, 0xffu);
        inv_diag_vq_cmd |= unpack_left_shift_u16(src_p[3], 8u, 0xffu);
        dst_p->inv_diag_vq_cmd = (int16_t)inv_diag_vq_cmd;
        inv_diag_vd_cmd = unpack_right_shift_u16(src_p[4], 0u, 0xffu);
        inv_diag_vd_cmd |= unpack_left_shift_u16(src_p[5], 8u, 0xffu);
        dst_p->inv_diag_vd_cmd = (int16_t)inv_diag_vd_cmd;
        inv_diag_vqs_cmd = unpack_right_shift_u16(src_p[6], 0u, 0xffu);
        inv_diag_vqs_cmd |= unpack_left_shift_u16(src_p[7], 8u, 0xffu);
        dst_p->inv_diag_vqs_cmd = (int16_t)inv_diag_vqs_cmd;
        break;

    case 5:
        dst_p->inv_diag_12_v = unpack_right_shift_u16(src_p[2], 0u, 0xffu);
        dst_p->inv_diag_12_v |= unpack_left_shift_u16(src_p[3], 8u, 0xffu);
        dst_p->inv_diag_run_faults_lo = unpack_right_shift_u16(src_p[4], 0u, 0xffu);
        dst_p->inv_diag_run_faults_lo |= unpack_left_shift_u16(src_p[5], 8u, 0xffu);
        dst_p->inv_diag_run_faults_hi = unpack_right_shift_u16(src_p[6], 0u, 0xffu);
        dst_p->inv_diag_run_faults_hi |= unpack_left_shift_u16(src_p[7], 8u, 0xffu);
        break;

    default:
        break;
    }

    return (0);
}

int feb_can_m175_diag_data_message_init(struct feb_can_m175_diag_data_message_t *msg_p)
{
    if (msg_p == NULL) return -1;

    memset(msg_p, 0, sizeof(struct feb_can_m175_diag_data_message_t));

    return 0;
}

uint8_t feb_can_m175_diag_data_message_inv_diag_record_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_m175_diag_data_message_inv_diag_record_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_m175_diag_data_message_inv_diag_record_is_in_range(uint8_t value)
{
    return (value <= 160u);
}

uint8_t feb_can_m175_diag_data_message_inv_diag_segment_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_m175_diag_data_message_inv_diag_segment_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_m175_diag_data_message_inv_diag_segment_is_in_range(uint8_t value)
{
    return (value <= 5u);
}

uint16_t feb_can_m175_diag_data_message_inv_diag_12_v_encode(double value)
{
    return (uint16_t)(value / 0.01);
}

double feb_can_m175_diag_data_message_inv_diag_12_v_decode(uint16_t value)
{
    return ((double)value * 0.01);
}

bool feb_can_m175_diag_data_message_inv_diag_12_v_is_in_range(uint16_t value)
{
    return (value <= 3600u);
}

int16_t feb_can_m175_diag_data_message_inv_diag_vq_cmd_encode(double value)
{
    return (int16_t)(value / 0.1);
}

double feb_can_m175_diag_data_message_inv_diag_vq_cmd_decode(int16_t value)
{
    return ((double)value * 0.1);
}

bool feb_can_m175_diag_data_message_inv_diag_vq_cmd_is_in_range(int16_t value)
{
    return ((value >= -10000) && (value <= 10000));
}

int16_t feb_can_m175_diag_data_message_inv_diag_id_cmd_encode(double value)
{
    return (int16_t)(value / 0.1);
}

double feb_can_m175_diag_data_message_inv_diag_id_cmd_decode(int16_t value)
{
    return ((double)value * 0.1);
}

bool feb_can_m175_diag_data_message_inv_diag_id_cmd_is_in_range(int16_t value)
{
    return ((value >= -20000) && (value <= 20000));
}

int16_t feb_can_m175_diag_data_message_inv_diag_ic_encode(double value)
{
    return (int16_t)(value / 0.1);
}

double feb_can_m175_diag_data_message_inv_diag_ic_decode(int16_t value)
{
    return ((double)value * 0.1);
}

bool feb_can_m175_diag_data_message_inv_diag_ic_is_in_range(int16_t value)
{
    return ((value >= -20000) && (value <= 20000));
}

int16_t feb_can_m175_diag_data_message_inv_diag_cos_encode(double value)
{
    return (int16_t)(value);
}

double feb_can_m175_diag_data_message_inv_diag_cos_decode(int16_t value)
{
    return ((double)value);
}

bool feb_can_m175_diag_data_message_inv_diag_cos_is_in_range(int16_t value)
{
    return ((value >= -5) && (value <= 5));
}

int16_t feb_can_m175_diag_data_message_inv_diag_gamma_resolver_encode(double value)
{
    return (int16_t)(value / 0.1);
}

double feb_can_m175_diag_data_message_inv_diag_gamma_resolver_decode(int16_t value)
{
    return ((double)value * 0.1);
}

bool feb_can_m175_diag_data_message_inv_diag_gamma_resolver_is_in_range(int16_t value)
{
    return ((value >= 0) && (value <= 3600));
}

uint16_t feb_can_m175_diag_data_message_inv_diag_run_faults_lo_encode(double value)
{
    return (uint16_t)(value);
}

double feb_can_m175_diag_data_message_inv_diag_run_faults_lo_decode(uint16_t value)
{
    return ((double)value);
}

bool feb_can_m175_diag_data_message_inv_diag_run_faults_lo_is_in_range(uint16_t value)
{
    (void)value;

    return (true);
}

int16_t feb_can_m175_diag_data_message_inv_diag_vd_cmd_encode(double value)
{
    return (int16_t)(value / 0.1);
}

double feb_can_m175_diag_data_message_inv_diag_vd_cmd_decode(int16_t value)
{
    return ((double)value * 0.1);
}

bool feb_can_m175_diag_data_message_inv_diag_vd_cmd_is_in_range(int16_t value)
{
    return ((value >= -10000) && (value <= 10000));
}

int16_t feb_can_m175_diag_data_message_inv_diag_mod_index_encode(double value)
{
    return (int16_t)(value / 0.0001);
}

double feb_can_m175_diag_data_message_inv_diag_mod_index_decode(int16_t value)
{
    return ((double)value * 0.0001);
}

bool feb_can_m175_diag_data_message_inv_diag_mod_index_is_in_range(int16_t value)
{
    return ((value >= 0) && (value <= 20000));
}

int16_t feb_can_m175_diag_data_message_inv_diag_vdc_encode(double value)
{
    return (int16_t)(value / 0.1);
}

double feb_can_m175_diag_data_message_inv_diag_vdc_decode(int16_t value)
{
    return ((double)value * 0.1);
}

bool feb_can_m175_diag_data_message_inv_diag_vdc_is_in_range(int16_t value)
{
    return ((value >= 0) && (value <= 10000));
}

int16_t feb_can_m175_diag_data_message_inv_diag_ia_encode(double value)
{
    return (int16_t)(value / 0.1);
}

double feb_can_m175_diag_data_message_inv_diag_ia_decode(int16_t value)
{
    return ((double)value * 0.1);
}

bool feb_can_m175_diag_data_message_inv_diag_ia_is_in_range(int16_t value)
{
    return ((value >= -20000) && (value <= 20000));
}

int16_t feb_can_m175_diag_data_message_inv_diag_gamma_observer_encode(double value)
{
    return (int16_t)(value / 0.1);
}

double feb_can_m175_diag_data_message_inv_diag_gamma_observer_decode(int16_t value)
{
    return ((double)value * 0.1);
}

bool feb_can_m175_diag_data_message_inv_diag_gamma_observer_is_in_range(int16_t value)
{
    return ((value >= 0) && (value <= 3600));
}

uint16_t feb_can_m175_diag_data_message_inv_diag_run_faults_hi_encode(double value)
{
    return (uint16_t)(value);
}

double feb_can_m175_diag_data_message_inv_diag_run_faults_hi_decode(uint16_t value)
{
    return ((double)value);
}

bool feb_can_m175_diag_data_message_inv_diag_run_faults_hi_is_in_range(uint16_t value)
{
    (void)value;

    return (true);
}

int16_t feb_can_m175_diag_data_message_inv_diag_vqs_cmd_encode(double value)
{
    return (int16_t)(value / 0.1);
}

double feb_can_m175_diag_data_message_inv_diag_vqs_cmd_decode(int16_t value)
{
    return ((double)value * 0.1);
}

bool feb_can_m175_diag_data_message_inv_diag_vqs_cmd_is_in_range(int16_t value)
{
    return ((value >= -10000) && (value <= 10000));
}

int16_t feb_can_m175_diag_data_message_inv_diag_fw_output_encode(double value)
{
    return (int16_t)(value / 0.1);
}

double feb_can_m175_diag_data_message_inv_diag_fw_output_decode(int16_t value)
{
    return ((double)value * 0.1);
}

bool feb_can_m175_diag_data_message_inv_diag_fw_output_is_in_range(int16_t value)
{
    return ((value >= -20000) && (value <= 20000));
}

int16_t feb_can_m175_diag_data_message_inv_diag_iq_cmd_encode(double value)
{
    return (int16_t)(value / 0.1);
}

double feb_can_m175_diag_data_message_inv_diag_iq_cmd_decode(int16_t value)
{
    return ((double)value * 0.1);
}

bool feb_can_m175_diag_data_message_inv_diag_iq_cmd_is_in_range(int16_t value)
{
    return ((value >= -20000) && (value <= 20000));
}

int16_t feb_can_m175_diag_data_message_inv_diag_ib_encode(double value)
{
    return (int16_t)(value / 0.1);
}

double feb_can_m175_diag_data_message_inv_diag_ib_decode(int16_t value)
{
    return ((double)value * 0.1);
}

bool feb_can_m175_diag_data_message_inv_diag_ib_is_in_range(int16_t value)
{
    return ((value >= -20000) && (value <= 20000));
}

int16_t feb_can_m175_diag_data_message_inv_diag_sin_encode(double value)
{
    return (int16_t)(value);
}

double feb_can_m175_diag_data_message_inv_diag_sin_decode(int16_t value)
{
    return ((double)value);
}

bool feb_can_m175_diag_data_message_inv_diag_sin_is_in_range(int16_t value)
{
    return ((value >= -5) && (value <= 5));
}

int feb_can_m176_fast_info_pack(
    uint8_t *dst_p,
    const struct feb_can_m176_fast_info_t *src_p,
    size_t size)
{
    uint16_t inv_fast_dc_bus_voltage;
    uint16_t inv_fast_motor_speed;
    uint16_t inv_fast_torque_command;
    uint16_t inv_fast_torque_feedback;

    if (size < 8u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 8);

    inv_fast_torque_command = (uint16_t)src_p->inv_fast_torque_command;
    dst_p[0] |= pack_left_shift_u16(inv_fast_torque_command, 0u, 0xffu);
    dst_p[1] |= pack_right_shift_u16(inv_fast_torque_command, 8u, 0xffu);
    inv_fast_torque_feedback = (uint16_t)src_p->inv_fast_torque_feedback;
    dst_p[2] |= pack_left_shift_u16(inv_fast_torque_feedback, 0u, 0xffu);
    dst_p[3] |= pack_right_shift_u16(inv_fast_torque_feedback, 8u, 0xffu);
    inv_fast_motor_speed = (uint16_t)src_p->inv_fast_motor_speed;
    dst_p[4] |= pack_left_shift_u16(inv_fast_motor_speed, 0u, 0xffu);
    dst_p[5] |= pack_right_shift_u16(inv_fast_motor_speed, 8u, 0xffu);
    inv_fast_dc_bus_voltage = (uint16_t)src_p->inv_fast_dc_bus_voltage;
    dst_p[6] |= pack_left_shift_u16(inv_fast_dc_bus_voltage, 0u, 0xffu);
    dst_p[7] |= pack_right_shift_u16(inv_fast_dc_bus_voltage, 8u, 0xffu);

    return (8);
}

int feb_can_m176_fast_info_unpack(
    struct feb_can_m176_fast_info_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    uint16_t inv_fast_dc_bus_voltage;
    uint16_t inv_fast_motor_speed;
    uint16_t inv_fast_torque_command;
    uint16_t inv_fast_torque_feedback;

    if (size < 8u) {
        return (-EINVAL);
    }

    inv_fast_torque_command = unpack_right_shift_u16(src_p[0], 0u, 0xffu);
    inv_fast_torque_command |= unpack_left_shift_u16(src_p[1], 8u, 0xffu);
    dst_p->inv_fast_torque_command = (int16_t)inv_fast_torque_command;
    inv_fast_torque_feedback = unpack_right_shift_u16(src_p[2], 0u, 0xffu);
    inv_fast_torque_feedback |= unpack_left_shift_u16(src_p[3], 8u, 0xffu);
    dst_p->inv_fast_torque_feedback = (int16_t)inv_fast_torque_feedback;
    inv_fast_motor_speed = unpack_right_shift_u16(src_p[4], 0u, 0xffu);
    inv_fast_motor_speed |= unpack_left_shift_u16(src_p[5], 8u, 0xffu);
    dst_p->inv_fast_motor_speed = (int16_t)inv_fast_motor_speed;
    inv_fast_dc_bus_voltage = unpack_right_shift_u16(src_p[6], 0u, 0xffu);
    inv_fast_dc_bus_voltage |= unpack_left_shift_u16(src_p[7], 8u, 0xffu);
    dst_p->inv_fast_dc_bus_voltage = (int16_t)inv_fast_dc_bus_voltage;

    return (0);
}

int feb_can_m176_fast_info_init(struct feb_can_m176_fast_info_t *msg_p)
{
    if (msg_p == NULL) return -1;

    memset(msg_p, 0, sizeof(struct feb_can_m176_fast_info_t));

    return 0;
}

int16_t feb_can_m176_fast_info_inv_fast_torque_command_encode(double value)
{
    return (int16_t)(value / 0.1);
}

double feb_can_m176_fast_info_inv_fast_torque_command_decode(int16_t value)
{
    return ((double)value * 0.1);
}

bool feb_can_m176_fast_info_inv_fast_torque_command_is_in_range(int16_t value)
{
    (void)value;

    return (true);
}

int16_t feb_can_m176_fast_info_inv_fast_torque_feedback_encode(double value)
{
    return (int16_t)(value / 0.1);
}

double feb_can_m176_fast_info_inv_fast_torque_feedback_decode(int16_t value)
{
    return ((double)value * 0.1);
}

bool feb_can_m176_fast_info_inv_fast_torque_feedback_is_in_range(int16_t value)
{
    (void)value;

    return (true);
}

int16_t feb_can_m176_fast_info_inv_fast_motor_speed_encode(double value)
{
    return (int16_t)(value);
}

double feb_can_m176_fast_info_inv_fast_motor_speed_decode(int16_t value)
{
    return ((double)value);
}

bool feb_can_m176_fast_info_inv_fast_motor_speed_is_in_range(int16_t value)
{
    (void)value;

    return (true);
}

int16_t feb_can_m176_fast_info_inv_fast_dc_bus_voltage_encode(double value)
{
    return (int16_t)(value / 0.1);
}

double feb_can_m176_fast_info_inv_fast_dc_bus_voltage_decode(int16_t value)
{
    return ((double)value * 0.1);
}

bool feb_can_m176_fast_info_inv_fast_dc_bus_voltage_is_in_range(int16_t value)
{
    (void)value;

    return (true);
}

int feb_can_m192_command_message_pack(
    uint8_t *dst_p,
    const struct feb_can_m192_command_message_t *src_p,
    size_t size)
{
    uint16_t vcu_inv_speed_command;
    uint16_t vcu_inv_torque_command;
    uint16_t vcu_inv_torque_limit_command;

    if (size < 8u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 8);

    vcu_inv_torque_command = (uint16_t)src_p->vcu_inv_torque_command;
    dst_p[0] |= pack_left_shift_u16(vcu_inv_torque_command, 0u, 0xffu);
    dst_p[1] |= pack_right_shift_u16(vcu_inv_torque_command, 8u, 0xffu);
    vcu_inv_speed_command = (uint16_t)src_p->vcu_inv_speed_command;
    dst_p[2] |= pack_left_shift_u16(vcu_inv_speed_command, 0u, 0xffu);
    dst_p[3] |= pack_right_shift_u16(vcu_inv_speed_command, 8u, 0xffu);
    dst_p[4] |= pack_left_shift_u8(src_p->vcu_inv_direction_command, 0u, 0x01u);
    dst_p[5] |= pack_left_shift_u8(src_p->vcu_inv_inverter_enable, 0u, 0x01u);
    dst_p[5] |= pack_left_shift_u8(src_p->vcu_inv_inverter_discharge, 1u, 0x02u);
    dst_p[5] |= pack_left_shift_u8(src_p->vcu_inv_speed_mode_enable, 2u, 0x04u);
    dst_p[5] |= pack_left_shift_u8(src_p->vcu_inv_rolling_counter, 4u, 0xf0u);
    vcu_inv_torque_limit_command = (uint16_t)src_p->vcu_inv_torque_limit_command;
    dst_p[6] |= pack_left_shift_u16(vcu_inv_torque_limit_command, 0u, 0xffu);
    dst_p[7] |= pack_right_shift_u16(vcu_inv_torque_limit_command, 8u, 0xffu);

    return (8);
}

int feb_can_m192_command_message_unpack(
    struct feb_can_m192_command_message_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    uint16_t vcu_inv_speed_command;
    uint16_t vcu_inv_torque_command;
    uint16_t vcu_inv_torque_limit_command;

    if (size < 8u) {
        return (-EINVAL);
    }

    vcu_inv_torque_command = unpack_right_shift_u16(src_p[0], 0u, 0xffu);
    vcu_inv_torque_command |= unpack_left_shift_u16(src_p[1], 8u, 0xffu);
    dst_p->vcu_inv_torque_command = (int16_t)vcu_inv_torque_command;
    vcu_inv_speed_command = unpack_right_shift_u16(src_p[2], 0u, 0xffu);
    vcu_inv_speed_command |= unpack_left_shift_u16(src_p[3], 8u, 0xffu);
    dst_p->vcu_inv_speed_command = (int16_t)vcu_inv_speed_command;
    dst_p->vcu_inv_direction_command = unpack_right_shift_u8(src_p[4], 0u, 0x01u);
    dst_p->vcu_inv_inverter_enable = unpack_right_shift_u8(src_p[5], 0u, 0x01u);
    dst_p->vcu_inv_inverter_discharge = unpack_right_shift_u8(src_p[5], 1u, 0x02u);
    dst_p->vcu_inv_speed_mode_enable = unpack_right_shift_u8(src_p[5], 2u, 0x04u);
    dst_p->vcu_inv_rolling_counter = unpack_right_shift_u8(src_p[5], 4u, 0xf0u);
    vcu_inv_torque_limit_command = unpack_right_shift_u16(src_p[6], 0u, 0xffu);
    vcu_inv_torque_limit_command |= unpack_left_shift_u16(src_p[7], 8u, 0xffu);
    dst_p->vcu_inv_torque_limit_command = (int16_t)vcu_inv_torque_limit_command;

    return (0);
}

int feb_can_m192_command_message_init(struct feb_can_m192_command_message_t *msg_p)
{
    if (msg_p == NULL) return -1;

    memset(msg_p, 0, sizeof(struct feb_can_m192_command_message_t));

    return 0;
}

int16_t feb_can_m192_command_message_vcu_inv_torque_command_encode(double value)
{
    return (int16_t)(value / 0.1);
}

double feb_can_m192_command_message_vcu_inv_torque_command_decode(int16_t value)
{
    return ((double)value * 0.1);
}

bool feb_can_m192_command_message_vcu_inv_torque_command_is_in_range(int16_t value)
{
    (void)value;

    return (true);
}

int16_t feb_can_m192_command_message_vcu_inv_speed_command_encode(double value)
{
    return (int16_t)(value);
}

double feb_can_m192_command_message_vcu_inv_speed_command_decode(int16_t value)
{
    return ((double)value);
}

bool feb_can_m192_command_message_vcu_inv_speed_command_is_in_range(int16_t value)
{
    (void)value;

    return (true);
}

uint8_t feb_can_m192_command_message_vcu_inv_direction_command_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_m192_command_message_vcu_inv_direction_command_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_m192_command_message_vcu_inv_direction_command_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_m192_command_message_vcu_inv_inverter_enable_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_m192_command_message_vcu_inv_inverter_enable_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_m192_command_message_vcu_inv_inverter_enable_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_m192_command_message_vcu_inv_inverter_discharge_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_m192_command_message_vcu_inv_inverter_discharge_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_m192_command_message_vcu_inv_inverter_discharge_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_m192_command_message_vcu_inv_speed_mode_enable_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_m192_command_message_vcu_inv_speed_mode_enable_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_m192_command_message_vcu_inv_speed_mode_enable_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_m192_command_message_vcu_inv_rolling_counter_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_m192_command_message_vcu_inv_rolling_counter_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_m192_command_message_vcu_inv_rolling_counter_is_in_range(uint8_t value)
{
    return (value <= 15u);
}

int16_t feb_can_m192_command_message_vcu_inv_torque_limit_command_encode(double value)
{
    return (int16_t)(value / 0.1);
}

double feb_can_m192_command_message_vcu_inv_torque_limit_command_decode(int16_t value)
{
    return ((double)value * 0.1);
}

bool feb_can_m192_command_message_vcu_inv_torque_limit_command_is_in_range(int16_t value)
{
    (void)value;

    return (true);
}

int feb_can_m193_read_write_param_command_pack(
    uint8_t *dst_p,
    const struct feb_can_m193_read_write_param_command_t *src_p,
    size_t size)
{
    uint16_t vcu_inv_data_command;

    if (size < 8u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 8);

    dst_p[0] |= pack_left_shift_u16(src_p->vcu_inv_parameter_address_command, 0u, 0xffu);
    dst_p[1] |= pack_right_shift_u16(src_p->vcu_inv_parameter_address_command, 8u, 0xffu);
    dst_p[2] |= pack_left_shift_u8(src_p->vcu_inv_read_write_command, 0u, 0x01u);
    vcu_inv_data_command = (uint16_t)src_p->vcu_inv_data_command;
    dst_p[4] |= pack_left_shift_u16(vcu_inv_data_command, 0u, 0xffu);
    dst_p[5] |= pack_right_shift_u16(vcu_inv_data_command, 8u, 0xffu);

    return (8);
}

int feb_can_m193_read_write_param_command_unpack(
    struct feb_can_m193_read_write_param_command_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    uint16_t vcu_inv_data_command;

    if (size < 8u) {
        return (-EINVAL);
    }

    dst_p->vcu_inv_parameter_address_command = unpack_right_shift_u16(src_p[0], 0u, 0xffu);
    dst_p->vcu_inv_parameter_address_command |= unpack_left_shift_u16(src_p[1], 8u, 0xffu);
    dst_p->vcu_inv_read_write_command = unpack_right_shift_u8(src_p[2], 0u, 0x01u);
    vcu_inv_data_command = unpack_right_shift_u16(src_p[4], 0u, 0xffu);
    vcu_inv_data_command |= unpack_left_shift_u16(src_p[5], 8u, 0xffu);
    dst_p->vcu_inv_data_command = (int16_t)vcu_inv_data_command;

    return (0);
}

int feb_can_m193_read_write_param_command_init(struct feb_can_m193_read_write_param_command_t *msg_p)
{
    if (msg_p == NULL) return -1;

    memset(msg_p, 0, sizeof(struct feb_can_m193_read_write_param_command_t));

    return 0;
}

uint16_t feb_can_m193_read_write_param_command_vcu_inv_parameter_address_command_encode(double value)
{
    return (uint16_t)(value);
}

double feb_can_m193_read_write_param_command_vcu_inv_parameter_address_command_decode(uint16_t value)
{
    return ((double)value);
}

bool feb_can_m193_read_write_param_command_vcu_inv_parameter_address_command_is_in_range(uint16_t value)
{
    (void)value;

    return (true);
}

uint8_t feb_can_m193_read_write_param_command_vcu_inv_read_write_command_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_m193_read_write_param_command_vcu_inv_read_write_command_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_m193_read_write_param_command_vcu_inv_read_write_command_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

int16_t feb_can_m193_read_write_param_command_vcu_inv_data_command_encode(double value)
{
    return (int16_t)(value);
}

double feb_can_m193_read_write_param_command_vcu_inv_data_command_decode(int16_t value)
{
    return ((double)value);
}

bool feb_can_m193_read_write_param_command_vcu_inv_data_command_is_in_range(int16_t value)
{
    (void)value;

    return (true);
}

int feb_can_m194_read_write_param_response_pack(
    uint8_t *dst_p,
    const struct feb_can_m194_read_write_param_response_t *src_p,
    size_t size)
{
    uint16_t inv_data_response;

    if (size < 8u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 8);

    dst_p[0] |= pack_left_shift_u16(src_p->inv_parameter_address_response, 0u, 0xffu);
    dst_p[1] |= pack_right_shift_u16(src_p->inv_parameter_address_response, 8u, 0xffu);
    dst_p[2] |= pack_left_shift_u8(src_p->inv_write_success, 0u, 0x01u);
    inv_data_response = (uint16_t)src_p->inv_data_response;
    dst_p[4] |= pack_left_shift_u16(inv_data_response, 0u, 0xffu);
    dst_p[5] |= pack_right_shift_u16(inv_data_response, 8u, 0xffu);

    return (8);
}

int feb_can_m194_read_write_param_response_unpack(
    struct feb_can_m194_read_write_param_response_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    uint16_t inv_data_response;

    if (size < 8u) {
        return (-EINVAL);
    }

    dst_p->inv_parameter_address_response = unpack_right_shift_u16(src_p[0], 0u, 0xffu);
    dst_p->inv_parameter_address_response |= unpack_left_shift_u16(src_p[1], 8u, 0xffu);
    dst_p->inv_write_success = unpack_right_shift_u8(src_p[2], 0u, 0x01u);
    inv_data_response = unpack_right_shift_u16(src_p[4], 0u, 0xffu);
    inv_data_response |= unpack_left_shift_u16(src_p[5], 8u, 0xffu);
    dst_p->inv_data_response = (int16_t)inv_data_response;

    return (0);
}

int feb_can_m194_read_write_param_response_init(struct feb_can_m194_read_write_param_response_t *msg_p)
{
    if (msg_p == NULL) return -1;

    memset(msg_p, 0, sizeof(struct feb_can_m194_read_write_param_response_t));

    return 0;
}

uint16_t feb_can_m194_read_write_param_response_inv_parameter_address_response_encode(double value)
{
    return (uint16_t)(value);
}

double feb_can_m194_read_write_param_response_inv_parameter_address_response_decode(uint16_t value)
{
    return ((double)value);
}

bool feb_can_m194_read_write_param_response_inv_parameter_address_response_is_in_range(uint16_t value)
{
    (void)value;

    return (true);
}

uint8_t feb_can_m194_read_write_param_response_inv_write_success_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_m194_read_write_param_response_inv_write_success_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_m194_read_write_param_response_inv_write_success_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

int16_t feb_can_m194_read_write_param_response_inv_data_response_encode(double value)
{
    return (int16_t)(value);
}

double feb_can_m194_read_write_param_response_inv_data_response_decode(int16_t value)
{
    return ((double)value);
}

bool feb_can_m194_read_write_param_response_inv_data_response_is_in_range(int16_t value)
{
    (void)value;

    return (true);
}

int feb_can_pcu_heartbeat_pack(
    uint8_t *dst_p,
    const struct feb_can_pcu_heartbeat_t *src_p,
    size_t size)
{
    if (size < 8u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 8);

    dst_p[0] |= pack_left_shift_u8(src_p->error0, 0u, 0x01u);
    dst_p[0] |= pack_left_shift_u8(src_p->error1, 1u, 0x02u);
    dst_p[0] |= pack_left_shift_u8(src_p->error2, 2u, 0x04u);
    dst_p[0] |= pack_left_shift_u8(src_p->error3, 3u, 0x08u);
    dst_p[0] |= pack_left_shift_u8(src_p->error4, 4u, 0x10u);
    dst_p[0] |= pack_left_shift_u8(src_p->error5, 5u, 0x20u);
    dst_p[0] |= pack_left_shift_u8(src_p->error6, 6u, 0x40u);
    dst_p[0] |= pack_left_shift_u8(src_p->error7, 7u, 0x80u);
    dst_p[1] |= pack_left_shift_u8(src_p->error8, 0u, 0x01u);
    dst_p[1] |= pack_left_shift_u8(src_p->error9, 1u, 0x02u);
    dst_p[1] |= pack_left_shift_u8(src_p->error10, 2u, 0x04u);
    dst_p[1] |= pack_left_shift_u8(src_p->error11, 3u, 0x08u);
    dst_p[1] |= pack_left_shift_u8(src_p->error12, 4u, 0x10u);
    dst_p[1] |= pack_left_shift_u8(src_p->error13, 5u, 0x20u);
    dst_p[1] |= pack_left_shift_u8(src_p->error14, 6u, 0x40u);
    dst_p[1] |= pack_left_shift_u8(src_p->error15, 7u, 0x80u);
    dst_p[2] |= pack_left_shift_u8(src_p->error16, 0u, 0x01u);
    dst_p[2] |= pack_left_shift_u8(src_p->error17, 1u, 0x02u);
    dst_p[2] |= pack_left_shift_u8(src_p->error18, 2u, 0x04u);
    dst_p[2] |= pack_left_shift_u8(src_p->error19, 3u, 0x08u);
    dst_p[2] |= pack_left_shift_u8(src_p->error20, 4u, 0x10u);
    dst_p[2] |= pack_left_shift_u8(src_p->error21, 5u, 0x20u);
    dst_p[2] |= pack_left_shift_u8(src_p->error22, 6u, 0x40u);
    dst_p[2] |= pack_left_shift_u8(src_p->error23, 7u, 0x80u);
    dst_p[3] |= pack_left_shift_u8(src_p->error24, 0u, 0x01u);
    dst_p[3] |= pack_left_shift_u8(src_p->error25, 1u, 0x02u);
    dst_p[3] |= pack_left_shift_u8(src_p->error26, 2u, 0x04u);
    dst_p[3] |= pack_left_shift_u8(src_p->error27, 3u, 0x08u);
    dst_p[3] |= pack_left_shift_u8(src_p->error28, 4u, 0x10u);
    dst_p[3] |= pack_left_shift_u8(src_p->error29, 5u, 0x20u);
    dst_p[3] |= pack_left_shift_u8(src_p->error30, 6u, 0x40u);
    dst_p[3] |= pack_left_shift_u8(src_p->error31, 7u, 0x80u);
    dst_p[4] |= pack_left_shift_u8(src_p->error32, 0u, 0x01u);
    dst_p[4] |= pack_left_shift_u8(src_p->error33, 1u, 0x02u);
    dst_p[4] |= pack_left_shift_u8(src_p->error34, 2u, 0x04u);
    dst_p[4] |= pack_left_shift_u8(src_p->error35, 3u, 0x08u);
    dst_p[4] |= pack_left_shift_u8(src_p->error36, 4u, 0x10u);
    dst_p[4] |= pack_left_shift_u8(src_p->error37, 5u, 0x20u);
    dst_p[4] |= pack_left_shift_u8(src_p->error38, 6u, 0x40u);
    dst_p[4] |= pack_left_shift_u8(src_p->error39, 7u, 0x80u);
    dst_p[5] |= pack_left_shift_u8(src_p->error40, 0u, 0x01u);
    dst_p[5] |= pack_left_shift_u8(src_p->error41, 1u, 0x02u);
    dst_p[5] |= pack_left_shift_u8(src_p->error42, 2u, 0x04u);
    dst_p[5] |= pack_left_shift_u8(src_p->error43, 3u, 0x08u);
    dst_p[5] |= pack_left_shift_u8(src_p->error44, 4u, 0x10u);
    dst_p[5] |= pack_left_shift_u8(src_p->error45, 5u, 0x20u);
    dst_p[5] |= pack_left_shift_u8(src_p->error46, 6u, 0x40u);
    dst_p[5] |= pack_left_shift_u8(src_p->error47, 7u, 0x80u);
    dst_p[6] |= pack_left_shift_u8(src_p->error48, 0u, 0x01u);
    dst_p[6] |= pack_left_shift_u8(src_p->error49, 1u, 0x02u);
    dst_p[6] |= pack_left_shift_u8(src_p->error50, 2u, 0x04u);
    dst_p[6] |= pack_left_shift_u8(src_p->error51, 3u, 0x08u);
    dst_p[6] |= pack_left_shift_u8(src_p->error52, 4u, 0x10u);
    dst_p[6] |= pack_left_shift_u8(src_p->error53, 5u, 0x20u);
    dst_p[6] |= pack_left_shift_u8(src_p->error54, 6u, 0x40u);
    dst_p[6] |= pack_left_shift_u8(src_p->error55, 7u, 0x80u);
    dst_p[7] |= pack_left_shift_u8(src_p->error56, 0u, 0x01u);
    dst_p[7] |= pack_left_shift_u8(src_p->error57, 1u, 0x02u);
    dst_p[7] |= pack_left_shift_u8(src_p->error58, 2u, 0x04u);
    dst_p[7] |= pack_left_shift_u8(src_p->error59, 3u, 0x08u);
    dst_p[7] |= pack_left_shift_u8(src_p->error60, 4u, 0x10u);
    dst_p[7] |= pack_left_shift_u8(src_p->error61, 5u, 0x20u);
    dst_p[7] |= pack_left_shift_u8(src_p->error62, 6u, 0x40u);
    dst_p[7] |= pack_left_shift_u8(src_p->error63, 7u, 0x80u);

    return (8);
}

int feb_can_pcu_heartbeat_unpack(
    struct feb_can_pcu_heartbeat_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    if (size < 8u) {
        return (-EINVAL);
    }

    dst_p->error0 = unpack_right_shift_u8(src_p[0], 0u, 0x01u);
    dst_p->error1 = unpack_right_shift_u8(src_p[0], 1u, 0x02u);
    dst_p->error2 = unpack_right_shift_u8(src_p[0], 2u, 0x04u);
    dst_p->error3 = unpack_right_shift_u8(src_p[0], 3u, 0x08u);
    dst_p->error4 = unpack_right_shift_u8(src_p[0], 4u, 0x10u);
    dst_p->error5 = unpack_right_shift_u8(src_p[0], 5u, 0x20u);
    dst_p->error6 = unpack_right_shift_u8(src_p[0], 6u, 0x40u);
    dst_p->error7 = unpack_right_shift_u8(src_p[0], 7u, 0x80u);
    dst_p->error8 = unpack_right_shift_u8(src_p[1], 0u, 0x01u);
    dst_p->error9 = unpack_right_shift_u8(src_p[1], 1u, 0x02u);
    dst_p->error10 = unpack_right_shift_u8(src_p[1], 2u, 0x04u);
    dst_p->error11 = unpack_right_shift_u8(src_p[1], 3u, 0x08u);
    dst_p->error12 = unpack_right_shift_u8(src_p[1], 4u, 0x10u);
    dst_p->error13 = unpack_right_shift_u8(src_p[1], 5u, 0x20u);
    dst_p->error14 = unpack_right_shift_u8(src_p[1], 6u, 0x40u);
    dst_p->error15 = unpack_right_shift_u8(src_p[1], 7u, 0x80u);
    dst_p->error16 = unpack_right_shift_u8(src_p[2], 0u, 0x01u);
    dst_p->error17 = unpack_right_shift_u8(src_p[2], 1u, 0x02u);
    dst_p->error18 = unpack_right_shift_u8(src_p[2], 2u, 0x04u);
    dst_p->error19 = unpack_right_shift_u8(src_p[2], 3u, 0x08u);
    dst_p->error20 = unpack_right_shift_u8(src_p[2], 4u, 0x10u);
    dst_p->error21 = unpack_right_shift_u8(src_p[2], 5u, 0x20u);
    dst_p->error22 = unpack_right_shift_u8(src_p[2], 6u, 0x40u);
    dst_p->error23 = unpack_right_shift_u8(src_p[2], 7u, 0x80u);
    dst_p->error24 = unpack_right_shift_u8(src_p[3], 0u, 0x01u);
    dst_p->error25 = unpack_right_shift_u8(src_p[3], 1u, 0x02u);
    dst_p->error26 = unpack_right_shift_u8(src_p[3], 2u, 0x04u);
    dst_p->error27 = unpack_right_shift_u8(src_p[3], 3u, 0x08u);
    dst_p->error28 = unpack_right_shift_u8(src_p[3], 4u, 0x10u);
    dst_p->error29 = unpack_right_shift_u8(src_p[3], 5u, 0x20u);
    dst_p->error30 = unpack_right_shift_u8(src_p[3], 6u, 0x40u);
    dst_p->error31 = unpack_right_shift_u8(src_p[3], 7u, 0x80u);
    dst_p->error32 = unpack_right_shift_u8(src_p[4], 0u, 0x01u);
    dst_p->error33 = unpack_right_shift_u8(src_p[4], 1u, 0x02u);
    dst_p->error34 = unpack_right_shift_u8(src_p[4], 2u, 0x04u);
    dst_p->error35 = unpack_right_shift_u8(src_p[4], 3u, 0x08u);
    dst_p->error36 = unpack_right_shift_u8(src_p[4], 4u, 0x10u);
    dst_p->error37 = unpack_right_shift_u8(src_p[4], 5u, 0x20u);
    dst_p->error38 = unpack_right_shift_u8(src_p[4], 6u, 0x40u);
    dst_p->error39 = unpack_right_shift_u8(src_p[4], 7u, 0x80u);
    dst_p->error40 = unpack_right_shift_u8(src_p[5], 0u, 0x01u);
    dst_p->error41 = unpack_right_shift_u8(src_p[5], 1u, 0x02u);
    dst_p->error42 = unpack_right_shift_u8(src_p[5], 2u, 0x04u);
    dst_p->error43 = unpack_right_shift_u8(src_p[5], 3u, 0x08u);
    dst_p->error44 = unpack_right_shift_u8(src_p[5], 4u, 0x10u);
    dst_p->error45 = unpack_right_shift_u8(src_p[5], 5u, 0x20u);
    dst_p->error46 = unpack_right_shift_u8(src_p[5], 6u, 0x40u);
    dst_p->error47 = unpack_right_shift_u8(src_p[5], 7u, 0x80u);
    dst_p->error48 = unpack_right_shift_u8(src_p[6], 0u, 0x01u);
    dst_p->error49 = unpack_right_shift_u8(src_p[6], 1u, 0x02u);
    dst_p->error50 = unpack_right_shift_u8(src_p[6], 2u, 0x04u);
    dst_p->error51 = unpack_right_shift_u8(src_p[6], 3u, 0x08u);
    dst_p->error52 = unpack_right_shift_u8(src_p[6], 4u, 0x10u);
    dst_p->error53 = unpack_right_shift_u8(src_p[6], 5u, 0x20u);
    dst_p->error54 = unpack_right_shift_u8(src_p[6], 6u, 0x40u);
    dst_p->error55 = unpack_right_shift_u8(src_p[6], 7u, 0x80u);
    dst_p->error56 = unpack_right_shift_u8(src_p[7], 0u, 0x01u);
    dst_p->error57 = unpack_right_shift_u8(src_p[7], 1u, 0x02u);
    dst_p->error58 = unpack_right_shift_u8(src_p[7], 2u, 0x04u);
    dst_p->error59 = unpack_right_shift_u8(src_p[7], 3u, 0x08u);
    dst_p->error60 = unpack_right_shift_u8(src_p[7], 4u, 0x10u);
    dst_p->error61 = unpack_right_shift_u8(src_p[7], 5u, 0x20u);
    dst_p->error62 = unpack_right_shift_u8(src_p[7], 6u, 0x40u);
    dst_p->error63 = unpack_right_shift_u8(src_p[7], 7u, 0x80u);

    return (0);
}

int feb_can_pcu_heartbeat_init(struct feb_can_pcu_heartbeat_t *msg_p)
{
    if (msg_p == NULL) return -1;

    memset(msg_p, 0, sizeof(struct feb_can_pcu_heartbeat_t));

    return 0;
}

uint8_t feb_can_pcu_heartbeat_error0_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_pcu_heartbeat_error0_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_pcu_heartbeat_error0_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_pcu_heartbeat_error1_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_pcu_heartbeat_error1_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_pcu_heartbeat_error1_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_pcu_heartbeat_error2_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_pcu_heartbeat_error2_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_pcu_heartbeat_error2_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_pcu_heartbeat_error3_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_pcu_heartbeat_error3_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_pcu_heartbeat_error3_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_pcu_heartbeat_error4_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_pcu_heartbeat_error4_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_pcu_heartbeat_error4_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_pcu_heartbeat_error5_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_pcu_heartbeat_error5_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_pcu_heartbeat_error5_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_pcu_heartbeat_error6_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_pcu_heartbeat_error6_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_pcu_heartbeat_error6_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_pcu_heartbeat_error7_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_pcu_heartbeat_error7_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_pcu_heartbeat_error7_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_pcu_heartbeat_error8_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_pcu_heartbeat_error8_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_pcu_heartbeat_error8_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_pcu_heartbeat_error9_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_pcu_heartbeat_error9_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_pcu_heartbeat_error9_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_pcu_heartbeat_error10_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_pcu_heartbeat_error10_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_pcu_heartbeat_error10_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_pcu_heartbeat_error11_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_pcu_heartbeat_error11_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_pcu_heartbeat_error11_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_pcu_heartbeat_error12_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_pcu_heartbeat_error12_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_pcu_heartbeat_error12_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_pcu_heartbeat_error13_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_pcu_heartbeat_error13_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_pcu_heartbeat_error13_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_pcu_heartbeat_error14_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_pcu_heartbeat_error14_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_pcu_heartbeat_error14_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_pcu_heartbeat_error15_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_pcu_heartbeat_error15_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_pcu_heartbeat_error15_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_pcu_heartbeat_error16_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_pcu_heartbeat_error16_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_pcu_heartbeat_error16_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_pcu_heartbeat_error17_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_pcu_heartbeat_error17_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_pcu_heartbeat_error17_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_pcu_heartbeat_error18_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_pcu_heartbeat_error18_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_pcu_heartbeat_error18_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_pcu_heartbeat_error19_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_pcu_heartbeat_error19_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_pcu_heartbeat_error19_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_pcu_heartbeat_error20_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_pcu_heartbeat_error20_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_pcu_heartbeat_error20_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_pcu_heartbeat_error21_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_pcu_heartbeat_error21_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_pcu_heartbeat_error21_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_pcu_heartbeat_error22_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_pcu_heartbeat_error22_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_pcu_heartbeat_error22_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_pcu_heartbeat_error23_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_pcu_heartbeat_error23_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_pcu_heartbeat_error23_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_pcu_heartbeat_error24_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_pcu_heartbeat_error24_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_pcu_heartbeat_error24_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_pcu_heartbeat_error25_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_pcu_heartbeat_error25_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_pcu_heartbeat_error25_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_pcu_heartbeat_error26_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_pcu_heartbeat_error26_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_pcu_heartbeat_error26_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_pcu_heartbeat_error27_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_pcu_heartbeat_error27_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_pcu_heartbeat_error27_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_pcu_heartbeat_error28_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_pcu_heartbeat_error28_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_pcu_heartbeat_error28_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_pcu_heartbeat_error29_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_pcu_heartbeat_error29_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_pcu_heartbeat_error29_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_pcu_heartbeat_error30_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_pcu_heartbeat_error30_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_pcu_heartbeat_error30_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_pcu_heartbeat_error31_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_pcu_heartbeat_error31_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_pcu_heartbeat_error31_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_pcu_heartbeat_error32_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_pcu_heartbeat_error32_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_pcu_heartbeat_error32_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_pcu_heartbeat_error33_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_pcu_heartbeat_error33_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_pcu_heartbeat_error33_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_pcu_heartbeat_error34_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_pcu_heartbeat_error34_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_pcu_heartbeat_error34_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_pcu_heartbeat_error35_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_pcu_heartbeat_error35_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_pcu_heartbeat_error35_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_pcu_heartbeat_error36_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_pcu_heartbeat_error36_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_pcu_heartbeat_error36_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_pcu_heartbeat_error37_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_pcu_heartbeat_error37_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_pcu_heartbeat_error37_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_pcu_heartbeat_error38_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_pcu_heartbeat_error38_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_pcu_heartbeat_error38_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_pcu_heartbeat_error39_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_pcu_heartbeat_error39_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_pcu_heartbeat_error39_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_pcu_heartbeat_error40_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_pcu_heartbeat_error40_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_pcu_heartbeat_error40_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_pcu_heartbeat_error41_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_pcu_heartbeat_error41_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_pcu_heartbeat_error41_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_pcu_heartbeat_error42_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_pcu_heartbeat_error42_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_pcu_heartbeat_error42_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_pcu_heartbeat_error43_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_pcu_heartbeat_error43_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_pcu_heartbeat_error43_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_pcu_heartbeat_error44_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_pcu_heartbeat_error44_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_pcu_heartbeat_error44_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_pcu_heartbeat_error45_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_pcu_heartbeat_error45_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_pcu_heartbeat_error45_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_pcu_heartbeat_error46_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_pcu_heartbeat_error46_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_pcu_heartbeat_error46_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_pcu_heartbeat_error47_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_pcu_heartbeat_error47_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_pcu_heartbeat_error47_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_pcu_heartbeat_error48_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_pcu_heartbeat_error48_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_pcu_heartbeat_error48_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_pcu_heartbeat_error49_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_pcu_heartbeat_error49_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_pcu_heartbeat_error49_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_pcu_heartbeat_error50_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_pcu_heartbeat_error50_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_pcu_heartbeat_error50_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_pcu_heartbeat_error51_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_pcu_heartbeat_error51_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_pcu_heartbeat_error51_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_pcu_heartbeat_error52_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_pcu_heartbeat_error52_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_pcu_heartbeat_error52_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_pcu_heartbeat_error53_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_pcu_heartbeat_error53_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_pcu_heartbeat_error53_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_pcu_heartbeat_error54_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_pcu_heartbeat_error54_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_pcu_heartbeat_error54_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_pcu_heartbeat_error55_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_pcu_heartbeat_error55_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_pcu_heartbeat_error55_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_pcu_heartbeat_error56_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_pcu_heartbeat_error56_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_pcu_heartbeat_error56_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_pcu_heartbeat_error57_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_pcu_heartbeat_error57_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_pcu_heartbeat_error57_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_pcu_heartbeat_error58_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_pcu_heartbeat_error58_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_pcu_heartbeat_error58_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_pcu_heartbeat_error59_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_pcu_heartbeat_error59_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_pcu_heartbeat_error59_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_pcu_heartbeat_error60_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_pcu_heartbeat_error60_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_pcu_heartbeat_error60_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_pcu_heartbeat_error61_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_pcu_heartbeat_error61_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_pcu_heartbeat_error61_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_pcu_heartbeat_error62_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_pcu_heartbeat_error62_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_pcu_heartbeat_error62_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_pcu_heartbeat_error63_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_pcu_heartbeat_error63_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_pcu_heartbeat_error63_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

int feb_can_dash_heartbeat_pack(
    uint8_t *dst_p,
    const struct feb_can_dash_heartbeat_t *src_p,
    size_t size)
{
    if (size < 8u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 8);

    dst_p[0] |= pack_left_shift_u8(src_p->io_expander_error, 0u, 0x01u);
    dst_p[0] |= pack_left_shift_u8(src_p->error1, 1u, 0x02u);
    dst_p[0] |= pack_left_shift_u8(src_p->error2, 2u, 0x04u);
    dst_p[0] |= pack_left_shift_u8(src_p->error3, 3u, 0x08u);
    dst_p[0] |= pack_left_shift_u8(src_p->error4, 4u, 0x10u);
    dst_p[0] |= pack_left_shift_u8(src_p->error5, 5u, 0x20u);
    dst_p[0] |= pack_left_shift_u8(src_p->error6, 6u, 0x40u);
    dst_p[0] |= pack_left_shift_u8(src_p->error7, 7u, 0x80u);
    dst_p[1] |= pack_left_shift_u8(src_p->error8, 0u, 0x01u);
    dst_p[1] |= pack_left_shift_u8(src_p->error9, 1u, 0x02u);
    dst_p[1] |= pack_left_shift_u8(src_p->error10, 2u, 0x04u);
    dst_p[1] |= pack_left_shift_u8(src_p->error11, 3u, 0x08u);
    dst_p[1] |= pack_left_shift_u8(src_p->error12, 4u, 0x10u);
    dst_p[1] |= pack_left_shift_u8(src_p->error13, 5u, 0x20u);
    dst_p[1] |= pack_left_shift_u8(src_p->error14, 6u, 0x40u);
    dst_p[1] |= pack_left_shift_u8(src_p->error15, 7u, 0x80u);
    dst_p[2] |= pack_left_shift_u8(src_p->error16, 0u, 0x01u);
    dst_p[2] |= pack_left_shift_u8(src_p->error17, 1u, 0x02u);
    dst_p[2] |= pack_left_shift_u8(src_p->error18, 2u, 0x04u);
    dst_p[2] |= pack_left_shift_u8(src_p->error19, 3u, 0x08u);
    dst_p[2] |= pack_left_shift_u8(src_p->error20, 4u, 0x10u);
    dst_p[2] |= pack_left_shift_u8(src_p->error21, 5u, 0x20u);
    dst_p[2] |= pack_left_shift_u8(src_p->error22, 6u, 0x40u);
    dst_p[2] |= pack_left_shift_u8(src_p->error23, 7u, 0x80u);
    dst_p[3] |= pack_left_shift_u8(src_p->error24, 0u, 0x01u);
    dst_p[3] |= pack_left_shift_u8(src_p->error25, 1u, 0x02u);
    dst_p[3] |= pack_left_shift_u8(src_p->error26, 2u, 0x04u);
    dst_p[3] |= pack_left_shift_u8(src_p->error27, 3u, 0x08u);
    dst_p[3] |= pack_left_shift_u8(src_p->error28, 4u, 0x10u);
    dst_p[3] |= pack_left_shift_u8(src_p->error29, 5u, 0x20u);
    dst_p[3] |= pack_left_shift_u8(src_p->error30, 6u, 0x40u);
    dst_p[3] |= pack_left_shift_u8(src_p->error31, 7u, 0x80u);
    dst_p[4] |= pack_left_shift_u8(src_p->error32, 0u, 0x01u);
    dst_p[4] |= pack_left_shift_u8(src_p->error33, 1u, 0x02u);
    dst_p[4] |= pack_left_shift_u8(src_p->error34, 2u, 0x04u);
    dst_p[4] |= pack_left_shift_u8(src_p->error35, 3u, 0x08u);
    dst_p[4] |= pack_left_shift_u8(src_p->error36, 4u, 0x10u);
    dst_p[4] |= pack_left_shift_u8(src_p->error37, 5u, 0x20u);
    dst_p[4] |= pack_left_shift_u8(src_p->error38, 6u, 0x40u);
    dst_p[4] |= pack_left_shift_u8(src_p->error39, 7u, 0x80u);
    dst_p[5] |= pack_left_shift_u8(src_p->error40, 0u, 0x01u);
    dst_p[5] |= pack_left_shift_u8(src_p->error41, 1u, 0x02u);
    dst_p[5] |= pack_left_shift_u8(src_p->error42, 2u, 0x04u);
    dst_p[5] |= pack_left_shift_u8(src_p->error43, 3u, 0x08u);
    dst_p[5] |= pack_left_shift_u8(src_p->error44, 4u, 0x10u);
    dst_p[5] |= pack_left_shift_u8(src_p->error45, 5u, 0x20u);
    dst_p[5] |= pack_left_shift_u8(src_p->error46, 6u, 0x40u);
    dst_p[5] |= pack_left_shift_u8(src_p->error47, 7u, 0x80u);
    dst_p[6] |= pack_left_shift_u8(src_p->error48, 0u, 0x01u);
    dst_p[6] |= pack_left_shift_u8(src_p->error49, 1u, 0x02u);
    dst_p[6] |= pack_left_shift_u8(src_p->error50, 2u, 0x04u);
    dst_p[6] |= pack_left_shift_u8(src_p->error51, 3u, 0x08u);
    dst_p[6] |= pack_left_shift_u8(src_p->error52, 4u, 0x10u);
    dst_p[6] |= pack_left_shift_u8(src_p->error53, 5u, 0x20u);
    dst_p[6] |= pack_left_shift_u8(src_p->error54, 6u, 0x40u);
    dst_p[6] |= pack_left_shift_u8(src_p->error55, 7u, 0x80u);
    dst_p[7] |= pack_left_shift_u8(src_p->error56, 0u, 0x01u);
    dst_p[7] |= pack_left_shift_u8(src_p->error57, 1u, 0x02u);
    dst_p[7] |= pack_left_shift_u8(src_p->error58, 2u, 0x04u);
    dst_p[7] |= pack_left_shift_u8(src_p->error59, 3u, 0x08u);
    dst_p[7] |= pack_left_shift_u8(src_p->error60, 4u, 0x10u);
    dst_p[7] |= pack_left_shift_u8(src_p->error61, 5u, 0x20u);
    dst_p[7] |= pack_left_shift_u8(src_p->error62, 6u, 0x40u);
    dst_p[7] |= pack_left_shift_u8(src_p->error63, 7u, 0x80u);

    return (8);
}

int feb_can_dash_heartbeat_unpack(
    struct feb_can_dash_heartbeat_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    if (size < 8u) {
        return (-EINVAL);
    }

    dst_p->io_expander_error = unpack_right_shift_u8(src_p[0], 0u, 0x01u);
    dst_p->error1 = unpack_right_shift_u8(src_p[0], 1u, 0x02u);
    dst_p->error2 = unpack_right_shift_u8(src_p[0], 2u, 0x04u);
    dst_p->error3 = unpack_right_shift_u8(src_p[0], 3u, 0x08u);
    dst_p->error4 = unpack_right_shift_u8(src_p[0], 4u, 0x10u);
    dst_p->error5 = unpack_right_shift_u8(src_p[0], 5u, 0x20u);
    dst_p->error6 = unpack_right_shift_u8(src_p[0], 6u, 0x40u);
    dst_p->error7 = unpack_right_shift_u8(src_p[0], 7u, 0x80u);
    dst_p->error8 = unpack_right_shift_u8(src_p[1], 0u, 0x01u);
    dst_p->error9 = unpack_right_shift_u8(src_p[1], 1u, 0x02u);
    dst_p->error10 = unpack_right_shift_u8(src_p[1], 2u, 0x04u);
    dst_p->error11 = unpack_right_shift_u8(src_p[1], 3u, 0x08u);
    dst_p->error12 = unpack_right_shift_u8(src_p[1], 4u, 0x10u);
    dst_p->error13 = unpack_right_shift_u8(src_p[1], 5u, 0x20u);
    dst_p->error14 = unpack_right_shift_u8(src_p[1], 6u, 0x40u);
    dst_p->error15 = unpack_right_shift_u8(src_p[1], 7u, 0x80u);
    dst_p->error16 = unpack_right_shift_u8(src_p[2], 0u, 0x01u);
    dst_p->error17 = unpack_right_shift_u8(src_p[2], 1u, 0x02u);
    dst_p->error18 = unpack_right_shift_u8(src_p[2], 2u, 0x04u);
    dst_p->error19 = unpack_right_shift_u8(src_p[2], 3u, 0x08u);
    dst_p->error20 = unpack_right_shift_u8(src_p[2], 4u, 0x10u);
    dst_p->error21 = unpack_right_shift_u8(src_p[2], 5u, 0x20u);
    dst_p->error22 = unpack_right_shift_u8(src_p[2], 6u, 0x40u);
    dst_p->error23 = unpack_right_shift_u8(src_p[2], 7u, 0x80u);
    dst_p->error24 = unpack_right_shift_u8(src_p[3], 0u, 0x01u);
    dst_p->error25 = unpack_right_shift_u8(src_p[3], 1u, 0x02u);
    dst_p->error26 = unpack_right_shift_u8(src_p[3], 2u, 0x04u);
    dst_p->error27 = unpack_right_shift_u8(src_p[3], 3u, 0x08u);
    dst_p->error28 = unpack_right_shift_u8(src_p[3], 4u, 0x10u);
    dst_p->error29 = unpack_right_shift_u8(src_p[3], 5u, 0x20u);
    dst_p->error30 = unpack_right_shift_u8(src_p[3], 6u, 0x40u);
    dst_p->error31 = unpack_right_shift_u8(src_p[3], 7u, 0x80u);
    dst_p->error32 = unpack_right_shift_u8(src_p[4], 0u, 0x01u);
    dst_p->error33 = unpack_right_shift_u8(src_p[4], 1u, 0x02u);
    dst_p->error34 = unpack_right_shift_u8(src_p[4], 2u, 0x04u);
    dst_p->error35 = unpack_right_shift_u8(src_p[4], 3u, 0x08u);
    dst_p->error36 = unpack_right_shift_u8(src_p[4], 4u, 0x10u);
    dst_p->error37 = unpack_right_shift_u8(src_p[4], 5u, 0x20u);
    dst_p->error38 = unpack_right_shift_u8(src_p[4], 6u, 0x40u);
    dst_p->error39 = unpack_right_shift_u8(src_p[4], 7u, 0x80u);
    dst_p->error40 = unpack_right_shift_u8(src_p[5], 0u, 0x01u);
    dst_p->error41 = unpack_right_shift_u8(src_p[5], 1u, 0x02u);
    dst_p->error42 = unpack_right_shift_u8(src_p[5], 2u, 0x04u);
    dst_p->error43 = unpack_right_shift_u8(src_p[5], 3u, 0x08u);
    dst_p->error44 = unpack_right_shift_u8(src_p[5], 4u, 0x10u);
    dst_p->error45 = unpack_right_shift_u8(src_p[5], 5u, 0x20u);
    dst_p->error46 = unpack_right_shift_u8(src_p[5], 6u, 0x40u);
    dst_p->error47 = unpack_right_shift_u8(src_p[5], 7u, 0x80u);
    dst_p->error48 = unpack_right_shift_u8(src_p[6], 0u, 0x01u);
    dst_p->error49 = unpack_right_shift_u8(src_p[6], 1u, 0x02u);
    dst_p->error50 = unpack_right_shift_u8(src_p[6], 2u, 0x04u);
    dst_p->error51 = unpack_right_shift_u8(src_p[6], 3u, 0x08u);
    dst_p->error52 = unpack_right_shift_u8(src_p[6], 4u, 0x10u);
    dst_p->error53 = unpack_right_shift_u8(src_p[6], 5u, 0x20u);
    dst_p->error54 = unpack_right_shift_u8(src_p[6], 6u, 0x40u);
    dst_p->error55 = unpack_right_shift_u8(src_p[6], 7u, 0x80u);
    dst_p->error56 = unpack_right_shift_u8(src_p[7], 0u, 0x01u);
    dst_p->error57 = unpack_right_shift_u8(src_p[7], 1u, 0x02u);
    dst_p->error58 = unpack_right_shift_u8(src_p[7], 2u, 0x04u);
    dst_p->error59 = unpack_right_shift_u8(src_p[7], 3u, 0x08u);
    dst_p->error60 = unpack_right_shift_u8(src_p[7], 4u, 0x10u);
    dst_p->error61 = unpack_right_shift_u8(src_p[7], 5u, 0x20u);
    dst_p->error62 = unpack_right_shift_u8(src_p[7], 6u, 0x40u);
    dst_p->error63 = unpack_right_shift_u8(src_p[7], 7u, 0x80u);

    return (0);
}

int feb_can_dash_heartbeat_init(struct feb_can_dash_heartbeat_t *msg_p)
{
    if (msg_p == NULL) return -1;

    memset(msg_p, 0, sizeof(struct feb_can_dash_heartbeat_t));

    return 0;
}

uint8_t feb_can_dash_heartbeat_io_expander_error_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_dash_heartbeat_io_expander_error_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_dash_heartbeat_io_expander_error_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_dash_heartbeat_error1_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_dash_heartbeat_error1_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_dash_heartbeat_error1_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_dash_heartbeat_error2_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_dash_heartbeat_error2_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_dash_heartbeat_error2_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_dash_heartbeat_error3_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_dash_heartbeat_error3_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_dash_heartbeat_error3_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_dash_heartbeat_error4_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_dash_heartbeat_error4_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_dash_heartbeat_error4_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_dash_heartbeat_error5_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_dash_heartbeat_error5_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_dash_heartbeat_error5_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_dash_heartbeat_error6_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_dash_heartbeat_error6_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_dash_heartbeat_error6_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_dash_heartbeat_error7_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_dash_heartbeat_error7_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_dash_heartbeat_error7_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_dash_heartbeat_error8_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_dash_heartbeat_error8_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_dash_heartbeat_error8_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_dash_heartbeat_error9_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_dash_heartbeat_error9_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_dash_heartbeat_error9_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_dash_heartbeat_error10_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_dash_heartbeat_error10_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_dash_heartbeat_error10_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_dash_heartbeat_error11_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_dash_heartbeat_error11_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_dash_heartbeat_error11_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_dash_heartbeat_error12_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_dash_heartbeat_error12_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_dash_heartbeat_error12_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_dash_heartbeat_error13_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_dash_heartbeat_error13_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_dash_heartbeat_error13_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_dash_heartbeat_error14_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_dash_heartbeat_error14_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_dash_heartbeat_error14_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_dash_heartbeat_error15_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_dash_heartbeat_error15_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_dash_heartbeat_error15_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_dash_heartbeat_error16_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_dash_heartbeat_error16_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_dash_heartbeat_error16_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_dash_heartbeat_error17_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_dash_heartbeat_error17_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_dash_heartbeat_error17_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_dash_heartbeat_error18_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_dash_heartbeat_error18_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_dash_heartbeat_error18_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_dash_heartbeat_error19_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_dash_heartbeat_error19_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_dash_heartbeat_error19_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_dash_heartbeat_error20_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_dash_heartbeat_error20_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_dash_heartbeat_error20_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_dash_heartbeat_error21_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_dash_heartbeat_error21_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_dash_heartbeat_error21_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_dash_heartbeat_error22_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_dash_heartbeat_error22_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_dash_heartbeat_error22_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_dash_heartbeat_error23_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_dash_heartbeat_error23_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_dash_heartbeat_error23_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_dash_heartbeat_error24_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_dash_heartbeat_error24_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_dash_heartbeat_error24_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_dash_heartbeat_error25_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_dash_heartbeat_error25_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_dash_heartbeat_error25_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_dash_heartbeat_error26_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_dash_heartbeat_error26_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_dash_heartbeat_error26_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_dash_heartbeat_error27_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_dash_heartbeat_error27_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_dash_heartbeat_error27_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_dash_heartbeat_error28_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_dash_heartbeat_error28_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_dash_heartbeat_error28_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_dash_heartbeat_error29_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_dash_heartbeat_error29_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_dash_heartbeat_error29_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_dash_heartbeat_error30_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_dash_heartbeat_error30_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_dash_heartbeat_error30_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_dash_heartbeat_error31_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_dash_heartbeat_error31_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_dash_heartbeat_error31_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_dash_heartbeat_error32_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_dash_heartbeat_error32_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_dash_heartbeat_error32_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_dash_heartbeat_error33_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_dash_heartbeat_error33_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_dash_heartbeat_error33_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_dash_heartbeat_error34_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_dash_heartbeat_error34_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_dash_heartbeat_error34_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_dash_heartbeat_error35_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_dash_heartbeat_error35_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_dash_heartbeat_error35_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_dash_heartbeat_error36_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_dash_heartbeat_error36_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_dash_heartbeat_error36_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_dash_heartbeat_error37_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_dash_heartbeat_error37_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_dash_heartbeat_error37_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_dash_heartbeat_error38_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_dash_heartbeat_error38_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_dash_heartbeat_error38_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_dash_heartbeat_error39_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_dash_heartbeat_error39_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_dash_heartbeat_error39_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_dash_heartbeat_error40_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_dash_heartbeat_error40_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_dash_heartbeat_error40_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_dash_heartbeat_error41_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_dash_heartbeat_error41_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_dash_heartbeat_error41_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_dash_heartbeat_error42_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_dash_heartbeat_error42_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_dash_heartbeat_error42_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_dash_heartbeat_error43_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_dash_heartbeat_error43_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_dash_heartbeat_error43_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_dash_heartbeat_error44_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_dash_heartbeat_error44_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_dash_heartbeat_error44_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_dash_heartbeat_error45_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_dash_heartbeat_error45_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_dash_heartbeat_error45_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_dash_heartbeat_error46_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_dash_heartbeat_error46_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_dash_heartbeat_error46_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_dash_heartbeat_error47_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_dash_heartbeat_error47_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_dash_heartbeat_error47_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_dash_heartbeat_error48_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_dash_heartbeat_error48_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_dash_heartbeat_error48_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_dash_heartbeat_error49_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_dash_heartbeat_error49_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_dash_heartbeat_error49_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_dash_heartbeat_error50_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_dash_heartbeat_error50_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_dash_heartbeat_error50_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_dash_heartbeat_error51_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_dash_heartbeat_error51_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_dash_heartbeat_error51_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_dash_heartbeat_error52_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_dash_heartbeat_error52_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_dash_heartbeat_error52_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_dash_heartbeat_error53_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_dash_heartbeat_error53_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_dash_heartbeat_error53_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_dash_heartbeat_error54_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_dash_heartbeat_error54_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_dash_heartbeat_error54_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_dash_heartbeat_error55_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_dash_heartbeat_error55_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_dash_heartbeat_error55_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_dash_heartbeat_error56_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_dash_heartbeat_error56_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_dash_heartbeat_error56_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_dash_heartbeat_error57_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_dash_heartbeat_error57_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_dash_heartbeat_error57_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_dash_heartbeat_error58_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_dash_heartbeat_error58_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_dash_heartbeat_error58_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_dash_heartbeat_error59_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_dash_heartbeat_error59_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_dash_heartbeat_error59_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_dash_heartbeat_error60_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_dash_heartbeat_error60_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_dash_heartbeat_error60_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_dash_heartbeat_error61_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_dash_heartbeat_error61_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_dash_heartbeat_error61_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_dash_heartbeat_error62_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_dash_heartbeat_error62_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_dash_heartbeat_error62_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_dash_heartbeat_error63_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_dash_heartbeat_error63_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_dash_heartbeat_error63_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

int feb_can_lvpdb_heartbeat_pack(
    uint8_t *dst_p,
    const struct feb_can_lvpdb_heartbeat_t *src_p,
    size_t size)
{
    if (size < 8u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 8);

    dst_p[0] |= pack_left_shift_u8(src_p->tps_init_failed, 0u, 0x01u);
    dst_p[0] |= pack_left_shift_u8(src_p->tps_lv_poll_failed, 1u, 0x02u);
    dst_p[0] |= pack_left_shift_u8(src_p->tps_sh_poll_failed, 2u, 0x04u);
    dst_p[0] |= pack_left_shift_u8(src_p->tps_lt_poll_failed, 3u, 0x08u);
    dst_p[0] |= pack_left_shift_u8(src_p->tps_bm_l_poll_failed, 4u, 0x10u);
    dst_p[0] |= pack_left_shift_u8(src_p->tps_sm_poll_failed, 5u, 0x20u);
    dst_p[0] |= pack_left_shift_u8(src_p->tps_af1_af2_poll_failed, 6u, 0x40u);
    dst_p[0] |= pack_left_shift_u8(src_p->tps_cp_rf_poll_failed, 7u, 0x80u);
    dst_p[1] |= pack_left_shift_u8(src_p->tps_lv_power_not_good, 0u, 0x01u);
    dst_p[1] |= pack_left_shift_u8(src_p->tps_sh_power_not_good, 1u, 0x02u);
    dst_p[1] |= pack_left_shift_u8(src_p->tps_lt_power_not_good, 2u, 0x04u);
    dst_p[1] |= pack_left_shift_u8(src_p->tps_bm_l_power_not_good, 3u, 0x08u);
    dst_p[1] |= pack_left_shift_u8(src_p->tps_sm_power_not_good, 4u, 0x10u);
    dst_p[1] |= pack_left_shift_u8(src_p->tps_af1_af2_power_not_good, 5u, 0x20u);
    dst_p[1] |= pack_left_shift_u8(src_p->tps_cp_rf_power_not_good, 6u, 0x40u);
    dst_p[1] |= pack_left_shift_u8(src_p->dash_state_stale, 7u, 0x80u);
    dst_p[2] |= pack_left_shift_u8(src_p->error16, 0u, 0x01u);
    dst_p[2] |= pack_left_shift_u8(src_p->error17, 1u, 0x02u);
    dst_p[2] |= pack_left_shift_u8(src_p->error18, 2u, 0x04u);
    dst_p[2] |= pack_left_shift_u8(src_p->error19, 3u, 0x08u);
    dst_p[2] |= pack_left_shift_u8(src_p->error20, 4u, 0x10u);
    dst_p[2] |= pack_left_shift_u8(src_p->error21, 5u, 0x20u);
    dst_p[2] |= pack_left_shift_u8(src_p->error22, 6u, 0x40u);
    dst_p[2] |= pack_left_shift_u8(src_p->error23, 7u, 0x80u);
    dst_p[3] |= pack_left_shift_u8(src_p->error24, 0u, 0x01u);
    dst_p[3] |= pack_left_shift_u8(src_p->error25, 1u, 0x02u);
    dst_p[3] |= pack_left_shift_u8(src_p->error26, 2u, 0x04u);
    dst_p[3] |= pack_left_shift_u8(src_p->error27, 3u, 0x08u);
    dst_p[3] |= pack_left_shift_u8(src_p->error28, 4u, 0x10u);
    dst_p[3] |= pack_left_shift_u8(src_p->error29, 5u, 0x20u);
    dst_p[3] |= pack_left_shift_u8(src_p->error30, 6u, 0x40u);
    dst_p[3] |= pack_left_shift_u8(src_p->error31, 7u, 0x80u);
    dst_p[4] |= pack_left_shift_u8(src_p->error32, 0u, 0x01u);
    dst_p[4] |= pack_left_shift_u8(src_p->error33, 1u, 0x02u);
    dst_p[4] |= pack_left_shift_u8(src_p->error34, 2u, 0x04u);
    dst_p[4] |= pack_left_shift_u8(src_p->error35, 3u, 0x08u);
    dst_p[4] |= pack_left_shift_u8(src_p->error36, 4u, 0x10u);
    dst_p[4] |= pack_left_shift_u8(src_p->error37, 5u, 0x20u);
    dst_p[4] |= pack_left_shift_u8(src_p->error38, 6u, 0x40u);
    dst_p[4] |= pack_left_shift_u8(src_p->error39, 7u, 0x80u);
    dst_p[5] |= pack_left_shift_u8(src_p->error40, 0u, 0x01u);
    dst_p[5] |= pack_left_shift_u8(src_p->error41, 1u, 0x02u);
    dst_p[5] |= pack_left_shift_u8(src_p->error42, 2u, 0x04u);
    dst_p[5] |= pack_left_shift_u8(src_p->error43, 3u, 0x08u);
    dst_p[5] |= pack_left_shift_u8(src_p->error44, 4u, 0x10u);
    dst_p[5] |= pack_left_shift_u8(src_p->error45, 5u, 0x20u);
    dst_p[5] |= pack_left_shift_u8(src_p->error46, 6u, 0x40u);
    dst_p[5] |= pack_left_shift_u8(src_p->error47, 7u, 0x80u);
    dst_p[6] |= pack_left_shift_u8(src_p->error48, 0u, 0x01u);
    dst_p[6] |= pack_left_shift_u8(src_p->error49, 1u, 0x02u);
    dst_p[6] |= pack_left_shift_u8(src_p->error50, 2u, 0x04u);
    dst_p[6] |= pack_left_shift_u8(src_p->error51, 3u, 0x08u);
    dst_p[6] |= pack_left_shift_u8(src_p->error52, 4u, 0x10u);
    dst_p[6] |= pack_left_shift_u8(src_p->error53, 5u, 0x20u);
    dst_p[6] |= pack_left_shift_u8(src_p->error54, 6u, 0x40u);
    dst_p[6] |= pack_left_shift_u8(src_p->error55, 7u, 0x80u);
    dst_p[7] |= pack_left_shift_u8(src_p->error56, 0u, 0x01u);
    dst_p[7] |= pack_left_shift_u8(src_p->error57, 1u, 0x02u);
    dst_p[7] |= pack_left_shift_u8(src_p->error58, 2u, 0x04u);
    dst_p[7] |= pack_left_shift_u8(src_p->error59, 3u, 0x08u);
    dst_p[7] |= pack_left_shift_u8(src_p->error60, 4u, 0x10u);
    dst_p[7] |= pack_left_shift_u8(src_p->error61, 5u, 0x20u);
    dst_p[7] |= pack_left_shift_u8(src_p->error62, 6u, 0x40u);
    dst_p[7] |= pack_left_shift_u8(src_p->error63, 7u, 0x80u);

    return (8);
}

int feb_can_lvpdb_heartbeat_unpack(
    struct feb_can_lvpdb_heartbeat_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    if (size < 8u) {
        return (-EINVAL);
    }

    dst_p->tps_init_failed = unpack_right_shift_u8(src_p[0], 0u, 0x01u);
    dst_p->tps_lv_poll_failed = unpack_right_shift_u8(src_p[0], 1u, 0x02u);
    dst_p->tps_sh_poll_failed = unpack_right_shift_u8(src_p[0], 2u, 0x04u);
    dst_p->tps_lt_poll_failed = unpack_right_shift_u8(src_p[0], 3u, 0x08u);
    dst_p->tps_bm_l_poll_failed = unpack_right_shift_u8(src_p[0], 4u, 0x10u);
    dst_p->tps_sm_poll_failed = unpack_right_shift_u8(src_p[0], 5u, 0x20u);
    dst_p->tps_af1_af2_poll_failed = unpack_right_shift_u8(src_p[0], 6u, 0x40u);
    dst_p->tps_cp_rf_poll_failed = unpack_right_shift_u8(src_p[0], 7u, 0x80u);
    dst_p->tps_lv_power_not_good = unpack_right_shift_u8(src_p[1], 0u, 0x01u);
    dst_p->tps_sh_power_not_good = unpack_right_shift_u8(src_p[1], 1u, 0x02u);
    dst_p->tps_lt_power_not_good = unpack_right_shift_u8(src_p[1], 2u, 0x04u);
    dst_p->tps_bm_l_power_not_good = unpack_right_shift_u8(src_p[1], 3u, 0x08u);
    dst_p->tps_sm_power_not_good = unpack_right_shift_u8(src_p[1], 4u, 0x10u);
    dst_p->tps_af1_af2_power_not_good = unpack_right_shift_u8(src_p[1], 5u, 0x20u);
    dst_p->tps_cp_rf_power_not_good = unpack_right_shift_u8(src_p[1], 6u, 0x40u);
    dst_p->dash_state_stale = unpack_right_shift_u8(src_p[1], 7u, 0x80u);
    dst_p->error16 = unpack_right_shift_u8(src_p[2], 0u, 0x01u);
    dst_p->error17 = unpack_right_shift_u8(src_p[2], 1u, 0x02u);
    dst_p->error18 = unpack_right_shift_u8(src_p[2], 2u, 0x04u);
    dst_p->error19 = unpack_right_shift_u8(src_p[2], 3u, 0x08u);
    dst_p->error20 = unpack_right_shift_u8(src_p[2], 4u, 0x10u);
    dst_p->error21 = unpack_right_shift_u8(src_p[2], 5u, 0x20u);
    dst_p->error22 = unpack_right_shift_u8(src_p[2], 6u, 0x40u);
    dst_p->error23 = unpack_right_shift_u8(src_p[2], 7u, 0x80u);
    dst_p->error24 = unpack_right_shift_u8(src_p[3], 0u, 0x01u);
    dst_p->error25 = unpack_right_shift_u8(src_p[3], 1u, 0x02u);
    dst_p->error26 = unpack_right_shift_u8(src_p[3], 2u, 0x04u);
    dst_p->error27 = unpack_right_shift_u8(src_p[3], 3u, 0x08u);
    dst_p->error28 = unpack_right_shift_u8(src_p[3], 4u, 0x10u);
    dst_p->error29 = unpack_right_shift_u8(src_p[3], 5u, 0x20u);
    dst_p->error30 = unpack_right_shift_u8(src_p[3], 6u, 0x40u);
    dst_p->error31 = unpack_right_shift_u8(src_p[3], 7u, 0x80u);
    dst_p->error32 = unpack_right_shift_u8(src_p[4], 0u, 0x01u);
    dst_p->error33 = unpack_right_shift_u8(src_p[4], 1u, 0x02u);
    dst_p->error34 = unpack_right_shift_u8(src_p[4], 2u, 0x04u);
    dst_p->error35 = unpack_right_shift_u8(src_p[4], 3u, 0x08u);
    dst_p->error36 = unpack_right_shift_u8(src_p[4], 4u, 0x10u);
    dst_p->error37 = unpack_right_shift_u8(src_p[4], 5u, 0x20u);
    dst_p->error38 = unpack_right_shift_u8(src_p[4], 6u, 0x40u);
    dst_p->error39 = unpack_right_shift_u8(src_p[4], 7u, 0x80u);
    dst_p->error40 = unpack_right_shift_u8(src_p[5], 0u, 0x01u);
    dst_p->error41 = unpack_right_shift_u8(src_p[5], 1u, 0x02u);
    dst_p->error42 = unpack_right_shift_u8(src_p[5], 2u, 0x04u);
    dst_p->error43 = unpack_right_shift_u8(src_p[5], 3u, 0x08u);
    dst_p->error44 = unpack_right_shift_u8(src_p[5], 4u, 0x10u);
    dst_p->error45 = unpack_right_shift_u8(src_p[5], 5u, 0x20u);
    dst_p->error46 = unpack_right_shift_u8(src_p[5], 6u, 0x40u);
    dst_p->error47 = unpack_right_shift_u8(src_p[5], 7u, 0x80u);
    dst_p->error48 = unpack_right_shift_u8(src_p[6], 0u, 0x01u);
    dst_p->error49 = unpack_right_shift_u8(src_p[6], 1u, 0x02u);
    dst_p->error50 = unpack_right_shift_u8(src_p[6], 2u, 0x04u);
    dst_p->error51 = unpack_right_shift_u8(src_p[6], 3u, 0x08u);
    dst_p->error52 = unpack_right_shift_u8(src_p[6], 4u, 0x10u);
    dst_p->error53 = unpack_right_shift_u8(src_p[6], 5u, 0x20u);
    dst_p->error54 = unpack_right_shift_u8(src_p[6], 6u, 0x40u);
    dst_p->error55 = unpack_right_shift_u8(src_p[6], 7u, 0x80u);
    dst_p->error56 = unpack_right_shift_u8(src_p[7], 0u, 0x01u);
    dst_p->error57 = unpack_right_shift_u8(src_p[7], 1u, 0x02u);
    dst_p->error58 = unpack_right_shift_u8(src_p[7], 2u, 0x04u);
    dst_p->error59 = unpack_right_shift_u8(src_p[7], 3u, 0x08u);
    dst_p->error60 = unpack_right_shift_u8(src_p[7], 4u, 0x10u);
    dst_p->error61 = unpack_right_shift_u8(src_p[7], 5u, 0x20u);
    dst_p->error62 = unpack_right_shift_u8(src_p[7], 6u, 0x40u);
    dst_p->error63 = unpack_right_shift_u8(src_p[7], 7u, 0x80u);

    return (0);
}

int feb_can_lvpdb_heartbeat_init(struct feb_can_lvpdb_heartbeat_t *msg_p)
{
    if (msg_p == NULL) return -1;

    memset(msg_p, 0, sizeof(struct feb_can_lvpdb_heartbeat_t));

    return 0;
}

uint8_t feb_can_lvpdb_heartbeat_tps_init_failed_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_lvpdb_heartbeat_tps_init_failed_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_lvpdb_heartbeat_tps_init_failed_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_lvpdb_heartbeat_tps_lv_poll_failed_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_lvpdb_heartbeat_tps_lv_poll_failed_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_lvpdb_heartbeat_tps_lv_poll_failed_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_lvpdb_heartbeat_tps_sh_poll_failed_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_lvpdb_heartbeat_tps_sh_poll_failed_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_lvpdb_heartbeat_tps_sh_poll_failed_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_lvpdb_heartbeat_tps_lt_poll_failed_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_lvpdb_heartbeat_tps_lt_poll_failed_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_lvpdb_heartbeat_tps_lt_poll_failed_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_lvpdb_heartbeat_tps_bm_l_poll_failed_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_lvpdb_heartbeat_tps_bm_l_poll_failed_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_lvpdb_heartbeat_tps_bm_l_poll_failed_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_lvpdb_heartbeat_tps_sm_poll_failed_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_lvpdb_heartbeat_tps_sm_poll_failed_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_lvpdb_heartbeat_tps_sm_poll_failed_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_lvpdb_heartbeat_tps_af1_af2_poll_failed_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_lvpdb_heartbeat_tps_af1_af2_poll_failed_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_lvpdb_heartbeat_tps_af1_af2_poll_failed_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_lvpdb_heartbeat_tps_cp_rf_poll_failed_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_lvpdb_heartbeat_tps_cp_rf_poll_failed_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_lvpdb_heartbeat_tps_cp_rf_poll_failed_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_lvpdb_heartbeat_tps_lv_power_not_good_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_lvpdb_heartbeat_tps_lv_power_not_good_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_lvpdb_heartbeat_tps_lv_power_not_good_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_lvpdb_heartbeat_tps_sh_power_not_good_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_lvpdb_heartbeat_tps_sh_power_not_good_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_lvpdb_heartbeat_tps_sh_power_not_good_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_lvpdb_heartbeat_tps_lt_power_not_good_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_lvpdb_heartbeat_tps_lt_power_not_good_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_lvpdb_heartbeat_tps_lt_power_not_good_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_lvpdb_heartbeat_tps_bm_l_power_not_good_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_lvpdb_heartbeat_tps_bm_l_power_not_good_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_lvpdb_heartbeat_tps_bm_l_power_not_good_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_lvpdb_heartbeat_tps_sm_power_not_good_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_lvpdb_heartbeat_tps_sm_power_not_good_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_lvpdb_heartbeat_tps_sm_power_not_good_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_lvpdb_heartbeat_tps_af1_af2_power_not_good_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_lvpdb_heartbeat_tps_af1_af2_power_not_good_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_lvpdb_heartbeat_tps_af1_af2_power_not_good_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_lvpdb_heartbeat_tps_cp_rf_power_not_good_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_lvpdb_heartbeat_tps_cp_rf_power_not_good_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_lvpdb_heartbeat_tps_cp_rf_power_not_good_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_lvpdb_heartbeat_dash_state_stale_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_lvpdb_heartbeat_dash_state_stale_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_lvpdb_heartbeat_dash_state_stale_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_lvpdb_heartbeat_error16_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_lvpdb_heartbeat_error16_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_lvpdb_heartbeat_error16_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_lvpdb_heartbeat_error17_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_lvpdb_heartbeat_error17_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_lvpdb_heartbeat_error17_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_lvpdb_heartbeat_error18_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_lvpdb_heartbeat_error18_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_lvpdb_heartbeat_error18_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_lvpdb_heartbeat_error19_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_lvpdb_heartbeat_error19_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_lvpdb_heartbeat_error19_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_lvpdb_heartbeat_error20_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_lvpdb_heartbeat_error20_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_lvpdb_heartbeat_error20_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_lvpdb_heartbeat_error21_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_lvpdb_heartbeat_error21_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_lvpdb_heartbeat_error21_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_lvpdb_heartbeat_error22_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_lvpdb_heartbeat_error22_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_lvpdb_heartbeat_error22_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_lvpdb_heartbeat_error23_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_lvpdb_heartbeat_error23_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_lvpdb_heartbeat_error23_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_lvpdb_heartbeat_error24_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_lvpdb_heartbeat_error24_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_lvpdb_heartbeat_error24_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_lvpdb_heartbeat_error25_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_lvpdb_heartbeat_error25_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_lvpdb_heartbeat_error25_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_lvpdb_heartbeat_error26_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_lvpdb_heartbeat_error26_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_lvpdb_heartbeat_error26_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_lvpdb_heartbeat_error27_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_lvpdb_heartbeat_error27_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_lvpdb_heartbeat_error27_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_lvpdb_heartbeat_error28_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_lvpdb_heartbeat_error28_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_lvpdb_heartbeat_error28_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_lvpdb_heartbeat_error29_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_lvpdb_heartbeat_error29_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_lvpdb_heartbeat_error29_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_lvpdb_heartbeat_error30_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_lvpdb_heartbeat_error30_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_lvpdb_heartbeat_error30_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_lvpdb_heartbeat_error31_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_lvpdb_heartbeat_error31_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_lvpdb_heartbeat_error31_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_lvpdb_heartbeat_error32_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_lvpdb_heartbeat_error32_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_lvpdb_heartbeat_error32_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_lvpdb_heartbeat_error33_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_lvpdb_heartbeat_error33_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_lvpdb_heartbeat_error33_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_lvpdb_heartbeat_error34_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_lvpdb_heartbeat_error34_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_lvpdb_heartbeat_error34_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_lvpdb_heartbeat_error35_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_lvpdb_heartbeat_error35_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_lvpdb_heartbeat_error35_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_lvpdb_heartbeat_error36_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_lvpdb_heartbeat_error36_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_lvpdb_heartbeat_error36_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_lvpdb_heartbeat_error37_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_lvpdb_heartbeat_error37_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_lvpdb_heartbeat_error37_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_lvpdb_heartbeat_error38_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_lvpdb_heartbeat_error38_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_lvpdb_heartbeat_error38_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_lvpdb_heartbeat_error39_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_lvpdb_heartbeat_error39_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_lvpdb_heartbeat_error39_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_lvpdb_heartbeat_error40_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_lvpdb_heartbeat_error40_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_lvpdb_heartbeat_error40_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_lvpdb_heartbeat_error41_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_lvpdb_heartbeat_error41_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_lvpdb_heartbeat_error41_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_lvpdb_heartbeat_error42_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_lvpdb_heartbeat_error42_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_lvpdb_heartbeat_error42_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_lvpdb_heartbeat_error43_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_lvpdb_heartbeat_error43_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_lvpdb_heartbeat_error43_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_lvpdb_heartbeat_error44_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_lvpdb_heartbeat_error44_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_lvpdb_heartbeat_error44_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_lvpdb_heartbeat_error45_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_lvpdb_heartbeat_error45_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_lvpdb_heartbeat_error45_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_lvpdb_heartbeat_error46_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_lvpdb_heartbeat_error46_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_lvpdb_heartbeat_error46_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_lvpdb_heartbeat_error47_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_lvpdb_heartbeat_error47_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_lvpdb_heartbeat_error47_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_lvpdb_heartbeat_error48_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_lvpdb_heartbeat_error48_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_lvpdb_heartbeat_error48_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_lvpdb_heartbeat_error49_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_lvpdb_heartbeat_error49_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_lvpdb_heartbeat_error49_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_lvpdb_heartbeat_error50_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_lvpdb_heartbeat_error50_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_lvpdb_heartbeat_error50_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_lvpdb_heartbeat_error51_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_lvpdb_heartbeat_error51_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_lvpdb_heartbeat_error51_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_lvpdb_heartbeat_error52_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_lvpdb_heartbeat_error52_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_lvpdb_heartbeat_error52_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_lvpdb_heartbeat_error53_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_lvpdb_heartbeat_error53_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_lvpdb_heartbeat_error53_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_lvpdb_heartbeat_error54_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_lvpdb_heartbeat_error54_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_lvpdb_heartbeat_error54_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_lvpdb_heartbeat_error55_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_lvpdb_heartbeat_error55_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_lvpdb_heartbeat_error55_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_lvpdb_heartbeat_error56_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_lvpdb_heartbeat_error56_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_lvpdb_heartbeat_error56_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_lvpdb_heartbeat_error57_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_lvpdb_heartbeat_error57_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_lvpdb_heartbeat_error57_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_lvpdb_heartbeat_error58_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_lvpdb_heartbeat_error58_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_lvpdb_heartbeat_error58_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_lvpdb_heartbeat_error59_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_lvpdb_heartbeat_error59_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_lvpdb_heartbeat_error59_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_lvpdb_heartbeat_error60_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_lvpdb_heartbeat_error60_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_lvpdb_heartbeat_error60_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_lvpdb_heartbeat_error61_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_lvpdb_heartbeat_error61_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_lvpdb_heartbeat_error61_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_lvpdb_heartbeat_error62_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_lvpdb_heartbeat_error62_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_lvpdb_heartbeat_error62_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_lvpdb_heartbeat_error63_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_lvpdb_heartbeat_error63_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_lvpdb_heartbeat_error63_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

int feb_can_dcu_heartbeat_pack(
    uint8_t *dst_p,
    const struct feb_can_dcu_heartbeat_t *src_p,
    size_t size)
{
    if (size < 8u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 8);

    dst_p[0] |= pack_left_shift_u8(src_p->error0, 0u, 0x01u);
    dst_p[0] |= pack_left_shift_u8(src_p->error1, 1u, 0x02u);
    dst_p[0] |= pack_left_shift_u8(src_p->error2, 2u, 0x04u);
    dst_p[0] |= pack_left_shift_u8(src_p->error3, 3u, 0x08u);
    dst_p[0] |= pack_left_shift_u8(src_p->error4, 4u, 0x10u);
    dst_p[0] |= pack_left_shift_u8(src_p->error5, 5u, 0x20u);
    dst_p[0] |= pack_left_shift_u8(src_p->error6, 6u, 0x40u);
    dst_p[0] |= pack_left_shift_u8(src_p->error7, 7u, 0x80u);
    dst_p[1] |= pack_left_shift_u8(src_p->error8, 0u, 0x01u);
    dst_p[1] |= pack_left_shift_u8(src_p->error9, 1u, 0x02u);
    dst_p[1] |= pack_left_shift_u8(src_p->error10, 2u, 0x04u);
    dst_p[1] |= pack_left_shift_u8(src_p->error11, 3u, 0x08u);
    dst_p[1] |= pack_left_shift_u8(src_p->error12, 4u, 0x10u);
    dst_p[1] |= pack_left_shift_u8(src_p->error13, 5u, 0x20u);
    dst_p[1] |= pack_left_shift_u8(src_p->error14, 6u, 0x40u);
    dst_p[1] |= pack_left_shift_u8(src_p->error15, 7u, 0x80u);
    dst_p[2] |= pack_left_shift_u8(src_p->error16, 0u, 0x01u);
    dst_p[2] |= pack_left_shift_u8(src_p->error17, 1u, 0x02u);
    dst_p[2] |= pack_left_shift_u8(src_p->error18, 2u, 0x04u);
    dst_p[2] |= pack_left_shift_u8(src_p->error19, 3u, 0x08u);
    dst_p[2] |= pack_left_shift_u8(src_p->error20, 4u, 0x10u);
    dst_p[2] |= pack_left_shift_u8(src_p->error21, 5u, 0x20u);
    dst_p[2] |= pack_left_shift_u8(src_p->error22, 6u, 0x40u);
    dst_p[2] |= pack_left_shift_u8(src_p->error23, 7u, 0x80u);
    dst_p[3] |= pack_left_shift_u8(src_p->error24, 0u, 0x01u);
    dst_p[3] |= pack_left_shift_u8(src_p->error25, 1u, 0x02u);
    dst_p[3] |= pack_left_shift_u8(src_p->error26, 2u, 0x04u);
    dst_p[3] |= pack_left_shift_u8(src_p->error27, 3u, 0x08u);
    dst_p[3] |= pack_left_shift_u8(src_p->error28, 4u, 0x10u);
    dst_p[3] |= pack_left_shift_u8(src_p->error29, 5u, 0x20u);
    dst_p[3] |= pack_left_shift_u8(src_p->error30, 6u, 0x40u);
    dst_p[3] |= pack_left_shift_u8(src_p->error31, 7u, 0x80u);
    dst_p[4] |= pack_left_shift_u8(src_p->error32, 0u, 0x01u);
    dst_p[4] |= pack_left_shift_u8(src_p->error33, 1u, 0x02u);
    dst_p[4] |= pack_left_shift_u8(src_p->error34, 2u, 0x04u);
    dst_p[4] |= pack_left_shift_u8(src_p->error35, 3u, 0x08u);
    dst_p[4] |= pack_left_shift_u8(src_p->error36, 4u, 0x10u);
    dst_p[4] |= pack_left_shift_u8(src_p->error37, 5u, 0x20u);
    dst_p[4] |= pack_left_shift_u8(src_p->error38, 6u, 0x40u);
    dst_p[4] |= pack_left_shift_u8(src_p->error39, 7u, 0x80u);
    dst_p[5] |= pack_left_shift_u8(src_p->error40, 0u, 0x01u);
    dst_p[5] |= pack_left_shift_u8(src_p->error41, 1u, 0x02u);
    dst_p[5] |= pack_left_shift_u8(src_p->error42, 2u, 0x04u);
    dst_p[5] |= pack_left_shift_u8(src_p->error43, 3u, 0x08u);
    dst_p[5] |= pack_left_shift_u8(src_p->error44, 4u, 0x10u);
    dst_p[5] |= pack_left_shift_u8(src_p->error45, 5u, 0x20u);
    dst_p[5] |= pack_left_shift_u8(src_p->error46, 6u, 0x40u);
    dst_p[5] |= pack_left_shift_u8(src_p->error47, 7u, 0x80u);
    dst_p[6] |= pack_left_shift_u8(src_p->error48, 0u, 0x01u);
    dst_p[6] |= pack_left_shift_u8(src_p->error49, 1u, 0x02u);
    dst_p[6] |= pack_left_shift_u8(src_p->error50, 2u, 0x04u);
    dst_p[6] |= pack_left_shift_u8(src_p->error51, 3u, 0x08u);
    dst_p[6] |= pack_left_shift_u8(src_p->error52, 4u, 0x10u);
    dst_p[6] |= pack_left_shift_u8(src_p->error53, 5u, 0x20u);
    dst_p[6] |= pack_left_shift_u8(src_p->error54, 6u, 0x40u);
    dst_p[6] |= pack_left_shift_u8(src_p->error55, 7u, 0x80u);
    dst_p[7] |= pack_left_shift_u8(src_p->error56, 0u, 0x01u);
    dst_p[7] |= pack_left_shift_u8(src_p->error57, 1u, 0x02u);
    dst_p[7] |= pack_left_shift_u8(src_p->error58, 2u, 0x04u);
    dst_p[7] |= pack_left_shift_u8(src_p->error59, 3u, 0x08u);
    dst_p[7] |= pack_left_shift_u8(src_p->error60, 4u, 0x10u);
    dst_p[7] |= pack_left_shift_u8(src_p->error61, 5u, 0x20u);
    dst_p[7] |= pack_left_shift_u8(src_p->error62, 6u, 0x40u);
    dst_p[7] |= pack_left_shift_u8(src_p->error63, 7u, 0x80u);

    return (8);
}

int feb_can_dcu_heartbeat_unpack(
    struct feb_can_dcu_heartbeat_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    if (size < 8u) {
        return (-EINVAL);
    }

    dst_p->error0 = unpack_right_shift_u8(src_p[0], 0u, 0x01u);
    dst_p->error1 = unpack_right_shift_u8(src_p[0], 1u, 0x02u);
    dst_p->error2 = unpack_right_shift_u8(src_p[0], 2u, 0x04u);
    dst_p->error3 = unpack_right_shift_u8(src_p[0], 3u, 0x08u);
    dst_p->error4 = unpack_right_shift_u8(src_p[0], 4u, 0x10u);
    dst_p->error5 = unpack_right_shift_u8(src_p[0], 5u, 0x20u);
    dst_p->error6 = unpack_right_shift_u8(src_p[0], 6u, 0x40u);
    dst_p->error7 = unpack_right_shift_u8(src_p[0], 7u, 0x80u);
    dst_p->error8 = unpack_right_shift_u8(src_p[1], 0u, 0x01u);
    dst_p->error9 = unpack_right_shift_u8(src_p[1], 1u, 0x02u);
    dst_p->error10 = unpack_right_shift_u8(src_p[1], 2u, 0x04u);
    dst_p->error11 = unpack_right_shift_u8(src_p[1], 3u, 0x08u);
    dst_p->error12 = unpack_right_shift_u8(src_p[1], 4u, 0x10u);
    dst_p->error13 = unpack_right_shift_u8(src_p[1], 5u, 0x20u);
    dst_p->error14 = unpack_right_shift_u8(src_p[1], 6u, 0x40u);
    dst_p->error15 = unpack_right_shift_u8(src_p[1], 7u, 0x80u);
    dst_p->error16 = unpack_right_shift_u8(src_p[2], 0u, 0x01u);
    dst_p->error17 = unpack_right_shift_u8(src_p[2], 1u, 0x02u);
    dst_p->error18 = unpack_right_shift_u8(src_p[2], 2u, 0x04u);
    dst_p->error19 = unpack_right_shift_u8(src_p[2], 3u, 0x08u);
    dst_p->error20 = unpack_right_shift_u8(src_p[2], 4u, 0x10u);
    dst_p->error21 = unpack_right_shift_u8(src_p[2], 5u, 0x20u);
    dst_p->error22 = unpack_right_shift_u8(src_p[2], 6u, 0x40u);
    dst_p->error23 = unpack_right_shift_u8(src_p[2], 7u, 0x80u);
    dst_p->error24 = unpack_right_shift_u8(src_p[3], 0u, 0x01u);
    dst_p->error25 = unpack_right_shift_u8(src_p[3], 1u, 0x02u);
    dst_p->error26 = unpack_right_shift_u8(src_p[3], 2u, 0x04u);
    dst_p->error27 = unpack_right_shift_u8(src_p[3], 3u, 0x08u);
    dst_p->error28 = unpack_right_shift_u8(src_p[3], 4u, 0x10u);
    dst_p->error29 = unpack_right_shift_u8(src_p[3], 5u, 0x20u);
    dst_p->error30 = unpack_right_shift_u8(src_p[3], 6u, 0x40u);
    dst_p->error31 = unpack_right_shift_u8(src_p[3], 7u, 0x80u);
    dst_p->error32 = unpack_right_shift_u8(src_p[4], 0u, 0x01u);
    dst_p->error33 = unpack_right_shift_u8(src_p[4], 1u, 0x02u);
    dst_p->error34 = unpack_right_shift_u8(src_p[4], 2u, 0x04u);
    dst_p->error35 = unpack_right_shift_u8(src_p[4], 3u, 0x08u);
    dst_p->error36 = unpack_right_shift_u8(src_p[4], 4u, 0x10u);
    dst_p->error37 = unpack_right_shift_u8(src_p[4], 5u, 0x20u);
    dst_p->error38 = unpack_right_shift_u8(src_p[4], 6u, 0x40u);
    dst_p->error39 = unpack_right_shift_u8(src_p[4], 7u, 0x80u);
    dst_p->error40 = unpack_right_shift_u8(src_p[5], 0u, 0x01u);
    dst_p->error41 = unpack_right_shift_u8(src_p[5], 1u, 0x02u);
    dst_p->error42 = unpack_right_shift_u8(src_p[5], 2u, 0x04u);
    dst_p->error43 = unpack_right_shift_u8(src_p[5], 3u, 0x08u);
    dst_p->error44 = unpack_right_shift_u8(src_p[5], 4u, 0x10u);
    dst_p->error45 = unpack_right_shift_u8(src_p[5], 5u, 0x20u);
    dst_p->error46 = unpack_right_shift_u8(src_p[5], 6u, 0x40u);
    dst_p->error47 = unpack_right_shift_u8(src_p[5], 7u, 0x80u);
    dst_p->error48 = unpack_right_shift_u8(src_p[6], 0u, 0x01u);
    dst_p->error49 = unpack_right_shift_u8(src_p[6], 1u, 0x02u);
    dst_p->error50 = unpack_right_shift_u8(src_p[6], 2u, 0x04u);
    dst_p->error51 = unpack_right_shift_u8(src_p[6], 3u, 0x08u);
    dst_p->error52 = unpack_right_shift_u8(src_p[6], 4u, 0x10u);
    dst_p->error53 = unpack_right_shift_u8(src_p[6], 5u, 0x20u);
    dst_p->error54 = unpack_right_shift_u8(src_p[6], 6u, 0x40u);
    dst_p->error55 = unpack_right_shift_u8(src_p[6], 7u, 0x80u);
    dst_p->error56 = unpack_right_shift_u8(src_p[7], 0u, 0x01u);
    dst_p->error57 = unpack_right_shift_u8(src_p[7], 1u, 0x02u);
    dst_p->error58 = unpack_right_shift_u8(src_p[7], 2u, 0x04u);
    dst_p->error59 = unpack_right_shift_u8(src_p[7], 3u, 0x08u);
    dst_p->error60 = unpack_right_shift_u8(src_p[7], 4u, 0x10u);
    dst_p->error61 = unpack_right_shift_u8(src_p[7], 5u, 0x20u);
    dst_p->error62 = unpack_right_shift_u8(src_p[7], 6u, 0x40u);
    dst_p->error63 = unpack_right_shift_u8(src_p[7], 7u, 0x80u);

    return (0);
}

int feb_can_dcu_heartbeat_init(struct feb_can_dcu_heartbeat_t *msg_p)
{
    if (msg_p == NULL) return -1;

    memset(msg_p, 0, sizeof(struct feb_can_dcu_heartbeat_t));

    return 0;
}

uint8_t feb_can_dcu_heartbeat_error0_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_dcu_heartbeat_error0_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_dcu_heartbeat_error0_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_dcu_heartbeat_error1_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_dcu_heartbeat_error1_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_dcu_heartbeat_error1_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_dcu_heartbeat_error2_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_dcu_heartbeat_error2_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_dcu_heartbeat_error2_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_dcu_heartbeat_error3_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_dcu_heartbeat_error3_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_dcu_heartbeat_error3_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_dcu_heartbeat_error4_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_dcu_heartbeat_error4_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_dcu_heartbeat_error4_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_dcu_heartbeat_error5_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_dcu_heartbeat_error5_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_dcu_heartbeat_error5_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_dcu_heartbeat_error6_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_dcu_heartbeat_error6_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_dcu_heartbeat_error6_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_dcu_heartbeat_error7_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_dcu_heartbeat_error7_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_dcu_heartbeat_error7_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_dcu_heartbeat_error8_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_dcu_heartbeat_error8_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_dcu_heartbeat_error8_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_dcu_heartbeat_error9_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_dcu_heartbeat_error9_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_dcu_heartbeat_error9_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_dcu_heartbeat_error10_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_dcu_heartbeat_error10_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_dcu_heartbeat_error10_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_dcu_heartbeat_error11_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_dcu_heartbeat_error11_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_dcu_heartbeat_error11_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_dcu_heartbeat_error12_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_dcu_heartbeat_error12_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_dcu_heartbeat_error12_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_dcu_heartbeat_error13_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_dcu_heartbeat_error13_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_dcu_heartbeat_error13_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_dcu_heartbeat_error14_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_dcu_heartbeat_error14_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_dcu_heartbeat_error14_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_dcu_heartbeat_error15_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_dcu_heartbeat_error15_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_dcu_heartbeat_error15_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_dcu_heartbeat_error16_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_dcu_heartbeat_error16_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_dcu_heartbeat_error16_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_dcu_heartbeat_error17_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_dcu_heartbeat_error17_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_dcu_heartbeat_error17_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_dcu_heartbeat_error18_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_dcu_heartbeat_error18_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_dcu_heartbeat_error18_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_dcu_heartbeat_error19_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_dcu_heartbeat_error19_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_dcu_heartbeat_error19_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_dcu_heartbeat_error20_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_dcu_heartbeat_error20_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_dcu_heartbeat_error20_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_dcu_heartbeat_error21_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_dcu_heartbeat_error21_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_dcu_heartbeat_error21_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_dcu_heartbeat_error22_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_dcu_heartbeat_error22_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_dcu_heartbeat_error22_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_dcu_heartbeat_error23_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_dcu_heartbeat_error23_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_dcu_heartbeat_error23_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_dcu_heartbeat_error24_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_dcu_heartbeat_error24_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_dcu_heartbeat_error24_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_dcu_heartbeat_error25_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_dcu_heartbeat_error25_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_dcu_heartbeat_error25_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_dcu_heartbeat_error26_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_dcu_heartbeat_error26_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_dcu_heartbeat_error26_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_dcu_heartbeat_error27_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_dcu_heartbeat_error27_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_dcu_heartbeat_error27_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_dcu_heartbeat_error28_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_dcu_heartbeat_error28_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_dcu_heartbeat_error28_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_dcu_heartbeat_error29_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_dcu_heartbeat_error29_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_dcu_heartbeat_error29_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_dcu_heartbeat_error30_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_dcu_heartbeat_error30_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_dcu_heartbeat_error30_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_dcu_heartbeat_error31_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_dcu_heartbeat_error31_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_dcu_heartbeat_error31_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_dcu_heartbeat_error32_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_dcu_heartbeat_error32_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_dcu_heartbeat_error32_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_dcu_heartbeat_error33_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_dcu_heartbeat_error33_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_dcu_heartbeat_error33_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_dcu_heartbeat_error34_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_dcu_heartbeat_error34_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_dcu_heartbeat_error34_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_dcu_heartbeat_error35_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_dcu_heartbeat_error35_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_dcu_heartbeat_error35_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_dcu_heartbeat_error36_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_dcu_heartbeat_error36_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_dcu_heartbeat_error36_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_dcu_heartbeat_error37_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_dcu_heartbeat_error37_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_dcu_heartbeat_error37_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_dcu_heartbeat_error38_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_dcu_heartbeat_error38_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_dcu_heartbeat_error38_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_dcu_heartbeat_error39_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_dcu_heartbeat_error39_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_dcu_heartbeat_error39_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_dcu_heartbeat_error40_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_dcu_heartbeat_error40_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_dcu_heartbeat_error40_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_dcu_heartbeat_error41_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_dcu_heartbeat_error41_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_dcu_heartbeat_error41_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_dcu_heartbeat_error42_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_dcu_heartbeat_error42_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_dcu_heartbeat_error42_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_dcu_heartbeat_error43_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_dcu_heartbeat_error43_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_dcu_heartbeat_error43_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_dcu_heartbeat_error44_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_dcu_heartbeat_error44_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_dcu_heartbeat_error44_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_dcu_heartbeat_error45_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_dcu_heartbeat_error45_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_dcu_heartbeat_error45_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_dcu_heartbeat_error46_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_dcu_heartbeat_error46_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_dcu_heartbeat_error46_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_dcu_heartbeat_error47_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_dcu_heartbeat_error47_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_dcu_heartbeat_error47_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_dcu_heartbeat_error48_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_dcu_heartbeat_error48_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_dcu_heartbeat_error48_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_dcu_heartbeat_error49_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_dcu_heartbeat_error49_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_dcu_heartbeat_error49_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_dcu_heartbeat_error50_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_dcu_heartbeat_error50_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_dcu_heartbeat_error50_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_dcu_heartbeat_error51_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_dcu_heartbeat_error51_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_dcu_heartbeat_error51_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_dcu_heartbeat_error52_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_dcu_heartbeat_error52_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_dcu_heartbeat_error52_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_dcu_heartbeat_error53_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_dcu_heartbeat_error53_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_dcu_heartbeat_error53_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_dcu_heartbeat_error54_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_dcu_heartbeat_error54_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_dcu_heartbeat_error54_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_dcu_heartbeat_error55_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_dcu_heartbeat_error55_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_dcu_heartbeat_error55_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_dcu_heartbeat_error56_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_dcu_heartbeat_error56_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_dcu_heartbeat_error56_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_dcu_heartbeat_error57_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_dcu_heartbeat_error57_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_dcu_heartbeat_error57_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_dcu_heartbeat_error58_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_dcu_heartbeat_error58_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_dcu_heartbeat_error58_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_dcu_heartbeat_error59_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_dcu_heartbeat_error59_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_dcu_heartbeat_error59_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_dcu_heartbeat_error60_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_dcu_heartbeat_error60_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_dcu_heartbeat_error60_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_dcu_heartbeat_error61_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_dcu_heartbeat_error61_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_dcu_heartbeat_error61_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_dcu_heartbeat_error62_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_dcu_heartbeat_error62_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_dcu_heartbeat_error62_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_dcu_heartbeat_error63_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_dcu_heartbeat_error63_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_dcu_heartbeat_error63_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

int feb_can_front_sensor_heartbeat_message_pack(
    uint8_t *dst_p,
    const struct feb_can_front_sensor_heartbeat_message_t *src_p,
    size_t size)
{
    if (size < 8u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 8);

    dst_p[0] |= pack_left_shift_u8(src_p->error0, 0u, 0x01u);
    dst_p[0] |= pack_left_shift_u8(src_p->error1, 1u, 0x02u);
    dst_p[0] |= pack_left_shift_u8(src_p->error2, 2u, 0x04u);
    dst_p[0] |= pack_left_shift_u8(src_p->error3, 3u, 0x08u);
    dst_p[0] |= pack_left_shift_u8(src_p->error4, 4u, 0x10u);
    dst_p[0] |= pack_left_shift_u8(src_p->error5, 5u, 0x20u);
    dst_p[0] |= pack_left_shift_u8(src_p->error6, 6u, 0x40u);
    dst_p[0] |= pack_left_shift_u8(src_p->error7, 7u, 0x80u);
    dst_p[1] |= pack_left_shift_u8(src_p->error8, 0u, 0x01u);
    dst_p[1] |= pack_left_shift_u8(src_p->error9, 1u, 0x02u);
    dst_p[1] |= pack_left_shift_u8(src_p->error10, 2u, 0x04u);
    dst_p[1] |= pack_left_shift_u8(src_p->error11, 3u, 0x08u);
    dst_p[1] |= pack_left_shift_u8(src_p->error12, 4u, 0x10u);
    dst_p[1] |= pack_left_shift_u8(src_p->error13, 5u, 0x20u);
    dst_p[1] |= pack_left_shift_u8(src_p->error14, 6u, 0x40u);
    dst_p[1] |= pack_left_shift_u8(src_p->error15, 7u, 0x80u);
    dst_p[2] |= pack_left_shift_u8(src_p->error16, 0u, 0x01u);
    dst_p[2] |= pack_left_shift_u8(src_p->error17, 1u, 0x02u);
    dst_p[2] |= pack_left_shift_u8(src_p->error18, 2u, 0x04u);
    dst_p[2] |= pack_left_shift_u8(src_p->error19, 3u, 0x08u);
    dst_p[2] |= pack_left_shift_u8(src_p->error20, 4u, 0x10u);
    dst_p[2] |= pack_left_shift_u8(src_p->error21, 5u, 0x20u);
    dst_p[2] |= pack_left_shift_u8(src_p->error22, 6u, 0x40u);
    dst_p[2] |= pack_left_shift_u8(src_p->error23, 7u, 0x80u);
    dst_p[3] |= pack_left_shift_u8(src_p->error24, 0u, 0x01u);
    dst_p[3] |= pack_left_shift_u8(src_p->error25, 1u, 0x02u);
    dst_p[3] |= pack_left_shift_u8(src_p->error26, 2u, 0x04u);
    dst_p[3] |= pack_left_shift_u8(src_p->error27, 3u, 0x08u);
    dst_p[3] |= pack_left_shift_u8(src_p->error28, 4u, 0x10u);
    dst_p[3] |= pack_left_shift_u8(src_p->error29, 5u, 0x20u);
    dst_p[3] |= pack_left_shift_u8(src_p->error30, 6u, 0x40u);
    dst_p[3] |= pack_left_shift_u8(src_p->error31, 7u, 0x80u);
    dst_p[4] |= pack_left_shift_u8(src_p->error32, 0u, 0x01u);
    dst_p[4] |= pack_left_shift_u8(src_p->error33, 1u, 0x02u);
    dst_p[4] |= pack_left_shift_u8(src_p->error34, 2u, 0x04u);
    dst_p[4] |= pack_left_shift_u8(src_p->error35, 3u, 0x08u);
    dst_p[4] |= pack_left_shift_u8(src_p->error36, 4u, 0x10u);
    dst_p[4] |= pack_left_shift_u8(src_p->error37, 5u, 0x20u);
    dst_p[4] |= pack_left_shift_u8(src_p->error38, 6u, 0x40u);
    dst_p[4] |= pack_left_shift_u8(src_p->error39, 7u, 0x80u);
    dst_p[5] |= pack_left_shift_u8(src_p->error40, 0u, 0x01u);
    dst_p[5] |= pack_left_shift_u8(src_p->error41, 1u, 0x02u);
    dst_p[5] |= pack_left_shift_u8(src_p->error42, 2u, 0x04u);
    dst_p[5] |= pack_left_shift_u8(src_p->error43, 3u, 0x08u);
    dst_p[5] |= pack_left_shift_u8(src_p->error44, 4u, 0x10u);
    dst_p[5] |= pack_left_shift_u8(src_p->error45, 5u, 0x20u);
    dst_p[5] |= pack_left_shift_u8(src_p->error46, 6u, 0x40u);
    dst_p[5] |= pack_left_shift_u8(src_p->error47, 7u, 0x80u);
    dst_p[6] |= pack_left_shift_u8(src_p->error48, 0u, 0x01u);
    dst_p[6] |= pack_left_shift_u8(src_p->error49, 1u, 0x02u);
    dst_p[6] |= pack_left_shift_u8(src_p->error50, 2u, 0x04u);
    dst_p[6] |= pack_left_shift_u8(src_p->error51, 3u, 0x08u);
    dst_p[6] |= pack_left_shift_u8(src_p->error52, 4u, 0x10u);
    dst_p[6] |= pack_left_shift_u8(src_p->error53, 5u, 0x20u);
    dst_p[6] |= pack_left_shift_u8(src_p->error54, 6u, 0x40u);
    dst_p[6] |= pack_left_shift_u8(src_p->error55, 7u, 0x80u);
    dst_p[7] |= pack_left_shift_u8(src_p->error56, 0u, 0x01u);
    dst_p[7] |= pack_left_shift_u8(src_p->error57, 1u, 0x02u);
    dst_p[7] |= pack_left_shift_u8(src_p->error58, 2u, 0x04u);
    dst_p[7] |= pack_left_shift_u8(src_p->error59, 3u, 0x08u);
    dst_p[7] |= pack_left_shift_u8(src_p->error60, 4u, 0x10u);
    dst_p[7] |= pack_left_shift_u8(src_p->error61, 5u, 0x20u);
    dst_p[7] |= pack_left_shift_u8(src_p->error62, 6u, 0x40u);
    dst_p[7] |= pack_left_shift_u8(src_p->error63, 7u, 0x80u);

    return (8);
}

int feb_can_front_sensor_heartbeat_message_unpack(
    struct feb_can_front_sensor_heartbeat_message_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    if (size < 8u) {
        return (-EINVAL);
    }

    dst_p->error0 = unpack_right_shift_u8(src_p[0], 0u, 0x01u);
    dst_p->error1 = unpack_right_shift_u8(src_p[0], 1u, 0x02u);
    dst_p->error2 = unpack_right_shift_u8(src_p[0], 2u, 0x04u);
    dst_p->error3 = unpack_right_shift_u8(src_p[0], 3u, 0x08u);
    dst_p->error4 = unpack_right_shift_u8(src_p[0], 4u, 0x10u);
    dst_p->error5 = unpack_right_shift_u8(src_p[0], 5u, 0x20u);
    dst_p->error6 = unpack_right_shift_u8(src_p[0], 6u, 0x40u);
    dst_p->error7 = unpack_right_shift_u8(src_p[0], 7u, 0x80u);
    dst_p->error8 = unpack_right_shift_u8(src_p[1], 0u, 0x01u);
    dst_p->error9 = unpack_right_shift_u8(src_p[1], 1u, 0x02u);
    dst_p->error10 = unpack_right_shift_u8(src_p[1], 2u, 0x04u);
    dst_p->error11 = unpack_right_shift_u8(src_p[1], 3u, 0x08u);
    dst_p->error12 = unpack_right_shift_u8(src_p[1], 4u, 0x10u);
    dst_p->error13 = unpack_right_shift_u8(src_p[1], 5u, 0x20u);
    dst_p->error14 = unpack_right_shift_u8(src_p[1], 6u, 0x40u);
    dst_p->error15 = unpack_right_shift_u8(src_p[1], 7u, 0x80u);
    dst_p->error16 = unpack_right_shift_u8(src_p[2], 0u, 0x01u);
    dst_p->error17 = unpack_right_shift_u8(src_p[2], 1u, 0x02u);
    dst_p->error18 = unpack_right_shift_u8(src_p[2], 2u, 0x04u);
    dst_p->error19 = unpack_right_shift_u8(src_p[2], 3u, 0x08u);
    dst_p->error20 = unpack_right_shift_u8(src_p[2], 4u, 0x10u);
    dst_p->error21 = unpack_right_shift_u8(src_p[2], 5u, 0x20u);
    dst_p->error22 = unpack_right_shift_u8(src_p[2], 6u, 0x40u);
    dst_p->error23 = unpack_right_shift_u8(src_p[2], 7u, 0x80u);
    dst_p->error24 = unpack_right_shift_u8(src_p[3], 0u, 0x01u);
    dst_p->error25 = unpack_right_shift_u8(src_p[3], 1u, 0x02u);
    dst_p->error26 = unpack_right_shift_u8(src_p[3], 2u, 0x04u);
    dst_p->error27 = unpack_right_shift_u8(src_p[3], 3u, 0x08u);
    dst_p->error28 = unpack_right_shift_u8(src_p[3], 4u, 0x10u);
    dst_p->error29 = unpack_right_shift_u8(src_p[3], 5u, 0x20u);
    dst_p->error30 = unpack_right_shift_u8(src_p[3], 6u, 0x40u);
    dst_p->error31 = unpack_right_shift_u8(src_p[3], 7u, 0x80u);
    dst_p->error32 = unpack_right_shift_u8(src_p[4], 0u, 0x01u);
    dst_p->error33 = unpack_right_shift_u8(src_p[4], 1u, 0x02u);
    dst_p->error34 = unpack_right_shift_u8(src_p[4], 2u, 0x04u);
    dst_p->error35 = unpack_right_shift_u8(src_p[4], 3u, 0x08u);
    dst_p->error36 = unpack_right_shift_u8(src_p[4], 4u, 0x10u);
    dst_p->error37 = unpack_right_shift_u8(src_p[4], 5u, 0x20u);
    dst_p->error38 = unpack_right_shift_u8(src_p[4], 6u, 0x40u);
    dst_p->error39 = unpack_right_shift_u8(src_p[4], 7u, 0x80u);
    dst_p->error40 = unpack_right_shift_u8(src_p[5], 0u, 0x01u);
    dst_p->error41 = unpack_right_shift_u8(src_p[5], 1u, 0x02u);
    dst_p->error42 = unpack_right_shift_u8(src_p[5], 2u, 0x04u);
    dst_p->error43 = unpack_right_shift_u8(src_p[5], 3u, 0x08u);
    dst_p->error44 = unpack_right_shift_u8(src_p[5], 4u, 0x10u);
    dst_p->error45 = unpack_right_shift_u8(src_p[5], 5u, 0x20u);
    dst_p->error46 = unpack_right_shift_u8(src_p[5], 6u, 0x40u);
    dst_p->error47 = unpack_right_shift_u8(src_p[5], 7u, 0x80u);
    dst_p->error48 = unpack_right_shift_u8(src_p[6], 0u, 0x01u);
    dst_p->error49 = unpack_right_shift_u8(src_p[6], 1u, 0x02u);
    dst_p->error50 = unpack_right_shift_u8(src_p[6], 2u, 0x04u);
    dst_p->error51 = unpack_right_shift_u8(src_p[6], 3u, 0x08u);
    dst_p->error52 = unpack_right_shift_u8(src_p[6], 4u, 0x10u);
    dst_p->error53 = unpack_right_shift_u8(src_p[6], 5u, 0x20u);
    dst_p->error54 = unpack_right_shift_u8(src_p[6], 6u, 0x40u);
    dst_p->error55 = unpack_right_shift_u8(src_p[6], 7u, 0x80u);
    dst_p->error56 = unpack_right_shift_u8(src_p[7], 0u, 0x01u);
    dst_p->error57 = unpack_right_shift_u8(src_p[7], 1u, 0x02u);
    dst_p->error58 = unpack_right_shift_u8(src_p[7], 2u, 0x04u);
    dst_p->error59 = unpack_right_shift_u8(src_p[7], 3u, 0x08u);
    dst_p->error60 = unpack_right_shift_u8(src_p[7], 4u, 0x10u);
    dst_p->error61 = unpack_right_shift_u8(src_p[7], 5u, 0x20u);
    dst_p->error62 = unpack_right_shift_u8(src_p[7], 6u, 0x40u);
    dst_p->error63 = unpack_right_shift_u8(src_p[7], 7u, 0x80u);

    return (0);
}

int feb_can_front_sensor_heartbeat_message_init(struct feb_can_front_sensor_heartbeat_message_t *msg_p)
{
    if (msg_p == NULL) return -1;

    memset(msg_p, 0, sizeof(struct feb_can_front_sensor_heartbeat_message_t));

    return 0;
}

uint8_t feb_can_front_sensor_heartbeat_message_error0_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_front_sensor_heartbeat_message_error0_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_front_sensor_heartbeat_message_error0_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_front_sensor_heartbeat_message_error1_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_front_sensor_heartbeat_message_error1_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_front_sensor_heartbeat_message_error1_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_front_sensor_heartbeat_message_error2_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_front_sensor_heartbeat_message_error2_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_front_sensor_heartbeat_message_error2_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_front_sensor_heartbeat_message_error3_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_front_sensor_heartbeat_message_error3_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_front_sensor_heartbeat_message_error3_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_front_sensor_heartbeat_message_error4_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_front_sensor_heartbeat_message_error4_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_front_sensor_heartbeat_message_error4_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_front_sensor_heartbeat_message_error5_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_front_sensor_heartbeat_message_error5_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_front_sensor_heartbeat_message_error5_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_front_sensor_heartbeat_message_error6_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_front_sensor_heartbeat_message_error6_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_front_sensor_heartbeat_message_error6_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_front_sensor_heartbeat_message_error7_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_front_sensor_heartbeat_message_error7_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_front_sensor_heartbeat_message_error7_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_front_sensor_heartbeat_message_error8_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_front_sensor_heartbeat_message_error8_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_front_sensor_heartbeat_message_error8_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_front_sensor_heartbeat_message_error9_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_front_sensor_heartbeat_message_error9_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_front_sensor_heartbeat_message_error9_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_front_sensor_heartbeat_message_error10_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_front_sensor_heartbeat_message_error10_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_front_sensor_heartbeat_message_error10_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_front_sensor_heartbeat_message_error11_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_front_sensor_heartbeat_message_error11_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_front_sensor_heartbeat_message_error11_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_front_sensor_heartbeat_message_error12_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_front_sensor_heartbeat_message_error12_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_front_sensor_heartbeat_message_error12_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_front_sensor_heartbeat_message_error13_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_front_sensor_heartbeat_message_error13_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_front_sensor_heartbeat_message_error13_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_front_sensor_heartbeat_message_error14_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_front_sensor_heartbeat_message_error14_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_front_sensor_heartbeat_message_error14_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_front_sensor_heartbeat_message_error15_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_front_sensor_heartbeat_message_error15_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_front_sensor_heartbeat_message_error15_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_front_sensor_heartbeat_message_error16_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_front_sensor_heartbeat_message_error16_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_front_sensor_heartbeat_message_error16_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_front_sensor_heartbeat_message_error17_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_front_sensor_heartbeat_message_error17_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_front_sensor_heartbeat_message_error17_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_front_sensor_heartbeat_message_error18_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_front_sensor_heartbeat_message_error18_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_front_sensor_heartbeat_message_error18_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_front_sensor_heartbeat_message_error19_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_front_sensor_heartbeat_message_error19_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_front_sensor_heartbeat_message_error19_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_front_sensor_heartbeat_message_error20_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_front_sensor_heartbeat_message_error20_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_front_sensor_heartbeat_message_error20_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_front_sensor_heartbeat_message_error21_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_front_sensor_heartbeat_message_error21_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_front_sensor_heartbeat_message_error21_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_front_sensor_heartbeat_message_error22_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_front_sensor_heartbeat_message_error22_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_front_sensor_heartbeat_message_error22_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_front_sensor_heartbeat_message_error23_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_front_sensor_heartbeat_message_error23_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_front_sensor_heartbeat_message_error23_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_front_sensor_heartbeat_message_error24_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_front_sensor_heartbeat_message_error24_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_front_sensor_heartbeat_message_error24_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_front_sensor_heartbeat_message_error25_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_front_sensor_heartbeat_message_error25_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_front_sensor_heartbeat_message_error25_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_front_sensor_heartbeat_message_error26_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_front_sensor_heartbeat_message_error26_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_front_sensor_heartbeat_message_error26_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_front_sensor_heartbeat_message_error27_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_front_sensor_heartbeat_message_error27_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_front_sensor_heartbeat_message_error27_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_front_sensor_heartbeat_message_error28_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_front_sensor_heartbeat_message_error28_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_front_sensor_heartbeat_message_error28_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_front_sensor_heartbeat_message_error29_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_front_sensor_heartbeat_message_error29_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_front_sensor_heartbeat_message_error29_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_front_sensor_heartbeat_message_error30_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_front_sensor_heartbeat_message_error30_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_front_sensor_heartbeat_message_error30_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_front_sensor_heartbeat_message_error31_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_front_sensor_heartbeat_message_error31_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_front_sensor_heartbeat_message_error31_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_front_sensor_heartbeat_message_error32_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_front_sensor_heartbeat_message_error32_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_front_sensor_heartbeat_message_error32_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_front_sensor_heartbeat_message_error33_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_front_sensor_heartbeat_message_error33_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_front_sensor_heartbeat_message_error33_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_front_sensor_heartbeat_message_error34_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_front_sensor_heartbeat_message_error34_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_front_sensor_heartbeat_message_error34_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_front_sensor_heartbeat_message_error35_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_front_sensor_heartbeat_message_error35_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_front_sensor_heartbeat_message_error35_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_front_sensor_heartbeat_message_error36_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_front_sensor_heartbeat_message_error36_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_front_sensor_heartbeat_message_error36_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_front_sensor_heartbeat_message_error37_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_front_sensor_heartbeat_message_error37_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_front_sensor_heartbeat_message_error37_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_front_sensor_heartbeat_message_error38_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_front_sensor_heartbeat_message_error38_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_front_sensor_heartbeat_message_error38_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_front_sensor_heartbeat_message_error39_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_front_sensor_heartbeat_message_error39_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_front_sensor_heartbeat_message_error39_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_front_sensor_heartbeat_message_error40_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_front_sensor_heartbeat_message_error40_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_front_sensor_heartbeat_message_error40_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_front_sensor_heartbeat_message_error41_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_front_sensor_heartbeat_message_error41_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_front_sensor_heartbeat_message_error41_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_front_sensor_heartbeat_message_error42_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_front_sensor_heartbeat_message_error42_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_front_sensor_heartbeat_message_error42_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_front_sensor_heartbeat_message_error43_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_front_sensor_heartbeat_message_error43_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_front_sensor_heartbeat_message_error43_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_front_sensor_heartbeat_message_error44_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_front_sensor_heartbeat_message_error44_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_front_sensor_heartbeat_message_error44_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_front_sensor_heartbeat_message_error45_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_front_sensor_heartbeat_message_error45_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_front_sensor_heartbeat_message_error45_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_front_sensor_heartbeat_message_error46_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_front_sensor_heartbeat_message_error46_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_front_sensor_heartbeat_message_error46_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_front_sensor_heartbeat_message_error47_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_front_sensor_heartbeat_message_error47_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_front_sensor_heartbeat_message_error47_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_front_sensor_heartbeat_message_error48_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_front_sensor_heartbeat_message_error48_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_front_sensor_heartbeat_message_error48_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_front_sensor_heartbeat_message_error49_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_front_sensor_heartbeat_message_error49_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_front_sensor_heartbeat_message_error49_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_front_sensor_heartbeat_message_error50_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_front_sensor_heartbeat_message_error50_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_front_sensor_heartbeat_message_error50_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_front_sensor_heartbeat_message_error51_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_front_sensor_heartbeat_message_error51_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_front_sensor_heartbeat_message_error51_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_front_sensor_heartbeat_message_error52_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_front_sensor_heartbeat_message_error52_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_front_sensor_heartbeat_message_error52_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_front_sensor_heartbeat_message_error53_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_front_sensor_heartbeat_message_error53_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_front_sensor_heartbeat_message_error53_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_front_sensor_heartbeat_message_error54_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_front_sensor_heartbeat_message_error54_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_front_sensor_heartbeat_message_error54_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_front_sensor_heartbeat_message_error55_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_front_sensor_heartbeat_message_error55_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_front_sensor_heartbeat_message_error55_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_front_sensor_heartbeat_message_error56_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_front_sensor_heartbeat_message_error56_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_front_sensor_heartbeat_message_error56_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_front_sensor_heartbeat_message_error57_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_front_sensor_heartbeat_message_error57_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_front_sensor_heartbeat_message_error57_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_front_sensor_heartbeat_message_error58_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_front_sensor_heartbeat_message_error58_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_front_sensor_heartbeat_message_error58_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_front_sensor_heartbeat_message_error59_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_front_sensor_heartbeat_message_error59_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_front_sensor_heartbeat_message_error59_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_front_sensor_heartbeat_message_error60_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_front_sensor_heartbeat_message_error60_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_front_sensor_heartbeat_message_error60_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_front_sensor_heartbeat_message_error61_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_front_sensor_heartbeat_message_error61_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_front_sensor_heartbeat_message_error61_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_front_sensor_heartbeat_message_error62_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_front_sensor_heartbeat_message_error62_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_front_sensor_heartbeat_message_error62_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_front_sensor_heartbeat_message_error63_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_front_sensor_heartbeat_message_error63_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_front_sensor_heartbeat_message_error63_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

int feb_can_rear_sensor_heartbeat_message_pack(
    uint8_t *dst_p,
    const struct feb_can_rear_sensor_heartbeat_message_t *src_p,
    size_t size)
{
    if (size < 8u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 8);

    dst_p[0] |= pack_left_shift_u8(src_p->error0, 0u, 0x01u);
    dst_p[0] |= pack_left_shift_u8(src_p->error1, 1u, 0x02u);
    dst_p[0] |= pack_left_shift_u8(src_p->error2, 2u, 0x04u);
    dst_p[0] |= pack_left_shift_u8(src_p->error3, 3u, 0x08u);
    dst_p[0] |= pack_left_shift_u8(src_p->error4, 4u, 0x10u);
    dst_p[0] |= pack_left_shift_u8(src_p->error5, 5u, 0x20u);
    dst_p[0] |= pack_left_shift_u8(src_p->error6, 6u, 0x40u);
    dst_p[0] |= pack_left_shift_u8(src_p->error7, 7u, 0x80u);
    dst_p[1] |= pack_left_shift_u8(src_p->error8, 0u, 0x01u);
    dst_p[1] |= pack_left_shift_u8(src_p->error9, 1u, 0x02u);
    dst_p[1] |= pack_left_shift_u8(src_p->error10, 2u, 0x04u);
    dst_p[1] |= pack_left_shift_u8(src_p->error11, 3u, 0x08u);
    dst_p[1] |= pack_left_shift_u8(src_p->error12, 4u, 0x10u);
    dst_p[1] |= pack_left_shift_u8(src_p->error13, 5u, 0x20u);
    dst_p[1] |= pack_left_shift_u8(src_p->error14, 6u, 0x40u);
    dst_p[1] |= pack_left_shift_u8(src_p->error15, 7u, 0x80u);
    dst_p[2] |= pack_left_shift_u8(src_p->error16, 0u, 0x01u);
    dst_p[2] |= pack_left_shift_u8(src_p->error17, 1u, 0x02u);
    dst_p[2] |= pack_left_shift_u8(src_p->error18, 2u, 0x04u);
    dst_p[2] |= pack_left_shift_u8(src_p->error19, 3u, 0x08u);
    dst_p[2] |= pack_left_shift_u8(src_p->error20, 4u, 0x10u);
    dst_p[2] |= pack_left_shift_u8(src_p->error21, 5u, 0x20u);
    dst_p[2] |= pack_left_shift_u8(src_p->error22, 6u, 0x40u);
    dst_p[2] |= pack_left_shift_u8(src_p->error23, 7u, 0x80u);
    dst_p[3] |= pack_left_shift_u8(src_p->error24, 0u, 0x01u);
    dst_p[3] |= pack_left_shift_u8(src_p->error25, 1u, 0x02u);
    dst_p[3] |= pack_left_shift_u8(src_p->error26, 2u, 0x04u);
    dst_p[3] |= pack_left_shift_u8(src_p->error27, 3u, 0x08u);
    dst_p[3] |= pack_left_shift_u8(src_p->error28, 4u, 0x10u);
    dst_p[3] |= pack_left_shift_u8(src_p->error29, 5u, 0x20u);
    dst_p[3] |= pack_left_shift_u8(src_p->error30, 6u, 0x40u);
    dst_p[3] |= pack_left_shift_u8(src_p->error31, 7u, 0x80u);
    dst_p[4] |= pack_left_shift_u8(src_p->error32, 0u, 0x01u);
    dst_p[4] |= pack_left_shift_u8(src_p->error33, 1u, 0x02u);
    dst_p[4] |= pack_left_shift_u8(src_p->error34, 2u, 0x04u);
    dst_p[4] |= pack_left_shift_u8(src_p->error35, 3u, 0x08u);
    dst_p[4] |= pack_left_shift_u8(src_p->error36, 4u, 0x10u);
    dst_p[4] |= pack_left_shift_u8(src_p->error37, 5u, 0x20u);
    dst_p[4] |= pack_left_shift_u8(src_p->error38, 6u, 0x40u);
    dst_p[4] |= pack_left_shift_u8(src_p->error39, 7u, 0x80u);
    dst_p[5] |= pack_left_shift_u8(src_p->error40, 0u, 0x01u);
    dst_p[5] |= pack_left_shift_u8(src_p->error41, 1u, 0x02u);
    dst_p[5] |= pack_left_shift_u8(src_p->error42, 2u, 0x04u);
    dst_p[5] |= pack_left_shift_u8(src_p->error43, 3u, 0x08u);
    dst_p[5] |= pack_left_shift_u8(src_p->error44, 4u, 0x10u);
    dst_p[5] |= pack_left_shift_u8(src_p->error45, 5u, 0x20u);
    dst_p[5] |= pack_left_shift_u8(src_p->error46, 6u, 0x40u);
    dst_p[5] |= pack_left_shift_u8(src_p->error47, 7u, 0x80u);
    dst_p[6] |= pack_left_shift_u8(src_p->error48, 0u, 0x01u);
    dst_p[6] |= pack_left_shift_u8(src_p->error49, 1u, 0x02u);
    dst_p[6] |= pack_left_shift_u8(src_p->error50, 2u, 0x04u);
    dst_p[6] |= pack_left_shift_u8(src_p->error51, 3u, 0x08u);
    dst_p[6] |= pack_left_shift_u8(src_p->error52, 4u, 0x10u);
    dst_p[6] |= pack_left_shift_u8(src_p->error53, 5u, 0x20u);
    dst_p[6] |= pack_left_shift_u8(src_p->error54, 6u, 0x40u);
    dst_p[6] |= pack_left_shift_u8(src_p->error55, 7u, 0x80u);
    dst_p[7] |= pack_left_shift_u8(src_p->error56, 0u, 0x01u);
    dst_p[7] |= pack_left_shift_u8(src_p->error57, 1u, 0x02u);
    dst_p[7] |= pack_left_shift_u8(src_p->error58, 2u, 0x04u);
    dst_p[7] |= pack_left_shift_u8(src_p->error59, 3u, 0x08u);
    dst_p[7] |= pack_left_shift_u8(src_p->error60, 4u, 0x10u);
    dst_p[7] |= pack_left_shift_u8(src_p->error61, 5u, 0x20u);
    dst_p[7] |= pack_left_shift_u8(src_p->error62, 6u, 0x40u);
    dst_p[7] |= pack_left_shift_u8(src_p->error63, 7u, 0x80u);

    return (8);
}

int feb_can_rear_sensor_heartbeat_message_unpack(
    struct feb_can_rear_sensor_heartbeat_message_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    if (size < 8u) {
        return (-EINVAL);
    }

    dst_p->error0 = unpack_right_shift_u8(src_p[0], 0u, 0x01u);
    dst_p->error1 = unpack_right_shift_u8(src_p[0], 1u, 0x02u);
    dst_p->error2 = unpack_right_shift_u8(src_p[0], 2u, 0x04u);
    dst_p->error3 = unpack_right_shift_u8(src_p[0], 3u, 0x08u);
    dst_p->error4 = unpack_right_shift_u8(src_p[0], 4u, 0x10u);
    dst_p->error5 = unpack_right_shift_u8(src_p[0], 5u, 0x20u);
    dst_p->error6 = unpack_right_shift_u8(src_p[0], 6u, 0x40u);
    dst_p->error7 = unpack_right_shift_u8(src_p[0], 7u, 0x80u);
    dst_p->error8 = unpack_right_shift_u8(src_p[1], 0u, 0x01u);
    dst_p->error9 = unpack_right_shift_u8(src_p[1], 1u, 0x02u);
    dst_p->error10 = unpack_right_shift_u8(src_p[1], 2u, 0x04u);
    dst_p->error11 = unpack_right_shift_u8(src_p[1], 3u, 0x08u);
    dst_p->error12 = unpack_right_shift_u8(src_p[1], 4u, 0x10u);
    dst_p->error13 = unpack_right_shift_u8(src_p[1], 5u, 0x20u);
    dst_p->error14 = unpack_right_shift_u8(src_p[1], 6u, 0x40u);
    dst_p->error15 = unpack_right_shift_u8(src_p[1], 7u, 0x80u);
    dst_p->error16 = unpack_right_shift_u8(src_p[2], 0u, 0x01u);
    dst_p->error17 = unpack_right_shift_u8(src_p[2], 1u, 0x02u);
    dst_p->error18 = unpack_right_shift_u8(src_p[2], 2u, 0x04u);
    dst_p->error19 = unpack_right_shift_u8(src_p[2], 3u, 0x08u);
    dst_p->error20 = unpack_right_shift_u8(src_p[2], 4u, 0x10u);
    dst_p->error21 = unpack_right_shift_u8(src_p[2], 5u, 0x20u);
    dst_p->error22 = unpack_right_shift_u8(src_p[2], 6u, 0x40u);
    dst_p->error23 = unpack_right_shift_u8(src_p[2], 7u, 0x80u);
    dst_p->error24 = unpack_right_shift_u8(src_p[3], 0u, 0x01u);
    dst_p->error25 = unpack_right_shift_u8(src_p[3], 1u, 0x02u);
    dst_p->error26 = unpack_right_shift_u8(src_p[3], 2u, 0x04u);
    dst_p->error27 = unpack_right_shift_u8(src_p[3], 3u, 0x08u);
    dst_p->error28 = unpack_right_shift_u8(src_p[3], 4u, 0x10u);
    dst_p->error29 = unpack_right_shift_u8(src_p[3], 5u, 0x20u);
    dst_p->error30 = unpack_right_shift_u8(src_p[3], 6u, 0x40u);
    dst_p->error31 = unpack_right_shift_u8(src_p[3], 7u, 0x80u);
    dst_p->error32 = unpack_right_shift_u8(src_p[4], 0u, 0x01u);
    dst_p->error33 = unpack_right_shift_u8(src_p[4], 1u, 0x02u);
    dst_p->error34 = unpack_right_shift_u8(src_p[4], 2u, 0x04u);
    dst_p->error35 = unpack_right_shift_u8(src_p[4], 3u, 0x08u);
    dst_p->error36 = unpack_right_shift_u8(src_p[4], 4u, 0x10u);
    dst_p->error37 = unpack_right_shift_u8(src_p[4], 5u, 0x20u);
    dst_p->error38 = unpack_right_shift_u8(src_p[4], 6u, 0x40u);
    dst_p->error39 = unpack_right_shift_u8(src_p[4], 7u, 0x80u);
    dst_p->error40 = unpack_right_shift_u8(src_p[5], 0u, 0x01u);
    dst_p->error41 = unpack_right_shift_u8(src_p[5], 1u, 0x02u);
    dst_p->error42 = unpack_right_shift_u8(src_p[5], 2u, 0x04u);
    dst_p->error43 = unpack_right_shift_u8(src_p[5], 3u, 0x08u);
    dst_p->error44 = unpack_right_shift_u8(src_p[5], 4u, 0x10u);
    dst_p->error45 = unpack_right_shift_u8(src_p[5], 5u, 0x20u);
    dst_p->error46 = unpack_right_shift_u8(src_p[5], 6u, 0x40u);
    dst_p->error47 = unpack_right_shift_u8(src_p[5], 7u, 0x80u);
    dst_p->error48 = unpack_right_shift_u8(src_p[6], 0u, 0x01u);
    dst_p->error49 = unpack_right_shift_u8(src_p[6], 1u, 0x02u);
    dst_p->error50 = unpack_right_shift_u8(src_p[6], 2u, 0x04u);
    dst_p->error51 = unpack_right_shift_u8(src_p[6], 3u, 0x08u);
    dst_p->error52 = unpack_right_shift_u8(src_p[6], 4u, 0x10u);
    dst_p->error53 = unpack_right_shift_u8(src_p[6], 5u, 0x20u);
    dst_p->error54 = unpack_right_shift_u8(src_p[6], 6u, 0x40u);
    dst_p->error55 = unpack_right_shift_u8(src_p[6], 7u, 0x80u);
    dst_p->error56 = unpack_right_shift_u8(src_p[7], 0u, 0x01u);
    dst_p->error57 = unpack_right_shift_u8(src_p[7], 1u, 0x02u);
    dst_p->error58 = unpack_right_shift_u8(src_p[7], 2u, 0x04u);
    dst_p->error59 = unpack_right_shift_u8(src_p[7], 3u, 0x08u);
    dst_p->error60 = unpack_right_shift_u8(src_p[7], 4u, 0x10u);
    dst_p->error61 = unpack_right_shift_u8(src_p[7], 5u, 0x20u);
    dst_p->error62 = unpack_right_shift_u8(src_p[7], 6u, 0x40u);
    dst_p->error63 = unpack_right_shift_u8(src_p[7], 7u, 0x80u);

    return (0);
}

int feb_can_rear_sensor_heartbeat_message_init(struct feb_can_rear_sensor_heartbeat_message_t *msg_p)
{
    if (msg_p == NULL) return -1;

    memset(msg_p, 0, sizeof(struct feb_can_rear_sensor_heartbeat_message_t));

    return 0;
}

uint8_t feb_can_rear_sensor_heartbeat_message_error0_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_rear_sensor_heartbeat_message_error0_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_rear_sensor_heartbeat_message_error0_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_rear_sensor_heartbeat_message_error1_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_rear_sensor_heartbeat_message_error1_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_rear_sensor_heartbeat_message_error1_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_rear_sensor_heartbeat_message_error2_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_rear_sensor_heartbeat_message_error2_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_rear_sensor_heartbeat_message_error2_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_rear_sensor_heartbeat_message_error3_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_rear_sensor_heartbeat_message_error3_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_rear_sensor_heartbeat_message_error3_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_rear_sensor_heartbeat_message_error4_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_rear_sensor_heartbeat_message_error4_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_rear_sensor_heartbeat_message_error4_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_rear_sensor_heartbeat_message_error5_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_rear_sensor_heartbeat_message_error5_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_rear_sensor_heartbeat_message_error5_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_rear_sensor_heartbeat_message_error6_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_rear_sensor_heartbeat_message_error6_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_rear_sensor_heartbeat_message_error6_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_rear_sensor_heartbeat_message_error7_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_rear_sensor_heartbeat_message_error7_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_rear_sensor_heartbeat_message_error7_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_rear_sensor_heartbeat_message_error8_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_rear_sensor_heartbeat_message_error8_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_rear_sensor_heartbeat_message_error8_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_rear_sensor_heartbeat_message_error9_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_rear_sensor_heartbeat_message_error9_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_rear_sensor_heartbeat_message_error9_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_rear_sensor_heartbeat_message_error10_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_rear_sensor_heartbeat_message_error10_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_rear_sensor_heartbeat_message_error10_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_rear_sensor_heartbeat_message_error11_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_rear_sensor_heartbeat_message_error11_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_rear_sensor_heartbeat_message_error11_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_rear_sensor_heartbeat_message_error12_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_rear_sensor_heartbeat_message_error12_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_rear_sensor_heartbeat_message_error12_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_rear_sensor_heartbeat_message_error13_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_rear_sensor_heartbeat_message_error13_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_rear_sensor_heartbeat_message_error13_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_rear_sensor_heartbeat_message_error14_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_rear_sensor_heartbeat_message_error14_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_rear_sensor_heartbeat_message_error14_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_rear_sensor_heartbeat_message_error15_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_rear_sensor_heartbeat_message_error15_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_rear_sensor_heartbeat_message_error15_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_rear_sensor_heartbeat_message_error16_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_rear_sensor_heartbeat_message_error16_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_rear_sensor_heartbeat_message_error16_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_rear_sensor_heartbeat_message_error17_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_rear_sensor_heartbeat_message_error17_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_rear_sensor_heartbeat_message_error17_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_rear_sensor_heartbeat_message_error18_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_rear_sensor_heartbeat_message_error18_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_rear_sensor_heartbeat_message_error18_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_rear_sensor_heartbeat_message_error19_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_rear_sensor_heartbeat_message_error19_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_rear_sensor_heartbeat_message_error19_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_rear_sensor_heartbeat_message_error20_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_rear_sensor_heartbeat_message_error20_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_rear_sensor_heartbeat_message_error20_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_rear_sensor_heartbeat_message_error21_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_rear_sensor_heartbeat_message_error21_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_rear_sensor_heartbeat_message_error21_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_rear_sensor_heartbeat_message_error22_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_rear_sensor_heartbeat_message_error22_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_rear_sensor_heartbeat_message_error22_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_rear_sensor_heartbeat_message_error23_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_rear_sensor_heartbeat_message_error23_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_rear_sensor_heartbeat_message_error23_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_rear_sensor_heartbeat_message_error24_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_rear_sensor_heartbeat_message_error24_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_rear_sensor_heartbeat_message_error24_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_rear_sensor_heartbeat_message_error25_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_rear_sensor_heartbeat_message_error25_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_rear_sensor_heartbeat_message_error25_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_rear_sensor_heartbeat_message_error26_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_rear_sensor_heartbeat_message_error26_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_rear_sensor_heartbeat_message_error26_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_rear_sensor_heartbeat_message_error27_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_rear_sensor_heartbeat_message_error27_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_rear_sensor_heartbeat_message_error27_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_rear_sensor_heartbeat_message_error28_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_rear_sensor_heartbeat_message_error28_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_rear_sensor_heartbeat_message_error28_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_rear_sensor_heartbeat_message_error29_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_rear_sensor_heartbeat_message_error29_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_rear_sensor_heartbeat_message_error29_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_rear_sensor_heartbeat_message_error30_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_rear_sensor_heartbeat_message_error30_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_rear_sensor_heartbeat_message_error30_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_rear_sensor_heartbeat_message_error31_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_rear_sensor_heartbeat_message_error31_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_rear_sensor_heartbeat_message_error31_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_rear_sensor_heartbeat_message_error32_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_rear_sensor_heartbeat_message_error32_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_rear_sensor_heartbeat_message_error32_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_rear_sensor_heartbeat_message_error33_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_rear_sensor_heartbeat_message_error33_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_rear_sensor_heartbeat_message_error33_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_rear_sensor_heartbeat_message_error34_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_rear_sensor_heartbeat_message_error34_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_rear_sensor_heartbeat_message_error34_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_rear_sensor_heartbeat_message_error35_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_rear_sensor_heartbeat_message_error35_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_rear_sensor_heartbeat_message_error35_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_rear_sensor_heartbeat_message_error36_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_rear_sensor_heartbeat_message_error36_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_rear_sensor_heartbeat_message_error36_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_rear_sensor_heartbeat_message_error37_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_rear_sensor_heartbeat_message_error37_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_rear_sensor_heartbeat_message_error37_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_rear_sensor_heartbeat_message_error38_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_rear_sensor_heartbeat_message_error38_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_rear_sensor_heartbeat_message_error38_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_rear_sensor_heartbeat_message_error39_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_rear_sensor_heartbeat_message_error39_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_rear_sensor_heartbeat_message_error39_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_rear_sensor_heartbeat_message_error40_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_rear_sensor_heartbeat_message_error40_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_rear_sensor_heartbeat_message_error40_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_rear_sensor_heartbeat_message_error41_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_rear_sensor_heartbeat_message_error41_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_rear_sensor_heartbeat_message_error41_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_rear_sensor_heartbeat_message_error42_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_rear_sensor_heartbeat_message_error42_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_rear_sensor_heartbeat_message_error42_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_rear_sensor_heartbeat_message_error43_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_rear_sensor_heartbeat_message_error43_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_rear_sensor_heartbeat_message_error43_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_rear_sensor_heartbeat_message_error44_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_rear_sensor_heartbeat_message_error44_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_rear_sensor_heartbeat_message_error44_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_rear_sensor_heartbeat_message_error45_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_rear_sensor_heartbeat_message_error45_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_rear_sensor_heartbeat_message_error45_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_rear_sensor_heartbeat_message_error46_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_rear_sensor_heartbeat_message_error46_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_rear_sensor_heartbeat_message_error46_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_rear_sensor_heartbeat_message_error47_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_rear_sensor_heartbeat_message_error47_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_rear_sensor_heartbeat_message_error47_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_rear_sensor_heartbeat_message_error48_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_rear_sensor_heartbeat_message_error48_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_rear_sensor_heartbeat_message_error48_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_rear_sensor_heartbeat_message_error49_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_rear_sensor_heartbeat_message_error49_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_rear_sensor_heartbeat_message_error49_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_rear_sensor_heartbeat_message_error50_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_rear_sensor_heartbeat_message_error50_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_rear_sensor_heartbeat_message_error50_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_rear_sensor_heartbeat_message_error51_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_rear_sensor_heartbeat_message_error51_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_rear_sensor_heartbeat_message_error51_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_rear_sensor_heartbeat_message_error52_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_rear_sensor_heartbeat_message_error52_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_rear_sensor_heartbeat_message_error52_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_rear_sensor_heartbeat_message_error53_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_rear_sensor_heartbeat_message_error53_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_rear_sensor_heartbeat_message_error53_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_rear_sensor_heartbeat_message_error54_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_rear_sensor_heartbeat_message_error54_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_rear_sensor_heartbeat_message_error54_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_rear_sensor_heartbeat_message_error55_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_rear_sensor_heartbeat_message_error55_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_rear_sensor_heartbeat_message_error55_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_rear_sensor_heartbeat_message_error56_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_rear_sensor_heartbeat_message_error56_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_rear_sensor_heartbeat_message_error56_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_rear_sensor_heartbeat_message_error57_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_rear_sensor_heartbeat_message_error57_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_rear_sensor_heartbeat_message_error57_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_rear_sensor_heartbeat_message_error58_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_rear_sensor_heartbeat_message_error58_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_rear_sensor_heartbeat_message_error58_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_rear_sensor_heartbeat_message_error59_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_rear_sensor_heartbeat_message_error59_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_rear_sensor_heartbeat_message_error59_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_rear_sensor_heartbeat_message_error60_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_rear_sensor_heartbeat_message_error60_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_rear_sensor_heartbeat_message_error60_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_rear_sensor_heartbeat_message_error61_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_rear_sensor_heartbeat_message_error61_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_rear_sensor_heartbeat_message_error61_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_rear_sensor_heartbeat_message_error62_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_rear_sensor_heartbeat_message_error62_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_rear_sensor_heartbeat_message_error62_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_rear_sensor_heartbeat_message_error63_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_rear_sensor_heartbeat_message_error63_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_rear_sensor_heartbeat_message_error63_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

int feb_can_feb_ping_pong_counter1_pack(
    uint8_t *dst_p,
    const struct feb_can_feb_ping_pong_counter1_t *src_p,
    size_t size)
{
    uint32_t counter;

    if (size < 8u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 8);

    counter = (uint32_t)src_p->counter;
    dst_p[0] |= pack_left_shift_u32(counter, 0u, 0xffu);
    dst_p[1] |= pack_right_shift_u32(counter, 8u, 0xffu);
    dst_p[2] |= pack_right_shift_u32(counter, 16u, 0xffu);
    dst_p[3] |= pack_right_shift_u32(counter, 24u, 0xffu);

    return (8);
}

int feb_can_feb_ping_pong_counter1_unpack(
    struct feb_can_feb_ping_pong_counter1_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    uint32_t counter;

    if (size < 8u) {
        return (-EINVAL);
    }

    counter = unpack_right_shift_u32(src_p[0], 0u, 0xffu);
    counter |= unpack_left_shift_u32(src_p[1], 8u, 0xffu);
    counter |= unpack_left_shift_u32(src_p[2], 16u, 0xffu);
    counter |= unpack_left_shift_u32(src_p[3], 24u, 0xffu);
    dst_p->counter = (int32_t)counter;

    return (0);
}

int feb_can_feb_ping_pong_counter1_init(struct feb_can_feb_ping_pong_counter1_t *msg_p)
{
    if (msg_p == NULL) return -1;

    memset(msg_p, 0, sizeof(struct feb_can_feb_ping_pong_counter1_t));

    return 0;
}

int32_t feb_can_feb_ping_pong_counter1_counter_encode(double value)
{
    return (int32_t)(value);
}

double feb_can_feb_ping_pong_counter1_counter_decode(int32_t value)
{
    return ((double)value);
}

bool feb_can_feb_ping_pong_counter1_counter_is_in_range(int32_t value)
{
    (void)value;

    return (true);
}

int feb_can_feb_ping_pong_counter2_pack(
    uint8_t *dst_p,
    const struct feb_can_feb_ping_pong_counter2_t *src_p,
    size_t size)
{
    uint32_t counter;

    if (size < 8u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 8);

    counter = (uint32_t)src_p->counter;
    dst_p[0] |= pack_left_shift_u32(counter, 0u, 0xffu);
    dst_p[1] |= pack_right_shift_u32(counter, 8u, 0xffu);
    dst_p[2] |= pack_right_shift_u32(counter, 16u, 0xffu);
    dst_p[3] |= pack_right_shift_u32(counter, 24u, 0xffu);

    return (8);
}

int feb_can_feb_ping_pong_counter2_unpack(
    struct feb_can_feb_ping_pong_counter2_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    uint32_t counter;

    if (size < 8u) {
        return (-EINVAL);
    }

    counter = unpack_right_shift_u32(src_p[0], 0u, 0xffu);
    counter |= unpack_left_shift_u32(src_p[1], 8u, 0xffu);
    counter |= unpack_left_shift_u32(src_p[2], 16u, 0xffu);
    counter |= unpack_left_shift_u32(src_p[3], 24u, 0xffu);
    dst_p->counter = (int32_t)counter;

    return (0);
}

int feb_can_feb_ping_pong_counter2_init(struct feb_can_feb_ping_pong_counter2_t *msg_p)
{
    if (msg_p == NULL) return -1;

    memset(msg_p, 0, sizeof(struct feb_can_feb_ping_pong_counter2_t));

    return 0;
}

int32_t feb_can_feb_ping_pong_counter2_counter_encode(double value)
{
    return (int32_t)(value);
}

double feb_can_feb_ping_pong_counter2_counter_decode(int32_t value)
{
    return ((double)value);
}

bool feb_can_feb_ping_pong_counter2_counter_is_in_range(int32_t value)
{
    (void)value;

    return (true);
}

int feb_can_feb_ping_pong_counter3_pack(
    uint8_t *dst_p,
    const struct feb_can_feb_ping_pong_counter3_t *src_p,
    size_t size)
{
    uint32_t counter;

    if (size < 8u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 8);

    counter = (uint32_t)src_p->counter;
    dst_p[0] |= pack_left_shift_u32(counter, 0u, 0xffu);
    dst_p[1] |= pack_right_shift_u32(counter, 8u, 0xffu);
    dst_p[2] |= pack_right_shift_u32(counter, 16u, 0xffu);
    dst_p[3] |= pack_right_shift_u32(counter, 24u, 0xffu);

    return (8);
}

int feb_can_feb_ping_pong_counter3_unpack(
    struct feb_can_feb_ping_pong_counter3_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    uint32_t counter;

    if (size < 8u) {
        return (-EINVAL);
    }

    counter = unpack_right_shift_u32(src_p[0], 0u, 0xffu);
    counter |= unpack_left_shift_u32(src_p[1], 8u, 0xffu);
    counter |= unpack_left_shift_u32(src_p[2], 16u, 0xffu);
    counter |= unpack_left_shift_u32(src_p[3], 24u, 0xffu);
    dst_p->counter = (int32_t)counter;

    return (0);
}

int feb_can_feb_ping_pong_counter3_init(struct feb_can_feb_ping_pong_counter3_t *msg_p)
{
    if (msg_p == NULL) return -1;

    memset(msg_p, 0, sizeof(struct feb_can_feb_ping_pong_counter3_t));

    return 0;
}

int32_t feb_can_feb_ping_pong_counter3_counter_encode(double value)
{
    return (int32_t)(value);
}

double feb_can_feb_ping_pong_counter3_counter_decode(int32_t value)
{
    return ((double)value);
}

bool feb_can_feb_ping_pong_counter3_counter_is_in_range(int32_t value)
{
    (void)value;

    return (true);
}

int feb_can_feb_ping_pong_counter4_pack(
    uint8_t *dst_p,
    const struct feb_can_feb_ping_pong_counter4_t *src_p,
    size_t size)
{
    uint32_t counter;

    if (size < 8u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 8);

    counter = (uint32_t)src_p->counter;
    dst_p[0] |= pack_left_shift_u32(counter, 0u, 0xffu);
    dst_p[1] |= pack_right_shift_u32(counter, 8u, 0xffu);
    dst_p[2] |= pack_right_shift_u32(counter, 16u, 0xffu);
    dst_p[3] |= pack_right_shift_u32(counter, 24u, 0xffu);

    return (8);
}

int feb_can_feb_ping_pong_counter4_unpack(
    struct feb_can_feb_ping_pong_counter4_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    uint32_t counter;

    if (size < 8u) {
        return (-EINVAL);
    }

    counter = unpack_right_shift_u32(src_p[0], 0u, 0xffu);
    counter |= unpack_left_shift_u32(src_p[1], 8u, 0xffu);
    counter |= unpack_left_shift_u32(src_p[2], 16u, 0xffu);
    counter |= unpack_left_shift_u32(src_p[3], 24u, 0xffu);
    dst_p->counter = (int32_t)counter;

    return (0);
}

int feb_can_feb_ping_pong_counter4_init(struct feb_can_feb_ping_pong_counter4_t *msg_p)
{
    if (msg_p == NULL) return -1;

    memset(msg_p, 0, sizeof(struct feb_can_feb_ping_pong_counter4_t));

    return 0;
}

int32_t feb_can_feb_ping_pong_counter4_counter_encode(double value)
{
    return (int32_t)(value);
}

double feb_can_feb_ping_pong_counter4_counter_decode(int32_t value)
{
    return ((double)value);
}

bool feb_can_feb_ping_pong_counter4_counter_is_in_range(int32_t value)
{
    (void)value;

    return (true);
}

int feb_can_m188_u2_c_message_rxd_pack(
    uint8_t *dst_p,
    const struct feb_can_m188_u2_c_message_rxd_t *src_p,
    size_t size)
{
    if (size < 8u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 8);

    dst_p[0] |= pack_left_shift_u8(src_p->inv_hv_input_current_sensor_validity, 4u, 0x10u);
    dst_p[0] |= pack_left_shift_u8(src_p->inv_14_v_master_fault, 7u, 0x80u);
    dst_p[1] |= pack_left_shift_u8(src_p->inv_hv_input_current, 0u, 0xffu);
    dst_p[2] |= pack_left_shift_u8(src_p->inv_dtc_status, 0u, 0x07u);
    dst_p[2] |= pack_left_shift_u8(src_p->inv_dtc_index, 3u, 0xf8u);
    dst_p[3] |= pack_left_shift_u8(src_p->inv_14_v_monitor, 0u, 0xffu);
    dst_p[4] |= pack_left_shift_u8(src_p->inv_14_v_conditional, 7u, 0x80u);
    dst_p[6] |= pack_left_shift_u8(src_p->inv_14_v_current_monitor, 0u, 0x7fu);

    return (8);
}

int feb_can_m188_u2_c_message_rxd_unpack(
    struct feb_can_m188_u2_c_message_rxd_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    if (size < 8u) {
        return (-EINVAL);
    }

    dst_p->inv_hv_input_current_sensor_validity = unpack_right_shift_u8(src_p[0], 4u, 0x10u);
    dst_p->inv_14_v_master_fault = unpack_right_shift_u8(src_p[0], 7u, 0x80u);
    dst_p->inv_hv_input_current = unpack_right_shift_u8(src_p[1], 0u, 0xffu);
    dst_p->inv_dtc_status = unpack_right_shift_u8(src_p[2], 0u, 0x07u);
    dst_p->inv_dtc_index = unpack_right_shift_u8(src_p[2], 3u, 0xf8u);
    dst_p->inv_14_v_monitor = unpack_right_shift_u8(src_p[3], 0u, 0xffu);
    dst_p->inv_14_v_conditional = unpack_right_shift_u8(src_p[4], 7u, 0x80u);
    dst_p->inv_14_v_current_monitor = unpack_right_shift_u8(src_p[6], 0u, 0x7fu);

    return (0);
}

int feb_can_m188_u2_c_message_rxd_init(struct feb_can_m188_u2_c_message_rxd_t *msg_p)
{
    if (msg_p == NULL) return -1;

    memset(msg_p, 0, sizeof(struct feb_can_m188_u2_c_message_rxd_t));

    return 0;
}

uint8_t feb_can_m188_u2_c_message_rxd_inv_hv_input_current_sensor_validity_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_m188_u2_c_message_rxd_inv_hv_input_current_sensor_validity_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_m188_u2_c_message_rxd_inv_hv_input_current_sensor_validity_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_m188_u2_c_message_rxd_inv_14_v_master_fault_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_m188_u2_c_message_rxd_inv_14_v_master_fault_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_m188_u2_c_message_rxd_inv_14_v_master_fault_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_m188_u2_c_message_rxd_inv_hv_input_current_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_m188_u2_c_message_rxd_inv_hv_input_current_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_m188_u2_c_message_rxd_inv_hv_input_current_is_in_range(uint8_t value)
{
    (void)value;

    return (true);
}

uint8_t feb_can_m188_u2_c_message_rxd_inv_dtc_status_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_m188_u2_c_message_rxd_inv_dtc_status_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_m188_u2_c_message_rxd_inv_dtc_status_is_in_range(uint8_t value)
{
    return (value <= 7u);
}

uint8_t feb_can_m188_u2_c_message_rxd_inv_dtc_index_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_m188_u2_c_message_rxd_inv_dtc_index_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_m188_u2_c_message_rxd_inv_dtc_index_is_in_range(uint8_t value)
{
    return (value <= 31u);
}

uint8_t feb_can_m188_u2_c_message_rxd_inv_14_v_monitor_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_m188_u2_c_message_rxd_inv_14_v_monitor_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_m188_u2_c_message_rxd_inv_14_v_monitor_is_in_range(uint8_t value)
{
    (void)value;

    return (true);
}

uint8_t feb_can_m188_u2_c_message_rxd_inv_14_v_conditional_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_m188_u2_c_message_rxd_inv_14_v_conditional_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_m188_u2_c_message_rxd_inv_14_v_conditional_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t feb_can_m188_u2_c_message_rxd_inv_14_v_current_monitor_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_m188_u2_c_message_rxd_inv_14_v_current_monitor_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_m188_u2_c_message_rxd_inv_14_v_current_monitor_is_in_range(uint8_t value)
{
    return (value <= 127u);
}

int feb_can_m187_u2_c_command_txd_pack(
    uint8_t *dst_p,
    const struct feb_can_m187_u2_c_command_txd_t *src_p,
    size_t size)
{
    if (size < 8u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 8);

    dst_p[0] |= pack_left_shift_u8(src_p->u2_c_id_byte, 0u, 0xffu);
    dst_p[1] |= pack_left_shift_u8(src_p->u2_c_setpoint_calc, 0u, 0xffu);

    return (8);
}

int feb_can_m187_u2_c_command_txd_unpack(
    struct feb_can_m187_u2_c_command_txd_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    if (size < 8u) {
        return (-EINVAL);
    }

    dst_p->u2_c_id_byte = unpack_right_shift_u8(src_p[0], 0u, 0xffu);
    dst_p->u2_c_setpoint_calc = unpack_right_shift_u8(src_p[1], 0u, 0xffu);

    return (0);
}

int feb_can_m187_u2_c_command_txd_init(struct feb_can_m187_u2_c_command_txd_t *msg_p)
{
    if (msg_p == NULL) return -1;

    memset(msg_p, 0, sizeof(struct feb_can_m187_u2_c_command_txd_t));

    return 0;
}

uint8_t feb_can_m187_u2_c_command_txd_u2_c_id_byte_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_m187_u2_c_command_txd_u2_c_id_byte_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_m187_u2_c_command_txd_u2_c_id_byte_is_in_range(uint8_t value)
{
    (void)value;

    return (true);
}

uint8_t feb_can_m187_u2_c_command_txd_u2_c_setpoint_calc_encode(double value)
{
    return (uint8_t)(value);
}

double feb_can_m187_u2_c_command_txd_u2_c_setpoint_calc_decode(uint8_t value)
{
    return ((double)value);
}

bool feb_can_m187_u2_c_command_txd_u2_c_setpoint_calc_is_in_range(uint8_t value)
{
    (void)value;

    return (true);
}

int feb_can_bms_current_limit_pack(
    uint8_t *dst_p,
    const struct feb_can_bms_current_limit_t *src_p,
    size_t size)
{
    if (size < 8u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 8);

    dst_p[0] |= pack_left_shift_u16(src_p->inv_max_discharge_current, 0u, 0xffu);
    dst_p[1] |= pack_right_shift_u16(src_p->inv_max_discharge_current, 8u, 0xffu);
    dst_p[2] |= pack_left_shift_u16(src_p->inv_max_charge_current, 0u, 0xffu);
    dst_p[3] |= pack_right_shift_u16(src_p->inv_max_charge_current, 8u, 0xffu);

    return (8);
}

int feb_can_bms_current_limit_unpack(
    struct feb_can_bms_current_limit_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    if (size < 8u) {
        return (-EINVAL);
    }

    dst_p->inv_max_discharge_current = unpack_right_shift_u16(src_p[0], 0u, 0xffu);
    dst_p->inv_max_discharge_current |= unpack_left_shift_u16(src_p[1], 8u, 0xffu);
    dst_p->inv_max_charge_current = unpack_right_shift_u16(src_p[2], 0u, 0xffu);
    dst_p->inv_max_charge_current |= unpack_left_shift_u16(src_p[3], 8u, 0xffu);

    return (0);
}

int feb_can_bms_current_limit_init(struct feb_can_bms_current_limit_t *msg_p)
{
    if (msg_p == NULL) return -1;

    memset(msg_p, 0, sizeof(struct feb_can_bms_current_limit_t));

    return 0;
}

uint16_t feb_can_bms_current_limit_inv_max_discharge_current_encode(double value)
{
    return (uint16_t)(value);
}

double feb_can_bms_current_limit_inv_max_discharge_current_decode(uint16_t value)
{
    return ((double)value);
}

bool feb_can_bms_current_limit_inv_max_discharge_current_is_in_range(uint16_t value)
{
    return (value <= 1000u);
}

uint16_t feb_can_bms_current_limit_inv_max_charge_current_encode(double value)
{
    return (uint16_t)(value);
}

double feb_can_bms_current_limit_inv_max_charge_current_decode(uint16_t value)
{
    return ((double)value);
}

bool feb_can_bms_current_limit_inv_max_charge_current_is_in_range(uint16_t value)
{
    return (value <= 1000u);
}

int feb_can_ebs_pressure_status_pack(
    uint8_t *dst_p,
    const struct feb_can_ebs_pressure_status_t *src_p,
    size_t size)
{
    uint16_t ebs_pressure_1;
    uint16_t ebs_pressure_2;
    uint16_t ebs_pressure_3;
    uint16_t ebs_pressure_4;

    if (size < 8u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 8);

    ebs_pressure_1 = (uint16_t)src_p->ebs_pressure_1;
    dst_p[0] |= pack_left_shift_u16(ebs_pressure_1, 0u, 0xffu);
    dst_p[1] |= pack_right_shift_u16(ebs_pressure_1, 8u, 0xffu);
    ebs_pressure_2 = (uint16_t)src_p->ebs_pressure_2;
    dst_p[2] |= pack_left_shift_u16(ebs_pressure_2, 0u, 0xffu);
    dst_p[3] |= pack_right_shift_u16(ebs_pressure_2, 8u, 0xffu);
    ebs_pressure_3 = (uint16_t)src_p->ebs_pressure_3;
    dst_p[4] |= pack_left_shift_u16(ebs_pressure_3, 0u, 0xffu);
    dst_p[5] |= pack_right_shift_u16(ebs_pressure_3, 8u, 0xffu);
    ebs_pressure_4 = (uint16_t)src_p->ebs_pressure_4;
    dst_p[6] |= pack_left_shift_u16(ebs_pressure_4, 0u, 0xffu);
    dst_p[7] |= pack_right_shift_u16(ebs_pressure_4, 8u, 0xffu);

    return (8);
}

int feb_can_ebs_pressure_status_unpack(
    struct feb_can_ebs_pressure_status_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    uint16_t ebs_pressure_1;
    uint16_t ebs_pressure_2;
    uint16_t ebs_pressure_3;
    uint16_t ebs_pressure_4;

    if (size < 8u) {
        return (-EINVAL);
    }

    ebs_pressure_1 = unpack_right_shift_u16(src_p[0], 0u, 0xffu);
    ebs_pressure_1 |= unpack_left_shift_u16(src_p[1], 8u, 0xffu);
    dst_p->ebs_pressure_1 = (int16_t)ebs_pressure_1;
    ebs_pressure_2 = unpack_right_shift_u16(src_p[2], 0u, 0xffu);
    ebs_pressure_2 |= unpack_left_shift_u16(src_p[3], 8u, 0xffu);
    dst_p->ebs_pressure_2 = (int16_t)ebs_pressure_2;
    ebs_pressure_3 = unpack_right_shift_u16(src_p[4], 0u, 0xffu);
    ebs_pressure_3 |= unpack_left_shift_u16(src_p[5], 8u, 0xffu);
    dst_p->ebs_pressure_3 = (int16_t)ebs_pressure_3;
    ebs_pressure_4 = unpack_right_shift_u16(src_p[6], 0u, 0xffu);
    ebs_pressure_4 |= unpack_left_shift_u16(src_p[7], 8u, 0xffu);
    dst_p->ebs_pressure_4 = (int16_t)ebs_pressure_4;

    return (0);
}

int feb_can_ebs_pressure_status_init(struct feb_can_ebs_pressure_status_t *msg_p)
{
    if (msg_p == NULL) return -1;

    memset(msg_p, 0, sizeof(struct feb_can_ebs_pressure_status_t));

    return 0;
}

int16_t feb_can_ebs_pressure_status_ebs_pressure_1_encode(double value)
{
    return (int16_t)(value);
}

double feb_can_ebs_pressure_status_ebs_pressure_1_decode(int16_t value)
{
    return ((double)value);
}

bool feb_can_ebs_pressure_status_ebs_pressure_1_is_in_range(int16_t value)
{
    (void)value;

    return (true);
}

int16_t feb_can_ebs_pressure_status_ebs_pressure_2_encode(double value)
{
    return (int16_t)(value);
}

double feb_can_ebs_pressure_status_ebs_pressure_2_decode(int16_t value)
{
    return ((double)value);
}

bool feb_can_ebs_pressure_status_ebs_pressure_2_is_in_range(int16_t value)
{
    (void)value;

    return (true);
}

int16_t feb_can_ebs_pressure_status_ebs_pressure_3_encode(double value)
{
    return (int16_t)(value);
}

double feb_can_ebs_pressure_status_ebs_pressure_3_decode(int16_t value)
{
    return ((double)value);
}

bool feb_can_ebs_pressure_status_ebs_pressure_3_is_in_range(int16_t value)
{
    (void)value;

    return (true);
}

int16_t feb_can_ebs_pressure_status_ebs_pressure_4_encode(double value)
{
    return (int16_t)(value);
}

double feb_can_ebs_pressure_status_ebs_pressure_4_decode(int16_t value)
{
    return ((double)value);
}

bool feb_can_ebs_pressure_status_ebs_pressure_4_is_in_range(int16_t value)
{
    (void)value;

    return (true);
}
