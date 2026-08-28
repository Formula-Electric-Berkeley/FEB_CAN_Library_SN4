/* Auto-generated. Do Not Edit.
 * Regenerate via: cd common/FEB_CAN_Library_SN4 && ./generate_can.sh
 */

#ifndef FEB_CAN_TRAITS_HPP
#define FEB_CAN_TRAITS_HPP

#include "feb_can_db.h"

#include <cstdint>

namespace feb::can
{

inline constexpr bool kFdBus = false;

enum class Node : std::uint8_t
{
  kNone = 0,
  kBms,
  kPcu,
  kDash,
  kDcu,
  kLvpdb,
  kDart,
  kSnFront,
  kSnRear,
  kIvt,
};

namespace msg
{

struct BmsCellData
{
  using Data = feb_can_bms_cell_data_t;
  static constexpr std::uint32_t kFrameId = 0x1u;
  static constexpr std::uint8_t kLength = 8u;
  static constexpr bool kExtended = false;
  static constexpr std::uint32_t kCycleMs = 100u;
  static constexpr Node kSender = Node::kBms;
  static constexpr auto kPack = &feb_can_bms_cell_data_pack;
  static constexpr auto kUnpack = &feb_can_bms_cell_data_unpack;
};

struct BmsAccumulatorVoltage
{
  using Data = feb_can_bms_accumulator_voltage_t;
  static constexpr std::uint32_t kFrameId = 0x2u;
  static constexpr std::uint8_t kLength = 8u;
  static constexpr bool kExtended = false;
  static constexpr std::uint32_t kCycleMs = 100u;
  static constexpr Node kSender = Node::kBms;
  static constexpr auto kPack = &feb_can_bms_accumulator_voltage_pack;
  static constexpr auto kUnpack = &feb_can_bms_accumulator_voltage_unpack;
};

struct BmsAccumulatorTemperature
{
  using Data = feb_can_bms_accumulator_temperature_t;
  static constexpr std::uint32_t kFrameId = 0x3u;
  static constexpr std::uint8_t kLength = 8u;
  static constexpr bool kExtended = false;
  static constexpr std::uint32_t kCycleMs = 100u;
  static constexpr Node kSender = Node::kBms;
  static constexpr auto kPack = &feb_can_bms_accumulator_temperature_pack;
  static constexpr auto kUnpack = &feb_can_bms_accumulator_temperature_unpack;
};

struct AccumulatorFaults
{
  using Data = feb_can_accumulator_faults_t;
  static constexpr std::uint32_t kFrameId = 0x4u;
  static constexpr std::uint8_t kLength = 1u;
  static constexpr bool kExtended = false;
  static constexpr std::uint32_t kCycleMs = 100u;
  static constexpr Node kSender = Node::kBms;
  static constexpr auto kPack = &feb_can_accumulator_faults_pack;
  static constexpr auto kUnpack = &feb_can_accumulator_faults_unpack;
};

struct BmsState
{
  using Data = feb_can_bms_state_t;
  static constexpr std::uint32_t kFrameId = 0x5u;
  static constexpr std::uint8_t kLength = 2u;
  static constexpr bool kExtended = false;
  static constexpr std::uint32_t kCycleMs = 100u;
  static constexpr Node kSender = Node::kBms;
  static constexpr auto kPack = &feb_can_bms_state_pack;
  static constexpr auto kUnpack = &feb_can_bms_state_unpack;
};

struct Brake
{
  using Data = feb_can_brake_t;
  static constexpr std::uint32_t kFrameId = 0x9u;
  static constexpr std::uint8_t kLength = 8u;
  static constexpr bool kExtended = false;
  static constexpr std::uint32_t kCycleMs = 100u;
  static constexpr Node kSender = Node::kPcu;
  static constexpr auto kPack = &feb_can_brake_pack;
  static constexpr auto kUnpack = &feb_can_brake_unpack;
};

struct BspdState
{
  using Data = feb_can_bspd_state_t;
  static constexpr std::uint32_t kFrameId = 0xAu;
  static constexpr std::uint8_t kLength = 1u;
  static constexpr bool kExtended = false;
  static constexpr std::uint32_t kCycleMs = 100u;
  static constexpr Node kSender = Node::kPcu;
  static constexpr auto kPack = &feb_can_bspd_state_pack;
  static constexpr auto kUnpack = &feb_can_bspd_state_unpack;
};

struct ResState
{
  using Data = feb_can_res_state_t;
  static constexpr std::uint32_t kFrameId = 0xBu;
  static constexpr std::uint8_t kLength = 2u;
  static constexpr bool kExtended = false;
  static constexpr std::uint32_t kCycleMs = 100u;
  static constexpr Node kSender = Node::kPcu;
  static constexpr auto kPack = &feb_can_res_state_pack;
  static constexpr auto kUnpack = &feb_can_res_state_unpack;
};

struct DashState
{
  using Data = feb_can_dash_state_t;
  static constexpr std::uint32_t kFrameId = 0x10u;
  static constexpr std::uint8_t kLength = 2u;
  static constexpr bool kExtended = false;
  static constexpr std::uint32_t kCycleMs = 100u;
  static constexpr Node kSender = Node::kDash;
  static constexpr auto kPack = &feb_can_dash_state_pack;
  static constexpr auto kUnpack = &feb_can_dash_state_unpack;
};

struct LvpdbLv24vBusAnd12vBusVoltages
{
  using Data = feb_can_lvpdb_lv_24v_bus_and_12v_bus_voltages_t;
  static constexpr std::uint32_t kFrameId = 0x16u;
  static constexpr std::uint8_t kLength = 4u;
  static constexpr bool kExtended = false;
  static constexpr std::uint32_t kCycleMs = 100u;
  static constexpr Node kSender = Node::kLvpdb;
  static constexpr auto kPack = &feb_can_lvpdb_lv_24v_bus_and_12v_bus_voltages_pack;
  static constexpr auto kUnpack = &feb_can_lvpdb_lv_24v_bus_and_12v_bus_voltages_unpack;
};

struct LvpdbLvShLtBmLCurrents
{
  using Data = feb_can_lvpdb_lv_sh_lt_bm_l_currents_t;
  static constexpr std::uint32_t kFrameId = 0x17u;
  static constexpr std::uint8_t kLength = 8u;
  static constexpr bool kExtended = false;
  static constexpr std::uint32_t kCycleMs = 100u;
  static constexpr Node kSender = Node::kLvpdb;
  static constexpr auto kPack = &feb_can_lvpdb_lv_sh_lt_bm_l_currents_pack;
  static constexpr auto kUnpack = &feb_can_lvpdb_lv_sh_lt_bm_l_currents_unpack;
};

struct LvpdbSmAf1Af2CpRfCurrents
{
  using Data = feb_can_lvpdb_sm_af1_af2_cp_rf_currents_t;
  static constexpr std::uint32_t kFrameId = 0x18u;
  static constexpr std::uint8_t kLength = 8u;
  static constexpr bool kExtended = false;
  static constexpr std::uint32_t kCycleMs = 100u;
  static constexpr Node kSender = Node::kLvpdb;
  static constexpr auto kPack = &feb_can_lvpdb_sm_af1_af2_cp_rf_currents_pack;
  static constexpr auto kUnpack = &feb_can_lvpdb_sm_af1_af2_cp_rf_currents_unpack;
};

struct LinearPotentiometerFront
{
  using Data = feb_can_linear_potentiometer_front_t;
  static constexpr std::uint32_t kFrameId = 0x1Eu;
  static constexpr std::uint8_t kLength = 4u;
  static constexpr bool kExtended = false;
  static constexpr std::uint32_t kCycleMs = 20u;
  static constexpr Node kSender = Node::kSnFront;
  static constexpr auto kPack = &feb_can_linear_potentiometer_front_pack;
  static constexpr auto kUnpack = &feb_can_linear_potentiometer_front_unpack;
};

struct LinearPotentiometerRear
{
  using Data = feb_can_linear_potentiometer_rear_t;
  static constexpr std::uint32_t kFrameId = 0x1Fu;
  static constexpr std::uint8_t kLength = 4u;
  static constexpr bool kExtended = false;
  static constexpr std::uint32_t kCycleMs = 20u;
  static constexpr Node kSender = Node::kSnRear;
  static constexpr auto kPack = &feb_can_linear_potentiometer_rear_pack;
  static constexpr auto kUnpack = &feb_can_linear_potentiometer_rear_unpack;
};

struct FrontLeftTireTemp
{
  using Data = feb_can_front_left_tire_temp_t;
  static constexpr std::uint32_t kFrameId = 0x20u;
  static constexpr std::uint8_t kLength = 8u;
  static constexpr bool kExtended = false;
  static constexpr std::uint32_t kCycleMs = 1000u;
  static constexpr Node kSender = Node::kSnFront;
  static constexpr auto kPack = &feb_can_front_left_tire_temp_pack;
  static constexpr auto kUnpack = &feb_can_front_left_tire_temp_unpack;
};

struct FrontRightTireTemp
{
  using Data = feb_can_front_right_tire_temp_t;
  static constexpr std::uint32_t kFrameId = 0x21u;
  static constexpr std::uint8_t kLength = 8u;
  static constexpr bool kExtended = false;
  static constexpr std::uint32_t kCycleMs = 1000u;
  static constexpr Node kSender = Node::kSnFront;
  static constexpr auto kPack = &feb_can_front_right_tire_temp_pack;
  static constexpr auto kUnpack = &feb_can_front_right_tire_temp_unpack;
};

struct RearLeftTireTemp
{
  using Data = feb_can_rear_left_tire_temp_t;
  static constexpr std::uint32_t kFrameId = 0x22u;
  static constexpr std::uint8_t kLength = 8u;
  static constexpr bool kExtended = false;
  static constexpr std::uint32_t kCycleMs = 1000u;
  static constexpr Node kSender = Node::kSnRear;
  static constexpr auto kPack = &feb_can_rear_left_tire_temp_pack;
  static constexpr auto kUnpack = &feb_can_rear_left_tire_temp_unpack;
};

struct RearRightTireTemp
{
  using Data = feb_can_rear_right_tire_temp_t;
  static constexpr std::uint32_t kFrameId = 0x23u;
  static constexpr std::uint8_t kLength = 8u;
  static constexpr bool kExtended = false;
  static constexpr std::uint32_t kCycleMs = 1000u;
  static constexpr Node kSender = Node::kSnRear;
  static constexpr auto kPack = &feb_can_rear_right_tire_temp_pack;
  static constexpr auto kUnpack = &feb_can_rear_right_tire_temp_unpack;
};

struct WssFrontData
{
  using Data = feb_can_wss_front_data_t;
  static constexpr std::uint32_t kFrameId = 0x24u;
  static constexpr std::uint8_t kLength = 8u;
  static constexpr bool kExtended = false;
  static constexpr std::uint32_t kCycleMs = 20u;
  static constexpr Node kSender = Node::kSnFront;
  static constexpr auto kPack = &feb_can_wss_front_data_pack;
  static constexpr auto kUnpack = &feb_can_wss_front_data_unpack;
};

struct WssRearData
{
  using Data = feb_can_wss_rear_data_t;
  static constexpr std::uint32_t kFrameId = 0x25u;
  static constexpr std::uint8_t kLength = 8u;
  static constexpr bool kExtended = false;
  static constexpr std::uint32_t kCycleMs = 20u;
  static constexpr Node kSender = Node::kSnRear;
  static constexpr auto kPack = &feb_can_wss_rear_data_pack;
  static constexpr auto kUnpack = &feb_can_wss_rear_data_unpack;
};

struct ImuAccelerationData
{
  using Data = feb_can_imu_acceleration_data_t;
  static constexpr std::uint32_t kFrameId = 0x26u;
  static constexpr std::uint8_t kLength = 6u;
  static constexpr bool kExtended = false;
  static constexpr std::uint32_t kCycleMs = 100u;
  static constexpr Node kSender = Node::kSnFront;
  static constexpr auto kPack = &feb_can_imu_acceleration_data_pack;
  static constexpr auto kUnpack = &feb_can_imu_acceleration_data_unpack;
};

struct ImuAccelerationDataRear
{
  using Data = feb_can_imu_acceleration_data_rear_t;
  static constexpr std::uint32_t kFrameId = 0x27u;
  static constexpr std::uint8_t kLength = 6u;
  static constexpr bool kExtended = false;
  static constexpr std::uint32_t kCycleMs = 100u;
  static constexpr Node kSender = Node::kSnRear;
  static constexpr auto kPack = &feb_can_imu_acceleration_data_rear_pack;
  static constexpr auto kUnpack = &feb_can_imu_acceleration_data_rear_unpack;
};

struct ImuGyroData
{
  using Data = feb_can_imu_gyro_data_t;
  static constexpr std::uint32_t kFrameId = 0x28u;
  static constexpr std::uint8_t kLength = 6u;
  static constexpr bool kExtended = false;
  static constexpr std::uint32_t kCycleMs = 100u;
  static constexpr Node kSender = Node::kSnFront;
  static constexpr auto kPack = &feb_can_imu_gyro_data_pack;
  static constexpr auto kUnpack = &feb_can_imu_gyro_data_unpack;
};

struct ImuGyroDataRear
{
  using Data = feb_can_imu_gyro_data_rear_t;
  static constexpr std::uint32_t kFrameId = 0x29u;
  static constexpr std::uint8_t kLength = 6u;
  static constexpr bool kExtended = false;
  static constexpr std::uint32_t kCycleMs = 100u;
  static constexpr Node kSender = Node::kSnRear;
  static constexpr auto kPack = &feb_can_imu_gyro_data_rear_pack;
  static constexpr auto kUnpack = &feb_can_imu_gyro_data_rear_unpack;
};

struct MagnetometerData
{
  using Data = feb_can_magnetometer_data_t;
  static constexpr std::uint32_t kFrameId = 0x2Au;
  static constexpr std::uint8_t kLength = 6u;
  static constexpr bool kExtended = false;
  static constexpr std::uint32_t kCycleMs = 100u;
  static constexpr Node kSender = Node::kSnFront;
  static constexpr auto kPack = &feb_can_magnetometer_data_pack;
  static constexpr auto kUnpack = &feb_can_magnetometer_data_unpack;
};

struct MagnetometerDataRear
{
  using Data = feb_can_magnetometer_data_rear_t;
  static constexpr std::uint32_t kFrameId = 0x2Bu;
  static constexpr std::uint8_t kLength = 6u;
  static constexpr bool kExtended = false;
  static constexpr std::uint32_t kCycleMs = 100u;
  static constexpr Node kSender = Node::kSnRear;
  static constexpr auto kPack = &feb_can_magnetometer_data_rear_pack;
  static constexpr auto kUnpack = &feb_can_magnetometer_data_rear_unpack;
};

struct DartTachMeasurements1234
{
  using Data = feb_can_dart_tach_measurements_1234_t;
  static constexpr std::uint32_t kFrameId = 0x2Du;
  static constexpr std::uint8_t kLength = 8u;
  static constexpr bool kExtended = false;
  static constexpr std::uint32_t kCycleMs = 100u;
  static constexpr Node kSender = Node::kDart;
  static constexpr auto kPack = &feb_can_dart_tach_measurements_1234_pack;
  static constexpr auto kUnpack = &feb_can_dart_tach_measurements_1234_unpack;
};

struct DartTachMeasurements5
{
  using Data = feb_can_dart_tach_measurements_5_t;
  static constexpr std::uint32_t kFrameId = 0x2Eu;
  static constexpr std::uint8_t kLength = 2u;
  static constexpr bool kExtended = false;
  static constexpr std::uint32_t kCycleMs = 100u;
  static constexpr Node kSender = Node::kDart;
  static constexpr auto kPack = &feb_can_dart_tach_measurements_5_pack;
  static constexpr auto kUnpack = &feb_can_dart_tach_measurements_5_unpack;
};

struct BbbTps
{
  using Data = feb_can_bbb_tps_t;
  static constexpr std::uint32_t kFrameId = 0x34u;
  static constexpr std::uint8_t kLength = 4u;
  static constexpr bool kExtended = false;
  static constexpr std::uint32_t kCycleMs = 100u;
  static constexpr Node kSender = Node::kBms;
  static constexpr auto kPack = &feb_can_bbb_tps_pack;
  static constexpr auto kUnpack = &feb_can_bbb_tps_unpack;
};

struct PcuTps
{
  using Data = feb_can_pcu_tps_t;
  static constexpr std::uint32_t kFrameId = 0x35u;
  static constexpr std::uint8_t kLength = 4u;
  static constexpr bool kExtended = false;
  static constexpr std::uint32_t kCycleMs = 100u;
  static constexpr Node kSender = Node::kPcu;
  static constexpr auto kPack = &feb_can_pcu_tps_pack;
  static constexpr auto kUnpack = &feb_can_pcu_tps_unpack;
};

struct DashTps
{
  using Data = feb_can_dash_tps_t;
  static constexpr std::uint32_t kFrameId = 0x36u;
  static constexpr std::uint8_t kLength = 4u;
  static constexpr bool kExtended = false;
  static constexpr std::uint32_t kCycleMs = 100u;
  static constexpr Node kSender = Node::kDash;
  static constexpr auto kPack = &feb_can_dash_tps_pack;
  static constexpr auto kUnpack = &feb_can_dash_tps_unpack;
};

struct DcuTps
{
  using Data = feb_can_dcu_tps_t;
  static constexpr std::uint32_t kFrameId = 0x37u;
  static constexpr std::uint8_t kLength = 4u;
  static constexpr bool kExtended = false;
  static constexpr std::uint32_t kCycleMs = 100u;
  static constexpr Node kSender = Node::kDcu;
  static constexpr auto kPack = &feb_can_dcu_tps_pack;
  static constexpr auto kUnpack = &feb_can_dcu_tps_unpack;
};

struct PcuRawAcc
{
  using Data = feb_can_pcu_raw_acc_t;
  static constexpr std::uint32_t kFrameId = 0x38u;
  static constexpr std::uint8_t kLength = 8u;
  static constexpr bool kExtended = false;
  static constexpr std::uint32_t kCycleMs = 50u;
  static constexpr Node kSender = Node::kPcu;
  static constexpr auto kPack = &feb_can_pcu_raw_acc_pack;
  static constexpr auto kUnpack = &feb_can_pcu_raw_acc_unpack;
};

struct PcuPedalVoltages
{
  using Data = feb_can_pcu_pedal_voltages_t;
  static constexpr std::uint32_t kFrameId = 0x39u;
  static constexpr std::uint8_t kLength = 8u;
  static constexpr bool kExtended = false;
  static constexpr std::uint32_t kCycleMs = 100u;
  static constexpr Node kSender = Node::kPcu;
  static constexpr auto kPack = &feb_can_pcu_pedal_voltages_pack;
  static constexpr auto kUnpack = &feb_can_pcu_pedal_voltages_unpack;
};

struct GpsPosData
{
  using Data = feb_can_gps_pos_data_t;
  static constexpr std::uint32_t kFrameId = 0x40u;
  static constexpr std::uint8_t kLength = 8u;
  static constexpr bool kExtended = false;
  static constexpr std::uint32_t kCycleMs = 200u;
  static constexpr Node kSender = Node::kSnFront;
  static constexpr auto kPack = &feb_can_gps_pos_data_pack;
  static constexpr auto kUnpack = &feb_can_gps_pos_data_unpack;
};

struct GpsAltitudeData
{
  using Data = feb_can_gps_altitude_data_t;
  static constexpr std::uint32_t kFrameId = 0x41u;
  static constexpr std::uint8_t kLength = 8u;
  static constexpr bool kExtended = false;
  static constexpr std::uint32_t kCycleMs = 200u;
  static constexpr Node kSender = Node::kSnFront;
  static constexpr auto kPack = &feb_can_gps_altitude_data_pack;
  static constexpr auto kUnpack = &feb_can_gps_altitude_data_unpack;
};

struct GpsMotionData
{
  using Data = feb_can_gps_motion_data_t;
  static constexpr std::uint32_t kFrameId = 0x42u;
  static constexpr std::uint8_t kLength = 4u;
  static constexpr bool kExtended = false;
  static constexpr std::uint32_t kCycleMs = 200u;
  static constexpr Node kSender = Node::kSnFront;
  static constexpr auto kPack = &feb_can_gps_motion_data_pack;
  static constexpr auto kUnpack = &feb_can_gps_motion_data_unpack;
};

struct GpsTimeData
{
  using Data = feb_can_gps_time_data_t;
  static constexpr std::uint32_t kFrameId = 0x43u;
  static constexpr std::uint8_t kLength = 3u;
  static constexpr bool kExtended = false;
  static constexpr std::uint32_t kCycleMs = 200u;
  static constexpr Node kSender = Node::kSnFront;
  static constexpr auto kPack = &feb_can_gps_time_data_pack;
  static constexpr auto kUnpack = &feb_can_gps_time_data_unpack;
};

struct GpsDateData
{
  using Data = feb_can_gps_date_data_t;
  static constexpr std::uint32_t kFrameId = 0x44u;
  static constexpr std::uint8_t kLength = 3u;
  static constexpr bool kExtended = false;
  static constexpr std::uint32_t kCycleMs = 200u;
  static constexpr Node kSender = Node::kSnFront;
  static constexpr auto kPack = &feb_can_gps_date_data_pack;
  static constexpr auto kUnpack = &feb_can_gps_date_data_unpack;
};

struct GpsStatusData
{
  using Data = feb_can_gps_status_data_t;
  static constexpr std::uint32_t kFrameId = 0x45u;
  static constexpr std::uint8_t kLength = 8u;
  static constexpr bool kExtended = false;
  static constexpr std::uint32_t kCycleMs = 200u;
  static constexpr Node kSender = Node::kSnFront;
  static constexpr auto kPack = &feb_can_gps_status_data_pack;
  static constexpr auto kUnpack = &feb_can_gps_status_data_unpack;
};

struct FusionQuaternionData
{
  using Data = feb_can_fusion_quaternion_data_t;
  static constexpr std::uint32_t kFrameId = 0x47u;
  static constexpr std::uint8_t kLength = 8u;
  static constexpr bool kExtended = false;
  static constexpr std::uint32_t kCycleMs = 100u;
  static constexpr Node kSender = Node::kSnFront;
  static constexpr auto kPack = &feb_can_fusion_quaternion_data_pack;
  static constexpr auto kUnpack = &feb_can_fusion_quaternion_data_unpack;
};

struct FusionEulerData
{
  using Data = feb_can_fusion_euler_data_t;
  static constexpr std::uint32_t kFrameId = 0x48u;
  static constexpr std::uint8_t kLength = 6u;
  static constexpr bool kExtended = false;
  static constexpr std::uint32_t kCycleMs = 100u;
  static constexpr Node kSender = Node::kSnFront;
  static constexpr auto kPack = &feb_can_fusion_euler_data_pack;
  static constexpr auto kUnpack = &feb_can_fusion_euler_data_unpack;
};

struct FusionLinearAccelData
{
  using Data = feb_can_fusion_linear_accel_data_t;
  static constexpr std::uint32_t kFrameId = 0x49u;
  static constexpr std::uint8_t kLength = 6u;
  static constexpr bool kExtended = false;
  static constexpr std::uint32_t kCycleMs = 100u;
  static constexpr Node kSender = Node::kSnFront;
  static constexpr auto kPack = &feb_can_fusion_linear_accel_data_pack;
  static constexpr auto kUnpack = &feb_can_fusion_linear_accel_data_unpack;
};

struct FusionEarthAccelData
{
  using Data = feb_can_fusion_earth_accel_data_t;
  static constexpr std::uint32_t kFrameId = 0x4Au;
  static constexpr std::uint8_t kLength = 6u;
  static constexpr bool kExtended = false;
  static constexpr std::uint32_t kCycleMs = 100u;
  static constexpr Node kSender = Node::kSnFront;
  static constexpr auto kPack = &feb_can_fusion_earth_accel_data_pack;
  static constexpr auto kUnpack = &feb_can_fusion_earth_accel_data_unpack;
};

struct FusionStatusData
{
  using Data = feb_can_fusion_status_data_t;
  static constexpr std::uint32_t kFrameId = 0x4Bu;
  static constexpr std::uint8_t kLength = 3u;
  static constexpr bool kExtended = false;
  static constexpr std::uint32_t kCycleMs = 100u;
  static constexpr Node kSender = Node::kSnFront;
  static constexpr auto kPack = &feb_can_fusion_status_data_pack;
  static constexpr auto kUnpack = &feb_can_fusion_status_data_unpack;
};

struct SensorTempsData
{
  using Data = feb_can_sensor_temps_data_t;
  static constexpr std::uint32_t kFrameId = 0x4Cu;
  static constexpr std::uint8_t kLength = 4u;
  static constexpr bool kExtended = false;
  static constexpr std::uint32_t kCycleMs = 1000u;
  static constexpr Node kSender = Node::kSnFront;
  static constexpr auto kPack = &feb_can_sensor_temps_data_pack;
  static constexpr auto kUnpack = &feb_can_sensor_temps_data_unpack;
};

struct SensorTempsDataRear
{
  using Data = feb_can_sensor_temps_data_rear_t;
  static constexpr std::uint32_t kFrameId = 0x4Du;
  static constexpr std::uint8_t kLength = 4u;
  static constexpr bool kExtended = false;
  static constexpr std::uint32_t kCycleMs = 1000u;
  static constexpr Node kSender = Node::kSnRear;
  static constexpr auto kPack = &feb_can_sensor_temps_data_rear_pack;
  static constexpr auto kUnpack = &feb_can_sensor_temps_data_rear_unpack;
};

struct SteerAngleData
{
  using Data = feb_can_steer_angle_data_t;
  static constexpr std::uint32_t kFrameId = 0x4Eu;
  static constexpr std::uint8_t kLength = 5u;
  static constexpr bool kExtended = false;
  static constexpr std::uint32_t kCycleMs = 100u;
  static constexpr Node kSender = Node::kSnFront;
  static constexpr auto kPack = &feb_can_steer_angle_data_pack;
  static constexpr auto kUnpack = &feb_can_steer_angle_data_unpack;
};

struct SteerStatusData
{
  using Data = feb_can_steer_status_data_t;
  static constexpr std::uint32_t kFrameId = 0x4Fu;
  static constexpr std::uint8_t kLength = 3u;
  static constexpr bool kExtended = false;
  static constexpr std::uint32_t kCycleMs = 100u;
  static constexpr Node kSender = Node::kSnFront;
  static constexpr auto kPack = &feb_can_steer_status_data_pack;
  static constexpr auto kUnpack = &feb_can_steer_status_data_unpack;
};

struct GpsPosDataRear
{
  using Data = feb_can_gps_pos_data_rear_t;
  static constexpr std::uint32_t kFrameId = 0x50u;
  static constexpr std::uint8_t kLength = 8u;
  static constexpr bool kExtended = false;
  static constexpr std::uint32_t kCycleMs = 200u;
  static constexpr Node kSender = Node::kSnRear;
  static constexpr auto kPack = &feb_can_gps_pos_data_rear_pack;
  static constexpr auto kUnpack = &feb_can_gps_pos_data_rear_unpack;
};

struct GpsAltitudeDataRear
{
  using Data = feb_can_gps_altitude_data_rear_t;
  static constexpr std::uint32_t kFrameId = 0x51u;
  static constexpr std::uint8_t kLength = 8u;
  static constexpr bool kExtended = false;
  static constexpr std::uint32_t kCycleMs = 200u;
  static constexpr Node kSender = Node::kSnRear;
  static constexpr auto kPack = &feb_can_gps_altitude_data_rear_pack;
  static constexpr auto kUnpack = &feb_can_gps_altitude_data_rear_unpack;
};

struct GpsMotionDataRear
{
  using Data = feb_can_gps_motion_data_rear_t;
  static constexpr std::uint32_t kFrameId = 0x52u;
  static constexpr std::uint8_t kLength = 4u;
  static constexpr bool kExtended = false;
  static constexpr std::uint32_t kCycleMs = 200u;
  static constexpr Node kSender = Node::kSnRear;
  static constexpr auto kPack = &feb_can_gps_motion_data_rear_pack;
  static constexpr auto kUnpack = &feb_can_gps_motion_data_rear_unpack;
};

struct GpsTimeDataRear
{
  using Data = feb_can_gps_time_data_rear_t;
  static constexpr std::uint32_t kFrameId = 0x53u;
  static constexpr std::uint8_t kLength = 3u;
  static constexpr bool kExtended = false;
  static constexpr std::uint32_t kCycleMs = 200u;
  static constexpr Node kSender = Node::kSnRear;
  static constexpr auto kPack = &feb_can_gps_time_data_rear_pack;
  static constexpr auto kUnpack = &feb_can_gps_time_data_rear_unpack;
};

struct GpsDateDataRear
{
  using Data = feb_can_gps_date_data_rear_t;
  static constexpr std::uint32_t kFrameId = 0x54u;
  static constexpr std::uint8_t kLength = 3u;
  static constexpr bool kExtended = false;
  static constexpr std::uint32_t kCycleMs = 200u;
  static constexpr Node kSender = Node::kSnRear;
  static constexpr auto kPack = &feb_can_gps_date_data_rear_pack;
  static constexpr auto kUnpack = &feb_can_gps_date_data_rear_unpack;
};

struct GpsStatusDataRear
{
  using Data = feb_can_gps_status_data_rear_t;
  static constexpr std::uint32_t kFrameId = 0x55u;
  static constexpr std::uint8_t kLength = 8u;
  static constexpr bool kExtended = false;
  static constexpr std::uint32_t kCycleMs = 200u;
  static constexpr Node kSender = Node::kSnRear;
  static constexpr auto kPack = &feb_can_gps_status_data_rear_pack;
  static constexpr auto kUnpack = &feb_can_gps_status_data_rear_unpack;
};

struct FusionQuaternionDataRear
{
  using Data = feb_can_fusion_quaternion_data_rear_t;
  static constexpr std::uint32_t kFrameId = 0x57u;
  static constexpr std::uint8_t kLength = 8u;
  static constexpr bool kExtended = false;
  static constexpr std::uint32_t kCycleMs = 100u;
  static constexpr Node kSender = Node::kSnRear;
  static constexpr auto kPack = &feb_can_fusion_quaternion_data_rear_pack;
  static constexpr auto kUnpack = &feb_can_fusion_quaternion_data_rear_unpack;
};

struct FusionEulerDataRear
{
  using Data = feb_can_fusion_euler_data_rear_t;
  static constexpr std::uint32_t kFrameId = 0x58u;
  static constexpr std::uint8_t kLength = 6u;
  static constexpr bool kExtended = false;
  static constexpr std::uint32_t kCycleMs = 100u;
  static constexpr Node kSender = Node::kSnRear;
  static constexpr auto kPack = &feb_can_fusion_euler_data_rear_pack;
  static constexpr auto kUnpack = &feb_can_fusion_euler_data_rear_unpack;
};

struct FusionLinearAccelDataRear
{
  using Data = feb_can_fusion_linear_accel_data_rear_t;
  static constexpr std::uint32_t kFrameId = 0x59u;
  static constexpr std::uint8_t kLength = 6u;
  static constexpr bool kExtended = false;
  static constexpr std::uint32_t kCycleMs = 100u;
  static constexpr Node kSender = Node::kSnRear;
  static constexpr auto kPack = &feb_can_fusion_linear_accel_data_rear_pack;
  static constexpr auto kUnpack = &feb_can_fusion_linear_accel_data_rear_unpack;
};

struct FusionEarthAccelDataRear
{
  using Data = feb_can_fusion_earth_accel_data_rear_t;
  static constexpr std::uint32_t kFrameId = 0x5Au;
  static constexpr std::uint8_t kLength = 6u;
  static constexpr bool kExtended = false;
  static constexpr std::uint32_t kCycleMs = 100u;
  static constexpr Node kSender = Node::kSnRear;
  static constexpr auto kPack = &feb_can_fusion_earth_accel_data_rear_pack;
  static constexpr auto kUnpack = &feb_can_fusion_earth_accel_data_rear_unpack;
};

struct FusionStatusDataRear
{
  using Data = feb_can_fusion_status_data_rear_t;
  static constexpr std::uint32_t kFrameId = 0x5Bu;
  static constexpr std::uint8_t kLength = 3u;
  static constexpr bool kExtended = false;
  static constexpr std::uint32_t kCycleMs = 100u;
  static constexpr Node kSender = Node::kSnRear;
  static constexpr auto kPack = &feb_can_fusion_status_data_rear_pack;
  static constexpr auto kUnpack = &feb_can_fusion_status_data_rear_unpack;
};

struct PcuHeartbeat
{
  using Data = feb_can_pcu_heartbeat_t;
  static constexpr std::uint32_t kFrameId = 0xD0u;
  static constexpr std::uint8_t kLength = 8u;
  static constexpr bool kExtended = false;
  static constexpr std::uint32_t kCycleMs = 100u;
  static constexpr Node kSender = Node::kPcu;
  static constexpr auto kPack = &feb_can_pcu_heartbeat_pack;
  static constexpr auto kUnpack = &feb_can_pcu_heartbeat_unpack;
};

struct DashHeartbeat
{
  using Data = feb_can_dash_heartbeat_t;
  static constexpr std::uint32_t kFrameId = 0xD1u;
  static constexpr std::uint8_t kLength = 8u;
  static constexpr bool kExtended = false;
  static constexpr std::uint32_t kCycleMs = 100u;
  static constexpr Node kSender = Node::kDash;
  static constexpr auto kPack = &feb_can_dash_heartbeat_pack;
  static constexpr auto kUnpack = &feb_can_dash_heartbeat_unpack;
};

struct LvpdbHeartbeat
{
  using Data = feb_can_lvpdb_heartbeat_t;
  static constexpr std::uint32_t kFrameId = 0xD2u;
  static constexpr std::uint8_t kLength = 8u;
  static constexpr bool kExtended = false;
  static constexpr std::uint32_t kCycleMs = 100u;
  static constexpr Node kSender = Node::kLvpdb;
  static constexpr auto kPack = &feb_can_lvpdb_heartbeat_pack;
  static constexpr auto kUnpack = &feb_can_lvpdb_heartbeat_unpack;
};

struct DcuHeartbeat
{
  using Data = feb_can_dcu_heartbeat_t;
  static constexpr std::uint32_t kFrameId = 0xD3u;
  static constexpr std::uint8_t kLength = 8u;
  static constexpr bool kExtended = false;
  static constexpr std::uint32_t kCycleMs = 100u;
  static constexpr Node kSender = Node::kDcu;
  static constexpr auto kPack = &feb_can_dcu_heartbeat_pack;
  static constexpr auto kUnpack = &feb_can_dcu_heartbeat_unpack;
};

struct FrontSensorHeartbeatMessage
{
  using Data = feb_can_front_sensor_heartbeat_message_t;
  static constexpr std::uint32_t kFrameId = 0xD4u;
  static constexpr std::uint8_t kLength = 8u;
  static constexpr bool kExtended = false;
  static constexpr std::uint32_t kCycleMs = 100u;
  static constexpr Node kSender = Node::kSnFront;
  static constexpr auto kPack = &feb_can_front_sensor_heartbeat_message_pack;
  static constexpr auto kUnpack = &feb_can_front_sensor_heartbeat_message_unpack;
};

struct RearSensorHeartbeatMessage
{
  using Data = feb_can_rear_sensor_heartbeat_message_t;
  static constexpr std::uint32_t kFrameId = 0xD5u;
  static constexpr std::uint8_t kLength = 8u;
  static constexpr bool kExtended = false;
  static constexpr std::uint32_t kCycleMs = 100u;
  static constexpr Node kSender = Node::kSnRear;
  static constexpr auto kPack = &feb_can_rear_sensor_heartbeat_message_pack;
  static constexpr auto kUnpack = &feb_can_rear_sensor_heartbeat_message_unpack;
};

struct FebPingPongCounter1
{
  using Data = feb_can_feb_ping_pong_counter1_t;
  static constexpr std::uint32_t kFrameId = 0xE0u;
  static constexpr std::uint8_t kLength = 8u;
  static constexpr bool kExtended = false;
  static constexpr std::uint32_t kCycleMs = 100u;
  static constexpr Node kSender = Node::kNone;
  static constexpr auto kPack = &feb_can_feb_ping_pong_counter1_pack;
  static constexpr auto kUnpack = &feb_can_feb_ping_pong_counter1_unpack;
};

struct FebPingPongCounter2
{
  using Data = feb_can_feb_ping_pong_counter2_t;
  static constexpr std::uint32_t kFrameId = 0xE1u;
  static constexpr std::uint8_t kLength = 8u;
  static constexpr bool kExtended = false;
  static constexpr std::uint32_t kCycleMs = 100u;
  static constexpr Node kSender = Node::kNone;
  static constexpr auto kPack = &feb_can_feb_ping_pong_counter2_pack;
  static constexpr auto kUnpack = &feb_can_feb_ping_pong_counter2_unpack;
};

struct FebPingPongCounter3
{
  using Data = feb_can_feb_ping_pong_counter3_t;
  static constexpr std::uint32_t kFrameId = 0xE2u;
  static constexpr std::uint8_t kLength = 8u;
  static constexpr bool kExtended = false;
  static constexpr std::uint32_t kCycleMs = 100u;
  static constexpr Node kSender = Node::kNone;
  static constexpr auto kPack = &feb_can_feb_ping_pong_counter3_pack;
  static constexpr auto kUnpack = &feb_can_feb_ping_pong_counter3_unpack;
};

struct FebPingPongCounter4
{
  using Data = feb_can_feb_ping_pong_counter4_t;
  static constexpr std::uint32_t kFrameId = 0xE3u;
  static constexpr std::uint8_t kLength = 8u;
  static constexpr bool kExtended = false;
  static constexpr std::uint32_t kCycleMs = 100u;
  static constexpr Node kSender = Node::kNone;
  static constexpr auto kPack = &feb_can_feb_ping_pong_counter4_pack;
  static constexpr auto kUnpack = &feb_can_feb_ping_pong_counter4_unpack;
};

struct BmsCellVoltages
{
  using Data = feb_can_bms_cell_voltages_t;
  static constexpr std::uint32_t kFrameId = 0x204u;
  static constexpr std::uint8_t kLength = 8u;
  static constexpr bool kExtended = false;
  static constexpr std::uint32_t kCycleMs = 10u;
  static constexpr Node kSender = Node::kBms;
  static constexpr auto kPack = &feb_can_bms_cell_voltages_pack;
  static constexpr auto kUnpack = &feb_can_bms_cell_voltages_unpack;
};

struct BmsCellTemperatures
{
  using Data = feb_can_bms_cell_temperatures_t;
  static constexpr std::uint32_t kFrameId = 0x205u;
  static constexpr std::uint8_t kLength = 8u;
  static constexpr bool kExtended = false;
  static constexpr std::uint32_t kCycleMs = 10u;
  static constexpr Node kSender = Node::kBms;
  static constexpr auto kPack = &feb_can_bms_cell_temperatures_pack;
  static constexpr auto kUnpack = &feb_can_bms_cell_temperatures_unpack;
};

struct EbsPressureStatus
{
  using Data = feb_can_ebs_pressure_status_t;
  static constexpr std::uint32_t kFrameId = 0x500u;
  static constexpr std::uint8_t kLength = 8u;
  static constexpr bool kExtended = false;
  static constexpr std::uint32_t kCycleMs = 100u;
  static constexpr Node kSender = Node::kPcu;
  static constexpr auto kPack = &feb_can_ebs_pressure_status_pack;
  static constexpr auto kUnpack = &feb_can_ebs_pressure_status_unpack;
};

struct IvtCurrent
{
  using Data = feb_can_ivt_current_t;
  static constexpr std::uint32_t kFrameId = 0x521u;
  static constexpr std::uint8_t kLength = 6u;
  static constexpr bool kExtended = false;
  static constexpr std::uint32_t kCycleMs = 0u;
  static constexpr Node kSender = Node::kIvt;
  static constexpr auto kPack = &feb_can_ivt_current_pack;
  static constexpr auto kUnpack = &feb_can_ivt_current_unpack;
};

struct IvtVoltage1
{
  using Data = feb_can_ivt_voltage1_t;
  static constexpr std::uint32_t kFrameId = 0x522u;
  static constexpr std::uint8_t kLength = 6u;
  static constexpr bool kExtended = false;
  static constexpr std::uint32_t kCycleMs = 0u;
  static constexpr Node kSender = Node::kIvt;
  static constexpr auto kPack = &feb_can_ivt_voltage1_pack;
  static constexpr auto kUnpack = &feb_can_ivt_voltage1_unpack;
};

struct IvtVoltage2
{
  using Data = feb_can_ivt_voltage2_t;
  static constexpr std::uint32_t kFrameId = 0x523u;
  static constexpr std::uint8_t kLength = 6u;
  static constexpr bool kExtended = false;
  static constexpr std::uint32_t kCycleMs = 0u;
  static constexpr Node kSender = Node::kIvt;
  static constexpr auto kPack = &feb_can_ivt_voltage2_pack;
  static constexpr auto kUnpack = &feb_can_ivt_voltage2_unpack;
};

struct IvtVoltage3
{
  using Data = feb_can_ivt_voltage3_t;
  static constexpr std::uint32_t kFrameId = 0x524u;
  static constexpr std::uint8_t kLength = 6u;
  static constexpr bool kExtended = false;
  static constexpr std::uint32_t kCycleMs = 0u;
  static constexpr Node kSender = Node::kIvt;
  static constexpr auto kPack = &feb_can_ivt_voltage3_pack;
  static constexpr auto kUnpack = &feb_can_ivt_voltage3_unpack;
};

struct IvtTemperature
{
  using Data = feb_can_ivt_temperature_t;
  static constexpr std::uint32_t kFrameId = 0x525u;
  static constexpr std::uint8_t kLength = 6u;
  static constexpr bool kExtended = false;
  static constexpr std::uint32_t kCycleMs = 0u;
  static constexpr Node kSender = Node::kIvt;
  static constexpr auto kPack = &feb_can_ivt_temperature_pack;
  static constexpr auto kUnpack = &feb_can_ivt_temperature_unpack;
};

struct ChargerLimits
{
  using Data = feb_can_charger_limits_t;
  static constexpr std::uint32_t kFrameId = 0x1806E5F4u;
  static constexpr std::uint8_t kLength = 8u;
  static constexpr bool kExtended = true;
  static constexpr std::uint32_t kCycleMs = 1000u;
  static constexpr Node kSender = Node::kBms;
  static constexpr auto kPack = &feb_can_charger_limits_pack;
  static constexpr auto kUnpack = &feb_can_charger_limits_unpack;
};

struct ChargerStatus
{
  using Data = feb_can_charger_status_t;
  static constexpr std::uint32_t kFrameId = 0x18FF50E5u;
  static constexpr std::uint8_t kLength = 8u;
  static constexpr bool kExtended = true;
  static constexpr std::uint32_t kCycleMs = 1000u;
  static constexpr Node kSender = Node::kNone;
  static constexpr auto kPack = &feb_can_charger_status_pack;
  static constexpr auto kUnpack = &feb_can_charger_status_unpack;
};

struct M160TemperatureSet1
{
  using Data = feb_can_m160_temperature_set_1_t;
  static constexpr std::uint32_t kFrameId = 0xA0u;
  static constexpr std::uint8_t kLength = 8u;
  static constexpr bool kExtended = false;
  static constexpr std::uint32_t kCycleMs = 100u;
  static constexpr Node kSender = Node::kNone;
  static constexpr auto kPack = &feb_can_m160_temperature_set_1_pack;
  static constexpr auto kUnpack = &feb_can_m160_temperature_set_1_unpack;
};

struct M161TemperatureSet2
{
  using Data = feb_can_m161_temperature_set_2_t;
  static constexpr std::uint32_t kFrameId = 0xA1u;
  static constexpr std::uint8_t kLength = 8u;
  static constexpr bool kExtended = false;
  static constexpr std::uint32_t kCycleMs = 100u;
  static constexpr Node kSender = Node::kNone;
  static constexpr auto kPack = &feb_can_m161_temperature_set_2_pack;
  static constexpr auto kUnpack = &feb_can_m161_temperature_set_2_unpack;
};

struct M162TemperatureSet3
{
  using Data = feb_can_m162_temperature_set_3_t;
  static constexpr std::uint32_t kFrameId = 0xA2u;
  static constexpr std::uint8_t kLength = 8u;
  static constexpr bool kExtended = false;
  static constexpr std::uint32_t kCycleMs = 100u;
  static constexpr Node kSender = Node::kNone;
  static constexpr auto kPack = &feb_can_m162_temperature_set_3_pack;
  static constexpr auto kUnpack = &feb_can_m162_temperature_set_3_unpack;
};

struct M163AnalogInputVoltages
{
  using Data = feb_can_m163_analog_input_voltages_t;
  static constexpr std::uint32_t kFrameId = 0xA3u;
  static constexpr std::uint8_t kLength = 8u;
  static constexpr bool kExtended = false;
  static constexpr std::uint32_t kCycleMs = 10u;
  static constexpr Node kSender = Node::kNone;
  static constexpr auto kPack = &feb_can_m163_analog_input_voltages_pack;
  static constexpr auto kUnpack = &feb_can_m163_analog_input_voltages_unpack;
};

struct M164DigitalInputStatus
{
  using Data = feb_can_m164_digital_input_status_t;
  static constexpr std::uint32_t kFrameId = 0xA4u;
  static constexpr std::uint8_t kLength = 8u;
  static constexpr bool kExtended = false;
  static constexpr std::uint32_t kCycleMs = 10u;
  static constexpr Node kSender = Node::kNone;
  static constexpr auto kPack = &feb_can_m164_digital_input_status_pack;
  static constexpr auto kUnpack = &feb_can_m164_digital_input_status_unpack;
};

struct M165MotorPositionInfo
{
  using Data = feb_can_m165_motor_position_info_t;
  static constexpr std::uint32_t kFrameId = 0xA5u;
  static constexpr std::uint8_t kLength = 8u;
  static constexpr bool kExtended = false;
  static constexpr std::uint32_t kCycleMs = 10u;
  static constexpr Node kSender = Node::kNone;
  static constexpr auto kPack = &feb_can_m165_motor_position_info_pack;
  static constexpr auto kUnpack = &feb_can_m165_motor_position_info_unpack;
};

struct M166CurrentInfo
{
  using Data = feb_can_m166_current_info_t;
  static constexpr std::uint32_t kFrameId = 0xA6u;
  static constexpr std::uint8_t kLength = 8u;
  static constexpr bool kExtended = false;
  static constexpr std::uint32_t kCycleMs = 10u;
  static constexpr Node kSender = Node::kNone;
  static constexpr auto kPack = &feb_can_m166_current_info_pack;
  static constexpr auto kUnpack = &feb_can_m166_current_info_unpack;
};

struct M167VoltageInfo
{
  using Data = feb_can_m167_voltage_info_t;
  static constexpr std::uint32_t kFrameId = 0xA7u;
  static constexpr std::uint8_t kLength = 8u;
  static constexpr bool kExtended = false;
  static constexpr std::uint32_t kCycleMs = 10u;
  static constexpr Node kSender = Node::kNone;
  static constexpr auto kPack = &feb_can_m167_voltage_info_pack;
  static constexpr auto kUnpack = &feb_can_m167_voltage_info_unpack;
};

struct M168FluxIdIqInfo
{
  using Data = feb_can_m168_flux_id_iq_info_t;
  static constexpr std::uint32_t kFrameId = 0xA8u;
  static constexpr std::uint8_t kLength = 8u;
  static constexpr bool kExtended = false;
  static constexpr std::uint32_t kCycleMs = 10u;
  static constexpr Node kSender = Node::kNone;
  static constexpr auto kPack = &feb_can_m168_flux_id_iq_info_pack;
  static constexpr auto kUnpack = &feb_can_m168_flux_id_iq_info_unpack;
};

struct M169InternalVoltages
{
  using Data = feb_can_m169_internal_voltages_t;
  static constexpr std::uint32_t kFrameId = 0xA9u;
  static constexpr std::uint8_t kLength = 8u;
  static constexpr bool kExtended = false;
  static constexpr std::uint32_t kCycleMs = 100u;
  static constexpr Node kSender = Node::kNone;
  static constexpr auto kPack = &feb_can_m169_internal_voltages_pack;
  static constexpr auto kUnpack = &feb_can_m169_internal_voltages_unpack;
};

struct M170InternalStates
{
  using Data = feb_can_m170_internal_states_t;
  static constexpr std::uint32_t kFrameId = 0xAAu;
  static constexpr std::uint8_t kLength = 8u;
  static constexpr bool kExtended = false;
  static constexpr std::uint32_t kCycleMs = 100u;
  static constexpr Node kSender = Node::kNone;
  static constexpr auto kPack = &feb_can_m170_internal_states_pack;
  static constexpr auto kUnpack = &feb_can_m170_internal_states_unpack;
};

struct M171FaultCodes
{
  using Data = feb_can_m171_fault_codes_t;
  static constexpr std::uint32_t kFrameId = 0xABu;
  static constexpr std::uint8_t kLength = 8u;
  static constexpr bool kExtended = false;
  static constexpr std::uint32_t kCycleMs = 100u;
  static constexpr Node kSender = Node::kNone;
  static constexpr auto kPack = &feb_can_m171_fault_codes_pack;
  static constexpr auto kUnpack = &feb_can_m171_fault_codes_unpack;
};

struct M172TorqueAndTimerInfo
{
  using Data = feb_can_m172_torque_and_timer_info_t;
  static constexpr std::uint32_t kFrameId = 0xACu;
  static constexpr std::uint8_t kLength = 8u;
  static constexpr bool kExtended = false;
  static constexpr std::uint32_t kCycleMs = 10u;
  static constexpr Node kSender = Node::kNone;
  static constexpr auto kPack = &feb_can_m172_torque_and_timer_info_pack;
  static constexpr auto kUnpack = &feb_can_m172_torque_and_timer_info_unpack;
};

struct M173ModulationAndFluxInfo
{
  using Data = feb_can_m173_modulation_and_flux_info_t;
  static constexpr std::uint32_t kFrameId = 0xADu;
  static constexpr std::uint8_t kLength = 8u;
  static constexpr bool kExtended = false;
  static constexpr std::uint32_t kCycleMs = 0u;
  static constexpr Node kSender = Node::kNone;
  static constexpr auto kPack = &feb_can_m173_modulation_and_flux_info_pack;
  static constexpr auto kUnpack = &feb_can_m173_modulation_and_flux_info_unpack;
};

struct M174FirmwareInfo
{
  using Data = feb_can_m174_firmware_info_t;
  static constexpr std::uint32_t kFrameId = 0xAEu;
  static constexpr std::uint8_t kLength = 8u;
  static constexpr bool kExtended = false;
  static constexpr std::uint32_t kCycleMs = 0u;
  static constexpr Node kSender = Node::kNone;
  static constexpr auto kPack = &feb_can_m174_firmware_info_pack;
  static constexpr auto kUnpack = &feb_can_m174_firmware_info_unpack;
};

struct M175DiagDataMessage
{
  using Data = feb_can_m175_diag_data_message_t;
  static constexpr std::uint32_t kFrameId = 0xAFu;
  static constexpr std::uint8_t kLength = 8u;
  static constexpr bool kExtended = false;
  static constexpr std::uint32_t kCycleMs = 3u;
  static constexpr Node kSender = Node::kNone;
  static constexpr auto kPack = &feb_can_m175_diag_data_message_pack;
  static constexpr auto kUnpack = &feb_can_m175_diag_data_message_unpack;
};

struct M176FastInfo
{
  using Data = feb_can_m176_fast_info_t;
  static constexpr std::uint32_t kFrameId = 0xB0u;
  static constexpr std::uint8_t kLength = 8u;
  static constexpr bool kExtended = false;
  static constexpr std::uint32_t kCycleMs = 3u;
  static constexpr Node kSender = Node::kNone;
  static constexpr auto kPack = &feb_can_m176_fast_info_pack;
  static constexpr auto kUnpack = &feb_can_m176_fast_info_unpack;
};

struct M192CommandMessage
{
  using Data = feb_can_m192_command_message_t;
  static constexpr std::uint32_t kFrameId = 0xC0u;
  static constexpr std::uint8_t kLength = 8u;
  static constexpr bool kExtended = false;
  static constexpr std::uint32_t kCycleMs = 5u;
  static constexpr Node kSender = Node::kNone;
  static constexpr auto kPack = &feb_can_m192_command_message_pack;
  static constexpr auto kUnpack = &feb_can_m192_command_message_unpack;
};

struct M193ReadWriteParamCommand
{
  using Data = feb_can_m193_read_write_param_command_t;
  static constexpr std::uint32_t kFrameId = 0xC1u;
  static constexpr std::uint8_t kLength = 8u;
  static constexpr bool kExtended = false;
  static constexpr std::uint32_t kCycleMs = 0u;
  static constexpr Node kSender = Node::kNone;
  static constexpr auto kPack = &feb_can_m193_read_write_param_command_pack;
  static constexpr auto kUnpack = &feb_can_m193_read_write_param_command_unpack;
};

struct M194ReadWriteParamResponse
{
  using Data = feb_can_m194_read_write_param_response_t;
  static constexpr std::uint32_t kFrameId = 0xC2u;
  static constexpr std::uint8_t kLength = 8u;
  static constexpr bool kExtended = false;
  static constexpr std::uint32_t kCycleMs = 0u;
  static constexpr Node kSender = Node::kNone;
  static constexpr auto kPack = &feb_can_m194_read_write_param_response_pack;
  static constexpr auto kUnpack = &feb_can_m194_read_write_param_response_unpack;
};

struct M188U2CMessageRxd
{
  using Data = feb_can_m188_u2_c_message_rxd_t;
  static constexpr std::uint32_t kFrameId = 0x1D5u;
  static constexpr std::uint8_t kLength = 8u;
  static constexpr bool kExtended = false;
  static constexpr std::uint32_t kCycleMs = 0u;
  static constexpr Node kSender = Node::kNone;
  static constexpr auto kPack = &feb_can_m188_u2_c_message_rxd_pack;
  static constexpr auto kUnpack = &feb_can_m188_u2_c_message_rxd_unpack;
};

struct M187U2CCommandTxd
{
  using Data = feb_can_m187_u2_c_command_txd_t;
  static constexpr std::uint32_t kFrameId = 0x1D7u;
  static constexpr std::uint8_t kLength = 8u;
  static constexpr bool kExtended = false;
  static constexpr std::uint32_t kCycleMs = 0u;
  static constexpr Node kSender = Node::kNone;
  static constexpr auto kPack = &feb_can_m187_u2_c_command_txd_pack;
  static constexpr auto kUnpack = &feb_can_m187_u2_c_command_txd_unpack;
};

struct BmsCurrentLimit
{
  using Data = feb_can_bms_current_limit_t;
  static constexpr std::uint32_t kFrameId = 0x202u;
  static constexpr std::uint8_t kLength = 8u;
  static constexpr bool kExtended = false;
  static constexpr std::uint32_t kCycleMs = 0u;
  static constexpr Node kSender = Node::kBms;
  static constexpr auto kPack = &feb_can_bms_current_limit_pack;
  static constexpr auto kUnpack = &feb_can_bms_current_limit_unpack;
};

}  // namespace msg

}  // namespace feb::can

#endif  /* FEB_CAN_TRAITS_HPP */
