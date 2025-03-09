import cantools
from cantools.database.conversion import BaseConversion

def get_measured_fan_speeds(frame_id: int):
    fan1_speed_signal = cantools.db.Signal(
        name="fan1_speed",
        start=0,
        length=8,
        byte_order="little_endian",
        is_signed=False,
    )
    
    fan2_speed_signal = cantools.db.Signal(
        name="fan2_speed",
        start=8,
        length=8,
        byte_order="little_endian",
        is_signed=False,
    )
    
    fan3_speed_signal = cantools.db.Signal(
        name="fan3_speed",
        start=16,
        length=8,
        byte_order="little_endian",
        is_signed=False,
    )
    
    fan4_speed_signal = cantools.db.Signal(
        name="fan4_speed",
        start=24,
        length=8,
        byte_order="little_endian",
        is_signed=False,
    )
    
    fan5_speed_signal = cantools.db.Signal(
        name="fan5_speed",
        start=32,
        length=8,
        byte_order="little_endian",
        is_signed=False,
    )

    msg = cantools.db.Message(
        frame_id=frame_id,
        name="FEB_DART_TACH_measurements",
        length=5,
        signals=[fan1_speed_signal,fan2_speed_signal,fan3_speed_signal,fan4_speed_signal,fan5_speed_signal],
        comment="DART message for Tachometer measurements.",
        strict=True
    )

    return msg 
