import cantools
from cantools.database.conversion import BaseConversion



def get_steering_data(frame_id: int):
    can_counter = cantools.db.Signal(
        name="can_counter",
        start=0,
        length=32,
        byte_order="little_endian",
        is_signed=False,
    
    flags = cantools.db.Signal(
        name="flags",
        start=32,
        length=16,
        byte_order="little_endian",
        is_signed=False,
    
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
        name="leftmost_temp",
        start=0,
        length=16,
        byte_order="big_endian",
        is_signed=False,
    )
    center_left_temp = cantools.db.Signal(
        name="leftmost_temp",
        start=16,
        length=16,
        byte_order="big_endian",
        is_signed=False,
    )
    center_right_temp = cantools.db.Signal(
        name="leftmost_temp",
        start=32,
        length=16,
        byte_order="big_endian",
        is_signed=False,
    )
    rightmost_temp = cantools.db.Signal(
        name="leftmost_temp",
        start=48,
        length=16,
        byte_order="big_endian",
        is_signed=False,
    )
    
    msg = cantools.db.Message(
        frame_id=frame_id,
        name="FEB_rear_left_tire_temp_data",
        length=8,
        signals=[can_counter, flags, angle],
        comment="Message for rear left tire temp data.",
        strict=True
    )

    return msg

def get_rear_right_tire_temp_data(frame_id: int):
    
    leftmost_temp = cantools.db.Signal(
        name="leftmost_temp",
        start=0,
        length=16,
        byte_order="big_endian",
        is_signed=False,
    )
    center_left_temp = cantools.db.Signal(
        name="leftmost_temp",
        start=16,
        length=16,
        byte_order="big_endian",
        is_signed=False,
    )
    center_right_temp = cantools.db.Signal(
        name="leftmost_temp",
        start=32,
        length=16,
        byte_order="big_endian",
        is_signed=False,
    )
    rightmost_temp = cantools.db.Signal(
        name="leftmost_temp",
        start=48,
        length=16,
        byte_order="big_endian",
        is_signed=False,
    )
    
    msg = cantools.db.Message(
        frame_id=frame_id,
        name="FEB_rear_right_tire_temp_data",
        length=8,
        signals=[can_counter, flags, angle],
        comment="Message for rear right tire temp data.",
        strict=True
    )

    return msg

def get_front_left_tire_temp_data(frame_id: int):
    
    leftmost_temp = cantools.db.Signal(
        name="leftmost_temp",
        start=0,
        length=16,
        byte_order="big_endian",
        is_signed=False,
    )
    center_left_temp = cantools.db.Signal(
        name="leftmost_temp",
        start=16,
        length=16,
        byte_order="big_endian",
        is_signed=False,
    )
    center_right_temp = cantools.db.Signal(
        name="leftmost_temp",
        start=32,
        length=16,
        byte_order="big_endian",
        is_signed=False,
    )
    rightmost_temp = cantools.db.Signal(
        name="leftmost_temp",
        start=48,
        length=16,
        byte_order="big_endian",
        is_signed=False,
    )
    
    msg = cantools.db.Message(
        frame_id=frame_id,
        name="FEB_front_left_tire_temp_data",
        length=8,
        signals=[can_counter, flags, angle],
        comment="Message for front left tire temp data.",
        strict=True
    )

    return msg

def get_front_right_tire_temp_data(frame_id: int):
    
    leftmost_temp = cantools.db.Signal(
        name="leftmost_temp",
        start=0,
        length=16,
        byte_order="big_endian",
        is_signed=False,
    )
    center_left_temp = cantools.db.Signal(
        name="leftmost_temp",
        start=16,
        length=16,
        byte_order="big_endian",
        is_signed=False,
    )
    center_right_temp = cantools.db.Signal(
        name="leftmost_temp",
        start=32,
        length=16,
        byte_order="big_endian",
        is_signed=False,
    )
    rightmost_temp = cantools.db.Signal(
        name="leftmost_temp",
        start=48,
        length=16,
        byte_order="big_endian",
        is_signed=False,
    )
    
    msg = cantools.db.Message(
        frame_id=frame_id,
        name="FEB_front_right_tire_temp_data",
        length=8,
        signals=[can_counter, flags, angle],
        comment="Message for front right tire temp data.",
        strict=True
    )

    return msg






def get_imu_data(frame_id: int):
    accelX = cantools.db.Signal(
        name="acceleration x",
        start=0,
        length=16,
        byte_order="big_endian",
        is_signed=False,
    )
    accelY = cantools.db.Signal(
        name="acceleration y",
        start=16,
        length=32,
        byte_order="big_endian",
        is_signed=False,
    )
    accelZ = cantools.db.Signal(
        name="acceleration z",
        start=32,
        length=16,
        byte_order="big_endian",
        is_signed=False,
    )
    
    msg = cantools.db.Message(
        frame_id=frame_id,
        name="FEB_imu_data",
        length=6,
        signals=[accelX, accelY, accelZ],
        comment="Message for imu data.",
        strict=True
    )
    return msg

def get_wss_data_front(frame_id: int):
    wss_right_front = cantools.db.Message(
        name = "wss_right_front",
        start = 0,
        length = 8,
        byte_order="big_endian",
        is_signed = False,
    )
    wss_left_front = cantools.db.Message(
        name = "wss_left_front",
        start = 8,
        length = 8,
        byte_order="big_endian",
        is_signed = False,
    )
    msg = cantools.db.Message(
        frame_id = frame_id,
        name = "get_wss_front_data",
        length = 8,
        signals = [can_counter, flags, angle],
        comment = "wheel speed sensor data for left and right front wheels.",
        strict = True
    )
    
    return msg
    
def get_wss_data_rear(frame_id: int):
    wss_right_rear = cantools.db.Message(
        name = "wss_right_rear",
        start = 0,
        length = 8,
        byte_order="big_endian",
        is_signed = False,
    )
    wss_left_rear = cantools.db.Message(
        name = "wss_right_rear",
        start = 8,
        length = 8,
        byte_order="big_endian",
        is_signed = False,
    )
    msg = cantools.db.Message(
        frame_id = frame_id,
        name = "get_wss_data_rear",
        length = 8,
        signals = [can_counter, flags, angle],
        comment = "wheel speed sensor data for left and right rear wheels.",
        strict = True
    )
    
    return msg
