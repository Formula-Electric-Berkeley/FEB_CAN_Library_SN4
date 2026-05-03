import cantools
from cantools.database.conversion import BaseConversion



def get_steering_data(frame_id: int):
    can_counter = cantools.db.Signal(
        name="can_counter",
        start=0,
        length=32,
        byte_order="little_endian",
        is_signed=False,
    )
    flags = cantools.db.Signal(
        name="flags",
        start=32,
        length=16,
        byte_order="little_endian",
        is_signed=False,
    )
    angle = cantools.db.Signal(
        name="angle",
        start=48,
        length=16,
        byte_order="little_endian",
        is_signed=False,
    )
    msg = cantools.db.Message(
        frame_id=frame_id,
        name="FEB_Steering_data",
        length=8,
        signals=[can_counter, flags, angle],
        comment="Message for steering data.",
        strict=True
    )

    return msg

def get_rear_left_tire_temp_data(frame_id: int):
    
    leftmost_temp = cantools.db.Signal(
        name="leftmost_temp_RL",
        start=0,
        length=16,
        byte_order="little_endian",
        is_signed=False,
    )
    center_left_temp = cantools.db.Signal(
        name="center_left_temp_RL",
        start=16,
        length=16,
        byte_order="little_endian",
        is_signed=False,
    )
    center_right_temp = cantools.db.Signal(
        name="center_right_temp_RL",
        start=32,
        length=16,
        byte_order="little_endian",
        is_signed=False,
    )
    rightmost_temp = cantools.db.Signal(
        name="rightmost_temp_RL",
        start=48,
        length=16,
        byte_order="little_endian",
        is_signed=False,
    )
    
    msg = cantools.db.Message(
        frame_id=frame_id,
        name="rear_left_tire_temp",
        length=8,
        signals=[leftmost_temp, center_left_temp, center_right_temp, rightmost_temp],
        comment="Message for rear left tire temp data.",
        strict=True
    )

    return msg

def get_rear_right_tire_temp_data(frame_id: int):
    
    leftmost_temp = cantools.db.Signal(
        name="leftmost_temp_RR",
        start=0,
        length=16,
        byte_order="little_endian",
        is_signed=False,
    )
    center_left_temp = cantools.db.Signal(
        name="center_left_temp_RR",
        start=16,
        length=16,
        byte_order="little_endian",
        is_signed=False,
    )
    center_right_temp = cantools.db.Signal(
        name="center_right_temp_RR",
        start=32,
        length=16,
        byte_order="little_endian",
        is_signed=False,
    )
    rightmost_temp = cantools.db.Signal(
        name="rightmost_temp_RR",
        start=48,
        length=16,
        byte_order="little_endian",
        is_signed=False,
    )
    
    msg = cantools.db.Message(
        frame_id=frame_id,
        name="rear_right_tire_temp",
        length=8,
        signals=[leftmost_temp, center_left_temp, center_right_temp, rightmost_temp],
        comment="Message for rear right tire temp data.",
        strict=True
    )

    return msg

def get_front_left_tire_temp_data(frame_id: int):
    
    leftmost_temp = cantools.db.Signal(
        name="leftmost_temp_FL",
        start=0,
        length=16,
        byte_order="little_endian",
        is_signed=False,
    )
    center_left_temp = cantools.db.Signal(
        name="center_left_temp_FL",
        start=16,
        length=16,
        byte_order="little_endian",
        is_signed=False,
    )
    center_right_temp = cantools.db.Signal(
        name="center_right_temp_FL",
        start=32,
        length=16,
        byte_order="little_endian",
        is_signed=False,
    )
    rightmost_temp = cantools.db.Signal(
        name="rightmost_temp_FL",
        start=48,
        length=16,
        byte_order="little_endian",
        is_signed=False,
    )
    
    msg = cantools.db.Message(
        frame_id=frame_id,
        name="front_left_tire_temp",
        length=8,
        signals=[leftmost_temp, center_left_temp, center_right_temp, rightmost_temp],
        comment="Message for front left tire temp data.",
        strict=True
    )

    return msg

def get_front_right_tire_temp_data(frame_id: int):
    
    leftmost_temp = cantools.db.Signal(
        name="leftmost_temp_FR",
        start=0,
        length=16,
        byte_order="little_endian",
        is_signed=False,
    )
    center_left_temp = cantools.db.Signal(
        name="center_left_temp_FR",
        start=16,
        length=16,
        byte_order="little_endian",
        is_signed=False,
    )
    center_right_temp = cantools.db.Signal(
        name="center_right_temp_FR",
        start=32,
        length=16,
        byte_order="little_endian",
        is_signed=False,
    )
    rightmost_temp = cantools.db.Signal(
        name="rightmost_temp_FR",
        start=48,
        length=16,
        byte_order="little_endian",
        is_signed=False,
    )
    
    msg = cantools.db.Message(
        frame_id=frame_id,
        name="front_right_tire_temp",
        length=8,
        signals=[leftmost_temp, center_left_temp, center_right_temp, rightmost_temp],
        comment="Message for front right tire temp data.",
        strict=True
    )

    return msg

def get_imu_acceleration_data_front(frame_id: int):
    # LSM6DSOX @ FS=2g: 1 LSB = 0.061 mg (matches lsm6dsox_from_fs2_to_mg)
    accelX = cantools.db.Signal(
        name="acceleration_x",
        start=0,
        length=16,
        byte_order="little_endian",
        is_signed=True,
        conversion=BaseConversion.factory(scale=0.061),
        unit="mg",
    )
    accelY = cantools.db.Signal(
        name="acceleration_y",
        start=16,
        length=16,
        byte_order="little_endian",
        is_signed=True,
        conversion=BaseConversion.factory(scale=0.061),
        unit="mg",
    )
    accelZ = cantools.db.Signal(
        name="acceleration_z",
        start=32,
        length=16,
        byte_order="little_endian",
        is_signed=True,
        conversion=BaseConversion.factory(scale=0.061),
        unit="mg",
    )

    msg = cantools.db.Message(
        frame_id=frame_id,
        name="imu_acceleration_data",
        length=6,
        signals=[accelX, accelY, accelZ],
        comment="IMU acceleration (LSM6DSOX, FS=2g, 0.061 mg/LSB).",
        strict=True
    )

    return msg


def get_imu_acceleration_data_rear(frame_id: int):
    # LSM6DSOX @ FS=2g: 1 LSB = 0.061 mg (matches lsm6dsox_from_fs2_to_mg)
    accelX = cantools.db.Signal(
        name="acceleration_x",
        start=0,
        length=16,
        byte_order="little_endian",
        is_signed=True,
        conversion=BaseConversion.factory(scale=0.061),
        unit="mg",
    )
    accelY = cantools.db.Signal(
        name="acceleration_y",
        start=16,
        length=16,
        byte_order="little_endian",
        is_signed=True,
        conversion=BaseConversion.factory(scale=0.061),
        unit="mg",
    )
    accelZ = cantools.db.Signal(
        name="acceleration_z",
        start=32,
        length=16,
        byte_order="little_endian",
        is_signed=True,
        conversion=BaseConversion.factory(scale=0.061),
        unit="mg",
    )

    msg = cantools.db.Message(
        frame_id=frame_id,
        name="imu_acceleration_data_rear",
        length=6,
        signals=[accelX, accelY, accelZ],
        comment="REAR IMU acceleration (LSM6DSOX, FS=2g, 0.061 mg/LSB).",
        strict=True
    )

    return msg


