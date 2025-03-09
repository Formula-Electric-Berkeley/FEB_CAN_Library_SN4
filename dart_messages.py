import cantools
from cantools.database.conversion import BaseConversion

def measured_fan_speeds(framd_id: int):
    fan1_speed = cantools.db.Signal(
        name="fan1_speed",
        start=0
        length=8
        byte_order="big_endian"
        is_signed=False,
    )
    
    fan2_speed = cantools.db.Signal(
        name="fan2_speed",
        start=8
        length=16
        byte_order="big_endian"
        is_signed=False,
    )
    
    fan3_speed = cantools.db.Signal(
        name="fan3_speed",
        start=16
        length=8
        byte_order="big_endian"
        is_signed=False,
    )
    
    fan4_speed = cantools.db.Signal(
        name="fan4_speed",
        start=24
        length=8
        byte_order="big_endian"
        is_signed=False,
    )
    
    fan5_speed = cantools.db.Signal(
        name="fan5_speed",
        start=32
        length=8
        byte_order="big_endian"
        is_signed=False,
    )
    
    return msg 
