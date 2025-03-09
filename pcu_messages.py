import cantools
from cantools.database.conversion import BaseConversion

def normalized_brake(frame_id: int):
    normalized_brake = cantools.db.Signal(
        name="normalized_brake",
        start=0,
        length=40,
        byte_order="big_endian",
        is_signed=False
    )
    msg = cantools.db.Message(
        frame_id=frame_id,
        name="normalized_brake",
        length=5,
        signals=[normalized_brake],
        comment="PCU normalized brake message",
        strict=True
    )
    return msg 

def rms_param_msg(frame_id: int):
    addr = cantools.db.Signal(
        name="addr",
        start=0,
        length=8,
        byte_order="big_endian",
        is_signed=False
    )

    read_write_command = cantools.db.Signal(
        name="read_write_command",
        start=16,
        length=8,
        byte_order="big_endian",
        is_signed=False
    )

    data = cantools.db.Signal(
        name="data",
        start=24,
        length=16,
        byte_order="big_endian",
        is_signed=False
    )

    msg = cantools.db.Message(
        frame_id=frame_id,
        name="rms_param_msg",
        length=8,
        signals=[addr, read_write_command, data],
        comment="param_message.",
        strict=True
    )
    return msg 


def rms_command_msg(frame_id: int):

    torque_signal_big = cantools.db.Signal(
        name="torque_signal_big",
        start=0,
        length=8,
        byte_order="big_endian",
        is_signed=False
    )

    torque_signal_small = cantools.db.Signal(
        name="torque_signal_small",
        start=8,
        length=8,
        byte_order="big_endian",
        is_signed=False
    )

    speed_signal_big = cantools.db.Signal(
        name="speed_signal",
        start=16,
        length=8,
        byte_order="big_endian",
        is_signed=False
    )

    speed_signal_small = cantools.db.Signal(
        name="speed_signal_small",
        start=24,
        length=8,
        byte_order="big_endian",
        is_signed=False
    )

    direction_value = cantools.db.Signal(
        name="direction_value",
        start=32,
        length=8,
        byte_order="big_endian",
        is_signed=False
    )

    inverter_enable = cantools.db.Signal(
        name="rms_enable",
        start=40,
        length=1,
        byte_order="big_endian",
        is_signed=False
    )

    inverter_disregard = cantools.db.Signal(
        name="rms_enable",
        start=41,
        length=1,
        byte_order="big_endian",
        is_signed=False
    )

    speed_mode = cantools.db.Signal(
        name="speed_mode",
        start=42,
        length=1,
        byte_order="big_endian",
        is_signed=False
    )

    commmand_torque_limited = cantools.db.Signal(
        name="command_torque_limited",
        start=48,
        length=16,
        byte_order="big_endian",
        is_signed=False
    )

    msg = cantools.db.Message(
        frame_id=frame_id,
        name="rms_command_msg",
        length=8,
        signals=[torque_signal_big, torque_signal_small, speed_signal_big, speed_signal_small, direction_value, inverter_enable, inverter_disregard, speed_mode, commmand_torque_limited],
        comment="rms_command message.",
        strict=True
    )
    return msg

def bspd(frame_id: int):
    bspd_state = cantools.db.Signal(
        name="bspd_state",
        start=0,
        length=8,
        byte_order="big_endian",
        is_signed=False
    )
    msg = cantools.db.Message(
        frame_id=frame_id,
        name="bspd",
        length=1,
        signals=[bspd_state],
        comment="bspd message.",
        strict=True
    )
    return msg 

def current(frame_id: int):
    tps_current = cantools.db.Signal(
        name="current",
        start=0,
        length=40,
        byte_order="big_endian",
        is_signed=False
    )

    msg = cantools.db.Message(
        frame_id=frame_id,
        name="tps_current",
        length=5,
        signals=[tps_current],
        comment="tps current message.",
        strict=True
    )
    return msg 