def get_imu_gyro_data_front(frame_id: int):
    # LSM6DSOX @ FS=2000dps: 1 LSB = 70 mdps (matches lsm6dsox_from_fs2000_to_mdps)
    gyroX = cantools.db.Signal(
        name="gyro_x",
        start=0,
        length=16,
        byte_order="little_endian",
        is_signed=True,
        conversion=BaseConversion.factory(scale=70),
        unit="mdps",
    )
    gyroY = cantools.db.Signal(
        name="gyro_y",
        start=16,
        length=16,
        byte_order="little_endian",
        is_signed=True,
        conversion=BaseConversion.factory(scale=70),
        unit="mdps",
    )
    gyroZ = cantools.db.Signal(
        name="gyro_z",
        start=32,
        length=16,
        byte_order="little_endian",
        is_signed=True,
        conversion=BaseConversion.factory(scale=70),
        unit="mdps",
    )

    msg = cantools.db.Message(
        frame_id=frame_id,
        name="imu_gyro_data",
        length=6,
        signals=[gyroX, gyroY, gyroZ],
        comment="IMU gyro (LSM6DSOX, FS=2000dps, 70 mdps/LSB).",
        strict=True
    )

    return msg


def get_imu_gyro_data_rear(frame_id: int):
    # LSM6DSOX @ FS=2000dps: 1 LSB = 70 mdps (matches lsm6dsox_from_fs2000_to_mdps)
    gyroX = cantools.db.Signal(
        name="gyro_x",
        start=0,
        length=16,
        byte_order="little_endian",
        is_signed=True,
        conversion=BaseConversion.factory(scale=70),
        unit="mdps",
    )
    gyroY = cantools.db.Signal(
        name="gyro_y",
        start=16,
        length=16,
        byte_order="little_endian",
        is_signed=True,
        conversion=BaseConversion.factory(scale=70),
        unit="mdps",
    )
    gyroZ = cantools.db.Signal(
        name="gyro_z",
        start=32,
        length=16,
        byte_order="little_endian",
        is_signed=True,
        conversion=BaseConversion.factory(scale=70),
        unit="mdps",
    )

    msg = cantools.db.Message(
        frame_id=frame_id,
        name="imu_gyro_data_rear",
        length=6,
        signals=[gyroX, gyroY, gyroZ],
        comment="REAR IMU gyro (LSM6DSOX, FS=2000dps, 70 mdps/LSB).",
        strict=True
    )

    return msg


def get_magnetometer_data_front(frame_id: int):
    # LIS3MDL @ FS=16gauss: 1 LSB = 1000/1711 = 0.5844 mG (matches lis3mdl_from_fs16_to_gauss * 1000)
    magX = cantools.db.Signal(
        name="magnetometer_x",
        start=0,
        length=16,
        byte_order="little_endian",
        is_signed=True,
        conversion=BaseConversion.factory(scale=0.5844),
        unit="mG",
    )
    magY = cantools.db.Signal(
        name="magnetometer_y",
        start=16,
        length=16,
        byte_order="little_endian",
        is_signed=True,
        conversion=BaseConversion.factory(scale=0.5844),
        unit="mG",
    )
    magZ = cantools.db.Signal(
        name="magnetometer_z",
        start=32,
        length=16,
        byte_order="little_endian",
        is_signed=True,
        conversion=BaseConversion.factory(scale=0.5844),
        unit="mG",
    )

    msg = cantools.db.Message(
        frame_id=frame_id,
        name="magnetometer_data",
        length=6,
        signals=[magX, magY, magZ],
        comment="Magnetometer (LIS3MDL, FS=16gauss, 0.5844 mG/LSB).",
        strict=True
    )

    return msg


def get_magnetometer_data_rear(frame_id: int):
    # LIS3MDL @ FS=16gauss: 1 LSB = 1000/1711 = 0.5844 mG (matches lis3mdl_from_fs16_to_gauss * 1000)
    magX = cantools.db.Signal(
        name="magnetometer_x",
        start=0,
        length=16,
        byte_order="little_endian",
        is_signed=True,
        conversion=BaseConversion.factory(scale=0.5844),
        unit="mG",
    )
    magY = cantools.db.Signal(
        name="magnetometer_y",
        start=16,
        length=16,
        byte_order="little_endian",
        is_signed=True,
        conversion=BaseConversion.factory(scale=0.5844),
        unit="mG",
    )
    magZ = cantools.db.Signal(
        name="magnetometer_z",
        start=32,
        length=16,
        byte_order="little_endian",
        is_signed=True,
        conversion=BaseConversion.factory(scale=0.5844),
        unit="mG",
    )

    msg = cantools.db.Message(
        frame_id=frame_id,
        name="magnetometer_data_rear",
        length=6,
        signals=[magX, magY, magZ],
        comment="REAR Magnetometer (LIS3MDL, FS=16gauss, 0.5844 mG/LSB).",
        strict=True
    )

    return msg




def get_gps_pos_data(frame_id: int):
    # int32 signed degrees * 1e7 (~11mm globally)
    lat = cantools.db.Signal(
        name="latitude",
        start=0,
        length=32,
        byte_order="little_endian",
        is_signed=True,
        conversion=BaseConversion.factory(scale=1e-7),
        unit="deg",
    )
    lon = cantools.db.Signal(
        name="longitude",
        start=32,
        length=32,
        byte_order="little_endian",
        is_signed=True,
        conversion=BaseConversion.factory(scale=1e-7),
        unit="deg",
    )

    msg = cantools.db.Message(
        frame_id=frame_id,
        name="gps_pos_data",
        length=8,
        signals=[lat, lon],
        comment="GPS lat/lon as int32 * 1e7 deg (~11mm/LSB globally).",
        strict=True
    )

    return msg


def get_gps_pos_data_rear(frame_id: int):
    # int32 signed degrees * 1e7 (~11mm globally)
    lat = cantools.db.Signal(
        name="latitude",
        start=0,
        length=32,
        byte_order="little_endian",
        is_signed=True,
        conversion=BaseConversion.factory(scale=1e-7),
        unit="deg",
    )
    lon = cantools.db.Signal(
        name="longitude",
        start=32,
        length=32,
        byte_order="little_endian",
        is_signed=True,
        conversion=BaseConversion.factory(scale=1e-7),
        unit="deg",
    )

    msg = cantools.db.Message(
        frame_id=frame_id,
        name="gps_pos_data_rear",
        length=8,
        signals=[lat, lon],
        comment="REAR GPS lat/lon as int32 * 1e7 deg (~11mm/LSB globally).",
        strict=True
    )

    return msg



