import cantools
from cantools.database.conversion import BaseConversion

def normalized_brake(frame_id: int):
    normalized_brake = cantools.db.Signal(
        name="normalized_brake",
        start=0,
        length=8,
        byte_order="little_endian",
        is_signed=False
    )

    msg = cantools.db.Message(
        frame_id=frame_id,
        name="normalized_brake",
        length=1,
        signals=[normalized_brake],
        comment="PCU normalized brake message",
        strict=True
    )
    
    return msg 

def rms_param_msg(frame_id: int):
    addr = cantools.db.Signal(
        name="address",
        start=0,
        length=8,
        byte_order="little_endian",
        is_signed=False
    )

    read_write_command = cantools.db.Signal(
        name="read_write_command",
        start=16,
        length=8,
        byte_order="little_endian",
        is_signed=False
    )

    data = cantools.db.Signal(
        name="data",
        start=32,
        length=16,
        byte_order="little_endian",
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
    torque_signal = cantools.db.Signal(
        name="torque_signal_small",
        start=0,
        length=16,
        byte_order="little_endian",
        is_signed=False
    )

    speed_signal = cantools.db.Signal(
        name="speed_signal",
        start=16,
        length=16,
        byte_order="little_endian",
        is_signed=False
    )

    direction_value = cantools.db.Signal(
        name="direction_value",
        start=32,
        length=1,
        byte_order="little_endian",
        is_signed=False
    )

    inverter_enable = cantools.db.Signal(
        name="inverter_enable",
        start=40,
        length=1,
        byte_order="little_endian",
        is_signed=False
    )

    inverter_dicharge = cantools.db.Signal(
       name="inverter_dicharge",
       start=41,
       length=1,
       byte_order="little_endian",
       is_signed=False
    )

    speed_mspeed_mode_enabledode = cantools.db.Signal(
       name="speed_mode_enabled",
       start=42,
       length=1,
       byte_order="little_endian",
       is_signed=False
    )

    commmand_torque_limited = cantools.db.Signal(
        name="command_torque_limited",
        start=48,
        length=16,
        byte_order="little_endian",
        is_signed=False
    )

    msg = cantools.db.Message(
        frame_id=frame_id,
        name="rms_command_msg",
        length=8,
        signals=[torque_signal, speed_signal,direction_value, inverter_enable, inverter_dicharge, speed_mspeed_mode_enabledode, commmand_torque_limited],
        comment="RMS command message.",
        strict=True
    )

    return msg

def bspd(frame_id: int):
    bspd_state = cantools.db.Signal(
        name="bspd_state",
        start=0,
        length=8,
        byte_order="little_endian",
        is_signed=False
    )
    
    msg = cantools.db.Message(
        frame_id=frame_id,
        name="BSPD_State",
        length=1,
        signals=[bspd_state],
        comment="BSPD message.",
        strict=True
    )

    return msg 

def current(frame_id: int):
    tps_current = cantools.db.Signal(
        name="tps_current",
        start=0,
        length=16,
        byte_order="little_endian",
        is_signed=False
    )

    msg = cantools.db.Message(
        frame_id=frame_id,
        name="PCU_TPS",
        length=2,
        signals=[tps_current],
        comment="PCU TPS chip reading",
        strict=True
    )
    
    return msg 
