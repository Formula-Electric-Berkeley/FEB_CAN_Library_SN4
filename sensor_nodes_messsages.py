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
        name="leftmost_temp_RL",
        start=0,
        length=16,
        byte_order="big_endian",
        is_signed=False,
    )
    center_left_temp = cantools.db.Signal(
        name="center_left_temp_RL",
        start=16,
        length=16,
        byte_order="big_endian",
        is_signed=False,
    )
    center_right_temp = cantools.db.Signal(
        name="center_right_temp_RL",
        start=32,
        length=16,
        byte_order="big_endian",
        is_signed=False,
    )
    rightmost_temp = cantools.db.Signal(
        name="rightmost_temp_RL",
        start=48,
        length=16,
        byte_order="big_endian",
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
        byte_order="big_endian",
        is_signed=False,
    )
    center_left_temp = cantools.db.Signal(
        name="center_left_temp_RR",
        start=16,
        length=16,
        byte_order="big_endian",
        is_signed=False,
    )
    center_right_temp = cantools.db.Signal(
        name="center_right_temp_RR",
        start=32,
        length=16,
        byte_order="big_endian",
        is_signed=False,
    )
    rightmost_temp = cantools.db.Signal(
        name="rightmost_temp_RR",
        start=48,
        length=16,
        byte_order="big_endian",
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
        byte_order="big_endian",
        is_signed=False,
    )
    center_left_temp = cantools.db.Signal(
        name="center_left_temp_FL",
        start=16,
        length=16,
        byte_order="big_endian",
        is_signed=False,
    )
    center_right_temp = cantools.db.Signal(
        name="center_right_temp_FL",
        start=32,
        length=16,
        byte_order="big_endian",
        is_signed=False,
    )
    rightmost_temp = cantools.db.Signal(
        name="rightmost_temp_FL",
        start=48,
        length=16,
        byte_order="big_endian",
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
        byte_order="big_endian",
        is_signed=False,
    )
    center_left_temp = cantools.db.Signal(
        name="center_left_temp_FR",
        start=16,
        length=16,
        byte_order="big_endian",
        is_signed=False,
    )
    center_right_temp = cantools.db.Signal(
        name="center_right_temp_FR",
        start=32,
        length=16,
        byte_order="big_endian",
        is_signed=False,
    )
    rightmost_temp = cantools.db.Signal(
        name="rightmost_temp_FR",
        start=48,
        length=16,
        byte_order="big_endian",
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
        length = 2,
        signals = [wss_right_front, wss_left_front],
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
        name = "wss_left_rear",
        start = 8,
        length = 8,
        byte_order="big_endian",
        is_signed = False,
    )
    msg = cantools.db.Message(
        frame_id = frame_id,
        name = "get_wss_data_rear",
        length = 2,
        signals = [wss_right_rear, wss_left_rear],
        comment = "wheel speed sensor data for left and right rear wheels.",
        strict = True
    )
    
    return msg

def get_LinPot_CoolantPressure_Front(frame_id: int):
     lin_pot_1 = cantools.db.Signal(
         name="linear_potrentiometer_1_front",
         start=0,
         length=16, 
         byte_order="big_endian",
         is_signed=False,
     )

     lin_pot_2 = cantools.db.Signal(
         name="linear_potrentiometer_2_front",
         start=16,
         length=16, 
         byte_order="big_endian",
         is_signed=False,
     )

     coolant_pressure_1 = cantools.db.Signal(
         name="coolant_pressure_1_front",
         start=32,
         length=16, 
         byte_order="big_endian",
         is_signed=False,
     )

     coolant_pressure_2 = cantools.db.Signal(
         name="coolant_pressure_2_front",
         start=48,
         length=16, 
         byte_order="big_endian",
         is_signed=False,
     )


     msg = cantools.db.Message(
         frame_id=frame_id,
         name="linear_potentiometer_coolant_pressure_front",
         length=8,
         signals=[lin_pot_1, lin_pot_2, coolant_pressure_1, coolant_pressure_2],
         comment="Linear Potentiometer and Coolant Pressure Front.",
         strict=True
     )
 
     return msg

def get_LinPot_CoolantPressure_Front(frame_id: int):
     lin_pot_1 = cantools.db.Signal(
         name="linear_potrentiometer_1_rear",
         start=0,
         length=16, 
         byte_order="big_endian",
         is_signed=False,
     )

     lin_pot_2 = cantools.db.Signal(
         name="linear_potrentiometer_2_rear",
         start=16,
         length=16, 
         byte_order="big_endian",
         is_signed=False,
     )

     coolant_pressure_1 = cantools.db.Signal(
         name="coolant_pressure_1_rear",
         start=32,
         length=16, 
         byte_order="big_endian",
         is_signed=False,
     )

     coolant_pressure_2 = cantools.db.Signal(
         name="coolant_pressure_2_rear",
         start=48,
         length=16, 
         byte_order="big_endian",
         is_signed=False,
     )


     msg = cantools.db.Message(
         frame_id=frame_id,
         name="linear_potentiometer_coolant_pressure_rear",
         length=8,
         signals=[lin_pot_1, lin_pot_2, coolant_pressure_1, coolant_pressure_2],
         comment="Linear Potentiometer and Coolant Pressure Rear.",
         strict=True
     )
 
     return msg