def get_gps_motion_data(frame_id: int):
    # uint16 0.01 km/h and 0.01 deg
    speed = cantools.db.Signal(
        name="speed",
        start=0,
        length=16,
        byte_order="little_endian",
        is_signed=False,
        conversion=BaseConversion.factory(scale=0.01),
        unit="km/h",
    )
    course = cantools.db.Signal(
        name="course",
        start=16,
        length=16,
        byte_order="little_endian",
        is_signed=False,
        conversion=BaseConversion.factory(scale=0.01),
        unit="deg",
    )

    msg = cantools.db.Message(
        frame_id=frame_id,
        name="gps_motion_data",
        length=4,
        signals=[speed, course],
        comment="GPS speed (0.01 km/h) and course-over-ground (0.01 deg).",
        strict=True
    )

    return msg


def get_gps_motion_data_rear(frame_id: int):
    # uint16 0.01 km/h and 0.01 deg
    speed = cantools.db.Signal(
        name="speed",
        start=0,
        length=16,
        byte_order="little_endian",
        is_signed=False,
        conversion=BaseConversion.factory(scale=0.01),
        unit="km/h",
    )
    course = cantools.db.Signal(
        name="course",
        start=16,
        length=16,
        byte_order="little_endian",
        is_signed=False,
        conversion=BaseConversion.factory(scale=0.01),
        unit="deg",
    )

    msg = cantools.db.Message(
        frame_id=frame_id,
        name="gps_motion_data_rear",
        length=4,
        signals=[speed, course],
        comment="REAR GPS speed (0.01 km/h) and course-over-ground (0.01 deg).",
        strict=True
    )

    return msg

def get_gps_time_data(frame_id: int):
    hours = cantools.db.Signal(
        name="hours",
        start=0,
        length=8,
        byte_order="little_endian",
        is_signed=True,
    )
    minutes = cantools.db.Signal(
        name="minutes",
        start=8,
        length=8,
        byte_order="little_endian",
        is_signed=True,
    )

    seconds = cantools.db.Signal(
        name="seconds",
        start=16,
        length=8,
        byte_order="little_endian",
        is_signed=True,
    )
    
    msg = cantools.db.Message(
        frame_id=frame_id,
        name="gps_time_data",
        length=3,
        signals=[hours, minutes, seconds],
        comment="GPS Time data message (UTC).",
        strict=True
    )

    return msg


def get_gps_time_data_rear(frame_id: int):
    hours = cantools.db.Signal(
        name="hours",
        start=0,
        length=8,
        byte_order="little_endian",
        is_signed=True,
    )
    minutes = cantools.db.Signal(
        name="minutes",
        start=8,
        length=8,
        byte_order="little_endian",
        is_signed=True,
    )

    seconds = cantools.db.Signal(
        name="seconds",
        start=16,
        length=8,
        byte_order="little_endian",
        is_signed=True,
    )

    msg = cantools.db.Message(
        frame_id=frame_id,
        name="gps_time_data_rear",
        length=3,
        signals=[hours, minutes, seconds],
        comment="REAR GPS Time data message (UTC).",
        strict=True
    )

    return msg

def get_gps_date_data(frame_id: int):
    day = cantools.db.Signal(
        name="day",
        start=0,
        length=8,
        byte_order="little_endian",
        is_signed=True,
    )
    month = cantools.db.Signal(
        name="month",
        start=8,
        length=8,
        byte_order="little_endian",
        is_signed=True,
    )

    year = cantools.db.Signal(
        name="year",
        start=16,
        length=8,
        byte_order="little_endian",
        is_signed=True,
    )
    
    msg = cantools.db.Message(
        frame_id=frame_id,
        name="gps_date_data",
        length=3,
        signals=[day, month, year],
        comment="GPS Date data message.",
        strict=True
    )

    return msg


def get_gps_date_data_rear(frame_id: int):
    day = cantools.db.Signal(
        name="day",
        start=0,
        length=8,
        byte_order="little_endian",
        is_signed=True,
    )
    month = cantools.db.Signal(
        name="month",
        start=8,
        length=8,
        byte_order="little_endian",
        is_signed=True,
    )

    year = cantools.db.Signal(
        name="year",
        start=16,
        length=8,
        byte_order="little_endian",
        is_signed=True,
    )

    msg = cantools.db.Message(
        frame_id=frame_id,
        name="gps_date_data_rear",
        length=3,
        signals=[day, month, year],
        comment="REAR GPS Date data message.",
        strict=True
    )

    return msg

def get_gps_altitude_data(frame_id: int):
    altitude = cantools.db.Signal(
        name="altitude",
        start=0,
        length=32,
        byte_order="little_endian",
        is_signed=True,
        conversion=BaseConversion.factory(scale=0.01),
        unit="m",
    )
    hdop = cantools.db.Signal(
        name="hdop",
        start=32,
        length=16,
        byte_order="little_endian",
        is_signed=False,
        conversion=BaseConversion.factory(scale=0.01),
    )
    vdop = cantools.db.Signal(
        name="vdop",
        start=48,
        length=16,
        byte_order="little_endian",
        is_signed=False,
        conversion=BaseConversion.factory(scale=0.01),
    )
    msg = cantools.db.Message(
        frame_id=frame_id,
        name="gps_altitude_data",
        length=8,
        signals=[altitude, hdop, vdop],
        comment="GPS altitude (cm) + horizontal/vertical DOP (x100).",
        strict=True
    )
    return msg


def get_gps_altitude_data_rear(frame_id: int):
    altitude = cantools.db.Signal(
        name="altitude",
        start=0,
        length=32,
        byte_order="little_endian",
        is_signed=True,
        conversion=BaseConversion.factory(scale=0.01),
        unit="m",
    )
    hdop = cantools.db.Signal(
        name="hdop",
        start=32,
        length=16,
        byte_order="little_endian",
        is_signed=False,
        conversion=BaseConversion.factory(scale=0.01),
    )
    vdop = cantools.db.Signal(
        name="vdop",
        start=48,
        length=16,
        byte_order="little_endian",
        is_signed=False,
        conversion=BaseConversion.factory(scale=0.01),
    )
    msg = cantools.db.Message(
        frame_id=frame_id,
        name="gps_altitude_data_rear",
        length=8,
        signals=[altitude, hdop, vdop],
        comment="REAR GPS altitude (cm) + horizontal/vertical DOP (x100).",
        strict=True
    )
    return msg

