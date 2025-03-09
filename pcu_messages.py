import cantools
from cantools.database.conversion import BaseConversion

def normalized_brake(framd_id: int):
    normalized_break = cantools.db.Signal(
        name="normalized_break",
        start=0
        length=40
        byte_order="big_endian"
        is_signed=False,
    )
    return msg 

def rms_param_msg(framd_id: int):
    rms_param_msg = cantools.db.Signal(
        name="rms_param_msg",
        start=0
        length=8
        byte_order="big_endian"
        is_signed=False,
    )

    read_write_command = cantools.db.Signal(
        name="read_write_command",
        start=16
        length=8
        byte_order="big_endian"
        is_signed=False,
    )

    data = cantools.db.Signal(
        name="data",
        start=24
        length=16
        byte_order="big_endian"
        is_signed=False,
    )

    return msg 


def rms_commndand_msg(frame_id: int):

    torque_signal = cantools.db.Signal(
        name="torque_signal",
        start=0
        length=16
        byte_order="big_endian"
        is_signed=False,
    )

    speed_signal = cantools.db.Signal(
        name="speed_signal",
        start=16
        length=16
        byte_order="big_endian"
        is_signed=False,
    )

    direction_value = cantools.db.Signal(
        name="direction_value",
        start=32
        length=8
        byte_order="big_endian"
        is_signed=False,
    )

    inverted_enable = cantools.db.Signal(
        name="rms_enable",
        start=40
        length=1
        byte_order="big_endian"
        is_signed=False,
    )

    inverted_disregard = cantools.db.Signal(
        name="rms_enable",
        start=41
        length=1
        byte_order="big_endian"
        is_signed=False,
    )

    speed_mode = cantools.db.Signal(
        name="speed_mode",
        start=42
        length=1
        byte_order="big_endian"
        is_signed=False,
    )

    commmand_torque_limited = cantools.db.Signal(
        name="command_torque_limited",
        start=48
        length=16
        byte_order="big_endian"
        is_signed=False,
    )

    

    return msg

def bspd(framd_id: int):
    bspd_state = cantools.db.Signal(
        name="bspd_state",
        start=0
        length=8
        byte_order="big_endian"
        is_signed=False,
    )
    return msg 

def current(framd_id: int):
    tps_current = cantools.db.Signal(
        name="current",
        start=0
        length=40
        byte_order="big_endian"
        is_signed=False,
    )
    return msg 
