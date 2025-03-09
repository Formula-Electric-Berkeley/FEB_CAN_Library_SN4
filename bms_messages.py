import cantools
from cantools.database.conversion import BaseConversion

def get_bms_cell_voltage(frame_id: int):
    bank_signal = cantools.db.Signal(
        name="bank_number",
        start=0,
        length=8,
        byte_order="little_endian",
        is_signed=False,
    )
    
    cell_signal = cantools.db.Signal(
        name="cell_number",
        start=8,
        length=8,
        byte_order="little_endian",
        is_signed=False,
    )

    voltage_signal = cantools.db.Signal(
        name="cell_voltage",
        start=16,
        length=16,
        byte_order="little_endian",
        is_signed=False,
        conversion=BaseConversion.factory(scale=1e-3),
        unit="mV",
    )

    msg = cantools.db.Message(
        frame_id=frame_id,
        name="FEB_BMS_Cell_Voltage",
        length=4,
        signals=[bank_signal, cell_signal, voltage_signal],
        comment="BMS message for cell voltage.",
        strict=True
    )

    return msg

def get_ivMeter_data(frame_id: int):
    low_range_current = cantools.db.Signal(
        name="low_range_current",
        start=0,
        length=8,
        byte_order="big_endian",
        is_signed=False,
    )
    
    high_range_current = cantools.db.Signal(
        name="high_range_current",
        start=8,
        length=8,
        byte_order="big_endian",
        is_signed=False,
    )

    hv_voltage = cantools.db.Signal(
        name="hv_voltage",
        start=16,
        length=8,
        byte_order="big_endian",
        is_signed=False,
        conversion=BaseConversion.factory(scale=1e-3),
        unit="mV",
    )

    msg = cantools.db.Message(
        frame_id=frame_id,
        name="FEB_IVMeter",
        length=3,
        signals=[low_range_current, high_range_current, hv_voltage],
        comment="ivMeter message for low and high range current and HV voltage.",
        strict=True
    )

    return msg