def get_gps_status_data(frame_id: int):
    fix_type = cantools.db.Signal(
        name="fix_type",
        start=0, length=8, byte_order="little_endian", is_signed=False,
        comment="0=Invalid, 1=GPS, 2=DGPS, 3=PPS",
    )
    fix_mode = cantools.db.Signal(
        name="fix_mode",
        start=8, length=8, byte_order="little_endian", is_signed=False,
        comment="1=NoFix, 2=2D, 3=3D",
    )
    sats_in_use = cantools.db.Signal(
        name="sats_in_use", start=16, length=8, byte_order="little_endian", is_signed=False,
    )
    sats_in_view = cantools.db.Signal(
        name="sats_in_view", start=24, length=8, byte_order="little_endian", is_signed=False,
    )
    valid = cantools.db.Signal(
        name="valid", start=32, length=8, byte_order="little_endian", is_signed=False,
    )
    has_fix = cantools.db.Signal(
        name="has_fix", start=40, length=8, byte_order="little_endian", is_signed=False,
    )
    pdop = cantools.db.Signal(
        name="pdop", start=48, length=16, byte_order="little_endian", is_signed=False,
        conversion=BaseConversion.factory(scale=0.01),
    )
    msg = cantools.db.Message(
        frame_id=frame_id,
        name="gps_status_data",
        length=8,
        signals=[fix_type, fix_mode, sats_in_use, sats_in_view, valid, has_fix, pdop],
        comment="GPS fix quality, satellite counts, validity flags, position DOP.",
        strict=True
    )
    return msg


def get_gps_status_data_rear(frame_id: int):
    fix_type = cantools.db.Signal(
        name="fix_type",
        start=0, length=8, byte_order="little_endian", is_signed=False,
        comment="0=Invalid, 1=GPS, 2=DGPS, 3=PPS",
    )
    fix_mode = cantools.db.Signal(
        name="fix_mode",
        start=8, length=8, byte_order="little_endian", is_signed=False,
        comment="1=NoFix, 2=2D, 3=3D",
    )
    sats_in_use = cantools.db.Signal(
        name="sats_in_use", start=16, length=8, byte_order="little_endian", is_signed=False,
    )
    sats_in_view = cantools.db.Signal(
        name="sats_in_view", start=24, length=8, byte_order="little_endian", is_signed=False,
    )
    valid = cantools.db.Signal(
        name="valid", start=32, length=8, byte_order="little_endian", is_signed=False,
    )
    has_fix = cantools.db.Signal(
        name="has_fix", start=40, length=8, byte_order="little_endian", is_signed=False,
    )
    pdop = cantools.db.Signal(
        name="pdop", start=48, length=16, byte_order="little_endian", is_signed=False,
        conversion=BaseConversion.factory(scale=0.01),
    )
    msg = cantools.db.Message(
        frame_id=frame_id,
        name="gps_status_data_rear",
        length=8,
        signals=[fix_type, fix_mode, sats_in_use, sats_in_view, valid, has_fix, pdop],
        comment="REAR GPS fix quality, satellite counts, validity flags, position DOP.",
        strict=True
    )
    return msg

def get_fusion_quaternion_data(frame_id: int):
    # Quaternion components scaled to int16 by * 32767, range [-1, 1].
    qw = cantools.db.Signal(
        name="q_w", start=0, length=16, byte_order="little_endian", is_signed=True,
        conversion=BaseConversion.factory(scale=1.0/32767.0),
    )
    qx = cantools.db.Signal(
        name="q_x", start=16, length=16, byte_order="little_endian", is_signed=True,
        conversion=BaseConversion.factory(scale=1.0/32767.0),
    )
    qy = cantools.db.Signal(
        name="q_y", start=32, length=16, byte_order="little_endian", is_signed=True,
        conversion=BaseConversion.factory(scale=1.0/32767.0),
    )
    qz = cantools.db.Signal(
        name="q_z", start=48, length=16, byte_order="little_endian", is_signed=True,
        conversion=BaseConversion.factory(scale=1.0/32767.0),
    )
    msg = cantools.db.Message(
        frame_id=frame_id,
        name="fusion_quaternion_data",
        length=8,
        signals=[qw, qx, qy, qz],
        comment="Fusion AHRS orientation quaternion (w, x, y, z).",
        strict=True
    )
    return msg


def get_fusion_quaternion_data_rear(frame_id: int):
    # Quaternion components scaled to int16 by * 32767, range [-1, 1].
    qw = cantools.db.Signal(
        name="q_w", start=0, length=16, byte_order="little_endian", is_signed=True,
        conversion=BaseConversion.factory(scale=1.0/32767.0),
    )
    qx = cantools.db.Signal(
        name="q_x", start=16, length=16, byte_order="little_endian", is_signed=True,
        conversion=BaseConversion.factory(scale=1.0/32767.0),
    )
    qy = cantools.db.Signal(
        name="q_y", start=32, length=16, byte_order="little_endian", is_signed=True,
        conversion=BaseConversion.factory(scale=1.0/32767.0),
    )
    qz = cantools.db.Signal(
        name="q_z", start=48, length=16, byte_order="little_endian", is_signed=True,
        conversion=BaseConversion.factory(scale=1.0/32767.0),
    )
    msg = cantools.db.Message(
        frame_id=frame_id,
        name="fusion_quaternion_data_rear",
        length=8,
        signals=[qw, qx, qy, qz],
        comment="REAR Fusion AHRS orientation quaternion (w, x, y, z).",
        strict=True
    )
    return msg

def get_fusion_euler_data(frame_id: int):
    roll = cantools.db.Signal(
        name="roll", start=0, length=16, byte_order="little_endian", is_signed=True,
        conversion=BaseConversion.factory(scale=0.01), unit="deg",
    )
    pitch = cantools.db.Signal(
        name="pitch", start=16, length=16, byte_order="little_endian", is_signed=True,
        conversion=BaseConversion.factory(scale=0.01), unit="deg",
    )
    yaw = cantools.db.Signal(
        name="yaw", start=32, length=16, byte_order="little_endian", is_signed=True,
        conversion=BaseConversion.factory(scale=0.01), unit="deg",
    )
    msg = cantools.db.Message(
        frame_id=frame_id,
        name="fusion_euler_data",
        length=6,
        signals=[roll, pitch, yaw],
        comment="Fusion AHRS Euler angles (0.01 deg/LSB).",
        strict=True
    )
    return msg


def get_fusion_euler_data_rear(frame_id: int):
    roll = cantools.db.Signal(
        name="roll", start=0, length=16, byte_order="little_endian", is_signed=True,
        conversion=BaseConversion.factory(scale=0.01), unit="deg",
    )
    pitch = cantools.db.Signal(
        name="pitch", start=16, length=16, byte_order="little_endian", is_signed=True,
        conversion=BaseConversion.factory(scale=0.01), unit="deg",
    )
    yaw = cantools.db.Signal(
        name="yaw", start=32, length=16, byte_order="little_endian", is_signed=True,
        conversion=BaseConversion.factory(scale=0.01), unit="deg",
    )
    msg = cantools.db.Message(
        frame_id=frame_id,
        name="fusion_euler_data_rear",
        length=6,
        signals=[roll, pitch, yaw],
        comment="REAR Fusion AHRS Euler angles (0.01 deg/LSB).",
        strict=True
    )
    return msg

