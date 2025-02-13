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
