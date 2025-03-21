import cantools
from cantools.database.conversion import BaseConversion

def get_lvpdb_flag_bus_voltage_lv_current(frame_id: int):
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
        length=16,
        byte_order="little_endian",
    )
    
    lv_current_signal = cantools.db.Signal(
        name="lv_current",
        start=48,
        length=16,
        byte_order="little_endian",
    )

    msg = cantools.db.Message(
        frame_id=frame_id,
        name="LVPDB_Flags_Bus_Voltage_LV_Current",
        length=8,
        signals=[flag_signal, bus_voltage_signal, lv_current_signal],
        comment="LVPDB message for flags, bus voltage, LV current.",
        strict=True
    )

    return msg

def get_lvpdb_cp_af_rf_sh_current(frame_id: int):
    cp_current_signal = cantools.db.Signal(
        name="cp_current",
        start=0,
        length=16,
        byte_order="little_endian",
    )
    
    af_current_signal = cantools.db.Signal(
        name="af_current",
        start=16,
        length=16,
        byte_order="little_endian",
    )
    
    rf_current_signal = cantools.db.Signal(
        name="rf_current",
        start=32,
        length=16,
        byte_order="little_endian",
    )
    
    sh_current_signal = cantools.db.Signal(
        name="sh_voltage",
        start=48,
        length=16,
        byte_order="little_endian",
    )

    msg = cantools.db.Message(
        frame_id=frame_id,
        name="LVPDB_CP_AF_RF_SH_Current",
        length=8,
        signals=[cp_current_signal, af_current_signal, rf_current_signal, sh_current_signal],
        comment="LVPDB message for Coolant Pump Current, Accumulator Fans, Radiator Fans, Shutdown Source.",
        strict=True
    )

    return msg

def get_lvpdb_L_AS_AB_current(frame_id: int):
    l_current_signal = cantools.db.Signal(
        name="l_current",
        start=0,
        length=16,
        byte_order="little_endian",
    )
    
    as_current_signal = cantools.db.Signal(
        name="as_voltage",
        start=16,
        length=16,
        byte_order="little_endian",
    )

    ab_current_signal = cantools.db.Signal(
        name="ab_voltage",
        start=48,
        length=16,
        byte_order="little_endian",
    )

    msg = cantools.db.Message(
        frame_id=frame_id,
        name="LVPDB_L_AS_AB_Current",
        length=8,
        signals=[l_current_signal, as_current_signal, ab_current_signal],
        comment="LVPDB message for .",
        strict=True
    )

    return msg