def get_fusion_linear_accel_data(frame_id: int):
    # Linear acceleration in body frame, gravity removed (mg).
    ax = cantools.db.Signal(
        name="lin_accel_x", start=0, length=16, byte_order="little_endian", is_signed=True,
        unit="mg",
    )
    ay = cantools.db.Signal(
        name="lin_accel_y", start=16, length=16, byte_order="little_endian", is_signed=True,
        unit="mg",
    )
    az = cantools.db.Signal(
        name="lin_accel_z", start=32, length=16, byte_order="little_endian", is_signed=True,
        unit="mg",
    )
    msg = cantools.db.Message(
        frame_id=frame_id,
        name="fusion_linear_accel_data",
        length=6,
        signals=[ax, ay, az],
        comment="Fusion linear acceleration (gravity removed, body frame, mg).",
        strict=True
    )
    return msg


def get_fusion_linear_accel_data_rear(frame_id: int):
    # Linear acceleration in body frame, gravity removed (mg).
    ax = cantools.db.Signal(
        name="lin_accel_x", start=0, length=16, byte_order="little_endian", is_signed=True,
        unit="mg",
    )
    ay = cantools.db.Signal(
        name="lin_accel_y", start=16, length=16, byte_order="little_endian", is_signed=True,
        unit="mg",
    )
    az = cantools.db.Signal(
        name="lin_accel_z", start=32, length=16, byte_order="little_endian", is_signed=True,
        unit="mg",
    )
    msg = cantools.db.Message(
        frame_id=frame_id,
        name="fusion_linear_accel_data_rear",
        length=6,
        signals=[ax, ay, az],
        comment="REAR Fusion linear acceleration (gravity removed, body frame, mg).",
        strict=True
    )
    return msg

def get_fusion_earth_accel_data(frame_id: int):
    # Linear acceleration in earth frame, gravity removed (mg).
    ax = cantools.db.Signal(
        name="earth_accel_x", start=0, length=16, byte_order="little_endian", is_signed=True,
        unit="mg",
    )
    ay = cantools.db.Signal(
        name="earth_accel_y", start=16, length=16, byte_order="little_endian", is_signed=True,
        unit="mg",
    )
    az = cantools.db.Signal(
        name="earth_accel_z", start=32, length=16, byte_order="little_endian", is_signed=True,
        unit="mg",
    )
    msg = cantools.db.Message(
        frame_id=frame_id,
        name="fusion_earth_accel_data",
        length=6,
        signals=[ax, ay, az],
        comment="Fusion linear acceleration (gravity removed, earth frame, mg).",
        strict=True
    )
    return msg


def get_fusion_earth_accel_data_rear(frame_id: int):
    # Linear acceleration in earth frame, gravity removed (mg).
    ax = cantools.db.Signal(
        name="earth_accel_x", start=0, length=16, byte_order="little_endian", is_signed=True,
        unit="mg",
    )
    ay = cantools.db.Signal(
        name="earth_accel_y", start=16, length=16, byte_order="little_endian", is_signed=True,
        unit="mg",
    )
    az = cantools.db.Signal(
        name="earth_accel_z", start=32, length=16, byte_order="little_endian", is_signed=True,
        unit="mg",
    )
    msg = cantools.db.Message(
        frame_id=frame_id,
        name="fusion_earth_accel_data_rear",
        length=6,
        signals=[ax, ay, az],
        comment="REAR Fusion linear acceleration (gravity removed, earth frame, mg).",
        strict=True
    )
    return msg

def get_fusion_status_data(frame_id: int):
    flags = cantools.db.Signal(
        name="flags", start=0, length=8, byte_order="little_endian", is_signed=False,
        comment="bit0 startup, bit1 angRateRecov, bit2 accelRecov, bit3 magRecov, bit4 accelIgnored, bit5 magIgnored",
    )
    accel_error = cantools.db.Signal(
        name="accel_error", start=8, length=8, byte_order="little_endian", is_signed=False,
        conversion=BaseConversion.factory(scale=0.1), unit="deg",
    )
    mag_error = cantools.db.Signal(
        name="mag_error", start=16, length=8, byte_order="little_endian", is_signed=False,
        conversion=BaseConversion.factory(scale=0.1), unit="deg",
    )
    msg = cantools.db.Message(
        frame_id=frame_id,
        name="fusion_status_data",
        length=3,
        signals=[flags, accel_error, mag_error],
        comment="Fusion AHRS internal flags + accel/mag rejection errors.",
        strict=True
    )
    return msg


def get_fusion_status_data_rear(frame_id: int):
    flags = cantools.db.Signal(
        name="flags", start=0, length=8, byte_order="little_endian", is_signed=False,
        comment="bit0 startup, bit1 angRateRecov, bit2 accelRecov, bit3 magRecov, bit4 accelIgnored, bit5 magIgnored",
    )
    accel_error = cantools.db.Signal(
        name="accel_error", start=8, length=8, byte_order="little_endian", is_signed=False,
        conversion=BaseConversion.factory(scale=0.1), unit="deg",
    )
    mag_error = cantools.db.Signal(
        name="mag_error", start=16, length=8, byte_order="little_endian", is_signed=False,
        conversion=BaseConversion.factory(scale=0.1), unit="deg",
    )
    msg = cantools.db.Message(
        frame_id=frame_id,
        name="fusion_status_data_rear",
        length=3,
        signals=[flags, accel_error, mag_error],
        comment="REAR Fusion AHRS internal flags + accel/mag rejection errors.",
        strict=True
    )
    return msg

def get_sensor_temps_data(frame_id: int):
    imu_temp = cantools.db.Signal(
        name="imu_temp", start=0, length=16, byte_order="little_endian", is_signed=True,
        conversion=BaseConversion.factory(scale=0.01), unit="degC",
    )
    mag_temp = cantools.db.Signal(
        name="mag_temp", start=16, length=16, byte_order="little_endian", is_signed=True,
        conversion=BaseConversion.factory(scale=0.01), unit="degC",
    )
    msg = cantools.db.Message(
        frame_id=frame_id,
        name="sensor_temps_data",
        length=4,
        signals=[imu_temp, mag_temp],
        comment="LSM6DSOX IMU and LIS3MDL magnetometer die temperatures (0.01 degC/LSB).",
        strict=True
    )
    return msg


