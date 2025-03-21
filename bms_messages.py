import cantools
from cantools.database.conversion import BaseConversion

def get_bms_state(frame_id: int):
    bms_state = cantools.db.Signal(
        name="bms_state",
        start=0,
        length=5,
        byte_order="little_endian",
        is_signed=False,
    )

    ping_alive = cantools.db.Signal(
        name="ping_alive",
        start=5,
        length=3,
        byte_order="little_endian",
        is_signed=False,
    )

    relay_state = cantools.db.Signal(
        name="relay_state",
        start=8,
        length=3,
        byte_order="little_endian",
        is_signed=False,
    )

    gpio_sense = cantools.db.Signal(
        name="gpio_sense",
        start=11,
        length=5,
        byte_order="little_endian",
        is_signed=False,
    )

    msg = cantools.db.Message(
        frame_id=frame_id,
        name="BMS_State",
        length=2,
        signals=[bms_state, ping_alive, relay_state, gpio_sense],
        comment="BMS message for BMS state.",
        strict=True
    )

    return msg

def get_bms_cell_data(frame_id: int):
    bms_flags = cantools.db.Signal(
        name="bms_flags",
        start=0,
        length=4,
        byte_order="little_endian",
        is_signed=False,
    )

    bms_cell = cantools.db.Signal(
        name="bms_cell",
        start=8,
        length=4,
        byte_order="little_endian",
        is_signed=False,
    )

    bms_bank = cantools.db.Signal(
        name="bms_bank",
        start=12,
        length=4,
        byte_order="little_endian",
        is_signed=False,
    )

    bms_voltage = cantools.db.Signal(
        name="bms_voltage",
        start=16,
        length=16,
        byte_order="little_endian",
        is_signed=False,
    )
    
    bms_temperature = cantools.db.Signal(
        name="bms_temperature",
        start=32,
        length=16,
        byte_order="little_endian",
        is_signed=False,
    )

    bms_send_time = cantools.db.Signal(
        name="bms_send_time",
        start=48,
        length=16,
        byte_order="little_endian",
        is_signed=False,
    )
    
    msg = cantools.db.Message(
        frame_id=frame_id,
        name="BMS_Cell_Data",
        length=8,
        signals=[bms_flags, bms_cell, bms_bank, bms_voltage, bms_temperature, bms_send_time],
        comment="BMS message for cell data.",
        strict=True
    )

    return msg

def get_accumulator_voltage(frame_id: int):
    total_pack_voltage = cantools.db.Signal(
        name="total_pack_voltage",
        start=0,
        length=16,
        byte_order="little_endian",
        is_signed=False,
    )

    min_cell_voltage = cantools.db.Signal(
        name="min_cell_voltage",
        start=16,
        length=16,
        byte_order="little_endian",
        is_signed=False,
    )

    max_cell_voltage = cantools.db.Signal(
        name="max_cell_voltage",
        start=32,
        length=16,
        byte_order="little_endian",
        is_signed=False,
    )

    send_time = cantools.db.Signal(
        name="send_time",
        start=48,
        length=16,
        byte_order="little_endian",
        is_signed=False,
    )

    msg = cantools.db.Message(
        frame_id=frame_id,
        name="BMS_Accumulator_Voltage",
        length=8,
        signals=[total_pack_voltage, min_cell_voltage, max_cell_voltage, send_time],
        comment="BMS message for accumulator voltage.",
        strict=True
    )

    return msg

def get_accumulator_temperature(frame_id: int):
    total_pack_voltage = cantools.db.Signal(
        name="average_pack_temperature",
        start=0,
        length=16,
        byte_order="little_endian",
        is_signed=False,
    )

    min_cell_temperature = cantools.db.Signal(
        name="min_cell_temperature",
        start=16,
        length=16,
        byte_order="little_endian",
        is_signed=False,
    )

    max_cell_temperature = cantools.db.Signal(
        name="max_cell_temperature",
        start=32,
        length=16,
        byte_order="little_endian",
        is_signed=False,
    )

    send_time = cantools.db.Signal(
        name="send_time",
        start=48,
        length=16,
        byte_order="little_endian",
        is_signed=False,
    )

    msg = cantools.db.Message(
        frame_id=frame_id,
        name="BMS_Accumulator_Temperature",
        length=8,
        signals=[total_pack_voltage, min_cell_temperature, max_cell_temperature, send_time],
        comment="BMS message for accumulator temperature.",
        strict=True
    )

    return msg
