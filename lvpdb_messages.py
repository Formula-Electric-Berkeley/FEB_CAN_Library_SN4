import cantools
from cantools.database.conversion import BaseConversion

def get_lvpdb_flag_bus_voltage(frame_id: int):
    flag_signal = cantools.db.Signal(
        name="flags",
        start=0,
        length=32,
        byte_order="little_endian",
        is_signed=False
    )
    
    bus_voltage_signal = cantools.db.Signal(
        name="bus_voltage",
        start=32,
        length=32,
        byte_order="little_endian",
        is_float=True,
    )

    msg = cantools.db.Message(
        frame_id=frame_id,
        name="FEB_LVPDB_Flags_Bus_Voltage",
        length=8,
        signals=[flag_signal, bus_voltage_signal],
        comment="LVPDB message for flags and bus voltage.",
        strict=True
    )

    return msg

def get_lvpdb_lv_cp_current(frame_id: int):
    lv_current_signal = cantools.db.Signal(
        name="lv_current",
        start=0,
        length=32,
        byte_order="little_endian",
        is_float=True
    )
    
    cp_current_signal = cantools.db.Signal(
        name="cp_voltage",
        start=32,
        length=32,
        byte_order="little_endian",
        is_float=True,
    )

    msg = cantools.db.Message(
        frame_id=frame_id,
        name="FEB_LVPDB_LV_CP_Current",
        length=8,
        signals=[lv_current_signal, cp_current_signal],
        comment="LVPDB message for Low Voltage and Coolant Pump Current.",
        strict=True
    )

    return msg

def get_lvpdb_af_rf_current(frame_id: int):
    af_current_signal = cantools.db.Signal(
        name="af_current",
        start=0,
        length=32,
        byte_order="little_endian",
        is_float=True
    )
    
    rf_current_signal = cantools.db.Signal(
        name="rf_voltage",
        start=32,
        length=32,
        byte_order="little_endian",
        is_float=True,
    )

    msg = cantools.db.Message(
        frame_id=frame_id,
        name="FEB_LVPDB_AF_RF_Current",
        length=8,
        signals=[af_current_signal, rf_current_signal],
        comment="LVPDB message for Rad Fans and Acc Fans Current.",
        strict=True
    )

    return msg

def get_lvpdb_sh_l_current(frame_id: int):
    sh_current_signal = cantools.db.Signal(
        name="sh_current",
        start=0,
        length=32,
        byte_order="little_endian",
        is_float=True
    )
    
    l_current_signal = cantools.db.Signal(
        name="l_voltage",
        start=32,
        length=32,
        byte_order="little_endian",
        is_float=True,
    )

    msg = cantools.db.Message(
        frame_id=frame_id,
        name="FEB_LVPDB_SH_L_Current",
        length=8,
        signals=[sh_current_signal, l_current_signal],
        comment="LVPDB message for Shutdown and Lidar Current.",
        strict=True
    )

    return msg

def get_lvpdb_as_ab_current(frame_id: int):
    as_current_signal = cantools.db.Signal(
        name="lv_current",
        start=0,
        length=32,
        byte_order="little_endian",
        is_float=True
    )
    
    ab_current_signal = cantools.db.Signal(
        name="cp_voltage",
        start=32,
        length=32,
        byte_order="little_endian",
        is_float=True,
    )

    msg = cantools.db.Message(
        frame_id=frame_id,
        name="FEB_LVPDB_AS_AB_Current",
        length=8,
        signals=[as_current_signal, ab_current_signal],
        comment="LVPDB message for Auton Steering and Auton Braking Current.",
        strict=True
    )

    return msg