def get_sensor_temps_data_rear(frame_id: int):
    imu_temp = cantools.db.Signal(
        name="imu_temp", start=0, length=16, byte_order="little_endian", is_signed=True,
        conversion=BaseConversion.factory(scale=0.01), unit="degC",
    )
    mag_temp = cantools.db.Signal(
        name="mag_temp", start=16, length=16, byte_order="little_endian", is_signed=True,
        conversion=BaseConversion.factory(scale=0.01), unit="degC",
    )
    msg = cantools.db.Message(
        frame_id=frame_id,
        name="sensor_temps_data_rear",
        length=4,
        signals=[imu_temp, mag_temp],
        comment="REAR LSM6DSOX IMU and LIS3MDL magnetometer die temperatures (0.01 degC/LSB).",
        strict=True
    )
    return msg

def get_wss_data_front(frame_id: int):
    # uint16 in 0.1 RPM units (range 0..6553.5 RPM); direction flags in byte 4.
    wss_left_front = cantools.db.Signal(
        name="wss_left_front",
        start=0,
        length=16,
        byte_order="little_endian",
        is_signed=False,
        conversion=BaseConversion.factory(scale=0.1),
        unit="RPM",
    )
    wss_right_front = cantools.db.Signal(
        name="wss_right_front",
        start=16,
        length=16,
        byte_order="little_endian",
        is_signed=False,
        conversion=BaseConversion.factory(scale=0.1),
        unit="RPM",
    )
    wss_dir_flags = cantools.db.Signal(
        name="wss_dir_flags",
        start=32,
        length=8,
        byte_order="little_endian",
        is_signed=False,
        comment="bit0: left wheel direction (0=fwd, 1=rev); bit1: right wheel direction",
    )
    msg = cantools.db.Message(
        frame_id=frame_id,
        name="wss_front_data",
        length=8,
        signals=[wss_left_front, wss_right_front, wss_dir_flags],
        comment="Front wheel speeds (uint16, 0.1 RPM/LSB) + direction flags.",
        strict=True
    )

    return msg
    
def get_wss_data_rear(frame_id: int):
    wss_right_rear = cantools.db.Signal(
        name = "wss_right_rear",
        start = 0,
        length = 32,
        byte_order="little_endian",
        is_signed = False,
    )
    wss_left_rear = cantools.db.Signal(
        name = "wss_left_rear",
        start = 32,
        length = 32,
        byte_order="little_endian",
        is_signed = False,
    )
    msg = cantools.db.Message(
        frame_id = frame_id,
        name = "wss_rear_data",
        length = 8,
        signals = [wss_right_rear, wss_left_rear],
        comment = "Wheel speed sensor data for left and right rear wheels.",
        strict = True
    )
    
    return msg

def get_LinPot_Front(frame_id: int):
    lin_pot_1 = cantools.db.Signal(
        name="linear_potentiometer_1_front",
        start=0,
        length=16, 
        byte_order="little_endian",
        is_signed=False,
     )
    
    lin_pot_2 = cantools.db.Signal(
        name="linear_potentiometer_2_front",
        start=16,
        length=16, 
        byte_order="little_endian",
        is_signed=False,
     )
    
    msg = cantools.db.Message(
        frame_id=frame_id,
        name="linear_potentiometer_front",
        length=4,
        signals=[lin_pot_1, lin_pot_2],
        comment="Linear Potentiometer Front.",
        strict=True
     )
 
    return msg

def get_LinPot_Rear(frame_id: int):
     lin_pot_1 = cantools.db.Signal(
        name="linear_potentiometer_1_rear",
        start=0,
        length=16, 
        byte_order="little_endian",
        is_signed=False,
     )

     lin_pot_2 = cantools.db.Signal(
        name="linear_potentiometer_2_rear",
        start=16,
        length=16, 
        byte_order="little_endian",
        is_signed=False,
     )

     msg = cantools.db.Message(
        frame_id=frame_id,
        name="linear_potentiometer_rear",
        length=4,
        signals=[lin_pot_1, lin_pot_2],
        comment="Linear Potentiometer Rear.",
        strict=True
     )
 
     return msg

def get_CoolantPressure(frame_id: int):
    coolant_pressure_1 = cantools.db.Signal(
        name="coolant_pressure_1",
        start=0,
        length=16, 
        byte_order="little_endian",
        is_signed=False,
     )
    coolant_pressure_2 = cantools.db.Signal(
        name="coolant_pressure_2",
        start=16,
        length=16, 
        byte_order="little_endian",
        is_signed=False,
     )

    msg = cantools.db.Message(
            frame_id=frame_id,
            name="coolant_pressure",
            length=4,
            signals=[coolant_pressure_1, coolant_pressure_2],
            comment="Coolant Pressure",
            strict=True
         )
    return msg

def get_front_sensor_heartbeat(frame_id: int):
    error0 = cantools.db.Signal(name="error0", start=0, length=1, byte_order="little_endian", is_signed=False)
    error1 = cantools.db.Signal(name="error1", start=1, length=1, byte_order="little_endian", is_signed=False)
    error2 = cantools.db.Signal(name="error2", start=2, length=1, byte_order="little_endian", is_signed=False)
    error3 = cantools.db.Signal(name="error3", start=3, length=1, byte_order="little_endian", is_signed=False)
    error4 = cantools.db.Signal(name="error4", start=4, length=1, byte_order="little_endian", is_signed=False)
    error5 = cantools.db.Signal(name="error5", start=5, length=1, byte_order="little_endian", is_signed=False)
    error6 = cantools.db.Signal(name="error6", start=6, length=1, byte_order="little_endian", is_signed=False)
    error7 = cantools.db.Signal(name="error7", start=7, length=1, byte_order="little_endian", is_signed=False)
    error8 = cantools.db.Signal(name="error8", start=8, length=1, byte_order="little_endian", is_signed=False)
    error9 = cantools.db.Signal(name="error9", start=9, length=1, byte_order="little_endian", is_signed=False)
    error10 = cantools.db.Signal(name="error10", start=10, length=1, byte_order="little_endian", is_signed=False)
    error11 = cantools.db.Signal(name="error11", start=11, length=1, byte_order="little_endian", is_signed=False)
    error12 = cantools.db.Signal(name="error12", start=12, length=1, byte_order="little_endian", is_signed=False)
    error13 = cantools.db.Signal(name="error13", start=13, length=1, byte_order="little_endian", is_signed=False)
    error14 = cantools.db.Signal(name="error14", start=14, length=1, byte_order="little_endian", is_signed=False)
    error15 = cantools.db.Signal(name="error15", start=15, length=1, byte_order="little_endian", is_signed=False)
    error16 = cantools.db.Signal(name="error16", start=16, length=1, byte_order="little_endian", is_signed=False)
    error17 = cantools.db.Signal(name="error17", start=17, length=1, byte_order="little_endian", is_signed=False)
    error18 = cantools.db.Signal(name="error18", start=18, length=1, byte_order="little_endian", is_signed=False)
    error19 = cantools.db.Signal(name="error19", start=19, length=1, byte_order="little_endian", is_signed=False)
    error20 = cantools.db.Signal(name="error20", start=20, length=1, byte_order="little_endian", is_signed=False)
    error21 = cantools.db.Signal(name="error21", start=21, length=1, byte_order="little_endian", is_signed=False)
    error22 = cantools.db.Signal(name="error22", start=22, length=1, byte_order="little_endian", is_signed=False)
    error23 = cantools.db.Signal(name="error23", start=23, length=1, byte_order="little_endian", is_signed=False)
    error24 = cantools.db.Signal(name="error24", start=24, length=1, byte_order="little_endian", is_signed=False)
    error25 = cantools.db.Signal(name="error25", start=25, length=1, byte_order="little_endian", is_signed=False)
    error26 = cantools.db.Signal(name="error26", start=26, length=1, byte_order="little_endian", is_signed=False)
    error27 = cantools.db.Signal(name="error27", start=27, length=1, byte_order="little_endian", is_signed=False)
    error28 = cantools.db.Signal(name="error28", start=28, length=1, byte_order="little_endian", is_signed=False)
    error29 = cantools.db.Signal(name="error29", start=29, length=1, byte_order="little_endian", is_signed=False)
    error30 = cantools.db.Signal(name="error30", start=30, length=1, byte_order="little_endian", is_signed=False)
    error31 = cantools.db.Signal(name="error31", start=31, length=1, byte_order="little_endian", is_signed=False)
    error32 = cantools.db.Signal(name="error32", start=32, length=1, byte_order="little_endian", is_signed=False)
    error33 = cantools.db.Signal(name="error33", start=33, length=1, byte_order="little_endian", is_signed=False)
    error34 = cantools.db.Signal(name="error34", start=34, length=1, byte_order="little_endian", is_signed=False)
    error35 = cantools.db.Signal(name="error35", start=35, length=1, byte_order="little_endian", is_signed=False)
    error36 = cantools.db.Signal(name="error36", start=36, length=1, byte_order="little_endian", is_signed=False)
    error37 = cantools.db.Signal(name="error37", start=37, length=1, byte_order="little_endian", is_signed=False)
    error38 = cantools.db.Signal(name="error38", start=38, length=1, byte_order="little_endian", is_signed=False)
    error39 = cantools.db.Signal(name="error39", start=39, length=1, byte_order="little_endian", is_signed=False)
    error40 = cantools.db.Signal(name="error40", start=40, length=1, byte_order="little_endian", is_signed=False)
    error41 = cantools.db.Signal(name="error41", start=41, length=1, byte_order="little_endian", is_signed=False)
    error42 = cantools.db.Signal(name="error42", start=42, length=1, byte_order="little_endian", is_signed=False)
    error43 = cantools.db.Signal(name="error43", start=43, length=1, byte_order="little_endian", is_signed=False)
    error44 = cantools.db.Signal(name="error44", start=44, length=1, byte_order="little_endian", is_signed=False)
    error45 = cantools.db.Signal(name="error45", start=45, length=1, byte_order="little_endian", is_signed=False)
    error46 = cantools.db.Signal(name="error46", start=46, length=1, byte_order="little_endian", is_signed=False)
    error47 = cantools.db.Signal(name="error47", start=47, length=1, byte_order="little_endian", is_signed=False)
    error48 = cantools.db.Signal(name="error48", start=48, length=1, byte_order="little_endian", is_signed=False)
    error49 = cantools.db.Signal(name="error49", start=49, length=1, byte_order="little_endian", is_signed=False)
    error50 = cantools.db.Signal(name="error50", start=50, length=1, byte_order="little_endian", is_signed=False)
    error51 = cantools.db.Signal(name="error51", start=51, length=1, byte_order="little_endian", is_signed=False)
    error52 = cantools.db.Signal(name="error52", start=52, length=1, byte_order="little_endian", is_signed=False)
    error53 = cantools.db.Signal(name="error53", start=53, length=1, byte_order="little_endian", is_signed=False)
    error54 = cantools.db.Signal(name="error54", start=54, length=1, byte_order="little_endian", is_signed=False)
    error55 = cantools.db.Signal(name="error55", start=55, length=1, byte_order="little_endian", is_signed=False)
    error56 = cantools.db.Signal(name="error56", start=56, length=1, byte_order="little_endian", is_signed=False)
    error57 = cantools.db.Signal(name="error57", start=57, length=1, byte_order="little_endian", is_signed=False)
    error58 = cantools.db.Signal(name="error58", start=58, length=1, byte_order="little_endian", is_signed=False)
    error59 = cantools.db.Signal(name="error59", start=59, length=1, byte_order="little_endian", is_signed=False)
    error60 = cantools.db.Signal(name="error60", start=60, length=1, byte_order="little_endian", is_signed=False)
    error61 = cantools.db.Signal(name="error61", start=61, length=1, byte_order="little_endian", is_signed=False)
    error62 = cantools.db.Signal(name="error62", start=62, length=1, byte_order="little_endian", is_signed=False)
    error63 = cantools.db.Signal(name="error63", start=63, length=1, byte_order="little_endian", is_signed=False)

    msg = cantools.db.Message(
        frame_id=frame_id,
        name="front_sensor_heartbeat_message",
        length=8,
        signals=[
            error0, error1, error2, error3, error4, error5, error6, error7,
            error8, error9, error10, error11, error12, error13, error14, error15,
            error16, error17, error18, error19, error20, error21, error22, error23,
            error24, error25, error26, error27, error28, error29, error30, error31,
            error32, error33, error34, error35, error36, error37, error38, error39,
            error40, error41, error42, error43, error44, error45, error46, error47,
            error48, error49, error50, error51, error52, error53, error54, error55,
            error56, error57, error58, error59, error60, error61, error62, error63
        ],
        comment="Front Sensor Heartbeat",
        strict=True
    )

    return msg

def get_rear_sensor_heartbeat(frame_id: int):


    error0 = cantools.db.Signal(name="error0", start=0, length=1, byte_order="little_endian", is_signed=False)
    error1 = cantools.db.Signal(name="error1", start=1, length=1, byte_order="little_endian", is_signed=False)
    error2 = cantools.db.Signal(name="error2", start=2, length=1, byte_order="little_endian", is_signed=False)
    error3 = cantools.db.Signal(name="error3", start=3, length=1, byte_order="little_endian", is_signed=False)
    error4 = cantools.db.Signal(name="error4", start=4, length=1, byte_order="little_endian", is_signed=False)
    error5 = cantools.db.Signal(name="error5", start=5, length=1, byte_order="little_endian", is_signed=False)
    error6 = cantools.db.Signal(name="error6", start=6, length=1, byte_order="little_endian", is_signed=False)
    error7 = cantools.db.Signal(name="error7", start=7, length=1, byte_order="little_endian", is_signed=False)
    error8 = cantools.db.Signal(name="error8", start=8, length=1, byte_order="little_endian", is_signed=False)
    error9 = cantools.db.Signal(name="error9", start=9, length=1, byte_order="little_endian", is_signed=False)
    error10 = cantools.db.Signal(name="error10", start=10, length=1, byte_order="little_endian", is_signed=False)
    error11 = cantools.db.Signal(name="error11", start=11, length=1, byte_order="little_endian", is_signed=False)
    error12 = cantools.db.Signal(name="error12", start=12, length=1, byte_order="little_endian", is_signed=False)
    error13 = cantools.db.Signal(name="error13", start=13, length=1, byte_order="little_endian", is_signed=False)
    error14 = cantools.db.Signal(name="error14", start=14, length=1, byte_order="little_endian", is_signed=False)
    error15 = cantools.db.Signal(name="error15", start=15, length=1, byte_order="little_endian", is_signed=False)
    error16 = cantools.db.Signal(name="error16", start=16, length=1, byte_order="little_endian", is_signed=False)
    error17 = cantools.db.Signal(name="error17", start=17, length=1, byte_order="little_endian", is_signed=False)
    error18 = cantools.db.Signal(name="error18", start=18, length=1, byte_order="little_endian", is_signed=False)
    error19 = cantools.db.Signal(name="error19", start=19, length=1, byte_order="little_endian", is_signed=False)
    error20 = cantools.db.Signal(name="error20", start=20, length=1, byte_order="little_endian", is_signed=False)
    error21 = cantools.db.Signal(name="error21", start=21, length=1, byte_order="little_endian", is_signed=False)
    error22 = cantools.db.Signal(name="error22", start=22, length=1, byte_order="little_endian", is_signed=False)
    error23 = cantools.db.Signal(name="error23", start=23, length=1, byte_order="little_endian", is_signed=False)
    error24 = cantools.db.Signal(name="error24", start=24, length=1, byte_order="little_endian", is_signed=False)
    error25 = cantools.db.Signal(name="error25", start=25, length=1, byte_order="little_endian", is_signed=False)
    error26 = cantools.db.Signal(name="error26", start=26, length=1, byte_order="little_endian", is_signed=False)
    error27 = cantools.db.Signal(name="error27", start=27, length=1, byte_order="little_endian", is_signed=False)
    error28 = cantools.db.Signal(name="error28", start=28, length=1, byte_order="little_endian", is_signed=False)
    error29 = cantools.db.Signal(name="error29", start=29, length=1, byte_order="little_endian", is_signed=False)
    error30 = cantools.db.Signal(name="error30", start=30, length=1, byte_order="little_endian", is_signed=False)
    error31 = cantools.db.Signal(name="error31", start=31, length=1, byte_order="little_endian", is_signed=False)
    error32 = cantools.db.Signal(name="error32", start=32, length=1, byte_order="little_endian", is_signed=False)
    error33 = cantools.db.Signal(name="error33", start=33, length=1, byte_order="little_endian", is_signed=False)
    error34 = cantools.db.Signal(name="error34", start=34, length=1, byte_order="little_endian", is_signed=False)
    error35 = cantools.db.Signal(name="error35", start=35, length=1, byte_order="little_endian", is_signed=False)
    error36 = cantools.db.Signal(name="error36", start=36, length=1, byte_order="little_endian", is_signed=False)
    error37 = cantools.db.Signal(name="error37", start=37, length=1, byte_order="little_endian", is_signed=False)
    error38 = cantools.db.Signal(name="error38", start=38, length=1, byte_order="little_endian", is_signed=False)
    error39 = cantools.db.Signal(name="error39", start=39, length=1, byte_order="little_endian", is_signed=False)
    error40 = cantools.db.Signal(name="error40", start=40, length=1, byte_order="little_endian", is_signed=False)
    error41 = cantools.db.Signal(name="error41", start=41, length=1, byte_order="little_endian", is_signed=False)
    error42 = cantools.db.Signal(name="error42", start=42, length=1, byte_order="little_endian", is_signed=False)
    error43 = cantools.db.Signal(name="error43", start=43, length=1, byte_order="little_endian", is_signed=False)
    error44 = cantools.db.Signal(name="error44", start=44, length=1, byte_order="little_endian", is_signed=False)
    error45 = cantools.db.Signal(name="error45", start=45, length=1, byte_order="little_endian", is_signed=False)
    error46 = cantools.db.Signal(name="error46", start=46, length=1, byte_order="little_endian", is_signed=False)
    error47 = cantools.db.Signal(name="error47", start=47, length=1, byte_order="little_endian", is_signed=False)
    error48 = cantools.db.Signal(name="error48", start=48, length=1, byte_order="little_endian", is_signed=False)
    error49 = cantools.db.Signal(name="error49", start=49, length=1, byte_order="little_endian", is_signed=False)
    error50 = cantools.db.Signal(name="error50", start=50, length=1, byte_order="little_endian", is_signed=False)
    error51 = cantools.db.Signal(name="error51", start=51, length=1, byte_order="little_endian", is_signed=False)
    error52 = cantools.db.Signal(name="error52", start=52, length=1, byte_order="little_endian", is_signed=False)
    error53 = cantools.db.Signal(name="error53", start=53, length=1, byte_order="little_endian", is_signed=False)
    error54 = cantools.db.Signal(name="error54", start=54, length=1, byte_order="little_endian", is_signed=False)
    error55 = cantools.db.Signal(name="error55", start=55, length=1, byte_order="little_endian", is_signed=False)
    error56 = cantools.db.Signal(name="error56", start=56, length=1, byte_order="little_endian", is_signed=False)
    error57 = cantools.db.Signal(name="error57", start=57, length=1, byte_order="little_endian", is_signed=False)
    error58 = cantools.db.Signal(name="error58", start=58, length=1, byte_order="little_endian", is_signed=False)
    error59 = cantools.db.Signal(name="error59", start=59, length=1, byte_order="little_endian", is_signed=False)
    error60 = cantools.db.Signal(name="error60", start=60, length=1, byte_order="little_endian", is_signed=False)
    error61 = cantools.db.Signal(name="error61", start=61, length=1, byte_order="little_endian", is_signed=False)
    error62 = cantools.db.Signal(name="error62", start=62, length=1, byte_order="little_endian", is_signed=False)
    error63 = cantools.db.Signal(name="error63", start=63, length=1, byte_order="little_endian", is_signed=False)

    msg = cantools.db.Message(
        frame_id=frame_id,
        name="rear_sensor_heartbeat_message",
        length=8,
        signals=[
            error0, error1, error2, error3, error4, error5, error6, error7,
            error8, error9, error10, error11, error12, error13, error14, error15,
            error16, error17, error18, error19, error20, error21, error22, error23,
            error24, error25, error26, error27, error28, error29, error30, error31,
            error32, error33, error34, error35, error36, error37, error38, error39,
            error40, error41, error42, error43, error44, error45, error46, error47,
            error48, error49, error50, error51, error52, error53, error54, error55,
            error56, error57, error58, error59, error60, error61, error62, error63
        ],
        comment="Rear Sensor Heartbeat",
        strict=True
    )

    return msg